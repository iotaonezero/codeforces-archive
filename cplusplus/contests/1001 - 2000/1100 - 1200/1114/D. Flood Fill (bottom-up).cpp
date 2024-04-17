#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.
 
const int MAX = 5000;
int col[MAX], dp[MAX][MAX];

void solve() {
    int n; std::cin >> n;
    
    int pre = -1, m = 0;
    for(int i = 0; i < n; i++) {
        int t; std::cin >> t;
        if(t != pre) {
            col[m] = t; pre = t; ++m;
        } 
    }
    n = m; // index from 0 till m - 1
    
    memset(dp, INT_MAX, sizeof dp);
    for(int i = 0; i < n; i++)
        dp[i][i] = 0;
    for(int len = 1; len < n; len++) {
        for(int l = 0; l + len < n; l++) {
            int r = l + len;
            // smaller to larger length of [L, R]
            if(col[l] == col[r])
                dp[l][r] = 1 + dp[l + 1][r - 1];
            else 
                dp[l][r] = std::min(dp[l + 1][r], dp[l][r - 1]) + 1;
        }
    }
    
    std::cout << dp[0][n - 1];   
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst = 1;
    while(tst--) solve();
        
    return 0;
}

// g++ -std=c++20 <filename>.cpp
