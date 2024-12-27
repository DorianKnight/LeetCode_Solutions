// Author: Dorian Knight
// Date: December 27th 2024
// Description: Valid Palindrome Java solution
// Rank: Easy

import java.util.regex.Pattern;

class Solution {
    public boolean isPalindrome(String s) {
        String lowerCaseS = s.toLowerCase();  // Convert to lower case

        // Reverse the string and remove punctuation from input string
        String forwardString = "";
        String reversedString = "";

        // Generate regular expression for all alphanumeric characters
        String alphaNumRegex = "[a-z0-9]";

        for (int i=s.length()-1; i>-1; i--) {
            String charToInspect = "";
            charToInspect += lowerCaseS.charAt(i);
            
            if (charToInspect.matches(alphaNumRegex)) {
                // Character is alphanumeric
                reversedString += lowerCaseS.charAt(i);
                forwardString = lowerCaseS.charAt(i) + forwardString;
            }
            
        }

        // Iteratre through both strings to see if they are equivalent
        for (int i=0; i<forwardString.length(); i++) {
            if (forwardString.charAt(i) != reversedString.charAt(i)){
                return false;
            }
        }
        return true;
    }
}

public class ValidPalindrome {
    public static void main(String[] args) {
        String input_string = "racecar";
        Solution answerClass = new Solution();
        boolean answer = answerClass.isPalindrome(input_string);
        System.out.println("Input: " + input_string + "\nPalindrome?: " + answer);
    }
}
