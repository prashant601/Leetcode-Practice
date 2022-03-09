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
    ListNode* deleteDuplicates(ListNode* head) {
    //     ListNode *temp=head, *pre;
    //     while(temp!=NULL && temp->next!=NULL){
    //     if(temp->val==temp->next->val){
    //         cout<<temp->val<<endl;
    //         temp->next=temp->next->next;
    //     }
    //     else{
    //     temp=temp->next;
    //     }
    //         pre=temp;;
    // }
    //     // head
    // return head;
        if(head==NULL)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur->next && cur->next->next)
        {
            if(cur->next->val==cur->next->next->val)
            {
            int d = cur->next->val;
            while(cur->next && cur->next->val==d)
            {
             ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete(temp);
            }
            }
            else
            cur = cur->next; 
            }
            return dummy->next;
            }
};