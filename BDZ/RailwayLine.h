#ifndef RAILWAYLINE_H
#define RAILWAYLINE_H

#include "Station.h"
class Railwayline{
private:
    char* currentStop;
    char* lastStop;
    double departTime;
    double arriveTime;

    Train* train;

    void Copy(const Railwayline& r);
    void Erase();
public:
    Railwayline();
    Railwayline(char* currentStop, char* lastStop, double departTime, double arriveTime);
    Railwayline(const Railwayline& r);
    Railwayline& operator=(const Railwayline& r);
    bool operator ==( Railwayline& r);
    ~Railwayline();


    void setTrainPointer(const Train& t);
    Train* getTrainPointer()const;
    double getDepartTime()const;
    double getArriveTime()const;
    const char* getCurrentStop()const;
    const char* getLastStop()const;

    void printLine() const;
};
#endif // RAILWAYLINE_H
