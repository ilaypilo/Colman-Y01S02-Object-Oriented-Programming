#pragma once
#include "TreeNode.h"
#include <fstream>


template <class T>
class Tree
{
	TreeNode<T>* _root;
	int _numNodes;//size of tree
public:
	Tree();
	~Tree();
	void save(ofstream& out) const;
	void load(ifstream& in);
	void freeMemory();
	bool treeContains(const T& item);
	void addNode(const T& item);
	const T& getNodeData(int index);
	TreeNode<T>* begin() const;

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

