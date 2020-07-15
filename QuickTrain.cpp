#include "QuickTrain.h"
#include "Train.h"
#include<iostream>
using namespace std;
void QuickTrain::setFasterBy(double x){
    if(x >= 1 && x <=3){
        fasterBy = getSpeed() * x;
    }
    else
    {
        cout<<"1-3"<<endl;
    }
}
double QuickTrain::getFasterBy()const{
    return fasterBy;
}
QuickTrain::QuickTrain():Train(), fasterBy(0){}
QuickTrain::QuickTrain(int numberOfWagons, const int* capacityOfWagons, int speed, double fasterBy):
    Train(numberOfWagons, capacityOfWagons, speed * fasterBy), fasterBy(fasterBy){}

void QuickTrain::Print(std::ostream &os) const{
    Train::Print(os);
    os<<"Faster by: "<<fasterBy<<endl;
}
void QuickTrain::Read(std::istream &is){
    Train::Read(is);
    cout<<"Faster by: ";
    is>>fasterBy;
    is.ignore();
}
std::ostream &operator<<(std::ostream &os, const QuickTrain &d) {
    d.Print(os);
    return os;
}
std::istream &operator>>(std::istream &is, QuickTrain &d) {
    d.Read(is);
    return is;
}
Train *QuickTrain::clone() const {
    return new QuickTrain(*this);
}
