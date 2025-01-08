// Author: Dorian Knight
// Date: January 8th 2025
// Description: Count Prefix and Suffix Pairs I
// Rank: Easy

#include <stdbool.h>

int countPrefixSuffixPairs(char** words, int wordsSize) {
    char* preSuffCandidate;
    char* preSuffCandidateNull;
    char* template;
    char* templateNull;
    char** wordsIterator = words;
    char** templateIterator;
    bool isPrefix;
    bool isSuffix;
    int preSuffCandidateSize;
    int templateSize;
    int prefixSuffixPairs = 0;
    for (int i=0; i<wordsSize-1; i++) {
        preSuffCandidate = *wordsIterator;
        preSuffCandidateNull = preSuffCandidate;
        templateIterator = (wordsIterator+1);

        // Find the end of the string
        while (*preSuffCandidateNull != '\0') {
            preSuffCandidateNull++;
        }

        for (int j=i+1; j<wordsSize; j++) {
            template = *templateIterator;
            templateNull = template;

            // Find the end of the strings
            while (*templateNull != '\0') {
                templateNull++;
            }

            // Check if template is larger than candidate
            preSuffCandidateSize = (int)(preSuffCandidateNull-preSuffCandidate);
            templateSize = (int)(templateNull - template);
            if (templateSize >= preSuffCandidateSize) {
                // Check if the preSuffCandidate is a prefix and a suffix for the template
                isPrefix = true; // Prove
                isSuffix = true; // Prove
                for (int k=0; k<(preSuffCandidateNull-preSuffCandidate); k++) {
                    // Check prefix
                    if (*(preSuffCandidate+k) != *(template+k)) {
                        isPrefix = false;
                    }

                    // Check suffix
                    if (*(preSuffCandidateNull-1-k) != *(templateNull-1-k)) {
                        isSuffix = false;
                    }
                }

                if (isPrefix && isSuffix) {
                    prefixSuffixPairs++;
                }
            }

            templateIterator++; // Advance to next word
        }
        wordsIterator++; // Advance to next word
    }

    return prefixSuffixPairs;
}
