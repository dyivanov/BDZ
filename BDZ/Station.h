#ifndef STATION_H
#define STATION_H
#include "Train.h"

class Train;
class Station
{
private:
    char* nameOfStation;
    Train** listOftrains;
    int trainPriority;
    int numberOfTrains;
    int currentTrain;
    double x;
    double y;

    void Copy(const Station& s);
    void Erase();
    void Resize();
public:
    Station();
    Station(const char* nameOfStation, int trainPriority, double x, double y);
    Station(const Station& s);
    Station& operator = (const Station& s);
    bool operator ==(const Station& s);
    friend std::ostream& operator<<(std::ostream& os, const Station& t);
    friend std::istream& operator>>(std::istream& is, Station& t);
    ~Station();

    void setTrainPriority(int trainPriority);
    
    int getTrainPriority()const;
    char* getNameOfStation() const;
    double getX()const;
    double getY()const;

    void addTrain(Train& t);
    void removeTrain(const Train& t);
    void printStationInformation(std::ostream &os) const;
    void readStationInformation(std::istream &is);
};
#endif // STATION_H
