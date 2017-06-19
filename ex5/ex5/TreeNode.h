#pragma once
#include <vector>
#include <iostream>
#include <string.h>

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
			return getChild(0);
		}
		else 
		{
			auto myIndex = _parent->findChildIndx(_data);
			auto myParentIndex = _parent->getParent() ? _parent->getParent()->findChildIndx(_parent->_data) : MAX_CHILDREN_INDEX;
			// if i'm not the last child, return my next brother
			if (_parent->getNumChildren() > myIndex + 1)
			{
				return _parent->getChild(myIndex + 1);
			}
			else if (_parent->getNumChildren() == MAX_CHILDREN && myParentIndex != MAX_CHILDREN_INDEX)
			{
				return _parent->getParent()->getChild(myParentIndex+1)->getNumChildren() ? _parent->getParent()->getChild(myParentIndex + 1)->getChild(0) : nullptr;
			}
			// if I'm the last child return my father first son of first son
			else if (_parent->getNumChildren() == MAX_CHILDREN && myParentIndex == MAX_CHILDREN_INDEX)
			{
				if (_parent->getParent()) {
					return  _parent->getParent()->getChild(0)->getChild(0)->getChild(0);
				}
				return _parent->getChild(0)->getChild(0);
			}
			return nullptr;
		}
	}
	TreeNode<T>* getPrevChild() const 
	{

		// if I'm the root return my first child if I have one
		if (_parent == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto myIndex = _parent->findChildIndx(_data);
			auto myParentIndex = _parent->getParent() ? _parent->getParent()->findChildIndx(_parent->_data) : 0;
			// if i'm not the first child, return my prev brother
			if (myIndex != 0)
			{
				return _parent->getChild(myIndex - 1);
			}
			else if (myIndex == 0 && myParentIndex != 0)
			{
				return _parent->getParent()->getChild(myParentIndex - 1)->getNumChildren() ? _parent->getParent()->getChild(myParentIndex - 1)->getChild(MAX_CHILDREN_INDEX) : nullptr;
			}
			// if I'm the first child of the first child
			else if (myIndex == 0 && myParentIndex == 0)
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
