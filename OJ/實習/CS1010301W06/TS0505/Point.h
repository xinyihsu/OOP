/*************************************************************************
 * File: Point.h
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-03
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-05
 * Description: be used to store and manipulate the location of a point in the plane
 *************************************************************************/
#pragma once
class Point
{
public:
	Point();
	Point(Point& point);
	~Point();
	void Set(float x, float y);
	void Move(float x, float y);
	void Rotate(void);
	void Reflect(void);
	float GetHorizontal(void) const;
	float GetVertical(void) const;
private:
	float coordinate[2] = { 0 };
};
