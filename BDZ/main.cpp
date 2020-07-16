#include <iostream>
#include "Train.h"
#include "Station.h"
#include "QuickTrain.h"
#include "DirectTrain.h"
#include "Express.h"
#include "RailwayLine.h"
#include "RailwaySchedule.h"
#include <ctime>
using namespace std;

int main()
{
    int arr[4] = {1,2,3,4};
    cout<<"----------EXAMPLE 1----------"<<endl;
    Train A(2,arr, 100);
    cout<<A;
    QuickTrain B(2,arr, 110,2.5);
    cout<<B;
    DirectTrain C(2,arr, 120,1);
    cout<<C;
    Express D(2, arr, 130, 2.5, 6);
    cout<<D;
    cout<<"----------EXAMPLE 2----------"<<endl;
    Station Plovdiv("Plovdiv", 5, 1,2);
    Plovdiv.addTrain(A);
    Plovdiv.addTrain(B);
    Plovdiv.addTrain(C);
    Plovdiv.addTrain(D);
    cout<<Plovdiv;
    cout<<"----------EXAMPLE 3----------"<<endl;
    Station A1("A1", 1, 3,9);
    Station A2("A2", 2, 4,2);
    Station A3("A3", 3, 6,0);
    Station A4("A4", 6, 3,12);
    A.addStation(A1);
    A.addStation(A3);
    B.addStation(A2);
    B.addStation(A4);
    C.addStation(A3);
    C.addStation(A1);
    D.addStation(A4);
    D.addStation(A2);
    cout<<A;
    cout<<B;
    cout<<C;
    cout<<D;
    cout<<"----------EXAMPLE 4----------"<<endl;
    Station A11("A", 1, 10,72);
    Station B11("B", 2, 1,20);
    Station C11("C", 3, 11,23);

    RailwaySchedule T;
    QuickTrain testTrain(2, arr, 100, 2.5);
    testTrain.addStation(A11);
    testTrain.addStation(B11);
    testTrain.addStation(C11);
    T.addLine(testTrain,2.5);
    T.PrintSchedule();

    cout<<"----------EXAMPLE 5----------"<<endl;
    T.showLinesAfter(2.0);
    cout<<"----------EXAMPLE 6----------"<<endl;

    system("cls");
    RailwaySchedule Schedule;
    int cm = -1;
    cout<<"----------Menu:----------"<<endl;
        cout<<"Please choose between: " <<endl;
        cout<<"(1) Add Train"<<endl;
        cout<<"(2) Remove Train"<<endl;
        cout<<"(3) Print list of trains"<<endl;
        cout<<endl;
        cout<<"(4) Add Station"<<endl;
        cout<<"(5) Remove Station"<<endl;
        cout<<"(6) Print list of stations"<<endl;
        cout<<endl;
        cout<<"(7) Print schedule"<<endl;
        cout<<"(8) Print schedule by departing time"<<endl;
        cout<<endl;
        cout<<"(9) Simulate move"<<endl;
        cout<<endl<<"(0)Exit"<<endl;

    while(cm != 0){
        cout<<endl<<"Your choose: ";
        cin>>cm;
        switch(cm){
        case 1:
            Schedule.createTrain();
            break;
        case 2:
            Schedule.removeTrain();
            break;
        case 3:
            Schedule.printListOfTrains();
            break;
        case 4:
            Schedule.createStation();
            break;
        case 5:
            Schedule.removeStation();
            break;
        case 6:
            Schedule.printListOfStations();
            break;
        case 7:
            Schedule.PrintSchedule();
            break;
        case 8:
            Schedule.PrintScheduleAfter();
        case 9:
            Schedule.simulateMove();
        case 0:
            break;
        }
    };
    return 0;
}
