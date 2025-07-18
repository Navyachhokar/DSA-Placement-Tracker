// ------------------------------------------------
// 🔸 Brute Force
// 💡 Try all pairs (buy < sell) and track max profit
// 🕒 Time Complexity: O(n^2)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
int maxProfitBrute(vector<int>& prices) {
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            maxProfit = max(maxProfit, prices[j] - prices[i]);
        }
    }
    return maxProfit;
}


// ------------------------------------------------
// 🔸 Optimal Approach (Greedy)
// 💡 Track min so far and max profit at each step
// 🕒 Time Complexity: O(n)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
 int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for(int i = 1; i< prices.size(); i++){
            int cost = prices[i] - mini;
            profit = max(cost,profit);
            mini = min(prices[i], mini);
        }
        return profit;
    }
