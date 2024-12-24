// Author: Dorian Knight
// Date: December 24th 2024
// Description: CPP solution to length of last word
// Rank: Easy

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // Start from end of the list and move backwards until a space is found
        int lastWordLength = 0;
        char space = ' ';
        char null = '\0';
        for (int i=s.length(); i>=0; i--){
            char character = s[i];
            if (character == space && lastWordLength > 0){
                break;
            }
            else if (character != space && character != null){
                cout << "Character " << "{" << character << "}" << " before increment: " << lastWordLength << "\n";
                lastWordLength ++;
            }
        }
        return lastWordLength;
    }
};


int main()
{
    string s = "Hello World";
    int answer = Solution().lengthOfLastWord(s);
    cout << answer;
}