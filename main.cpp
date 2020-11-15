#include <iostream>
#include <string>
using namespace std;

void sentenceFramer(string sentence) {
    // Variable to hold the length of the sentence's first word
    int letterCounter = 0;
    // Variable to hold status of statement activity
    bool statementActive = true;
    // Loop to calculate length of the
    for (int j = 0; j < sentence.length(); j++) {
        if (!isspace(sentence[j]) && statementActive) {
            letterCounter++;
        } else if (isspace(sentence[j])) {
            statementActive = false;
        }
    }
    // loop to counter how many letters there are in the first word
    for (int k = 0; k < letterCounter; k++) {
        cout << "* ";
    }
    cout << endl;
    for (int h = 0; h < sentence.length(); h++) {
        if (sentence[h] == sentence[0]) {
            cout << "* " << sentence[h];
        } else if (sentence[h] != sentence[0] && !isspace(sentence[h])) {
            cout << sentence[h];
        } else if (isspace(sentence[h]) || sentence[h] == sentence[sentence.length()]) {
            cout << sentence[h] << "*" << endl;
        }
    }
    cout << endl;
    for (int k = 0; k < letterCounter; k++) {
        cout << "* ";
    }
}
int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    sentenceFramer(sentence);
    return 0;
}
