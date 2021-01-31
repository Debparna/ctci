#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <climits>
#include<list>
using namespace std;

struct node{
  int data;
  node *right;
  node *left;
};

// createBst
void createBst(node* &root, int arr[], int start, int end){
  if(start > end)
    return;

  if(root == NULL){
    int ind = start + (end-start)/2; //(end + start)/2

    node *ptr = new node;
    ptr->data = arr[ind];
    ptr->left = NULL;
    ptr->right = NULL;
    root = ptr;

    createBst(root->left, arr, start, ind-1);
    createBst(root->right, arr, ind+1, end);
  }
}

void insertNode(int data, node* &root){
  //ROOT
  if(root == NULL){
    node *newRoot = new node;
    newRoot->data = data;
    newRoot->left = NULL;
    newRoot->right = NULL;
    root = newRoot;
    return;
  }
  //LEFT
  if( root->data >= data){ //If data is lesser than root then go left
    if(root->left == NULL){ // But if left is NULL then create left node
      node *p = new node;
      p->data = data;
      p->left = NULL;
      p->right = NULL;
      root->left = p;
      return;
    }
    insertNode(data, root->left); //if root->left is not NULL
  }
  //RIGHT
  if(root->data <= data){
    if(root->right == NULL){
      node *p = new node;
      p->left = NULL;
      p->right = NULL;
      p->data = data;
      root->right = p;
      return;
    }
    insertNode(data, root->right);
  }
}


/*******************************************************************************************/
/*
 QUESTION 1 - Balance a binary tree
 Implement a function to check if a tree is balanced.
 */

//Returns the largest of a and b. If both are equivalent, a is returned.
int height(node* root){
  if(root == NULL)
    return 0;

  return max(height(root->right), height(root->left))+1;
}

bool isBalanced(node *root){
  if(root == NULL){
    return true;
  }

  int diff = height(root->left) - height(root->right);
  if(abs(diff) > 1){
    return false;
  }
  else
    return (isBalanced(root->left) && isBalanced(root->right));
}

/*******************************************************************************************/
//if BST or not
//For each node check that if max value in the left subtree is smaller than the node and min value in the right subtree greater then the node

/* Returns true if a binary tree is a binary search tree */
int isBST(node* root)
{
  if (root == NULL)
    return(true);

  /* false if the max of the left is > than us */
  //if (root->left != NULL && maxValue(root->left) > root->data)
  return(false);

  /* false if the min of the right is <= than us */
  // if (root->right!=NULL && minValue(root->right) < root->data)
  return(false);

  /* false if, recursively, the left or right is not a BST */
  if (!isBST(root->left) || !isBST(root->right))
    return(false);

  /* passing all that, it's a BST */
  return(true);
}


/*
 QUESTION 4 - common ancestor
 Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree.
 Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.

 Main point:
 Two nodes, could be anywhere on the tree, find the first common ancestor of the 2 nodes.

 Solution -
 For any node r, we know the following:
 1. If p is on one side and q is on the other, r is the first common ancestor.
 2. Else, the  first common ancestor is on the left or the right side.
 So, we can create a simple recursive algorithm called search that calls search(left side) and search(right side)
 looking at how many nodes (p or q) are placed from the left side and from the right side of the current node.
 If there are two nodes on one of the sides, then we have to check if the child node on this side is p or q
 (because in this case the current node is the common ancestor). If the child node is neither p nor q, we should
 continue to search further (starting from the child). If one of the searched nodes (p or q) is located on the right
 side of the current node, then the other node is located on the other side. Thus the current node is the common ancestor.

 Algorithm: NOT A BINARY TREE
 Search left and right for p and q.
 - If p and q are on two sides left and right of the root then the root is the common ancestor.
 - If both of them are found on one side for example on the left or the right then increase curr parent from the root to go the the child on the side on which p and q were found.
 - Then from that new parent search which side p and q are, if they are on either side of the new parent then that parent is the common ancestor, otherwise do this again, increase the current parent to the next one on either side and search from there. (Recursive)
 */

//root1 is decendent of root
bool isDecendent(node *root, node *pOrq){
  if(root == NULL) // is root has no more descendants it returns NULL
    return false;

  if(root == pOrq)
    return true;

  return isDecendent(root->left, pOrq) || isDecendent(root->right, pOrq); //checks left and then right
}

