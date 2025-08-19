#include<bits/stdc++.h>
using namespace std;



vector<int> adj_list[1005];
bool vis[1005];
int level[1005];
int parent[1005]; //path printing করার জন্য parent কে track রাখতে হয়। 

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0; 



    while(!q.empty()){
        int par = q.front();
        q.pop();


        for(int child: adj_list[par]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                level[child] = level[par] +1;
                parent[child] = par; //3 এই জায়গায় parent of child = হচ্ছে par. ei লাইন থেকে পুরা path কি  ট্রাক করা হয়ে গেলো
                
                
            }
        }
    }
}
int main(){

    int n, e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent)); //২  parent এর মান সব গুলা কে -1 করে দিলাম। 

    int src, dst; 
    cin >> src >> dst;
    bfs(src);
    vector<int> path; // ৮ এই vector কে নিলাম। ভালু গুলা কে  reverse  করতে। 


    /* 
    for(int i=0; i<n; i++){ //4. loop চালিয়ে কার parent এর under এ child আছে দেখলাম
        cout << i << " parent -> " << parent[i] << endl;
    }
    */

    // ** আমাদের এই কোড এর কাজ টা হচ্ছে destination থেকে count start হবে। ৬ তার prent 5 তারপর ৫ এর parent ৩ tarpor 1 , 0; 
    

    int node = dst; // ৫. ei node টা সুরু করব destination থেকে। 

    while(node != -1){ //৬  নিচে থেকে root নডে যাব।

        //cout << node << " ";
        path.push_back(node);// print na kore এই vector er মদ্ধে রাখলাম

        node = parent[node]; //৭. parent of [node] এর মদ্ধে value কে node এর মদ্ধে রাখলাম। 
    }
    reverse(path.begin(), path.end()); //9 reverse korlam 
     for(int x : path){  
        cout << x << " ";
     }


    return 0;
}


/* 
input :
7 7
0 1
1 3
3 2
1 4
3 5
2 5
5 6
0 6


output: 0 1 3 5 6 


*/