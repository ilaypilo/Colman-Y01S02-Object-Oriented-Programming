#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Rectangle
{
public:
    Rectangle(int x, int y, int width, int height);
    
    int x() const;
    int y() const;
    int height() const;
    int width() const;
private:
    int _height, _width;
    int _x, _y;
};

struct TreeSplitRectangle
{
    vector<Rectangle> operator()(const Rectangle& rect) const;
};

struct TreeIndexRectangle
{
    int operator()(const Rectangle& outer, const Rectangle& inner) const;
};