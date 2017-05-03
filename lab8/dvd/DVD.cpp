#include "DVD.h"
#include "Exceptions/NoFileException.h"
#include "Exceptions/InvalidSequenceException.h"

#include <fstream>
#include <regex>
#include <sstream>
#include <cmath>

using std::vector;
using std::string;
using std::ifstream;
using std::getline;
using std::regex;
using std::to_string;
using std::stringstream;

void DVD::delay(const string input_file, const string output_file, int delay, int frame_rate) {
    vector<string> lines = readLines(input_file);

    for (auto & line : lines) {
        line = delayLine(line, delay, frame_rate);
    }

    writeToFile(output_file, lines);
}

void DVD::writeToFile(const string output_file, vector<string> lines) {
    std::ofstream file;
    file.open(output_file, std::ofstream::out | std::ofstream::trunc);

    if (file.fail()) {
        throw NoFileException("No output file in given path. Remember to provide a full path to the file.");
    }

    for (auto & line : lines) {
        file << line << "\n";
    }
}

vector<string> DVD::readLines(const string input_file) {
    string line;
    vector<string> lines;
    ifstream input(input_file);

    if (! input) {
        throw NoFileException("No input file in given path. Remember to provide a full path to the file.");
    }

    while (getline(input, line)) {
        lines.push_back(line);
    }

    return lines;
}

string DVD::delayLine(const string line, int delay, int frame_rate) {
    validateLineFormat(line);

    stringstream ssline(line);
    string text;
    int start;
    int end;

    ssline.ignore(1, '{');
    ssline >> start;
    ssline.ignore(1, '}');
    ssline.ignore(1, '{');
    ssline >> end;
    ssline.ignore(1, '}');
    getline(ssline, text);

    const int c = (int) floor(frame_rate * ((double) delay / 1000));

    return "{" + to_string(start + c) + "}{" + to_string(end + c) + "}" + text;
}

void DVD::validateLineFormat(const string line) {
    regex expression("^(\\{\\d+\\}\\{\\d+\\}).+$");

    if (! regex_match(line, expression)) {
        throw InvalidSequenceException("Provided file contains a syntax error");
    }
}
