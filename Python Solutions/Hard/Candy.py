# Author: Dorian Knight
# Date: December 21st 2024
# Description: Candy leetcode question solution
# Rank: Hard

class Solution:
    def candy(self, ratings: list[int]) -> int:
        if len(ratings) == 0:
            # No children therefore no candy
            return 0

        candy_assignment = []

        # You have to find the minimum child in the list and then build the candy distribution around them
        min_rating = (2*10**4) + 1 # Every child will have a lower rating according to the question specifications
        index = 0

        min_rating_positions = []
        for i in range(len(ratings)):
            child_rating = ratings[i]
            if child_rating <= min_rating:
                min_rating = child_rating

        # Find all the indices with the minimum rating
        for i in range(len(ratings)):
            child_rating = ratings[i]
            if child_rating == min_rating:
                min_rating_positions.append(i)

        # Go through all of the minimum rating indices and find which one has the lowest difference with its neighbours
        # To do that, we need to find the maximum difference between its neighbours and find out who has the lowest max difference
        candidate_differences = []
        for candidate_idx in min_rating_positions:
            candidate_starting_point_rating = ratings[candidate_idx]

            left_neighbour_rating = ratings[candidate_idx-1] if candidate_idx > 0 else 0
            right_neighbour_rating = ratings[candidate_idx+1] if candidate_idx < len(ratings)-1 else 0

            diff_left = left_neighbour_rating - candidate_starting_point_rating
            diff_right = right_neighbour_rating - candidate_starting_point_rating

            max_diff = max(diff_left, diff_right)
            candidate_differences.append([candidate_idx, max_diff])

        # Find the candidate with the lowest max difference and start building the distribution around that candidate
        min_diff = (2*10**4) + 1
        for candidate in candidate_differences:
            if candidate[1] < min_diff:
                min_diff = candidate[1]
                index = candidate[0]

        candy_assignment = [[min_rating, 1]] # Lowest rated child gets one candy

        # Build the candy distribution to the left of the minimal rating
        for j in range(index-1,-1,-1):
            current_child_rating = ratings[j]
            current_child_candy = [current_child_rating,1]
            right_child_rating = ratings[j+1]
            right_child_candy = candy_assignment[0][1] # First index

            if current_child_rating > right_child_rating:
                current_child_candy[1] = right_child_candy + 1

            candy_assignment.insert(0, current_child_candy)

        # Build the candy distribution to the right of the minimal rating
        for k in range(index+1,len(ratings)):
            current_child_rating = ratings[k]
            current_child_candy = [current_child_rating,1]
            left_child_rating = ratings[k-1]
            left_child_candy = candy_assignment[-1][1] # Last index

            if current_child_rating > left_child_rating:
                current_child_candy[1] = left_child_candy + 1

            candy_assignment.append(current_child_candy)

        # Check that the candy count is correct
        correct_assignment = False
        while correct_assignment == False:
            correct_assignment = True  # Switch to false if an error is found

            # Check the right neightbour of the left most child
            if len(ratings) > 1:
                if candy_assignment[1][0] > candy_assignment[0][0] and candy_assignment[1][1] <= candy_assignment[0][1]:
                    candy_assignment[1][1] = candy_assignment[0][1] + 1

            for i in range(1,len(candy_assignment)-1):
                left_neighbour = candy_assignment[i-1]
                right_neighbour = candy_assignment[i+1]
                current_child = candy_assignment[i]

                if left_neighbour[0] > current_child[0] and left_neighbour[1] <= current_child[1]:
                    # If the left neightbour has a higher rating but the same or less candy, increase the candy count of the left neighbour
                    left_neighbour[1] = current_child[1] + 1
                    correct_assignment = False

                elif right_neighbour[0] > current_child[0] and right_neighbour[1] <= current_child[1]:
                    right_neighbour[1] = current_child[1] + 1
                    correct_assignment = False

            # Check the left neighbour of the right most child
            if len(ratings) > 1:
                if candy_assignment[-2][0] > candy_assignment[-1][0] and candy_assignment[-2][1] <= candy_assignment[-1][1]:
                    candy_assignment[-2][1] = candy_assignment[-1][1] + 1

        # Count all the candy assigned in the dictionary
        candy_count = 0
        for individual_candy_assignment in candy_assignment:
            candy_count += individual_candy_assignment[1]

        return candy_count

def main():
    rating_input = [29,51,87,87,72,12]
    print(f"Rating input: {rating_input}")
    answer = Solution().candy(rating_input)
    print(f"The minimum amount of candies is: {answer}")

if __name__ == "__main__":
    main()