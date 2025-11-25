#include "Utils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
/**
 * @brief reads configuration from a file.
 * Opens the given file,  checks line is key=value ways
 * returns a map of strings keys and double values
 * @param filename Name of the configutation file
 * @return map of configuration keys and values
 * @throws runtime_error if file cannot be opened
 */
map<string, double> readConfig(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("Cannot open config file");
    }
    map<string, double> config;
    string line;
    while (getline(file, line))
    {
        if (line.empty() || line[0] == '#')
        {
            continue;
        }
        auto pos = line.find('=');
        if (pos == string::npos)
        {
            continue;
        }
        string key = line.substr(0, pos);
        double value = stod(line.substr(pos + 1));
        config[key] = value;
    }
    return config;
}