#ifndef LOGIN_SIGNUP_H
#define LOGIN_SIGNUP_H
#include <string>
#include <unordered_map>

using namespace std;
class Login_Signup {
private:
    string filename;
    unordered_map<string, pair<string, string>> user_database;

    
    //Function to generate salt randomly
    static string generate_salt(const size_t length = 7);
    //Function to crate a password by hashing user input and generated salt
    static string generate_hash(const string& password, const string& salt);

public:
    //Functions for user authentification
    bool register_user(const string& username, const string& password, const string& filename); //Constructor
    bool verify_login(const string& username, const string& password);
    //Functions to save or retrieve user data

    void save_to_file(const string& filename);
    void load_from_file(const string& filename);
    //constructor
    Login_Signup(unordered_map<string, pair<string, string>> &ud, string &fn);
    
};



#endif //LOGIN_SIGNUP_H
