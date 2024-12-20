# Author: Dorian Knight
# Date:
# Description: TwoSum solution
# Rank: Easy

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #Iterate through every single combination of numbers to see which one equates to the target
        for i in range(len(nums)-1):
            firstNum = nums[i]
            for j in range(len(nums)-1-i):
                secondNum = nums[j+1+i]
                #print("FirstNum ",firstNum,"\nSecondNum",secondNum)
                if (firstNum + secondNum == target):
                    #print("Got here")
                    return [i,j+1+i]