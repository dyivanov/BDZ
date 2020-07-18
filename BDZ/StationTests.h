#ifndef STATIONTESTS_H
#define STATIONTESTS_H
#include "pch.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Train.h"
#include "Station.h"

TEST_CASE("Create empty station")
{
	Station station();
	CHECK(station.getTrainPriority() == '1');
	CHECK(station.getNameOfStation() == 'nullptr');
	CHECK(station.getX() == '0');
	CHECK(station.getY() == '0');
}

TEST_CASE("Create station Sofia")
{
	Station station("Sofia", 10 , 12, 15);
	CHECK(station.getTrainPriority() == '10');
	CHECK(station.getNameOfStation() == 'Sofia');
	CHECK(station.getX() == '12');
	CHECK(station.getY() == '15');
}

TEST_CASE("Test case for operators =")
{
	Station Sofia("Sofia", 10 , 12, 15);
	Station Burgas("Burgas", 7 , 10, 19);
	Sofia = Burgas;
	
	CHECK(Sofia.getTrainPriority() == '7');
	CHECK(Sofia.getNameOfStation() == 'Burgas');
	CHECK(Sofia.getX() == '10');
	CHECK(Sofia.getY() == '19');
}

TEST_CASE("Test case for operators ==")
{
	Station Sofia("Sofia", 10 , 12, 15);
	Station Burgas("Burgas", 7 , 10, 19);
	CHECK(!(Sofia == Burgas));
}
#endif // STATIONTESTS_H
