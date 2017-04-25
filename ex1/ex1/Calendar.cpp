#include "Calendar.h"

int Calendar::setDate(const MyDate& newDate, int num) {
	if (num > CALENDAR_SIZE || num < 1)
		return -1;
	this->arrDates[num-1] = newDate;
	return 0;
}
bool Calendar::isFree(int num) {
	if (num > CALENDAR_SIZE || num < 1)
		return false;
	return arrDates[num-1].isFree();
}

int Calendar::firstFree() {
	int i;
	// look for empty place in the array
	for (i = 0; i < CALENDAR_SIZE; i++) {
		if (arrDates[i].isFree())
			return i+1;
	}
	// nothing found
	return -1;
}
// insert the date to the first free place in the array
int Calendar::insert(const MyDate& newDate) {
	int index = this->firstFree();
	if (index != -1) {
		this->arrDates[index-1] = newDate;
		return index;
	}
	return -1;
}
// return the index of the early date in calendar
int Calendar::oldest() {
	int i,index = -1;
	MyDate oldest;
	for (i = 0; i < CALENDAR_SIZE; i++) {
		if (oldest.isFree() && !this->arrDates[i].isFree()) {
			oldest = this->arrDates[i];
			index = i;
		}
		else if (!this->arrDates[i].isFree()) {
			if (this->arrDates[i].isBefore(oldest)) {
				oldest = this->arrDates[i];
				index = i;
			}
		}
	}
	return index;
}
// check how many dates in Calendar has the same values as the arg
int Calendar::datesNum(const MyDate& newDate) {
	int i, count = 0;
	for (i = 0; i < CALENDAR_SIZE; i++) {
		if (this->arrDates[i].equal(newDate))
			count++;
	}
	return count;
}

// init all the array to zeroz
void Calendar::deleteAll() {
	int i;
	for (i = 0; i < CALENDAR_SIZE; i++) {
		this->arrDates[i].deleteMyDate();
	}
}
// init a spesific date in the array with zeroz
int Calendar::deleteDate(int num) {
	if (num > CALENDAR_SIZE || num < 1)
		return -1;
	this->arrDates[num-1].deleteMyDate();
	return 0;
}

char* Calendar::print() {
	int i, counter=0;
	char *date;
	string strDate;
	// build the string
	if (this == NULL) {
		strDate = "";
	}
	else {
		// concatenate all dates
		for (i = 0; i < CALENDAR_SIZE; i++) {
			if (!arrDates[i].isFree()) {
				// add space between words
				if (counter > 0)
					strDate += " ";
				date = this->arrDates[i].print();
				strDate += date;
				delete date;
				counter++;
			}

		}
	}
	if (strDate.length() == 0)
		strDate = "Empty Calendar";
	char *outDate = new char[strDate.length() + 1];
	// copy the str to date
	strcpy(outDate, strDate.c_str());
	return outDate;
}

// sort all dates
void Calendar::sortDates() {
	int i,j;
	MyDate tempDate;
	for (i = 0; i < CALENDAR_SIZE; i++) {
		for (j = i+1; j < CALENDAR_SIZE; j++) {
			if (!this->arrDates[j].isFree() && (this->arrDates[j].isBefore(this->arrDates[i]) || this->arrDates[i].isFree())) {
				// replace the dates
				tempDate = this->arrDates[i];
				this->arrDates[i] = this->arrDates[j];
				this->arrDates[j] = tempDate;
			}
		}
	}
}