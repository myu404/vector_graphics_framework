/*
* Author: Michael Yu
* C++ Programming, Summer 2021
* Vector Graphics Framework: Assignment 01
* 7/20/2021
*/

#include "VectorGraphic.h"

#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace VG
{
  // ADD IMPLEMENTATION HERE!
    VectorGraphic::VectorGraphic() 
        : myPath(),
        myShapeStyle(ShapeStyle::Closed)
    {
    }

    void VectorGraphic::addPoint(const Point& p)
    {
        myPath.emplace_back(p.getX(), p.getY());
    }

    void VectorGraphic::addPoint(Point&& p)
    {
        myPath.emplace_back(std::move(p.getX()), std::move(p.getY()));
    }

    void VectorGraphic::removePoint(const Point& p)
    {
        myPath.erase(std::remove(myPath.begin(), myPath.end(), p), myPath.end());
    }

    void VectorGraphic::erasePoint(int index)
    {
        removePoint(getPoint(index));
    }

    void VectorGraphic::openShape()
    {
        myShapeStyle = ShapeStyle::Open;
    }

    void VectorGraphic::closeShape()
    {
        myShapeStyle = ShapeStyle::Closed;
    }

    bool VectorGraphic::isOpen() const
    {
        return myShapeStyle == ShapeStyle::Open;
    }

    bool VectorGraphic::isClosed() const
    {
        return !isOpen();
    }

    int VectorGraphic::getWidth() const
    {
        auto compare = [](const auto& pointA, const auto& pointB)
        {
            return pointA.getX() < pointB.getX();
        };

        auto [minX, maxX] = minmaxDimension(compare);

        return results.second.getX() - results.first.getX();
    }

    int VectorGraphic::getHeight() const
    {
        auto compare = [](const auto& pointA, const auto& pointB)
        {
            return pointA.getY() < pointB.getY();
        };

        auto results = minmaxDimension(compare);
        return results.second.getY() - results.first.getY();
    }

    std::pair<Point, Point> VectorGraphic::minmaxDimension(std::function<bool(const Point& pointA, const Point& pointB)> compare) const
    {
        auto results = std::minmax_element(myPath.begin(), myPath.end(), compare);
        return std::pair<Point, Point>(*results.first, *results.second);
    }


    size_t VectorGraphic::getPointCount() const
    {
        return myPath.size();
    }

    const Point& VectorGraphic::getPoint(int index) const
    {
        // at() throws out of range exception if index is out of orange
        return myPath.at(index);
    }

    bool VectorGraphic::operator==(const VectorGraphic& other) const
    {
        return myShapeStyle == other.myShapeStyle && std::ranges::equal(myPath, other.myPath);
    }

    bool VectorGraphic::operator!=(const VectorGraphic& other) const
    {
        return !(*this == other);
    }
}
