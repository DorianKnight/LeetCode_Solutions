// Author: Dorian Knight
// Date: December 29th 2024
// Description: Gas station C++ solution
// Rank: Medium

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Find difference between gas and cost
        vector<int> gasDelta;
        int totalSum = 0;
        for (int i=0; i<gas.size(); i++) {
            int delta = gas[i] - cost[i];
            totalSum += delta;
            gasDelta.push_back(delta);
        }

        // If the total sum is negative, there is no solution
        if (totalSum < 0) {
            return -1;
        }

        // Iterate over the gas delta and find the minimum on the delta vs index graph
        // Note that the delta is cumulative as time goes on
        int minDelta = gasDelta[0];
        int minDeltaIndex = 0;
        int runningDelta = minDelta;
        for (int j=1; j<gasDelta.size(); j++) {
            runningDelta += gasDelta[j];
            if (runningDelta <= minDelta) {
                minDelta = runningDelta;
                minDeltaIndex = j;
            }
        }

        // The start point is one index to the right of the local minima
        int startingPos = minDeltaIndex+1;
        if (startingPos == gas.size()) {
            startingPos = 0;
        }

        return startingPos;
    }
};