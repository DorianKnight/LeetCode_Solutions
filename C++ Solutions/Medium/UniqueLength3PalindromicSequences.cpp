// Author: Dorian Knight
// Date: January 4th 2025
// Description: Unique Length-3 Palindromic Sequences C++ solution
// Rank: Medium

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<char> lftLtrHist;
        vector<char> midLtrHist;

        // Pick the letter on the left of the palindrome
        char lftLtr;
        char rhtLtr;
        bool foundInLftHist;
        bool foundInMidHist;
        int palindromeCount = 0;
        for (int lftPtr=0; lftPtr<s.length()-2; lftPtr++) {
            lftLtr = s[lftPtr];
            // Check if the lftLtr has already been selected
            foundInLftHist = false;
            for (int j=0; j<lftLtrHist.size(); j++) {
                if (lftLtr == lftLtrHist[j]) {
                    foundInLftHist = true;
                }
            }

            // Check if left letter is in the history, if not, add it and proceed
            if (!foundInLftHist) {
                lftLtrHist.push_back(lftLtr);

                // Find the left letter on the right side of the string
                int rhtPtr;
                bool matchFound = false;
                for (rhtPtr=s.length()-1; rhtPtr>lftPtr; rhtPtr--) {
                    rhtLtr = s[rhtPtr];
                    if (rhtLtr == lftLtr) {
                        matchFound = true;
                        break;
                    }
                }

                if (matchFound) {
                    // Left and right have been found, iterate between then and find all unique palindromes
                    for (int midPtr = lftPtr+1; midPtr < rhtPtr; midPtr++) {
                        char midLtr = s[midPtr];
                        // Check if the middle letter is unique
                        foundInMidHist = false;
                        for (int k=0; k<midLtrHist.size(); k++) {
                            if (midLtrHist[k] == midLtr) {
                                // Letter is not unique
                                foundInMidHist = true;
                            }
                        }

                        if (!foundInMidHist) {
                            // Letter was not in history and is a valid palindrome
                            palindromeCount++;
                            midLtrHist.push_back(midLtr);
                        }
                    }
                    // Clear mid letter history as the same letters can be used as long as the bookending letters are different
                    midLtrHist.clear();
                }
            }
        }
        return palindromeCount;
    }
};