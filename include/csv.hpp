#ifndef CSV
#define CSV

#include <string>
#include <vector>

using std::string;
using std::vector;

/**
 * @brief Writes in a CSV file.
 * @details Opens an CSV file and writes on it.
 * @param filename The name of the file that should be written on.
 * @param data A vector of vector containing the data that should be written on the file.
 */
void writeCSV(const string& filename, const vector<vector<string>>& data);

/**
 * @brief Reads a CSV file.
 * @details Opens an CSV file and reads what's on it.
 * @param filename The name of the file that should be read.
 */
vector<vector<string>> readCSV(const std::string& filename);

#endif