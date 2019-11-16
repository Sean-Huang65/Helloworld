/**
 * 解法一：时间33%
 * 双向链表实现
 * 优化方向：
 * 判断分支优化
 * 可优化为单链表
 */

class MyLinkedList {
private:
    struct node{
        node *prev,*next;
        int val;
    }*head;
    int length;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=nullptr;
        length=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        node *tmp=head;
        int res=-1;
        int cnt=0;
        while(tmp!=nullptr){
            if(cnt==index) return tmp->val;
            cnt++;
            tmp = tmp->next;
        }   
        return res;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node *tmp = new node;
        tmp->prev = nullptr;
        tmp->next = nullptr;
        tmp->val = val;
        if(head==nullptr){
            head = tmp;
            length++;
        }
        else{
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
            length++;
        }
        
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *tmp = new node;
        tmp->prev = nullptr;
        tmp->next = nullptr;
        tmp->val = val;
        node *end=head;
        if(end==nullptr){
            head = tmp;
            length++;
            return;
        }
        while(end->next!=nullptr){
            end=end->next;
        }
        end->next=tmp;
        tmp->prev=end;
        length++;
        return;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<=0){
            addAtHead(val);
        }
        else if(index>length){
        }
        else if(index==length){
            addAtTail(val);
        }
        else{
            node *tmp=head;
            node *newNode=new node;
            newNode->prev = nullptr;
            newNode->next = nullptr;
            newNode->val = val;
            int cnt=0;
            while(cnt<index){
                tmp=tmp->next;
                cnt++;
            }
            newNode->next = tmp;
            newNode->prev = tmp->prev;
            tmp->prev->next = newNode;
            tmp->prev=newNode;
            length++;
        }
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index==0 && length>0){
            node*tmp=head;
            head=head->next;
            if(head != nullptr){
                head->prev=nullptr;
            }
            delete(tmp);
            tmp=nullptr;
            length--;
            return;
        }
        if(index>0 && index<length){
            int cnt=0;
            node *tmp=head;
            while(cnt<index){
                tmp=tmp->next;
                cnt++;
            }
            if(cnt==length-1){
                node *n=tmp->prev;
                n->next=nullptr;
                delete(tmp);
                length--;
                return;
            }
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
            delete(tmp);
            tmp=nullptr;
            length--;
        }
        return;
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