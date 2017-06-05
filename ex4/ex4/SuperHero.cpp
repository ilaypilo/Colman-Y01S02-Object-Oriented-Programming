#include "SuperHero.h"
#include "CaptainSpider.h"

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

// file type
// [type]				2 chars		2 bytes
// [size_of_name]		int			4 bytes
// [name]				char *		size_of_name
// [age]				dobule		8 bytes
// [radioactive]		bool		1 byte

static bool LoadBuildFlag = true;

void SuperHero::load(ifstream& in_file)
{
	if (LoadBuildFlag)
	{
		auto szName = 0;
		// read name size
		in_file.read((char *)&szName, sizeof(szName));
		// read the name to temp name
		auto tempName = new char[szName + 1]();
		in_file.read(tempName, szName);
		// set the name
		setName(tempName);
		delete[]tempName;
		// read age
		in_file.read((char*)&_age, sizeof(_age));
		// read radioactive
		in_file.read((char*)&_radioactive, sizeof(_radioactive));
	}
	// check if CaptainSpider is saving
	if (typeid(*this).name() == typeid(CaptainSpider).name())
	{
		LoadBuildFlag = !LoadBuildFlag;
	}
}

static bool SaveBuildFlag = true;

void SuperHero::save(ofstream& out_file) const
{
	if (SaveBuildFlag)
	{
		// get name length
		int szName = strlen(getName());
		// write name size
		out_file.write((char *)&szName, sizeof(szName));
		// write the name itself
		out_file.write(_name, szName);
		// write the age
		out_file.write((char*)&_age, sizeof(_age));
		// write the radioactive
		out_file.write((char*)&_radioactive, sizeof(_radioactive));
	}
	// check if CaptainSpider is saving
	if (typeid(*this).name() == typeid(CaptainSpider).name())
	{
		SaveBuildFlag = !SaveBuildFlag;
	}
}