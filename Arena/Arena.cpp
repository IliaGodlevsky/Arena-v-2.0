#include <iostream>
#include <ctime>

#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../ThreadGuard/ThreadGurad.h"
#include "../Decision/Decision.h"
#include "../Decision/HumanDecision.h"
#include "../Factories/UnitFactory/UnitFactory.h"
#include "../Factories/UnitFactory/WarriorFactory.h"
#include "../Factories/UnitFactory/WizardFactory.h"
#include "../UnitState/InnerUnitState/DeadUnitState.h"

#include "Arena.h"

const std::vector<std::string> m_reserveNames =
{
	"Bill","Glen","Mark","Gven","Sally","Opera",
	"Dgill","Sam","Oliver","Gvinett","Tony","Moody",
	"Sigma","Anna","Vector","Trench","Rex","Paul",
	"Bruno","Silvia","John","Tirion","Mortal","Wolf",
	"Elizabeth","Unberto","Izabell","Oxford","Mark"
};

int Arena::m_round = 0;

// Return the maximum number of players
// that can take part in the game
constexpr int Arena::getMaxNubmerOfPlayers()const
{
	return 7; 
}

constexpr int Arena::getMinNumberOfPlayers()const
{
	return 2;
}

Arena::Arena()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	showMiniature();
	m_units.resize(setNumberOfUnits());
}

void Arena::showMiniature()const
{
	std::cout << "Welcome to Arena\n";
}

// Sets number of players, that will play the game
int Arena::setNumberOfUnits()const
{
	return inputNumber("Set number of players: ",
		getMaxNubmerOfPlayers(), getMinNumberOfPlayers());
}

int Arena::getCurrentRound()
{
	return m_round;
}

// Returns the object of a class
Arena& Arena::getInstance()
{
	static Arena instance;
	return instance;
}

void Arena::showUnits()const
{
	system("pause"); system("cls");
	std::cout << "Round: " 
		<< getCurrentRound() + 1 << std::endl;
	for (size_t i = 0; i < m_units.size(); i++)
	{
		std::cout << i + 1 << ". ";
		m_units[i]->showFullInfo();
		setColor();
		std::cout << std::endl;
	}
}

// If some unit is dead, it will be
// removed from the game
void Arena::takeOfLosers()
{
	for (size_t i = 0; i < m_units.size(); i++)
	{
		if (!m_units[i]->isAlive())
		{
			m_units.erase(m_units.begin() + i);
			if (m_unitIndex > i)
				--m_unitIndex;
			i--;
		}
	}
}

bool Arena::isGameOver()const
{
	return std::count_if(m_units.begin(), m_units.end(), [&](const UnitPtr& unit) 
	{ return unit->isAlly(*m_units[0]); }) == m_units.size();
}

void Arena::prepareUnits()
{
	std::vector<std::string> unitsNames;
	std::thread thread([&unitsNames]() { unitsNames = loadFromFile("Names.txt"); });
	if (unitsNames.empty())
		unitsNames = m_reserveNames;
	ThreadGuard guard(thread);
	int teamNumber = 1;
	auto unitGenerator = [&unitsNames, &thread, &teamNumber]()
	{	
		enum { WARRIOR = 1, WIZARD };
		std::vector<UnitFactoryPtr> unitFactories({ 
			UnitFactoryPtr(new WarriorFactory()),
			UnitFactoryPtr(new WizardFactory()) });
		index factoryNumber = inputNumber("1. Warrior 2. "
			"Wizard\nChoose unit type: ", WIZARD, WARRIOR);
		UnitPtr unit = unitFactories[factoryNumber - 1]->createUnit();
		if (thread.joinable())
			thread.join();
		unit->setName(unitsNames[randomNumber(unitsNames.size() - 1)]);
		unit->setTeam(teamNumber);
		system("cls");
		teamNumber++;
		return unit;
	};
	std::generate(m_units.begin(), m_units.end(), unitGenerator);
}

