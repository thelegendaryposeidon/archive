/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* tempHead= head;

        while(tempHead!=NULL){
            mp[tempHead]= new Node(tempHead->val);
            tempHead= tempHead->next;
        }

        tempHead= head;
        while(tempHead!=NULL){
            Node* node= mp[tempHead];
            node->next= mp[tempHead->next];
            node->random= mp[tempHead->random];
            tempHead= tempHead->next;
        }
        return mp[head];
    }
};