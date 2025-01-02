// Author: Dorian Knight
// Date: January 2nd 2025
// Description: Count Vowel Strings in Ranges C solution
// Rank: Medium

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* queryAnswers = (int*)malloc(sizeof(int)*queriesSize);
    *returnSize = queriesSize; // Used to tell judge how long return array is
    int stringsAnswerKey[wordsSize]; // Contains the number of valid strings up until ith point

    // Iterate over string list and find which strings do and don't have vowels
    int validStringsToThisPoint = 0;
    for (int i=0; i<wordsSize; i++) {
        // Find last character in word
        int nullTermIdx = 0;
        while (words[i][nullTermIdx] != '\0') {
            nullTermIdx++;
        }

        char firstChar = words[i][0];
        char lastChar  = words[i][nullTermIdx-1];

        if ((firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') &&
            (lastChar  == 'a' || lastChar  == 'e' || lastChar  == 'i' || lastChar  == 'o' || lastChar  == 'u')) {
                validStringsToThisPoint++;
        }

        stringsAnswerKey[i] = validStringsToThisPoint;
    }

    int firstWordIndex;
    int lastWordIndex;
    int stringVowelCount;
    // User query list and string answer key to construct the return array
    for (int j=0; j<queriesSize; j++) {
        firstWordIndex = queries[j][0];
        lastWordIndex = queries[j][1];
        if (firstWordIndex > 0) {
            stringVowelCount = stringsAnswerKey[lastWordIndex] - stringsAnswerKey[firstWordIndex-1]; // To include increase on first word index
        }

        else {
            stringVowelCount = stringsAnswerKey[lastWordIndex];
        }
        queryAnswers[j] = stringVowelCount;
    }

    return queryAnswers;
}




// Brute force solution
int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* queryAnswers = (int*)malloc(sizeof(int)*queriesSize);
    *returnSize = queriesSize; // Used to tell judge how long return array is
    int firstWordIndex;
    int lastWordIndex;
    int stringVowelCount;

    for (int i=0; i<queriesSize; i++) {
        // Find out what indices bound the search
        firstWordIndex = queries[i][0];
        lastWordIndex = queries[i][1];
        stringVowelCount = 0;

        // Iterate through string list and find out how many strings meet the question parameters within the bounds
        for (int j=firstWordIndex; j<=lastWordIndex; j++) {
            // Find last character in word
            int nullTermIdx = 0;
            while (words[j][nullTermIdx] != '\0') {
                nullTermIdx++;
            }

            char firstChar = words[j][0];
            char lastChar  = words[j][nullTermIdx-1];

            if ((firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') &&
                (lastChar  == 'a' || lastChar  == 'e' || lastChar  == 'i' || lastChar  == 'o' || lastChar  == 'u')) {
                    stringVowelCount++;
                }
        }

        queryAnswers[i] = stringVowelCount;
    }

    return queryAnswers;
}