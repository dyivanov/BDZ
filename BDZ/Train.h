#ifndef TRAIN_H
#define TRAIN_H
#include<iostream>
#include "Station.h"

class Station;
class  Train
{
private:
    int numberOfWagons;
    int* capacityOfWagons;
    int trainSpeed;
    int currentTrainStation;
    int numberOfTrainStation;
    Station* trainStation;

    void Copy(const Train& t);
    void Erase();
    void Resize();

public:
    Train();
    Train(int numberOfWagons, const int* capacityOfWagons, int trainSpeed);
    Train(const Train& t);
    Train& operator = (const Train& t);
    friend std::ostream& operator<<(std::ostream& os, const Train& t);
    friend std::istream& operator>>(std::istream& is, Train& t);
    virtual Train* clone() const;
    virtual~Train();

    void printTrainInformation(std::ostream& os) const;
    void readTrainInformation(std::istream& is);

    void addTrainStation(const Station& s);
    void removeTrainStation(const Station& s);

    void setCapacityOfWagons(int numberOfWagons, const int* capacityOfWagons);
    int getTrainSpeed()const;
    int getCurrentTrainStation()const;
    const Station* getListOfTrainStations()const;
};
#endif // TRAIN_H
