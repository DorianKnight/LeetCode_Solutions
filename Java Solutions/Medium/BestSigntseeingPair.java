// Author: Dorian Knight
// Date: December 27th 2024
// Description: Best sightseeing pair Java solution
// Rank: Medium


class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        // Dynamic programming approach learned in editorial

        // Original equation
        // score = values[i] + values[j] + i-j

        // Broken apart equation
        // values[i] + i = left score
        // values[j] - j = right score

        // Iteratre through the list keeping the maximum left score saved and save the maximum sightseeing pair

        int maxLftScore = values[0];
        int rightScore;
        int maxScore = -1;
        for (int i=1; i<values.length; i++){
            rightScore = values[i] -i;
            int candidateMaxScore = maxLftScore + rightScore;

            if (candidateMaxScore >= maxScore) {
                maxScore = candidateMaxScore;
            }

            if ((rightScore + 2*i) > maxLftScore) {
                // For the next iteration, the right score will be used as the left score
                maxLftScore = rightScore + 2*i;
            }
        }

        return maxScore;



        // Brute force O(n^2) time complexity algorithm

        // Iterate through each pairwise comparison and calculate the pair score
        // Store the pair score as a maximum value, return this maximum value

        // int maxScore = -1;
        // for (int i=0; i<values.length-1; i++){
        //     int lftPtrVal = values[i];
        //     for (int j=i+1; j<values.length; j++){
        //         int rhtPtrVal = values[j];
        //         int pairwiseScore = lftPtrVal + rhtPtrVal + i-j;

        //         if (pairwiseScore > maxScore){
        //             maxScore = pairwiseScore;
        //         }
        //     }
        // }

        // return maxScore;
    }
}

public class BestSigntseeingPair {
    public static void main(String[] args) {
        int[] input_vals = {8,1,5,2,6};
        Solution answerClass = new Solution();
        int answer = answerClass.maxScoreSightseeingPair(input_vals);
        System.out.println("Input: " + input_vals + " max pair value: " + answer);
    }
}
