// Author: Dorian Knight
// Date: January 20th 2025
// Description: 3Sum Java solution
// Rank: Medium
// Topics: Array || Two Pointers || Sorting

import java.util.HashMap;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        // Construct hashmap containing each number and its quantity in the list
        HashMap<Integer, Integer> numQuant = new HashMap<Integer, Integer>();
        HashMap<String, Integer> sumsHist = new HashMap<String, Integer>();
        List<List<Integer>> sumsOfThree = new ArrayList<>();
        int numAtI;
        int quantity;
        for (int i=0; i<nums.length; i++) {
            numAtI = nums[i];
            if (numQuant.containsKey(numAtI)) {
                // Num found in list, increase quantity by 1
                quantity = numQuant.get(numAtI) + 1;
                numQuant.put(numAtI, quantity);
            }
            else {
                // Num not found in list, add it to hashmap
                numQuant.put(numAtI, 1);
            }
        }

        // Use two pointers and check hashmap if missing number is contained in the list
        int lftPtr;
        int rhtPtr;

        int lftVal;
        int rhtVal;

        int missingVal;
        boolean isValid;
        boolean isDuplicate = false;
        int numQty;

        for (lftPtr=0; lftPtr<nums.length-2; lftPtr++) {
            lftVal = nums[lftPtr];
            for (rhtPtr=lftPtr+1; rhtPtr<nums.length-1; rhtPtr++) {
                isValid = false;
                rhtVal = nums[rhtPtr];

                // Calculate value missing to make sum zero and check if it is in hashmap
                missingVal = -1*(lftVal + rhtVal);
                if (numQuant.containsKey(missingVal)) {
                    // Check that you didn't double dip and pick one of the numbers in your list
                    numQty = numQuant.get(missingVal);
                    if ( ((lftVal == missingVal && rhtVal != missingVal) || (lftVal != missingVal && rhtVal == missingVal)) && numQty > 1) {
                        // Missing val isn't unique but there's more than one
                        isValid = true;
                    }

                    else if (lftVal == missingVal && rhtVal == missingVal && numQty > 2) {
                        isValid = true;
                    }

                    else if (lftVal != missingVal && rhtVal != missingVal) {
                        // Missing val is unique
                        isValid = true;
                    }

                    if (isValid) {
                        // Consider adding
                        Integer minVal = Math.min(Math.min(lftVal, missingVal), rhtVal);
                        Integer maxVal = Math.max(Math.max(lftVal, missingVal), rhtVal);
                        Integer midVal = -1*(maxVal + minVal);

                        String threeSumId = minVal.toString() + midVal.toString() + maxVal.toString();
                        if (!sumsHist.containsKey(threeSumId)) {
                            // Not present and valid
                            List<Integer> newAddition = Arrays.asList(lftVal, rhtVal, missingVal);
                            sumsOfThree.add(newAddition);

                            // Add to history
                            sumsHist.put(threeSumId, 1); // One is a dummy value
                        }
                    }
                }
            }
        }

        return sumsOfThree;
    }
}


/* First try at solution on December 27th -  was able to pass 88/313 test cases*/

// Author: Dorian Knight
// Date: December 27th 2024
// Description: 3Sum Java solution
// Rank: Medium

// class Solution {
//     public List<List<Integer>> threeSum(int[] nums) {
//         // Sort the list in ascending order
//         boolean sorted = false;
//         List<List<Integer>> sumOfThree = new ArrayList<>();

//         // Bubble sort
//         while (!sorted){
//             sorted = true; // switch to false once evidence is found
//             for (int i=0; i<nums.length-1; i++) {
//                 int lft = nums[i];
//                 int rht = nums[i+1];

//                 if (rht < lft){
//                     // Swap
//                     nums[i] = rht;
//                     nums[i+1] = lft;
//                     sorted = false;
//                 }
//             }
//         }

//         // Look through sorted array for three numbers that add up to 0
//         boolean verifiedSolutionFound = false;
//         int lft = 0;
//         while (lft<nums.length-2){
//             int lftVal = nums[lft];
//             int mid = lft+1;
//             int midVal = nums[mid];
//             int rht = nums.length-1;
//             int rhtVal = nums[rht];
//             int target = 0-lftVal;
//             boolean targetFound = false;
//             boolean duplicate = false;

//             // Move mid and rht pointers closer to the center until the right numbers are found

//             do {
//                 targetFound = false;
//                 rhtVal = nums[rht];
//                 midVal = nums[mid];
//                 if (midVal + rhtVal > target) {
//                     // Move the rht pointer to the left
//                     rht--;
//                 }

//                 else if (midVal + rhtVal < target) {
//                     // Move the mid pointer to the right
//                     mid++;
//                 }

//                 else {
//                     // Check for duplicates
//                     duplicate = false;
//                     System.out.println("Sum of three size: " + sumOfThree.size());
//                     for (int i=0; i<sumOfThree.size(); i++){
//                         List<Integer> inspectArr = sumOfThree.get(i);
//                         if (inspectArr.get(0) == lftVal) {
//                             if (inspectArr.get(1) == midVal) {
//                                 if (inspectArr.get(2) == rhtVal){
//                                     // Nested because all indices have to be duplicated to switch boolean variable to true
//                                     duplicate = true;
//                                     System.out.println("Duplicate found");
//                                     // Keep iterating
//                                     mid++;
//                                 }
//                             }
//                         }
//                     }
//                     targetFound = true;
//                 }
//                 System.out.println("1: " + (mid < rht && (midVal+rhtVal != target)));
//                 System.out.println("mid: " + mid + " rht: " + rht);
//                 System.out.println("midVal: " + midVal + " rhtVal: " + rhtVal + " Target: " + target);
//                 System.out.println("2: " + (duplicate && (mid < rht)));
//                 System.out.println("3: " + ((mid < rht && (midVal+rhtVal != target)) || (duplicate && (mid < rht))));

//             } while(mid < rht);
//             // while ((mid < rht && (midVal+rhtVal != target)) || (duplicate && (mid < rht)));



//             // Add tupple to array list if not a duplicate
//             if (!duplicate && targetFound) {
//                 sumOfThree.add(Arrays.asList(lftVal, midVal, rhtVal));
//                 verifiedSolutionFound = true;
//             }

//             if (!verifiedSolutionFound) {
//                 // Only iterate if no solution was found because there could be two solutions for one lft pointer index
//                 lft++;
//             }
//         }
//         return sumOfThree;
//     }
// }

// public class 3Sum {
//     public static void main(String args[]) {

//     }
// }

// // Unfortunately to pass this problem the answer needs to be sorted correctly :(
//             // You can have all the correct tupples but if they're not in order you won't pass


// [-1,0,1,2,-1,-4]
// [-4,-1,-1,0,1,2]
