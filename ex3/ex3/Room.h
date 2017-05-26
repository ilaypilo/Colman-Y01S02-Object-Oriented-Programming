#pragma once
#include <string>

#include "Hazard.h"
using namespace std;

class Hazard;

#pragma pack(push, 1)
class Room
{
public:
	virtual void type() {};
	Room(int tunnel1, int tunnel2, int tunnel3);
	~Room();
	bool attackInRoom(std::string& message) const;
	int getTunnel1() const;
	int getTunnel2() const;
	int getTunnel3() const;
	std::string roomHazard() const;
	const Hazard* getHazard() const;
	void deleteHazard();
	void setHazard(Hazard *ptr);

	bool roomIsEmpty() const;
	bool isMushMushHere() const;
	bool clashInRoom(std::string& msg) const;
	//const Hazard* _hazard;
protected:
	const Hazard* _hazard;
private:
	int _tunnels[3];
};
#pragma pack(pop)
