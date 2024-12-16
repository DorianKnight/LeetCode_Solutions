# Author: Dorian Knight
# Date: December 16th 2024
# Description: Find the longest common prefix in a list of strings

class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        # Find the shortest word in the list
        min_len = 201 # Maximum length according to the leetcode question specs
        for object in strs:
            if len(object) < min_len:
                min_len = len(object)

        # Iterate over each string in the string list and compare each character across all strings in order
        # strs[0][0] == strs[1][0] == strs[2][0]
        max_prefix_found = False
        max_prefix = ""
        for i in range(min_len):
            if len(strs) == 1:
                # Only one string in the input list
                max_prefix = strs[0]
                return max_prefix

            for j in range(len(strs)-1):
                charCurr = strs[j][i]
                charNext = strs[j+1][i]

                if charCurr != charNext:
                    max_prefix_found = True
                    return max_prefix

            if max_prefix_found == False:
                max_prefix += charCurr
        return max_prefix

def main():
    LCP = Solution()
    input = ["flow", "flower", "flight"]
    input = ["a"]
    answer = LCP.longestCommonPrefix(input)
    print(f"Input: {input} \nOutput: {answer}")

if __name__ == "__main__":
    main()