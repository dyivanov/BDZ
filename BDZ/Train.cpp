#include<iostream>
#include "Train.h"

void Train::Copy(const Train& t)
{
    this->numberOfWagons = t.numberOfWagons;
    this->setCapacityOfWagons(t.numberOfWagons, t.capacityOfWagons);
    this->trainSpeed = t.trainSpeed;
    this->numberOfTrainStation = t.numberOfTrainStation;
    this->currentTrainStation = t.currentTrainStation;
    trainStation = new Station[numberOfTrainStation];
    
    for(int i=0; i < currentTrainStation; ++i)
    {
        trainStation[i] = t.trainStation[i];
    }
}

void Train::Erase()
{
    delete[] capacityOfWagons;
    delete[] trainStation;
}

void Train::Resize()
{
    Station* temp = trainStation;
    numberOfTrainStation *= 2;
    
    trainStation = new Station[numberOfTrainStation];
    for(int i=0; i<currentTrainStation; ++i){
        trainStation[i] = temp[i];
    }
    
    delete[] temp;
}

Train::Train():numberOfWagons(0), capacityOfWagons(nullptr), trainSpeed(0), currentTrainStation(0), numberOfTrainStation(1), trainStation(nullptr){}

Train::Train(int numberOfWagons,const int* capacityOfWagons, int trainSpeed)
{
    this->numberOfWagons = numberOfWagons;
    this->setCapacityOfWagons(numberOfWagons, capacityOfWagons);
    this->trainSpeed = trainSpeed;
    numberOfTrainStation = 1;
    currentTrainStation = 0;
    trainStation = new Station[numberOfTrainStation];
}

Train::Train(const Train& t)
{
    Copy(t);
}

Train &Train::operator=(const Train& t)
{
    if(this != &t)
    {
        Erase();
        Copy(t);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Train &t) 
{
    t.printTrainInformation(os);
    return os;
}

std::istream &operator>>(std::istream &is, Train &t) 
{
    t.readTrainInformation(is);
    return is;
}

Train *Train::clone() const
{
    return new Train(*this);
}

Train::~Train()
{
    Erase();
}

void Train::printTrainInformation(std::ostream &os)const
{
    os<<"Number of wagons: "<<numberOfWagons<<std::endl;
    
    os<<"Capacity of each wagon is: ";
    for(int i = 0; i < numberOfWagons - 1; ++i)
    {
        os<<capacityOfWagons[i]<<", ";
    }
    os<<capacityOfWagons[numberOfWagons - 1]<< std::endl;
    
    os<<"Current speed of the train: "<<speed<<std::endl;
    
    if(currentTrainStation > 0)
    {
       std::cout<<"Stops of the train: \n";
        for(int i = 0; i < currentStation; ++i)
        {
            std::cout<<i + 1<<": "<<trainStation[i].getNameOfStation()<<std::endl;
        }
    }
}

void Train::readTrainInformation(std::istream &is)
{
    std::cout<<"Please enter number of wagons: ";
    is>>numberOfWagons;
    is.ignore();
    
    std::cout<<"   Please enter capacity of each wagon: \n";
    capacityOfWagons = new int[numberOfWagons];
    for(int i=0; i < numberOfWagons; ++i)
    {
        std::cout<<i+1<<": ";
        is>>capacityOfWagons[i];
        is.ignore();
    }
    
    std::cout<<"Please enter the speed of the train: ";
    is>>trainStation;
    is.ignore();
}

void Train::addTrainStation(const Station& s)
{
    if(currentTrainStation == numberOfTrainStation)
    {
        Resize();
    }
    trainStation[currentTrainStation] = s;
    ++currentTrainStation;
}

void Train::removeTrainStation(const Station& s)
{
    for(int i = 0; i < currentTrainStation; ++i)
    {
        if(trainStation[i] == s)
        {
            for(int j = i; j < currentTrainStation-1; ++j)
            {
                trainStation[j] = trainStation[j+1];
            }
            break;
        }
    }
}

void Train::setCapacityOfWagons(int numberOfWagons, const int* capacityOfWagons)
{
        this->capacityOfWagons = new int[numberOfWagons];
        for(int i = 0; i < numberOfWagons; i++){
            this->capacityOfWagons[i] = capacityOfWagons[i];
        }
}

int Train::getTrainSpeed()const
{
    return trainSpeed;
}

int Train::getCurrentTrainStation()const
{
    return currentTrainStation;
}

const Station* Train::getListOfTrainStations()const
{
    return this->trainStation;
}
