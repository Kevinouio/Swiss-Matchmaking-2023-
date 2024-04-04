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
