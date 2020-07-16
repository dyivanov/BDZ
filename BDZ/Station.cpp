#include<iostream>
#include "Station.h"
#include<cstring>
using namespace std;
void Station::Copy(const Station& s){
    this->nameOfStation = new char[strlen(s.nameOfStation) + 1];
    strcpy(this->nameOfStation, s.nameOfStation);
    this->setPriority(s.priority);
    this->numberOfTrains = s.numberOfTrains;
    this->currentTrain = s.currentTrain;
    this->x = s.x;
    this->y = s.y;
    trains = new Train*[s.numberOfTrains];
    for(int i = 0; i < currentTrain; ++i){
        trains[i] = new Train();
        trains[i] = s.trains[i];
    }
}
void Station::Erase(){
    delete[] nameOfStation;
}
void Station::Resize(){
    Train** temp = trains;
    numberOfTrains *= 2;
    trains = new Train*[numberOfTrains];
    for(int i = 0; i < currentTrain; ++i){
        trains[i] = new Train();
        trains[i] = temp[i];
    }
    delete[] temp;
}

Station::Station():nameOfStation(nullptr),trains(nullptr), priority(1), numberOfTrains(0), currentTrain(0), x(0), y(0){}
Station::Station(const char* nameOfStation, int priority, double x, double y){
    this->nameOfStation = new char[strlen(nameOfStation) + 1];
    strcpy(this->nameOfStation, nameOfStation);
    this->setPriority(priority);
    this->x = x;
    this->y = y;
    numberOfTrains = 1;
    currentTrain = 0;
    trains = new Train*[numberOfTrains];
}
Station::Station(const Station& s){
    Copy(s);
}
Station &Station::operator =(const Station& s){
    if(this != &s){
        Erase();
        Copy(s);
    }
    return *this;
}
bool Station::operator ==(const Station& s){
    if(this->getNameOfStation() == s.getNameOfStation() &&
       this->getPriority() == s.getPriority() &&
       this->getX() == s.getX() &&
        this->getY() == s.getY()){
        return true;
    }
    return false;

}
std::ostream &operator<<(std::ostream &os, const Station &s) {
    s.Print(os);
    return os;
}
std::istream &operator>>(std::istream &is, Station &s) {
    s.Read(is);
    return is;
}
Station::~Station(){
    Erase();
}

void Station::addTrain(Train& t){
    if(currentTrain == numberOfTrains){
        Resize();
    }
    trains[currentTrain] = &t;
    ++currentTrain;
}
void Station::removeTrain(const Train& t){
    for(int i = 0; i < currentTrain; ++i){
        if(true){
            for(int j = i; j < currentTrain-1; ++j){
                trains[j] = trains[j+1];
            }
            break;
        }
    }
}
void Station::Print(std::ostream &os) const{
    os<<"Name of the station: "<<nameOfStation<<endl;
    os<<"Priority of the station: "<<priority<<endl;
    os<<"Coordinates: "<<"("<<x<<", "<<y<<")"<<endl;
    os<<"Number of the trains: "<<currentTrain<<endl;
    if(currentTrain > 0){
        cout<<"     Trains in the station: "<<endl;
        for(int i=0;i<currentTrain; ++i){
            cout<<*(trains[i]);
        }
    }
}
void Station::Read(std::istream &is){
    if(nameOfStation != nullptr){
        return;
    }
    is.ignore();
    cout<<"Name of the station: ";
    char buffer[1024];
    is.getline(buffer,1024);
    nameOfStation = new char[strlen(buffer) + 1];
    strcpy(nameOfStation,buffer);
    cout<<"Priority of the station: ";
    is>>priority;
    is.ignore();
    cout<<"Coordinates: ";
    is>>x>>y;
    is.ignore();
}
void Station::setPriority(int priority){
    if(priority >= 1 && priority <=10){
        this->priority = priority;
    }
    else{
        cout<<"Invalid priority, it must be 1-10!"<<endl;
    }
}
int Station::getPriority()const{
    return priority;
}
char* Station::getNameOfStation()const{
    return this->nameOfStation;
}
double Station::getX() const{
    return x;
}
double Station::getY() const{
    return y;
}

