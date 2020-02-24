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

enum : unsigned { WARRIOR = 1, WIZARD };

void invoke(const GameStep& method)
{
	(Arena::getInstance().*method)();
}

void playGameStep(Arena& arena, const GameStep& method)
{
	arena.showUnits();
	invoke(method);
	arena.takeOfLosers();
}

void playGameSteps(Arena& arena)
{
	enum : unsigned { CAST_STEP, ATTACK_STEP };
	static unsigned gameStep = CAST_STEP;
	playGameStep(arena, gameSteps[gameStep]);
	if (++gameStep >= gameSteps.size())
	{
		gameStep = CAST_STEP;
		arena.goNextUnit();
	}
}

void announceWinner(Arena& arena)
{
	arena.showUnits();
	std::cout << "Became the winner\n";
}

// reserve names for computer players, can be needed
// if file with names is empty or is not found
const Strings m_reserveNames =
{
	"Bill","Glen","Mark","Gven","Sally","Opera",
	"Dgill","Sam","Oliver","Gvinett","Tony","Moody",
	"Sigma","Anna","Vector","Trench","Rex","Paul",
	"Bruno","Silvia","John","Tirion","Mortal","Wolf",
	"Elizabeth","Unberto","Izabell","Oxford","Mark"
};

int Arena::m_round = 0;

constexpr int Arena::getMaxNubmerOfPlayers()const
{
	return 6;
}

constexpr int Arena::getMinNumberOfPlayers()const
{
	return 2;
}

Arena::Arena()
{
	
}

void Arena::showMiniature()const
{
	setColor(LIGHT_RED);
	std::cout << R"(
        ___           ___           ___           ___           ___     
       /\  \         /\  \         /\  \         /\__\         /\  \    
      /::\  \       /::\  \       /::\  \       /::|  |       /::\  \   
     /:/\:\  \     /:/\:\  \     /:/\:\  \     /:|:|  |      /:/\:\  \  
    /::\~\:\  \   /::\~\:\  \   /::\~\:\  \   /:/|:|  |__   /::\~\:\  \ 
   /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /:/ |:| /\__\ /:/\:\ \:\__\
   \/__\:\/:/  / \/_|::\/:/  / \:\~\:\ \/__/ \/__|:|/:/  / \/__\:\/:/  /
        \::/  /     |:|::/  /   \:\ \:\__\       |:/:/  /       \::/  / 
        /:/  /      |:|\/__/     \:\ \/__/       |::/  /        /:/  /  
       /:/  /       |:|  |        \:\__\         /:/  /        /:/  /   
       \/__/         \|__|         \/__/         \/__/         \/__/    )";
	setColor(LIGHT_GREY);
	std::cout << R"(     
      _,.
    ,` -.)
   ( _/-\\-._
  /,|`--._,-^|            ,
  \_| |`-._/||          ,'|       Made in MS Visual Studio 2017
    |  `-, / |         /  /       Created with Visual C++11
    |     || |        /  /        Author: Ilya Hadleuski
     `r-._||/   __   /  /         E-mail: godleevsky2015@gmail.com
 __,-<_     )`-/  `./  /
'  \   `---'   \   /  /
    |           |./  /
    /           //  /
