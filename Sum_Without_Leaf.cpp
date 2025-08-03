#include<bits/stdc++.h>
using namespace std;
class Node {
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


Node* input_tree(){
    int val;
    cin >> val;
    Node* root;

    if(val == -1) root = NULL;
        else root = new Node(val);
    
    queue<Node* >  q;
    if(root != NULL) q.push(root);

    while(!q.empty()){
        Node* font = q.front();
        q.pop();

        int l,r;
        cin >> l >> r;
        Node* myleft, *myright;

        if(l == -1) myleft = NULL;
            else myleft = new Node(l);
        if(r == -1) myright = NULL;
            else myright = new Node(r);
        
        font->left = myleft;
        font->right = myright;

          if(myleft) q.push(myleft);
        if(myright) q.push(myright);
    }

    return root;

}



int sum_without_leaf(Node* root){
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL){ //আমারা জানি root node কোনো child না থাকে তার মানে leaf node
        return 0;
    }

    //এখন left subtree ও right subtree-এর উপর recursive call করলাম।
    int leftNode = sum_without_leaf(root->left);
    int rightNode = sum_without_leaf(root->right);

    //এখন root নোডটা যেহেতু leaf নয় (উপরে চেক করে ফেলেছি), তাই তার মানকে যোগ করবো
    return leftNode + rightNode + root->val;
}



int main(){
    Node* root = input_tree();

   int result = sum_without_leaf(root);
   cout << result << endl;
    return 0;
}


//https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-07/challenges/sum-without-leaf