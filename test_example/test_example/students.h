#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Student{
	_______________
	_______________

protected:
	_______________

public:

	Student() :name(NULL), average(0){}

	Student(const char* name, double average){ /* להשלים */}

	_________ getName(){ return name; }
	_________ getAverage(){ return average; }

	_______ void save(ofstream& out){ /* להשלים */}

	_______ void load(ifstream& in){ /* להשלים */}

	________ ~Student(){	delete[] name; };

	void saveType(ofstream& out){
		out.write(&type, 1);
	}

	_______ char loadType(ifstream& in){
		char type;
		in.read(&type, sizeof(char));
		return type;
	}
};


class UndergradStudent ________________{
	____________________;
public:
	UndergradStudent(){}
	UndergradStudent(const char* name, double average, double projectGrade) 
:_________{ _______________; type = 'U'; }

______________________________________________

______________________________________________

______________________________________________

______________________________________________

______________________________________________

};

class MAStudent { /* להשלים */};

class PhdStudent { /* להשלים */};

int mainAPIStudent()
{
	int n = 3;
	Student** arr = new Student*[n];
	arr[0] = new UndergradStudent("a", 89.0, 95.5);
	arr[1] = new MAStudent("b", 95.0, 60);
	arr[2] = new PhdStudent("c", 90.0, 'A');

	ofstream out("students.db", ios::binary);
	out.write((char*)&n, sizeof(n));
	for (int i = 0; i<n; i++){
		arr[i]->saveType(out);
		arr[i]->save(out);
		delete arr[i];
	}
	delete[] arr;
	out.close();

	ifstream in("students.db", ios::binary);
	in.read((char*)&n, sizeof(n));
	arr = new Student*[n];
	for (int i = 0; i<n; i++){
		char type = Student::loadType(in);
		switch (type){
		case 'U':arr[i] = new UndergradStudent(); break;
		case 'M':arr[i] = new MAStudent(); break;
		case 'P':arr[i] = new PhdStudent(); break;
		}
		arr[i]->load(in);
		cout << arr[i]->getName() << " " << arr[i]->getAverage() << endl;
	}
	in.close();

	for (int i = 0; i<n; i++){delete arr[i];}
	delete[] arr;

}
