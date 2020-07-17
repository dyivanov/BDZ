#ifndef TRAINTESTS_H
#define TRAINTESTS_H

#include "pch.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Train.h"
#include "Station.h"

TEST_CASE("Create Empty Train")
{
	Train train();
	CHECK(train.getTrainSpeed() == '0');
  CHECK(train.getCurrentTrainStation() == '0');
  CHECK(train.getListOfTrainStations() == "nullptr");
}

TEST_CASE("Create Train with speed - 120")
{
	Train train(0, 0, 120);
	CHECK(train.getTrainSpeed() == '120');
}

TEST_CASE("Test for functions - addTrainStation()")
{
	Train train();
  Station Sofia();
	CHECK(train.getCurrentTrainStation() == '0');
  train.addTrainStation(Sofia);
  CHECK(train.getCurrentTrainStation() == '1');
}

TEST_CASE("Test for functions - removeTrainStation()")
{
	Train train();
  Station Sofia();
	CHECK(train.getCurrentTrainStation() == '0');
  train.addTrainStation(Sofia);
  CHECK(train.getCurrentTrainStation() == '1');
  train.removeTrainStation(Sofia);
  CHECK(train.getCurrentTrainStation() == '0');
}
#endif // TRAIN_H
