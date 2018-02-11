/*
 * tree.c: testing queue using binary trees
 */

# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>

# include "queue.h"

struct tree {
  struct tree *left, *right;
  int key;
};

struct tree* build_tree(long depth, int *key)
{
  struct tree *node = NULL;
  if (depth >= 0) {
    node = malloc(sizeof (struct tree));
    if (!node)
      err(1, "tree node allocation failed, dying");
    node->left = build_tree(depth - 1, key);
    *key += 1;
    node->key = *key;
    node->right = build_tree(depth - 1, key);
  }
  return node;
}

void bfs(struct tree *root)
{
  if (root)
  {
    struct queue *q = malloc(sizeof(struct queue));
    queue_init(q);
    queue_push(q, root);
    queue_push(q, NULL);
    while (queue_is_empty(q) != 0)
    {
      struct tree *node = queue_pop(q);
      if (node)
      {
        printf("%d ", node->key);
        if (node->left)
        {
          queue_push(q, node->left);
        }
        if (node->right)
        {
          queue_push(q, node-right);
        }
      }
      else
      {
        printf("\n");
        if (queue_is_empty(q) != 0)
        {
          queue_push(q, NULL);
        }
      }
    }
  }
}

void delete_tree(struct tree *root)
{
  if (root) {
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
  }
}

int main(int argc, char *argv[])
{
  long depth = 3;
  if (argc > 1)
    depth = strtol(argv[1], NULL, 10);
  int key = 0;
  struct tree *root = build_tree(depth, &key);
  bfs(root);
  delete_tree(root);
  return 0;
}
