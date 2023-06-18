#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> values = {28, 29, 31, 34, 46, 41, 46, 47, 49, 51, 52, 58, 60};
    sort(values.begin(), values.end());

    cout << values.size() <<endl;
    for(int crt: values){
        cout << crt << ", ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int T;

    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}
