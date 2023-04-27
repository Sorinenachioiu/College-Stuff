#include <bits/stdc++.h>
using namespace std;

ifstream in("suma2.in");
ofstream out ("suma2.out");

int dp[200005];
int v[200005];
int N;

void solve(){
    for(int i = 0; i < N; i++){
        dp[i] = max(dp[i-2] + v[i], dp[i-1]);
    }
}

void read(){
    in >> N;

    for(int i = 0; i < N; i++){
        in >> v[i];
    }
}

int main(){

    read();
    solve();
    out << dp[N-1];
    return 0;
}
