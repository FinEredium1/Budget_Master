#include "log_in.h"

log_in::log_in(){
    // do nothing
}

void log_in::push_in(ifstream &read){

    if (read.is_open()){
        string line, user, pass;
        double amount;
        while (getline(read, line)){
        istringstream iss(line);
        iss >> user >> pass >> amount;
        account* sA = new account;
        sA->username = user;
        sA->password = pass;
        sA->amount = amount;
        all_accounts.push_back(sA);
        }
    }
    else{
        cout << "There are no accounts avalable to read from" << endl;
    }
}

void log_in::deposit(const string& inputFileName, double amount) {
    ifstream inputFile(inputFileName);
    ofstream outputFile("dat.txt");

    if (!inputFile || !outputFile) {
        cerr << "Failed to open files." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string user;
        string pass;
        double number = 0;
        if (iss >> user >> pass >> number) {
            if (user == _user && pass == _pass) {
                (amount > 0) ? number = amount: number = number;
                _amount += number;
                number = _amount;
            }
            outputFile << user << " " << pass << " " << number << endl;
        } else {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    if (remove(inputFileName.c_str()) != 0) {
        cerr << "Error deleting file: " << inputFileName << endl;
        return;
    }

    // Rename the modified file to the original name
    if (rename("dat.txt", inputFileName.c_str()) != 0) {
        cerr << "Error renaming file." << endl;
        return;
    }


    cout << "Deposit completed!" << endl;
}

void log_in::withdraw(const string& inputFileName, double amount) {
    bool success = true;
    ifstream inputFile(inputFileName);
    ofstream outputFile("dat.txt");

    if (!inputFile || !outputFile) {
        cerr << "Failed to open files." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string user;
        string pass;
        double number = 0;
        if (iss >> user >> pass >> number) {
            if (user == _user && pass == _pass) {
                (amount > 0) ? number = amount: number = number;
                (number > _amount) ? number = -1 : _amount -= number;
                if (number == -1){
                    cout << "Your account does not have sufficient funds to withdral $" << amount << endl;
                    success = false;
                    number = 0;
                }
                number = _amount;
            }
            outputFile << user << " " << pass << " " << number << endl;
        } else {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    if (remove(inputFileName.c_str()) != 0) {
        cerr << "Error deleting file: " << inputFileName << endl;
        return;
    }

    // Rename the modified file to the original name
    if (rename("dat.txt", inputFileName.c_str()) != 0) {
        cerr << "Error renaming file." << endl;
        return;
    }

    if (success){
        cout << "Withdrawl completed!" << endl;
    }
}

double log_in::get_amount(){
    return _amount;
}

void log_in::create_account(string name, string pass, ofstream &write){
    for (account* acc: all_accounts){
        if (acc->username == name && acc->password == pass){
            cout << "This account already exists. Please log in" << endl;
            return;
        }
    }
    account* sA = new account;
    sA->username = name;
    sA->password = pass;
    sA->amount = 0;
    all_accounts.push_back(sA);
    write << name << " " << pass << " " << 0 << " \n";

}



bool log_in::access_account(string name, string pass){
    bool user_match = false;
    for (account* acc: all_accounts){
        if (acc->username == name){
            if (acc->password == pass){
                cout << "You have logged in to " << acc->username << endl;
                _amount = acc->amount;
                _user = acc->username;
                _pass = acc->password;
                return true;
            }
            else{
                cout << "Password doesn't match with the username " << acc->username << endl;
                cout << "Searching..." << endl;
                user_match = true;
                continue;
            }
        }
    }
    if (user_match){
        cout << "Wrong Password" << endl;
    }
    cout << "Username is not in our directory. Please create new account." << endl;
    return false;
}

log_in::~log_in(){
    for (account* acc: all_accounts){
        delete acc;
    }
}