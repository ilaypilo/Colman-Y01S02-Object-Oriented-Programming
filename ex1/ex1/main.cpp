#include "MyDate.h"
#include "Calendar.h"
#include <iostream>

int main() {
	MyDate* date1 = new MyDate(1, 1, 1901);
	MyDate* date2 = new MyDate(5, 2, 1901);
	MyDate* date3 = new MyDate(10, 3, 1901);
	MyDate* date4 = new MyDate(15, 4, 1902);
	MyDate* date5 = new MyDate(20, 5, 1901);
	MyDate* date6 = new MyDate(21, 6, 1901);
	MyDate* date7 = new MyDate(1, 3, 2007);
	MyDate* date8 = new MyDate(2, 3, 2007);
	MyDate* date9 = new MyDate(2, 3, 2020);
	date1->isBefore(*date2); //false
	date1->isBefore(*date3); //flase
	date1->isBefore(*date4); // true
	date1->isBefore(*date5); // true
	date1->isBefore(*date6); // wrong date
	date1->delay(360);
	date1->bringForward(360);
	date2->delay(360);
	date2->bringForward(360);
	date3->delay(360);
	date3->bringForward(360);
	date4->delay(360);
	date4->bringForward(360);
	date5->delay(360);
	date5->bringForward(360);
	date6->delay(360);
	date6->bringForward(360);
	date6->print();
	
	Calendar* cal = new Calendar;
	cal->setDate(*date6, 0);
	cal->oldest();
	cal->setDate(*date5, 1);
	cal->insert(*date7);
	cal->insert(*date8);
	cal->insert(*date9);
	cal->firstFree();
	cal->insert(*date4);
	cal->insert(*date4);
	cal->insert(*date4);
	cal->insert(*date9);
	cal->insert(*date9);
	cout << cal->print() << endl;
	cal->deleteDate(5);
	cout << cal->print() << endl;




	cal->setDate(*date5, 20);
	cal->oldest();

	cal->datesNum(*date4);
	cal->datesNum(*date5);
	cout << endl << "Not Sorted" << endl << cal->print();
	cal->sortDates();
	cout << endl << "Sorted" << endl << cal->print();
	cal->deleteAll();
	cout << endl << "Zerroz" << endl << cal->print();


}