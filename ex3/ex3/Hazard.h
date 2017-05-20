#pragma once
#include <string>

using namespace std;

class Hazard
{
	int _type;
public:
	enum{ Empty, MushMush, Pit, Bat };
	Hazard()
	{
		_type = Empty;
	}
	~Hazard();

	int getHazardType() const
	{
		return _type;
	}
	bool setHazardType(int type)
	{
		if (type < Empty || type > Bat)
			return false;
		_type = type;
		return true;
	}
};