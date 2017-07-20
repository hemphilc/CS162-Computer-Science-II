/**
  * @brief Assignment 2
  * @author Corey Hemphill
  */

#ifndef RECTANGLE
#define RECTANGLE

#include "Point.h"

/**
 * @brief The Rectangle class creates a Rectangle object on a cartesian plane
 */
class Rectangle {
private:
    Point upperLeftVertex;
    double height = 1;
    double width = 1;

public:
//Constructors//
    /**
     * @brief Rectangle Default Constructor creates Rectangle object
     */
    Rectangle();

    /**
     * @brief Rectangle Constructor creates Rectangle object using two specified points
     * @param p1 Reference for upper left vertex
     * @param p2 Reference for lower right vertex
     */
    Rectangle(const Point& p1, const Point& p2);

    /**
     * @brief Rectangle Constructor creates Rectangle object using specified upper left vertex, height, and width
     * @param p1 Reference for upper left vertex
     * @param height Rectangle height
     * @param width Rectangle width
     */
    Rectangle(const Point& p1, double theHeight, double theWidth);

//Functions//
    /**
     * @brief getUpperLeftVertex Gets upper left vertex point
     * @return Returns upperLeftVertex (x, y)
     */
    Point getUpperLeftVertex();

    /**
     * @brief getCenter Calculates center point of given Rectangle object
     * @return Returns center (x, y)
     */
    Point getCenter();

    /**
     * @brief getWidth Gets width of given Rectangle object
     * @return Returns width
     */
    double getWidth();

    /**
     * @brief getHeight Gets height of given Rectangle object
     * @return Returns height
     */
    double getHeight();

    /**
     * @brief getArea Calculates the area of given Rectangle object
     * @return Returns area
     */
    double getArea();

    /**
     * @brief getPerimeter Calculates the perimeter of given Rectangle object
     * @return Returns perimeter
     */
    double getPerimeter();

    /**
     * @brief shift Shifts the x and y coordinate of the upper left vertex point of given Rectangle object
     * @param xShift Amount to shift point on x-axis
     * @param yShift Amount to shift point on y-axis
     */
    void shift(double xShift, double yShift);

    /**
     * @brief contains Determines if the given point resides within or on the given Rectangle object's boundaries
     * @param p Reference to point to be determined
     * @return Returns false if the point resides outside the boundary of the Rectangle object, returns true otherwise
     */
    bool contains(const Point& p);
};

#endif // RECTANGLE

