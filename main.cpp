#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/**
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
    int sentenceLength;
    int spaceCounter;
    int incrementer;
    int rowNumber;
    // int to hold the length of the inputted sentence
    int inputLength = sentence.length();
    int rowLength;
    int rowRemainder;
    int counter;

    // Verifier to cease loop when firstWordLength has been found
    wordLoopComplete = false;
    // int to store length of the first word in sentence
    firstWordLength = 0;
    // int to hold the length of the spacelessSentence char array
    sentenceLength = 0;
    // int to hold the number of spaces within the inputted sentence
    spaceCounter = 0;
    // int to incremenent index limit of for loop dynamically
    incrementer = 0;
    // int to hold the the number of rows needed to properly display sentence
    rowNumber = 0;
    // int to hold the length of the currently printed row
    rowLength = 0;
    // int to hold the remainder of the firstWordLength minus the rowLength
    rowRemainder = 0;
    // counter to increment the index of the spacelessSentence array according to the parallel contents within the sentence[index]
    counter = 0;

    // Loop to find length of first word in sentence
    for (int index = 0; index < sentence.length(); index++)
    {
        // If the char isn't a space and if the word isn't complete...
        if (sentence[index] != ' ' && !wordLoopComplete)
            // Add 1 to firstWordLength
            firstWordLength += 1; 
        // If the char is a space...
        else if (sentence[index] == ' ')
            // The first word is complete
            wordLoopComplete = true;
    } // End of loop

    // Loop to find number of spaces within the inputted sentence
    for (int index = 1; index < inputLength; index++)
    {
        // if the current char is a space or NULL...
        if (sentence[index] == ' ' || sentence[index] == NULL)
            // increment the spaceCounter by 1
            spaceCounter++;
    } // End of loop

    // char array (the size of the inputted sentence minus the number of spaces in inputted sentence) to hold a sentence void of spaces
    char spacelessSentence[inputLength - spaceCounter];

    // Loop to print first row of asterisks
    for (int index = 0; index < (firstWordLength + 2); index++)
        std::cout << "*";
    // Return line
    std::cout << endl;

    // Loop to create new sentence with no spaces
    for (int index = 0; index < sentence.length(); index++)
    {
        // if the current char isn't a space...
        if (sentence[index] != ' ' && sentence[index] != NULL)
        {
            // Add the char into the spacelessSentence
            spacelessSentence[counter] = sentence[index];
            // Add one to the spacelessSentence index counter
            counter++;
        }
        // if the current char IS a space...
        else if (sentence[index] == ' ' || sentence[index] == NULL)
        {
            // Do NOT increment the spacelessSentence index counter
            counter = counter;
        }
    } // End of loop

    // Calcuate the length of the spacelessSentence char array
    sentenceLength = sizeof(spacelessSentence) / sizeof(spacelessSentence[0]);
    // Create the number of rows for the frame
    rowNumber = ceil(sentenceLength / firstWordLength);

    // Loop to display the sentence in a frame of asterisks
    for (int indexOne = 0; indexOne < rowNumber; indexOne++)
    {
        // Print asterisk BEFORE (to the left of) the word
        std::cout << "*";

        // Loop to print (firstWordLength) characters
        for (int indexTwo = incrementer; indexTwo < (firstWordLength * (indexOne + 1)); indexTwo++)
        {
            // if char is not NULL...
            if (spacelessSentence[indexTwo] != '\0')
                // Print char
                std::cout << spacelessSentence[indexTwo];
            // if the current char isn't a space or NULL...
            if (spacelessSentence[indexTwo] != ' ' && spacelessSentence[indexTwo] != NULL)
                // increment the current rowLength
                rowLength++;
        } // End of nested loop

        // Assign the difference of firstWordLength and rowLength
        rowRemainder = firstWordLength - rowLength;

        // if the rowRemainder is creater than 0...
        if (rowRemainder > 0)
        {
            // Loop to display (rowRemainder) asterisks in the current row
            for (int index = 0; index < rowRemainder; index++)
                std::cout << "*";
        }

        // Print asterisk AFTER (to the right of) the word
        std::cout << "*" << endl;
        // reset the value of rowLength to  0
        rowLength = 0;
        // add (firstWordLength) to the incremeneter
        incrementer += (firstWordLength);
    } // End of MAIN loop

    // Loop to print last row of asterisks
    for (int index = 0; index < (firstWordLength + 2); index++)
        std::cout << "*";
    // Return line
    std::cout << endl;
} // End of sentenceFramer method

// Purpose: Prompt user for a string to then input within sentenceFramer on execution
int main()
{
    // string to hold program prompt
    string prompt;
    // string to hold inputted sentence
    string sentence;

    // Design prompt for user
    prompt = "Please enter a single sentence (period optional) : ";

    // Display prompt
    std::cout  << prompt;
    // Input sentence into program
    getline(cin, sentence);
    // Execute sentenceFramer using inputted sentence
    sentenceFramer(sentence);

    return 0;
} //  End of main method
