#include "Cave.h"
#include "SealedRoom.h"
#include "RegularRoom.h"
#include "MushMush.h"
#include "Pit.h"
#include "Bat.h"
#include <typeinfo>

// constructor
Cave::Cave(const int* const sealedRooms, int size): _playerIndex(-1)
{
	// init rooms and tunnels 0-19 (serial)
	for (auto i = 0; i < 20; i++)
	{
		auto sealed = false;
		for (auto j = 0; j < size; j++)
			if (sealedRooms[j] == i)
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
	if (index < 0 || index >19)
		throw "Invalid Index Exception";
	return _rooms[index];
}
void Cave::plotHazard(int idx, const std::string& eventName) const
{
	if(idx > 19 || idx < 0 || !_rooms[idx]->roomIsEmpty())
	{
		throw "Invalid Index Exception";
	}
	
	if (eventName == "MushMush")
		_rooms[idx]->setHazard(new MushMush);
	else if (eventName == "Pit")
		_rooms[idx]->setHazard(new MushMush);
	else if (eventName == "Bat")
		_rooms[idx]->setHazard(new MushMush);
	else
		throw "Invalid Hazard Exception";
}
void Cave::plotPlayerIdx(int idx)
{
	if (idx < 0 || idx >19|| !_rooms[idx]->roomIsEmpty())
		throw "Invalid Index Exception";
	_playerIndex = idx;
}
int Cave::findMushMush(void) const
{
	for (auto i = 0; i < 20; i++)
	{
		if (_rooms[i]->getHazard())
			if (_rooms[i]->isMushMushHere())
				return i;
	}
	throw "MushMush Not Found Exception";
}
void Cave::movePlayer(int idx)
{
	if (_rooms[_playerIndex]->getTunnel1() == idx)
		_playerIndex = idx;
	else if (_rooms[_playerIndex]->getTunnel2() == idx)
		_playerIndex = idx;
	else if (_rooms[_playerIndex]->getTunnel3() == idx)
		_playerIndex = idx;
	else
		throw "Invalid Index Exception";
}
std::string Cave::playerAttack(int idx)
{
	auto attackFlag = false;
	if (_rooms[_playerIndex]->getTunnel1() != idx && _rooms[_playerIndex]->getTunnel2() != idx && _rooms[_playerIndex]->getTunnel3() != idx)
		throw "Invalid Index Exception";
	string attackMsg;

	if (!_rooms[idx]->attackInRoom(attackMsg))
	{
		auto idxMushMush = findMushMush();
		if (_rooms[_rooms[idxMushMush]->getTunnel1()]->roomIsEmpty())
		{
			_rooms[idxMushMush]->deleteHazard();
			plotHazard(_rooms[idxMushMush]->getTunnel1(), "MushMush");
		}
		else if (_rooms[_rooms[idxMushMush]->getTunnel2()]->roomIsEmpty())
		{
			_rooms[idxMushMush]->deleteHazard();
			plotHazard(_rooms[idxMushMush]->getTunnel2(), "MushMush");
		}
		else if (_rooms[_rooms[idxMushMush]->getTunnel3()]->roomIsEmpty())
		{
			_rooms[idxMushMush]->deleteHazard();
			plotHazard(_rooms[idxMushMush]->getTunnel3(), "MushMush");
		}
	}
	else if (attackMsg == "You got MushMush" || attackMsg == "You just shot yourself")
		_gameOver = true;

	return attackMsg;
}
std::string Cave::playerClash(int idx)
{
	if (idx < 0 || idx >19)
		throw "Invalid Index Exception";
	string clashMsg1st;
	string clashMsg2nd;
	_rooms[_playerIndex]->clashInRoom(clashMsg1st);
	if (clashMsg1st == "A Bat will move you")
	{
		_rooms[_playerIndex]->deleteHazard();
		movePlayer(idx);
		if (_rooms[_playerIndex]->clashInRoom(clashMsg2nd))
			return clashMsg1st;
		return clashMsg2nd;
	}
	return clashMsg1st;
}
bool Cave::gameOver() const
{
	return _gameOver;
}
void Cave::hazardNearPlayer(std::string* hazards) const
{
	hazards[0] = _rooms[_rooms[_playerIndex]->getTunnel1()]->roomHazard();
	hazards[1] = _rooms[_rooms[_playerIndex]->getTunnel2()]->roomHazard();
	hazards[2] = _rooms[_rooms[_playerIndex]->getTunnel3()]->roomHazard();
}