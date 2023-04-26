#include <bits/stdc++.h>
using namespace std;

ifstream in ("treap.in");
ofstream out ("treap.out");

#define pb push_back
const int NMAX = 150005;

struct treapEntry{
    int key;
    int priority;
}myTreap[NMAX];

vector<int> G[NMAX];
bool izItHeap[NMAX];
bool izItBST[NMAX];
int minKey[NMAX];
int maxKey[NMAX];

inline bool isHeap(const int &firstCh, const int &secondCh, const int &node){
    if(firstCh != -1 && myTreap[firstCh].priority > myTreap[node].priority) return false;
    if(secondCh != -1 && myTreap[secondCh].priority > myTreap[node].priority) return false;
    return true;
}

inline bool isBST(const int &firstCh, const int &secondCh, const int &node){
    if(firstCh != -1){
        maxKey[node] = max(maxKey[node], maxKey[firstCh]);
        minKey[node] = min(minKey[node], minKey[firstCh]);
    }
    if(secondCh != -1){
        maxKey[node] = max(maxKey[node], maxKey[secondCh]);
        minKey[node] = min(minKey[node], minKey[secondCh]);
    }

    int nodeKey = myTreap[node].key;
    // the node has 2 ch
    if(firstCh != -1 && secondCh != -1){
        // if 1st ch = left ch and 2nd ch = right ch
        int firstKey = myTreap[firstCh].key;
        int secondKey = myTreap[secondCh].key;
        if( firstKey <= nodeKey && secondKey > nodeKey){
            if(maxKey[firstCh] > nodeKey) return false;
            if(minKey[secondCh] <= nodeKey) return false;
            return true;
        }

        //if 1st ch = right ch and 2nd ch = left ch
        if( secondKey <= nodeKey && firstKey > nodeKey ){
            if(minKey[secondCh] > nodeKey) return false;
            if(minKey[firstCh] <= nodeKey) return false;
            return true;
        }
        return false;
    }

    // node has only 1 ch
    if(firstCh != -1){
        if(myTreap[firstCh].key <= nodeKey &&
            maxKey[firstCh] <= nodeKey) return true;
        if(myTreap[firstCh].key > nodeKey && 
            minKey[firstCh] > nodeKey) return true;
        return false;
    }

    if(secondCh != -1){
        if(myTreap[secondCh].key <= nodeKey &&
            maxKey[secondCh] <= nodeKey) return true;
        if(myTreap[secondCh].key > nodeKey && 
            minKey[secondCh] > nodeKey) return true;
        return false;
    }
    return true;
}

bool viz[NMAX];
void solve(const int &node){
    viz[node] = true; // node is bein' visited

    // not a Binary tree
    if(G[node].size() > 3){
        izItBST[node] = false;
        izItHeap[node] = false;
        return ;
    }

    int firstCh = -1;
    int secondCh = -1;
    // see what it's childrens are
    for(auto const &children : G[node])
        if(!viz[children]){
            solve(children);
            if(firstCh == -1){
                firstCh = children;
            }else{
                secondCh = children;
            }
        }
    
    // a leaf
    if(firstCh == -1){
        izItBST[node] = true;
        izItHeap[node] = true;
        return;
    }

    if(firstCh != -1 && !(izItBST[firstCh] && izItHeap[firstCh])||
        secondCh != -1 && !(izItBST[secondCh] && izItHeap[secondCh])){
            izItBST[node] = false;
            izItHeap[node] = false;
            return;
        }

    // check if it's a heap
    if(isHeap(firstCh, secondCh, node))
        izItHeap[node] = true;
    // check if it's a BST
    if(isBST(firstCh, secondCh, node))
        izItBST[node] = true;
}

int N;
void read(){
    
    int node1, node2;
    in >> N;

    for(int i = 1; i <= N; i++) {
        izItBST[i] = true;
        izItHeap[i] = true;
    }

    for(int i = 1; i < N ; i++){
        in >> node1 >> node2;
        G[node1].pb(node2);
        G[node2].pb(node1);
    }

    for(int i = 1; i <= N; i++){
        in >> myTreap[i].key;
        maxKey[i] = myTreap[i].key;
        minKey[i] = myTreap[i].key;
    }
    for(int i = 1; i <= N; i++)
        in >> myTreap[i].priority;
}

int main()
{
    ios::sync_with_stdio(false);
    read();
    
    solve(1);

    out << ((izItBST[1] && izItHeap[1])?1:0);
    for(int i = 2; i <= N; i++) out << " " << ((izItBST[i] && izItHeap[i])?1:0);
    out << "\n";
    return 0;
}
