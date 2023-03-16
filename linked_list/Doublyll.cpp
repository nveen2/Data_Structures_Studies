#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int n){
        data= n;
        this->prev=NULL;
        this->next=NULL;
    }
};
Node * insertatbegg(Node * head, int x){
    Node* temp=new Node(x);
    temp->next=head;
    if(head!=NULL){
    
    head->prev=temp;
    }
    return temp;
}
 void printll(Node *head){
    if(head->next==NULL){
        cout<<head->data<<" ";
        return;
    }
    if(head==NULL){
        cout<<0<<" ";
    }
    Node *temp=head;
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
 }
 Node * insertatend(Node * head, int n){
    Node * temp=new Node(n);
    if (head==NULL){
            return head;
    }
    Node *curr=head;
    while(curr->next!=0){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
 }
 Node *iterative_reverse(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *prev=NULL;
    Node *curr=head;
    while(curr!=NULL){
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
        
    }
    return prev->prev;
   
 }
 Node *recursive_reverse(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
     Node *rest_head=recursive_reverse(head->next);
     Node *rest_tail=head->next;
     rest_tail->next=NULL;
     head->next=NULL;
     return rest_head;
 }
 Node *recursive_reverse2(Node *curr, Node *prev){
    Node *next=curr->next;
    curr->next=prev;
    return recursive_reverse2(next, curr);
 }
void removeduplicates(Node *head){
    Node *curr=head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data==curr->next->data){
        Node *temp=curr->next;
        curr->next=curr->next->next;
        delete(temp);
        } 
        else{
            curr=curr->next;
        }
    }
}
Node *reverseingroupsrecursive(Node *head, int k){
    Node *curr=head;
    Node *next=NULL;
    Node *prev=NULL;
    int count=0;
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(curr!=NULL){
            Node *n_head=reverseingroupsrecursive(next,k);
            head->next=n_head;
        }
    return prev;
}
Node *reverseingroupsiterative(Node *head, int k){
    Node *curr=head;
    Node *prevfrst=NULL;
    bool isfirst=true;
    while(curr!=NULL){
        Node *first=curr;
        Node *prev=NULL;
        int count=0;
        while(curr!=NULL && count<k){
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(isfirst){
            head=prev;
            isfirst=false;
        }
        else{
            prevfrst->next=prev;
        }
        prevfrst=first;
    }
    return head;
}
 int lengthofloop(Node *head){
    int length=2;
    Node *slow=head;
    Node *fast=head;
    Node *start;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(slow!=fast){
        return false;
    }
    slow =head;
    while(slow->next !=fast->next){
        slow=slow->next;
        fast=fast->next;
        start=fast->next;
    }
    Node *temp=start;
    temp=temp->next;
    while(temp!=start){
        temp=temp->next;
        length++;
    }
    
    return length;
      
 }

 
int main(){
    Node *p1=new Node(12);
    Node *p2=new Node(13);
    Node *p3=new Node(14);
    p1->next=p2;
    p2->next=p3;
    p2->prev=p1;
    p3->prev=p2;
    Node *p4=new Node(60);
    p3->next=p4;
    p4->next=p2;
    
    Node *head=insertatbegg(p1, 90);
    // insertatbegg(p1, 100);
    insertatend(head, 200);
    printll(head);
    Node *b=reverseingroupsiterative(head,3);
    printll(b);
    cout<<lengthofloop(head);
    
    
}
