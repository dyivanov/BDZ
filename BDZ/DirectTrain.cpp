#include "DirectTrain.h"
#include<iostream>

DirectTrain::DirectTrain():Train(), trainPriority(1){}

DirectTrain::DirectTrain(int numberOfWagons, const int* capacityOfWagons, int trainSpeed, int trainPriority):
                   Train(numberOfWagons, capacityOfWagons, trainSpeed), trainPriority(trainPriority){}

std::ostream &operator<<(std::ostream &os, const DirectTrain &d) 
{
    d.printTrainInformation(os);
    return os;
}

std::istream &operator>>(std::istream &is, DirectTrain &d) 
{
    d.readTrainInformation(is);
    return is;
}

Train *DirectTrain::clone() const 
{
    return new DirectTrain(*this);
}

void DirectTrain::printTrainInformation(std::ostream &os) const
{
    Train::printTrainInformation(os);
    os<<"Direct train priority: "<<trainPriority<<std::endl;
}

void DirectTrain::readTrainInformation(std::istream &is)
{
    Train::readTrainInformation(is);
    std::cout<<"Direct train priority: ";
    is>>trainPriority;
    is.ignore();
}

int DirectTrain::getTrainPriority() const
{
    return trainPriority;
}

void DirectTrain::addTrainStation(const Station& s)
{
    if(trainPriority <= s.getTrainPriority())
    {
        Train::addTrainStation(s);
    }
    else
    {
        std::cout<<"This train stop is with low priority! \n";
    }
}
