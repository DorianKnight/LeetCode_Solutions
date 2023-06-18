/**
 * Solution description:
 * 
 * Iterate through the string and take all of the alphanumeric characters.
 * After their removal, check that the string read forwards and backwards are the same
 **/

#include <cstring>

class Solution {
public:
    bool isPalindrome(string s) {
        bool ret_val = false;

        // Iterate through the string and extract all alphanumberic characters
        string parsed_string;

        for (int i=0; i<s.length(); i++)
        {
            if (iswalnum(s[i]))
            {
                // Is a character or number
                parsed_string.append(1,tolower(s[i]));
            }
        }

        // Check if the string read forwards and backwards is the same
        string rev_parsed_string = reverseString(parsed_string);

        if (rev_parsed_string == parsed_string)
        {
            ret_val = true;
        }
        return ret_val;
    }

    string reverseString (string forwardString)
    {
        // Custom function to reverse provided string
        string reversedString;

        for (int i=forwardString.length()-1; i>=0; i--)
        {
            reversedString.append(1,forwardString[i]);
        }

        return reversedString;
    }
};