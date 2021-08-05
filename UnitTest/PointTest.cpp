/*
* Author: Michael Yu
* C++ Programming, Summer 2021
* Vector Graphics Framework: Assignment 01
* 7/20/2021
*/

//
//  PointTest.cpp
//  Assignment1
//
//  Created by Chris Elderkin on 4/26/15.
//  Copyright (c) 2015 Chris Elderkin. All rights reserved.
//

#include "Point.h"
#include "TestHarness.h"

#include <sstream>


TEST(equality, Point)
{
    CHECK_EQUAL(VG::Point(1, 2), VG::Point(1, 2));
}

TEST(inequality, Point)
{
    CHECK(VG::Point(1, 2) != VG::Point(3, 4));
}

TEST(constexprPoint, Point)
{
    constexpr int i = VG::Point{4, 5}.getX();

    CHECK_EQUAL(i, 4);
}

// ADD MORE TESTS HERE!
TEST(ctor, Point)
{
    VG::Point p(1, 2);
    CHECK_EQUAL(1, p.getX());
    CHECK_EQUAL(2, p.getY());
}

TEST(copyCtor, Point)
{
    VG::Point p(1, 2);

    VG::Point pCopy(p);

    CHECK(p == pCopy);
}

TEST(copyAssignment, Point)
{
    VG::Point p(1, 2);

    VG::Point pCopy(199, 299);

    pCopy = p;

    CHECK(p == pCopy);
    CHECK(pCopy != VG::Point(199, 299));
}


TEST(outputOperator, Point)
{
    std::stringstream ss;

    VG::Point p(1, 2);
    
    ss << p;

    CHECK_EQUAL("Point x=\"1\" y=\"2\"", ss.str());
}

TEST(moveCtor, Point)
{
    // Moving is the same as copying for POD (plain old data) types
    VG::Point p(1, 2);

    VG::Point pMove(std::move(p));

    CHECK(p == pMove);
}

TEST(moveAssignment, Point)
{
    // Moving is the same as copying for POD (plain old data) types
    VG::Point p(1, 2);

    VG::Point pMove(199, 299);

    pMove = std::move(p);

    CHECK(p == pMove);
}
