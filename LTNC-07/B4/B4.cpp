#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string& words) {
    istringstream stream(words);
    vector<string> tokens;
    string token;
    while (getline(stream, token, ';')) {
        tokens.push_back(token);
    }
    return tokens;
}

bool canPlaceWordHorizontally(vector<string>& crossword, string& word, int row, int col) {
    if (col + word.length() > crossword[0].size()) {
        return false;
    }

    for (int i = 0; i < word.length(); i++) {
        if (crossword[row][col + i] != '-' && crossword[row][col + i] != word[i]) {
            return false;
        }
    }

    return true;
}

vector<bool> placeWordHorizontally(vector<string>& crossword, string& word, int row, int col) {
    vector<bool> resetPositions(word.length(), false);
    for (int i = 0; i < word.length(); i++) {
        if (crossword[row][col + i] == '-') {
            crossword[row][col + i] = word[i];
            resetPositions[i] = true;
        }
    }

    return resetPositions;
}

void unplaceWordHorizontally(vector<string>& crossword, vector<bool>& resetPositions, int row, int col) {
    for (int i = 0; i < resetPositions.size(); i++) {
        if (resetPositions[i]) {
            crossword[row][col + i] = '-';
        }
    }
}

bool canPlaceWordVertically(vector<string>& crossword, string& word, int row, int col) {
    if (row + word.length() > crossword.size()) {
        return false;
    }

    for (int i = 0; i < word.length(); i++) {
        if (crossword[row + i][col] != '-' && crossword[row + i][col] != word[i]) {
            return false;
        }
    }

    return true;
}

vector<bool> placeWordVertically(vector<string>& crossword, string& word, int row, int col) {
    vector<bool> resetPositions(word.length(), false);
    for (int i = 0; i < word.length(); i++) {
        if (crossword[row + i][col] == '-') {
            crossword[row + i][col] = word[i];
            resetPositions[i] = true;
        }
    }

    return resetPositions;
}

void unplaceWordVertically(vector<string>& crossword, vector<bool>& resetPositions, int row, int col) {
    for (int i = 0; i < resetPositions.size(); i++) {
        if (resetPositions[i]) {
            crossword[row + i][col] = '-';
        }
    }
}

bool solveCrossword(vector<string>& crossword, vector<string>& wordList, int wordIndex) {
    if (wordIndex == wordList.size()) {
        return true;
    }

    string word = wordList[wordIndex];
    for (int i = 0; i < crossword.size(); i++) {
        for (int j = 0; j < crossword[0].size(); j++) {
            if (canPlaceWordHorizontally(crossword, word, i, j)) {
                vector<bool> resetPositions = placeWordHorizontally(crossword, word, i, j);
                if (solveCrossword(crossword, wordList, wordIndex + 1)) {
                    return true;
                }
                unplaceWordHorizontally(crossword, resetPositions, i, j);
            }

            if (canPlaceWordVertically(crossword, word, i, j)) {
                vector<bool> resetPositions = placeWordVertically(crossword, word, i, j);
                if (solveCrossword(crossword, wordList, wordIndex + 1)) {
                    return true;
                }
                unplaceWordVertically(crossword, resetPositions, i, j);
            }
        }
    }

    return false;
}

vector<string> crosswordPuzzle(vector<string>& crossword, string& words) {
    vector<string> wordList = split(words);
    solveCrossword(crossword, wordList, 0);
    return crossword;
}

int main() {
    vector<string> crossword = {
        "++++++++++",
        "+------+++",
        "+++-++++++",
        "+++-++++++",
        "+++-----++",
        "+++-++-+++",
        "++++++-+++",
        "++++++-+++",
        "++++++-+++",
        "++++++++++"
    };

    string words = "POLAND;LHASA;SPAIN;INDIA";

    vector<string> solvedCrossword = crosswordPuzzle(crossword, words);

    // Print the solved crossword puzzle
    for (const string& row : solvedCrossword) {
        cout << row << endl;
    }

    return 0;
}
