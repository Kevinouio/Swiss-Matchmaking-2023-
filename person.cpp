#include "person.h"

Person::Person() {
    this->name = "";
    this->USCFID = "";
    this->rating = 0;
    this->score = 0;
}

void Person::setScore(double score) {
    this->score = score;
}

double Person::getScore() {
    return score;
}


void Person::setRating(int rating) {
    this->rating = rating;
}

int Person::getRating() {
    return rating;
}


void Person::setName(string name) {
    this->name = name;
}

string Person::getName() {
    return name;
}


void Person::setUSCFID(string USCFID) {
    this->USCFID = USCFID;
}

string Person::getUSCFID() {
    return USCFID;
}

void Person::updateMatchHistory(int currRound, string result, int matchNum, string color) {

    string playerResult;

    playerResult = result + " " + to_string(matchNum) + " " + color;
    if (result == "BYE") {
        this->matchHistory.at(currRound) = "BYE";
        this->score += 1;
    }
    else if (result == "W"){
        this->matchHistory.at(currRound) = playerResult;
        this->score +=1;
    }
    else {
        this->matchHistory.at(currRound) = playerResult;
    }
}


void Person::setMatchHistory(int rounds) {
    for(int i = 0; i < rounds; i++) {
        this->matchHistory.push_back("DNE");
    }
}

void Person::setCurHistory(vector<string> matches) {
    this->matchHistory = matches;
}

vector<string> Person::getMatchHistory() {
    return matchHistory;
}