node* commonAncestor(node *root, node *p, node *q){
  if(root == NULL)
    return NULL;

  if(root == p || root == q)
    return root;

  bool p_on_left = isDecendent(root->left, p);
  bool q_on_left = isDecendent(root->left, q);

  if(p_on_left && q_on_left) //if p and q are on left then start the recursive search on left to find the root
    return commonAncestor(root->left, p, q);
  else if(p_on_left || q_on_left) // if either on left that means one on left and one on right therefore the common ancestor is the root
    return root;
  else
    return commonAncestor(root->right, p, q); //if both on right, isDescendant is called but root->left becomes null and the root->right gets called recursively.
}

/*******************************************************************************************/

/*QUESTION 5 - subtree
 You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes.
 Create an algorithm to decide if T2 is a subtree of T1.

 Main point:
 return true or false if tree 2 is a subtree of tree 1 or not.

 Alternative Approach:
 The treeMatch procedure visits each node in the small tree at most once and is called no more than once per node of the large tree.
 Worst case runtime is at most O(n * m), where n and m are the sizes of trees T1 and T2, respectively.
 If k is the number of occurrences of T2’s root in T1, the worst case runtime can be characterized as O(n + k * m).

 Algorithm:
 T1 - Large tree
 T2 - Smaller tree
 For each node in T2 check if there is a matching node in T1.
 */

//isSubtree call isIdentical
bool isIdentical(node* root1, node* root2){
  if(root1 == NULL && root2 == NULL)
    return true;

  if(root1 == NULL || root2 == NULL)
    return false;

  if(root1->data == root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right))
    return true;

  return false;
}

bool isSubTree(node* root, node* subRoot){
  if(root == NULL && subRoot == NULL)
    return true;

  if(root == NULL || subRoot == NULL)
    return false;

  return isIdentical(root, subRoot) || isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}

/********************************************************************************************************/

/*QUESTION 6 - print paths which sum up to value

 You are given a binary tree in which each node contains a value. Design an algorithm to print all paths which sum up to that value. Note that it can be any path in the tree - it does not have to start at the root.

 Start from the root and branch left and right, computing the sum thus far on each path. When we  nd the sum, we print the current path. Note that we don’t stop just because we found the sum. Why? Because we could have the following path (assume we are lookingforthesum5):2+3+–4+3+1+2. Ifwestoppedoncewehit2+3,we’dmiss severalpaths(2+3+-4+3+1and3+-4+3+1+2). So,wekeepgoingalongevery possible path. On every node, we look “up” to see if we’ve found the sum. That is—rather than asking “does this node start a path with the sum?,” we ask “does this node complete a path with the sum?”

 Main Point:
 -
 - Print paths which sum up to a value.
 - Does not start at root

 My Algorithm: Start at a node, traverse the tree to find values lower than it and add each time a value is found. The minute the added value exceeds the given node value subtract the last value from it and add the next value that is lower than the given value. If there is no other value left then the paths of the nodes do not add up to the node. If the sum is reached, print the path.
 Questions to ask: if the path/nodes are already visited then are they invalid for the next round?
 if they are not invlaid then from where can we start and how many nodes can we repeat?

 Given Algorithm Interpreted:
 Check if root is null, if not assign it to the first level (level 0), sumPath is the path of nodes that will either equal or not equal the sum. Then loop to all the nodes in that level and add it to sumPath, for each added node check "lookup" to see if the sumPath matches the desired sum. If not go to the previous level (i = level, i--) and add the previous node to sumPath, then see if the sumPath with the two nodes added matches the sum(7), if it does, print it using the inner for loop. If it doesnt match i will reach below 0 which means no more levels left. The for loop will end and go to check if the root has a left, the recursive print call for root->left will do the same with root->left as the root(2), if the left is over then the root->right will start.
 */

void addSum(node *root, node *value){
  while (root != NULL) {

  }
}

void print(node *root, int sum, int *path, int level){
  if(root == NULL){
    return;
  }
  path[level] = root->data;
  int sumPath = 0;
  for(int i = level; i >= 0; i--){
    sumPath += path[i];
    if(sumPath == sum){
      for(int j = level; j >= i; j--)
        cout << path[j] << " ";
      cout << '\n';
    }
  }

  if(root->left)
    print(root->left, sum, path, level+1);
  if(root->right)
    print(root->right, sum, path, level+1);
}

