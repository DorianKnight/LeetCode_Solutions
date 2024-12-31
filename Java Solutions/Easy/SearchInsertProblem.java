// Author: Dorian Knight
// Date: December 31st 2024
// Description: Search Insert Problem.java
// Rank: Easy

class Solution {
    public int searchInsert(int[] nums, int target) {
        int searchVal = nums.length;
        for (int i=0; i<nums.length; i++) {
            int candidate = nums[i];
            if (candidate >= target) {
                searchVal =  i;
                break;
            }
        }
        return searchVal;
    }
}