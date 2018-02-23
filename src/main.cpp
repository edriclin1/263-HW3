#include "functions.h"

/**
* Main to run balance and iToP functions. Takes
* command line arguments to load file and 
* specify command.
* 
* @author Edric Lin
* @version 2/23/2018
*/


/**
* Runs the program to test functions.
*
* @param argc number of command line arguments
* @param argv command line arguments
*/
int main(int argc, char** argv) {

    // if not 3 arguments, error
    if (argc != 3) {
        std::cout << "\t> Usage: ./prog_name input_file command" << std::endl;
        std::cout << "\t> Commands:" << std::endl;
        std::cout << "\t>     -bs: Balance symbols" << std::endl;
        std::cout << "\t>     -ip: Infix to postfix" << std::endl;
        exit(1);
    }

    // load input string
    std::string input = loadInput(argv[1]);
    if (input.empty()) {
        exit(1);
    }
    //std::cout << input << std::endl;
 
    // if command is 0, balance input symbols
    if (std::string(argv[2]) == "-bs") {
        if (balancedSymbols(input)) {
            std::cout << "\t> Yay! Input symbols are balanced." << std::endl;
        } else {
            std::cout << "\t> Oh no! Input symbols are NOT balanced." << std::endl;
        }
    }

    // if command is 1, convert infix to postfix
    else if (std::string(argv[2]) == "-ip") {
        std::string output = iToP(input);
        std::cout << "\t> Infix: " << input << std::endl;
        std::cout << "\t> Postfix: " << output << std::endl;
    }

    // else invalid command
    else {
        std::cout << "\t> Usage: ./prog_name input_file command" << std::endl;
        std::cout << "\t> Commands:" << std::endl;
        std::cout << "\t>     0: Balance symbols" << std::endl;
        std::cout << "\t>     1: Infix to postfix" << std::endl;
    }

    return 0; 
}