#pragma once
#include "TreeNode.h"
#include <fstream>


template <class T>
class Tree
{
	TreeNode<T>* _root;
	int _numNodes;//size of tree
public:
	Tree() : _root(nullptr), _numNodes(0) {};
	~Tree() {};
	void save(ofstream& out) const;
	void load(ifstream& in);
	void freeMemory();
	bool treeContains(const T& item);
	void addNode(const T& item) 
	{
		if (_root == nullptr) {
			_root = new TreeNode<T>(new T(item));
		}
		else 
		{
			auto next = _root;
			auto last = _root;
			// go to the last element
			while (next)
			{
				last = next;
				next = next->getNextChild();
			}
			// add brother
			if (!last->getParent())
			{
				last->addChild(new T(item));
			}
			else if (last->getParent()->getNumChildren() < 4)
			{
				last->getParent()->addChild(new T(item));
			}
			// add a son for the first son
			else if (last->getParent()->getParent() == nullptr)
			{
				last->getParent()->getChild(0)->addChild(new T(item));
			}
			else if (last->getParent()->getParent()->findChildIndx(last->getParent()->getData()) != MAX_CHILDREN_INDEX)
			{
				auto index = last->getParent()->getParent()->findChildIndx(last->getParent()->getData());
				last->getParent()->getParent()->getChild(index+1)->addChild(new T(item));
			}
			else 
			{
				last->getParent()->getParent()->getChild(0)->getChild(0)->addChild(new T(item));
			}
		}
		_numNodes++;
	}
	const T& getNodeData(int index);
	TreeNode<T>* begin() const 
	{
		return _root;
	}

	class Iterator {
		TreeNode<T> *_p;
		friend class Tree<T>;
	public:
		Iterator(TreeNode<T> *pt = 0) : _p(pt) {}

		int operator!=(Iterator itr) const {

		}

		int operator==(Iterator itr) const {

		}

		Iterator& operator++() throw (char*){

		}

		Iterator& operator++(int) throw (char*) {

		}

		Iterator& operator--() throw(char*) {

		}
		
		Iterator& operator--(int) throw(char*) {

		}

		T& operator*() throw (char*) {

		}

	};
};

