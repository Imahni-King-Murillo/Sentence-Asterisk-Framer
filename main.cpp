#include <iostream>
#include <string>
#include <math.h>

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
    double firstWordLength;
    int incrementer;
    double rowNumber = 0;
    int inputLength = sentence.length();
    char spacelessSentence[inputLength];
    int rowLength = 0;
    int rowRemainder = 0;
    int sentenceLength = 0;
    int counter = 0;

    // Verifier to cease loop when firstWordLength has been found
    wordLoopComplete = false;
    // int to store length of the first word in sentence
    firstWordLength = 0;
    // int to incremenent index limit of for loop dynamically
    incrementer = 0;

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
        std::cout << "*";
    // Return line
    std::cout << endl;

    // Loop to create new sentence with no spaces
    for (int index = 0; index < sentence.length(); index++)
    {
        if (sentence[index] != ' ' && sentence[index] != NULL)
        {
            spacelessSentence[counter] = sentence[index];
            counter++;
        }
        else if (sentence[index] == ' ' || sentence[index] == NULL)
        {
            counter = counter;
        }
    };

    sentenceLength = sizeof(spacelessSentence) / sizeof(spacelessSentence[0]);

    // Create the number of rows for the frame
    rowNumber = ceil(sentenceLength / firstWordLength);

    // Loop to display the sentence in a frame
    for (int indexOne = 0; indexOne < rowNumber; indexOne++)
    {
        // Print asterisk BEFORE the word
        std::cout << "*";
        // Print firstWordLength letters
        for (int indexTwo = incrementer; indexTwo < (firstWordLength * (indexOne + 1)); indexTwo++)
        {
            std::cout << spacelessSentence[indexTwo];
            // add firstWordLength letters into a row
            if (spacelessSentence[indexTwo] != ' ' && spacelessSentence[indexTwo] != NULL)
            rowLength++;
        };
        // create an int that holds a remainder
        rowRemainder = firstWordLength - rowLength;
        // if the rmainder is creater than 0
        if (rowRemainder > 0)
        {
            // Loop to print asterisks in the empty row spots
            for (int index = 0; index < rowRemainder; index++)
            {
                std::cout << "*";
            }
        }
        // Print asterisk AFTER the word
        std::cout << "*" << endl;
        // clear the contents inside of the row
        rowLength = 0;
        // add firstWordLength to the incremeneter
        incrementer += (firstWordLength);
    };

    // Loop to print last row of asterisks
    for (int index = 0; index < (firstWordLength + 2); index++)
        std::cout << "*";
    // Return line
    std::cout << endl;
}

// Purpose: Prompt user for a string to then input within sentenceFramer on execution
int main()
{
    string prompt;
    string sentence;

    // Design prompt for user
    prompt = "Please enter a single sentence (period optional) : ";

    // Display prompt
    std::cout  << prompt;
    // Input sentence
    sentence = "Hello world";
    //getline(cin, sentence);
    // Execute sentenceFramer using inputted sentence
    sentenceFramer(sentence);
    return 0;
}
