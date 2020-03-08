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

// reserve names for computer players, can be needed
// if file with names is empty or is not found
const Strings reserveNames =
{
	"Bill","Glen","Mark","Gven","Sally","Opera",
	"Dgill","Sam","Oliver","Gvinett","Tony","Moody",
	"Sigma","Anna","Vector","Trench","Rex","Paul",
	"Bruno","Silvia","John","Tirion","Mortal","Wolf",
	"Elizabeth","Unberto","Izabell","Oxford","Mark"
};

int Arena::m_round = 0;

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
	setColor(LIGHT_CYAN);
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

void Arena::prepareArena()
{
	enum { PREPARE_STEPS = 4 };
	constexpr ArenaActions<PREPARE_STEPS> prepareSteps{
		&Arena::setNumberOfUnits,
		&Arena::prepareUnits,
		&Arena::proposeToPlayTeams,
		&Arena::setStartUnit
	};
	for (auto step : prepareSteps)
		(this->*step)();
}

void Arena::playArena()
{
	while (!isGameOver())
		playGameSteps();
}

void Arena::announceWinner()const
{
	showUnits();
	std::cout << "Became the winner\n";
}

void Arena::playGameStep(const GameStep& gameStep)
{
	showUnits();
	(this->*gameStep)();
	takeOfLosers();
}

void Arena::playGameSteps()
{
	enum { CAST_STEP, ATTACK_STEP, GAME_STEPS };
	constexpr ArenaActions<GAME_STEPS> gameSteps{
		&Arena::playCastStep,
		&Arena::playAttackStep
	};
	static int gameStep = CAST_STEP;
	playGameStep(gameSteps.at(gameStep));
	if (++gameStep > ATTACK_STEP)
	{
		gameStep = CAST_STEP;
		goNextUnit();
	}
}

void Arena::setNumberOfUnits()
{
	const char* setMsg 
		= "\n\t\t\tSet number of players: ";
	enum { MAX_NUMBER_OF_UNITS = 6, 
		MIN_NUMBER_OF_UNITS = 2 };
	m_units.clear();
	const int numberOfUnits = 
		inputNumber(setMsg, 
		MAX_NUMBER_OF_UNITS, 
		MIN_NUMBER_OF_UNITS);	
	m_units.resize(numberOfUnits);
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
	Strings unitsNames;
	std::thread thread([&unitsNames]() { unitsNames = loadFromFile("Names.txt"); });
	ThreadGuard guard(thread);
	int teamNumber = 1;
	constexpr int UNITS_FACTORIES = 2;
	const std::array<UnitFactoryPtr, UNITS_FACTORIES> unitFactories({
		UnitFactoryPtr(new WarriorFactory()),
		UnitFactoryPtr(new WizardFactory()) });
	const char* chooseFactoryMsg = "\t\t\t1. Warrior 2. Wizard\n\t\t\tChoose unit type: ";
	std::generate(m_units.begin(), m_units.end(), [&]()
	{
		enum { WARRIOR = 1, WIZARD };
		const index factoryNumber = inputNumber(chooseFactoryMsg, WIZARD, WARRIOR);
		auto unit = unitFactories[factoryNumber - 1]->createUnit();
		if (thread.joinable())
			thread.join();
		if (unitsNames.empty())
			unitsNames = reserveNames;
		unit->setName(unitsNames[randomNumber((int)unitsNames.size() - 1)]);
		unit->setTeam(teamNumber++);
		return unit;
	});
}

void Arena::proposeToPlayTeams()
{	
	enum { MIN_PLAYERS_TO_PLAY_TEAMS = 2, 
		MIN_TEAMS_NUMBER = 2 };
	if (m_units.size() > MIN_PLAYERS_TO_PLAY_TEAMS)
	{
		const bool wantsToPlayInTeams 
			= static_cast<bool>(inputNumber(teamPlayQuest, YES, NO));
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

Units Arena::breakIntoTeams(size_t teamsNumber)
{
	index unitIndex;
	constexpr auto QUIT = 0;
	const auto LIMIT = m_units.size();
	Units teams;
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