#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <map>
using namespace std;
/**
 * @brief Reads key-value pairs from a configuration file
 * Each line in the file should have format: key-value
 * Lines starting with '#' or empty lines ignored
 * @param filename Path to the configuration file
 * @return A map where keys ar estrings and values are double
 * @throws runtime_eroor if the file cannot be openend
 */
map<string, double> readConfig(const string &filename);
#endif // Ending of UTILS_H