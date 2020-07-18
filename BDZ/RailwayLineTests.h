#ifndef RAILWAYLINETESTS_H
#define RAILWAYLINETESTS_H

#include "pch.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "RailwayLine.h"

TEST_CASE("Create empty RailwayLine")
{
    Railwayline railwayline();
    CHECK(railwayline.getTrainPointer() == "nullptr");
    CHECK(railwayline.getTrainCurrentStop() == "nullptr");
    CHECK(railwayline.getTrainLastStop() == "nullptr");
    CHECK(railwayline.getTrainDepartTime() == "0.0");
    CHECK(railwayline.getTrainArriveTime() == "0.0");
}

TEST_CASE("Create non-empty RailwayLine")
{
    Railwayline railwayline("Sofia", "Burgas", 12.00, 19.30);
    CHECK(railwayline.getTrainPointer() == "nullptr");
    CHECK(railwayline.getTrainCurrentStop() == "Sofia");
    CHECK(railwayline.getTrainLastStop() == "Burgas");
    CHECK(railwayline.getTrainDepartTime() == "12.00");
    CHECK(railwayline.getTrainArriveTime() == "19.30");
}
#endif // RAILWAYLINETESTS_H
