#include "functions.h"

/**
* Functions used to get user input, balance symbols, and
* convert infix to postfix.
* 
* @author Edric Lin
* @version 2/23/2018
*/

/**
* Takes as input a string of arbitrary length. It checks 
* the entire file to determine if there is a closing 
* parenthesis, square bracket, and curly brace for every 
* corresponding opening symbol.
*
* @param input the string to balance
* @return whether or not the string is balanced
*/
bool balancedSymbols(std::string input) {

    std::stack<char, std::deque<char>> symbols;

    for (std::string::iterator it = input.begin(); it != input.end(); it++) { // http://www.cplusplus.com/reference/string/string/begin/
        if (*it == '(' || *it == '[' || *it == '{') {
            symbols.push(*it);
        }

        if (*it == ')' || *it == ']' || *it == '}') {
            if (symbols.empty()) {
                return false;
            }
            symbols.pop();
        }
    }

    return symbols.empty();
}

/**
* Takes as input a valid infix expression and returns the 
* corresponding postfix expression.
*
* @param input the string to convert to postfix
* @return the converted postfix string
*/
std::string iToP(std::string input) {

    // stack to temporarily hold operations and '('
    std::stack<char, std::deque<char>> operations;

    // string to hold final output
    std::string output;

    //iterate through string characters
    for (std::string::iterator it = input.begin(); it != input.end(); it++) { // http://www.cplusplus.com/reference/string/string/begin/

        // if character is an operation
        if (isOperator(*it)) {

            // write stack operations to output until top has less weight than current operation
            while (!operations.empty() && (getWeight(*it) <= getWeight(operations.top()))) {
                output += operations.top();
                operations.pop();
            }

            // add current operation to stack
            operations.push(*it);
        }

        // if character is a '('
        else if (*it == '(') {
            operations.push(*it);
        }

        // if character is a ')'
        else if (*it == ')') {

            // pop operations into output until '('
            while (operations.top() != '(') {
                output += operations.top();
                operations.pop();
            }

            // pop the '('
            operations.pop();
        }

        // else character is an operand
        else {

            // append char directly to output
            output += *it;
        }
    }

    // after input iteration is finished, append remaining stack operations
    while (!operations.empty()) {
        output += operations.top();
        operations.pop();
    }

    return output;
}

/**
* Check if a character is an operator symbol (i.e. if
* its a '+', '-', '*', or '/').
*
* @param c the character to check
* @return whether the character is an operation
*/
bool isOperator(char c) {

    // array of possible operations
    char symbols[4] = {'+', '-', '*', '/'};

    // check if char is an operation
    for (int i = 0; i < 4; i++) {
        if (symbols[i] == c) {
            return true;
        }
    }

    // return false if no operation match
    return false;
}

/**
* Returns the weight of a operation. Returns -1 if not
* an operation.
*
* @param c the character to weigh
* @return the weight of the character operation
*/
int getWeight(char c) {

    // add and subtract lowest weight
    if (c == '+' || c == '-') {
        return 0;
    }

    // multiply and divide highest wieght
    if (c == '*' || c == '/') {
        return 1;
    }

    // not an operation, return -1
    return -1;
}

/**
* Attemps to load a input from a user specified
* file into a string.
*
* @param filename the name of the file to load
* @return the string that was loaded
*/
std::string loadInput(std::string filename) {

    // input to return
    std::string input;

    // read input from file
    std::ifstream myfile (filename);

    // if file is able to be opened
    if (myfile.is_open()) {

        // read line
        std::string line;
        while (std::getline(myfile, line)) {
            input += line;
        }
        myfile.close();
    }

    // error opening file
    else {
        std::cout << "\t> Unable to open file." << std::endl; 
    }

    return input;
}