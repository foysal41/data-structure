#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
vector<pair<int, int>> movee = {{-1,0},{1,0},{0,-1},{0,1}};

int n, m;

bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
    {
        return false;
    }else{
        return true;
    }
}


void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});

    vis[si][sj] = true;
    level[si][sj] = 0; 

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        for(int i=0; i<4; i++){
            int ci = par_i + movee[i].first;
            int cj = par_j + movee[i].second;

            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1 ;
            }
        }


    }
    


}



int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++ ){
            cin >> grid[i][j];
        }
    }

    int si,sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    if(grid[si][sj] != '.' || grid[di][dj] != '.'){
        cout << "NO" << endl;
        return 0;
    }

    bfs(si, sj);

    if(vis[di][dj]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }





    return 0;
}