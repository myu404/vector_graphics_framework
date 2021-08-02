#include "Scene.h"
#include "TestHarness.h"
#include <algorithm>

struct LayerMatcher
{
    LayerMatcher() :
    myMountainsFound(false),
    mySeaFound(false),
    mySkyFound(false)
    {
    }
    
    void operator()(const Framework::Layer& layer)
    {
        if (layer.getAlias() == "Mountains")
        {
            myMountainsFound = true;
        }
        else if (layer.getAlias() == "Sea")
        {
            mySeaFound = true;
        }
        else if (layer.getAlias() == "Sky")
        {
            mySkyFound = true;
        }
    }
    
    bool allLayersFound()
    {
        return myMountainsFound && mySeaFound && mySkyFound;
    }
    
    bool onlyMountainsSkyFound()
    {
        return myMountainsFound && !mySeaFound && mySkyFound;
    }
    
private:
    bool myMountainsFound;
    bool mySeaFound;
    bool mySkyFound;
};

TEST(pushBack, Scene)
{
    Framework::Scene scene(800, 600);
	scene.pushBack(Framework::Layer("Mountains"));
	scene.pushBack(Framework::Layer("Sea"));
	scene.pushBack(Framework::Layer("Sky"));
    
    LayerMatcher matcher = std::for_each(scene.begin(), scene.end(), LayerMatcher());
    CHECK(matcher.allLayersFound());
}

TEST(remove, Scene)
{
    Framework::Scene scene(800, 600);
	scene.pushBack(Framework::Layer("Mountains"));
	scene.pushBack(Framework::Layer("Sea"));
	scene.pushBack(Framework::Layer("Sky"));
    
    scene.remove(Framework::Layer("Sea"));
    
    LayerMatcher matcher = std::for_each(scene.begin(), scene.end(), LayerMatcher());
    CHECK(matcher.onlyMountainsSkyFound());
}

TEST(copyCtor, Scene)
{
    Framework::Scene scene(800, 600);
    scene.pushBack(Framework::Layer("Mountains"));
    scene.pushBack(Framework::Layer("Sea"));
    scene.pushBack(Framework::Layer("Sky"));

    Framework::Scene sceneCopy(scene);

    CHECK_EQUAL(scene.getWidth(), sceneCopy.getWidth());
    CHECK_EQUAL(scene.getHeight(), sceneCopy.getHeight());
    // Need to implement equality operators for Layer to perform the following check
    //CHECK(std::equal(scene.begin(), scene.end(), sceneCopy.begin()));
}

TEST(copyAssign, Scene)
{
    Framework::Scene scene(800, 600);
    scene.pushBack(Framework::Layer("Mountains"));
    scene.pushBack(Framework::Layer("Sea"));
    scene.pushBack(Framework::Layer("Sky"));

    Framework::Scene sceneCopy = scene;

    CHECK_EQUAL(scene.getWidth(), sceneCopy.getWidth());
    CHECK_EQUAL(scene.getHeight(), sceneCopy.getHeight());
    // Need to implement equality operators for Layer to perform the following check
    //CHECK(std::equal(scene.begin(), scene.end(), sceneCopy.begin()));
}

TEST(iteratorBegin, Scene)
{
    Framework::Scene scene(800, 600);
    scene.pushBack(Framework::Layer("Mountains"));
    scene.pushBack(Framework::Layer("Sea"));
    scene.pushBack(Framework::Layer("Sky"));

    CHECK_EQUAL("Mountains", scene.begin()->getAlias());
}

TEST(iteratorEnd, Scene)
{
    Framework::Scene scene(800, 600);
    scene.pushBack(Framework::Layer("Mountains"));
    scene.pushBack(Framework::Layer("Sea"));
    scene.pushBack(Framework::Layer("Sky"));

    CHECK_EQUAL("Sky", (--scene.end())->getAlias());
}

TEST(getDimensions, Scene)
{
    Framework::Scene scene(800, 600);

    CHECK_EQUAL(800, scene.getWidth());
    CHECK_EQUAL(600, scene.getHeight());
}
