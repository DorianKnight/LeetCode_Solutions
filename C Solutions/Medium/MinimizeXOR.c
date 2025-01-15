// Author: Dorian Knight
// Date: January 15th 2025
// Description: Minimize XOR C solution
// Rank: Medium
// Topics: Greedy || Bit Manipulation

int minimizeXor(int num1, int num2) {
    // Find out how many set bits are required
    int setBitCount = 0;
    int allBits2 = num2;
    while (allBits2 > 0) {
        if (allBits2%2 == 1) {
            // Odd numbers always have their LSB set
            setBitCount++;
        }
        allBits2 >>= 1; // Shift right to check if the bit to the left is set
    }

    /** Thought process:
     *  To minize the XOR result we want to set the same bits that are in num1
     *  If we can't set all the bits, we should prioritize the set bits starting from the left moving to the right
     *
     *  If we set all the bits but still need to set more (num2 has more set bits than num 1)
     *  then we want to set all bits that are zero prioritizing unset bits from the right moving to the left
     */

    // Shift through the first number and find which bits are
    int minimalXorOperand = 0;
    int allBits1 = num1;
    int bitLen;
    int mask;

    while(allBits1 > 0 && setBitCount > 0) {
        // MSB of num1 is set
        // Find what bit num the MSB is and set that in the ret val

        bitLen = (int)log2(allBits1);
        mask = pow(2, bitLen);

        // Set that bit
        minimalXorOperand |= mask;

        // Reset MSB
        allBits1 = allBits1 & (~mask);

        setBitCount--; // Subtract from the set bit count as bit has been set
    }

    // If bits still need to be set, set them from right to left
    // Only set a bit if it is not already set

    int bitVal;
    bitLen = 0;
    while(setBitCount > 0) {
        // Check if bit is set
        mask = pow(2, bitLen);
        bitVal = num1 & mask;

        if (bitVal == 0) {
            // Bit is not set
            minimalXorOperand |= mask;
            setBitCount--;
        }
        bitLen++;
    }

    return minimalXorOperand;
}
