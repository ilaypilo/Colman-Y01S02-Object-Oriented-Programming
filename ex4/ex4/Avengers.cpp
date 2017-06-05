#include "SuperHero.h"
#include "Avengers.h"

// default constructor
Avengers::Avengers() : _superHeros(nullptr), _numSuperHeros(0)
{
}

// Destructor
Avengers::~Avengers()
{
	
}

void Avengers::saveType(ofstream& out, const SuperHero* hero) const
{
	
}
void Avengers::save(ofstream& out) const
{
	
}
void Avengers::load(ifstream& in)
{
	
}

void Avengers::setSuperHeros(SuperHero** superHeros, int size)
{
	
}

// return pointer to the superheroes
SuperHero** Avengers::getSuperHeros() const
{
	return _superHeros;
}