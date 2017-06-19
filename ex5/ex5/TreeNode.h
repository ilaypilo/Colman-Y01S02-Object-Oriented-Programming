#pragma once
#include <vector>
#include <iostream>
#include <string.h>
#include <queue> 

using namespace std;

#define MAX_CHILDREN 4
#define MAX_CHILDREN_INDEX (MAX_CHILDREN-1)
template<class T>
class TreeNode {

private:

	T* _data;
	TreeNode<T>* _parent;
	vector< TreeNode<T>* > _children;

public:
	// children constructor
	TreeNode(TreeNode<T>* parent,T* data)
	{
		_parent = parent;
		_data = data;
	}
	// root constructor
	TreeNode(T* data)
	{
		_parent = nullptr;
		_data = data;
	}
	// destructor
	~TreeNode()
	{
		for (auto i = 0; i<_children.size(); i++)
		{
			delete getChild(i);
		}
		if (_data) delete _data;
	}

	T* getData() const
	{
		return _data;
	}
	void setData(T* data)
	{
		_data = data;
	}
	void addChild(T* data)
	{
		if (_children.size() != 4) 
		{
			_children.push_back(new TreeNode<T>(this, data));
		}
	}

	void addChild(TreeNode<T>* newChild)
	{
		newChild->setParent(this);
		_children.push_back(newChild);
	}
	//removes the nodes last entered child or if no children - does nothing
	void removeChild() 
	{ 
		if(_children.size())
		{
			_children.erase(_children.end()-1);
		}
	}
	// returns ptr or NULL
	TreeNode<T>* findChild(T* data) const
	{
		for(auto i=0; i<_children.size();i++)
		{
			if(_children.at(i)->_data == data)
			{
				return _children.at(i);
			}
		}
		return nullptr;
	}
	// returns childs indx or -1
	int findChildIndx(T* data) const 
	{
		for (auto i = 0; i<getNumChildren(); i++)
		{
			if (_children.at(i)->_data == data)
			{
				return i;
			}
		}
		return -1;
	}
	TreeNode<T>* getChild(int indx) const 
	{
		if (indx >= 0 && indx < _children.size()) {
			return _children.at(indx);
		}
		return nullptr;
	}
	// get the node root
	TreeNode<T>* getRoot() const 
	{
		auto root = const_cast<TreeNode<T>*>(this);
		while (root->getParent())
		{
			root = root->getParent();
		}
		return root;
	}
	TreeNode<T>* getNextChild() const 
	{
		// get the root
		auto root = getRoot();
		// create the queue
		queue<TreeNode<T>*> q;
		q.push(root);
		// search our item in the queue
		while (!q.empty())
		{
			// get item from the queue
			TreeNode<T>* tmp = q.front();
			q.pop();
			// append all children to the queue
			for (auto i = 0; i < tmp->getNumChildren(); i++)
			{
				q.push(tmp->getChild(i));
			}

			if (*tmp->getData() == *_data) 
			{
				// return the next in the queue
				if (!q.empty()) {
					return q.front();
				}
				return nullptr;
			}
		}
		return nullptr;
	}
	TreeNode<T>* getPrevChild() const 
	{

		// get the root
		auto root = getRoot();
		// create the queue
		queue<TreeNode<T>*> q;
		q.push(root);
		// search our item in the queue
		TreeNode<T>* lastTemp = nullptr;
		while (!q.empty())
		{
			// get item from the queue
			TreeNode<T>* tmp = q.front();
			q.pop();
			// append all children to the queue
			for (auto i = 0; i < tmp->getNumChildren(); i++)
			{
				q.push(tmp->getChild(i));
			}

			if (*tmp->getData() == *_data)
			{
				// return the one we just, if this is root return nullptr
				return lastTemp;
				
			}
			lastTemp = tmp;
		}
		return nullptr;
	}
	TreeNode<T>* getParent() const
	{
		return _parent;
	}
	void setParent(TreeNode<T>* parent)
	{
		_parent = parent;
	}
	int getNumChildren() const
	{
		return _children.size();
	}

};
