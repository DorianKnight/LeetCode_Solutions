// Author: Dorian Knight
// Date: December 29th 2024
// Description: Product of Array Except Self C++ solution
// Rank: Medium

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;

        // Get the answer for the entire list excluding the 0th element
        int zeroCount = 0;
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                // Exclude zeros
                product *= nums[i];
            }

            else {
                zeroCount++;
            }
        }

        int newAddition;
        int finalProduct = product;
        vector<int> exclusiveProduct;
        for (int i=0; i<nums.size(); i++) {
            if (zeroCount > 1 || (zeroCount == 1 && nums[i] != 0)) {
                // Every product will have a 'multiply by zero' in it's product equation
                newAddition = 0;
            }
            else if (nums[i] == 0 && zeroCount == 1) {
                newAddition = finalProduct;
            }

            else if (i > 0) {
                product = product *nums[i-1] * pow(nums[i], -1);  // Pow operation gets around division
                newAddition = product;
            }

            else {
                product = finalProduct * pow(nums[i], -1);
                newAddition = product;
            }
            exclusiveProduct.push_back(newAddition);
        }

        return exclusiveProduct;
    }
};

int main() {

}