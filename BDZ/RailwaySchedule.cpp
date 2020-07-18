#include "RailwaySchedule.h"
#include<iostream>
#include<cstring>
#include<cmath>
#define QuickTrainType 1 
#define DirectTrainType 2 
#define ExpressTrainType 3 



void RailwaySchedule::Copy(const RailwaySchedule& other){
    //SCHEDULE
    currentLine = other.currentLine;
    numberOfLines = other.numberOfLines;
    schedules = new Railwayline[numberOfLines];
    for(int i = 0; i < currentLine; ++i)
    {
        schedules[i] = other.schedules[i];
    }
    
    //TRIANS
    currentTrain = other.currentTrain;
    numberOfTrains = other.numberOfTrains;
    listOfTrains = new Train*[numberOfTrains];
    for(int i = 0; i < currentTrain; ++i)
    {
        listOfTrains[i] = other.listOfTrains[i]->clone();
    }
    
    //STATIONS
    currentStation = other.currentStation;
    numberOfStations = other.numberOfStations;
    listOfStations = new Station[numberOfStations];
    for(int i = 0; i < currentStation; ++i)
    {
        listOfStations[i] = other.listOfStations[i];
    }
}

void RailwaySchedule::Erase()
{
    delete[] schedules;
    delete[] listOfStations;
    for(int i = 0; i < currentTrain; ++i)
    {
        delete listOfTrains[i];
    }
    delete[] listOfTrains;
}

void RailwaySchedule::resizeL()
{
    Railwayline* temp = schedules;
    numberOfLines *= 2;
    schedules = new Railwayline[numberOfLines];
    for(int i=0; i<currentLine; ++i)
    {
        schedules[i] = temp[i];
    }
    delete[] temp;
}

void RailwaySchedule::resizeT()
{
    Train** temp = listOfTrains;
    numberOfTrains *= 2;
    listOfTrains = new Train*[numberOfTrains];
    for(int i=0; i<currentTrain; ++i)
    {
        listOfTrains[i] = temp[i]->clone();
    }
    delete[] temp;
}

void RailwaySchedule::resizeS()
{
    Station* temp = listOfStations;
    numberOfStations *= 2;
    listOfStations = new Station[numberOfStations];
    for(int i=0; i<currentStation; ++i)
    {
        listOfStations[i] = temp[i];
    }
    delete[] temp;
}

void RailwaySchedule::sortSchedule()
{
    for(int i = 0; i < currentLine - 1; ++i)
    {
        for(int j = i + 1; j < currentLine; ++j)
        {
            if(schedules[i].getDepartTime() > schedules[j].getDepartTime())
            {
                Railwayline temp = schedules[i];
                schedules[i] = schedules[j];
                schedules[j] = temp;
            }
        }
    }
}

RailwaySchedule::RailwaySchedule(): numberOfLines(1), currentLine(0),numberOfTrains(1), currentTrain(0), numberOfStations(1), currentStation(0), schedules(nullptr),listOfStations(nullptr), listOfTrains(nullptr)
{
    schedules = new Railwayline[numberOfLines];
    listOfTrains = new Train*[numberOfTrains];
    listOfStations = new Station[numberOfStations];
}

RailwaySchedule::RailwaySchedule(const RailwaySchedule& other)
{
    Copy(other);
}

RailwaySchedule& RailwaySchedule::operator=(const RailwaySchedule& other)
{
    if(this != & other)
    {
        Erase();
        Copy(other);
    }
    return *this;
}

RailwaySchedule::~RailwaySchedule()
{
    Erase();
}

void RailwaySchedule::addLine(const Train& r, double departTime)
{
    const Station* listOfStation = r.getStations();
    for(int i = 0; i < r.getCurrentStation() - 1; ++i)
    {
        for(int j = i + 1; j < r.getCurrentStation(); ++j)
        {
            double pointA = listOfStation[i].getX() - listOfStation[i].getY();
            double pointB = listOfStation[j].getX() - listOfStation[j].getY();
            double trainSpeed = r.getSpeed();
            double arriveTime = calculateArriveTime(pointA, pointB, trainSpeed);
            arriveTime += departTime;
            Railwayline line(listOfStation[i].getNameOfStation(), listOfStation[j].getNameOfStation(),departTime, arriveTime);
            line.setTrainPointer(r);
            if(currentLine == numberOfLines)
            {
                resizeL();
            }
            schedules[currentLine] = line;
            ++currentLine;
        }
    }
    sortSchedule();
}

