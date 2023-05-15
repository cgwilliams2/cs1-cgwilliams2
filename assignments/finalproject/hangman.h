// hangman.h

#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

void initialize();
void readFile();
void game();
void gameRun();
void printMenu();
void printStats();
void gameStart();
void changeDifficulty();
std::string word(int difficulty);
void debug();

#endif
