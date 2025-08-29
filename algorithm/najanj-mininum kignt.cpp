#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105] [105];
int level[105][105];

//5) move  গুলা বানিয়ে দিলাম
vector<pair<int,int>> movee = {{ 2,-1},{ 1,-2},{ 2, 1},{ 1, 2},{-1, 2},{-2, 1},{-2,-1},{-1,-2}}; 
int n, m; //Row and column input nilam


bool valid(int i, int j) // 6) move করতে করতে বাইরে না চলে যায়
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}



void bfs(int si, int sj) //07) BFS 
{
    queue<pair<int, int>> q; // 08) each queue এ src and Destination রাখবো।
    q.push({si,sj}); //09) queue এর মদ্ধে push করে রাখলাম। 

    vis[si][sj] = true; 
    level[si][sj] = 0; 

    while(!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        for(int i=0; i<8; i++){
            int ci = par_i + movee[i].first;
            int cj = par_j + movee[i].second;

        //10) প্রতিটা  child গুলা কে check করতে হবে যে ভেলিদ কিনা। visited কিনা
        if(valid(ci,cj) && !vis[ci][cj])
        {
            q.push({ci,cj}); // valid হলে child এ পুশ করবো।
            vis[ci][cj] = true;
            level[ci][cj] = level[par_i][par_j] + 1; // level কে ১ বারিয়ে দিবো। 

        }
     }
    }

}
int main(){

    int tc; cin >> tc;
    while(tc--){

    
    n = 8, m = 8;
    string src, des; // ২) user only src and destinatin দিবে। তাই পুরা গ্রিদ loop চালানো লাগবে না। 
    cin >> src >> des;
    int si,sj, di, dj; // 3) si= মানে  src এর row  sj= মানে src column.
     
    si=src[1]-'1';  //4) src এর row তে asci value তে convert করে নিলাম। 
    sj=src[0]-'a';

    di=des[1]-'1';
    dj=des[0]-'a';

    //cout << si << sj << di << dj << endl; output e asbe 00 77

    memset(vis, false, sizeof(vis));
    memset(level,false,sizeof(level));
    bfs(si,sj);
    cout << level[di][dj] << endl;
    }
    return 0;
}