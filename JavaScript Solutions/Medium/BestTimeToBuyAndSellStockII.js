// Author: Dorian Knight
// Date: April 30th 2025
// Description: Best time to buy and sell stock 2 JavaScript solution
// Rank: Medium
// Topics: Array || Dynamic Programming || Greedy

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let maximumProfit = 0;
    for (let i=0; i<prices.length-1; i++) {
        let current_price = prices[i];
        let next_price = prices[i+1];
        let price_difference = next_price - current_price;

        if (price_difference > 0) {
            maximumProfit += price_difference;
        }
    }

    return maximumProfit;
};
