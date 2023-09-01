#include <stdlib.h>
#include "binary_trees.h"

/**
 * head_t *heap_insert - Inserts the nodes depending the size of the value
 * @root: Node for inserts values
 * @value: Value that insert in the node
 * Return: The new node with the nuews values
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (*root == NULL) {
        *root = binary_tree_node(NULL, value);
        return *root;
    }

    heap_t *new_node = binary_tree_node(NULL, value);
    heap_t *current = *root;

    while (current->left != NULL && current->right != NULL) {
        if (value >= current->n) {
            int temp = current->n;
            current->n = value;
            value = temp;
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current->left == NULL) {
        current->left = new_node;
    } else {
        current->right = new_node;
    }

    while (new_node->parent != NULL && new_node->n > new_node->parent->n) {
        int temp = new_node->n;
        new_node->n = new_node->parent->n;
        new_node->parent->n = temp;
        new_node = new_node->parent;
    }

    return new_node;
}