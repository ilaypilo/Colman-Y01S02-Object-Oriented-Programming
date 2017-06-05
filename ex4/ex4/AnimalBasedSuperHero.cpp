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
void AnimalBasedSuperHero::load(ifstream& in_file)
{
	
}
void AnimalBasedSuperHero::save(ofstream& out_file) const
{
	
}