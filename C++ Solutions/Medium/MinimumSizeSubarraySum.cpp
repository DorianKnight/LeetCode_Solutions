// Author: Dorian Knight
// Date: January 3rd 2025
// Description: Minimum Size Subarray Sum C++ solution
// Rank: Medium

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minWindowSize = 100001; // More than the maximum window array length
        int lftPtr = 0;
        int rhtPtr = 0;
        int windowSum = nums[0];
        bool solutionFound = false;

        while (rhtPtr < nums.size()-1) {
            if (windowSum >= target) {
                // The window meets the condition, check size to see if it's minimum
                int windowSize = rhtPtr - lftPtr + 1;
                if (windowSize < minWindowSize) {
                    minWindowSize = windowSize;
                    solutionFound = true;
                }

                // Window meets criteria, try to find minimal window size by advancing left pointer
                windowSum -= nums[lftPtr];
                lftPtr++;
            }

            else {
                // Window doesn't meet criteria so expand window to get closer to target
                rhtPtr++;
                windowSum += nums[rhtPtr];

            }
        }

        // Check if there is an answer
        if (windowSum < target && !solutionFound) {
            // The entire array doesn't add up to the target
            return 0;
        }

        while (rhtPtr - lftPtr >= 0) {
            // Right pointer has reached the end of the list but window may still be shrunk
            if (windowSum >= target) {
                int windowSize = rhtPtr - lftPtr + 1;
                if (windowSize < minWindowSize) {
                    minWindowSize = windowSize;
                }

                windowSum -= nums[lftPtr];
                lftPtr++;
            }

            else {
                break;
            }
        }

        return minWindowSize;
    }
};