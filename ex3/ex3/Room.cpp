
#include "Room.h"

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
	
	switch(_hazard->getHazardType())
	{
	case Hazard::Empty:
		return "";
	case Hazard::MushMush:
		return "MushMush is near";
	case Hazard::Pit:
		return "Pit is near";
	case Hazard::Bat:
		return "Bat is near";
	}
}

bool Room::roomIsEmpty() const
{
	if (_hazard->getHazardType() == Hazard::Empty)
		return true;
	return false;
}

const Hazard* Room::getHazard() const
{
	return _hazard;
}

bool Room::attackInRoom(std::string& message) const
{
	if (typeid(this).name() == "SealedRoom")
		message = "You just shot yourself";
	else 
	{
		switch (_hazard->getHazardType())
		{
		case Hazard::Empty:
			message = "";
			return false;
		case Hazard::MushMush:
			message = "You got MushMush";
		case Hazard::Pit:
			message = "Pit is whistling";
		case Hazard::Bat:
			message = "Bat is laughing";
		}
	}
	return true;
}


bool Room::isMushMushHere() const
{
	if (_hazard->getHazardType() == Hazard::MushMush)
		return true;
	return false;
}
bool Room::clashInRoom(std::string& msg) const
{

	switch (_hazard->getHazardType())
	{
	case Hazard::Empty:
		msg = "";
		return true;
	case Hazard::MushMush:
		msg = "MushMush got you";
	case Hazard::Pit:
		msg = "You fell into a Pit";
	case Hazard::Bat:
		msg = "A Bat will move you";
	}
	return false;
}