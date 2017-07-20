/**
  * @brief Assignment 2
  * @author Corey Hemphill
  */

#include <iostream>
#include <cmath>

#include "Rectangle.h"
#include "Point.h"

using namespace std;

Rectangle::Rectangle()
    : upperLeftVertex(0, 0) {}

Rectangle::Rectangle(const Point& p1, const Point& p2) {
    upperLeftVertex.setX(p1.getX());
    upperLeftVertex.setY(p1.getY());
    height = p1.getY() - p2.getY();
    width = p2.getX() - p1.getX();
}

Rectangle::Rectangle(const Point& p1, double theHeight, double theWidth) {
    upperLeftVertex.setX(p1.getX());
    upperLeftVertex.setY(p1.getY());
    height = theHeight;
    width = theWidth;
}

Point Rectangle::getUpperLeftVertex() {
    return upperLeftVertex;
}

Point Rectangle::getCenter() {
    Point center((upperLeftVertex.getX() + (getWidth() / 2.0)), (upperLeftVertex.getY() - (getHeight() / 2.0)));
    return center;
}

double Rectangle::getWidth() {
    return width;
}

double Rectangle::getHeight() {
    return height;
}

double Rectangle::getArea() {
    double area = getWidth() * getHeight();
    return area;
}

double Rectangle::getPerimeter() {
    double perimeter = (2 * getWidth()) + (2 * getHeight());
    return perimeter;
}

void Rectangle::shift(double xShift, double yShift) {
    upperLeftVertex.setX(upperLeftVertex.getX() + xShift);
    upperLeftVertex.setY(upperLeftVertex.getY() + yShift);
}

bool Rectangle::contains(const Point& p) {
    Point lowerRightVertex((upperLeftVertex.getX() + getWidth()), (upperLeftVertex.getY() - getHeight()));
    if ((p.getX() < upperLeftVertex.getX()) || (p.getX() > lowerRightVertex.getX())) {
        return false;
    }
    else if ((p.getY() > upperLeftVertex.getY()) || (p.getY() < lowerRightVertex.getY())) {
        return false;
    }
    else {
        return true;
    }
}

