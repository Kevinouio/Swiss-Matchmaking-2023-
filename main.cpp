#include <iostream>
#include "outputs.h"
#include "viewmain.h"
#include "newtourmain.h"
#include "editTourMain.h"
using namespace std;

int main()
{
    while (1){
        string userInput = "";



        bool notNum = true;
        while (notNum) {
            firstWindow();
            cin >> userInput;
            for (int i = 0; i < userInput.size(); i++) {
                if (!(isdigit(userInput.at(i)))) {
                    errorMessageCharacter();
                    notNum = true;
                    break;
                }
                notNum = false;
            }
        }
        if ((1 > stoi(userInput)) || (stoi(userInput) >5)) {
            errorNotAnOption();
            continue;
        }

        if (stoi(userInput) == 1) {
            while (1) {
                userInput = "";


                notNum = true;
                while (notNum) {
                    createTourWindow();
                    cin >> userInput;
                    for (int i = 0; i < userInput.size(); i++) {
                        if (!(isdigit(userInput.at(i)))) {
                            errorMessageCharacter();
                            notNum = true;
                            break;
                        }
                        notNum = false;
                    }
                }
                if ((1 > stoi(userInput)) || (stoi(userInput) >5)) {
                    errorNotAnOption();
                    continue;
                }

                if (stoi(userInput) == 1) {
                    newTourMain();
                }
                else if (stoi(userInput) ==2) {
                    editTourMain();
                }
                else if (stoi(userInput) ==3) {
                    break;
                }

            }


        }
        else if (stoi(userInput) == 2) {
            viewMain();
        }




        else if (stoi(userInput) ==3) {
            break;
        }

    }




    return 0;
}
