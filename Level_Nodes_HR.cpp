#include<bits/stdc++.h>
using namespace std;

// 1️⃣: TreeNode বানানোর জন্য ক্লাস তৈরি করছি
class Node{
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

// 2️⃣: Tree input নেওয়ার ফাংশন (Level order অনুযায়ী)
//https://docs.google.com/document/d/1_uHZeCaLCY-zdEt5VXmWHKnc_ovtLdKS3O9yW-PVe5o/edit?tab=t.0#heading=h.jdc9yps3qnlr
Node* input_tree(){
    int val;
    cin >> val;
    Node* root;
    if(val == -1) root = NULL;
        else root = new Node(val);

    queue<Node* > q;
    if(root != NULL) q.push(root);

    while(!q.empty()){
        Node* parent = q.front();
        q.pop();

        int l,r;
        cin >> l >> r;
        Node* myLeft, *myRight;

        if(l == -1) myLeft = NULL;
            else myLeft = new Node(l);
        if(r == -1 ) myRight = NULL;
            else myRight = new Node(r);

        parent->left = myLeft;
        parent->right = myRight;


        //Push child  node to left and right
        if(parent->left) q.push(parent->left);
        if(parent->right) q.push(parent->right);
    }

return root;
}


// 3️⃣: নির্দিষ্ট লেভেলের সব নোড প্রিন্ট করার ফাংশন
void print_level_nodes(Node* root, int target_level){
    if(root == NULL){
        cout << "Invalid" << endl;
        return;
    }

    queue<pair<Node*, int>>q; // 4️⃣: একটা queue বানালাম যেটা Node ও Level রাখবে
    q.push({root, 0});         // 5️⃣: রুট নোডটাকে level 0 দিয়ে ঢুকিয়ে দিলাম
    bool isFoundValue = false;  // 6️⃣: ধরলাম এখনো কাঙ্ক্ষিত লেভেল পাইনি
   

    while(!q.empty()){
        pair<Node*, int> parent = q.front(); // 7️⃣: সামনের pair টা বের করলাম
        q.pop();

        Node* node = parent.first;          // 8️⃣: pair থেকে node আলাদা করলাম
        int level = parent.second;           // 9️⃣: pair থেকে level আলাদা করলাম

        if(level == target_level){          // 🔟: যদি level মিলে যায়, মানটা প্রিন্ট করবো
            cout << node->val << " ";
            isFoundValue = true;
        }

         // 1️⃣1️⃣: যদি child থাকে, তাদেরকে queue তে পাঠিয়ে দিচ্ছি পরবর্তী level সহ
        if(node->left) q.push({node->left, level + 1});
        if(node->right) q.push({node->right, level + 1});
    }

        // 1️⃣2️⃣: যদি কিছুই না পাই target level এ, তাহলে Invalid প্রিন্ট করবো
    if(!isFoundValue){
        cout << "Invalid" << endl;
    }
}


int main(){
    Node* root = input_tree(); // 1️⃣3️⃣: Tree input নিচ্ছি
    int level;
    cin >> level; // 1️⃣4️⃣: Target level ইনপুট নিচ্ছি

    print_level_nodes(root, level); // 1️⃣5️⃣: ফাংশন কল করে প্রিন্ট করিয়ে নিচ্ছি
    return 0;
}





// https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-07/challenges/level-nodes-2