/* Solution description:
 * 
 * Check if the string length is 1, if so, the max substring length is 1
 * Check if the string length is 0, if so, the max substring length is 0
 *
 * If length is neither 0 or 1, then pick the first character in s and add it to the substring of interest
 * Continue to add characters into the substring of interest until you find that the candidate character
 * is a duplicate of one of the characters that is already in the substring.
 *
 * When you find a duplicate, break out of the for loop and see if the length of the substring of interest
 * is greater than the maximum length found. Update the max value as necessary
 * 
 * Start a new substring of interest at the next character (if originally index 0, now move to index 1) and
 * repeat process until you've iterated through the entire string.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_substring_length = 0;
        if (s.length() == 1)
        {
            max_substring_length = 1;
        }
        else if (s.length() > 0 && s.length() != 1)
        {
            for (int i=0; i<s.length()-1; i++)
            {
                // Gets first string in the substring
                string substring_of_interest;
                substring_of_interest.push_back(s[i]);

                for (int j=i+1; j<s.length(); j++)
                {
                    char char_candidate = s[j];
                    bool duplicate = false;
                    // Search for char_candidate in substring_of_interest
                    for (int k=0; k<substring_of_interest.length(); k++)
                    {
                        if (char_candidate == substring_of_interest[k])
                        {
                            duplicate = true;
                            break;
                        }
                    }

                    if (duplicate)
                    {
                        // If char_candidate is a duplicate, this substring is complete
                        break;
                    }
                    else
                    {
                        // If char_candidate is not a duplicate, add it to the substring of interest
                        substring_of_interest.push_back(char_candidate);
                    }
                }

                // Compute the length and see if this is the largest substring
                int length_of_interest = substring_of_interest.length();
                if (length_of_interest > max_substring_length)
                {
                    max_substring_length = length_of_interest;
                }
            }
        }
        return max_substring_length;
    }
};