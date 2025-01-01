// Author: Dorian Knight
// Date: January 1st 2025
// Description: Add Binary C# solution
// Rank: Easy

public class Solution {
    public string AddBinary(string a, string b) {
        int aLen = a.Length;
        int bLen = b.Length;
        int biggerLen;
        int smallerLen;
        string sum = "";
        string biggerStr;
        string smallerStr;

        if (aLen >= bLen) {
            biggerLen = aLen;
            smallerLen = bLen;
            biggerStr = a;
            smallerStr = b;
        }

        else {
            smallerLen = aLen;
            biggerLen = bLen;
            smallerStr = a;
            biggerStr = b;
        }

        int carry = 0;
        int delta = biggerLen - smallerLen;
        int bitSum;
        // Iterate on both strings from right to left
        for (int i=smallerLen-1; i>=0; i--){
            bitSum = (biggerStr[i+delta] - '0') + (smallerStr[i] - '0') + carry;  // Char subtraction to convert char to int
            carry = 0; // Reset the carry bit

            if (bitSum == 2) {
                carry = 1;
                bitSum = 0;
            }

            else if (bitSum == 3) {
                carry = 1;
                bitSum = 1;
            }

            // Add bitSum to string
            sum = bitSum.ToString() + sum;
        }

        if (delta > 0) {
            // Add carry bit through larger string
            for (int i=delta-1; i>=0; i--) {
                bitSum = (biggerStr[i] - '0') + carry;
                carry = 0; // Reset carry bit

                if (bitSum == 2) {
                    carry = 1;
                    bitSum = 0;
                }

                else if (bitSum == 3) {
                    carry = 1;
                    bitSum = 1;
                }

                sum = bitSum + sum;
            }
        }

        // If there is a remaining carry bit
        if (carry == 1) {
            sum = '1' + sum;
        }

        return sum;
    }
}