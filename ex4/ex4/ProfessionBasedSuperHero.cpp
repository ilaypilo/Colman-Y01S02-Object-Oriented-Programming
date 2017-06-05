#include "ProfessionBasedSuperHero.h"

//=================================================================================//
// constructors
//=================================================================================//

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
ProfessionBasedSuperHero::ProfessionBasedSuperHero(	const ProfessionBasedSuperHero& professionBasedSuperHero) 
													: SuperHero(professionBasedSuperHero) // call SuperHero copy constructor
{
	setProfession(professionBasedSuperHero.getProfession());
	setYearsExperience(professionBasedSuperHero.getYearsExperience());
}

// destructor 
ProfessionBasedSuperHero::~ProfessionBasedSuperHero()
{
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
	// check if addresses are the same
	if (profession == _profession) 
	{
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
	if (yearsExperience >= 0)
	{
		_yearsExperience = yearsExperience;
	}
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

// file type
// SuperHero
// [szProfession]			int			4 bytes
// [Profession]				char *		szProfession
// [yearsExperience]		int			4 bytes

#define CLASS_ID "PB"
#define CLASS_ID_SIZE 2

void ProfessionBasedSuperHero::load(ifstream& in_file)
{
	SuperHero::load(in_file);
	// ProfessionBasedSuperHero
	auto szProfession = 0;
	// read _profession size
	in_file.read((char*)&szProfession, sizeof(szProfession));
	// read _profession
	auto tempProfession = new char[szProfession + 1]();
	in_file.read((char*)tempProfession, szProfession);
	setProfession(tempProfession);
	delete[]tempProfession;
	// read _yearsExperience
	in_file.read((char*)&_yearsExperience, sizeof(_yearsExperience));
}

void ProfessionBasedSuperHero::save(ofstream& out_file) const
{
	// SuperHero
	// get length of char *
	int szName = strlen(getName());
	// write class ID
	out_file.write(CLASS_ID, CLASS_ID_SIZE);
	// write _name size
	out_file.write((char *)&szName, sizeof(szName));
	// write the _name
	out_file.write(_name, szName);
	// write _age
	out_file.write((char*)&_age, sizeof(_age));
	// write _radioactive
	out_file.write((char*)&_radioactive, sizeof(_radioactive));

	// ProfessionBasedSuperHero
	// get length of char *
	int szProfession = strlen(getProfession());
	// write _profession size
	out_file.write((char*)&szProfession, sizeof(szProfession));
	// write _profession
	out_file.write(_profession, szProfession);
	// write _yearsExperience
	out_file.write((char*)&_yearsExperience, sizeof(_yearsExperience));
	
}