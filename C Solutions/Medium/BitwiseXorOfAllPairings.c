// Author: Dorian Knight
// Date: January 16th 2025
// Description: Bitwise Xor of all pairings C solution
// Rank: Medium
// Topics: Array || Bit manipulation || Brainteaser


int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    /** Thought process:
     *  2 XOR 2 = 0
     *  2 XOR 2 XOR 2 = 2
     *
     *  Applying XOR to the same thing twice results in a value of zero
     *  Applying XOR to the same thing an odd number of times is equivalent to the original number
     *
     *  These two statements are equivalent:
     *  2 XOR 5 XOR 2 XOR 10
     *  5 XOR 10
     *
     *  This example above can be represented as follows
     *  nums1 = [2]
     *  nums1Size = 1
     *
     *  nums2 = [5, 10]
     *  nums2Size = 2
     *
     *  Taking this pattern further we can see four scenarios
     *  Scenario 1: nums1 is even and nums2 is even
     *  Scenario 2: nums1 is even and nums2 is odd
     *  Scenario 3: nums1 is odd and nums2 is even
     *  Scenario 4: nums1 is odd and nums2 is odd
     *
     *  Scenario 1: return zero as each number will appear an even amount of times
     *  Scenario 2: XOR all elements in nums1 as they will appear an odd number of times while nums2 will appear and even number of times and cancel out to zero
     *  Scenario 3: XOR all elements in nums2 because it's the reverse of scenario 2
     *  Scenario 4: XOR all elements as they all appear an odd number of times
     */

    int xorResult = 0;

    if (nums1Size%2 == 1 && nums2Size%2 == 1) {
        // Scenario 4: everything appears an odd number of times
        for (int i=0; i<nums1Size; i++) {
            xorResult ^= *(nums1 + i);
        }

        for (int j=0; j<nums2Size; j++) {
            xorResult ^= *(nums2 + j);
        }
    }

    else if (nums1Size%2 == 0 && nums2Size%2 == 0) {
        // Scenario 1: Everything appears an even number of times
        // Do nothing, result is already zero
    }

    else if (nums1Size%2 == 1) {
        // Scenario 3: Nums1 is odd while nums2 is even resulting in nums2 values showing up an odd number of times
        for (int j=0; j<nums2Size; j++) {
            xorResult ^= *(nums2 + j);
        }
    }

    else {
        // Scenario 2: Nums1 is even while nums2 is odd resulting in nums1 values showing up an odd number of times
        for (int i=0; i<nums1Size; i++) {
            xorResult ^= *(nums1 + i);
        }
    }
    return xorResult;
}



// Brute force solution

int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int operandOne;
    int operandTwo;
    int result = 0;

    // Iterate over both arrays and xor all results
    for (int i=0; i<nums1Size; i++) {
        operandOne = *(nums1 + i);

        for (int j=0; j<nums2Size; j++) {
            result ^= operandOne;
            operandTwo = *(nums2 + j);
            result ^= operandTwo;
        }
    }

    return result;
}
