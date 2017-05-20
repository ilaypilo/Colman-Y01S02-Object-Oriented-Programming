#pragma once

#include <string>
#include <vector>
#include "Room.h"

using namespace std;

class Room;
class Cave
{
	Room* _rooms[20];
	// tunnels
	vector<vector<int>> tunnels = { { 2, 18, 19 },
									{ 5, 17, 18 },
									{ 0, 4, 17 },
									{ 7, 16, 19 },
									{ 2, 6, 15 },
									{ 1, 9, 14 },
									{ 4, 8, 13 },
									{ 3, 11, 12 },
									{ 6, 10, 11 },
									{ 5, 10, 13 },
									{ 8, 9, 12 },
									{ 7, 8, 15 },
									{ 7, 10, 14 },
									{ 6, 9, 17 },
									{ 5, 12, 16 },
									{ 4, 11, 19 },
									{ 3, 14, 18 },
									{ 1, 2, 13 },
									{ 0, 1, 16 },
									{ 0, 3, 15 } };
public:
    Cave(const int* const sealedRooms, int size);
    ~Cave();
    const Room* getRoomAtIndex(int index) const;
    void plotHazard(int idx, const std::string& eventName);
	void plotPlayerIdx(int idx);
    int findMushMush(void) const;
	void movePlayer(int idx);
    std::string playerAttack(int idx);
    std::string playerClash(int idx);
	bool gameOver() const;
    
    void hazardNearPlayer(std::string* hazards) const;
};
