#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "csv.hpp"

using std::string;
using std::vector;
using std::getline;
using std::ofstream;
using std::cerr;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::runtime_error;
using std::cout;

void writeCSV(const string& filename, const vector<vector<string>>& data) {
    ofstream file(filename); // ofstream abre o arquivo para escrita dando a ele o nome file
    if (!file.is_open()) {
        string err = "Unable to open file for writing: " + filename;
        throw runtime_error(err);
    }

    for (const auto& row : data) {
        for (int i = 0; i < row.size(); ++i) {
            file << row[i]; // escreve cada string da linha ao arquivo
            if (i < row.size() - 1) { // se a string não for a última da linha
                file << ","; // adiciona vírgula
            }
        }
        file << "\n";
    }

    file.close();
}

vector<vector<string>> readCSV(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename); // ifstream é a função que abre o arquivo para leitura dando a ele o nome file
    if (!file.is_open()) {
        string err = "Unable to open file for reading: " + filename;
        throw runtime_error(err);
    }

    string line;
    while (getline(file, line)) { // getline verifica se ainda existem linhas a ser lidas no arquivo, se sim, atribui a linha à variável line
        vector<string> row;
        stringstream ss(line); // stringstream transforma uma string em um tipo de objeto 
        string value;
        while (getline(ss, value, ',')) { // aqui o loop passa pela stringstream separando-a por cada ',' e adiciona a string ao vetor da linha
            row.push_back(value); // adiciona a string à linha
        }
        data.push_back(row); // adiciona a linha ao vetor
    }

    file.close();

    // data.erase(data.begin()); // apaga a primeira linha da tabela, a linha dos títulos das colunas

    return data;
}