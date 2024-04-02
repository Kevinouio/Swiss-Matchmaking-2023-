#include "person.h"

Person::Person() {
    this->name = "";
    this->USCFID = "";
    this->rating = 0;
    this->score = 0;
}

void Person::setScore(int score) {
    this->score = score;
}

int Person::getScore() {
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
