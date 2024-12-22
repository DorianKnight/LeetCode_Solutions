# Author: Dorian Knight
# Date: December 22nd 2024
# Description: Best time to buy and sell a stock
# Rank: Easy

class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        # Two pointer solution

        max_profit = 0
        iterator = 0

        if len(prices) < 2:
            return max_profit

        # Initialize left pointer as buy date and right pointer as sell date
        buy_price = prices[iterator]
        buy_address = iterator
        sell_price = prices[iterator+1]
        sell_address = iterator+1

        while iterator < len(prices)-1:
            current_price = prices[iterator]
            current_price_address = iterator
            next_price = prices[iterator+1]
            next_price_address = iterator+1

            # If a new higher value has been found, update the right pointer
            if next_price >= sell_price:
                sell_price = next_price
                sell_address = next_price_address

            # If a new lower value has been found, update left pointer
            # Also check that sell pointer is ahead of buy pointer
            if current_price < buy_price and current_price_address < sell_address:
                buy_price = current_price
                buy_address = current_price_address

            # If there's a lower but still viable buy price somewhere further down the list
            if current_price_address > buy_address and current_price < buy_price:
                buy_address = current_price_address
                buy_price = current_price
                sell_address = next_price_address
                sell_price = next_price

            difference = sell_price - buy_price
            if difference > max_profit:
                max_profit = difference

            iterator += 1

        return max_profit

def main():
    input_prices = [2,1,2,1,0,1,2]
    #input_prices = [7,1,5,7,2,3]
    #input_prices = [2,7,1,4,11]
    #print(f"{input_prices[9461]} : {input_prices[9464]}")
    answer, buy_address, sell_address = Solution().maxProfit(input_prices)
    print(f"The maximum profit is: {answer} at addesses {buy_address}, {sell_address}")


if __name__ == "__main__":
    main()