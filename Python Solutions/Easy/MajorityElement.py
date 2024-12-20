# Author: Dorian Knight
# Date: December 20th 2204
# Description: Majority element python solution
# Rank: Easy

class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        countTracker = {}
        for num in nums:
            if num not in countTracker:
                # Initialize the number in the tracking dictionary
                countTracker[num] = 1
            else:
                countTracker[num] += 1

        majorityThreshold = len(nums)/2

        # Iterate through the dictionary and extract the majority element
        for key, value in countTracker.items():
            if value > majorityThreshold:
                return key

def main():
    input_nums = [3,2,3]
    answer = Solution().majorityElement(input_nums)
    print(f"Output: {answer}")

if __name__ == "__main__":
    main()