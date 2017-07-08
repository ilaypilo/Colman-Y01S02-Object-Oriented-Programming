#include "RoundList.h"
#include "students.h"
#include "stlTest.h"
#include <cmath> 
#include <type_traits>

class A{
	int x;
	public:
	A(int x){this->x=x;}
	int getX(){return x;}
	int getName(){ return x;}
	int getAge(){ return x;}
};

void test1(){
    RoundList<A> list(A(5));
	RoundList<A>::Iterator it=list.begin();
	if((*it).getX()!=5)
		cout<<"error in q1, check CTOR, begin() and operator* (-10)"<<endl;
	
    for(int i=1;i<5;i++)
        list.insert(A(i),list.begin());
	long result=0;
    for(int i=0;i<list.getSize()*3;i++){
        result+=pow((*it).getX(),(i+1));
        it++;		
    }
	if(result!=67255197)
		cout<<"error in q1, check multiple inserts, begin() and operators * and ++ (-15)"<<endl;
	
	// other tests for submit mode...
	
}

void test2(){
  UndergradStudent s1("a",89.0,95.5);
  MAStudent s2("b",95.0,60);
  PhdStudent s3("c",90.0,'A');

  if(!is_base_of<Student,UndergradStudent>::value)
	  cout<<"error in q2, wrong definition of an undergrad student (-5)"<<endl;
  if(!is_base_of<Student,MAStudent>::value)
	  cout<<"error in q2, wrong definition of an MA student (-5)"<<endl;
  if(!is_base_of<Student,PhdStudent>::value)
	  cout<<"error in q2, wrong definition of a Phd student (-5)"<<endl;

  int n=3;
  Student** arr=new Student*[n];
  arr[0]= &s1;
  arr[1]= &s2;
  arr[2]= &s3;
  
  ofstream out("students.db",ios::binary);
  out.write((char*)&n,sizeof(n));
  for(int i=0;i<n;i++){
      arr[i]->saveType(out);
      arr[i]->save(out);
  }
  delete[] arr;  
  out.close();
  
  ifstream in("students.db",ios::binary);
  in.read((char*)&n,sizeof(n));
  arr=new Student*[n];
  for(int i=0;i<n;i++){
      char type = Student::loadType(in);
      switch(type){
          case 'U':arr[i]=new UndergradStudent();break;
          case 'M':arr[i]=new MAStudent();break;
          case 'P':arr[i]=new PhdStudent();break;
      }
      arr[i]->load(in);
  }  
  in.close();
  
  if(strcmp(arr[0]->getName(),s1.getName()))
	  cout<<"error in q2, wrong save or load for student a (-5)"<<endl;
  if(strcmp(arr[1]->getName(),s2.getName()))
	  cout<<"error in q2, wrong save or load for student b (-5)"<<endl;
  if(strcmp(arr[2]->getName(),s3.getName()))
	  cout<<"error in q2, wrong save or load for student c (-5)"<<endl;
  
  for(int i=0;i<n;i++){
      delete arr[i];
  }
  delete[] arr; 

	// additional test for submit mode
  
 }
 
 struct Sum{
	 int sum=0;
	 template<class T>
	 void operator()(T& t){
		 sum+=t.getX();
	 }
 };

void test3(){
    vector<A> emps;  
    emps.push_back(A(19));
    emps.push_back(A(24));
    emps.push_back(A(42));
    emps.push_back(A(35));
    
    if(2!=count_if(emps.begin(),emps.end(),AgeChecker(30)))
		cout<<"error in q3, check ageChecker (-10)"<<endl;
    
	Sum s;
	AgeChecker ac(20);
    apply_if(emps.begin(),emps.end(),ac,s);
	if(s.sum!=19)
		cout<<"error in q3, check apply_if and ageChecker (-10)"<<endl;
	
	// additional tests for submit mode...
}

int main()
{
	mainAPIRoundList();
	mainAPIStudent();
	mainAPISTL();
	cout << "staring test" << endl;
	test1();
	test2();
	test3();
	cout<<"done"<<endl;
}