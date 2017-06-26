#pragma once
#include <vector>
#include "TreeNode.h"
using namespace std;

template <class T, class IndexFunc, class SplitFunc>
class QuadTree
{
	SplitFunc splitRect;
	IndexFunc indexRect;
	TreeNode<T>* _root;
	int _numNodes; //size of tree
	vector<T> _objects;
	int _maxObjects;
public:
	QuadTree(int maxObjs) : _root(nullptr), _numNodes(0) {
		_maxObjects = maxObjs;
	}
    
	void addNodeGuided(const T& item) {
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
					auto children = splitRect(item);
					for (auto i = 0; i < CHILDREN; i++)
					{
						tmp->addChild(new T(children.at(i)));
					}
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
    void query(vector<T>& objs, const T& obj);
    
    template <class Func>
	void applyAllQuadrants(Func& f) {
		queue<TreeNode<T>*> q;
		q.push(_root);

		while (!q.empty())
		{
			TreeNode<T>* tmp = q.front();
			q.pop();

			f(*tmp->getData());
			for (auto i = 0; i < tmp->getNumChildren(); i++)
			{
				f(*tmp->getChild(i)->getData());
				q.push(tmp->getChild(i));
			}
		}
	}
    
    template <class Func>
    void applyAllObjs(Func& f);
};