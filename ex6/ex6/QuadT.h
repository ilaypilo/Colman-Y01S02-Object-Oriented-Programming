#pragma once

template <class T, class IndexFunc, class SplitFunc>
class QuadTree
{
public:
    QuadTree(int maxObjs);
    
    void addNodeGuided(const T& item);
    void query(vector<T>& objs, const T& obj);
    
    template <class Func>
    void applyAllQuadrants(Func& f);
    
    template <class Func>
    void applyAllObjs(Func& f);
};