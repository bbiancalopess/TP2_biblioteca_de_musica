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
using std::runtime_error;

void Csv::writeCSV(const string& filename, const vector<vector<string>>& data) {
    ofstream file(filename);
    if (!file.is_open()) {
        string err = "Unable to open file for writing: " + filename;
        throw runtime_error(err);
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
        string err = "Unable to open file for reading: " + filename;
        throw runtime_error(err);
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