#include "ProfessionBasedSuperHero.h"

// default constructor
ProfessionBasedSuperHero::ProfessionBasedSuperHero() : _yearsExperience(0), _profession(nullptr)
{
	
}
// constructor with all args
ProfessionBasedSuperHero::ProfessionBasedSuperHero(	const char* name, double age, bool radioactive, // superhero args
													const char* profession, int yearsExperience) // ProfessionBasedSuperHero args
													: SuperHero(name, age, radioactive) // call superhero constructor
													
{
	// build class args
	setProfession(profession);
	setYearsExperience(yearsExperience);
}
// constructor with class's args
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* profession, int yearsExperience)
{
	setProfession(profession);
	setYearsExperience(yearsExperience);
}

// copy constructor
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const ProfessionBasedSuperHero& professionBasedSuperHero) : SuperHero(professionBasedSuperHero)
{
	//SuperHero::SuperHero(professionBasedSuperHero.getName(), professionBasedSuperHero.getAge(), professionBasedSuperHero.getRadioactive());
	setProfession(professionBasedSuperHero.getProfession());
	setYearsExperience(professionBasedSuperHero.getYearsExperience());
}

// destructor 
ProfessionBasedSuperHero::~ProfessionBasedSuperHero()
{
	// call SuperHero destructor
	SuperHero::~SuperHero();
	if (!_profession)
	{
		delete _profession;
	}
}

//=================================================================================//
// set functions
//=================================================================================//

void ProfessionBasedSuperHero::setProfession(const char* profession)
{
	// check if name is valid
	if (!profession)
	{
		// throw "[ProfessionBasedSuperHero::setName] invalid name!"
		return;
	}
	// remove the name if needed
	if (!_profession)
	{
		delete _profession;
	}
	// alloc new size for the name
	_profession = new char[strlen(profession) + 1]();
	// unsafe function
	strcpy(_profession, profession);
}

void ProfessionBasedSuperHero::setYearsExperience(int yearsExperience)
{
	_yearsExperience = yearsExperience;
}
//=================================================================================//
// get functions
//=================================================================================//

//const char* ProfessionBasedSuperHero::getProfession() const { return _profession; }
int ProfessionBasedSuperHero::getYearsExperience() const
{
	return _yearsExperience;
}
//=================================================================================//
// load and save functions
//=================================================================================//

void ProfessionBasedSuperHero::load(ifstream& in_file)
{
	
}
void ProfessionBasedSuperHero::save(ofstream& out_file) const
{
	
}