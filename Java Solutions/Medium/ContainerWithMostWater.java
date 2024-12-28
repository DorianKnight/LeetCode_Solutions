// Author: Dorian Knight
// Date: December 27th 2024
// Description: Container with most water Java solution
// Rank: Medium

class Solution {
    public int maxArea(int[] height) {
        // Two pointer solution
        // Start at both ends of the array and move closer to the center
        // Theorized time complexity O(n)

        int lftPtr = 0;
        int rhtPtr = height.length-1;
        int maxArea = 0;

        while (rhtPtr > lftPtr) {
            int lftHeight = height[lftPtr];
            int rhtHeight = height[rhtPtr];
            int area;

            if (lftHeight < rhtHeight) {
                area = lftHeight * (rhtPtr-lftPtr);
                // Move the pointer mapping to the smaller column
                lftPtr++;
            }

            else {
                area = rhtHeight * (rhtPtr-lftPtr);
                // Move the pointer mapping to the smaller column
                rhtPtr--;
            }

            if (area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
}

public class ContainerWithMostWater {
    public static void main(String args[]) {

    }
}