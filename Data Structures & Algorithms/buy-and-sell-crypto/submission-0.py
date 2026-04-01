class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maks = int(0)
        l = int(len(prices))
        buy = l -2
        sell = l-1

        while buy >= 0:
            
            if maks < prices[sell]-prices[buy]:
                maks = (prices[sell]-prices[buy])
            print(f"MAX: {maks}, buy: {buy}, sell: {sell}, prices[sell]: {prices[sell]}, prices[buy]: {prices[buy]}")
            if prices[sell] < prices[buy]:
                sell = buy
            buy -=1
        print(f"MAX: {maks}")
        return maks



        