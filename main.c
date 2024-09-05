#include <ctype.h>
#include <stdio.h>

// Main function: Entry point of the program
void main()
{
    int k = 1;		                        // Distance to shift letters in the alphabet
    char userInputFirst, userInputSecond;   // Characters provided by the user to influence shifting
    char inputFileName[30], outputFileName[30];// Input and output file names
    char current;	                     // Current character read from the input file
    int totalCharacters = 0;              // Total number of characters read from the input file
    int totalCharactersChanged = 0;       // Total number of characters that were changed
    int distanceShifted = 0;
    FILE *fp1, *fp2;				// File pointers for input and output files

    printf("Enter the filename to be scanned:  ");	// Prompt user for input file name
    scanf("%s", inputFileName);

    fp1 = fopen(inputFileName, "r");		// Open the input file in read-only mode
    if (fp1 == NULL) {
        printf("Error opening the Input File!\n"); // Error message if file can't be opened
        return;
    }

    printf("Enter the output file name: ");     // Prompt user for output file name
    scanf("%s", outputFileName);
    fp2 = fopen(outputFileName, "w"); // Open output file in write-only mode

    // Prompt user for characters that will influence the shift value
    do {
        printf("Enter the chars that will increment k, they must be digits and/or punctuation marks: ");
        scanf(" %c %c", &userInputFirst, &userInputSecond);
    }
    // Continue prompting until both characters are either digits or punctuation marks
    while (!(isdigit(userInputFirst) || ispunct(userInputFirst)) && 
           (isdigit(userInputSecond) || ispunct(userInputSecond)));

    // Process each character from the input file
    while ((current = getc(fp1)) != EOF)	// Read characters until end of file
    {
        if (k > 5) { k = 1; }                     // Reset k to 1 if it exceeds 5
        
        // Determine base character for alphabet shifting based on case
        char firstAlphabet = isupper(current) ? 'A' : 'a';
        
        // Increment k if the current character matches user inputs
        if (current == userInputFirst || current == userInputSecond) {
            k++;
        } else {
            if (isalpha(current)) { // If current character is an English alphabet letter
                current = (char)(current + k); // Shift the letter by k positions
                distanceShifted+= k;
                // Wrap around if the letter exceeds 'Z' or 'z'
                if (current > firstAlphabet + 25) {
                    current -= 26;
                }
                k++; // Increment k after processing the letter
                totalCharactersChanged++; // Track number of characters changed
            }
            
            // Reset k if the character is a whitespace
            if (current == ' ' || current == '\t' || current == '\n') {
                k = 1;
            }
            
            totalCharacters++; // Track total number of characters read
        }
        
        putc(current, fp2); // Write the processed character to the output file
    }
    double percentLetters = ((double)totalCharactersChanged/totalCharacters)*100;
    double averageDistance = ((double) distanceShifted/totalCharactersChanged);

    fclose(fp1);				// Close the input file
    fclose(fp2);                // Close the output file
    printf("Total characters: %d\n", totalCharacters); // Print total number of characters read
    printf("Characters processed: %d\n", totalCharactersChanged); // Print number of characters changed
    printf("Average distance: %.3f\n", averageDistance);
    printf("Percentage letters: %.3f%%\n", percentLetters);
}
