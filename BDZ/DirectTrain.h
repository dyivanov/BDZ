#ifndef DIRECTTRAIN_H
#define DIRECTTRAIN_H
#include "Train.h"
#include "Station.h"
class DirectTrain: public virtual Train{
protected:
    int trainPriority;
public:
    DirectTrain();
    DirectTrain(int numberOfWagons, const int* capacityOfWagons, int speed, int trainPriority);
    virtual Train* clone() const;

    void Print(std::ostream& os) const;
    void Read(std::istream& is);

    int getTrainPriority()const;
    void addStation(const Station& s);

    friend std::ostream& operator<<(std::ostream& os, const DirectTrain& q);
    friend std::istream& operator>>(std::istream& is, DirectTrain& q);
};
#endif // DIRECTTRAIN_H
