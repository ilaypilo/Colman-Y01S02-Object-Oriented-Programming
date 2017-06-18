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
		_children->push_back(new TreeNode<T>(this, data));
	}

	void addChild(TreeNode<T>* newChild)
	{
		newChild->setParent(this);
		_children->push_back(newChild);
	}
	//removes the nodes last entered child or if no children - does nothing
	void removeChild() 
	{ 
		if(_children->size())
		{
			_children->erase(_children->end());
		}
	}
	// returns ptr or NULL
	TreeNode<T>* findChild(T* data) const
	{
		for(auto i=0; i<_children->size();i++)
		{
			if(_children->at(i)->_data == data)
			{
				return _children->at(i);
			}
		}
	}
	int findChildIndx(T* data) const; // returns childs indx or -1
	TreeNode<T>* getChild(int indx) const;
	TreeNode<T>* getNextChild() const;
	TreeNode<T>* getPrevChild() const;
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
		return _children->size();
	}

};
