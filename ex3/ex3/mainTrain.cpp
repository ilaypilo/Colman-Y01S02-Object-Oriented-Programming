#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

#include "Cave.h"
#include "SealedRoom.h"

static std::string expectedResults[] =
{
    "Bat is nearPit is nearMushMush is nearYou got MushMush1"
};

static std::string getStatusString(const Cave& c)
{
    string near_player[3];
    c.hazardNearPlayer(near_player);
    
    return near_player[0] + near_player[1] + near_player[2];
}

static std::string integerToString(int x)
{
    std::stringstream s;
    s<<x;
    return s.str();
}

static bool test(void)
{
    Cave cave(NULL, 0);
    std::string status;
    cave.plotPlayerIdx(1);
    cave.plotHazard(9, "MushMush");
    cave.plotHazard(2, "Pit");
    cave.plotHazard(18, "Bat");
    
    status += getStatusString(cave);
    
    bool gotException = false;
    try
    {
        cave.movePlayer(6);
        status += getStatusString(cave);
        status += cave.playerClash(6);
    }
    catch(const char* p)
    {
        gotException = (0 == strcmp(p, "Invalid Index Exception"));
    }
    if (!gotException)
        std::cout<<"Error: Incorrectly Handled Exception\n";
    cave.movePlayer(17);
    status += getStatusString(cave);
    
    cave.movePlayer(13);
    status += getStatusString(cave);
    
    status += cave.playerAttack(9);
    
    status += integerToString(cave.gameOver());
    
    return status == expectedResults[0];
}
int main()
{
    //if (!test())
    //    std::cout<<"Error: Game Logic Error\n";
    //Room* r = new SealedRoom(1,2,3);
    //delete r;
    //std::cout<<"done\n";

	int selaed[5] = { 13,17,1,9,5 };
	Cave cave(selaed, 5);
	cave.plotPlayerIdx(15);
	cave.plotHazard(2, "MushMush");
	cave.findMushMush();
	cave.plotHazard(11, "Pit");
	cave.plotHazard(19, "Bat");
	cout << cave.playerAttack(4) << endl;
	cave.movePlayer(4);
	cout << cave.playerClash(2) << endl;
	cave.gameOver();

    return 0;
}
