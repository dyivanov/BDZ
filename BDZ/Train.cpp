#include<iostream>
using namespace std;
#include "Train.h"

void Train::Copy(const Train& t){
    this->numberOfWagons = t.numberOfWagons;
    this->setCapacityOfWagons(t.numberOfWagons, t.capacityOfWagons);
    this->speed = t.speed;
    this->numberOfStations = t.numberOfStations;
    this->currentStation = t.currentStation;
    stations = new Station[numberOfStations];
    for(int i=0; i < currentStation; ++i){
        stations[i] = t.stations[i];
    }
}
void Train::Erase(){
    delete[] capacityOfWagons;
    delete[] stations;
}
void Train::Resize(){
    Station* temp = stations;
    numberOfStations *= 2;
    stations = new Station[numberOfStations];
    for(int i=0; i<currentStation; ++i){
        stations[i]=temp[i];
    }
    delete[] temp;
}
void Train::Print(std::ostream &os)const{
    os<<"Number of wagons: "<<numberOfWagons<<endl;
    os<<"Capacity of each wagon is: ";
    for(int i = 0; i < numberOfWagons - 1; ++i){
        os<<capacityOfWagons[i]<<", ";
    }
    os<<capacityOfWagons[numberOfWagons - 1]<<endl;
    os<<"Speed of the train: "<<speed<<endl;
    if(currentStation > 0){
       cout<<"Stops of the train: "<<endl;
        for(int i = 0; i < currentStation; ++i){
            cout<<i + 1<<": "<<stations[i].getNameOfStation()<<endl;
        }
    }
}
void Train::Read(std::istream &is){
    cout<<"Please enter number of wagons: ";
    is>>numberOfWagons;
    is.ignore();
    cout<<"   Please enter capacity of each wagon: "<<endl;
    capacityOfWagons = new int[numberOfWagons];
    for(int i=0; i < numberOfWagons; ++i){
        cout<<i+1<<": ";
        is>>capacityOfWagons[i];
        is.ignore();
    }
    cout<<"Please enter the speed of train: ";
    is>>speed;
    is.ignore();
}
Train::Train():numberOfWagons(0), capacityOfWagons(nullptr), speed(0), currentStation(0), numberOfStations(1), stations(nullptr){}
Train::Train(int numberOfWagons,const int* capacityOfWagons, int speed){
    this->numberOfWagons = numberOfWagons;
    this->setCapacityOfWagons(numberOfWagons, capacityOfWagons);
    this->speed = speed;
    numberOfStations = 1;
    currentStation = 0;
    stations = new Station[numberOfStations];
}
Train::Train(const Train& t){
    Copy(t);
}
Train &Train::operator=(const Train& t){
    if(this != &t){
        Erase();
        Copy(t);
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Train &t) {
    t.Print(os);
    return os;
}
std::istream &operator>>(std::istream &is, Train &t) {
    t.Read(is);
    return is;
}

Train::~Train(){
    Erase();
}

void Train::addStation(const Station& s){
    if(currentStation == numberOfStations){
        Resize();
    }
    stations[currentStation] = s;
    ++currentStation;
}
void Train::removeStation(const Station& s){
    for(int i = 0; i < currentStation; ++i){
        if(stations[i] == s){
            for(int j = i; j < currentStation-1; ++j){
                stations[j] = stations[j+1];
            }
            break;
        }
    }
}
int Train::getCurrentStation()const{
    return currentStation;
}
int Train::getSpeed()const{
    return speed;
}
void Train::setCapacityOfWagons(int numberOfWagons, const int* capacityOfWagons){
        this->capacityOfWagons = new int[numberOfWagons];
        for(int i = 0; i < numberOfWagons; i++){
            this->capacityOfWagons[i] = capacityOfWagons[i];
        }
}
const Station* Train::getStations()const{
    return this->stations;
}
Train *Train::clone() const {
    return new Train(*this);
}
