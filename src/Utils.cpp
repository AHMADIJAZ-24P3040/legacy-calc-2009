#include "Utils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
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