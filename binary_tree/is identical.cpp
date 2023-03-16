isIdentical(Node *p, Node *q){
if(p==NULL || q==NULL){
        return(p=q);
    }
    return(p->val==q->val) && (isIdentical(p->left, q->left) && isIdentical(p->right, q->right));
}
