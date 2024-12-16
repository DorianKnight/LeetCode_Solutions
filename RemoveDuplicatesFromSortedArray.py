class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        compare_num = -101 # Outside of number range according to Leetcode question specs
        unique_nums = 0
        i = 0

        # Iterate through the list, check for duplicates and if found, delet the duplicate
        while i < len(nums):
            if nums[i] != compare_num:
                unique_nums += 1
                compare_num = nums[i]
                i += 1  # Advance to the next number
            else:
                del nums[i]
                # Don't advance to the next number, re-evaluate the same index
        return unique_nums

def main():
    input_nums = [0,0,0,1,1,1,2,2,2,3,3,3]
    dupsRemoved = Solution()
    answer = dupsRemoved.removeDuplicates(input_nums)
    print(f"Output: {answer}")

if __name__ == "__main__":
    main()