# Author: Dorian Knight
# Date: December 23rd 2024
# Description: Python solution for jump game
# Rank: Medium

class Solution:
    def canJump(self, nums: list[int]) -> bool:
        # Edge case coverage
        if (len(nums) < 2):
            # Can always jump to the end of the list when there is no list
            # Singleton list is always jumpable because the first element is the last element
            return True

        elif (nums[0] == 0):
            # List with a starting zero - can never jump to the end of the list
            return False

        # Initialize left and right pointers at the start of the list
        lft_ptr = 0
        rht_ptr = 1

        while rht_ptr < len(nums)-1:
            jump_to = nums[rht_ptr]
            if jump_to == 0:
                # Stuck, find the point where you need to jump to
                while rht_ptr < len(nums)-1:
                    # If while condition becomes false rht_ptr will be at last index
                    if nums[rht_ptr] == 0:
                        rht_ptr += 1
                    else:
                        break

                # Now rht_ptr is at the index we need to jump to
                # Move the left pointer back until a suitable jump length is found
                jump_found = False
                while lft_ptr >= 0:
                    jump_distance = rht_ptr - lft_ptr
                    if nums[lft_ptr] >= jump_distance:
                        # Jump can be made
                        jump_found = True

                        # Update pointers to begin advancing again
                        lft_ptr = rht_ptr
                        rht_ptr += 1
                        break

                    else:
                        # Move backwards in the list to find a suitable jump
                        lft_ptr -= 1

                if jump_found == False:
                    # Looked back in the left hand side for suitable jump and nothing was found
                    # Jump can not be completed
                    return False

            else:
                # Advance through the list
                rht_ptr +=1
                lft_ptr +=1
        # Parent while loop has completed meaning right pointer has reached the last index and is at the end of the list
        return True

def main():
    input_nums = [3,0,1,0,4]
    answer = Solution().canJump(input_nums)
    print(f"Answer {answer}")

if __name__ == "__main__":
    main()
