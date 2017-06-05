#include "SuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "AnimalBasedSuperHero.h"
#include "CaptainAmerica.h"
#include "Spiderman.h"
#include "CaptainSpider.h"

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

	auto captain_california = new CaptainAmerica("capten california", 39, true, "professor", 9, 40);
	auto copy_of_captain_california(*captain_california);
	delete captain_california;

	auto black_spiderman = new Spiderman("black spiderman", 22, true, "spider", 5);
	auto copy_of_black_spiderman(*black_spiderman);
	delete black_spiderman;

	auto red_captain_spider = new CaptainSpider("capten california", 39, true, "professor", 9, 40, "unhuman", 6);
	auto copy_of_red_captain_spider(*red_captain_spider);
	delete red_captain_spider;

	ofstream f1("SH.bin", ios::binary);
	noob_batman.save(f1);
	f1.close();

	SuperHero noob_batman_from_file;
	ifstream f2("SH.bin", ios::binary);
	noob_batman_from_file.load(f2);
	f2.close();

	return 0;
}
