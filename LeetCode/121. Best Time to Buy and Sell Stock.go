func maxProfit(prices []int) int {
    maxProfit, minPrice := 0, prices[0]
    
    for i := 1; i<len(prices);i++ {
        if (minPrice > prices[i]){
            minPrice = prices[i]
        } else if profit := prices[i] - minPrice; maxProfit < profit{
            maxProfit = profit
        }   
    }
    return maxProfit
}