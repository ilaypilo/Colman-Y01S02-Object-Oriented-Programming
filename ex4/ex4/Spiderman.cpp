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

	// AnimalBasedSuperHero
	// get length of char *
	int szAnimal = strlen(getAnimal());
	// write _profession size
	out_file.write((char*)&szAnimal, sizeof(szAnimal));
	// write _profession
	out_file.write(_animal, szAnimal);

	//Spiderman
	// write _webSize
	out_file.write((char*)&_webSize, sizeof(_webSize));
}