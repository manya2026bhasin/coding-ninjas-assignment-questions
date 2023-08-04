/*Node with maximum child sum

Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 
Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1*/

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
template <typename T>
class Pair
{
public:
    TreeNode<T> *node;
    int sum;
};
Pair<int> helper(TreeNode<int> *root)
{
    Pair<int> ans;
    int chidrensum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        chidrensum += root->children[i]->data;
    }
    ans.node = root;
    ans.sum = chidrensum;
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair<int> ans2 = helper(root->children[i]);
        if (ans2.sum > ans.sum)
        {
            ans = ans2;
        }
    }
    return ans;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    return helper(root).node;
}
