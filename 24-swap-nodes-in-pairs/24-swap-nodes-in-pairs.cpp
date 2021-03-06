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
private:
    
//     void helper(ListNode* head,ListNode* &last){
//         if(head==NULL || head->next==NULL) return;
        
//         ListNode* temp=head->next;
        
//         if(last!=NULL)
//             last->next=temp;
        
//         if(ans==NULL)
//             ans=temp;

//         head->next= temp->next;
//         temp->next=head;
        
//         last=head;
//         helper(head->next,last);
//     }
public:
    // ListNode* ans;
    ListNode* swapPairs(ListNode* head) { 
        // if(head==NULL || head->next==NULL) return head;
        // ListNode* temp=NULL;
        // ans=NULL;
        // helper(head,temp);
        // return ans;
        
        //approach 2
        if(head==NULL || head->next==NULL) return head;
        ListNode *new_head= head->next;
        ListNode *temp= head->next->next;
        new_head->next= head;
        head->next=swapPairs(temp);
        
        return new_head;
        
    }
};