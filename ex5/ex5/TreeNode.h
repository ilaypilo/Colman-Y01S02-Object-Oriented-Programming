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

	TreeNode(TreeNode<T>* parent,T* data);
	TreeNode(T* data);
	~TreeNode();

	T* getData() const;
	void setData(T* data);
	void addChild(T* data);
	void addChild(TreeNode<T>* newChild);
	void removeChild(); //removes the nodes last entered child or if no children - does nothing
	TreeNode<T>* findChild(T* data) const; // returns ptr or NULL
	int findChildIndx(T* data) const; // returns childs indx or -1
	TreeNode<T>* getChild(int indx) const;
	TreeNode<T>* getNextChild() const;
	TreeNode<T>* getPrevChild() const;
	TreeNode<T>* getParent() const;
	void setParent(TreeNode<T>* parent);
	int getNumChildren() const;

};
