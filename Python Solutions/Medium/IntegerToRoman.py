# Author: Dorian Knight
# Date: December 24th 2024
# Description: Integer to Roman Python solution
# Rank: Medium

class Solution:
    def intToRoman(self, num: int) -> str:
        roman_conversion = ""

        while num >= 1000:
            if num - 1000 >= 0:
                roman_conversion += "M"
                num -= 1000

        while num >= 100:
            if num >= 900:
                # Subtractive case
                roman_conversion += "CM"
                num -= 900

            elif num >= 500:
                roman_conversion += "D"
                num -= 500

            elif num >= 400:
                # Subtractive case
                roman_conversion += "CD"
                num -= 400
            else:
                roman_conversion += "C"
                num -= 100

        while num >= 10:
            if num >= 90:
                # Subtractive case
                roman_conversion += "XC"
                num -= 90
            elif num >= 50:
                roman_conversion += "L"
                num -= 50
            elif num >= 40:
                # Subtractive case
                roman_conversion += "XL"
                num -= 40
            else:
                roman_conversion += "X"
                num -= 10

        while num >= 1:
            if num >= 9:
                roman_conversion += "IX"
                num -= 9
            elif num >= 5:
                roman_conversion += "V"
                num -= 5
            elif num >= 4:
                roman_conversion += "IV"
                num -= 4
            else:
                roman_conversion += "I"
                num -= 1

        return roman_conversion

def main():
    input_num = 1695
    answer = Solution().intToRoman(input_num)
    print(f"Integer: {input_num}, roman numeral: {answer}")


if __name__ == "__main__":
    main()