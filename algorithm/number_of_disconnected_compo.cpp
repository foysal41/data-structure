#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void dfs(int src)
{
    vis[src] = true;
    for(int child : adj_list[src])
        if(!vis[child])
            dfs(child);
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    int cnt = 0; // 2) যখনই কাউন্ট করব তখন এক প্লাস প্লাস করব 
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false) // 1) প্রথমে চেক i কে source করে vis false/true (০ ৫ ৪ true)
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}


/* 


8 6
1 2
0 5
2 3
6 7
4 5
1 3

outtupt: 3

*/