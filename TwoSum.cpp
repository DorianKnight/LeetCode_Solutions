class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* Solution description:
         *
         * Pick the element at index 0, if less than target pick element at index 1. If index 0 and 1 
         * add up to the target, return the indices. If not, keep number at index 0 and pick number 
         * at index 2. If all indicies have been exhaused with index 0, discard index zero, pick index 
         * 1 and only check if the target is met with indicies after 1 as the combination
         * of 0 and 1 is already has been proven to not work.
         */
        for (int i = 0; i<(nums.size() - 1); i++)
        {
            int firstNum = nums.at(i);
            
            for (int j = i+1; j<nums.size(); j++)
            {
                int secondNum = nums.at(j);
                if (secondNum + firstNum == target)
                {
                    // Declar vector and push indices onto data structure
                    vector<int> returnVal;
                    returnVal.push_back(i);
                    returnVal.push_back(j);
                    return returnVal;
                }
            }
            
        }
        vector<int> failedReturn (0,0);
        return failedReturn;
    }
};