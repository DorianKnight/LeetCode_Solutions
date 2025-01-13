// Author: Dorian Knight
// Date: January 13th 2025
// Description: Minimum Length of String After Operations solution C++
// Rank: Medium
// Topics: Hash table || String || Counting

#include <unordered_map>

class Solution {
public:
    int minimumLength(string s) {
        // Create a unordered map to store the frequency of all variables
        unordered_map<string, int> letterFreq;

        string letter;
        int freq = 0;

        for (int i=0; i<s.length(); i++) {
            letter = s.substr(i,1);

            // Get letter frequency from hash map
            if (letterFreq.find(letter) != letterFreq.end()) {
                freq = letterFreq[letter];
            }

            else {
                freq = 0;
            }

            // Add / update element in unordered map
            letterFreq[letter] = ++freq;
        }

        int minCharCount = 0;
        // Iterate through the hashmap to find the miminum number of chars
        /** Thought process:
         *  If there is an odd number of the same letter, we can erase until we only have 1 of that letter left
         *  If there is an even number of the same letter, we can erase until we only have 2 of that letter left
         * 
         *  "abaacbcbb"
         *  a: 3  --> 1
         *  b: 4  --> 2
         *  c: 2  --> 2
         * 
         *  1 + 2 + 2 = 5
         *  Therefore 5 is the minimum number of chars we can have in this string
         */

        for (auto i : letterFreq) {
            if (i.second%2 == 1) {
                // Odd number letter frequency
                minCharCount++;
            }

            else if (i.second%2 == 0) {
                // Even number letter frequency
                minCharCount += 2;
            }
        }
        return minCharCount;
    }
};
