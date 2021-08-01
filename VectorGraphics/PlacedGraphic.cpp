#include "PlacedGraphic.h"

namespace Framework
{
    PlacedGraphic::PlacedGraphic()
        : placementPoint(VG::Point(0, 0)),
        graphic(std::make_shared<VG::VectorGraphic>())
    {
    }

    PlacedGraphic::PlacedGraphic(VG::Point const& point, VG::HVectorGraphic& vectorGraphic)
        : placementPoint(point),
        graphic(vectorGraphic)
    {
    }

    void PlacedGraphic::setPlacementPoint(VG::Point const& placement)
    {
        placementPoint = placement;
    }

    VG::Point const& PlacedGraphic::getPlacementPoint() const
    {
        return placementPoint;
    }

    void PlacedGraphic::setGraphic(VG::HVectorGraphic const& graphic)
    {
        this->graphic = graphic;
    }

    VG::HVectorGraphic const& PlacedGraphic::getGraphic() const
    {
        return graphic;
    }

    bool PlacedGraphic::operator==(const PlacedGraphic& other) const
    {
        return (placementPoint == other.placementPoint && *graphic == *other.graphic);
    }

    bool PlacedGraphic::operator!=(const PlacedGraphic& other) const
    {
        return !(*this == other);
    }
}