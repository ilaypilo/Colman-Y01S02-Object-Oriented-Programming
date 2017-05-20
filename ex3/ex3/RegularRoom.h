#pragma once
#pragma once
#include "Room.h"

class RegularRoom : public Room
{
public:
	RegularRoom(int tunnel1, int tunnel2, int tunnel3) : Room(tunnel1, tunnel2, tunnel3) {}
};
