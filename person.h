#ifndef PERSON_H
#define PERSON_H
#include <string>
using std::string;

class Person
{
public:
    Person();

    void setScore(int score);
    int getScore();


    void setRating(int rating);
    int getRating();


    void setName(string name);
    string getName();

    void setUSCFID(string USCFID);
    string getUSCFID();


private:
    int rating;
    string name;
    string USCFID;
    int score;

};

#endif // PERSON_H
