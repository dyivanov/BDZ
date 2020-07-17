#ifndef RAILWAYLINE_H
#define RAILWAYLINE_H
#include "Station.h"

class Railwayline
{
private:
    char* currentTrainStop;
    char* lastTrainStop;
    double trainDepartTime;
    double trainArriveTime;

    Train* train;

    void Copy(const Railwayline& r);
    void Erase();
    
public:
    Railwayline();
    Railwayline(char* currentTrainStop, char* lastTrainStop, double trainDepartTime, double trainArriveTime);
    Railwayline(const Railwayline& r);
    Railwayline& operator=(const Railwayline& r);
    bool operator ==( Railwayline& r);
    ~Railwayline();

    void setTrainPointer(const Train& t);
    
    Train* getTrainPointer()const;
    double getTrainDepartTime()const;
    double getTrainArriveTime()const;
    const char* getTrainCurrentStop()const;
    const char* getTrainLastStop()const;

    void printRailwayLineInformation() const;
};
#endif // RAILWAYLINE_H
