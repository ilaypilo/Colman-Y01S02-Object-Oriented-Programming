#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Rectangle
{
public:
	Rectangle(int x, int y, int width, int height) : _x(x), _y(y), _width(width), _height(height) {};
	int x() const 
	{
		return _x;
	}
	int y() const 
	{
		return _y;
	}
	int height() const
	{
		return _height;
	}
	int width() const
	{
		return _width;
	}
	bool operator==(const Rectangle &rect) const
	{
		return (_x==rect.x() && _y == rect.y() && _height == rect.height() && _width == rect.width() );
	}

private:
    int _height, _width;
    int _x, _y;
};

//(1,1,40,40)


struct TreeSplitRectangle
{
	vector<Rectangle> operator()(const Rectangle& rect) const;
};

struct TreeIndexRectangle
{
	int operator()(const Rectangle& outer, const Rectangle& inner) const;
};