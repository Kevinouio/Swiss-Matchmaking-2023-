#ifndef EDITTOURMAIN_H
#define EDITTOURMAIN_H
#include "outputs.h"
#include "string"
#include <fstream>
#include <vector>
#include "person.h"
#include "createPairings.h"

using namespace std;

void ratingSort(vector<Person> &unsortedVector, vector<Person> &sortedVector) {
    int highest = unsortedVector[0].getRating();
    int index = 0;
    for (int i = 0; i < unsortedVector.size(); i++) {
        if (unsortedVector[i].getRating() > highest) {
            highest = unsortedVector[i].getRating();
            index = i;
        }
    }
    sortedVector.push_back(unsortedVector[index]);
    unsortedVector.erase(unsortedVector.begin() + index);
}

void scoreSort(vector<Person>& unsortedVector, vector<Person>& sortedVector) {
    int highest = unsortedVector[0].getScore();
    int index = 0;
    for (int i = 0; i < unsortedVector.size(); i++) {
        if (unsortedVector[i].getScore() > highest) {
            highest = unsortedVector[i].getScore();
            index = i;
        }
    }
    sortedVector.push_back(unsortedVector[index]);
    unsortedVector.erase(unsortedVector.begin() + index);
}


void roundOneSort(vector<Person> sortedVector) {
    if (sortedVector.size() % 2 == 1) {
        cout << sortedVector[0].getName() << " : By";
        sortedVector.erase(sortedVector.begin());
    }
    for (int i = 0; i < sortedVector.size() / 2; i++) {
        cout << sortedVector[i].getName() << " : " << sortedVector[sortedVector.size() - 1 - i].getName();
    }
}

void addPlayer(string tourName, vector<Person> &people, int rounds) {
    Person player;
    int rating;
    string name;
    string USCFID;
    int score = 0;
    ofstream txtFile(tourName + "Players.txt");

    cin.ignore();
    cout << "Name of Player?\nEnter:  ";
    getline(cin, name);
    player.setName(name);
    txtFile << name << endl;

    cout <<"Rating of Player?\nEnter:  ";
    cin >> rating;
    player.setRating(rating);
    txtFile << rating << endl;

    cin.ignore();
    cout <<"USCFID of Player?(Type NA if player does not have one)\nEnter:  ";
    getline(cin,USCFID);
    if ("NA" == USCFID) {
        USCFID = "00000000";
    }
    player.setUSCFID(USCFID);
    txtFile << USCFID << endl;

    player.setScore(score);
    txtFile << score << endl;

    player.setMatchHistory(rounds);

    people.push_back(player);

}




void getCurrentPlayers(string tourName, vector<Person> &people, int &rounds) {
    ifstream inFile(tourName + "Players.txt");
    string fileInput;

    while (!inFile.eof()) {
        Person player;
        vector<string> matches;

        getline(inFile, fileInput);
        player.setName(fileInput);

        getline(inFile,fileInput);
        player.setRating(stoi(fileInput));

        getline(inFile, fileInput);
        player.setScore(stoi(fileInput));

        getline(inFile, fileInput);
        player.setUSCFID(fileInput);

        for (int i = 0; i < rounds; i++) {
            getline(inFile, fileInput);
            matches.push_back(fileInput);
        }

        player.setCurHistory(matches);

        people.push_back(player);

    }
    inFile.close();
    // Insert a sorting algorithm right here for scores first and then by ratings
    ratingSort(people, people);
}

void viewLeaderboard(vector<Person> &people, string tourName, int rounds) {
    string csvLine;

    ratingSort(people, people);
    ofstream cvsLeaderboard(tourName + "Leaderboard.csv");
    csvLine = "Placement,Name,Rating,Score,";
    for(int i = 0; i < rounds; i++) {
        if(i == rounds - 1) {
            csvLine += "Round " + to_string(i+1);
            break;
        }
        csvLine += "Round " + to_string(i+1) + ",";
    }
    cvsLeaderboard << csvLine << endl;

    // I don't really know how you want to display this because this is just the leaderboard all of the infor for this is going to be in the leaderboard file

    for (int i = 0; i < people.size(); i++) {
        csvLine = to_string(i+1) + ",";
        csvLine += people.at(i).getName() + ",";
        csvLine += to_string(people.at(i).getRating()) + ",";
        csvLine += to_string(people.at(i).getScore()) + ",";
        for(int i = 0; i < rounds; i++) {
            if(i == rounds - 1) {
                csvLine += "DNE";
                break;
            }
            csvLine += "DNE,";
        }
        cvsLeaderboard << csvLine << endl;
    }
}

int getRounds(string tourName) {
    ifstream inFile(tourName + ".csv");
    string fileLine = "";
    vector<string> tokens;

    getline(inFile, fileLine);
    while (getline(inFile, fileLine, ',')) {
        tokens.push_back(fileLine);
    }

    return stoi(tokens.at(5));


}
void removePlayer(vector<Person> &people) {


}
void editTourMain() {
    ifstream inFile;
    vector<Person> people;
    string tourName;
    int userInput = -1;
    int rounds;



    cin.ignore();
    while (true) {
        cout << "What is the name of the tournmanet? \nEnter:  ";
        getline(cin,tourName);
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

    rounds = getRounds(tourName);


    while(1) {
        userInput = -1;
        while ((1 > userInput) || (userInput >5)) {
            editTourWindow();
            cin >> userInput;
            if ((1 > userInput) || (userInput >5)) {
                errorMessageValue();
            }
        }

        if (userInput ==1) {
            addPlayer(tourName, people, rounds);
        }
        else if (userInput ==2) {

        }
        else if (userInput ==3) {
            createPairings(people);
        }
        else if (userInput == 4) {
            viewLeaderboard(people, tourName, rounds);
        }
        else if (userInput ==5) {
            break;
        }

    }


}


#endif // EDITTOURMAIN_H
