#include <iostream>

using namespace std;

template<class T>
class RoundList{

	template<class E>
	class Item{
		Item<E>* next;
		E data;
	public:

		Item() :next(NULL){}
		Item(const E& pdata) :next(NULL), data(pdata){}

		void setNext(Item<E>* next){ this->next = next; }
		Item<E>* getNext(){ return next; }
		void setData(E data){ this->data = data; }
		E& getData(){ return data; }
	};


	Item<T>* head;
	int size;

public:

	RoundList(const T& item) : head(new Item<T>(item)), size(1)
	{ 
		head->setNext(head);
	}

	class Iterator{
		Item<T>* p;
	public:
		friend class RoundList<T>;
		Iterator(Item<T>* pt = NULL) :p(pt){}
		Iterator& operator++(int)
		{
			p = p->getNext();
			return *this;
		}
		T& operator*() { return p->getData(); }
		int operator==(Iterator it) const
		{
			return p == it.p;
		}
		int operator!=(Iterator it) const
		{
			return p != it.p;
		}
		
	};

	Iterator begin() { return head; }
	void insert(const T& newItem, Iterator it)
	{
		auto myNewItem = new Item<T>(newItem);
		myNewItem->setNext(it.p->getNext());
		it.p->setNext(myNewItem);
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
