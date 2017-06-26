#include <iostream>
#include "QuadT.h"
#include "Rectangle.h"

static const vector<vector<Rectangle>> expectedResults =
{
    {Rectangle(5,5,25,20)},
    {},
    {Rectangle(6,6,1,1), Rectangle(20,6,1,1), Rectangle(22,6,1,1), Rectangle(8,20,1,1), Rectangle(12,28,1,1)},
    {Rectangle(5,5,25,20), Rectangle(17,5,12,10), Rectangle(5,5,12,10), Rectangle(5,15,12,10),
        Rectangle(17,15,12,10)},
    {Rectangle(8,20,1,1), Rectangle(12,28,1,1), Rectangle(8,16,1,1), Rectangle(10,26,1,1)},
    {Rectangle(6,6,1,1), Rectangle(8,8,1,1)}
};

struct GetRecs
{
    void operator()(const Rectangle& r)
    {
        _quadrants.push_back(r);
    }
    const vector<Rectangle>& quadrants() const
    {
        return _quadrants;
    }
private:
    vector<Rectangle> _quadrants;
};

bool testQuadrants(QuadTree<Rectangle, TreeIndexRectangle, TreeSplitRectangle>& t, int index)
{
    GetRecs gq;
    t.applyAllQuadrants(gq);
    
	return gq.quadrants() == expectedResults[index];
}

//bool testObjs(QuadTree<Rectangle, TreeIndexRectangle, TreeSplitRectangle>& t, int index)
//{
//    GetRecs gq;
//    t.applyAllObjs(gq);
//    
//    return gq.quadrants() == expectedResults[index];
//}
//
//static bool testCollision(QuadTree<Rectangle, TreeIndexRectangle, TreeSplitRectangle>& t,
//                          const Rectangle& r,
//                          int index)
//{
//    vector<Rectangle> res;
//    t.query(res, r);
//    
//    return res == expectedResults[index];
//}

int main(void)
{
    int index = 0;
	TreeSplitRectangle splitedRect;
	auto splited = splitedRect(Rectangle(1, 1, 40, 40));
	TreeIndexRectangle indexRect;
	auto q0 = indexRect(Rectangle(1, 1, 40, 40), Rectangle(25, 5, 5, 5));
	auto q1 = indexRect(Rectangle(1, 1, 40, 40), Rectangle(1, 1, 5, 5));
	auto q2 = indexRect(Rectangle(1, 1, 40, 40), Rectangle(1, 25, 5, 5));
	auto q3 = indexRect(Rectangle(1, 1, 40, 40), Rectangle(25, 25, 5, 5));
	auto q_nothing = indexRect(Rectangle(1, 1, 40, 40), Rectangle(1, 1, 21, 21));

    QuadTree<Rectangle, TreeIndexRectangle, TreeSplitRectangle> t(5);
    t.addNodeGuided(Rectangle(5,5,25,20));
    
    if (!testQuadrants(t, index++))
        cout<<"Error: applyAllQuadrants.\n";
    //if (!testObjs(t, index++))
    //    cout<<"Error: applyAllObjs.\n";
    
    //t.addNodeGuided(Rectangle(6,6,1,1));
    //t.addNodeGuided(Rectangle(20,6,1,1));
    //t.addNodeGuided(Rectangle(22,6,1,1));
    //t.addNodeGuided(Rectangle(8,20,1,1));
    //t.addNodeGuided(Rectangle(12,28,1,1));
    //
    //if (!testObjs(t, index++))
    //    cout<<"Error: applyAllObjs.\n";
    //
    //t.addNodeGuided(Rectangle(22,8,1,1));
    //
    //if (!testQuadrants(t, index++))
    //    cout<<"Error: applyAllQuadrants.\n";
    //
    //
    //t.addNodeGuided(Rectangle(8,8,1,1));
    //t.addNodeGuided(Rectangle(8,16,1,1));
    //t.addNodeGuided(Rectangle(24,28,1,1));
    //t.addNodeGuided(Rectangle(10,26,1,1));
    //
    //vector<Rectangle> v;
    //if (!testCollision(t, Rectangle(10,22,1,1), index++))
    //    cout<<"Error: query.\n";
    //
    //if (!testCollision(t, Rectangle(1,1,1,1), index++))
    //    cout<<"Error: query.\n";
    //cout<<"Done\n";
    
    return 0;
}
