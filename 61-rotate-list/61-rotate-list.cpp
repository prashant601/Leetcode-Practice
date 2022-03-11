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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0 ) return head;
        
        ListNode *temp=head, *temp1=head, *lasthead=head;
        int n=1;
        
        while(temp->next!=NULL){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k%n==0) return head;
        
        temp->next=head;
        int c=1;
        // temp=head;
        cout<<n<<" "<<k<<" ";
        temp1=head;
        while(n-k!=c){
            temp1=temp1->next;
            c++;
        }
        head=temp1->next;
        temp1->next=NULL;
        
        // while(temp!=NULL){
        //     cout<<" c "<<c<<" ";
        //     if(n-k==c){
        //         cout<<" hehe";
        //         head=temp->next;
        //         temp->next=NULL;
        //     }
        //     c++;
        //     temp=temp->next;
        // }
        
        return head;
    }
};