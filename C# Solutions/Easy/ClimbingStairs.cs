// Author: Dorian Knight
// Date: December 30th 2024
// Description: Climbing Stairs C# solution
// Rank: Easy

public class Solution {
    public int ClimbStairs(int n) {
        List<int> fibonacci = new List<int>();
        for (int i=0; i<n; i++) {
            if (i == 0) {
                fibonacci.Add(1);
            }

            else if (i == 1) {
                fibonacci.Add(2);
            }

            else {
                fibonacci.Add(fibonacci[i-1] + fibonacci[i-2]);
            }
        }

        return fibonacci[n-1];
    }
}