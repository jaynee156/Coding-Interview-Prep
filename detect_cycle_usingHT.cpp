//to find a cycle in a Linked List(using hash tables)
#include <iostream>
#include <unordered_map>
using namespace std;
class node{
    public:
    int data;
    node * next;

    node(int d){
        this->data = d;
        this->next = NULL;
    }
};
bool find_cycle(node *head){
    unordered_map<node *, bool> ht;
    node* traverse = head;
    while(traverse!=NULL){
        cout<<traverse->data<<endl;
        if(ht.count(traverse)!=0)
            return true;
        else{
            ht[traverse] = true;
            traverse = traverse->next;
        }
    }
    return false;
}
void insert_head(node* &head, int d){
    if(head == NULL){
        head = new node(d);
    }
    else{
        node * n = new node(d);
        n->next = head;
        head = n; 
    }

}
int main() {
    int x;
    //starting to build a linked list
    node * head = NULL;
    for(int i=0;i<5;i++){
        cin>>x;
        insert_head(head, x);
    }
    //creating a cycle
    node* temp = head->next->next->next->next;
    temp->next = head->next;

    if(find_cycle(head)){
        cout<<"cycle found";
    }
    else {
        cout<<"cycle not found";
    }
}
