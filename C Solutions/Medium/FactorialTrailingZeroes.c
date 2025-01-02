// Author: Dorian Knight
// Date: January 2nd 2025
// Description: Factorial Trailing Zeroes C solution
// Rank: Medium

int trailingZeroes(int n) {
    int zeros = 0;
    while (n>=5) {
        n /= 5;
        zeros += n;
    }

    return zeros;
}