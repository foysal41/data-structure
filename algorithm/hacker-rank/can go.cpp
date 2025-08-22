#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> movee = {{ -1,0 }, {1, 0} , {0,-1}, {0,1}};
int n,m;

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }else{
        return true;
    }
}

void dfs(int si, int sj){
    //queue<pair<int, int>> q;
    vis[si][sj] = true;

    for(int i=0; i<4; i++){
        int ci = si+movee[i].first;
        int cj = sj+movee[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#'){
            dfs(ci, cj);
        }
    }

}

int main(){

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            cin >> grid[i][j];
        }
    }

    int si, sj, ei, ej;
    for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
        if(grid[i][j] == 'A'){
            si = i;
            sj = j;
        }

        if(grid[i][j] == 'B'){
            ei =i;
            ej = j;
        }
       }
    }

    if(si ==-1 || ei == -1){
        cout << "NO";
        return 0;
    }

    memset(vis,false, sizeof(vis));
    dfs(si,sj);

    if(vis[ei][ej]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}


//https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-07/challenges/can-go-1