#include<bits/stdc++.h>   
using namespace std;

vector<int> adj_list[1005];  // অ্যাডজেসেন্সি লিস্ট, গ্রাফের জন্য সর্বোচ্চ 1000 নোড
bool vis[1005];              // ভিজিটেড অ্যারে, কোন নোড ঘোরা হয়েছে সেটা মার্ক করে রাখে

// BFS ফাংশন
void bfs(int src){
    queue<int> q;         // কিউ ডিক্লেয়ার (FIFO – First In First Out)
    q.push(src);          // সোর্স নোডকে কিউতে রাখা হলো
    vis[src] = true;      // সোর্সকে ভিজিটেড মার্ক করলাম

    while(!q.empty()){    // যতক্ষণ কিউ খালি না হয়
        int par = q.front();  // কিউর প্রথম নোড বের করলাম
        q.pop();              // কিউ থেকে সরিয়ে দিলাম

        // ওই নোডের সব (children) চেক করা
        for(int child: adj_list[par]){
            if(!vis[child]){       // যদি ভিজিটেড না হয়
                q.push(child);     // কিউতে ঢোকালাম
                vis[child] = true; // ভিজিটেড মার্ক করে দিলাম
            }
        }
    }
    cout << endl;
}


int main(){
    int n, e;              // n = number of nodes, e = number of edges
    cin >> n >> e;

    // গ্রাফ ইনপুট নেওয়া (Undirected Graph)
    while (e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);  // a → b এজ
        adj_list[b].push_back(a);  // b → a এজ (Undirected বলে)
    }

    memset(vis, false, sizeof(vis));  // vis[] অ্যারে শুরুতে সব false করে দিলাম

    int src, dst;     
    cin >> src >> dst;   // সোর্স আর ডেস্টিনেশন ইনপুট নিলাম

    bfs(src);            // সোর্স থেকে BFS চালালাম

    // এখন চেক করবো destination visited হলো কিনা
    if(vis[dst]){
        cout << "YES\n";   // dst নোডে পৌঁছানো সম্ভব
    } else {
        cout << "NO\n";    // dst নোডে পৌঁছানো সম্ভব না
    }
    
    return 0;
}
