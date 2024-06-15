#include <iostream>
#include <string>
#include "../include/system/csv.hpp"
#include "../include/system/System.hpp"

using std::string;

string funcao () {

    vector<vector<string>> data = {
        {"Id", "Name", "Email", "Password", "userType"},
    {"1", "admin", "admin", "12345", "ouvinte"}
    };

    Csv* arquivos = new Csv();

    arquivos->writeCSV("../csv/users.csv", data);

    

    std::vector<std::vector<std::string>> data2 = arquivos->readCSV("../csv/users.csv");

    for (const auto& row : data2) {
        if (row[2] == "admi") {
            if (row[3] == "12345") {
                return "login";
            } else {
                return "senha errada";
            }
        }
        std::cout << "\n";
    }
  
    return "voce nao esta cadastrado";
}

int main () {
    
    System* sistema = new System();
    
    sistema->startTheSystem();
    
    return 0;
}