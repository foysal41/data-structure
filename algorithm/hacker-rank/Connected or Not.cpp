#include<bits/stdc++.h>
using namespace std;
int main(){
    int node, edge;
    cin >> node >> edge;
   
    int adj_mat[node][node];
    memset(adj_mat,0,sizeof(adj_mat));

    for(int i=0; i<node;i++){
        for(int j=0; j<node; j++){
            if(i==j){
                adj_mat[i][j] = 1;
            }
        }
    }


    //Directed Edge Input
    for(int i=0; i<edge; i++){
       
            int a, b;
            cin >> a >> b;
            adj_mat[a][b] = 1;
    
    }

    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        if(adj_mat[u][v] == 1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }



   

    return 0;
}