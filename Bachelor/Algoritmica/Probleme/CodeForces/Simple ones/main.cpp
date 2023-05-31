#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(int N){
    int result = 0, K;
    int crtVal;
    cin >> K;
    for(int i = 0; i < N; i++){
        cin >> crtVal;
        if(crtVal >= K && K > 0){
            result++;
        }
    }

    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int T;
    cin >> T;
    solve(T);
    // while(T){
    //     solve();
    //     T--;
    // }
    return 0;
}
