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
    Framework::PlacedGraphic pgCopy(VG::Point(999, 9999), vg);
    pgCopy = pg;

    CHECK_EQUAL(pg.getPlacementPoint(), pgCopy.getPlacementPoint());
    CHECK_EQUAL(pg.getGraphic()->getPointCount(), pgCopy.getGraphic()->getPointCount());
    CHECK_EQUAL(pg.getGraphic()->isClosed(), pgCopy.getGraphic()->isClosed());

    // Verify copy constructor performed a deep copy of graphic object
    // Expect raw object pointer to be pointing to different addresses
    CHECK(pg.getGraphic().get() != pgCopy.getGraphic().get());
}

TEST(moveCtor, PlacedGraphic)
{
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    vg->addPoint(VG::Point{ 1, 1 });
    vg->addPoint(VG::Point{ 2, 2 });
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    Framework::PlacedGraphic pgMove(std::move(pg));

    CHECK_EQUAL(pgMove.getPlacementPoint(), VG::Point(44, 55));
    CHECK_EQUAL(pgMove.getGraphic()->getPointCount(), 2);
    CHECK(pgMove.getGraphic()->isClosed());
}

TEST(moveAssignment, PlacedGraphic)
{
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    vg->addPoint(VG::Point{ 1, 1 });
    vg->addPoint(VG::Point{ 2, 2 });
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);

    VG::HVectorGraphic vg2(new VG::VectorGraphic);
    vg2->addPoint(VG::Point{ 3, 3 });
    vg2->openShape();
    Framework::PlacedGraphic pgMove(VG::Point(66, 77), vg);
    pgMove = std::move(pg);

    CHECK_EQUAL(pgMove.getPlacementPoint(), VG::Point(44, 55));
    CHECK_EQUAL(pgMove.getGraphic()->getPointCount(), 2);
    CHECK(pgMove.getGraphic()->isClosed());
}

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