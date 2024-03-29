#include "AnimalBasedSuperHero.h"
//=================================================================================//
// constructors
//=================================================================================//
AnimalBasedSuperHero::AnimalBasedSuperHero() : _animal(nullptr)
{
	
}
AnimalBasedSuperHero::AnimalBasedSuperHero(	const char* name, double age, bool radioactive, const char* animal)
											: SuperHero(name, age, radioactive) // call superhero constructor
{
	// build class args
	setAnimal(animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const char* animal)
{
	setAnimal(animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(	const AnimalBasedSuperHero& animalBasedSuperHero) 
											: SuperHero(animalBasedSuperHero) // call SuperHero copy constructor
{
	setAnimal(animalBasedSuperHero.getAnimal());
}

// destructor
AnimalBasedSuperHero::~AnimalBasedSuperHero()
{
	if (!_animal)
	{
		delete _animal;
	}
}
//=================================================================================//
// set functions
//=================================================================================//
void AnimalBasedSuperHero::setAnimal(const char* animal)
{
	// check if name is valid
	if (!animal)
	{
		// throw "[AnimalBasedSuperHero::setName] invalid name!"
		return;
	}
	// check if addresses are the same
	if (animal == _animal)
	{
		return;
	}
	// remove the name if needed
	if (!_animal)
	{
		delete _animal;
	}
	// alloc new size for the name
	_animal = new char[strlen(animal) + 1]();
	// unsafe function
	strcpy(_animal, animal);
}
//=================================================================================//
// get functions
//=================================================================================//
const char* AnimalBasedSuperHero::getAnimal() const
{
	return _animal;
}
//=================================================================================//
// load and save functions
//=================================================================================//

// file type
// SuperHero
// [szAnimal]			int			4 bytes
// [Animal]				char *		szAnimal

void AnimalBasedSuperHero::load(ifstream& in_file)
{
	SuperHero::load(in_file);
	// ProfessionBasedSuperHero
	auto szAnimal = 0;
	// read _profession size
	in_file.read((char*)&szAnimal, sizeof(szAnimal));
	// read _profession
	auto tempAnimal = new char[szAnimal + 1]();
	in_file.read((char*)tempAnimal, szAnimal);
	setAnimal(tempAnimal);
	delete[]tempAnimal;
}

void AnimalBasedSuperHero::save(ofstream& out_file) const
{
	// SuperHero
	SuperHero::save(out_file);
	// AnimalBasedSuperHero
	// get length of char *
	int szAnimal = strlen(getAnimal());
	// write _profession size
	out_file.write((char*)&szAnimal, sizeof(szAnimal));
	// write _profession
	out_file.write(_animal, szAnimal);
}