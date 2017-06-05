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
// file type
// SuperHero
// AnimalBasedSuperHero
// [webSize]			double			8 bytes



#define CLASS_ID "SP"
#define CLASS_ID_SIZE 2

void Spiderman::load(ifstream& in_file)
{
	AnimalBasedSuperHero::load(in_file);
	// read _webSize
	in_file.read((char*)&_webSize, sizeof(_webSize));
}

void Spiderman::save(ofstream& out_file) const
{
	// AnimalBasedSuperHero
	AnimalBasedSuperHero::save(out_file);

	//Spiderman
	// write _webSize
	out_file.write((char*)&_webSize, sizeof(_webSize));
}