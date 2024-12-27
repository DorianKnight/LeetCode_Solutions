// Author: Dorian Knight
// Date: December 27th 2024
// Description: Is Subsequence Java solution
// Rank: Easy

class Solution {
    public boolean isSubsequence(String s, String t) {
        // Iterate through all the chars in the substring to see if they match the full string in order
        int stringIterator = 0;
        boolean matched;
        for (int i=0; i<s.length(); i++){
            matched = false; // Match must be found
            char substringChar = s.charAt(i);
            while (matched == false && stringIterator < t.length()) {
                // Iterate through the complete string until a matched char is found
                char charToInspect = t.charAt(stringIterator);
                
                if (charToInspect == substringChar) {
                    matched = true;
                }
                stringIterator++;
            }
            
            if (!matched){
                // Iterated through the complete string and substring match was not found
                return false;
            }
        }

        return true;
    }
}

public class IsSubsequence {
    public static void main(String[] args) {
        Solution answerClass = new Solution();
        String subsequence = "ace";
        String fullStr = "abcdefg";
        boolean answer = answerClass.isSubsequence(subsequence, fullStr);
    }
}
