#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_t *binary_tree_node - Insert node in left o rigth position
 * @parent: The node of the tree node.
 * @value: Value that insert in the tree
 * Return: Return the tree with the all positions
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node = malloc(sizeof(binary_tree_t));
if (node == NULL)
return (NULL);
node->parent = parent;
node->n = value;
node->left = node->right = NULL;
return (node);
}
