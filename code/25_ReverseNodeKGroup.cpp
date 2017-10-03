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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *res, *prevtail, *currhead, *currtail, *nexthead;
        int counter=1;
        prevtail=new ListNode(0);
        prevtail->next=head;
        nexthead=head;
        currtail=head;
        currhead=prevtail;
        res=head;
        bool firstflag=true;
        if(k==1) return head;
        while(currtail!=nullptr){
            counter++;
            currtail=currtail->next;
            if(counter==k&&currtail!=nullptr){
                if(firstflag==true){
                    res=currtail;
                    firstflag=false;
                }
                nexthead=currtail->next;
                currtail->next=nullptr;
                currhead=prevtail->next;
                
                prevtail->next=reverseList(currhead);
                
                prevtail=currhead;
                prevtail->next=nexthead;
                currtail=nexthead;
                counter=1;
            }
        }
        
        return res;
        
        
    }
    ListNode* reverseList(ListNode* head){
        ListNode *back, *curr, *front;
        back=nullptr;
        curr=head;
        while(curr!=nullptr){
            front=curr->next;
            curr->next=back;
            back=curr;
            curr=front;
        }
        return back;
    }
};
