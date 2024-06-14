#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "../../include/system/csv.hpp"

using std::string;
using std::vector;
using std::getline;
using std::ofstream;
using std::cerr;
using std::endl;
using std::stringstream;
using std::ifstream;

void Csv::writeCSV(const string& filename, const vector<vector<string>>& data) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file for writing: " << filename << endl;
        return;
    }

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }

    file.close();
}

vector<vector<string>> Csv::readCSV(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file for reading: " << filename << endl;
        return data;
    }

    string line;
    while (getline(file, line)) {
        vector<string> row;
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        data.push_back(row);
    }

    file.close();
    return data;
}

/*
int main() {
    vector<vector<string>> data = {
        {"Name", "Age", "City"},
        {"Alice", "30", "New York"},
        {"Bob", "25", "Los Angeles"},
        {"Charlie", "35", "Chicago"}
    };

    writeCSV("output.csv", data);
    std::cout << "CSV file written successfully." << std::endl;

    std::vector<std::vector<std::string>> data = readCSV("output.csv");

    for (const auto& row : data) {
        for (const auto& col : row) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
*/