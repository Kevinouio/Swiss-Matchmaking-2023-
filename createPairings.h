#ifndef CREATEPAIRINGS_H
#define CREATEPAIRINGS_H
#include "person.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


// Bubble sort
void sortRatings(vector<Person> &people)
{
    for(int i = 0; i < people.size() - 1; i++)
    {
        for(int j = 0; j < people.size() - i - 1; j++)
        {
            if(people.at(j).getRating() < people.at(j+1).getRating())
            {
                Person temp = people[j];

                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}


// So this is going to create a pairing file in which it creaes a csv list for the pairing for the current round

//This is going to seperate the players into different vectors depending on their score.
vector<vector<Person>> pigeionHoleSort(int currRound, vector<Person> &people) {

    vector<vector<Person>> scores;
    string vectorName = "";


    for (int i = 0; i < (2 * (currRound-1) ) + 1; i++) {
        vector<Person> scoreAmount;
        scores.push_back(scoreAmount);
    }

    for(int i = 0; i < people.size(); i++) {
        //hardest line of code to write tbh but this seperates each player into their respective score group

        scores.at((people.at(i).getScore() / 0.5)).push_back(people.at(i));
    }


    for (int i = 0; i < scores.size(); i++) {
        if (scores.at(i).size() == 0) {
            continue;
        }
        sortRatings(scores.at(i));
    }


    people.clear();
    for (int i = (scores.size()-1); i >= 0; i--) {
        people.insert(people.end(), scores.at(i).begin(), scores.at(i).end());
    }


    return scores;

}

void giveBye(Person &player, int currRound){
    string result = "BYE";
    player.updateMatchHistory(currRound, result,0,"");
}


vector<vector<Person>> createPairings(vector<Person> &people,string tourName, int currRound) {
    //sorting algorithm for the people vector
    ofstream csvPairings(tourName + "Round_" + to_string(currRound) + ".csv");
    string csvLine;
    vector<Person> tempPeople;
    vector<vector<Person>> scores;
    vector<vector<Person>> tempScores;
    vector<vector<Person>> matches;


    csvLine = ",White,,Black";
    csvPairings << csvLine << endl;

    csvLine = "Match No.,Player 1,Result,Player 2";
    csvPairings << csvLine << endl;


    tempPeople = people;
    scores = pigeionHoleSort(currRound + 1, people);
    tempScores = scores;


    //Round one with no conditions are being broken
    if (currRound == 1) {
        //This part can be rewritten because ceiling division just doesn't work for some reason
        int repeats = ceil(tempPeople.size()/2);
        if (tempPeople.size() % 2 == 1) {
            repeats++;
        }

        for (int i = 0; i< repeats; i++) {
            vector<Person> pairs;
            Person player;
            int index = 0;
            if (tempPeople.size() % 2 == 1) {

                player = scores.at(scores.size()-1).at(0);
                for (int i = 0; i < people.size(); i++) {
                    if (player.getName() == people.at(i).getName()) {
                        index = i;
                    }
                }
                giveBye(people.at(index), currRound);
                tempPeople.erase(tempPeople.begin());

                continue;
            }
            pairs.push_back(tempPeople.at(0));
            tempPeople.erase(tempPeople.begin());
            pairs.push_back(tempPeople.at(tempPeople.size()-1));
            tempPeople.pop_back();



            matches.push_back(pairs);
        }
        for (int i = 0; i < matches.size() ; i++) {
            if (i % 2 == 0) {
                csvLine = to_string(i+1) + ".," + matches.at(i).at(0).getName() +"(" + to_string(matches.at(i).at(0).getRating()) + "),,";
                csvLine += matches.at(i).at(1).getName() +"(" + to_string(matches.at(i).at(1).getRating()) + "),";
                csvPairings << csvLine << endl;
            }
            else if (i % 2 == 1) {
                csvLine = to_string(i+1) + ".," + matches.at(i).at(1).getName() +"(" + to_string(matches.at(i).at(1).getRating()) + "),,";
                csvLine += matches.at(i).at(0).getName() +"(" + to_string(matches.at(i).at(0).getRating()) + "),";
                csvPairings << csvLine << endl;
            }
        }


    }














    return matches;


}




#endif // CREATEPAIRINGS_H
