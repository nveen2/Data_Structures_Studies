vector<int> levelorder(Node* root) {
        vector<int> ans; 
        
        if(root == NULL) 
            return ans; 
            
        queue<Node*> q; 
        q.push(root); 
        
        while(!q.empty()) {
           
            Node *temp = q.front(); 
            q.pop(); 
            
            if(temp->left != NULL) 
                q.push(temp->left); 
            if(temp->right != NULL) 
                q.push(temp->right); 
                
            ans.push_back(temp->key); 
        }
        return ans; 
    }
// Time complexity- O(N) Space complexity- O(N)
