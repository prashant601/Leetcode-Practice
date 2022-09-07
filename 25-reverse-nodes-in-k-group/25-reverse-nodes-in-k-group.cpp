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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre= NULL, *curr=head, *nex, *head1=head;
        int i=0,cnt=0;
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        } 
        curr=head;
        
        if(cnt<k) return head;
        
        while(curr!=NULL and i<k){
            i++;
            nex= curr->next;
            curr->next=pre;
            pre= curr;
            curr= nex;
        }
        
        if(nex!=NULL)
        head->next= reverseKGroup(nex, k);
        head= pre;
        return head;
    }
};