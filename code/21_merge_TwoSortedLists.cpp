/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* tmp=new ListNode(0);
        ListNode* res=tmp;
        while(l1!=nullptr&&l2!=nullptr)
        {
            if(l1->val<l2->val){
                tmp->next=l1;
                tmp=tmp->next;
                l1=l1->next;
            }else{
                tmp->next=l2;
                tmp=tmp->next;
                l2=l2->next;
            }
                
        }
        
        if(l1==nullptr&&l2!=nullptr){
            tmp->next=l2;
        }else if(l1!=nullptr&&l2==nullptr){
            tmp->next=l1;
        }
        return res->next;
        
    }
};
