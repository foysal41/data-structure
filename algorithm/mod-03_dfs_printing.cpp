#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];//(1)
bool vis[1005];//(1)

void dfs(int src) //(1)
{ 
    //base case এখানে কোন base case লাগবে না কারন। নিচে আমার check করছি child গুলা  visit আছে কিনা। যদি সব visited হলে dfs recurction হবে না



    cout << src << " "; //(2) Source node কে print করলাম। 
    vis[src] = true; //(3) যেহেতু Source node কে print  করলাম  তাই ওইটা visit true করে দিলাম। 
    for(int child:adj_list[src])//(4) আমার child এর মদ্ধে adj_list src index এ যাই তারপর আমারা একটা vector পাব ওই সব গুলা child পাব। ওইটা child e মধ্যে রাখবো। 
    {
     if(vis[child] == false){ //(5) কিন্তু তার আগে দেকব child গুলা visit কিনা। 
        dfs(child);  //(6) oi child গুলা কে recursion চালাব। 
      }
    
       
    }
}

int main(){
    int n, e; //(1)
    cin >> n >> e;//(1)
    while(e--){//(1)
        int a, b;//(1)
        cin >> a >> b;//(1)
        adj_list[a].push_back(b);//(1)
        adj_list[b].push_back(a);//(1)

    }

    memset(vis, false, sizeof(vis));//(1)
    dfs(0);//(1)

    return 0;
}


/* 

7 7
0 2
2 4
0 1
1 5
1 3
0 3
3 6

output: 0 2 4 1 5 3 6 


*/