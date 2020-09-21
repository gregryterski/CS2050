//Greg Ryterski
//gjr7dz, 18186949
//Prelab 15
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodestruct{
  int key;
  struct nodestruct *left, *right;
} Tree;

Tree * insertBST(int, Tree*);
Tree * findBST(int, Tree*);
void printTree(Tree*);

int main(void){
  Tree* binaryTree = insertBST(1, NULL);
  if(binaryTree == NULL)
    return 0;
  for(int i=0; i<5; i++){
    binaryTree = insertBST((i*20/3), binaryTree);
  }
  printf("Binary Search Tree: ");
  printTree(binaryTree);
  Tree* foundNode = findBST(2, binaryTree);
  if(foundNode == NULL){
    printf("Searched node is not in tree.\n");
    return 0;
  }
  printf("Found Node: %d\n", foundNode->key);
}

Tree * insertBST(int key, Tree* bst){
  if(bst == NULL){
    bst = malloc(sizeof(Tree));
    if(bst == NULL)
      return NULL;
    bst->key = key;
    bst->left = NULL;
    bst->right = NULL;
    return bst;
  }
  else{
  if(key < bst->key){
    bst->left = insertBST(key, bst->left);
  }
  else if(key > bst->key){
    bst->right = insertBST(key, bst->right);
  }

  return bst;
  }
}

Tree* findBST(int searchVal, Tree* bst){
  if(bst == NULL)
    return NULL;

  if(searchVal < bst->key){
    return findBST(searchVal, bst->left);
  }
  else if(searchVal > bst->key){
    return findBST(searchVal, bst->right);
  }
  else{
    return bst;
  }
  return NULL;
}

void printTree(Tree* bst){
  if(bst == NULL)
    return;
  if(bst->right == NULL){
    printf("%d\n", bst->key);
    return;
  }
  printf("%d -> ", bst->key);
  printTree(bst->right);
}
