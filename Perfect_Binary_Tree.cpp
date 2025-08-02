#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int max_height(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;

    int l = max_height(root->left);
    int r = max_height(root->right);

    return max(l, r) + 1;
}

Node* input_tree(){
    int val ;
    cin >> val;
    Node* root;

    if(val == -1) root = NULL;
        else root = new Node(val);
    
    queue<Node* > q;
    if(root){
        q.push(root);
    }

    while(!q.empty()){
        Node* parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node* myleft, *myright;

        if(l == -1) myleft = NULL;
            else myleft = new Node(l);
        if(r == -1) myright = NULL;
            else myright = new Node(r);

        parent->left = myleft;
        parent->right = myright;

        if(myleft) q.push(myleft);
        if(myright) q.push(myright);
    }

    return root;

}


int count_nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);

    return l + r + 1;
}


int main(){

     Node* root = input_tree();

    int mx_depth = max_height(root);
    int total_nodes = count_nodes(root);
    int cal = pow(2, mx_depth +1) -1;

    if(total_nodes == cal){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}

//https://docs.google.com/document/d/1E4UxZrZtl7wPnwLD-KTJHTsiKOEySIKJF1m3rq_7kNU/edit?usp=sharing
//https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-07/challenges/perfect-binary-tree