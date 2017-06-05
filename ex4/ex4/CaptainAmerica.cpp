#include "CaptainAmerica.h"

//=================================================================================//
// constructors
//=================================================================================//
CaptainAmerica::CaptainAmerica() : _ageIncludingFreezing(0)
{
	
}
CaptainAmerica::CaptainAmerica(	const char* name, double age, bool radioactive,
								const char* profession, int yearsExperience,
								double ageIncludingFreezing)
								: SuperHero(name, age, radioactive), // call SuperHero constructor
								ProfessionBasedSuperHero(profession, yearsExperience) // call ProfessionBasedSuperHero constructor
{
	setAgeIncludingFreezing(ageIncludingFreezing);
}
CaptainAmerica::CaptainAmerica(	const char* profession, int yearsExperience,
								double ageIncludingFreezing)
								: ProfessionBasedSuperHero(profession, yearsExperience) // call ProfessionBasedSuperHero constructor
{
	setAgeIncludingFreezing(ageIncludingFreezing);
}
CaptainAmerica::CaptainAmerica(double ageIncludingFreezing)
{
	setAgeIncludingFreezing(ageIncludingFreezing);
}

// copy constructor
CaptainAmerica::CaptainAmerica(	const CaptainAmerica& captainAmerica)
								: SuperHero(captainAmerica), // call SuperHero copy constructor
								ProfessionBasedSuperHero(captainAmerica) // call ProfessionBasedSuperHero copy constructor
{
	setAgeIncludingFreezing(captainAmerica.getAgeIncludingFreezing());
}
CaptainAmerica::~CaptainAmerica()
{
	
}
//=================================================================================//
// get functions
//=================================================================================//
double CaptainAmerica::getAgeIncludingFreezing() const
{
	return _ageIncludingFreezing;
}
//=================================================================================//
// set functions
//=================================================================================//
void CaptainAmerica::setAgeIncludingFreezing(double ageIncludingFreezing)
{
	// update only if freeze more the age
	if(ageIncludingFreezing > getAge())
	{
		_ageIncludingFreezing = ageIncludingFreezing;
	}
}
//=================================================================================//
// load and save functions
//=================================================================================//

// file type
// SuperHero
// ProfessionBasedSuperHero
// [ageIncludingFreezing]		double		8 bytes


#define CLASS_ID "CA"
#define CLASS_ID_SIZE 2

void CaptainAmerica::load(ifstream& in_file)
{
	ProfessionBasedSuperHero::load(in_file);
	// read _ageIncludingFreezing
	in_file.read((char*)&_ageIncludingFreezing, sizeof(_ageIncludingFreezing));

}

void CaptainAmerica::save(ofstream& out_file) const
{
	// ProfessionBasedSuperHero
	ProfessionBasedSuperHero::save(out_file);
	// CaptainAmerica
	// write _ageIncludingFreezing
	out_file.write((char*)&_ageIncludingFreezing, sizeof(_ageIncludingFreezing));
}