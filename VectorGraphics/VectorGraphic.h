/*
* Author: Michael Yu
* C++ Programming, Summer 2021
* Vector Graphics Framework: Assignment 01
* 7/20/2021
*/

#pragma once

#include "Point.h"
#include <vector>

#include <functional>

namespace VG
{
    using Points = std::vector<Point>;

    class VectorGraphic
    {
    public:
        VectorGraphic();

        VectorGraphic(const VectorGraphic& other) = default;
        VectorGraphic(VectorGraphic&& other) = default;
        ~VectorGraphic() = default;

        VectorGraphic& operator=(const VectorGraphic&) = default;
        VectorGraphic& operator=(VectorGraphic&&) = default;

        void addPoint(const Point& p);
        void addPoint(Point&& p);
        void removePoint(const Point& p);
        void erasePoint(int index);

        void openShape();
        void closeShape();

        bool isOpen() const;
        bool isClosed() const;

        int getWidth() const;
        int getHeight() const;

        size_t getPointCount() const;
        const Point& getPoint(int index) const;

        bool operator==(const VectorGraphic&) const = default;
        bool operator!=(const VectorGraphic&) const = default;

    private:
        Points myPath;

        enum class ShapeStyle { Open, Closed } myShapeStyle;

        std::pair<Point, Point> minmaxDimension(std::function<bool(const Point& pointA, const Point& pointB)> compare) const;
    };

}
