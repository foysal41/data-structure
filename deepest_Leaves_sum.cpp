#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int mx_depth; 
int sum = 0; 

int max_height(Node* root) // detaimine max_height from root node 
{
    if(root == NULL)
        return 0;
        
      if(root->left == NULL && root->right == NULL)
        return 0;
   
    int l = max_height(root->left);
    int r = max_height(root->right);
    
    return max(l,r) + 1;
}


Node *input_tree() // for taking input
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // 1. ber kore ana
        Node *p = q.front();
        q.pop();

        // 2. oi node ke niye kaj
        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        // 3. children push kora
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}



void level_order(Node* root){
  if(root == NULL){
    cout << "No Tree";
    return; 
  }
  
  //এখানে আমাদের গ্রুপ ডেটা নিতে হবে pair এর মাধ্যমেতার ভিতর একটা লেভেল থাকবে এবং তার একটা node থাকবে 
 
  queue<pair<Node*, int>> q; //তো এখানে আমরা একটা queue তৈরি করে নিলাম এব
  
  q.push({root, 0}); //একটা node থাকবে একটা int থাকবে সেটা 0 থেকে শুরু হবে 
  
  while(!q.empty()){
    
    pair<Node*, int> f = q.front(); //q.front(); থেকে যখন বের করব রিটার্ন করবে সম্পূর্ণ pair টা. এবং সেটা f-front নামের store থাকবে 
    q.pop();
    
    // pair থেকে দুইটা জিনিস আলাদা একটা ভেরিয়েবলে রাখলাম node and level variable
    Node* node = f.first;
    int level = f.second;
    
    //আমরা যে max_height টা বের করেছি তার সঙ্গে compare করব level কে |  যদি লেভেলটা যদি সর্বোচ্চ val পর্যন্ত যায় তখন আমরা তাদের ভ্যালু যোগ করব 
    if(level == mx_depth){
      sum += node->val;
    }

    //যদি node left থাকে,  তাহলে তার লেফট এর ভ্যালু  নিব তার সাথে সাথে এক যোগ করে দেব 
    if(node->left){
      q.push({node->left, level+1});
    }
    
    if(node->right){
      q.push({node->right, level+1});
    }
  }
} // for printing output



int main()
{
    Node* root = input_tree();
    
    //cout << max_height(root) << endl; // ম্যাক্স হাইট এর রুট পাঠায় দিলাম 
    
    mx_depth = max_height(root); // Mx_depth এটা গ্লোবালি ডিক্লেয়ার করে রেখেছি 
  level_order(root);
    cout << sum << endl;
    
    return 0; 
}


//https://leetcode.com/problems/deepest-leaves-sum/