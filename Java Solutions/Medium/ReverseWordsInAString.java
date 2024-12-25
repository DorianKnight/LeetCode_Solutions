// Author: Dorian Knight
// Date: December 25th 2025
// Description: Reverse Words in a String Java solution
// Rank: Medium

class Solution {
    public String reverseWords(String s) {
        int stringLength = s.length();
        String reversedWord = "";
        char spaceChar = ' ';

        // Two pointer solution to isolate words
        int lftPtr;
        int rhtPtr;
        int iterator = stringLength-1;
        while (iterator >= 0) {
            lftPtr = iterator-1;
            rhtPtr = iterator;

            // Check that the right pointer is at a character then proceed to move the left pointer until you hit a whitespace
            if (s.charAt(rhtPtr) != spaceChar) {
                // Begin moving the left pointer until you hit a space
                while (lftPtr >= 0 && s.charAt(lftPtr) != spaceChar) {
                    lftPtr--;
                }
                reversedWord += s.substring(lftPtr+1, rhtPtr+1);
                reversedWord += " "; // Add a space so the next word isn't connected

                // Reset iterator
                iterator = lftPtr;
            }

            else {
                // Right pointer was at a space, decrement iterator
                iterator--;
            }
        }
        return reversedWord.substring(0, reversedWord.length()-1);  // Remove trailing whitespace
    }
}

public class ReverseWordsInAString {
    public static void main (String[] args) {
        Solution answerClass = new Solution();
        String stringToReverse = "the sky is blue";
        String answer = answerClass.reverseWords(stringToReverse);
        System.out.println("Input: " + stringToReverse + "\nOutput: " + answer);
    }
}
