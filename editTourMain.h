#ifndef EDITTOURMAIN_H
#define EDITTOURMAIN_H
#include "outputs.h"
#include "string"
#include <fstream>
#include <vector>
#include "person.h"
#include "createPairings.h"

using namespace std;

void addPlayer(string tourName, vector<Person> &people, int rounds) {
    Person player;
    int rating;
    string name;
    string USCFID;
    double score = 0.0;
    string fileInput = "";
    vector<string> stringlines;
    ifstream txtinFile(tourName + "Players.txt");

    while (!txtinFile.eof()) {
        getline(txtinFile,fileInput);
        stringlines.push_back(fileInput);

    }
    txtinFile.close();
    ofstream txtFile(tourName + "Players.txt");

    for (int i = 0; i < stringlines.size(); i++) {
        if (i == stringlines.size()-1) {
            txtFile << stringlines.at(i);
            continue;
        }
        txtFile << stringlines.at(i) << endl;
    }

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
    for (int i = 0; i < rounds; i++) {
        txtFile << "DNE" << endl;
    }

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
        if (inFile.eof()){
            break;
        }
        getline(inFile,fileInput);
        player.setRating(stoi(fileInput));

        getline(inFile, fileInput);
        player.setUSCFID(fileInput);


        getline(inFile, fileInput);
        player.setScore(stod(fileInput));



        for (int i = 0; i < rounds; i++) {
            getline(inFile, fileInput);
            matches.push_back(fileInput);
        }

        player.setCurHistory(matches);

        people.push_back(player);

    }
    inFile.close();
    // Insert a sorting algorithm right here for scores first and then by ratings
}

void viewLeaderboard(vector<Person> &people, string tourName, int rounds) {
    string csvLine;

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
    //Also put sorting algorithm in here as well

    for (int i = 0; i < people.size(); i++) {
        vector<string> curPlayerHistory;

        csvLine = to_string(i+1) + ",";
        csvLine += people.at(i).getName() + ",";
        csvLine += to_string(people.at(i).getRating()) + ",";
        csvLine += to_string(people.at(i).getScore()) + ",";

        curPlayerHistory = people.at(i).getMatchHistory();

        for(int i = 0; i < curPlayerHistory.size(); i++) {
            if(i == rounds - 1) {
                csvLine += curPlayerHistory.at(i);
                break;
            }

            csvLine += curPlayerHistory.at(i) + ",";
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

int getCurrRounds(string tourName) {
    ifstream inFile(tourName + ".csv");
    string fileLine = "";
    vector<string> tokens;

    getline(inFile, fileLine);
    while (getline(inFile, fileLine, ',')) {
        tokens.push_back(fileLine);
    }

    return stoi(tokens.at(6));


}
void removePlayer(vector<Person> &people) {


}
void editTourMain() {
    ifstream inFile;
    vector<Person> people;
    string tourName;
    int userInput = -1;
    int rounds;
    int currRound;
    vector<vector<Person>> matches;
    string matchNum = "0";
    string result = "";

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
    currRound = getCurrRounds(tourName);
    getCurrentPlayers(tourName, people, rounds);



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
            string color = "";
            while (1) {
                cout << "Which match would you like to update? \nEnter:  ";
                cin >> matchNum;
                for (int i = 0; i < matchNum.size(); i++) {
                    if (isdigit(matchNum.at(i))) {
                        errorMessageValue();
                        continue;
                    }
                }
                break;
            }

            while (1) {
                cout << "Whot won? (W=White D= Draw B=Black) \nEnter:  ";
                cin >> result;
                if (!((result != "W") || (result != "D") || (result != "B"))) {
                    //Insert error message
                    continue;
                }
                break;
            }

            \
                for (int i = 0; i < matches.at(stoi(matchNum) - 1).size(); i++) {
                if ((stoi(matchNum) % 2)+1 == 0) {
                    color = "BL";
                }
                else {
                    color = "WH";
                }
                matches.at(stoi(matchNum) - 1).at(i).updateMatchHistory(currRound, result, stoi(matchNum), color);
            }





        }
        else if (userInput ==3) {
            matches = createPairings(people, tourName, currRound);
        }
        else if (userInput == 4) {
            pigeionHoleSort(currRound,people);
            viewLeaderboard(people, tourName, rounds);
        }
        else if (userInput ==5) {
            break;
        }

    }


}


#endif // EDITTOURMAIN_H
