#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "TestHarness.h"
#include <iostream>

TEST(ctor, PlacedGraphic)
{
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);

    constexpr VG::Point expected(44, 55);
    CHECK_EQUAL(expected, pg.getPlacementPoint());
    auto test = pg.getGraphic().get();
    CHECK_EQUAL(vg.get(), test);
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
    auto test = pg.getGraphic().get();
    CHECK_EQUAL(vg.get(), test);
}
