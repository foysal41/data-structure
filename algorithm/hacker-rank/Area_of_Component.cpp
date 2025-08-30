#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> movee = {{-1,0},{1,0},{0,-1},{0,1}};

int n,m;
int cnt; 
bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
    {
        return false;
    }else{
        return true;
    }
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;

    for(int i=0; i<4; i++){
        int ci = si+movee[i].first;
        int cj = sj + movee[i].second;

        if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci,cj);
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

    memset(vis, false, sizeof(vis));

    int mn =INT_MAX;
    bool found = false;


      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '.' && !vis[i][j])
            {
                cnt = 0;
                dfs(i,j);
                mn = min(mn, cnt);
                found = true;
            }
        }
    }


    if(!found){
        cout << -1 << endl;
    }else{
        cout << mn << endl;
    }

    return 0;
}