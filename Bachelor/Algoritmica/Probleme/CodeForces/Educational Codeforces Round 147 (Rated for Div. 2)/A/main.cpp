#include <bits/stdc++.h>
using namespace std;

int T;
void solve(){
    string crt;
    
    cin >> crt;

    if(crt.length() > 1 && crt[0] == '0'){
        cout << 0;
        return;
    }

    int result = 1;

    if(crt[0] == '?')
        result = 9;

    for(int i = 1; i < crt.length(); i++){
        if(crt[i] == '?')
            result *= 10;
    }

    cout << result;
}

int main(){
    cin >> T;

    while(T--)
        solve();

    return 0;
}