#include "CaptainSpider.h"

//=================================================================================//
// constructors
//=================================================================================//
CaptainSpider::CaptainSpider()
{
	
}
CaptainSpider::CaptainSpider(	const char* name, double age, bool radioactive,
								const char* profession, int yearsExperience,
								double ageIncludingFreezing,
								const char* animal,
								double webSize)
								: SuperHero(name, age, radioactive), // call SuperHero constructor
								Spiderman(animal, webSize), // call Spiderman constructor
								CaptainAmerica(profession, yearsExperience, ageIncludingFreezing) // call CaptainAmerica constructor
{
	
}
CaptainSpider::CaptainSpider(	const char* profession, int yearsExperience,
								double ageIncludingFreezing,
								const char* animal,
								double webSize)
								: Spiderman(animal, webSize), // call Spiderman constructor
								CaptainAmerica(profession, yearsExperience, ageIncludingFreezing) // call CaptainAmerica constructor
{
	
}
CaptainSpider::CaptainSpider(	double ageIncludingFreezing,
								double webSize)
								: Spiderman(webSize), // call Spiderman constructor
								CaptainAmerica(ageIncludingFreezing) // call CaptainAmerica constructor
{
	
}
CaptainSpider::CaptainSpider(	const CaptainSpider& captainSpider)
								: SuperHero(captainSpider), // call SuperHero copy constructor
								Spiderman(captainSpider), // call AnimalBasedSuperHero copy constructor
								CaptainAmerica(captainSpider) // call AnimalBasedSuperHero copy constructor
{
	
}
CaptainSpider::~CaptainSpider()
{
	
}
//=================================================================================//
// load and save functions
//=================================================================================//
void CaptainSpider::load(ifstream& in_file)
{
	
}
void CaptainSpider::save(ofstream& out_file) const
{
	
}