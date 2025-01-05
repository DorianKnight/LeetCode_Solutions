// Author: Dorian Knight
// Date: January 5th 2025
// Description: Shifting Letters II C# solution
// Rank: Medium

public class Solution {
    public string ShiftingLetters(string s, int[][] shifts) {
        // Calculate the net shift for each charater
        int[] netShift = new int[s.Length+1];
        int beginIdx;
        int endIdx;
        int direction; // 1 is positive, 0 is negative
        for (int i=0; i<shifts.Length; i++) {
            beginIdx  = shifts[i][0];
            endIdx    = shifts[i][1];
            direction = shifts[i][2];

            if (direction == 1) {
                // Positive increment
                netShift[beginIdx] += 1;
                netShift[endIdx+1] -= 1;
            }

            else {
                // Negative increment
                netShift[beginIdx] -= 1;
                netShift[endIdx+1] += 1;
            }
        }

        // Apply shift on each character in String
        string shiftedStr = "";
        int currentShift = 0;
        for (int k=0; k<s.Length; k++) {
            char charToShift = s.Substring(k,1).ToCharArray()[0];
            currentShift += netShift[k];
            charToShift = (char)((int)charToShift + currentShift%26);
            if ((int)charToShift < 97) {
                // Wrap around
                int negativeWrap = 97 - (int)charToShift;
                charToShift = (char)(123 - negativeWrap);
            }

            if ((int)charToShift > 122) {
                // Wrap around
                int positiveWrap = (int)charToShift - 122;
                charToShift = (char)(96 + positiveWrap);
            }
            shiftedStr += charToShift.ToString();
        }
        return shiftedStr;
    }
}


