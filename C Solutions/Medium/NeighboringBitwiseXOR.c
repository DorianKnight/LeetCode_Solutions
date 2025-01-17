// Author: Dorian Knight
// Date: January 17th 2025
// Description: Neighboring Bitwise XOR C solution
// Rank: Medium
// Topics: Array || Bit Manipulation

bool doesValidArrayExist(int* derived, int derivedSize) {
    /**Thought process:
     * Indices i through n-2 tell us how many toggles have happend, index n-1 tells us if the last bit should match the first bit
     * If there have been an even amount of toggles, the last element in the array should match the first element
     * The opposite is also true, if there have been an odd amount of toggles, the last element in the array should be different from the first element
     * 
     * This means that there are two situations where reconstructing the original equation is impossible
     * Scenario 1: When there have been an even number of toggles but the last element should be different from the first element
     * Scenario 2: When there have been an odd number of toggles but the last element should match the first element
     */

    int toggleCount = 0;
    for (int i=0; i< derivedSize-1; i++) {
        // Count the number of toggles up until the second last element
        if (derived[i] == 1) {
            toggleCount++;
        }
    }

    bool retVal = true;
    int lastIndex = derived[derivedSize-1];
    if (toggleCount%2 == 1 && lastIndex == 0) {
        // Scenario 2: Odd number of toggles but first element should match last element
        retVal = false;
    }

    else if (toggleCount%2 == 0 && lastIndex == 1) {
        // Scenario 1: Even number of toggles but first element should be different from last element
        retVal = false;
    }

    return retVal;
}
