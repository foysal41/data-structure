#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> movee = {{ -1, 0 } , {1,-0}, {0, -1} , {0, 1}};

int n, m;
bool valid(int i, int j){
    if(i < 0 || i>=n || j <0 || j>=m){
        return false;
    }else{
        return true;
    }
}

int dsf_count(int si, int sj){
    vis[si][sj] = true;
    int sz = 1;

    for(int i=0; i<4; i++){
        int ci = si + movee[i].first;
        int cj = sj + movee[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
            int dsf_operations = dsf_count(ci, cj);
            sz = sz+dsf_operations;
        }
    }

    return sz;
}


int main(){
    cin >> n >> m;

    for(int i= 0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    vector<int> sizes;

    //তুমি চাও শুধু অ্যাপার্টমেন্ট সংখ্যা নয়, বরং প্রতিটি অ্যাপার্টমেন্টে কতগুলো রুম আছে (মানে connected component-এর সাইজ)।
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='.' && !vis[i][j]){ //যদি সেল '.' হয় (মানে room) এবং এখনো vis[i][j] == false (মানে আগে কোনো DFS এই রুম কভার করেনি) | তাহলে বুঝব এখান থেকে একটা নতুন অ্যাপার্টমেন্ট শুরু হচ্ছে।
                int rooms = dsf_count(i,j); //dfs_count(i,j) কল করলে এই (i,j) থেকে DFS ছড়িয়ে পুরো apartment ভিজিট করবে। সেই সাথে কয়টা রুম ভিজিট হলো তার সংখ্যা রিটার্ন করবে।
                sizes.push_back(rooms); //এই apartment-এর সাইজ (রুম সংখ্যা) rooms এখন একটা list/vector sizes এ যোগ করছি। শেষে sizes ভেক্টরে সব apartment-এর সাইজ জমে থাকবে।
            }
        }
    }


    if(sizes.empty()){
        cout << "-1" << endl;
        return 0;
    }

    sort(sizes.begin(), sizes.end());

   for(int x : sizes) cout << x << " ";
    cout << "\n";
    

    return 0;
}