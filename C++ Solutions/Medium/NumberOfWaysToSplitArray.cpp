// Author: Dorian Knight
// Date: January 3rd 2025
// Description: Number of ways to split array C++ solution
// Rank: Medium

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Iterate through list and calculate total sum
        long totalSum = 0;
        for (int i=0; i<nums.length(); i++) {
            totalSum += nums[i];
        }

        int validSplits = 0;
        long leftSum = 0;
        long rightSum = totalSum;
        // Iterate through list and find all valid splits
        // Splits cannot be empty
        for (int j=0; j<nums.length()-1; j++) {
            leftSum += nums[j];
            rightSum -= nums[j];

            if (leftSum >= rightSum) {
                validSplits++;
            }
        }

        return validSplits;
    }
};