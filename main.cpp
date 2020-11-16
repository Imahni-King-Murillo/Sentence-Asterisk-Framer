#include <iostream>
#include <string>

using namespace std;

/*
Purpose: Frame any inputted string within asterisks
Input: 1 string
Output: void; printed display of framed sentence
Example:
Input = "Hello everybody!"
Output = 
*******
*Hello*
*every*
*body!*
*******
*/
void sentenceFramer(string sentence)
{
    bool wordLoopComplete;
    int firstWordLength;

    // Verifier to cease loop when firstWordLength has been found
    wordLoopComplete = false;
    // int to store length of the first word in sentence
    firstWordLength = 0;

    // Loop to find length of first word in sentence
    for (int index = 0; index < sentence.length(); index++)
    {
        // If the letter isn't NULL and if the word isn't complete
        if (sentence[index] != ' ' && !wordLoopComplete)
            // Add 1 to firstWordLength
            firstWordLength += 1; 
        // If the letter is NULL
        else if (sentence[index] == ' ')
            // The first word is complete
            wordLoopComplete = true;
    } // End of loop

    // Loop to print first row of asterisks
    for (int index = 0; index < (firstWordLength + 2); index++)
        cout << "*";
    // Return line
    cout << endl;

    // Loop to print sentence contents
    for (int indexOne = 0; indexOne < 3; indexOne++)
    {
        // Print asterisk BEFORE the word
        cout << "*";
        // Print firstWordLength letters
        for (int indexTwo = 0; indexTwo < firstWordLength; indexTwo++)
        {
            // If character is not a space
            if (sentence[indexTwo] != ' ')
                // Print letter
                cout << sentence[indexTwo];
        };
        // Print asterisk AFTER the word
        cout << "*" << endl;
    };

    // Loop to print last row of asterisks
    for (int index = 0; index < (firstWordLength + 2); index++)
        cout << "*";
    // Return line
    cout << endl;
}

// Purpose: Prompt user for a string to then input within sentenceFramer on execution
int main()
{
    string prompt;
    string sentence;

    // Design prompt for user
    prompt = "Please enter a single sentence (period optional) : ";

    // Display prompt
    cout  << prompt;
    // Input sentence
    getline(cin, sentence);
    // Execute sentenceFramer using inputted sentence
    sentenceFramer(sentence);
    return 0;
}
