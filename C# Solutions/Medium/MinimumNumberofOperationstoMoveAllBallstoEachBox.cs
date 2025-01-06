// Author: Dorian Knight
// Date: January 6th 2025
// Description: Minimum Number of Operations to Move All Balls to Each Box
// Rank: Medium

public class Solution {
    public int[] MinOperations(string boxes) {
        // Create two lists, one with the number of operations to move all balls to the right and left
        int[] lftOps = new int[boxes.Length];
        int[] rhtOps = new int[boxes.Length];
        int[] minOps = new int[boxes.Length];

        // Count operations for right shift
        int ballCount = 0;
        if (boxes[0] == '1') {
            ballCount = 1;
        }
        for (int i=1; i<boxes.Length; i++) {
            // All previous operations plus the operations from current index
            rhtOps[i] = rhtOps[i-1] + ballCount;

            // Increment ball count if a ball is found in ith box
            if (boxes[i] == '1') {
                ballCount++;
            }
        }

        // Reset ball count
        ballCount = 0;
        if (boxes[boxes.Length-1] == '1') {
            ballCount = 1;
        }
        // Count operations for left shifts
        for (int j=boxes.Length-2; j>=0; j--) {
            lftOps[j] = lftOps[j+1] + ballCount;

            // Increment ball count if a ball is found in ith box
            if (boxes[j] == '1') {
                ballCount++;
            }

            minOps[j] = lftOps[j] + rhtOps[j];
        }

        // Populate the last index in the minimum operations list as it was skipped over in the last for loop
        minOps[boxes.Length-1] = rhtOps[boxes.Length-1];

        return minOps;
    }
}