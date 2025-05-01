// Author: Dorian Knight
// Date: January 13th 2025
// Description: Plus One C solution
// Rank: Easy
// Topics: Array || Math

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int num;
    int carryBit = 0;
    *returnSize = digitsSize; // This may be updated in case of overflow

    int index = digitsSize-1;
    bool firstTimeThrough = true;

    // Start at end and continue moving until most significant digit has been reached
    do {
        num = *(digits + index);

        // Add one or carrybit
        if (firstTimeThrough) {
            num++;
            firstTimeThrough = false;
        }

        else {
            num += carryBit;
            carryBit = 0; // Reset carry bit
        }

        // Check for overflow
        if (num == 10) {
            num = 0;
            carryBit = 1;
        }

        // Update the number at the appropriate index
        *(digits + index) = num;

        index--;
    } while (carryBit == 1 && index >= 0);

   // If carry bit is still one we need to create a new array with the correct number
   if (carryBit == 1) {
        int* expandedNums = (int*)malloc(sizeof(int)*(digitsSize+1));
        *expandedNums = 1; // Add carry bit to blank spot
        carryBit = 0;

        // Copy over the rest of the num array
        for (int i=0;i < digitsSize; i++) {
            *(expandedNums + i + 1) = *(digits + i);
        }

        // Reset digit pointer to head of new array
        digits = expandedNums;

        // Update return size to correct value
        *returnSize = digitsSize+1;
   }

   return digits;
}
