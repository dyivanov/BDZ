#include "RailwayLine.h"
#include<iostream>
#include<cstring>
using namespace std;

void Railwayline::Copy(const Railwayline& r){
    this->currentStop = new char[strlen(r.currentStop) + 1];
    strcpy(this->currentStop, r.currentStop);
    this->lastStop = new char[strlen(r.lastStop) + 1];
    strcpy(this->lastStop, r.lastStop);
    train = r.train;
    this->arriveTime = r.arriveTime;
    this->departTime = r.departTime;
}
void Railwayline::Erase(){
    delete[] currentStop;
    delete[] lastStop;
}

Railwayline::Railwayline(){
    currentStop = nullptr;
    lastStop = nullptr;
    train = nullptr;
    departTime = 0.0;
    arriveTime = 0.0;
}

Railwayline::Railwayline(char* currentStop, char* lastStop, double departTime, double arriveTime){
    this->currentStop = new char[strlen(currentStop) + 1];
    strcpy(this->currentStop, currentStop);
    this->lastStop = new char[strlen(lastStop) + 1];
    strcpy(this->lastStop, lastStop);
    this->departTime = departTime;
    this->arriveTime = arriveTime;
}
Railwayline::Railwayline(const Railwayline& r){
    Copy(r);
}
Railwayline& Railwayline::operator =(const Railwayline& r){
        if(this != &r){
        Erase();
        Copy(r);
    }
    return *this;
}
bool Railwayline::operator==( Railwayline& r){
    if(!strcmp(this->currentStop,r.currentStop) &&
       !strcmp(this->lastStop,r.lastStop) &&
       this->arriveTime == r.arriveTime &&
       this->departTime == r.departTime){
        return true;
       }
    return false;
}
Railwayline::~Railwayline(){
    Erase();
}
void Railwayline::printLine()const{
    cout<<"Current stop: "<<currentStop<<" -> "<<"Last stop: "<<lastStop<<endl;
    cout<<"     Depart time:"<<this->departTime<<endl;
    cout<<"     Arrive time:"<<this->arriveTime<<endl;
}
void Railwayline::setTrainPointer(const Train& t){
    train = t.clone();
}
Train* Railwayline::getTrainPointer()const{
    return train;
}
double Railwayline::getDepartTime()const{
    return departTime;
}
double Railwayline::getArriveTime()const{
    return arriveTime;
}
const char* Railwayline::getCurrentStop()const{
    return currentStop;
}
const char* Railwayline::getLastStop()const{
    return lastStop;
}
