#include <iostream>
#include "Login_Signup.h"
#include <fstream>
using namespace std;

//function to take only 1,2, or 3 as input
int taking_input() {
    int choice;
    cout<< "1. Register\n2. Login\n3. Exit" << endl;
    while (true) {
        cout << "Enter your option: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1 || choice == 2 || choice ==3) break;
        cout << "Please enter a number between 1 to 3" << endl;
    }

    return choice;
}

int main() {
    //=== === === Welcome Block === === ===
    constexpr  int console_width = 80;
    const string text = "=== === === === === Welcome === === === === ===";
    const int pad = (console_width - text.length()) / 2;
    cout << string(pad, ' ') << text << endl;


    string filename = "user_data.txt";                              //file name saved as a constant variable for convenience

    unordered_map<string, pair<string, string>> user_database;      //unordered map for loading and saving user info from and to the file
    Login_Signup admin(user_database, filename);

    admin.load_from_file(filename);

    while (true) {
        int choice = taking_input();
        if (choice == 1) {
            string username, password;
            bool valid_username = false;
            
            while (!valid_username) {
                cout << "Enter username: ";
                cin >> username;
                if (admin.username_exists(username)) {
                    cerr << "Username already exists, try something else" << endl;
                } else {
                    valid_username = true;
                }
            }
            
            cout << "Enter password: ";
            cin >> password;
            
            if (admin.register_user(username, password, filename)) {
                cout << "Registration Successful\n Welcome " << username << endl;
            } else {
                cerr << "Registration failed" << endl;
            }
        } else if (choice == 2) {
            string username, password;

            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (admin.verify_login(username, password)) {
                cout << "Login successful! Welcome " << username <<endl;
            } else {
                cerr <<"Wrong password! Try again." << endl;
            }
        } else break;
    }

}
