#pragma once
#include "MyDate.h"
#define CALENDAR_SIZE 30

class Calendar
{
	MyDate arrDates[CALENDAR_SIZE];
public:
	Calendar() {};
	// put date into the array in the place of num;
	int setDate(const MyDate& newDate, int num);
	// check if the date in the place num is free;
	bool isFree(int num);
	int firstFree();
	int insert(const MyDate& newDate);
	int oldest();
	int datesNum(const MyDate& newDate);
	void deleteAll();
	int deleteDate(int num);
	char* print();
	void sortDates();

	~Calendar() {};
};

