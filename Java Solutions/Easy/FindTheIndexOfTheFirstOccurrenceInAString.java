// Author: Dorian Knight
// Date: December 26th 2024
// Description: Find the index of the first occurrence in a string Java solution
// Rank: Easy

class Solution {
    public int strStr(String haystack, String needle) {
        // Edge case detection
        if (needle.length() > haystack.length()) {
            // Needle can't be contained within the haystack becuase the haystack is smaller than the needle
            return -1;
        }
        int haystackIterator = 0;
        int substringIterator = 0;
        char haystackCompare;
        int endOfMatch = 0;
        int startOfMatch = 0;

        // Loop through the haystack string and find the substring
        while (substringIterator < needle.length() && haystackIterator < haystack.length()) {
            haystackCompare = haystack.charAt(haystackIterator);
            if (haystackCompare == needle.charAt(substringIterator)) {
                // Found part of the substring, increment both iterators until you go through the entire needle
                endOfMatch = haystackIterator;
                haystackIterator++;
                substringIterator++;
            }

            else {
                // Substring was not found in the haystack
                // Reset the haystack iterator to the beginning of the match + 1
                haystackIterator = haystackIterator - substringIterator +1;
                // Reset the substring iterator
                substringIterator = 0;
                startOfMatch = haystackIterator;
            }
        }

        if (endOfMatch - startOfMatch == needle.length() -1){
            // Complete substring was matched
            return startOfMatch;
        }

        else {
            return -1;
        }
    }
}

public class FindTheIndexOfTheFirstOccurrenceInAString {
    public static void main(String[] args) {
        String haystack = "sadbutsad";
        String needle = "sad";
        Solution answerClass = new Solution();
        int answer = answerClass.strStr(haystack, needle);
        System.out.println("Haystack: " + haystack + " Needle: " + needle + "\nAnswer: " + answer);
    }
}
