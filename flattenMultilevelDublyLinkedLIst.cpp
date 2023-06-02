/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head ){
        if(head == NULL){
            return NULL;
        }
        Node* temp = head;
        Node* nextNode =NULL;
        while(temp != NULL){
            nextNode = temp->next;
            if(temp -> child != NULL){
           
             temp -> next = solve(temp->child);
                temp->child = NULL;
              temp ->next->prev = temp;
            
                Node* tail = temp->next;
                while(tail->next != NULL){tail=tail->next;}
                tail->next = nextNode;
                if(nextNode != NULL){
                    nextNode -> prev= tail;
                }
                temp = nextNode;
            }
            else {
                temp = temp ->next;
            }
        }
return head;
    }
    Node* flatten(Node* head) {
     return solve(head);     
    }
};
