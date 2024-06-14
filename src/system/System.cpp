#include <iostream>
#include "../../include/system/System.hpp"
#include "../../include/system/csv.hpp"
#include <vector>
#include <string>
#include <stdexcept>

using std::vector;
using std::string;
using std::stoi;
using std::to_string;
using std::runtime_error;
using std::cerr;
using std::endl;
using std::cout;

string System::login(string email, string password) {
    try {
        Csv* file = new Csv();
    
        vector<vector<string>> data = file->readCSV("../csv/users.csv");

        for (const auto& row : data) {
            if (row[2] == email) {
                if (row[3] == password) {
                    return "loged";
                } else {
                    return "wrong password";
                }
            }
        }

        return "not registered";
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }
}

string getNextId(){
    try{
        Csv* arquivo = new Csv();

        vector<vector<string>> users = arquivo->readCSV("../csv/users.csv");

        return to_string(stoi(users[users.size() - 1][0]) + 1);
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }
}

string System::signUp(string name, string email, string password, string userType) {
    try {
        Csv* file = new Csv();
    
        vector<vector<string>> data = file->readCSV("../csv/users.csv");

        vector<string> newData = {getNextId(), name, email, password, userType};

        data.push_back(newData);

        file->writeCSV("../csv/users.csv", data);

        return "cadastrado";
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }    
}

void System::startTheSystem() {
    cout << 
}