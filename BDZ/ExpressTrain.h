#ifndef EXPRESS_H
#define EXPRESS_H
#include "QuickTrain.h"
#include "DirectTrain.h"

class Express: virtual public QuickTrain, virtual public DirectTrain{
public:
    Express();
    Express(int numberOfWagons, const int* capacityOfWagons, int speed, double fasterBy, int trainPriority);
    virtual Train* clone() const;

    friend std::ostream& operator<<(std::ostream& os, const Express& g);
    friend std::istream& operator>>(std::istream& is, Express& q);

    void Print(std::ostream& os) const;
    void Read(std::istream& is);
};
#endif // EXPRESS_H
