
#include "Room.h"
#include "MushMush.h"
#include "Pit.h"
#include "Bat.h"
#include "SealedRoom.h"
#include <typeinfo>

Room::Room(int tunnel1, int tunnel2, int tunnel3)
{
	_tunnels[0] = tunnel1;
	_tunnels[1] = tunnel2;
	_tunnels[2] = tunnel3;
}


int Room::getTunnel1() const
{
	return _tunnels[0];
}
int Room::getTunnel2() const
{
	return _tunnels[1];
}
int Room::getTunnel3() const
{
	return _tunnels[2];
}

std::string Room::roomHazard() const
{
	if (!_hazard)
		return "";
	if(typeid(*_hazard).name() == typeid(MushMush).name())
		return "MushMush is near";
	if (typeid(*_hazard).name() == typeid(Pit).name())
		return "Pit is near";
	if (typeid(*_hazard).name() == typeid(Bat).name())
		return "Bat is near";
}

bool Room::roomIsEmpty() const
{
	if (_hazard)
		return false;
	return true;
}

const Hazard* Room::getHazard() const
{
	return _hazard;
}

bool Room::attackInRoom(std::string& message) const
{
	if (typeid(*this).name() == typeid(SealedRoom).name())
		message = "You just shot yourself";
	else 
	{
		if (!_hazard)
		{
			message = "";
			return false;
		}
		if (typeid(*_hazard).name() == typeid(MushMush).name())
			message = "You got MushMush";
		if (typeid(*_hazard).name() == typeid(Pit).name())
			message = "Pit is whistling";
		if (typeid(*_hazard).name() == typeid(Bat).name())
			message = "Bat is laughing";
	}
	return true;
}


bool Room::isMushMushHere() const
{
	if (typeid(*_hazard).name() == typeid(MushMush).name())
		return true;
	return false;
}

bool Room::clashInRoom(std::string& msg) const
{
	if (!_hazard)
	{
		msg = "";
		return true;
	}
	if (typeid(*_hazard).name() == typeid(MushMush).name())
		msg = "MushMush got you";
	if (typeid(*_hazard).name() == typeid(Pit).name())
		msg = "You fell into a Pit";
	if (typeid(*_hazard).name() == typeid(Bat).name())
		msg = "A Bat will move you";
	return false;
}