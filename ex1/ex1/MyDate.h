#pragma once
#include <string.h>
#include <string>
using namespace std;


// class MyDate handle dates in format of ints
class MyDate
{
	int day, month, year;
	bool validate(int day, int month, int year);
public:
	// Default CTOR init date with zeros
	MyDate() {
		this->day = 0;
		this->month = 0;
		this->year = 0;
	}
	// CTOR with date args
	MyDate(int day, int month, int year);
	// init with the ex's date;
	void init() {
		this->day = 9;
		this->month = 4;
		this->year = 2017;
	}
	// set function for diff data members
	int set(int day, int month, int year);
	int setDay(int day);
	int setMonth(int month);
	int setYear(int year);

	//check if the arg date is before or init date
	bool isBefore(const MyDate& newDate);
	// delay the date by days
	int delay(int num);
	// bring forward the date by days
	int bringForward(int num);
	char* print();

	// is free
	bool isFree() {
		if (this->day == 0 && this->month == 0 && this->year == 0)
			return true;
		else
			return false;
	}
	// check if date is equal
	bool equal(const MyDate& newDate) {
		if (this->day == newDate.day && this->month == newDate.month && this->year == newDate.year)
			return true;
		else
			return false;
	}
	void deleteMyDate() {
		this->day = 0;
		this->month = 0;
		this->year = 0;
	}
	// MyDate destructor
	~MyDate() {};
};

