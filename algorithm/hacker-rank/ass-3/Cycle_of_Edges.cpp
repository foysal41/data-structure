
#include<bits/stdc++.h>
using namespace std;

int par[200005];

int group_size[200005];

int find(int node)
{
    if(par[node] ==  -1)
    {
        return node;
    }

    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}



void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(leader1 == leader2){
        return;
    }

    if(group_size[leader1] >= group_size[leader2]) 
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];

    }else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}




int main(){

    int n, e;
    cin >> n >> e;

    memset(par, -1, sizeof(par));
    for(int i=1; i<= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    int cnt = 0; 

    while(e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);

        if(leaderA == leaderB)
        {
            cnt++;
        }else{
            dsu_union(a,b);
        }
    }

    cout << cnt <<  endl;

    return 0;
}


//https://docs.google.com/document/d/14njd4oOHn8-_sWfnerEGqYAa5dNv-veba9ICrCayQw8/edit?usp=sharing
//https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-07/challenges/cycle-of-edges


/*
ব্যবহৃত অ্যালগরিদম: Disjoint Set Union (DSU) —  Module 11 থেকে (detect_cycle_in_undirected_graph_using_DSU.cpp)

কেন এই অ্যালগরিদম?

আনডিরেক্টেড গ্রাফে কোনো এজ (u, v) সাইকেল তৈরি করবে iff (যদি) u এবং v ইতিমধ্যেই একই কানেক্টেড কম্পোনেন্টে থাকে।

DSU দিয়ে আমরা প্রতিটি এজ ইনসার্ট করার সময় দুই প্রান্তের লিডার (leader) বের করি:

যদি leader(u) == leader(v) → এই এজটা সাইকেল তৈরি করবে → কাউন্ট বাড়াই।

নইলে union(u, v) করি → দুই সেট মার্জ হয়ে যায়।

এটা তোমার Module 11-এর একদম স্ট্যান্ডার্ড টেমপ্লেট—কেবল bool cycle না রেখে কতগুলো এজ সাইকেল করে সেটার কাউন্ট রাখছি।

*/