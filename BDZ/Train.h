#ifndef TRAIN_H
#define TRAIN_H
#include<iostream>
#include "Station.h"
class Station;
class  Train{
private:
    int numberOfWagons;
    int* capacityOfWagons;
    int speed;
    int currentStation;
    int numberOfStations;
    Station* stations;

    void Copy(const Train& t);
    void Erase();
    void Resize();


public:
    Train();
    Train(int numberOfWagons, const int* capacityOfWagons, int speed);
    Train(const Train& t);
    Train& operator = (const Train& t);
    friend std::ostream& operator<<(std::ostream& os, const Train& t);
    friend std::istream& operator>>(std::istream& is, Train& t);
    virtual Train* clone() const;
    virtual~Train();

    void Print(std::ostream& os) const;
    void Read(std::istream& is);

    void addStation(const Station& s);
    void removeStation(const Station& s);

    void setCapacityOfWagons(int numberOfWagons, const int* capacityOfWagons);
    int getSpeed()const;
    int getCurrentStation()const;
    const Station* getStations()const;
};
#endif // TRAIN_H
