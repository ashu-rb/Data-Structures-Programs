#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data=val;
            next=NULL;
        }

};
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

Node* takeInput(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

    
void insertati(Node* head,int i)
{
    Node* t=head;int c=0;
    Node * q= new node(value);
    if(head==NULL)return;
    while(c!=i-1 && t->next!=NULL){
        t=t->nxt;
        ++c;
    }
    if(c==i-1){
       cout<<"Enter val to insert";
        cin>>q->data;
        q=t->next;
        t=q->next;

    }

    
    }

int main()
{
    Node *head=takeInput();
    insertati(head,3);
    return 0;
}