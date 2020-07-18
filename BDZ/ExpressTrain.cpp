#include "ExpressTrain.h"
#include<iostream>

ExpressTrain::ExpressTrain():Train(), QuickTrain(), DirectTrain(){}

ExpressTrain::ExpressTrain(int numberOfWagons, const int* capacityOfWagons, int trainSpeed, double fasterBy, int trainPriority):
                     Train(numberOfWagons, capacityOfWagons, trainSpeed),
                QuickTrain(numberOfWagons, capacityOfWagons, trainSpeed, fasterBy),
               DirectTrain(numberOfWagons, capacityOfWagons, trainSpeed, trainPriority){}

Train *ExpressTrain::clone() const 
{
    return new ExpressTrain(*this);
}

std::ostream &operator<<(std::ostream &os, const ExpressTrain &d) 
{
    d.printTrainInformation(os);
    return os;
}

std::istream &operator>>(std::istream &is, ExpressTrain &e)
{
    e.readTrainInformation(is);
    return is;
}

void ExpressTrain::printTrainInformation(std::ostream &os) const
{
    Train::printTrainInformation(os);
    os<<"Faster by: "<<getFasterBy()<<std::endl;
    os<<"Priority: "<<getTrainPriority()<<std::endl;
}

void ExpressTrain::readTrainInformation(std::istream &is)
{
   Train::readTrainInformation(is);
   std::cout<<"Faster by: ";
   is>>fasterBy;
   is.ignore();
  
   std::cout<<"Train priority: ";
   is>>trainPriority;
   is.ignore();
}
