// Author: Dorian Knight
// Date: December 24th 2024
// Description: Longest common prefix C# solution
// Rank: Easy

public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        // Iterate through each string and see if the first "i" characters match.
        // If yes, keep going, if no, return the greatest common prefix
        string greatest_common_prefix = "";
        int iterator = 0;
        int min_length = 201;

        // Find the shortest word in the list
        foreach(string word in strs) {
            if (word.Length < min_length) {
                min_length = word.Length;
            }
        }

        // Iterate over every index across each word until you get to the last index in the shortest word
        bool compare_successful = true;
        while (iterator < min_length && compare_successful) {
            // Get the character at index "i" to compare against other characters in other strings at index "i"
            // If the comparison is successful then add that character to the prefix string
            char candidate_prefix_char = strs[0][iterator];

            foreach(string word in strs){
                char compare_against = word[iterator];
                if (candidate_prefix_char != compare_against) {
                    compare_successful = false;
                    break;
                }
            }

            if (compare_successful) {
                // String are immutable in C# :(
                greatest_common_prefix = greatest_common_prefix + candidate_prefix_char;
            }

            iterator++;
        }

        return greatest_common_prefix;
    }
}