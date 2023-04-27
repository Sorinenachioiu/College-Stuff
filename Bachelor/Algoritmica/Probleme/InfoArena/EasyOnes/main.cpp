#include <bits/stdc++.h>
using namespace std;

ifstream in("razboi2.in");
ofstream out ("razboi2.out");


// bool operator > (pair<int, int> &a , pair<int, int> &b){
//     return a.first > b.first;
// }

void solve(){

    int N;
    long long mancareTotala;
    in >> N;

    vector <pair <int, int>> soldat(N);

    for(int i = 0; i < N; i++){
        in >> soldat[i].first;
        soldat[i].second = i;
        mancareTotala += soldat[i].first;
    }

    
    sort(soldat.begin(), soldat.end());

    out << soldat[].first << " ";
    
}

int main(){
    solve();
    return 0;
}