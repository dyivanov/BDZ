#include "DirectTrain.h"
#include<iostream>
using namespace std;
DirectTrain::DirectTrain():Train(), trainPriority(1){}
DirectTrain::DirectTrain(int numberOfWagons, const int* capacityOfWagons, int speed, int trainPriority):
    Train(numberOfWagons, capacityOfWagons,speed), trainPriority(trainPriority){}


void DirectTrain::addStation(const Station& s){
    if(trainPriority <= s.getPriority()){
        Train::addStation(s);
    }
    else
    {
        cout<<"This stop is with low priority!"<<endl;
    }
}
void DirectTrain::Print(std::ostream &os) const{
    Train::Print(os);
    os<<"Priority: "<<trainPriority<<endl;
}
void DirectTrain::Read(std::istream &is){
    Train::Read(is);
    cout<<"Train priority: ";
    is>>trainPriority;
    is.ignore();
}
std::ostream &operator<<(std::ostream &os, const DirectTrain &d) {
    d.Print(os);
    return os;
}
std::istream &operator>>(std::istream &is, DirectTrain &d) {
    d.Read(is);
    return is;
}

int DirectTrain::getTrainPriority()const{
    return trainPriority;
}
Train *DirectTrain::clone() const {
    return new DirectTrain(*this);
}
