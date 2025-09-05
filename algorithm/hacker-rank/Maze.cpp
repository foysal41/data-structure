#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int,int> parentArr[1005][1005];
vector<pair<int,int>> movee = {{0,1},{0,-1},{-1,0},{1,0}};

 int row , column;

bool valid(int i, int j)
{
    if(i<0 || i>=row || j<0 || j>=column)
    {
        return false;
    }else{
        return true;
    }
}


void bfs(int source_i , int source_j)
{
    queue<pair<int, int>>q;
    q.push({source_i,source_j });
    vis[source_i][source_j] = true;
    level[source_i][source_j] = 0; 
    parentArr[source_i][source_j] = {-1,-1};

    while(!q.empty())
    {
        pair<int , int > par = q.front();
        q.pop();

        int parent_i = par.first;
        int parent_j = par.second;

        for(int i=0; i<4; i++){
            int child_i = parent_i + movee[i].first;
            int child_j = parent_j + movee[i].second;

            if(valid(child_i,child_j) && !vis[child_i][child_j] && (grid[child_i][child_j]=='.' || grid[child_i][child_j]=='D'))

            {
                q.push({child_i,child_j});
                vis[child_i][child_j] = true;
                level[child_i][child_j] = level[parent_i][parent_j] +1;
                parentArr[child_i][child_j] = {parent_i, parent_j};
            }
        }



    }
}



int main(){

   
    cin >> row >> column;
 
    int source_i=-1, source_j=-1,destination_i=-1, destination_j=-1;



    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cin >> grid[i][j]; 

            //ei লুপ থেকে source er I, J আলাদা করে নিলাম। 
            if(grid[i][j] == 'R')
            {
                source_i = i;
                source_j = j;
            }else if(grid[i][j] == 'D')
            {
                destination_i= i;
                destination_j= j;
            }
        }
    }


    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parentArr, -1, sizeof(parentArr));


    bfs(source_i, source_j);
    //cout << vis[destination_i][destination_j] << endl;  destination print kore dakah
       if(destination_i == -1 || !vis[destination_i][destination_j]){
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                cout << grid[i][j];
            }

            cout << endl;
        }

        return 0;
    }



   int node_i = destination_i, node_j = destination_j;
  
    while(!(node_i==source_i && node_j==source_j))
    {
        if(grid[node_i][node_j] == '.') grid[node_i][node_j] = 'X';
        auto par = parentArr[node_i][node_j];
        node_i = par.first;
        node_j = par.second;
        if(node_i == -1 && node_j == -1){
            break;
        }
    }


    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}