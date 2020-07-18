#include "QuickTrain.h"
#include "Train.h"
#include<iostream>
#include <cassert>
#define Index_MIN 1
#define Index_MAX 3

QuickTrain::QuickTrain():Train(), fasterBy(0){}

QuickTrain::QuickTrain(int numberOfWagons, const int* capacityOfWagons, int trainSpeed, double fasterBy):
                 Train(numberOfWagons, capacityOfWagons, trainSpeed * fasterBy), fasterBy(fasterBy){}

std::ostream &operator<<(std::ostream &os, const QuickTrain &d) 
{
    d.printTrainInformation(os);
    return os;
}

std::istream &operator>>(std::istream &is, QuickTrain &d) 
{
    d.readTrainInformation(is);
    return is;
}

Train *QuickTrain::clone() const {
    return new QuickTrain(*this);
}

void QuickTrain::printTrainInformation(std::ostream &os) const
{
    Train::printTrainInformation(os);
    os<<"Faster by: "<<fasterBy<<std::endl;
}

void QuickTrain::readTrainInformation(std::istream &is)
{
    Train::readTrainInformation(is);
    std::cout<<"Faster by: ";
    is>>fasterBy;
    is.ignore();
}

void QuickTrain::setFasterBy(double index)
{
    assert((Index_MIN <= index && index <= Index_MAX) && "Sped index should be in [1,3]");
    fasterBy = getTrainSpeed() * index;
}

double QuickTrain::getFasterBy()const
{
    return fasterBy;
}
