#pragma once
#include <string>

class Hazard;
class Room
{
public:
    Room(int tunnel1, int tunnel2, int tunnel3);
    ~Room() ;
    bool attackInRoom(std::string& message) const;
    int getTunnel1() const;
    int getTunnel2() const;
    int getTunnel3() const;
    std::string roomHazard() const;
    const Hazard* getHazard() const;
    
    bool roomIsEmpty() const;
    bool isMushMushHere() const;
    bool clashInRoom(std::string& msg) const;
protected:
    const Hazard* _hazard;
private:
    int _tunnels[3];
};