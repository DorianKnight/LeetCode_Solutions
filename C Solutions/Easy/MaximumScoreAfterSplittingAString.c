// Author: Dorian Knight
// Date: January 2nd 2025
// Description: Maximum Score After Splitting A String
// Rank: Easy

int maxScore(char* s) {
    // Iterate through the list and count the total amount of ones
    int totalOnes = 0;
    int iterator = 0;
    char indvScore = s[iterator];
    while (indvScore != '\0') {
        if (indvScore == '1') {
            totalOnes++;
        }
        iterator++;
        indvScore = s[iterator];
    }

    int maxScore = -1;
    int maxScoreIdx = -1;
    int onesOnRight = totalOnes;
    int zeroesOnLeft = 0;
    int score;
    for (int i=0; i<iterator-1; i++) {
        // Iterate until 2nd last index
        if (s[i] == '0') {
            zeroesOnLeft++;
        }
        else if (s[i] == '1') {
            onesOnRight--;
        }

        score = zeroesOnLeft + onesOnRight;
        if (score > maxScore) {
            maxScore = score;
            maxScoreIdx = i;
        }
    }
    return maxScore;
}