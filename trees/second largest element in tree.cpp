/*Second Largest Element In Tree

Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. Also, value of data at each level is distinct.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
  */


************************************************************/
TreeNode<int>*LargestNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int>* ans=root;
    if(root->data>ans->data){
        ans=root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* maxi=LargestNode(root->children[i]);
        if(maxi->data>ans->data){
            ans=maxi;
        }
    }
    return ans;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int>* large=LargestNode(root);
    int track=large->data;
    large->data=INT_MIN;
    TreeNode<int>* ansfinal=LargestNode(root);
    while(ansfinal->data==track){
        ansfinal->data=INT_MIN;
        ansfinal=LargestNode(root);
    }
    return ansfinal;
}
