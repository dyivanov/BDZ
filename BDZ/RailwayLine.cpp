#include "RailwayLine.h"
#include<iostream>
#include<cstring>
#include <cassert>

void Railwayline::Copy(const Railwayline& r)
{
    this->currentTrainStop = new char[strlen(r.currentTrainStop) + 1];
    strcpy(this->currentTrainStop, r.currentTrainStop);
    
    this->lastTrainStop = new char[strlen(r.lastTrainStop) + 1];
    strcpy(this->lastTrainStop, r.lastTrainStop);
    
    train = r.train;
    
    this->trainArriveTime = r.trainArriveTime;
    
    this->trainDepartTime = r.trainDepartTime;
}

void Railwayline::Erase()
{
    delete[] currentTrainStop;
    delete[] lastTrainStop;
}

Railwayline::Railwayline()
{
    currentTrainStop = nullptr;
    lastTrainStop = nullptr;
    train = nullptr;
    trainDepartTime = 0.0;
    trainArriveTime = 0.0;
}

Railwayline::Railwayline(char* currentTrainStop, char* lastTrainStop, double trainDepartTime, double trainArriveTime)
{
    assert(currentTrainStop != nullptr && "Current train stop name is nullptr");
    this->currentTrainStop = new char[strlen(currentTrainStop) + 1];
    strcpy(this->currentTrainStop, currentTrainStop);
    
    assert(lastTrainStop != nullptr && "Last train stop name is nullptr");
    this->lastTrainStop = new char[strlen(lastTrainStop) + 1];
    strcpy(this->lastTrainStop, lastTrainStop);
    
    assert(trainDepartTime >= 0 && "Train depart time should be possitive number!");
    this->trainDepartTime = trainDepartTime;
    
    assert(trainArriveTime >= 0 && "Train arrive time should be possitive number!");
    this->trainArriveTime = trainArriveTime;
}

Railwayline::Railwayline(const Railwayline& r)
{
    Copy(r);
}

Railwayline& Railwayline::operator =(const Railwayline& r)
{
    if(this != &r)
    {
        Erase();
        Copy(r);
    }
    
    return *this;
}

bool Railwayline::operator==( Railwayline& r)
{
    if( (!strcmp(this->currentTrainStop, r.currentTrainStop) )&&
        (!strcmp(this->lastTrainStop, r.lastTrainStop)) &&
        (this->trainArriveTime == r.trainArriveTime) &&
        (this->trainDepartTime == r.trainDepartTime))
    {
        return true;
    }
    return false;
}

Railwayline::~Railwayline()
{
    Erase();
}

void Railwayline::setTrainPointer(const Train& t)
{
    train = t.clone();
}

Train* Railwayline::getTrainPointer() const
{
    return train;
}

double Railwayline::getTrainDepartTime() const 
{
    return trainDepartTime;
}

double Railwayline::getTrainArriveTime() const
{
    return trainArriveTime;
}

const char* Railwayline::getTrainCurrentStop() const
{
    return currentTrainStop;
}

const char* Railwayline::getTrainLastStop() const
{
    return lastTrainStop;
}

void Railwayline::printTrainInformation() const
{
    std::cout<<"Current stop: "<<currentTrainStop<<" -> "<<"Last stop: "<<lastTrainStop<<endl;
    std::cout<<"     Depart time:"<<this->trainDepartTime<<std::endl;
    std::cout<<"     Arrive time:"<<this->trainArriveTime<<std::endl;
}