\_/' \         |/  /
 |    |   _,^-'/  /
 |    , ``  (\/  /_
  \,.->._    \X-=/^
  (  /   `-._//^`
   `Y-.____(__}
    |     {__)
          ())";
	setColor();
}

int Arena::setNumberOfUnits()const
{
	std::cout << std::endl;
	return inputNumber("\t\t\tSet number of players: ",
		getMaxNubmerOfPlayers(), getMinNumberOfPlayers());
}

int Arena::getCurrentRound()
{
	return m_round;
}

Arena& Arena::getInstance()
{
	static Arena instance;
	return instance;
}

void Arena::showUnits()const
{
	system("pause"); system("cls");
	std::cout << "Round: " << getCurrentRound() + 1 << "\n";
	for (size_t i = 0; i < m_units.size(); i++)
	{
		std::cout << i + 1 << ". ";
		m_units[i]->showFullInfo();
	}
}

void Arena::takeOfLosers()
{
	const auto currentUnit = *m_currentUnit;
	m_units.erase(std::remove_if(m_units.begin(), m_units.end(),
		std::mem_fn(&Unit::isDead)), m_units.end());
	m_currentUnit = std::find_if(m_units.begin(), m_units.end(),
		std::bind1st(std::equal_to<UnitPtr>(), currentUnit));
}

bool Arena::isGameOver()const
{
	return std::count_if(m_units.begin(), m_units.end(), [&](const UnitPtr& unit) 
	{ return unit->isAlly(**m_currentUnit); }) == m_units.size();
}

void Arena::prepareUnits()
{
	m_units.resize(setNumberOfUnits());
	Strings unitsNames;
	std::thread thread([&unitsNames]() { unitsNames = loadFromFile("Names.txt"); });
	ThreadGuard guard(thread);
	int teamNumber = 1;
	std::vector<UnitFactoryPtr> unitFactories({
		UnitFactoryPtr(new WarriorFactory()),
		UnitFactoryPtr(new WizardFactory()) });
	auto unitGenerator = [&]()
	{		
		index factoryNumber = inputNumber("\t\t\t1. Warrior 2. "
			"Wizard\n\t\t\tChoose unit type: ", WIZARD, WARRIOR);
		UnitPtr unit = unitFactories[factoryNumber - 1]->createUnit();
		if (thread.joinable())
			thread.join();
		if (unitsNames.empty())
			unitsNames = m_reserveNames;
		unit->setName(unitsNames[randomNumber((int)unitsNames.size() - 1)]);
		unit->setTeam(teamNumber++);
		return unit;
	};
	std::generate(m_units.begin(), m_units.end(), unitGenerator);
}

void Arena::proposeToPlayTeams()
{	
	constexpr int MIN_PLAYERS_TO_PLAY_TEAMS = 2;
	constexpr int MIN_TEAMS_NUMBER = 2;
	if (m_units.size() > MIN_PLAYERS_TO_PLAY_TEAMS)
	{
		const bool wantsToPlayInTeams = static_cast<bool>(inputNumber(teamPlayQuest, YES, NO));
		if (wantsToPlayInTeams)
		{
			const size_t teamsNumber = (size_t)inputNumber("Enter teams"
				" number: ", (int)m_units.size(), MIN_TEAMS_NUMBER);
			auto teams = breakIntoTeams(teamsNumber);
			for (auto& team : teams)
				std::copy(team.begin(), team.end(), std::back_inserter(m_units));
		}
	}
}

void Arena::setStartUnit()
{
	std::shuffle(m_units.begin(), m_units.end(),
		std::mt19937(std::random_device()()));
	m_currentUnit = m_units.begin();
	m_round = 0;
}

std::vector<Gladiators> Arena::breakIntoTeams(size_t teamsNumber)
{
	index unitIndex;
	constexpr int QUIT = 0;
	const size_t LIMIT = m_units.size();
	std::vector<Gladiators> teams;
	for (size_t i = 0; i < teamsNumber; i++)
	{
		teams.resize(i + 1);
		for (size_t j = 0; j < LIMIT; j++)
		{
			showUnits();
			unitIndex = inputNumber("Choose unit for " + std::to_string(i + 1)
				+ " team" + " (0 to stop): ", (int)m_units.size(), QUIT);
			if (QUIT == unitIndex || m_units.empty())
				break;
			teams[i].push_back(m_units[unitIndex - 1]);
			m_units[unitIndex - 1]->setTeam(int(i) + 1);
			m_units.erase(m_units.begin() + (unitIndex - 1));
			if (m_units.size() == (teamsNumber - i - 1))
				break;
			system("cls");
		}
	}
	return teams; 
}

void Arena::playCastStep()
{
	auto m_magicToCast = (*m_currentUnit)->chooseMagicToCast(m_units);
	auto m_unitToCast = (*m_currentUnit)->chooseUnitToCast(m_magicToCast, m_units);
	if (nullptr != m_unitToCast && nullptr != m_magicToCast)
	{
		std::cout << (*m_currentUnit)->getName()
			<< " charmed " << m_unitToCast->getName()
			<< " with " << m_magicToCast->getName() << std::endl;
		(*m_currentUnit)->castMagic(*m_unitToCast, m_magicToCast);
		rewardKiller(m_unitToCast);
	}
}

void Arena::playAttackStep()
{
	auto m_unitToAttack = (*m_currentUnit)->chooseUnitToAttack(m_units);
	if (nullptr != m_unitToAttack)
	{
		std::cout << (*m_currentUnit)->getName()
			<< " attacked " << m_unitToAttack->getName() << std::endl;
		(*m_currentUnit)->injureUnit(*m_unitToAttack);
		rewardKiller(m_unitToAttack);
	}
}

void Arena::rewardKiller(UnitPtr victim)
{
	if (victim->isDead())
	{
		signal(Signals::WAIT_TIME, Signals::DEATH);
		std::cout << (*m_currentUnit)->getName()
			<< " slashed " << victim->getName() << std::endl;
		(*m_currentUnit)->levelUp();
		(*m_currentUnit)->takeKilledUnitMagic(*victim);
	}
}

void Arena::goNextUnit()
{
	if (++m_currentUnit >= m_units.end())
	{   
		m_currentUnit = m_units.begin();
		m_round++;
		goNewRound();
	}
}

void Arena::goNewRound()
{
	std::for_each(m_units.begin(), m_units.end(), 
		std::mem_fn(&Unit::moveIntoNewRound));
}