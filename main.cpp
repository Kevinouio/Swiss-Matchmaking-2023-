#include <iostream>
#include <fstream>



using namespace std;

int main()
{
    int option;
    cout << "Welcome to the Chess Swiss Game Matcher" << endl;



    while (1) {




        cout << endl << "0. Exit" << endl;
        cout << "1. Create matches" << endl;
        cout << "2. Update match result" << endl;
        cout << "3. Add players" << endl;
        cout << "4. Edit points" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        //Stop the maker
        if(option == 0) {
            cout << "Good-bye!" << endl;
            break;
        }

        // Creates Matches
        else if(option == 1) {
            // variable creation

        }

        // Update Match results
        else if(option == 2) {




        }

        // Lmao
        else if(option == 3) {




        }

        // wrong choice
        else
        {
            cout << "You entered an invalid option. Try again." << endl;
        }

    }


}
