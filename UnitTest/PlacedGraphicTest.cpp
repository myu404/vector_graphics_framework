#pragma once
#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "TestHarness.h"
#include <iostream>


TEST(defaultCtor, PlacedGraphic)
{
    Framework::PlacedGraphic pg;

    constexpr VG::Point expectedPoint(0, 0);
    CHECK_EQUAL(expectedPoint, pg.getPlacementPoint());
    auto test = pg.getGraphic().get();
    CHECK_EQUAL(0, pg.getGraphic()->getPointCount());
    CHECK(pg.getGraphic()->isClosed());
}

TEST(ctor, PlacedGraphic)
{
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);

    constexpr VG::Point expected(44, 55);
    CHECK_EQUAL(expected, pg.getPlacementPoint());
    CHECK_EQUAL(vg.get(), pg.getGraphic().get());
}

TEST(copyCtor, PlacedGraphic)
{
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    Framework::PlacedGraphic pgCopy(pg);

    CHECK_EQUAL(pg.getPlacementPoint(), pgCopy.getPlacementPoint());
    CHECK_EQUAL(pg.getGraphic()->getPointCount(), pgCopy.getGraphic()->getPointCount());
    CHECK_EQUAL(pg.getGraphic()->isClosed(), pgCopy.getGraphic()->isClosed());

    // Verify copy constructor performed a deep copy of graphic object
    // Expect raw object pointer to be pointing to different addresses
    CHECK(pg.getGraphic().get() != pgCopy.getGraphic().get());
}

TEST(copyAssign, PlacedGraphic)
{
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    Framework::PlacedGraphic pgCopy = pg;

    CHECK_EQUAL(pg.getPlacementPoint(), pgCopy.getPlacementPoint());
    CHECK_EQUAL(pg.getGraphic()->getPointCount(), pgCopy.getGraphic()->getPointCount());
    CHECK_EQUAL(pg.getGraphic()->isClosed(), pgCopy.getGraphic()->isClosed());

    // Verify copy constructor performed a deep copy of graphic object
    // Expect raw object pointer to be pointing to different addresses
    CHECK(pg.getGraphic().get() != pgCopy.getGraphic().get());
}

// How to test for move semantics

TEST(setPlacementPoint, PlacedGraphic)
{
    Framework::PlacedGraphic graphic;
    graphic.setPlacementPoint(VG::Point(44, 55));

    constexpr VG::Point expected(44, 55);
    CHECK_EQUAL(expected, graphic.getPlacementPoint());
}

TEST(setGraphic, PlacedGraphic)
{
    Framework::PlacedGraphic pg;
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    pg.setGraphic(vg);
    CHECK_EQUAL(vg.get(), pg.getGraphic().get());
}

TEST(equalityOperator, PlacedGraphic)
{
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    
    VG::HVectorGraphic vg2(new VG::VectorGraphic);
    Framework::PlacedGraphic pg2(VG::Point(44, 55), vg2);

    CHECK(pg == pg2);
}

TEST(inequalityOperator, PlacedGraphic)
{
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);

    VG::HVectorGraphic vg2(new VG::VectorGraphic);
    Framework::PlacedGraphic pg2(VG::Point(144, 155), vg2);

    CHECK(pg != pg2);
}