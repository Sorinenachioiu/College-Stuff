#include <bits/stdc++.h>
using namespace std;

void myPrint(int result){
    cout << "Output : \n";
    cout << result <<'\n';
    cout.flush();
}

void solve(){
    int N;
    cin >> N;

        vector<pair<int, int>> a(N), b(N), res(2*N + 11);

    int crt;
    int ant = -1;
    int crtIndx = -1;
    int dimA = 0,
        dimB = 0;
    int maxim = 0;

    map<int, int> secvMaxA, secvMaxB;

    for(int i = 0; i < N; i++){
        cin >> crt;
        if(crt == ant){
            a[crtIndx].second++;
            secvMaxA[crt] = max(a[crtIndx].second, secvMaxA[crt]);
        }else{
            a[++crtIndx].first = crt;
            a[crtIndx].second = 1;
            dimA++;
            if(secvMaxA.find(crt) == secvMaxA.end()){
                secvMaxA[crt] = 1;
            }
        }
        ant = crt;
    }

    crtIndx = -1;
    ant = -1;
    for(int i = 0; i < N; i++){
        cin >> crt;
        if(crt == ant){
            b[crtIndx].second++;
            secvMaxB[crt] = max(b[crtIndx].second, secvMaxB[crt]);
        }else{
            b[++crtIndx].first = crt;
            b[crtIndx].second = 1;
            dimB++;
            if(secvMaxB.find(crt) == secvMaxB.end()){
                secvMaxB[crt] = 1;
            }
        }

        ant = crt;
    }

    for(auto const & [key, value]: secvMaxA){
        if(secvMaxB.find(key) == secvMaxB.end()){
            secvMaxB[key] = 0;
        }
        maxim = max(maxim, secvMaxA[key] + secvMaxB[key]);
    }
    myPrint(maxim);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int T;

    cin >> T;

    while(T--){
        cout << "Input :\n";
        cout.flush();
        solve();
    }

    return 0;
}
