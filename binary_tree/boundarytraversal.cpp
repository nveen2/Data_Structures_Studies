// Boundary traversal
// For anticlockwise boundary traversal
// First I take left left boundary elements without leaf
// Then I take leaf nodes
// Then I take right boundary elements in reverse


void addleftboundary(Node *root, vector<int> &res){
    if(root==NULL || (root->left==NULL &&root->right==NULL))
    return;
    res.push_back(root->data);
    if(root->left){
        addleftboundary(root->left,res);
    }
    else
        addleftboundary(root->right,res);
}
void addrightboundary(Node *root, vector<int> &res){
    if(root==NULL || (root->right==NULL && root->left==NULL))
    return;
    if(root->right){
        addrightboundary(root->right, res);
    }
    else{
    addrightboundary(root->left,res);
    }
    res.push_back(root->data);
}
void addleaves(Node *root, vector<int> &res){
    if(root==NULL)
    return;
    if(root->right == NULL && root->left==NULL){
        res.push_back(root->data);
    }
    addleaves(root->left, res);
    addleaves(root->right, res);
}

    vector <int> boundary(Node *root)
    {
        
        vector<int> res;
        res.push_back(root->data);
        addleftboundary(root->left,res);
        addleaves(root->left,res);
        addleaves(root->right,res);
        addrightboundary(root->right,res);
        return res;
    }
};
