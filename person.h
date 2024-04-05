#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
using namespace std;


//Person class which is self expanatory
class Person
{
public:
    Person();

    //setter and getter for scores.
    void setScore(double score);
    double getScore();

    //setter and getter for rating.
    void setRating(int rating);
    int getRating();

    //setter and getter for name.
    void setName(string name);
    string getName();

    //setter and getter for USCFID.
    void setUSCFID(string USCFID);
    string getUSCFID();

    void updateMatchHistory(int currRound, string result, int matchNum, string color);
    void setMatchHistory(int rounds);
    void setCurHistory(vector<string> matches);

    vector<string> getMatchHistory();


private:
    //Every info about each player
    int rating;
    string name;
    string USCFID;
    double score;
    vector<string> playablePeople;
    vector<string> matchHistory;

};

#endif // PERSON_H
