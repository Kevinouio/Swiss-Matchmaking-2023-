#ifndef NEWTOURMAIN_H
#define NEWTOURMAIN_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



void newTourMain(){
    //inializes varibles
    string userChoice;
    string tourName;
    string organizer;
    int baseTime;
    int increment;
    string timeControl;
    string location;
    int rounds;
    string date;
    string csvLine;

    //gets the name of the tournmanet
    cout << "What's the name of the tournment? \nEnter:  ";
    cin >> tourName;
    cin.ignore();

    //Gets the organizer of the tournanment
    cout << "Organizer of the tournment? \nEnter:    ";
    getline(cin,organizer);

    //Gets the base time
    cout <<"Time control? Base time:    ";
    cin >> baseTime;

    //Gets the time incremnet of the tournmanet
    cout << "Increment:    ";
    cin >> increment;
    cin.ignore();

    //Gets the location of the tournament
    cout << "Location:    ";
    getline(cin,location);

    //Gets the amount of rounds in the tournament
    cout << "Rounds:    ";
    cin >> rounds;
    cin.ignore();

    //Gets the date of the tournament
    cout << "Date:    ";
    getline(cin,date);

    //Creates the time control string
    timeControl = to_string(baseTime) + "+" + to_string(increment);


    ofstream csvFile(tourName + ".csv");
    csvLine = "Tournament,Organizer,Location,Date,Time Control,Rounds";
    csvFile << csvLine << endl;
    csvLine = tourName + "," + organizer + "," + location + "," + date + "," + timeControl + "," + to_string(rounds);
    csvFile << csvLine << endl << endl;
    csvFile.close();

    ofstream cvsLeaderboard(tourName + "Leaderboard.csv");
    csvLine = "Placement,Name,Rating,Score,";
    for(int i = 0; i < rounds; i++) {
        if(i == rounds - 1) {
            csvLine += "Round " + to_string(i);
        }
        csvLine += "Round " + to_string(i) + ",";
    }
    cvsLeaderboard << csvLine << endl;

    ofstream txtPeopleFile(tourName +"Players.txt");
    txtPeopleFile.close();


}


#endif // NEWTOURMAIN_H

