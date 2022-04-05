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
    bool helper(ListNode* head){
        if(head==NULL) return true;
        bool a=helper(head->next);
        if(a==false) return false;
        else if( head->val!=main->val )
            return false;
            
        else{
            main=main->next;
            return true;
        }
    }
public:
    ListNode* main;
    bool isPalindrome(ListNode* head) {
        main=head;
        return helper(head);
    }
};