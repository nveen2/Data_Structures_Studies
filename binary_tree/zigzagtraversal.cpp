vector <int> zigZagTraversal(Node* root)
    {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        bool ltr=true;
        queue<Node *> ququ;
        ququ.push(root);
        while(!ququ.empty()){
            int size=ququ.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                Node *node=ququ.front();
                ququ.pop();
                int index=(ltr)?i:(size-i-1);
								row[index]=node->value;
                if(node->left){
                    ququ.push(node->left);
                }
                if(node->right){
                    ququ.push(node->right);
                }
            }
            ltr=!ltr;
            for(auto i:row){
            result.push_back(i);
            }
        }
        return result;    
        
    }
/*Zig-zag traversal of tree

In this kind of traversal we do one level in the way of left to right and the below level we do right to left.
Time Complexity: O(n) as we are traversing all the nodes of the Binary tree in ZigZag traversal of Binary Tree at least once. 
Space Complexity: O(n) as extra space for storing the nodes of alternate levels in the stack has been used.
*/
