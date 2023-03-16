int diameter(Node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

int height(Node *node, int &diameter){
    if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return (1+max(lh, rh));
}
//One method is using brute force. Time complexity of Brute Force = O(n^2)
//So now we have a method to find the diameter in O(n) time
