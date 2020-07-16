#ifndef EXPRESSTRAIN_H
#define EXPRESSTRAIN_H
#include "QuickTrain.h"
#include "DirectTrain.h"

class ExpressTrain: virtual public QuickTrain, virtual public DirectTrain
{
public:
    ExpressTrain();
    ExpressTrain(int numberOfWagons, const int* capacityOfWagons, int getTrainSpeed, double fasterBy, int trainPriority);
    virtual Train* clone() const;

    friend std::ostream& operator<<(std::ostream& os, const ExpressTrain& g);
    friend std::istream& operator>>(std::istream& is, ExpressTrain& q);

    void printTrainInformation(std::ostream& os) const;
    void readTrainInformation(std::istream& is);
};
#endif // EXPRESSTRAIN_H
