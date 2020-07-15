#ifndef QUICKTRAIN_H
#define QUICKTRAIN_H
#include "Train.h"
#include "Station.h"
class QuickTrain: public virtual Train{
protected:
    double fasterBy;
public:
    QuickTrain();
    QuickTrain(int numberOfWagons, const int* capacityOfWagons, int speed, double fasterBy);
    virtual Train* clone() const;

    void setFasterBy(double x);
    double getFasterBy()const;
    void Print(std::ostream& os) const;
    void Read(std::istream& is);
    friend std::ostream& operator<<(std::ostream& os, const QuickTrain& q);
    friend std::istream& operator>>(std::istream& is, QuickTrain& q);
};
#endif // QUICKTRAIN_H

