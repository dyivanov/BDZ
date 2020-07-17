#ifndef QUICKTRAIN_H
#define QUICKTRAIN_H
#include "Train.h"
#include "Station.h"

class QuickTrain: public virtual Train
{
protected:
    double fasterBy;
    
public:
    QuickTrain();
    QuickTrain(int numberOfWagons, const int* capacityOfWagons, int speed, double fasterBy);
    friend std::ostream& operator<<(std::ostream& os, const QuickTrain& q);
    friend std::istream& operator>>(std::istream& is, QuickTrain& q);
    virtual Train* clone() const;

    void setFasterBy(double x);
    double getFasterBy()const;
    void printTrainInformation(std::ostream& os) const;
    void readTrainInformation(std::istream& is);
};
#endif // QUICKTRAIN_H

