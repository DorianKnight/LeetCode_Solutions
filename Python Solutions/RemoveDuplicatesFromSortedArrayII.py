# Author: Dorian Knight
# Date: December 20th 2024
# Description: Remove duplicates from sorted array 2 python solution
# Rank: Easy

class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        i = 0
        checkNum = nums[i]
        foundCounter = 0
        finalNumCount = 0
        while i < len(nums):
            if nums[i] == checkNum:
                foundCounter += 1      
            else:
                checkNum = nums[i]
                foundCounter = 1

            if foundCounter > 2:
                del nums[i]
            else:
                finalNumCount += 1
                i +=1
        return finalNumCount



def main():
    input_nums = [1,1,1,1,2,2,2,2,3,3,3,3,4,4,4]
    answer = Solution().removeDuplicates(input_nums)
    print(f"Output: Array {input_nums}, k: {answer}")

if __name__ == "__main__":
    main()