#ifndef DIRECTTRAIN_H
#define DIRECTTRAIN_H
#include "Train.h"
#include "Station.h"

class DirectTrain: public virtual Train
{
protected:
    int trainPriority;
    
public:
    DirectTrain();
    DirectTrain(int numberOfWagons, const int* capacityOfWagons, int trainSpeed, int trainPriority);
    friend std::ostream& operator<<(std::ostream& os, const DirectTrain& q);
    friend std::istream& operator>>(std::istream& is, DirectTrain& q);
    virtual Train* clone() const;

    void printTrainInformation(std::ostream& os) const;
    void readTrainInformation(std::istream& is);

    int getTrainPriority() const;
    void addTrainStation(const Station& s);
};
#endif // DIRECTTRAIN_H
