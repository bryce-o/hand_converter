#include <iostream>
#include <string.h>
#include <istream>
#include <getopt.h>


using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;


int main(int argc, char * argv[]) {
    
    int gotopt;
    int option_index = 0;
    bool tourney;
    int num_calls = 0;
    string filename;
    option long_opts[] = {
        { "help", no_argument, 0, 'h'},
        { "tournament", no_argument, 0, 't'},
        { "cash", no_argument, 0, 'c'},
        { "filename", required_argument, 0, 'f'},
        { nullptr, 0, nullptr, '\0' },
    };
    
    while ((gotopt = getopt_long(argc, argv, "htcf:", long_opts, &option_index)) != -1) {
        if (gotopt == 'h'){
            cout << "USAGE: \n./converter '--tournament' (-t) OR '--cash' (-c) '--filename' (-f) FILENAME\n";
            cout << "Run the program with either the 'tournament or 'cash' arguments to specify what kind of hand the file is" << endl;
            exit(0);
        } // help
        if (gotopt == 'f'){
            filename = optarg;
        } // filename
        if (gotopt == 't'){
            tourney = true;
            num_calls++;
        }
        if (gotopt == 'c') {
            tourney = false;
            num_calls++;
        }// while
    }// get_opt
    if (num_calls != 1) {
        cout << "Incorrect usage. Call with --help for details" << endl;
        return 0;
    }
    
    
    
    
   
    return 0;
}
