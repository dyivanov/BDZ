#include "Express.h"
#include<iostream>
using namespace std;
Express::Express():Train(), QuickTrain(), DirectTrain(){}
Express::Express(int numberOfWagons, const int* capacityOfWagons, int speed, double fasterBy, int trainPriority):
                Train(numberOfWagons, capacityOfWagons, speed),
                QuickTrain(numberOfWagons, capacityOfWagons, speed, fasterBy),
                DirectTrain(numberOfWagons, capacityOfWagons, speed, trainPriority){}

void Express::Print(std::ostream &os)const{
    Train::Print(os);
    os<<"Faster by: "<<getFasterBy()<<endl;
    os<<"Priority: "<<getTrainPriority()<<endl;
}
void Express::Read(std::istream &is){
   Train::Read(is);
   cout<<"Faster by: ";
   is>>fasterBy;
   is.ignore();
   cout<<"Train priority: ";
   is>>trainPriority;
   is.ignore();
}
std::ostream &operator<<(std::ostream &os, const Express &d) {
    d.Print(os);
    return os;
}
std::istream &operator>>(std::istream &is, Express &e) {
    e.Read(is);
    return is;
}
Train *Express::clone() const {
    return new Express(*this);
}

