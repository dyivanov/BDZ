#include<iostream>
#include "Station.h"
#include<cstring>
#define MIN_Priority 1
#define MAX_Priority 10

void Station::Copy(const Station& s)
{
    this->nameOfStation = new char[strlen(s.nameOfStation) + 1];
    strcpy(this->nameOfStation, s.nameOfStation);
    this->setStationPriority(s.priority);
    this->numberOfTrains = s.numberOfTrains;
    this->currentTrain = s.currentTrain;
    this->x = s.x;
    this->y = s.y;
    
    trains = new Train*[s.numberOfTrains];
    for(int i = 0; i < currentTrain; ++i)
    {
        trains[i] = new Train();
        trains[i] = s.trains[i];
    }
}
void Station::Erase()
{
    delete[] nameOfStation;
}

void Station::Resize()
{
    Train** temp = trains;
    numberOfTrains *= 2;
    trains = new Train*[numberOfTrains];
    for(int i = 0; i < currentTrain; ++i)
    {
        trains[i] = new Train();
        trains[i] = temp[i];
    }
    delete[] temp;
}

Station::Station():nameOfStation(nullptr), trains(nullptr), stationPriority(1), numberOfTrains(0), currentTrain(0), x(0), y(0){}

Station::Station(const char* nameOfStation, int stationPriority, double x, double y)
{
    assert(nameOfStation != nullptr && "Name of the statios requires non-null argument");
    this->nameOfStation = new char[strlen(nameOfStation) + 1];
    strcpy(this->nameOfStation, nameOfStation);
    assert(stationPriority > 0 && "Station priority requires value > 0");
    this->setStationPriority(stationPriority);
    this->x = x;
    this->y = y;
    numberOfTrains = 1;
    currentTrain = 0;
    trains = new Train*[numberOfTrains];
}

Station::Station(const Station& s)
{
    Copy(s);
}

Station &Station::operator =(const Station& s)
{
    if(this != &s)
    {
        Erase();
        Copy(s);
    }
    return *this;
}

bool Station::operator ==(const Station& s)
{
    if((this->getNameOfStation() == s.getNameOfStation()) &&
       (this->getPriority() == s.getPriority()) &&
       (this->getX() == s.getX()) &&
       (this->getY() == s.getY()))
    {
        return true;
    }
    return false;

}

std::ostream &operator<<(std::ostream &os, const Station &s)
{
    s.printStationInformation(os);
    return os;
}

std::istream &operator>>(std::istream &is, Station &s) {
    s.readStationInformation(is);
    return is;
}

Station::~Station(){
    Erase();
}

void Station::addTrain(Train& t)
{
    if(currentTrain == numberOfTrains)
    {
        Resize();
    }
    trains[currentTrain] = &t;
    ++currentTrain;
}

void Station::removeTrain(const Train& t)
{
    for(int i = 0; i < currentTrain; ++i)
    {
        if(true)
        {
            for(int j = i; j < currentTrain-1; ++j)
            {
                trains[j] = trains[j+1];
            }
            break;
        }
    }
}

void Station::printStationInformation(std::ostream &os) const
{
    os<<"Name of the station: "<<nameOfStation<<std::endl;
    os<<"Priority of the station: "<<stationPriority<<std::endl;
    os<<"Coordinates: "<<"("<<x<<", "<<y<<")"<<std::endl;
    os<<"Number of the trains: "<<currentTrain<<std::endl;
    if(currentTrain > 0)
    {
        std::cout<<"     Trains in the station: "<<std::endl;
        for(int i=0;i<currentTrain; ++i)
        {
            std::cout<<*(trains[i]);
        }
    }
}
void Station::readStationInformation(std::istream &is)
{
    if(nameOfStation != nullptr)
    {
        return;
    }
    is.ignore();
    
    std::cout<<"Name of the station: ";
    char buffer[1024];
    is.getline(buffer,1024);
    nameOfStation = new char[strlen(buffer) + 1];
    strcpy(nameOfStation,buffer);
    
    std::cout<<"Priority of the station: ";
    is>>priority;
    is.ignore();
    
    std::cout<<"Coordinates: ";
    is>>x>>y;
    is.ignore();
}
void Station::setStationPriority(int stationPriority)
{
    if(MIN_Priority <= stationPriority && stationPriority <= MAX_Priority)
    {
        this->stationPriority = stationPriority;
    }
    else
    {
        std::cout<<"Invalid priority, it must be 1-10!"<<std::endl;
    }
}

int Station::getPriority()
    const
{
    return stationPriority;
}

char* Station::getNameOfStation() const
{
    return this->nameOfStation;
}

double Station::getX() const
{
    return x;
}
double Station::getY() const
{
    return y;
}
