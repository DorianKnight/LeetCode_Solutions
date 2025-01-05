// Author: Dorian Knight
// Date: January 5th 2025
// Description: Jump game II C++ solution
// Rank: Medium

class Solution {
public:
    int jump(vector<int>& nums) {
        // Take current index and 'look ahead' as far as possible
        // Find max number, move to that index and repeat the process until you reach the end
        int iterator = 0;
        int jumpCount = 0;
        while (iterator < nums.size()-1) {
            int lookAheadDist = nums[iterator];
            if (lookAheadDist + iterator >= nums.size()-1) {
                // Can jump straight to the end
                jumpCount++;
                return jumpCount;
            }
            int maxNextJump = -1;
            int maxNextJumpIdx = -1;
            for (int lookAheadIdx=iterator+1; lookAheadIdx<=iterator+lookAheadDist; lookAheadIdx++) {
                if ((nums[lookAheadIdx] + lookAheadIdx) >= (maxNextJump + maxNextJumpIdx)) {
                    // Take the jump that gets you the furthest
                    maxNextJump = nums[lookAheadIdx];
                    maxNextJumpIdx = lookAheadIdx;
                }
            }
            iterator = maxNextJumpIdx;
            jumpCount++;
        }
        return jumpCount;  
    }
};