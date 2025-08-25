class Solution {
public:
    vector<int> adj_list[200005];//01) adj list conert করছি 
    bool vis[200005]; // 05) vis array নিয়ে নিলাম। 

    void dfs(int src){
        vis[src] = true;

        for(int child : adj_list[src]){ //07 adj_list থেকে each item বার করে নিব আর দেখব visited কিনা। 
            if(!vis[child]){
                dfs(child); //08 যদি ভিজিটেড না হয় তাহলে  DFS চালিয়ে দিবো 
            }
        }

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0; i<edges.size(); i++){ //02) edge list এর উপর প্রতিটা ইনডেক্সের উপরে loop চালালাম. এই লোক চালালে কি পাব? 
            int a = edges[i][0]; //03) সেই edge মধ্যে দুইটা করে ইনডেক্স আছে. প্রথম element তাকে বের করে নিয়ে আসলাম. i নাম্বার ইনডেক্স একটা ভেক্টর পাবো তার মধ্যে 0 নম্বর index 
            int b = edges[i][1];

            adj_list[a].push_back(b); // 04) যেহেতু এটা আন ডাইরেক্টেড সে তো এখানে আমরা দুইবার দুই দিকে pushback করলাম 
            adj_list[b].push_back(a); 


        }

        memset(vis,false,sizeof(vis));
        dfs(source); // 06 source কে পাঁঠিয়ে দিলাম। 

        //09 এইবার এখান থেকে রিটার্ন করার পালা যদি visited না হয় তাহলে false
        if(vis[destination] == true)
            return true;
        else return false;


        //short curt of 9
        //return vis[destination];
    }
};


//https://docs.google.com/document/d/1m-OCIS35DOH568t-KAo21U7p5FrZKLosP8YXjNW1ocw/edit?usp=sharing