#include "SuperHero.h"
#include "ProfessionBasedSuperHero.h"

int main()
{
	SuperHero mushmush;
	SuperHero batman("batman", 23.5, false);
	SuperHero OldHero("old", 70, false);
	ProfessionBasedSuperHero professionalBatman("professional batman", 28.5, true, "hunter", 6);
	auto copy_of_batman(professionalBatman);
	return 0;
}
