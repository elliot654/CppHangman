#include <iostream>
#include <cstdlib>
#include <string>
#include<ctime>
#include <fstream>
using namespace std;



const int max_tries = 10;

int letterFill(char guess, string secretword, string& guessword) {
    int i;
    int matches = 0;
    int length = secretword.length();

    for (i = 0; i < length; i++) {
        if (guess == guessword[i]) {
            return 0;
        }
        if (guess == secretword[i]) {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

int main(int argc, char** argv) {

    int num_wrong = 0;
    char letter;
    string word;//the word to guess
    string words[65000];
    ifstream file("words.txt");
    if (file.is_open()) {
        for (int i = 0; i < 65000; ++i) {
            file >> words[i];
        }
    }

    //set a random word
    srand(time(NULL));
    int n = rand() % 65000;
    word = words[n];

    string unknown(word.length(), '*');

    while (num_wrong < max_tries) {
        cout << unknown << endl;
        cout << "guess a letter" << endl;
        cin >> letter;

        if (letterFill(letter, word, unknown) == 0) {
            cout << "nope" << endl;
            num_wrong++;
        }
        else {
            cout << "good guess" << endl;
        }
        cout << "you have " << (max_tries - num_wrong) << " guesses left" << endl;
        if (word == unknown) {
            cout << "you win the word was " << word;
            break;
        }
    }
    if (num_wrong == max_tries) {
        cout << "you lose the word was " << word;
    }
    return 0;
}

