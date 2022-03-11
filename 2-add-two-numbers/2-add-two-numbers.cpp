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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int car=0,sum=0;
        ListNode * t1=l1,*t2=l2 , *temp, *head;
        temp= new ListNode(0);
        head=temp;
        
        while(t1!=NULL || t2!=NULL){
            int a= (t1!=NULL) ? t1->val: 0;
            int b= (t2!=NULL) ? t2->val: 0;
            sum=car + a + b;
            temp->next= new ListNode(sum%10);
            // t1->val=sum%10;
            // t2->val=sum%10;
            car=sum/10;
            temp=temp->next;
            // temp=t1;
            if(t1!=NULL) t1=t1->next;
            if(t2!=NULL) t2=t2->next;
            
        }
        // while(t1!=NULL){
        //     sum=car+ t1->val;
        //     t1->val=sum%10;
        //     car=sum/10;
        //     temp=t1;
        //     t1=t1->next;
        // }
        // while(t2!=NULL){
        //     sum=car+ t2->val;
        //     t2->val=sum%10; //t1
        //     car=sum/10;
        //     temp=t2;
        //     t2=t2->next;
        // }
        if(car!=0)
            temp->next= new ListNode(car);
        
//         //to print longer one
//         t1=l1,t2=l2;
//         while(t1!=NULL && t2!=NULL){
//             t1=t1->next;
//             t2=t2->next;
//         }        
        
//         if(t1==NULL && t2!=NULL)
//         return l2;
        
        return head->next;
    }
};