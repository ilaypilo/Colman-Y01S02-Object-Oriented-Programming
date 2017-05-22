#pragma once
#include "Room.h"

class SealedRoom : public Room
{
public:
	SealedRoom(int tunnel1, int tunnel2, int tunnel3) : Room(tunnel1, tunnel2, tunnel3) {}
	virtual void type() {};
};
