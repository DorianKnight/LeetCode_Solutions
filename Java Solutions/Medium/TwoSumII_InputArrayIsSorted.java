// Author: Dorian Knight
// Date: December 27th 2024
// Description: Two Sum II Java solution
// Rank: Medium

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        // Array is sorted in 'ascending' order so I can subtract the left pointer value from the total
        // to get the required number on the right hand side 
        
        // I can move the left pointer up if I'm below the target and move the right pointer to the left if I'm under the total value

        int i = 0;
        int j = numbers.length-1;

        while (numbers[i] + numbers[j] != target){
            if (numbers[i] + numbers[j] > target){
                j--;
            }

            else{
                i++;
            }
        }

        int[] answer = {i+1, j+1};
        return answer;
    }
}


public class TwoSumII_InputArrayIsSorted {
    public static void main(String[] args) {

    }
}