void RailwaySchedule::createTrain()
{
    int type = - 1;
    std::cout<<"Types of trains:"<<std::endl;
    std::cout<<"    (1) Quick train"<<std::endl;
    std::cout<<"    (2) Direct train"<<std::endl;
    std::cout<<"    (3) Express train"<<std::endl;
    std::cout<<"Please choose type of train: ";
    while( (type < QuickTrainType) || (type > ExpressTrainType) )
    {
        cin>>type;
        if(type == QuickTrainType)
        {
            std::cout<<"    Quick train:"<<std::endl;
            QuickTrain T;
            cin>>T;
            if(currentTrain == numberOfTrains)
            {
                resizeT();
            }
            listOfTrains[currentTrain] = T.clone();
            ++currentTrain;
            std::cout<<"The train was added!"<<std::endl;
        }
        else if(type == DirectTrainType)
        {
            std::cout<<"    Direct train:"<<std::endl;
            DirectTrain T;
            cin>>T;
            if(currentTrain == numberOfTrains)
            {
                resizeT();
            }
            listOfTrains[currentTrain] = T.clone();
            ++currentTrain;
            std::cout<<"The train was added!"<<std::endl;
        }
        else if(type == ExpressTrainType)
        {
            cout<<"    Express train:"<<endl;
            Express T;
            cin>>T;
            if(currentTrain == numberOfTrains){
                resizeT();
            }
            listOfTrains[currentTrain] = T.clone();
            ++currentTrain;
            std::cout<<"The train was added!"<<std::endl;
        }
        else
        {
            std::cout<<"Incorrect choose, please try again: " ;
        }
    }

    /*----------------------------------------------*/
    std::cout<<"Please choose departing time of the train: ";
    double dTime = -1;
    while(dTime < 0.0)
    {
        cin>>dTime;
        if(dTime < 0)
        {
            std::cout<<"Incorrect choose, please try again: ";
        }
    }
    
    /*----------------------------------------------*/
    std::cout<<std::endl<<"New options:"<<std::endl;
    std::cout<<"    (0) Exit"<<std::endl;
    std::cout<<"    (1) Add stop"<<std::endl;
    int cm = -1;
    std::cout<<"Your choose: ";
    while(cm != 0 && cm != 1)
    {
        cin>>cm;
        if(cm != 1 && cm != 0)
        {
            std::cout<<"Incorrect choose, please try again: ";
        }
    }
    /*----------------------------------------------*/
    if(cm == 0)
    {
        return;
    }
    if(currentStation != 0 && cm == 1)
    {
        std::cout<<"List of all stations(stops): "<<std::endl;
        for(int i = 0; i <  currentStation; ++i)
        {
            std::cout<<"    ["<<i + 1<<"]: "<<listOfStations[i].getNameOfStation()<<std::endl;
        }
        std::cout<<"For exit enter 0"<<std::endl;
        std::cout<<"Please choose which stop to add: ";

        int index = -1;
        while(index != 0)
        {
            cin>>index;
            if(index- 1 >= 0 && index -1 < currentStation)
            {
                listOfTrains[currentTrain - 1]->addStation(listOfStations[index - 1]);
                this->addLine(*(listOfTrains[currentTrain - 1]), dTime);
                std::cout<<"The stop was added!"<<std::endl;
            }
            else if(index != 0 && index != 1)
            {
                std::cout<<"Incorrect choose, please try again: ";
            }
        }
    }
    else
    {
        std::cout<<"There is not available stops!"<<std::endl;
    }
}
void RailwaySchedule::removeTrain()
{
    if(currentTrain == 0)
    {
        std::cout<<"Empty"<<std::endl;
        return;
    }
    std::cout<<"List of all trains:"<<std::endl;
    for(int i = 0; i <  currentTrain; ++i)
    {
    std::cout<<"    ["<<i + 1<<"]:"<<std::endl;
    std::cout<<*(listOfTrains[i]);
    }
    std::cout<<"Please choose witch train to remove: ";
    int index = -1;
    while(!(index- 1 >= 0 && index -1 < currentTrain))
    {
        cin>>index;
        if(index- 1 >= 0 && index -1 < currentTrain)
        {
            for(int i = 0; i < currentTrain; ++i)
            {
                if(i == index - 1)
                {
                    for(int j = i; j < currentTrain-1; ++j)
                    {
                        listOfTrains[j] = listOfTrains[j+1];
                    }
                --currentTrain;
                std::cout<<"The train was removed!"<<std::endl;
                return;
                }
            }
        }
        else
        {
            std::cout<<"Incorrect choose, please try again: ";
        }
    }
}
void RailwaySchedule::createStation()
{
    cout<<"    Station:"<<std::endl;
    Station S;
    cin>>S;
    if(currentStation == numberOfStations)
    {
        resizeS();
    }
    listOfStations[currentStation] = S;
    ++currentStation;
    std::cout<<"The station was added!"<<std::endl;
}
void RailwaySchedule::removeStation()
{
    if(currentStation == 0)
    {
        std::cout<<"Empty"<<std::endl;
        return;
    }
    
    std::cout<<"List of all stations:"<<std::endl;
    for(int i = 0; i <  currentStation; ++i)
    {
    std::cout<<"    ["<<i + 1<<"]: "<<listOfStations->getNameOfStation()<<std::endl;
    }
    std::cout<<"Please choose witch Station to remove: ";
    int index = -1;
    while(!(index- 1 >= 0 && index -1 < currentStation))
    {
        cin>>index;
        if(index- 1 >= 0 && index -1 < currentStation){
            for(int i = 0; i < currentStation; ++i){
                if(i == index - 1){
                    for(int j = i; j < currentStation-1; ++j){
                        listOfStations[j] = listOfStations[j+1];
                    }
                --currentStation;
                cout<<"Station was removed!"<<endl;
                return;
                }
            }
        }
        else{
            cout<<"Incorrect choose, please try again: ";
        }
    }
}
void RailwaySchedule::removeLine(Railwayline& r){
    for(int i = 0; i < currentLine; ++i){
        if(r == schedules[i]){
            schedules[i] = schedules[currentLine - 1];
            --currentLine;
        }
    }
}
void RailwaySchedule::PrintSchedule()const{
    if(currentLine == 0){
        cout<<"There is not available lines!"<<endl;
        return;
    }
    for(int i = 0; i < currentLine; ++i){
        cout<<i + 1<<": ";
        schedules[i].printLine();
    }
}
void RailwaySchedule::PrintScheduleAfter()const{
     if(currentLine == 0){
        cout<<"There is not available lines!"<<endl;
        return;
    }
    else{
        cout<<"Please enter time for departing: ";
        double time = -1;
        while(time < 0){
            cin>>time;
            if(time < 0){
                cout<<"Incorrect time, try again: ";
            }
        }
        int count = 0;
        for(int i = 0; i < currentLine; ++i){
            if(schedules[i].getDepartTime() >= time){
                cout<<count + 1<<": ";
                schedules[i].printLine();
                ++count;
            }
        }
    }
}