//Part 2 - paths from root, with a specified sum
/* Print all the paths from root, with a specified sum in Binary tree
 Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum.

 For this problem, preorder traversal is best suited as we have to add up a key value as we land on that node.

 We start from the root and start traversing by preorder traversal, adding key value to the sum_so_far and checking whether it is equal to the required sum.
 Also, as tree node doesn’t have a pointer pointing to its parent, we have to explicitly save from where we have moved. We use a vector path to store the path for this.*/


void printPathsUtil(node* curr_node, int sum,
                    int sum_so_far, vector<int> &path)
{
  if (curr_node == NULL)
    return;

  // add the current node's value
  sum_so_far += curr_node->data;

  // add the value to path
  path.push_back(curr_node->data);

  // print the required path
  if (sum_so_far == sum )
  {
    cout << "Path found: ";
    for (int i=0; i<path.size(); i++)
      cout << path[i] << " ";

    cout << endl;
  }

  // if left child exists
  if (curr_node->left != NULL)
    printPathsUtil(curr_node->left, sum, sum_so_far, path);

  // if right child exists
  if (curr_node->right != NULL)
    printPathsUtil(curr_node->right, sum, sum_so_far, path);


  // Remove last element from path
  // and move back to parent
  path.pop_back();
}

void printPaths(node *root, int sum)
{
  vector<int> path;
  printPathsUtil(root, sum, 0, path);
}

//Part 3
/*
 Given a binary tree and a number, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals the given number.
 Return false if no such path can be found.

 Algorithm:
 Recursively check if left or right child has path sum equal to ( number – value at current node)
 */

/*
 Given a tree and a sum, return true if there is a path from the root
 down to a leaf, such that adding up all the values along the path
 equals the given sum.

 Strategy: subtract the node value from the sum when recurring down,
 and check to see if the sum is 0 when you run out of tree.
 */
bool hasPathSum(struct node* node, int sum)
{
  /* return true if we run out of tree and sum==0 */
  if (node == NULL)
  {
    return (sum == 0);
  }

  else
  {
    bool ans = 0;

    /* otherwise check both subtrees */
    int subSum = sum - node->data;

    /* If we reach a leaf node and sum becomes 0 then return true*/
    if ( subSum == 0 && node->left == NULL && node->right == NULL )
      return 1;

    if(node->left)
      ans = ans || hasPathSum(node->left, subSum);
    if(node->right)
      ans = ans || hasPathSum(node->right, subSum);

    return ans;
  }
}

/********************************************************************************************************/


/*
 QUESTION 3
 Given a binary search tree, design an algorithm which creates a linked list of all the nodes at each depth (eg, if you have a tree with depth D, you’ll have D linked lists).
 In a usual breath  first search traversal, we simply traverse the nodes without caring which level we are on.
 In this case, it is critical to know the level. We thus use a dummy node to indicate when we have finished one level and are starting on the next.

 RESULT:
 5
 2  7
 1 3 6 8
 4   9

 Use the same createBST function as above to create the tree
 Use a vector of linked lists to store the linked lists at each depth.

 void createLinkedList(vector<list<node*>> &vec, node* root){
 list<node*> rootList;
 rootList.push_back(root); //push the list with the root onto the vector
 vec.push_back(rootList); //First depth is root, so first list

 int depth = 0;
 while(!vec[depth].empty()){ //If res is not empty that means that root exists
 list<node*> nodeList; //create another list

 list<node*>::iterator iter; //iterator for the list
 for(iter = vec[depth].begin(); iter != vec[depth].end(); iter++ ) //begin with root
 {
 node *ptr = *iter;
 if(ptr->left)
 nodeList.push_back(ptr->left);
 if(ptr->right)
 nodeList.push_back(ptr->right);
 }

 vec.push_back(nodeList);
 depth++;
 }
 }

 void printLevelLinkedLists(vector<list<node*>> vec){
 //every vector needs an iterator
 vector<list<node*> >::iterator iter;
 for(iter = vec.begin(); iter != vec.end(); iter++){ //iterate through the vector
 list<node*> li = *iter;
 list<node*>::iterator it;
 for(it = li.begin(); it != li.end(); it++){ //iterate through the list
 node* ptr = *it;
 cout << ptr->data << " ";
 }
 cout << '\n';
 }
 }

 class Binary_Tree{

 node *root;
 list<list<node*>> level(node*);
 public:
 Binary_Tree()
 {
 root = NULL;
 }

 void insert(int element);
 list<list<node*> > level();

 };

 list<list<node*> > Binary_Tree::level(node* node)
 {
 list<node*> current;
 list<node*> current;
 //parent;
 list<list<node*>> result;

 list<Node*>::iterator itr;
 if (node != NULL)
 current.push_back(node);

 while(current.size() > 0)
 {
 result.push_back(current);
 parent = current;

 current.clear();
 itr = parent.begin();
 while(itr != parent.end())
 {
 if((*itr)->left != NULL)
 current.push_back((*itr)->left);

 if((*itr)->right != NULL)
 current.push_back((*itr)->right);

 itr++;
 }

 }
 return result;
 }
 */

