bool isBalanced(Node *root)
    {
        if(root==NULL)
        return true;
        int lt=height(root->left);
        int rt=height(root->right);
        bool as=abs(lt-rt)<=1;
        if(as && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
//we recursively check for each node that if we assume it as a tree then is it 
//balanced
