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
	int _maxObjects;
public:
	QuadTree(int maxObjs) : _root(nullptr), _numNodes(0) {
		_maxObjects = maxObjs;
	}
    
	void addNodeGuided(const T& item) {
		if (_root == nullptr) {
			_root = new TreeNode<T>(new T(item));
			_root->setQuadrant(true);
		}
		else
		{
			queue<TreeNode<T>*> q;
			q.push(_root);
			while (!q.empty())
			{
				TreeNode<T>* tmp = q.front();
				q.pop();
				// if we are a quadrant and we have less then _maxObjects
				if (tmp->getQuadrant())
				{
					if (tmp->getNumObjects() < _maxObjects)
					{
						tmp->addObject(new T(item));
						break;
					}
					else
					{
						auto children = splitRect(*tmp->getData());
						for (auto i = 0; i < CHILDREN; i++)
						{
							tmp->addChild(new T(children[i]));
						}
						for (auto i = 0; i < tmp->getNumObjects(); i++)
						{
							auto idx = indexRect(*tmp->getData(), *tmp->getObject(i)->getData());
							if (idx == -1) break;
							tmp->getChild(idx)->addObject(new T(*tmp->getObject(i)->getData()));
						}
						tmp->clearObjects();
						break;
					}
				
					// if we have 4 children add them to the queue
					for (auto i = 0; i < tmp->getNumChildren(); i++)
					{
						q.push(tmp->getChild(i));
					}
				}
			}
		}
		_numNodes++;
	}
	void query(vector<T>& objs, const T& obj) 
	{
		queue<TreeNode<T>*> q;
		q.push(_root);
		while (!q.empty())
		{
			TreeNode<T>* tmp = q.front();
			q.pop();
			// if we are a quadrant and we have less then _maxObjects
			if (tmp->getQuadrant())
			{
				auto idx = indexRect(*tmp->getData(), obj);
				if (idx == -1) break;
			
				if (tmp->getChild(idx)->getNumChildren() == 0)
				{
					for (auto i = 0; i < tmp->getChild(idx)->getNumObjects(); i++)
					{
						objs.push_back(*tmp->getChild(idx)->getObject(i)->getData());
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
	}
    
    template <class Func>
	void applyAllQuadrants(Func& f) {
		queue<TreeNode<T>*> q;
		q.push(_root);

		while (!q.empty())
		{
			TreeNode<T>* tmp = q.front();
			q.pop();
			if (tmp->getQuadrant())
			{
				f(*tmp->getData());
			}
			for (auto i = 0; i < tmp->getNumChildren(); i++)
			{
				f(*tmp->getChild(i)->getData());
				q.push(tmp->getChild(i));
			}
		}
	}
    
    template <class Func>
	void applyAllObjs(Func& f) 
	{
		queue<TreeNode<T>*> q;
		q.push(_root);

		while (!q.empty())
		{
			TreeNode<T>* tmp = q.front();
			q.pop();
			if (!tmp->getQuadrant())
			{
				f(*tmp->getData());
			}
			for (auto i = 0; i < tmp->getNumObjects(); i++)
			{
				f(*tmp->getObject(i)->getData());
			}
			for (auto i = 0; i < tmp->getNumChildren(); i++)
			{
				q.push(tmp->getChild(i));
			}
		}
	}
};