/* RED FLAG
 QUESTION 3
 Write an algorithm to find the ‘next’ node (e.g., in-order successor) of a given node in a binary search tree where each node has a link to its parent.
 Questions:
 1) Is the link to parent direct or indirect?
 2) Is the given node any node or will it always be the root node?
 3) What does next mean? Right below? lesser or greater?
 Main goal:
 - Find the next node of a given node.
 - BST
 - each node has a link to its parent

 My Algorithm:
 Since the successor according to the question is the next in its inorder traveral then see where the node is in its visitation order of the three positions - left, parent or right. If

 Solution:
 Inorder: L N R
 We approach this problem by thinking very, very carefully about what happens on an in-order traversal. On an in-order traversal, we visit X.left, then X, then X.right.
 So, if we want to  find X.successor(), we do the following:
 1. If X has a right child, then the successor must be on the right side of X (because of the order in which we visit nodes). Specifically, the left-most child must be the  first node visited in that subtree.
 2. Else, we go to X’s parent (call it P).
 2.a. If X was a left child (P.left = X), then P is the successor of X
 2.b. If X was a right child (P.right = X), then we have fully visited P, so we call successor(P).
 */


int main(){
  node *root = NULL;
  int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //( numbers - 0 to 9

  /*
   3
   1 4
   2   5
   */
  createBst(root, arr2, 0, 4);
  cout << "Root: " << root->data << endl;
  cout<< "Left of Root: "<< endl << " " << root->left->data<<endl;
  cout<< root->left->right->data << endl; //" " << root->left->right->data<<'\n';
  //cout<< "    " <<root->left->right->right->data << endl;
  cout<< "Right of Root: "<< endl << " " << root->right->data<<endl;
  cout<<root->right->right->data << endl; //<<" "<<root->right->right->data<<'\n';
  //cout<< "    "<<root->right->right->right->data << endl;

  //Q1 - isBalanced
  //for(int i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++)
  //  insertNode(arr2[i], root);
  cout << isBalanced(root);

  //Q3
  //createBst(root, arr2, 0, 8);
  //vector<list<node*> > res;
  //findLevelLinkedLists(res, root);
  //printLevelLinkedLists(res);

  //Q4
  //createBst(root, arr2, 0, 8);
  //node *ancestor = commonAncestor(root, root->left->left, root->left->right->right);
  //cout << ancestor->data << endl;

  //Q5
  //int arrBig[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};    // Bigger Tree
  //int arrSmall[] = {1, 2, 3, 4};                  // Subtree
  //node *subRoot;
  //root = subRoot = NULL;
  //createBst(root, arrBig, 0, 8);
  //createBst(subRoot, arrSmall, 0, 3);
  //cout << "Identical:  " << isIdentical(root->left->left->left, subRoot->left) <<  endl;
  //cout << "Is a subtree: " << isSubTree(root, subRoot) << endl ;

  //Q6
  //createBst(root, arr2, 0, 8);
  //int path[100];

  //Part 1
  //print(root, 7, path, 0);

  //Part 2
  //int sum = 38;
  //printPaths(root, sum);

  //Part 3
  //if(hasPathSum(root, sum))
  //printf("There is a root-to-leaf path with sum %d", sum);
  //else
  //printf("There is no root-to-leaf path with sum %d", sum);

  return 0;
}
