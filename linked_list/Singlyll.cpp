#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
Node* insertbegg(Node * head, int n){
        Node *temp= new Node(n);
        temp->next=head;
    
    return temp;
 }
 Node *insertlast(Node * head, int n){
    Node *temp=new Node(n);
    if(head==NULL){
        return temp;
    }
    else{
        Node *a= head;
        while(a->next!=0){
            a=a->next;
        }
        a->next=temp;
    }
    return head;
 }
 int searchinll(Node *head, int n){
    if(head==NULL)
    return -1;
    int pos=1;
    Node *temp=head;
    while(temp!=0){
        if(temp->data==n){
            return pos;
        }
         temp=temp->next;
        pos+=1;
    }
    return -1;
   
 }
 int rsearch(Node *head, int x){
    if(head==NULL){
        return -1;
    }
    if(head->data==x){
            return 1;
    }
    else{
       int res=rsearch(head->next, x);{
            if(res==-1)
            return -1;
            else{
                return (res+1);
            }
        }
    }
 }
Node *insertatgiven(Node *head, int pos, int n){
    if(pos==1){
        Node *temp=new Node(n);
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    while(pos-2!=0){
        curr=curr->next;
        pos--;
        if(curr==NULL){
            return head;
        }
    }
    Node *temp=new Node(n);
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
Node* sortList(Node* head)
// it is potd where ll numbers are sorted ascending order according to their magnitude but they should be sorted because there are some negative values in the ll
    {
        Node *a=head;
        Node *b=head->next;
        while(b!=NULL){
            if(b->data>=a->data){
               a=b;
            }
            else{
                a->next=b->next;
                b->next=head;
                head=b;
                b=a;
            }
            b=b->next;
        }
        return head;
    }
int countNodesinLoop(struct Node *head)
{
    Node *slw=head, *fast=head;
    while(slw && fast && fast->next){
        slw=slw->next;
        fast=fast->next->next;
        if(fast==slw){
            int res = 1;
     Node* temp = slw;
    while (temp->next != slw) {
        res++;
        temp = temp->next;
    }
    return res;
        }
    }
    
    return 0;
}
Node* deleteMid(Node* head)
{
    Node *fast=head, *slw=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slw=slw->next;
    }
    Node *a=head;
    while(a->next!=slw){
        a=a->next;
    }
    a->next=a->next->next;
    return head;
}

// int countNodesinLoop(struct Node *head)
// {
//     Node *slw=head, *fast=head;
//     while(slw && fast && fast->next){
//         slw=slw->next;
//         fast=fast->next->next;
//         if(fast==slw){
//             int res = 1;
//     struct Node* temp = slw;
//     while (temp->next != slw) {
//         res++;
//         temp = temp->next;
//     }
//     return res;
//         }
//     }
    
//     return 0;
// }
Node* divide(int N, Node *head){
        Node *es=NULL, *ee=NULL, *os=NULL, *oe=NULL;
        for(Node *curr=head ; curr!=NULL ; curr=curr->next){
            int x=curr->data;
            if(x%2==0){
                if(es==NULL){
                    es=curr;
                    ee=es;
                }
                else{
                    ee->next=curr;
                    ee=ee->next;
                }
                
            }
            else{
                if(os==NULL){
                    os=curr;
                    oe=os;
                }
                else{
                    oe->next=curr;
                    oe=oe->next;
                }
                
            }
        }
        if(os==NULL || es==NULL){
            return head;
        }
        ee->next=os;
        oe->next=NULL;
        
        return es;
    }

void printrecurssive(Node *head){
    if(head==NULL){
        return;
    }
    if(head!=NULL){
        cout<<head->data<<" ";
        printrecurssive(head->next);
    }
}

 void printll(Node *head){
    if(head->next==NULL){
        cout<<head->data<<" ";
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
 

int main(){
    Node *head=new Node(30);
    head=insertlast(head, 50);
    // Node *a=new Node(90);
    // head->next=a;
    // head= insertbegg(head, 10);
    // head= insertbegg(head, 100);
    // head= insertbegg(head, 10000);
    // head=insertlast(head, 900);
    // head=insertatgiven(head,2,500);
    // head=insertatgiven(head,3,1500);
    // head=insertatgiven(head,9,10500);
    // head=insertatgiven(head,1,121);
    // printrecurssive(temp2);
    printll(head);
    Node *s=sortList(head);
    printll(s);
    // cout<<searchinll(head,121)<<endl;
    // cout<<searchinll(head,222)<<endl;
    // cout<<rsearch(head, 10500)<<endl;
}
