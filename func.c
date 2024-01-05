#include "binary_trees.h"

#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void) {
  binary_tree_t *root;

  root = binary_tree_node(NULL, 98);
  root->left = binary_tree_node(root, 12);
  root->right = binary_tree_node(root, 402);
  binary_tree_print(root);
  printf("\n");
  binary_tree_insert_left(root->right, 128);
  binary_tree_insert_left(root, 54);
  binary_tree_print(root);
  return (0);
}

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value) {

  binary_tree_t *new;

  if (!parent)
    return (NULL);
  new = malloc(sizeof(struct binary_tree_s));
  if (!new)
    return (NULL);
  new->parent = parent;
  new->n = value;
  new->right = NULL;
  new->left = parent->left;
  if (parent->left) {
    parent->left->parent = new;
  }
  parent->left = new;

  return (new);
}
