#include <stdlib.h>
#include <stdio.h>


struct TreeNode { 
    int val;
    struct TreeNode* left; 
    struct TreeNode* right;
};

// a) insertion
struct TreeNode* insert(struct TreeNode* root, int x) {
    struct TreeNode* newTreeNode = NULL; // only used if root doesn't exist yet
    // struct TreeNode* current = root; // not used???
    if (root == NULL) {
        newTreeNode = malloc(sizeof(struct TreeNode));
        newTreeNode -> val = x; 
        newTreeNode -> left = NULL;
        newTreeNode -> right = NULL;
        return newTreeNode;
    }

    // x is greater than root so should be inserted to right of root
    else if (x > root -> val) { 
        root -> right = insert(root -> right, x);
    }    
    // x is smaller than root so should be inserted to left
    else { 
        root -> left = insert(root -> left, x);
    }
    return root;
}

// b) searching
struct TreeNode* search(struct TreeNode* root, int x) {  
    if (root -> val == x) {
        return root; 
    }

    else if (x > root -> val) {
        return search(root -> right, x);
    }

    else if( x < root -> val) {
        return search(root -> left, x);
    }

    else {
        return NULL;
    }
}

// c) deletion
struct TreeNode* delete(struct TreeNode* root, int el) {
    struct TreeNode* x = search(root, el);
    if (x == NULL) {
        return root; 
    } 
    
    struct TreeNode* u = root; // uncle of t
    struct TreeNode* parent = NULL; 

    while (u != x) {
        parent = u; // parent = root ... Not needed???
        if (x -> val < u -> val) { // if x is smaller than root, go left
            u = u -> left; 
        } else { // if x is larger than root, go right
            u = u-> right; 
        }
    }

   if (u -> right == NULL) {
       if (parent == NULL) {
           root = u -> left; 
       } else {
           parent -> right = u -> left; 
       }
   } else if (u -> left == NULL) {
       if (parent == NULL) {
           root = u -> right; 
       } else if (parent -> left == u) {
           parent -> left  = u -> right; 
       } else {
           parent -> right = u -> right; 
       }
   } else {
       struct TreeNode* p = x -> left; 
       struct TreeNode* q = p; 
       while (p -> right != NULL) {
           q = p; 
           p = p -> right; 
       }
    if (parent == NULL) {
        root = p; 
    } else if (parent -> left == u) {
        parent -> left = p;
    } else {
        parent -> right = p; 
    }
    p -> right = u -> right; 
    if (q != p) {
        q -> right = p -> left;
        p -> left = u -> left; 
    }
   } 
}

void printTree(struct TreeNode* root) {
    if (root == NULL) {
        return; 
    }
    if (root -> left != NULL) {
        printf("%d -- %d\n", root -> val, root -> left -> val);
        printTree(root -> left);
    }
   if (root -> right != NULL) {
       printf("%d -- %d\n", root -> val, root -> right -> val);
       printTree(root -> right);
   }
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 6);
    printTree(root);
    delete(root, 8);
    printf("after deletion");
    printTree(root);



}