/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertAtTail(ListNode*& head, ListNode*& tail, int data){
        ListNode* temp= new ListNode(data);
        
        if(head==NULL){
            head= temp;
            tail= temp;
            return head;
        }
        else{
            tail->next= temp;
            tail= temp;
            return head;
        }
    }
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        int carry= 0;
        ListNode* ansHead= NULL;
        ListNode* ansTail= NULL;

        while(head1!=NULL && head2!=NULL){
            int sum= carry+head1->val+head2->val;
            int digit= sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry= sum/10;
            head1= head1->next;
            head2= head2->next;
        }

        while(head1!=NULL){
            int sum= carry+head1->val;
            int digit= sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry= sum/10;
            head1= head1->next;
        }

        while(head2!=NULL){
            int sum= carry+head2->val;
            int digit= sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry= sum/10;
            head2= head2->next;
        }

        while(carry!=0){
            int sum= carry;
            int digit= sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry= sum/10;
        }
        return ansHead;
    }
};