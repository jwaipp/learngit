#include<bits/stdc++.h>
using namespace std;
void test01() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    int m = weight.size(), n = bagWeight;
    vector<vector<int>> dp(m, vector<int> (n + 1, 0));
    // init
    for(int j = weight[0]; j <= bagWeight; ++j) {
        dp[0][j] = value[0];
    }
    for(int i = 1; i < m; ++i) {
        for(int j = 0; j <= bagWeight; ++j) {
            if(j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i -1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    for(auto& nums : dp) {
        for(auto&num : nums) {
            cout<<num<<' ';
        }
        cout<<endl;
    }
    // cout<<dp[m - 1][bagWeight]<<endl;
}
int main() {
    test01();

}