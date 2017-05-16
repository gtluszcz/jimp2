#define NUMBER_OF_ADDED_ARGUMENTS 1

#include "Exceptions/Exception.h"
#include "DVD.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char * argv[]) {
    if (argc != 4 + NUMBER_OF_ADDED_ARGUMENTS) {
        cout << "The program expects four arguments to be passed. " << argc - NUMBER_OF_ADDED_ARGUMENTS << " given." << endl;
        return 0;
    }

    string input_file = argv[NUMBER_OF_ADDED_ARGUMENTS];
    string output_file = argv[1 + NUMBER_OF_ADDED_ARGUMENTS];
    int delay = atoi(argv[2 + NUMBER_OF_ADDED_ARGUMENTS]);
    int frame_rate = atoi(argv[3 + NUMBER_OF_ADDED_ARGUMENTS]);

    try {
        DVD::delay(input_file, output_file, delay, frame_rate);
    } catch (Exception e) {
        cout << e.message() << endl;
        return 0;
    }

    cout << "Subtitles conversion has been successful" << endl;

    return 0;
}
