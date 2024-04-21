class Node{
public:
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }
};
class MyLinkedList {
public:
Node* head;
int n;
    MyLinkedList() {
        head=new Node(0);
        n=0;
    }
    
    int get(int index) {
        if(index>=n) return -1;
        Node* temp=head->next;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* temp=head;
        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        n++;
    }
    
    void addAtTail(int val) {
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new Node(val);
        n++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>n) return;
        if(index==n) return addAtTail(val);
        int count=0;
        Node* temp=head;
        while(count<index && temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        Node* curr=temp;
        Node* newNode=new Node(val);
        newNode->next=curr->next;
        curr->next=newNode;
        n++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=n) return;
        int count=0;
        Node* temp=head;
        while(count<index && temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        Node* curr=temp;
        curr->next=curr->next!=NULL ? curr->next->next: NULL;
        n--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */