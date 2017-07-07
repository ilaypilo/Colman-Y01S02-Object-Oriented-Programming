#include <iostream>

using namespace std;

template<class T>
class RoundList{

	template<class E>
	class Item{
		_________ next;
		E data;
	public:

		Item() :next(NULL){}
		Item(const E& pdata) :next(NULL), data(______){}

		void setNext(________ next){ this->next = next; }
		_________ getNext(){ return next; }
		void setData(__________){ this->data = data; }
		________ getData(){ return data; }
	};


	Item<T>* head;
	int size;

public:

	RoundList(______) :head(____), size(__){ ____________________ }

	class Iterator{
		________ p;
	public:
		Iterator(_______ pt = NULL) :p(__){}
		Iterator& operator++(int){
			__________
			return ________;
		}
		T& operator*(){ __________________ }
		friend class ________________;
	};

	Iterator begin() { _____________ }
	void insert(const T& newItem, Iterator it){
		____________________________
		____________________________
		____________________________
		____________________________
		size++;
	}

	int getSize(){
		return size;
	}

};

// API test
void mainAPIRoundList()
{
	RoundList<int> list(5);
	for (int i = 1; i<5; i++)
		list.insert(i, list.begin());

	RoundList<int>::Iterator it = list.begin();
	for (int i = 0; i<list.getSize() * 2; i++){
		cout << *it << "->";
		it++;
	}
	cout << endl;
	// output: 5->4->3->2->1->5->4->3->2->1->   
}
