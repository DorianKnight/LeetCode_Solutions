// Author: Dorian Knight
// Date: January 11th 2025
// Description: Construct K Palindrome Strings C++ solution
// Rank: Medium

#include <unordered_map>

class Solution {
public:
    bool canConstruct(string s, int k) {
        // Create a hash map of all letters and how often they apprear
        unordered_map<string, int> letterAppearance;
        for (int i=0; i<s.length(); i++) {
            string inspectSubStr = s.substr(i,1);
            if (letterAppearance.find(inspectSubStr) != letterAppearance.end()) {
                // Letter found, increase frequency count
                letterAppearance[inspectSubStr] = ++letterAppearance[inspectSubStr];
            }

            else {
                // Letter not found, add to unordered map
                letterAppearance[inspectSubStr] = 1;
            }
        }

        int singlesCount = 0;
        int doublesCount = 0;
        int appFreq;
        for (auto kv : letterAppearance) {
            appFreq = kv.second; // Get the appearance frequency
            if (appFreq%2 == 1) {
                singlesCount++;
                appFreq -= 1;
            }

            doublesCount += appFreq/2;
        }

        /**
         * Thought process:
         *
         * There can only be one individual letter per palindrome so if the singles count exceeds the number of palindromes
         * specified by k the return is an automatic false
         *
         * If the number of individual letters is less than the number of palindromes specified by k, the doubles count combined
         * with the singles count needs to equal or exceed the number specified by k, if not, the return value should be false
         * 
         * You can also split doubles into singles so singles + 2*doubles < k = false return
         */

        bool retVal = true;
        if (singlesCount > k) {
            retVal = false;
        }

        else if (singlesCount + 2*doublesCount < k) {
            retVal = false;
        }



        return retVal;
    }
};