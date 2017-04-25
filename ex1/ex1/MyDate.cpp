// ex1
// ID: 304961519
// Name: Ilay Pilosof
// Date: 1/4/17


// implementation of MyDate class
#include "MyDate.h"


// validate the date
bool MyDate::validate(int day, int month, int year) {
	//check year
	if (year <= 1900 || year >= 2100)
		return false;
	//check month
	if (month > 12 || month < 1)
		return false;
	//check days for februar
	if (month == 2 && (day > 28 || day < 1))
		return false;
	//check days for the other months
	else if (day > 30 || day < 1)
		return false;
	// Date is valid
	return true;
}

// CTOR with date args
MyDate::MyDate(int day, int month, int year) {
	// check if the date is valid
	if (validate(day, month, year)) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else {
		// if wrong date -> init with zeroz
		this->day = 0;
		this->month = 0;
		this->year = 0;
	}
}

// set function for all data members
int MyDate::set(int day, int month, int year) {
	// check if the date is valid
	if (validate(day, month, year)) {
		this->day = day;
		this->month = month;
		this->year = year;
		return 0;
	}
	// wrong date, do nothing
	else {
		return -1;
	}
}
// set function for day
int MyDate::setDay(int day) {
	// check if the date is valid
	if (validate(day, this->month, this->year)) {
		this->day = day;
		return 0;
	}
	// wrong date, do nothing
	else {
		return -1;
	}
}
// set function for month
int MyDate::setMonth(int month) {
	// check if the date is valid
	if (validate(this->day, month, this->year)) {
		this->month = month;
		return 0;
	}
	// wrong date, do nothing
	else {
		return -1;
	}
}
// set function for year
int MyDate::setYear(int year) {
	// check if the date is valid
	if (validate(this->day, this->month, year)) {
		this->year = year;
		return 0;
	}
	// wrong date, do nothing
	else {
		return -1;
	}
}

//check if the arg date is before or init date
bool MyDate::isBefore(const MyDate& newDate) {
	// check years
	if (this->year > newDate.year)
		return false;
	// if equal check months
	else if (this->year == newDate.year) {
		if (this->month > newDate.month)
			return false;
		// if equal check days
		else if (this->month == newDate.month) {
			if (this->day >= newDate.day)
				return false;
		}
	}
	// if nothing return false -> the date is before!
	return true;
}
// delay the date by days
int MyDate::delay(int num) {
	if (num > 358) 
		return -1;
	while (num > 0) {
		//increase days
		this->day++;
		num--;
		//increase months
		if ((this->month != 2 && this->day > 30) || (this->month == 2 && this->day > 28)) {
			this->day = 1;
			this->month++;
		}
		//increase years
		if (this->month > 12) {
			this->month = 1;
			this->year++;
		}
	}
	return 0;
}
// bringForward the date by days
int MyDate::bringForward(int num) {
	if (num > 358)
		return -1;
	while (num > 0) {
		//decrease days
		this->day--;
		num--;
		//decrease months
		if ((this->month != 3 && this->day < 1)) {
			this->day = 30;
			this->month--;
		}
		//decrease month for february
		else if (this->month == 3 && this->day < 1) {
			this->day = 28;
			this->month--;
		}
		//decrease years
		if (this->month < 1) {
			this->month = 12;
			this->year--;
		}
	}
	return 0;
}

char* MyDate::print() {
	// bulding the string
	string strDate = to_string(this->day) + "/";
	strDate += to_string(this->month) + "/";
	strDate += to_string(this->year);
	// alloc date
	char *outDate = new char [strDate.length()+1];
	// copy the str to date
	strcpy(outDate, strDate.c_str());
	return outDate;
}