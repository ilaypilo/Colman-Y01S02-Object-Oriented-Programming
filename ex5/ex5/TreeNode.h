#pragma once
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

#define MAX_CHILDREN 4
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
	TreeNode<T>* getNextChild() const 
	{
		
		// if I'm the root return my first child if I have one
		if (_parent == nullptr) 
		{
			return _children.size() ? _children.at(0) : nullptr;
		}
		// if i'm not the last child, return my next brother
		else 
		{
			auto myIndex = _parent->findChildIndx(_data);
			if (_parent->getNumChildren() > myIndex + 1)
			{
				return _parent->_children.at(myIndex + 1);
			}
			// if I'm the last child return my father first son of first son
			else if (_parent->getNumChildren() == myIndex + 1)
			{
				return _parent->_children.at(0)->getNumChildren() ? _parent->_children.at(0)->_children.at(0) : nullptr;
			}
		}
	}
	TreeNode<T>* getPrevChild() const 
	{
		// if I'm the root return null
		if (_parent == nullptr)
		{
			return nullptr;
		}
		// if i'm not the last child, return my prev brother
		else
		{
			auto myIndex = _parent->findChildIndx(_data);
			if (myIndex > 0)
			{
				return _parent->_children.at(myIndex - 1);
			}
			// if I'm the first child return my father
			else if (myIndex == 0)
			{
				return _parent;
			}
		}
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
