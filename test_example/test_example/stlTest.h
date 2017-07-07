#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Employee{
	char* name;
	int age;

public:

	Employee(const char* name, int age){
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}

	const char* getName()const { return name; }
	int getAge()const { return age; }

};


struct AgeChecker {
	int _limit;
	AgeChecker(int limit) :_limit(limit){}
	bool operator()(const Employee& a) const
	{
		return a.getAge() < _limit;
	}
};


struct AgeComparator {
	bool operator()(const Employee& a, const Employee& b) const
	{
		return a.getAge() <  b.getAge();
	}
};


struct PrintName {
	void operator()(const Employee& a) const
	{
		cout << a.getName() << endl;
	}
};

template<class iterator, class condition, class func> 
void apply_if(iterator _First, iterator _Last, condition _Cond, func& _Func)
{	// apply _Func on [_First, _Last), if _Cond
	while (_First != _Last) 
	{
		if (_Cond(*_First))
		{
			_Func(*_First);
		}
		_First++;
	}
}

int mainAPISTL()
{
	vector<Employee> emps;
	emps.push_back(Employee("A", 19));
	emps.push_back(Employee("B", 24));
	emps.push_back(Employee("C", 42));
	emps.push_back(Employee("D", 35));

	cout << count_if(emps.begin(), emps.end(), AgeChecker(30)) << endl; // 2

	sort(emps.begin(), emps.end(), AgeComparator());

	// A B D C    
	for_each(emps.begin(), emps.end(), PrintName());
	AgeChecker ac(20);
	PrintName pn;
    apply_if(emps.begin(),emps.end(),ac,pn); // A

	return 0;
}
