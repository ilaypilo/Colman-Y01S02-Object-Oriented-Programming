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


#define CLASS_ID_SIZE 2
#define SH "SH" //SuperHero
#define AB "AB" //AnimalBasedSuperHero
#define SP "SP" //Spiderman

#define PB "PB" //ProfessionBasedSuperHero
#define CA "CA" //CaptainAmerica
#define CS "CS" //CaptainSpider

void Avengers::saveType(ofstream& out, const SuperHero* hero) const
{
	char *classId = nullptr;
	if (typeid(*hero).name() == typeid(SuperHero).name())
		classId = SH;
	else if (typeid(*hero).name() == typeid(AnimalBasedSuperHero).name())
		classId = AB;
	else if (typeid(*hero).name() == typeid(Spiderman).name())
		classId = SP;
	else if (typeid(*hero).name() == typeid(ProfessionBasedSuperHero).name())
		classId = PB;
	else if (typeid(*hero).name() == typeid(CaptainAmerica).name())
		classId = CA;
	else if (typeid(*hero).name() == typeid(CaptainSpider).name())
		classId = CS;
	out.write(classId, CLASS_ID_SIZE);
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