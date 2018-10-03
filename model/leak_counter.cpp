/* by stanford  */
#include "leak_counter.hpp"

#include <fstream>
#include <cassert>
// #include <cstdlib>
// #include <ctime>
// #include <cmath>
// #include <cassert>

using std::ifstream;
using std::string;
using std::unordered_map;
// using std::round;

#include <iostream>
// FIXME: iostream

LeakCounter::LeakCounter()
{
    MakeLeakTable("data/flat2.csv", flatLeaks);
    MakeLeakTable("data/stair2.csv", stairLeaks);
    std::cout << "LeakCounter prepared" << std::endl;
}


// float LeakCounter::CountLeak(int ionsCount, float angle) {
//     assert(ionsCount >= 0 && ionsCount <= 3);
//     if (!ionsCount) return 0;

//     int intAngle = round(angle);
//     if (intAngle == 0) intAngle++;
//     float leak = 0;
//     while(1) try {
//         leak = angleTable.at(intAngle);
//         break;
//     } catch(std::out_of_range) {
//         if (intAngle < angle
//         && intAngle > 1              // TODO: check if this shit is safe
//         || intAngle == angleCount) intAngle--;
//         else intAngle++;
//     }

//     return leak;
// }


bool LeakCounter::MakeLeakTable(
    const string filename,
    std::array<LeakMap, maxCrossingsCount> &leaks
) {
    ifstream data(filename);
    float leak = 0;
    int angle = 1;
    while (angle != angleCount + 1) {
        for (int i = 0; i != maxCrossingsCount; i++) {
            data >> leak;
            leaks[i].insert(std::make_pair(angle++, leak * 1e6));
            assert(data.good() || data.eof());
            data.get();
        }
        if (data.eof()) break;
    }
    if (angle != angleCount + 1) return false;
    else return true;
}


// float CountLeak(Conder) {
    
// }


// int main() {

//     unordered_map<short, float> angleTable;
//     if (!makeAngleTable(dataFilename, angleTable)) {
//         cout << "Error: not enough data." << endl;
//         return 0;
//     }


//     for (int j = 0; j != conderCount; j++) {
//         for (int i = 0; i != angleCount; i++) {
//             float floatAngle = static_cast<float>(rand())
//                              / static_cast<float>(RAND_MAX/(angleCount));
//             int intAngle = round(floatAngle);
//             if (intAngle == 0) intAngle++;
//             float leak = 0;
//             while(1) try {
//                 leak = angleTable.at(intAngle);
//                 output << std::fixed
//                        << std::showpoint
//                        << std::setprecision(FLOAT_PRECISION)
//                        << std::right
//                        << leak;
//                 break;
//             } catch(std::out_of_range) {
//                 if (intAngle < floatAngle
//                 && intAngle > 1
//                 || intAngle == angleCount) intAngle--;
//                 else intAngle++;
//             }
//             if (i != angleCount - 1) output << ", ";
//         } output << endl;
//     }

//     return 0;
// }
