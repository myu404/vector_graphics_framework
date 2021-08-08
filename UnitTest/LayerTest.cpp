#pragma once
#include "Layer.h"
#include "TestHarness.h"
#include <algorithm>

struct PlacedGraphicMatcher
{
    PlacedGraphicMatcher() :
        myUpperGraphicsFound(false),
        myMiddleGraphicsFound(false),
        myLowerGraphicsFound(false)
    {
    }

    void operator()(const Framework::PlacedGraphic& pg)
    {
        if (pg.getPlacementPoint() == VG::Point(11, 22))
        {
            myUpperGraphicsFound = true;
        }
        else if (pg.getPlacementPoint() == VG::Point(33, 44))
        {
            myMiddleGraphicsFound = true;
        }
        else if (pg.getPlacementPoint() == VG::Point(55, 66))
        {
            myLowerGraphicsFound = true;
        }
    }

    bool allPlacedGraphicsFound()
    {
        return myUpperGraphicsFound && myMiddleGraphicsFound && myLowerGraphicsFound;
    }

    bool onlyUpperLowerFound()
    {
        return myUpperGraphicsFound && !myMiddleGraphicsFound && myLowerGraphicsFound;
    }

private:
    bool myUpperGraphicsFound;
    bool myMiddleGraphicsFound;
    bool myLowerGraphicsFound;
};

TEST(pushBack, Layer)
{
    Framework::Layer layer("Test");
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    layer.pushBack(Framework::PlacedGraphic(VG::Point(11, 22), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(33, 44), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(55, 66), vg));

    PlacedGraphicMatcher matcher = std::for_each(layer.begin(), layer.end(), PlacedGraphicMatcher());
    CHECK(matcher.allPlacedGraphicsFound());
}

TEST(remove, Layer)
{
    Framework::Layer layer("Test");
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    layer.pushBack(Framework::PlacedGraphic(VG::Point(11, 22), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(33, 44), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(55, 66), vg));

    layer.remove(Framework::PlacedGraphic(VG::Point(33, 44), vg));

    PlacedGraphicMatcher matcher = std::for_each(layer.begin(), layer.end(), PlacedGraphicMatcher());
    CHECK(matcher.onlyUpperLowerFound());
}


TEST(copyCtor, Layer)
{
    Framework::Layer layer("Test");
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    layer.pushBack(Framework::PlacedGraphic(VG::Point(11, 22), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(33, 44), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(55, 66), vg));

    Framework::Layer layerCopy(layer);

    CHECK_EQUAL(layer.getAlias(), layerCopy.getAlias());
    CHECK(std::equal(layer.begin(), layer.end(), layerCopy.begin()));
}

TEST(copyAssign, Layer)
{
    Framework::Layer layer("Test");
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    layer.pushBack(Framework::PlacedGraphic(VG::Point(11, 22), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(33, 44), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(55, 66), vg));

    Framework::Layer layerCopy("Copy");
    layerCopy = layer;

    CHECK_EQUAL(layer.getAlias(), layerCopy.getAlias());
    CHECK(std::equal(layer.begin(), layer.end(), layerCopy.begin()));
}

TEST(moveCtor, Layer)
{
    Framework::Layer layer("Test");
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    layer.pushBack(Framework::PlacedGraphic(VG::Point(11, 22), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(33, 44), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(55, 66), vg));

    Framework::Layer layerCopy(std::move(layer));

    CHECK_EQUAL(layerCopy.getAlias(), "Test");
}

TEST(moveAssign, Layer)
{
    Framework::Layer layer("Test");
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    layer.pushBack(Framework::PlacedGraphic(VG::Point(11, 22), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(33, 44), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(55, 66), vg));

    Framework::Layer layerCopy("Copy");
    layerCopy = std::move(layer);

    CHECK_EQUAL(layerCopy.getAlias(), "Test");
}

TEST(iteratorBegin, Layer)
{
    Framework::Layer layer("Test");
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    layer.pushBack(Framework::PlacedGraphic(VG::Point(11, 22), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(33, 44), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(55, 66), vg));

    CHECK_EQUAL(VG::Point(11, 22), layer.begin()->getPlacementPoint());
}

TEST(iteratorEnd, Layer)
{
    Framework::Layer layer("Test");
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    layer.pushBack(Framework::PlacedGraphic(VG::Point(11, 22), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(33, 44), vg));
    layer.pushBack(Framework::PlacedGraphic(VG::Point(55, 66), vg));

    CHECK_EQUAL(VG::Point(55, 66), (--layer.end())->getPlacementPoint());
}

TEST(getAlias, Layer)
{
    Framework::Layer layer("Test");

    CHECK_EQUAL("Test", layer.getAlias());
}
