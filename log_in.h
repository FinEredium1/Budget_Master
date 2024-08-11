#ifndef LOGIN_h
#define LOGIN_h

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdio>
using namespace sf;
using namespace std;


struct account{
    string username;
    string password;
    double amount;
};

class log_in{
    private:
    vector <account*> all_accounts;
    double _amount;
    string _user;
    string _pass;
    public:
    log_in();
    ~log_in();
    void push_in(ifstream&);
    void create_account(string, string, ofstream&);
    bool access_account(string, string);
    double get_amount();
    void deposit(const string&, double);
    void withdraw(const string&, double);
};


#endif