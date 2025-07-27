#include <iostream>
#include "Login_Signup.h"
#include <fstream>
using namespace std;

int main() {
    //=== === === Welcome Block === === ===
    constexpr  int console_width = 80;
    const string text = "=== === === === === Welcome === === === === ===";
    const int pad = (console_width - text.length()) / 2;
    cout << string(pad, ' ') << text << endl;
    cout<< "1. Register\n2. Login\n3. Exit" << endl;


    //Choice to dictate control flow
    int choice;
    while (true) {
        cout << "Enter your option: ";
        cin >> choice;
        if (choice == 1 || choice == 2 || choice ==3) break;
        cout << "Please enter a number between 1 to 3" << endl;
    }
    string filename = "user_data.txt";                        //file name saved as a constant variable for convenience

    unordered_map<string, pair<string, string>> user_database;      //unordered map for loading and saving user info from and to the file
    Login_Signup admin(user_database, filename);

    fstream file;
    file.open(filename, ios::in | ios::out | ios::app);        //opening file in input, output, and append mode

    //checks whether the file opens or not
    if (!file.is_open()) {
        cerr << "Error opening file"<< endl;
    }
    while (choice != 3) {
        if (choice == 1) {
            string username, password;
            admin.load_from_file(filename);

            //loops until a unique username is typed
            while (true) {
                cout << "Enter username: ";
                cin >> username;

                if (user_database.contains(username)) {
                    cerr << "Username already exists, try something else";
                } else {
                    cout << "Enter password: ";
                    cin >> password;
                    break;
                }
            }
            admin.register_user(username, password, filename);
            cout << "Registration Successful\n Welcome " << username << endl;
        } else if (choice == 2) {
            string username, password;
            admin.load_from_file(filename);
        }
    }

}
