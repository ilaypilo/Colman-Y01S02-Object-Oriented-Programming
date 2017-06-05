#include "SuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "AnimalBasedSuperHero.h"
#include "CaptainAmerica.h"
#include "Spiderman.h"

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

	auto capten_california = new CaptainAmerica("capten california", 39, true, "professor", 9, 40);
	auto copy_of_capten_california(*capten_california);
	delete capten_california;

	auto black_spiderman = new Spiderman("black spiderman", 22, true, "spider", 5);
	auto copy_of_black_spiderman(*black_spiderman);
	delete black_spiderman;


	return 0;
}
