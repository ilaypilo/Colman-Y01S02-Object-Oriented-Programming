
#ifndef AVENGERS__H_
#define AVENGERS__H_

#include "CaptainSpider.h"
#include "SuperHero.h"
#include "Spiderman.h"
#include "AnimalBasedSuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "CaptainAmerica.h"
class Avengers
{
public:
	Avengers();
	~Avengers();

	void saveType(ofstream& out, const SuperHero* hero) const;
	void save(ofstream& out) const;
	void load(ifstream& in);

	void setSuperHeros(SuperHero** superHeros, int size);
	SuperHero** getSuperHeros() const;

private:
	SuperHero** _superHeros;
	int _numSuperHeros;
};

#endif