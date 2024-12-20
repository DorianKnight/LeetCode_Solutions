# Author: Dorian Knight
# Date: December 20th 2024
# Description: Remove Element python solution
# Rank: Easy

class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == val:
                del nums[i]
            else:
                i += 1
        return len(nums)

def main():
    input_nums = [3,2,2,3]
    input_val = 3
    answer = Solution().removeElement(input_nums, input_val)
    print(f"Output: {answer}")

if __name__ == "__main__":
    main()