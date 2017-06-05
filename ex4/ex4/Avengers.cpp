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
char SuperHeroId[] = "SH"; //SuperHero
char AnimalBasedSuperHeroId[] = "AB"; //AnimalBasedSuperHero
char SpidermanId[] = "SP"; //Spiderman
char ProfessionBasedSuperHeroId[] = "PB"; //ProfessionBasedSuperHero
char CaptainAmericaId[] = "CA"; //CaptainAmerica
char CaptainSpiderId[] = "CS"; //CaptainSpider

void Avengers::saveType(ofstream& out, const SuperHero* hero) const
{
	char *classId = nullptr;
	if (typeid(*hero).name() == typeid(SuperHero).name())
		classId = SuperHeroId;
	else if (typeid(*hero).name() == typeid(AnimalBasedSuperHero).name())
		classId = AnimalBasedSuperHeroId;
	else if (typeid(*hero).name() == typeid(Spiderman).name())
		classId = SpidermanId;
	else if (typeid(*hero).name() == typeid(ProfessionBasedSuperHero).name())
		classId = ProfessionBasedSuperHeroId;
	else if (typeid(*hero).name() == typeid(CaptainAmerica).name())
		classId = CaptainAmericaId;
	else if (typeid(*hero).name() == typeid(CaptainSpider).name())
		classId = CaptainSpiderId;

	out.write(classId, CLASS_ID_SIZE);
}
void Avengers::save(ofstream& out) const
{
	// save the size of the array
	out.write((char*)&_numSuperHeros, sizeof(_numSuperHeros));
	// save all objects
	for (auto i=0; i < _numSuperHeros; i++)
	{
		if (_superHeros[i])
		{
			Avengers::saveType(out, _superHeros[i]);
			_superHeros[i]->save(out);
		}
	}
}
bool compareClassId(char * classId, char * constId)
{
	return (classId[0] == constId[0] && classId[1] == constId[1]);
}

void Avengers::load(ifstream& in)
{
	// load the size of the array
	in.read((char*)&_numSuperHeros, sizeof(_numSuperHeros));
	// alloc memory in the array
	if(_superHeros)
	{
		delete[]_superHeros;
	}
	_superHeros = new SuperHero*[_numSuperHeros]();
	// load all objects
	for (auto i = 0; i < _numSuperHeros; i++)
	{
		// get the hero type
		char classId[2];
		in.read(classId, CLASS_ID_SIZE);
		// alloc the object
		if (compareClassId(classId, SuperHeroId))
			_superHeros[i] = new SuperHero;
		else if (compareClassId(classId, AnimalBasedSuperHeroId))
			_superHeros[i] = new AnimalBasedSuperHero;
		else if (compareClassId(classId, SpidermanId))
			_superHeros[i] = new Spiderman;
		else if (compareClassId(classId, ProfessionBasedSuperHeroId))
			_superHeros[i] = new ProfessionBasedSuperHero;
		else if (compareClassId(classId, CaptainAmericaId))
			_superHeros[i] = new CaptainAmerica;
		else if (compareClassId(classId, CaptainSpiderId))
			_superHeros[i] = new CaptainSpider;
		// load the args
		_superHeros[i]->load(in);
	}
}

void Avengers::setSuperHeros(SuperHero** superHeros, int size)
{
	if (size > 0)
	{
		_numSuperHeros = size;
		// alloc memory in the array
		if (_superHeros)
		{
			delete[]_superHeros;
		}
		_superHeros = new SuperHero*[_numSuperHeros]();
		// deep copy for all objects
		for (auto i = 0; i < size; i++)
		{
			if (typeid(*superHeros[i]).name() == typeid(SuperHero).name())
				_superHeros[i] = new SuperHero(*superHeros[i]);
			else if (typeid(*superHeros[i]).name() == typeid(AnimalBasedSuperHero).name())
				_superHeros[i] = new AnimalBasedSuperHero(*dynamic_cast<AnimalBasedSuperHero*>(superHeros[i]));
			else if (typeid(*superHeros[i]).name() == typeid(Spiderman).name())
				_superHeros[i] = new Spiderman(*dynamic_cast<Spiderman*>(superHeros[i]));
			else if (typeid(*superHeros[i]).name() == typeid(ProfessionBasedSuperHero).name())
				_superHeros[i] = new ProfessionBasedSuperHero(*dynamic_cast<ProfessionBasedSuperHero*>(superHeros[i]));
			else if (typeid(*superHeros[i]).name() == typeid(CaptainAmerica).name())
				_superHeros[i] = new CaptainAmerica(*dynamic_cast<CaptainAmerica*>(superHeros[i]));
			else if (typeid(*superHeros[i]).name() == typeid(CaptainSpider).name())
				_superHeros[i] = new CaptainSpider(*dynamic_cast<CaptainSpider*>(superHeros[i]));
		}
	}

}

// return pointer to the superheroes
SuperHero** Avengers::getSuperHeros() const
{
	return _superHeros;
}