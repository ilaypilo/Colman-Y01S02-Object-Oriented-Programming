#include "SuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "AnimalBasedSuperHero.h"

int main()
{
	SuperHero mushmush;
	SuperHero noob_batman("batman", 23.5, false);
	SuperHero old_batman("old", 70, false);
	ProfessionBasedSuperHero professionalBatman("professional batman", 28.5, true, "hunter", 6);
	auto copy_of_professional_batman(professionalBatman);
	auto animal_batman = new AnimalBasedSuperHero("animal batman", 33, false, "bat");
	auto copy_of_animal_batman(*animal_batman);
	delete animal_batman;


	return 0;
}
