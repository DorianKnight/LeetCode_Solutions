// Author: Dorian Knight
// Date: December 28th 2024
// Description: H-Index Java solution
// Rank: Medium

class Solution {
    public int hIndex(int[] citations) {
        // Use bubble sort to sort in "non-ascending" order
        boolean sorted = false;
        while (!sorted) {
            sorted = true; // Prove this
            for (int i=0; i<citations.length-1; i++){
                int ptrVal = citations[i];
                int nxtVal = citations[i+1];

                if (nxtVal > ptrVal) {
                    // Swap
                    citations[i] = nxtVal;
                    citations[i+1] = ptrVal;
                    sorted = false;
                }
            }
        }

        // With sorted array, find the maximum square area
        int h_index = 0;
        for (int i=0; i<citations.length; i++){
            if (i+1<=citations[i]) {
                h_index = i+1;
            }
            else {
                break; // Save unnecessary iterations
            }
        }

        return h_index;
    }
}