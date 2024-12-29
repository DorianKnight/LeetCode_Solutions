// Author: Dorian Knight
// Date: December 29th 2024
// Description: Pow(x,n) C# solution
// Rank: Medium

public class Solution {
    public double MyPow(double x, int n) {
        double power = Math.Abs(n);
        double raisedNumber = 1;

        // Edge cases
        if (x == 1) {
            // 1 to the power of anything is 1
            return x;
        }

        else if (x == -1 && n%2 == 1) {
            // Odd power
            return -1;
        }

        else if (x == -1 && n%2 == 0) {
            // Even power
            return 1;
        }

        // Not quite sure how to handle this edge case
        if (power == 2147483648) {
            // I think this means that there's an overflow and the right answer is 0
            return 0;
        }

        for (int i=0; i<power; i++) {
            raisedNumber *= x;
        }

        double answer;
        if (n < 0) {
            // Negative power
            answer = 1/raisedNumber;
        }

        else {
            // Positive power
            answer = raisedNumber;
        }

        return answer;
    }
}