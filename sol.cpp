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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  
  private:

   TreeNode * makeBST(TreeNode * root,vector<int>&ans,int  s,int  e){

     if(s > e) return NULL;


     int mid = s + ( e -s)/2;

     root = new TreeNode(ans[mid]);

     root -> left = makeBST(root -> left,ans,s,mid-1);
     root -> right =makeBST(root -> right,ans,mid+1,e);

     return root;




   }


public:
    TreeNode* sortedListToBST(ListNode* head) {

    // using the brute force solution.
     
     if(head == NULL) return NULL;

     vector<int> ans;

     ListNode * temp = head;
     while(temp != NULL){
        ans.push_back(temp -> val);
        temp = temp -> next;
     }


     TreeNode * root  = NULL;
   
    int n = ans.size();
    int s = 0;
    int e = n-1;

  root =  makeBST(root,ans,s,e);
   return root;



    }
};