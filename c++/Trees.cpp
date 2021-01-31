\#include <deque>
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

struct Node{
  int data;
  Node *right;
  Node *left;
};

class binaryTree {
public:
  void insert(Node* &root, int n);
  bool find(int n, Node* root);
  void remove(int n, Node *root);
  Node* FindMin(Node* root);
  Node* Delete(Node *root, int data);

  void random();
  void LevelOrderPrintTree(Node* root);
};

void binaryTree::insert(Node* &root, int data){  //* & for insert as root whatever left or right will be changed
  if(root == NULL){
    Node *newRoot = new Node;
    newRoot->data = data;
    newRoot->left = NULL;
    newRoot->right = NULL;
    root = newRoot;
    return;                //RETURN
  }
  //LEFT
  if( root->data >= data){ /// YOU DO HAVE <= and not just <
    if(root->left == NULL){
      Node *p = new Node;
      p->data = data;
      p->left = NULL;
      p->right = NULL;
      root->left = p;
      return;         //RETURN
    }
    insert(root->left, data); //if root->left is not NULL
  }
  //RIGHT
  if(root->data <= data){
    if(root->right == NULL){
      Node *p = new Node;
      p->left = NULL;
      p->right = NULL;
      p->data = data;
      root->right = p;
      return;
    }
    insert(root->right, data);
  }
}

bool binaryTree::find(int n, Node * root){
  // Base Cases: root is null or key is present at root
  if(root == NULL){
    cout << "not found";
    return false;
  }
  else if(root->data == n){
    cout << "found";
    return true;
  }
  // Key is greater than root's key
  else if ( n > root->data){
    find(n, root->right);
    cout << "found";
    return true;
  }
  // Key is smaller than root's key
  else if ( n < root->data){
    find(n, root->left);
    cout << "found";
    return true;
  }
  else
    cout << "not found";
  return false;
}

//1) Node to be deleted is leaf: Simply remove from the tree.
//2) Node to be deleted has only one child: Copy the child to the node and delete the child
//3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor to      the node and delete the inorder successor. In this particular case, inorder successor can be obtained by finding the minimum value in right child of the node.
Node* binaryTree:: FindMin(Node* root){
  while(root->left != NULL)
    root = root->left;
  return root;
}

Node* binaryTree::Delete(Node *root, int data){
  if(root == NULL)
    return root;

  // If the key to be deleted is smaller than the root's key, then it lies in left subtree
  else if(data < root->data)
    root->left = Delete(root->left, data);

  //If the key to be deleted is greater than the root's key, then it lies in right subtree
  else if(data > root->data)
    root->right = Delete(root->right, data);

  //if key is same as root's key, then This is the node to be deleted
  else {
    //Case 1: No Child
    if(root->left == NULL && root->right == NULL){
      delete root;
      root = NULL;
    }
    //Case 2: one child on right
    else if(root->left == NULL){
      Node *temp = root;
      root = root->right;
      delete temp;
    }
    //Case 2: one child on left
    else if(root->right == NULL){
      Node *temp = root;
      root = root->left;
      delete temp;
    }
    // node with two children: Get the inorder successor (smallest in the right subtree)
    else{
      Node *temp = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right, temp->data);
    }
  }
  return root;
}


void createBst(Node* &root, int arr[], int start, int end){
  if(start > end){
    return;
  }
  if (root == NULL) {
    int ind = (start+ end) / 2;
    Node *newRoot = new Node;
    newRoot->data = arr[ind];
    newRoot->left = NULL;
    newRoot->right = NULL;
    root = newRoot;

    createBst(root->left, arr, start, ind-1);
    createBst(root->right, arr, ind+1, end);

  }
}

//TRAVERSALS -
//DFS Traversals:

//INORDER - L N R
void inOrder(Node *root)
{
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

//Preorder:  N L R
void preOrder(Node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

//Postorder: L R N
void postOrder(Node *root)
{
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

//BFS
//Level order traversal of tree
void binaryTree::LevelOrderPrintTree(Node* root){
  if(root == NULL){
    return;
  }
  queue<Node*> queue;
  queue.push(root);

  while(!(queue.empty())){
    Node* temp = queue.front();
    cout << temp->data << " ";
    queue.pop();

    if(temp->left != NULL){
      queue.push(temp->left);
    }
    if(temp->right != NULL){
      queue.push(temp->right);
    }
  }
}

int main(){
  Node *root = NULL;
  int arr2[] = {1, 2, 3, 4, 5}; //( numbers - 0 to 9

  //Q1
  //for(int i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++)
  //  obj.insert(root, arr2[i]);

  /*
   3
   1 4
   2   5
   */
  createBst(root, arr2, 0, 4);
  cout << "Root: " << root->data << endl;
  cout << "Left of Root: " << endl << " " << root->left->data << endl;
  cout << root->left->right->data << endl; //" " << root->left->right->data<<'\n';
  //cout<< "    " <<root->left->right->right->data << endl;
  cout << "Right of Root: " << endl << " " << root->right->data << endl;
  cout << root->right->right->data << endl; //<<" "<<root->right->right->data<<'\n';
  //cout<< "    "<<root->right->right->right->data << endl;

  //binaryTree obj;
  //obj.find(6, root);
  //cout << "Level Order  ";
  //obj.LevelOrderPrintTree(root);
  //cout << endl;
  //cout << "inorder  ";
  //inOrder(root);
  //cout << endl;
  //cout << "postOrder  ";
  //postOrder(root);
  //cout << endl;
  //cout << "preOrder  ";
  //preOrder(root);
  //cout << endl;

}
