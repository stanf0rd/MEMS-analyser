/* by stanford  */

#define ANGLE_COUNT 89
#define FLOAT_PRECISION 4

#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_map>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::unordered_map;
using std::round;


void man() {
    cout << "     Welcome to MEMS-generator!     "     << "\n\n"
         << "Start command example:   "                << "\n"
         << "$ ./a.out data.csv output.txt 10 20 "     << "\n\n"
         << "a.out     -  program file name"           << "\n"
         << "data.csv  -  file with 89 angle values from 1° to 90°"    << "\n"
         << "out.txt   -  file, where generated data will be written"  << "\n"
         << "10        -  count of  angles to generate (max 100)"      << "\n"
         << "20        -  count of conders to generate (max 100)"      << endl;
}

bool makeAngleTable(const string filename, unordered_map<short, float> &angleTable) {
    ifstream data(filename);
    float leak = 0;
    int angle = 1;
    while (angle != ANGLE_COUNT + 1) {
        data >> leak;
        if (!data.good()) {
            data.clear();
            data.ignore(256, '\n');
            angle++;
            continue;
        }
        angleTable.insert(std::make_pair(angle++, leak * 1e6));
        if (data.eof()) break;
    }
    if (angle != ANGLE_COUNT + 1) return false;
    else return true;
}


int main(int argc, char const *argv[]) {
    if (argc != 5) {
        man();
        return 0;
    }

    ushort angleCount  = stoi(string(argv[3])),
           conderCount = stoi(string(argv[4]));

    if (angleCount  > 100
    ||  angleCount  < 1
    ||  conderCount > 100
    ||  conderCount < 1
    ) {
        man();
        return 0;
    }

    string dataFilename(argv[1]);
    string outFilename(argv[2]);

    unordered_map<short, float> angleTable;
    if (!makeAngleTable(dataFilename, angleTable)) {
        cout << "Error: not enough data." << endl;
        return 0;
    }

    std::srand(std::time(nullptr));
    ofstream output(outFilename);
    if (!output.is_open()) {
        cout << "unable to open file " << "\"" << outFilename << "\"" << endl;
        return 0;
    }

    for (int j = 0; j != conderCount; j++) {
        for (int i = 0; i != angleCount; i++) {
            float floatAngle = static_cast<float>(rand())
                             / static_cast<float>(RAND_MAX/(ANGLE_COUNT));
            int intAngle = round(floatAngle);
            if (intAngle == 0) intAngle++;
            float leak = 0;
            while(1) try {
                leak = angleTable.at(intAngle);
                output << std::fixed
                       << std::showpoint
                       << std::setprecision(FLOAT_PRECISION)
                       << std::right
                       << leak;
                break;
            } catch(std::out_of_range) {
                if (intAngle < floatAngle
                && intAngle > 1
                || intAngle == ANGLE_COUNT) intAngle--;
                else intAngle++;
            }
            if (i != angleCount - 1) output << ", ";
        } output << endl;
    }

    return 0;
}
