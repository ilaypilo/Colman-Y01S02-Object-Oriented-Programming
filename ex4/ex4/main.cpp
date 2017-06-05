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
	ProfessionBasedSuperHero professional_batman("professional batman", 28.5, true, "hunter", 6);
	auto copy_of_professional_batman(professional_batman);
	auto animal_batman = new AnimalBasedSuperHero("animal batman", 33, false, "bat");
	auto copy_of_animal_batman(*animal_batman);

	auto captain_california = new CaptainAmerica("capten california", 39, true, "professor", 9, 40);
	auto copy_of_captain_california(*captain_california);
	
	auto black_spiderman = new Spiderman("black spiderman", 22, true, "spider", 5);
	auto copy_of_black_spiderman(*black_spiderman);
	

	auto red_captain_spider = new CaptainSpider("capten california", 39, true, "professor", 9, 40, "unhuman", 6);
	auto copy_of_red_captain_spider(*red_captain_spider);
	delete red_captain_spider;


	// SUPER HERO
	ofstream f1("SH.bin", ios::binary);
	noob_batman.save(f1);
	f1.close();

	SuperHero noob_batman_from_file;
	ifstream f2("SH.bin", ios::binary);
	noob_batman_from_file.load(f2);
	f2.close();


	//ProfessionBasedSuperHero
	ofstream f3("PB.bin", ios::binary);
	professional_batman.save(f3);
	f3.close();

	ProfessionBasedSuperHero professional_batman_from_file;
	ifstream f4("PB.bin", ios::binary);
	professional_batman_from_file.load(f4);
	f4.close();


	//CaptainAmerica
	ofstream f5("CA.bin", ios::binary);
	captain_california->save(f5);
	f5.close();

	CaptainAmerica captain_california_from_file;
	ifstream f6("CA.bin", ios::binary);
	captain_california_from_file.load(f6);
	f6.close();
	delete captain_california;

	//AnimalBasedSuperHero
	ofstream f7("AB.bin", ios::binary);
	animal_batman->save(f7);
	f7.close();

	AnimalBasedSuperHero animal_batman_from_file;
	ifstream f8("AB.bin", ios::binary);
	animal_batman_from_file.load(f8);
	f8.close();
	delete animal_batman;

	//SpiderMan
	ofstream f9("SP.bin", ios::binary);
	black_spiderman->save(f9);
	f9.close();

	Spiderman black_spiderman_from_file;
	ifstream f10("SP.bin", ios::binary);
	black_spiderman_from_file.load(f10);
	f10.close();
	delete black_spiderman;

	return 0;
}
