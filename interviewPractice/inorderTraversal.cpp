
// inorder traversal of a binary tree without recursion
#include <stack>
#include <iostream>
using std::string;
  



//binary tree Node definition:
struct Node 
{ 
    //constructor
    Node (int d) 
    { 
        this->data = d; 
        left = right = NULL; 
    } 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
  
class Solution { 
public:
//inorder traversal method:
void inOrderTraversal(struct Node *root) 
{   
    current=root;
    while (current != NULL || mystack.empty() == false) 
    { 
        //traverse down to the left most Node of the current Node 
        while (current !=  NULL) 
        { 
            // assign a pointer to a tree node before traversing the node's left subtree 
            mystack.push(current); 
            current = current->left; 
        } 
        // Current must be NULL at this point 
        current = mystack.top(); 
        mystack.pop(); 
        //print current node 
        std::cout<<current->data<< " "; 
        
        current = current->right; 
    } 
} 
private:
    std::stack<Node *> mystack; 
    Node *current;

};

int main(void) 
{ 
  
  Solution sol;
    /*visualization of the binary tree :
              1
            /  \ 
         2      3 
        / \    / \
      4   5   6  7          */
    struct Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7);

   sol.inOrderTraversal(root); 


    //deallocate memory
    delete root;

    return 0; 
} 
  

