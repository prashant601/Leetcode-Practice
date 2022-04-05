/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void helper(ListNode* head, int &val){
        if(head->next==NULL) return;
        if(head!=NULL && head->val==val) head=head->next;
        if(head->next->val==val){
            ListNode* temp=head->next;
            head->next=head->next->next;
            temp->next=NULL;
            // free(temp);
        }
        if(head->next!=NULL)
            helper(head->next,val);
    }
    ListNode* removeElements(ListNode* head, int val) {
//         if(head==NULL) return head;
        
//         while(head->val==val && head->next!=NULL)   head=head->next;
        
//         helper(head,val);
//         while(head->val==val && head!=NULL)   head=head->next;
//         // helper(head,val);
//         // helper(head,val);
//         return head;
        if (head == NULL) return NULL;
        head->next = removeElements(head->next, val);
        if(head->val == val)
            return head->next;
        else return head;
    }
};