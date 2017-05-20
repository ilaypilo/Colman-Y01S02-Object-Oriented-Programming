#include "Cave.h"
#include "SealedRoom.h"
#include "RegularRoom.h"

// constructor
Cave::Cave(const int* const sealedRooms, int size)
{
	// init rooms and tunnels 0-19 (serial)
	for (auto i = 0; i < 20; i++)
	{
		auto sealed = false;
		for (auto j = 0; j < size; j++)
			if(sealedRooms[j] == i)
			{
				sealed = true;
			}
		if (sealed)
			_rooms[i] = new SealedRoom(tunnels.at(i).at(0), tunnels.at(i).at(1), tunnels.at(i).at(2));
		else
			_rooms[i] = new RegularRoom(tunnels.at(i).at(0), tunnels.at(i).at(1), tunnels.at(i).at(2));
	}
}

// destructor
Cave::~Cave()
{
	for (auto i = 0; i < 20; i++)
	{
		delete _rooms[i];
	}
}


const Room* Cave::getRoomAtIndex(int index) const
{
	return _rooms[index];
}
void Cave::plotHazard(int idx, const std::string& eventName)
{
	//MushMush
	//Pit
	//Bat
	if(idx > 19 || idx < 0 || !_rooms[idx]->roomIsEmpty())
	{
		throw "Invalid Index Exception";
	}
	if (eventName == "MushMush")
		_rooms[idx]->_hazard->setHazardType(Hazard::MushMush);
	else if (eventName == "Pit")
		_rooms[idx]->_hazard->setHazardType(Hazard::Pit);
	else if (eventName == "Bat")
		_rooms[idx]->_hazard->setHazardType(Hazard::Bat);
	else
		throw "Invalid Hazard Exception";
}
void Cave::plotPlayerIdx(int idx){}
int Cave::findMushMush(void) const{}
void Cave::movePlayer(int idx){}
std::string Cave::playerAttack(int idx){}
std::string Cave::playerClash(int idx){}
bool Cave::gameOver() const{}
void Cave::hazardNearPlayer(std::string* hazards) const{}