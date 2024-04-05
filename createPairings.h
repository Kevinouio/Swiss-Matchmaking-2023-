#ifndef CREATEPAIRINGS_H
#define CREATEPAIRINGS_H
#include "person.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
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

//This is going to seperate the players into different vectors depending on their array.
vector<vector<Person>> pigeionHoleSort(int currRound, vector<Person> &people) {
    vector<vector<Person>> scores;
    string vectorName = "";
    for (int i = 0; i < (2 * (currRound-1) ) + 1; i++) {
        vector<Person> scoreAmount;
        scores.push_back(scoreAmount);
    }
    for(int i = 0; i < people.size(); i++) {
        //hardest line of code to write tbh but this seperates each player into their respective score group
        scores.at(people.at(i).getScore() / 0.5).push_back(people.at(i));
    }

    for (int i = 0; i < scores.size(); i++) {
        //sortRatings(scores.at(i));
    }


    people = scores.at(0);
    for (int i = 1; i < scores.size(); i++) {
        people.insert(people.end(), scores.at(i).begin(), scores.at(i).end());
    }


    return scores;

}

void giveBye(vector<vector<Person>> &scores, int currRound){
    string result = "BYE";
    scores.at(-1).at(0).updateMatchHistory(currRound, result,0,"");
}


vector<vector<Person>> createPairings(vector<Person> &people,string tourName, int currRound) {
    //sorting algorithm for the people vector

    ofstream csvPairings(tourName + "Round_" + to_string(currRound) + ".csv");
    string csvLine;
    vector<vector<Person>> scores;
    vector<vector<Person>> tempScores;
    vector<vector<Person>> matches;


    csvLine = ",White,,Black";
    csvPairings << csvLine << endl;

    csvLine = "Match No.,Player 1,Result,Player 2";
    csvPairings << csvLine << endl;



    scores = pigeionHoleSort(currRound, people);
    if (currRound == 1) {
        for (int i = 0; i< ceil(people.size()/2); i++) {
            vector<Person> pairs;
            if (people.size() % 2 == 1) {
                giveBye(scores, currRound);
                continue;
            }
            pairs.push_back(people.at(0));
            people.erase(people.begin());
            pairs.push_back(people.at(-1));
            people.erase(people.begin() - 1);



            matches.push_back(pairs);
        }

        for (int i = 0; i < matches.size() ; i++) {
            if (i % 2 == 0) {
                csvLine = to_string(i) + ".," + matches.at(i).at(0).getName() +"(" + to_string(matches.at(i).at(0).getRating()) + "),";
                csvLine += matches.at(i).at(1).getName() +"(" + to_string(matches.at(i).at(1).getRating()) + "),";
                csvPairings << csvLine << endl;
            }
            else if (i % 2 == 1) {
                csvLine = to_string(i) + ".," + matches.at(i).at(0).getName() +"(" + to_string(matches.at(i).at(0).getRating()) + "),";
                csvLine += matches.at(i).at(1).getName() +"(" + to_string(matches.at(i).at(1).getRating()) + "),";
                csvPairings << csvLine << endl;
            }
        }


    }

    return matches;


}




#endif // CREATEPAIRINGS_H
