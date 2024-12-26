// Author: Dorian Knight
// Date: December 25th 2024
// Description: Zigzag conversion Java solution
// Rank: Medium

class Solution {
    public String convert(String s, int numRows) {
        // Edge cases
        if (numRows == 1) {
            return s; // Everything is on one row... that's just the string parameter with no changes.
        }

        // Assign each character with a row in the zigzag pattern
        int zigzagCounter = 1;
        boolean countDescending = true;
        int[][] zigzagArr = new int[s.length()][2];

        for (int i=0; i<s.length(); i++) {

            zigzagArr[i][0] = s.charAt(i);
            zigzagArr[i][1] = zigzagCounter;

            // Check if count should ascend or descend
            if (zigzagCounter == 1) {
                countDescending = true;
            }

            else if (zigzagCounter == numRows) {
                countDescending = false;
            }

            // Increment/decrement the zigzag counter depending on descending boolean
            if (countDescending) {
                zigzagCounter++;
            }

            else {
                zigzagCounter--;
            }

        }

        // Concatenate string in order of row in zigzag pattern
        String zigzagString = "";
        zigzagCounter = 1; // Reset zigzag counter
        while(zigzagCounter <= numRows) {
            // Iterate over each element in the zigzag array and find the characters with the row index matching the zigzag counter    
            for (int i=0; i<s.length(); i++) {
                if (zigzagArr[i][1] == zigzagCounter) {
                    zigzagString += (char)zigzagArr[i][0];
                }
            }
            zigzagCounter++;
        }

        return zigzagString;
    }
}

public class ZigzagConversion {
    public static void main(String[] args) {
        String input_string = "PAYPALISHIRING";
        int numRows = 3;
        Solution answerSolution = new Solution();
        String answer = answerSolution.convert(input_string, numRows);
        System.out.println("Input string: " + input_string + "\nOutput string: " + answer);
    }
}
