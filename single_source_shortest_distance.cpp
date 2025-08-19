#include<bits/stdc++.h>    
using namespace std;

vector<int> adj_list[1005]; // (2) অ্যাডজেসেন্সি লিস্ট: 1000 টা নোড পর্যন্ত গ্রাফ রাখতে পারবো
bool vis[1005];             // (3) vis[] = কোন নোড ভিজিটেড হলো কিনা চেক করার জন্য
int level[1005];            // (4) level[] = সোর্স থেকে কত দূরে (কত লেভেল/এজ দূরে) আছে সেটা রাখবে


void bfs(int src)
{
    queue<int> q;              // (5) BFS এর জন্য একটা queue নিলাম (FIFO)
    q.push(src);               // (6) সোর্স নোড কিউতে দিলাম
    vis[src] = true;           // (7) সোর্স নোডকে ভিজিটেড মার্ক করলাম
    level[src] = 0;            // (8) সোর্সের লেভেল সবসময় 0

    while(!q.empty())          // (9) যতক্ষণ কিউ খালি না হয়
    {
        int par = q.front();   // (10) কিউ থেকে সামনের নোড বের করলাম
        q.pop();

        // (11) par এর প্রতিবেশী/চাইল্ড গুলো দেখা শুরু
        for(int child : adj_list[par]){
            if(!vis[child]){                 // (12) যদি child এখনো ভিজিটেড না হয়
                q.push(child);               // (13) child কে কিউতে ঢুকালাম
                vis[child] = true;           // (14) ভিজিটেড মার্ক করলাম
                level[child] = level[par] + 1; // (15) child এর লেভেল = parent এর লেভেল + 1
            }
        }
    }
}


int main(){
    int n, e;
    cin >> n >> e;                         // (16) নোড আর এজের সংখ্যা ইনপুট নিলাম

    while(e--){                            // (17) e সংখ্যক এজ ইনপুট নিবো
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);          // (18) a → b এজ
        adj_list[b].push_back(a);          // (19) b → a এজ (কারণ undirected গ্রাফ)
    }

    memset(vis, false, sizeof(vis));       // (20) সব নোডকে unvisited করা হলো
    memset(level, -1, sizeof(level));      // (21) সব নোডের level শুরুতে -1 (মানে reachable না)

    int src, dst;
    cin >> src >> dst;                     // (22) সোর্স আর ডেস্টিনেশন ইনপুট নিলাম

    bfs(src);                              // (23) সোর্স থেকে BFS চালালাম
    
    // for(int i=0; i<n; i++){             // (24) চাইলে ডিবাগে সব নোডের level প্রিন্ট করতে পারি
    //     cout << i << "->" << level[i] << endl;
    // }

    cout << level[dst] << endl;            // (25) destination নোডের লেভেল (সর্বনিম্ন পথ) প্রিন্ট করলাম

    return 0;                              // (26) প্রোগ্রাম শেষ
}


/* 
7 8
0 1
1 3
3 2
1 4
3 5
2 5
5 6
4 6
0
4


*/
