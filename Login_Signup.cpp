#include "Login_Signup.h"
#include <chrono>
#include <queue>
#include <random>

using namespace std;

string Login_Signup::generate_salt(const size_t length) {

    //character set to randomly pick from
    static const string char_set = "012345678ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    //A pseudo random number generator (PRNG) with a seed of the time difference between the moment of initialization to epoch
    mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dist(0, char_set.size() - 1);

    string salt;

    for (int i = 0; i < length; i++) {
        //the dist object selects a number with the predefined range from the PRNG and picks a char from char_set
        salt += char_set[dist(generator)];
    }

    return salt;

}

string Login_Signup::generate_hash(const string &password, const string &salt) {
    hash<string> hasher;        //An object of the hash class template which hashes strings
    size_t hash_value = hasher(password + salt);

    stringstream ss;            //ss is a string stream object which creates a stream of string
    ss << hex <<hash_value;     //the hash value, an unsigned integer, is turned into hexadecimal and then fed to the stream

    return ss.str();            //The
}

bool Login_Signup::register_user(const string &username, const string &password, const string &filename) {
    if (user_database.find(username) == user_database.end()) {
        return false;
    } else {
        string salt = generate_salt();
        string hashed_password = generate_hash(password, salt);

        user_database[username] = make_pair(salt, hashed_password);
        save_to_file(filename);
        return true;
    }
}

bool Login_Signup::verify_login(const string &username, const string &password) {
    auto it = user_database.find(username);
    if (it == user_database.end()) {
        return false;
    } else {
        string retrieved_salt = it -> second.first;
        string stored_hash = it -> second.second;
        string computed_hash = generate_hash(password, retrieved_salt);

        if (computed_hash == stored_hash) return true;
        else {
            cout << "Wrong password" << endl;
            return false;
        }
    }
}




