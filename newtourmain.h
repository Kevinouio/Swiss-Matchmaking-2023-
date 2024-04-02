#ifndef NEWTOURMAIN_H
#define NEWTOURMAIN_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



void newTourMain(){
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


    cout << "What's the name of the tournment? \nEnter:  ";
    cin >> tourName;
    cin.ignore();

    cout << "Organizer of the tournment? \nEnter:    ";
    getline(cin,organizer);

    cout <<"Time control? Base time:    ";
    cin >> baseTime;

    cout << "Increment:    ";
    cin >> increment;

    cin.ignore();
    cout << "Location:    ";
    getline(cin,location);

    cout << "Rounds:    ";
    cin >> rounds;
    cin.ignore();

    cout << "Date:    ";
    getline(cin,date);

    timeControl = to_string(baseTime) + "+" + to_string(increment);
    ofstream csvFile(tourName + ".csv");

    csvLine = "Tournament,Organizer,Location,Date,Time Control,Rounds";
    csvFile << csvLine << endl;
    csvLine = tourName + "," + organizer + "," + location + "," + date + "," + timeControl + "," + to_string(rounds);
    csvFile << csvLine << endl << endl;

    csvLine = "Name,Rating,USCFID,Score,";
    for(int i = 0; i < rounds; i++) {
        if(i == rounds - 1) {
            csvLine += "Round " + to_string(i);
        }
        csvLine += "Round " + to_string(i) + ",";
    }
    csvFile.close();

    ofstream txtPeopleFile(tourName +"players.txt");
    txtPeopleFile.close();


}


#endif // NEWTOURMAIN_H

