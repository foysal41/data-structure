#include<bits/stdc++.h>
using namespace std;
/* 
Working Steps
    1. 2D grid input 
    2. Source and End point find
    3.  DFS/BFS(s)
    4. is end point visited or not. 
*/

char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> movee = {{-1,0} , {1,0}, {0, -1}, {0,1}};
int n, m; 

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 | j>= m)
        return false;
    return true;
}

void dfs(int si, int sj){
    cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for(int i=0; i<4; i++){
    int ci = si + movee[i].first;
    int cj = sj + movee[i].second;

    if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.' || grid[ci][cj] == 'E')
        dfs(ci,cj);
    }
}

int main(){

    cin >> n >> m; 

    for(int i=0; i<n; i++)  
        for(int j=0; j<m; j++)
            cin >>grid[i][j];


    int si,sj, ei, ej;
   for(int i=0; i<n; i++)  {
        for(int j=0; j<m; j++){
           
            if(grid[i][j]=='S'){
                si=i;
                sj=j;
            }
            if(grid[i][j]=='E'){
                ei=i;
                ej=j;
            }
        }
        //cout << endl;
     }  
     
     cout << si << " " << sj << endl;
     cout << ei << " " << ej << endl;

     memset(vis, false, sizeof(vis));
     dfs(si, sj);

     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << vis[i][j];
        }
        cout << endl;
     }

    return 0;
}













/* 
You are given a 2D matrix representing a maze in a city. Each cell can represent a road, a building, or a destination point.
You are standing at point S (Start) and want to reach point E (End). You can move up, down, left, and right through road cells, but you cannot pass through buildings.

Your task is to determine whether there exists a path from S to E.

. → road

* → building

S → starting point

E → ending point

6 7
*******
*S..*..
*.*.*..
*...*.*
*.E.*..
*******



*/