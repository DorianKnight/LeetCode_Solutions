// Author: Dorian Knight
// Date: January 6th 2025
// Description: House Robber C# solution
// Rank: Medium
public class Solution {
    public int Rob(int[] nums) {
        // Keep track of maximum sum as you go along
        if (nums.Length == 1) {
            return nums[0];
        }

        int prevMax = nums[0];
        int currMax;
        if (nums[0] > nums[1]) {
            currMax = nums[0];
        }

        else {
            currMax = nums[1];
        }

        int temp;
        for (int i=2; i<nums.Length; i++) {
            if (prevMax + nums[i] > currMax) {
                temp = prevMax;
                prevMax = currMax;
                currMax = temp + nums[i];
            }

            else {
                prevMax = currMax;
            }
        }
        return currMax;
    }
}