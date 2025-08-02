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


Node* input_tree(){
    int val;
    cin >> val;
    Node* root;

    if(val == -1) root =  NULL;
        else root = new Node(val);
    queue<Node* > q;
    if(root != NULL) q.push(root);

    while(!q.empty()){
        Node* parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node* myLeft , *myRight;

        if(l== -1) myLeft = NULL;
            else myLeft = new Node(l);

        if(r == -1 ) myRight = NULL;
            else myRight = new Node(r);

       parent->left = myLeft;
       parent->right = myRight;

       if(myLeft != NULL){
            q.push(myLeft);
       }

       if(myRight != NULL){
        q.push(myRight);
       }
    }

    return root;
}

void get_leaf(Node* root, vector<int> &leaves){
    if(root == NULL){
        return;
    }

    //if dont have any child then push the value into vector
    if(root->left == NULL && root->right == NULL){
        leaves.push_back(root->val);
    }

    get_leaf(root->left, leaves);
    get_leaf(root->right, leaves);
}

int main(){

    Node* root = input_tree();

    vector<int> leaves;
    get_leaf(root, leaves);

    sort(leaves.begin(), leaves.end(), greater<>());


    for(int val : leaves){
        cout << val << " ";
    }
    return 0;
}


//https://docs.google.com/document/d/1E4UxZrZtl7wPnwLD-KTJHTsiKOEySIKJF1m3rq_7kNU/edit?usp=sharing
//https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-07/challenges/level-nodes-2