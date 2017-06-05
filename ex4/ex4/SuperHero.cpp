#include "SuperHero.h"

//=================================================================================//
// constructors
//=================================================================================//
 // default constructor
SuperHero::SuperHero(): _name(nullptr), _age(0), _radioactive(false)
{
}

// constructor with args
SuperHero::SuperHero(const char* name, double age, bool radioactive)
{
	setName(name);
	setAge(age);
	setRadioactive(radioactive);
}

// copy constructor
SuperHero::SuperHero(const SuperHero& superHero)
{
	setName(superHero.getName());
	setAge(superHero.getAge());
	setRadioactive(superHero.getRadioactive());
}

// destructor
SuperHero::~SuperHero()
{
	if (!_name)
	{
		delete _name;
	}
}


//=================================================================================//
// get functions
//=================================================================================//

const char* SuperHero::getName() const
{
	return _name;
}

double SuperHero::getAge() const
{
	return _age;
}

bool SuperHero::getRadioactive() const
{
	return _radioactive;
}


//=================================================================================//
// set functions
//=================================================================================//


void SuperHero::setName(const char* name)
{
	// check if name is valid
	if (!name)
	{
		// throw "[SuperHero::setName] invalid name!"
		return;
	}
	// check if addresses are the same
	if (name == _name)
	{
		return;
	}
	// remove the name if needed
	if (!_name)
	{
		delete _name;
	}
	// alloc new size for the name
	_name = new char[strlen(name)+1]();
	// unsafe function
	strcpy(_name, name);
}


void SuperHero::setAge(double age)
{
	if (age < 15 || age >40)
	{
		// throw "[SuperHero::setAge] invalid age!"
		_age = 0;
		return;
	}
	_age = age;
}


void SuperHero::setRadioactive(bool radioactive)
{
	_radioactive = radioactive;
}

//=================================================================================//
// load and save functions
//=================================================================================//

void SuperHero::load(ifstream& in_file)
{
	
}
void SuperHero::save(ofstream& out_file) const
{
	
}