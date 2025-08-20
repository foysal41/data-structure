#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;                 // ✅ visited mark WHEN enqueued

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        cout << par << " ";          // কাজ করা

        // children push + visited check
        for(int child : adj_list[par]){
            if(!vis[child]){         // ✅ একই নোড বারবার যেন না আসে
                vis[child] = true;
                q.push(child);       // ✅ কিউতে ঢোকালাম
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;

    // ❌ BUG LINE REMOVED:
    // vector<int> adj_list[n];   // (গ্লোবালটাকে শ্যাডো করছিল)

    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);    // Undirected
    }

    memset(vis, false, sizeof(vis));
    bfs(0);                          // সোর্স 1 (প্রয়োজনে বদলাও)
    return 0;
}
