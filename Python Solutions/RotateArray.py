# Author: Dorian Knight
# Date: December 20th 2024
# Description: Rotate array python solution
# Rank: Medium

class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        array_length = len(nums)

        if k == 0 or array_length == 0:
            # No need to rotate
            return 0

        index_of_interest = 0
        index_in_motion = nums[index_of_interest]

        # Variable to prevent cycling over the same indicies
        start_of_loop = 0

        for i in range(array_length):
            # Take number and move it to index_of_interest + k
            new_index = index_of_interest+(k%array_length)
            # Modulus used to account for shifts that are greater than the array length (ex: k=6 but array len=5 therefore real shift is just 1)

            # Numbers at the end will 'overflow' to the beginning
            if new_index > array_length-1:
                new_index = (index_of_interest+k%array_length) - array_length

            # Insert number at proper spot
            saved_num = nums[new_index]
            nums[new_index] = index_in_motion

            # Break out of for loop if this is the last iteration
            if i == array_length-1:
                break

            # Reset the values for the next loop
            if new_index == start_of_loop and array_length > 1:
                # Algorithm has cycled back to the beginning, offset by 1 to keep algorithm going
                new_index += 1
                saved_num = nums[new_index]
                start_of_loop += 1 # Move the start of the loop

            index_in_motion = saved_num
            index_of_interest = new_index

def main():
    input_array = [1,2]
    rotate_by = 4
    answer = Solution().rotate(input_array, rotate_by)
    print(f"Rotate by: {rotate_by}, Rotated array: {input_array}")


if __name__ == "__main__":
    main()