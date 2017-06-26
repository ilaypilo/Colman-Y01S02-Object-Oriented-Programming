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
	//bool operator!=(const Rectangle &rect) const
	//{
	//	return (_x != rect.x() || _y != rect.y() || _height != rect.height() || _width != rect.width());
	//}

private:
    int _height, _width;
    int _x, _y;
};

//(1,1,40,40)


struct TreeSplitRectangle
{
	vector<Rectangle> operator()(const Rectangle& rect) const 
	{
		// Rectangle: int x, int y, int width, int height
		auto wh = rect.width() / 2;
		auto hh = rect.height() / 2;
		vector<Rectangle> splited;
		Rectangle q0(rect.x()+ wh, rect.y(), wh, hh);
		Rectangle q1(rect.x(), rect.y(), wh, hh);
		Rectangle q2(rect.x(), rect.y()+ hh, wh, hh);
		Rectangle q3(rect.x()+ wh, rect.y()+ hh, wh, hh);
		splited.push_back(q0);
		splited.push_back(q1);
		splited.push_back(q2);
		splited.push_back(q3);

		return splited;
	}
};

struct TreeIndexRectangle
{
	int operator()(const Rectangle& outer, const Rectangle& inner) const 
	{

		auto q = -1;
		if (inner.y() + inner.height() > (outer.y() + outer.height()) ||
			inner.x() + inner.width() > (outer.x() + outer.width()) )
		{
			q = -1;
		}

		//check x
		if (inner.x() < outer.x() + (outer.width() / 2))
		{
			q = 1;
		}
		else
		{
			q = 0;
		}
		//check y
		if (inner.y() > outer.y() + (outer.height() / 2))
		{
			switch (q) 
			{
			case 0:
				q = 3;
				break;
			case 1:
				q = 2;
				break;
			}
		}
		return q;
	}
};