#ifndef  ANIMAL_BASED_SUPERHERO__H_
#define ANIMAL_BASED_SUPERHERO__H_



#include "SuperHero.h"
class AnimalBasedSuperHero :
	virtual public SuperHero
{
public:
	AnimalBasedSuperHero();
	AnimalBasedSuperHero(const char* name, double age, bool radioactive, const char* animal);
	AnimalBasedSuperHero(const char* animal);
	AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero);
	virtual ~AnimalBasedSuperHero();

	void setAnimal(const char* animal);
	const char* getAnimal() const;

	virtual void load(ifstream& in_file);
	virtual void save(ofstream& out_file) const;

protected:
	char* _animal;
};

#endif // ! ANIMAL_BASED_SUPERHERO__H_