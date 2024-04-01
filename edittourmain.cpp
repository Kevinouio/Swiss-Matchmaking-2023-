#include "edittourmain.h"
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
    player.setUSCFID(USCFID);
    txtFile << USCFID;

    player.setScore(score);
    txtFile << score;

    people.push_back(player);

}



void readPlayers(){

}





void editTourMain()
