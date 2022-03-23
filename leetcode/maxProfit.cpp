#include<iostream>
#include<vector>
using namespace std;

// 动态规划
int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    int n = prices.size();
    // opt[i][0] 表示持有股票，最大收益
    // opt[i][1] 表示未持有股票，冷冻期，最大收益
    // opt[i][2] 表示未持有股票，非冷冻期，最大收益
    vector< vector<int> > opt(n, vector<int>(3));

    // 初始化
    opt[0][0] = -prices[0];
    opt[0][1] = 0;
    opt[0][2] = 0;

    // 算出所有交易方式的收益
    for (int i = 1; i < prices.size(); ++i) {
        opt[i][0] = max(opt[i - 1][0], opt[i - 1][2] - prices[i]);
        opt[i][1] = opt[i - 1][0] + prices[i];
        opt[i][2] = max(opt[i - 1][1], opt[i - 1][2]);
    }

    return max(opt[prices.size() - 1][1], opt[prices.size() - 1][2]);
}