void RailwaySchedule::printListOfStations() const
{
    if(currentStation == 0)
    {
        std::cout<<"There is not available stations!"<<std::endl;
        return;
    }
    for(int i = 0; i < currentStation; ++i)
    {
        std::cout<<i + 1<<": "<<listOfStations[i]<<std::endl;
    }
}

void RailwaySchedule::printListOfTrains() const
{
    if(currentTrain == 0)
    {
        std::cout<<"There is not available trains!"<<std::endl;
        return;
    }
    for(int i = 0; i < currentTrain; ++i)
    {
        std::cout<<i + 1<<": "<<std::endl;
        std::cout<<"    ["<<i+1<<"]"<<*(listOfTrains[i]);
    }
}

void RailwaySchedule::showLinesAfter(double time) const
{
    for(int i = 0; i < currentLine; ++i)
    {
        if(schedules[i].getArriveTime() > time)
        {
            schedules[i].printLine();
        }
    }
}

void RailwaySchedule::simulateMove()
{
    cout<<"Please choose current time: ";
    int time = -1;
    while (time < 0)
    {
        cin>>time;
        if(time < 0)
        {
            std::cout<<"Incorrect time, please try again!"<<std::endl;
            std::cout<<"Your choose: ";
        }
    }
    int n = currentLine;
    for(int i = 0; i < n; ++i)
    {
        if(time >= this->schedules[i].getArriveTime())
        {
            this->findStationByName(schedules[i].getCurrentStop())->removeTrain(*schedules[i].getTrainPointer());
            this->findStationByName(schedules[i].getLastStop())->addTrain(*schedules[i].getTrainPointer());
            schedules[i].getTrainPointer()->removeStation(*(findStationByName(schedules[i].getCurrentStop())));
            this->removeLine(schedules[i]);
        }
    }
}

double RailwaySchedule::calculateArriveTime(double pointA, double pointB, int trainSpeed)
{
    return sqrt(pow(pointA, 2) + pow(pointB, 2)) / (double)trainSpeed;
}

Station* RailwaySchedule::findStationByName(const char* nameOfStation)
{
    for(int i = 0; i < currentStation ; ++i)
    {
        if(strcmp(listOfStations[i].getNameOfStation(), nameOfStation) == 0)
        {
            return &(listOfStations[i]);
        }
    }
    return nullptr;
}
