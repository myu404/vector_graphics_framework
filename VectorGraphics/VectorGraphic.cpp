/*
* Author: Michael Yu
* C++ Programming, Summer 2021
* Vector Graphics Framework: Assignment 01
* 7/20/2021
*/

#pragma once

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
        myPath.push_back(p);
    }

    void VectorGraphic::addPoint(Point&& p)
    {
        myPath.push_back(std::move(p));
    }

    void VectorGraphic::removePoint(const Point& p)
    {
        auto newEndItr = std::remove(myPath.begin(), myPath.end(), p);
        
        if (newEndItr == myPath.end()) throw std::invalid_argument("Point does not exist in Vector Graphic. Nothing is removed/erased");
        
        myPath.erase(newEndItr, myPath.end());
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

        // implemented structured binding
        auto [minX, maxX] = minmaxDimension(compare);

        return maxX.getX() - minX.getX();
    }

    int VectorGraphic::getHeight() const
    {
        auto compare = [](const auto& pointA, const auto& pointB)
        {
            return pointA.getY() < pointB.getY();
        };

        // implemented structured binding
        auto [minY, maxY] = minmaxDimension(compare);

        return maxY.getY() - minY.getY();
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
        return myShapeStyle == other.myShapeStyle && myPath == other.myPath;
    }

    bool VectorGraphic::operator!=(const VectorGraphic& other) const
    {
        return !(*this == other);
    }
}
