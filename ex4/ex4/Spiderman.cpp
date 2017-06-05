#include "Spiderman.h"
//=================================================================================//
// constructors
//=================================================================================//
Spiderman::Spiderman() : _webSize(0)
{
	
}
Spiderman::Spiderman(	const char* name, double age, bool radioactive,
						const char* animal,
						double webSize)
						: SuperHero(name, age, radioactive), // call SuperHero constructor
						AnimalBasedSuperHero(animal) // call AnimalBasedSuperHero constructor
{
	setWebSize(webSize);
}
Spiderman::Spiderman(	const char* animal,
						double webSize)
						: AnimalBasedSuperHero(animal) // call AnimalBasedSuperHero constructor
{
	setWebSize(webSize);
}

Spiderman::Spiderman(double webSize)
{
	setWebSize(webSize);
}
Spiderman::Spiderman(	const Spiderman& spiderman)
						: SuperHero(spiderman), // call SuperHero copy constructor
						AnimalBasedSuperHero(spiderman) // call AnimalBasedSuperHero copy constructor
{
	setWebSize(spiderman.getWebSize());
}
Spiderman::~Spiderman()
{
	
}
//=================================================================================//
// get functions
//=================================================================================//
double Spiderman::getWebSize() const
{
	return _webSize;
}
//=================================================================================//
// set functions
//=================================================================================//
void Spiderman::setWebSize(double webSize)
{
	if (webSize >= 0)
	{
		_webSize = webSize;
	}
}
//=================================================================================//
// load and save functions
//=================================================================================//
void Spiderman::load(ifstream& in_file)
{
	
}
void Spiderman::save(ofstream& out_file) const
{
	
}