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
//     bool helper(ListNode* head){
//         if(head==NULL) return true;
//         bool a=helper(head->next);
//         if(a==false) return false;
//         else if( head->val!=main->val )
//             return false;
            
//         else{
//             main=main->next;
//             return true;
//         }
//     }
    bool helper1(ListNode* head, ListNode* &main1){
        if(head==NULL || main1==NULL) return true;
        bool a= helper1(head->next,main1);
        if(a==false) return a;
        a= (head->val==main1->val);
        main1=main1->next;
        return a;
    }
public:
    // ListNode* main;
    bool isPalindrome(ListNode* head) {
        // main=head;
        // return helper(head);
        return helper1(head,head);
    }
};