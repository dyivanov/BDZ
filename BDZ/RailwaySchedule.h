#ifndef RAILWAYSCHEDULE_H
#define RAILWAYSCHEDULE_H
#include "QuickTrain.h"
#include "DirectTrain.h"
#include "ExpressTrain.h"
#include "RailwayLine.h"
#include<cstring>

class RailwaySchedule
{
private:
    int numberOfLines;
    int currentLine;
    Railwayline* schedules;

    int numberOfTrains;
    int currentTrain;
    Train** listOfTrains;

    int numberOfStations;
    int currentStation;
    Station* listOfStations;

    void Copy(const RailwaySchedule& r);
    void Erase();
    void resizeL();
    void resizeT();
    void resizeS();
    void sortSchedule();

    Station* findStationByName(const char* nameOfStation);
    
public:
    RailwaySchedule();
    RailwaySchedule(const RailwaySchedule& r);
    RailwaySchedule& operator =(const RailwaySchedule& r);
    ~RailwaySchedule();

    void addLine(const Train& r, double trainDepartTime);
    void removeLine(Railwayline& r);
    
    void addTrain();
    void removeTrain();
    
    void addStation();
    void removeStation();

    void printScheduleInformation() const;
    void printScheduleAfter() const;
    void printListOfTrains() const;
    void printListOfStations()const;
    void showLinesAfter(double time) const;
    void simulateMove();

    double calculateArriveTime(double pointA, double pointB, int speed);
};
#endif // RAILWAYSCHEDULE_H
