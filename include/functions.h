#include <string>
#include <stack>
#include <fstream>
#include <iostream>

/**
* Header file for Game of Life.
* 
* @author Edric Lin
* @author Austin Maley
* @version 2/10/2018
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
bool balancedSymbols(std::string input);

/**
* Takes as input a valid infix expression and returns the 
* corresponding postfix expression.
*
* @param input the string to convert to postfix
* @return the converted postfix string
*/
std::string iToP(std::string input);

/**
* Check if a character is an operator symbol (i.e. if
* its a '+', '-', '*', or '/').
*
* @param c the character to check
* @return whether the character is an operation
*/
bool isOperator(char symbol);

/**
* Returns the weight of a operation. Returns -1 if not
* an operation.
*
* @param c the character to weigh
* @return the weight of the character operation
*/
int getWeight(char c);

/**
* Attemps to load a input from a user specified
* file into a string.
*
* @param filename the name of the file to load
* @return the string that was loaded
*/
std::string loadInput(std::string filename);