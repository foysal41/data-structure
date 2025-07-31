
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

bool isNodePresent(BinaryTreeNode<int> *root, int x) {

    if(root == NULL)
        return false;

    if(root->data == x){
        return true;
    }

    bool lft = isNodePresent(root->left, x );
    bool rit = isNodePresent(root->right, x);

    if(lft == true || rit == true){
        return true;
    }else{
        return false;
    }
    
}

//https://docs.google.com/document/d/1NPHfCjoGG1sXOsrTfQuMzPxLZhcDXoJOKKFJdpXnbBc/edit?usp=sharingIs Node Present?
