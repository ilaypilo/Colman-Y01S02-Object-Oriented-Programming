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
void CaptainAmerica::load(ifstream& in_file)
{
	
}
void CaptainAmerica::save(ofstream& out_file) const
{
	
}