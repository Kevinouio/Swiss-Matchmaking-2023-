#include <iostream>
#include "outputs.h"
#include "viewmain.h"
#include "newtourmain.h"
#include "editTourMain.h"
using namespace std;

int main()
{
    while (1){
        int userInput = -1;



        while ((1 > userInput) || (userInput >3)) {
            firstWindow();
            cin >> userInput;
            if ((1 > userInput) || (userInput >3)) {
                errorMessageValue();
            }
        }

        if (userInput == 1) {
            while (1) {
                userInput = -1;


                while ((1 > userInput) || (userInput >3)) {
                    createTourWindow();
                    cin >> userInput;
                    if ((1 > userInput) || (userInput >3)) {
                        errorMessageValue();
                    }
                }

                if (userInput == 1) {
                    newTourMain();
                }
                else if (userInput ==2) {
                    editTourMain();
                }
                else if (userInput ==3) {
                    break;
                }

            }


        }
        else if (userInput == 2) {
            viewMain();
        }




        else if (userInput ==3) {
            break;
        }

    }




    return 0;
}
