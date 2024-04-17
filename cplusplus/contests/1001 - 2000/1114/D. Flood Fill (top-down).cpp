#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.
 
const int MAX = 5001;
int col[MAX], dp[MAX][MAX];

int compute(int l, int r) {
    
    if(dp[l][r] != -1) return dp[l][r];
    
    if(l >= r) return dp[l][r] = 0;
    
    if(col[l] == col[r]) return dp[l][r] = 1 + compute(l + 1, r - 1);
    
    return dp[l][r] = 1 + std::min(compute(l + 1, r), compute(l, r - 1));
}

void solve() {
    int n; std::cin >> n;
    
    int m = 0;
    for(int i = 0; i < n; i++) {
        int t; std::cin >> t;
        if(i == 0 || t != col[m - 1]) {
            col[m] = t; ++m;
        }
    }
    n = m; // indices from 0 till m - 1
    
    memset(dp, -1, sizeof dp);
    std::cout << compute(0, n - 1);
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
