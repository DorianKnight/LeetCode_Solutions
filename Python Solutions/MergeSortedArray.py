# Author: Dorian Knight
# Date: December 17th 2024
# Description: Merge Sorted Array Solution
# Rank: Easy

class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        numbersMerged = m
        for mergeNum in nums2:
            # Find where mergeNum should fit in nums1
            mergedNum = False
            for i in range(len(nums1)):
                # Iterate through nums1 to find spot
                checkNum = nums1[i]
                if checkNum > mergeNum:
                    nums1.insert(i, mergeNum)
                    mergedNum = True
                    numbersMerged += 1
                    break

            if mergedNum == False:
                # Iterated through the complete list and no suitable place was found
                # Therefore, insert at the end of valid list
                nums1.insert(numbersMerged, mergeNum)
                numbersMerged += 1


        # Iterate through nums1 and remove trailing zeroes
        i = 0
        while i < len(nums1):
            if i >= m+n and nums1[i] == 0:
                del nums1[i]
            else:
                i += 1


def main():
    input1 = [1,2,3,0,0,0]
    m=3
    input2 = [2,5,6]
    answer = Solution().merge(input1, m, input2, len(input2))
    print(f"Output: {input1}")

if __name__ == "__main__":
    main()