void Arena::proposeToPlayTeams()
{
	const int MIN_PLAYERS_TO_PLAY_TEAMS = 2;
	const int MIN_TEAMS_NUMBER = 2;
	if (m_units.size() > MIN_PLAYERS_TO_PLAY_TEAMS)
	{
		const bool answer = static_cast<bool>(inputNumber(teamPlayQuest, YES, NO));
		if (YES == answer)
		{
			size_t teamsNumber = inputNumber("Enter teams"
				" number: ", m_units.size(), MIN_TEAMS_NUMBER);
			std::vector<Gladiators> teams = breakIntoTeams(teamsNumber);
			pushAlliesToArena(teams);
		}
	}
	std::shuffle(m_units.begin(), m_units.end(), 
		std::mt19937(std::random_device()()));
}

std::vector<Gladiators> Arena::breakIntoTeams(size_t teamsNumber)
{
	index unitIndex;
	const size_t QUIT = 0;
	const size_t LIMIT = m_units.size();
	std::vector<Gladiators> teams;
	for (size_t i = 0; i < teamsNumber; i++)
	{
		teams.resize(i + 1);
		for (size_t j = 0; j < LIMIT; j++)
		{
			showUnits();
			unitIndex = inputNumber("Choose unit for " + std::to_string(i + 1)
				+ " team" + " (0 to stop): ", m_units.size(), QUIT);
			if (QUIT == unitIndex || m_units.empty())
				break;
			teams[i].push_back(m_units[unitIndex - 1]);
			m_units[unitIndex - 1]->setTeam(i + 1);
			m_units.erase(m_units.begin() + (unitIndex - 1));
			if (m_units.size() == (teamsNumber - i - 1))
				break;
			system("cls");
		}
	}
	return teams;
}

void Arena::pushAlliesToArena(const std::vector<Gladiators>& teams)
{
	std::back_insert_iterator<Gladiators> iter(m_units);
	for (auto& team : teams)
		std::copy(team.begin(), team.end(), iter);
}

void Arena::playCastStep()
{
	m_magicToCast = m_units[m_unitIndex]->chooseMagicToCast(m_units);
	m_unitToCast = m_units[m_unitIndex]->chooseUnitToCast(m_magicToCast, m_units);
	if (nullptr != m_unitToCast && nullptr != m_magicToCast)
	{
		auto& messager = Messager::getIncstance();
		messager.writeMessage(m_units[m_unitIndex]->getName(),
			" charmed ", m_unitToCast->getName(),
			" with ", m_magicToCast->getName() + "\n");
		m_units[m_unitIndex]->castMagic(*m_unitToCast, m_magicToCast);
		rewardKiller(m_unitToCast);
	}
}

void Arena::playAttackStep()
{
	if (!isGameOver())
	{
		m_unitToAttack = m_units[m_unitIndex]->chooseUnitToAttack(m_units);
		if (nullptr != m_unitToAttack)
		{
			auto& messager = Messager::getIncstance();
			messager.writeMessage(m_units[m_unitIndex]->getName(),
				" attacked ", m_unitToAttack->getName() + "\n");
			m_units[m_unitIndex]->injureUnit(*m_unitToAttack);
			rewardKiller(m_unitToAttack);
		}
	}
}

void Arena::rewardKiller(UnitPtr victim)
{
	if (!victim->isAlive())
	{
		std::cout << m_units[m_unitIndex]->getName() << " slashed " << 
			victim->getName() << std::endl;
		m_units[m_unitIndex]->levelUp();
		m_units[m_unitIndex]->takeKilledUnitMagic(*victim);
	}
}

void Arena::goNextUnit()
{
	m_unitIndex++;
	if (m_unitIndex >= m_units.size())
	{
		m_unitIndex = 0;
		m_round++;
		goNewRound();
	}
}

void Arena::goNewRound()
{
	for (auto unit : m_units)
		unit->moveIntoNewRound();
}