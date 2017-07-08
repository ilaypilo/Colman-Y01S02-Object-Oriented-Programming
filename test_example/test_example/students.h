#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Student{
	char * name;
	double average;

protected:
	char type;
public:

	Student() :name(NULL), average(0){}

	Student(const char* name, double average)
	{
		this->name = new char[strlen(name) + 1]();
		strcpy(this->name, name);
		this->average = average;
	}

	char* getName(){ return name; }
	double getAverage(){ return average; }

	virtual void save(ofstream& out)
	{
		auto szName = strlen(name);
		out.write((char*)&szName, sizeof(int));
		out.write(name, szName);
		out.write((char*)&average, sizeof(double));
	}

	virtual void load(ifstream& in)
	{
		int szName;
		in.read((char*)&szName, sizeof(int));
		name = new char[szName + 1]();
		in.read(name, szName);
		in.read((char*)&average, sizeof(double));
	}

	virtual ~Student(){	delete[] name; };

	void saveType(ofstream& out){
		out.write(&type, 1);
	}

	static char loadType(ifstream& in){
		char type;
		in.read(&type, sizeof(char));
		return type;
	}
};


class UndergradStudent : public Student {
	double projectGrade;
public:
	UndergradStudent(){}
	UndergradStudent(const char* name, double average, double projectGrade)
					: Student(name, average)
	{
		this->projectGrade = projectGrade;
		type = 'U';
	}

	virtual void save(ofstream& out)
	{
		Student::save(out);
		out.write((char *)&projectGrade, sizeof(double));

	}

	virtual void load(ifstream& in)
	{
		Student::load(in);
		in.read((char *)&projectGrade, sizeof(double));
	}

};

class MAStudent : public Student {
	int tesPages;
public:
	MAStudent() {}
	MAStudent(const char* name, double average, int tesPages)
		: Student(name, average)
	{
		this->tesPages = tesPages;
		type = 'M';
	}

	virtual void save(ofstream& out)
	{
		Student::save(out);
		out.write((char *)&tesPages, sizeof(int));

	}

	virtual void load(ifstream& in)
	{
		Student::load(in);
		in.read((char *)&tesPages, sizeof(int));
	}

};

class PhdStudent : public Student {
	char pollGrade;
public:
	PhdStudent() {}
	PhdStudent(const char* name, double average, char pollGrade)
		: Student(name, average)
	{
		this->pollGrade = pollGrade;
		type = 'P';
	}

	virtual void save(ofstream& out)
	{
		Student::save(out);
		out.write((char *)&pollGrade, sizeof(char));

	}

	virtual void load(ifstream& in)
	{
		Student::load(in);
		in.read((char *)&pollGrade, sizeof(char));
	}

};

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


	return 0;
}
