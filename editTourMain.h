#ifndef EDITTOURMAIN_H
#define EDITTOURMAIN_H
#include "outputs.h"
#include "string"
#include <fstream>
#include <vector>
#include "person.h"

using namespace std;


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
    player.setUSCFID(USCFID);
    txtFile << USCFID;

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

void getCurrentPlayers(string tourName, vector<Person> &people) {
    ifstream inFile(tourName + "players.txt");
    string fileInput;

    while (!inFile.eof()) {
        Person player;
        getline(inFile, fileInput);
        player.setName(fileInput);

        getline(inFile,fileInput);
        player.setRating(stoi(fileInput));

        getline(inFile, fileInput);
        player.setScore(stoi(fileInput));

        getline(inFile, fileInput);
        player.setUSCFID(fileInput);

        people.push_back(player);

    }
    inFile.close();
    // Insert a sorting algorithm right here for scores first and then by ratings
}

void viewLeaderboard(vector<Person> &people) {


    for (int i = 0; i < people.size(); i++) {
        cout << people.at(i).getName() << endl;
        cout << people.at(i).getRating() << endl;
        cout << people.at(i).getScore() << endl;
        cout << people.at(i).getUSCFID() << endl;


    }
}


void readPlayers(string name, vector<Person> &people){
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

        while ((1 > userInput) || (userInput >5)) {
            editTourWindow();
            cin >> userInput;
            if ((1 > userInput) || (userInput >5)) {
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
        else if (userInput == 4) {

        }
        else if (userInput ==5) {
            break;
        }

    }


}


#endif // EDITTOURMAIN_H
