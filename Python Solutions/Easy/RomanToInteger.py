# Author: Dorian Knight
# Date: December 15th 2024
# Description: Roman to Integer leetcode python solution
# Rank: Easy

class Solution:
    def romanToInt(self, s: str) -> int:
        # Define each roman numeral with a decimal value
        roman_to_dec = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        decimal_conversion = 0
        i = 0
        while i < len(s)-1:
            # Take the two characters at a time
            char1 = s[i]
            char2 = s[i+1]

            if roman_to_dec[char2] > roman_to_dec[char1]:
                # Subtraction operation happening
                decimal_conversion += (roman_to_dec[char2]-roman_to_dec[char1])

                # Iterate the counter value to skip over char2
                i += 2
            else:
                decimal_conversion += roman_to_dec[char1]
                i += 1
        
        # Add the last roman numeral if it was skipped by the while loop
        if i<len(s):
            decimal_conversion += roman_to_dec[s[-1]]
        return decimal_conversion
    
def main():
    roman_numeral = "MDCXCV"
    solved = Solution()
    answer = solved.romanToInt(roman_numeral)
    print(f"The answer to {roman_numeral} is: {answer}")


if __name__ == "__main__":
    main()