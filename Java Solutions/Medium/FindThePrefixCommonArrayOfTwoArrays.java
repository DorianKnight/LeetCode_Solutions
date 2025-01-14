// Author: Dorian Knight
// Date: January 14th 2025
// Description: Find the Prefix Common Array of Two Arrays java solution
// Rank: Medium
// Topics: Array || Hash Table || Bit Manipulation

import java.util.HashMap;

class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        HashMap<Integer, Integer> prevNums = new HashMap<Integer, Integer>();
        int[] commonPrefix = new int[A.length];
        // Iterate through both lists A and B, check current characters for commonalities in the hashmap
        int commonInts = 0;
        int aInspect;
        int bInspect;
        for (int i=0; i<A.length; i++) {
            aInspect = A[i];
            bInspect = B[i];

            if (prevNums.get(aInspect) != null) {
                // A[i] was found in the hashmap
                commonInts++;
            }

            else {
                // Add A to hashmap
                prevNums.put(aInspect, 0);
            }

            if (prevNums.get(bInspect) != null) {
                // B[i] was found in the hashmap
                commonInts++;
            }

            else {
                // Add B to hashmap
                prevNums.put(bInspect, 0);
            }

            // Update common prefix array
            commonPrefix[i] = commonInts;
        }

        return commonPrefix;
    }
}