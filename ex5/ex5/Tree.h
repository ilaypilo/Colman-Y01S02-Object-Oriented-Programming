#pragma once
#include "TreeNode.h"
#include "Student.h"
#include <fstream>


template <class T>
class Tree
{
	TreeNode<T>* _root;
	int _numNodes; //size of tree
public:
	Tree() : _root(nullptr), _numNodes(0) {};
	~Tree() {};
	void save(ofstream& out) const 
	{
		out.write((char*)&_numNodes, sizeof(_numNodes));
		auto node = _root;
		for (auto i = 0; i < _numNodes; i++) 
		{
			node->getData()->save(out);
			node = node->getNextChild();
		}
	}
	void load(ifstream& in) {
		
		int treeSize;
		in.read((char*)&treeSize, sizeof(treeSize));
		for (auto i = 0; i < treeSize; i++)
		{
			Student tmpStudent;
			tmpStudent.load(in);
			addNode(tmpStudent);
		}
	}
	void freeMemory();
	bool treeContains(const T& item) 
	{
		queue<TreeNode<T>*> q;
		q.push(_root);

		while (!q.empty())
		{
			TreeNode<T>* tmp = q.front();
			q.pop();

			if (*tmp->getData() == item)
				return true;
			else
			{
				for (auto i = 0; i < tmp->getNumChildren(); i++)
				{
					q.push(tmp->getChild(i));
				}
			}
		}
		return false;
	}
	void addNode(const T& item) 
	{
		if (_root == nullptr) {
			_root = new TreeNode<T>(new T(item));
		}
		else 
		{
			queue<TreeNode<T>*> q;
			q.push(_root);
			while (!q.empty())
			{
				TreeNode<T>* tmp = q.front();
				q.pop();
				// if we have less then 4 children add a child.
				if (tmp->getNumChildren() < 4) 
				{
					tmp->addChild(new T(item));
					break;
				}
				// if we have 4 children add them to the queue
				for (auto i = 0; i < tmp->getNumChildren(); i++)
				{
					q.push(tmp->getChild(i));
				}
			}
		}
		_numNodes++;
	}
	const T& getNodeData(int index) 
	{
		auto node = _root;
		for (auto i = 0; i < index; i++)
		{
			node = node->getNextChild();
		}
		return *node->getData();
	}
	TreeNode<T>* begin() const 
	{
		return _root;
	}
	class Iterator {
		TreeNode<T> *_p;
		friend class Tree<T>;
	public:
		Iterator(TreeNode<T> *pt = 0) : _p(pt) {}

		int operator!=(Iterator itr) const 
		{
			return this != itr;
		}

		int operator==(Iterator itr) const 
		{
			return this == itr;
		}

		Iterator& operator++() throw (char*)
		{
			_p = _p->getNextChild();
			return *this;
		}

		Iterator& operator++(int) throw (char*) 
		{
			//for (auto i = 0; i < times; i++)
			//{
				_p = _p->getNextChild();
			//}
			return *this;
		}

		Iterator& operator--() throw(char*) 
		{
			_p = _p->getPrevChild();
			return *this;
		}
		
		Iterator& operator--(int) throw(char*) 
		{
			//for (auto i = 0; i < times; i++)
			//{
				_p = _p->getPrevChild();
			//}
			return *this;
		}

		T& operator*() throw (char*) 
		{
			return *_p->getData();
		}

	};
};

