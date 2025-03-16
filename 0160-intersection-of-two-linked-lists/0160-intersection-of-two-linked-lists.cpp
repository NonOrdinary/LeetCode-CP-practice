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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //exploited len diffrence as linked list is linear so
        //lenA=a+x and lenB=b+x where x is length of common linked list
        //so if somehow we can make a=b then we are done and it can be done 
        int lenA=0;
        ListNode *root=headA;
        while(root!=NULL){
            root=root->next;
            lenA++;
        }
        int lenB=0;
        root=headB;
        while(root!=NULL){
            root=root->next;
            lenB++;
        }
        if(lenA>lenB){
            while(lenA!=lenB){
                headA=headA->next;
                lenA--;
            }
        }
        else{
            while(lenA!=lenB){
                headB=headB->next;
                lenB--;
            }
        }

        while(headA!=NULL && headB!=NULL && headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};