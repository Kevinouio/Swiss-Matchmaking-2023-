#ifndef NEWTOURMAIN_H
#define NEWTOURMAIN_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#include "outputs.h"
#include "string"
#include <fstream>
#include <vector>
#include "person.h"




void addPlayer(string tourName, vector<Person> &people) {
    Person player;
    int rating;
    string name;
    string USCFID;
    int score = 0;
    ofstream txtFile(tourName + "players.txt");

    cout << "Name of Player?\nEnter:  ";
    getline(cin, name);
    player.setName(name);
    txtFile << name;

    cout <<"Rating of Player?\nEnter:  ";
    cin >> rating;
    player.setRating(rating);
    txtFile << rating;

    cout <<"USCFID of Player?(Type NA if player does not have one)\nEnter:  ";
    getline(cin,USCFID);
    if ("NA" == USCFID) {
        USCFID = "00000000";
    }


    player.setScore(score);
    txtFile << score;

    people.push_back(player);

}



//The logic for this part is genuinly difficult
void createPairings(vector<Person> &people) {
    int size = people.size()/2;
    for (int i = 0; i < size; i++) {
        cout << "Pairing " << i << "\t" << endl;
    }

}

void readPlayers(string name){
    ifstream inFile(name + "players.txt");

    // This is for a display i think ryan you should code this part aswell since it is simply displaying
    // Also put your sort function here or smth



}



void editTourMain() {
    ifstream inFile;
    vector<Person> people;
    string tourName;
    int userInput = -1;




    cin.ignore();
    getline(cin, tourName);

    while (true) {
        cout << "What is the name of the tournmanet? \nEnter:  ";
        cin >> tourName;
        inFile.open(tourName + ".csv");

        if (!inFile.is_open()){
            cout << "Error opening file. Try again" << endl;
        }
        else {
            break;
        }

    }


    /*
       Okay so here Ryan is where you just want to dispay the information about the tournament so i'll leave you with this parth of the code

     */

    inFile.close();




    while(1) {

        while ((1 > userInput) || (userInput >3)) {
            editTourWindow();
            cin >> userInput;
            if ((1 > userInput) || (userInput >3)) {
                errorMessageValue();
            }
        }

        if (userInput ==1) {
            addPlayer(tourName, people);
        }
        else if (userInput ==2) {

        }
        else if (userInput ==3) {
            createPairings(people);
        }
        else if (userInput ==4) {
            break;
        }

    }


}




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

    ofstream csvPeopleFile(tourName +"players.txt");
    csvPeopleFile.close();


}


#endif // NEWTOURMAIN_H

