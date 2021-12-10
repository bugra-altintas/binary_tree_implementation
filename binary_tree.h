#ifndef THE1_H
#define THE1_H

#define MAX_LENGTH 1000
#define MAX(a, b) (a<b) ? (b) : (a)
#define MIN(a, b) (a>b) ? (b) : (a)
#define MAX_VAL 999999
#define MIN_VAL 0

/*
 * This function gets a parameter that indicates whether user will give initial values or not. If it evaluates false,
 * it simply sets all values of thearray -1. Otherwise,it scans an integer from the user stating the number
 * of values that s/he willenter. User will enter that many integer index and value pairs. If the value for that index
 * is insertedbefore, or the index or the value is out of the range, it simply ignores it.
*/
void initialize_the_tree(int binary_tree[MAX_LENGTH], int get_values_from_user);

/*
 * This function gets index of parent node, 'l'eft, 'r'ight or 'i'tself for where to insert and integer value.
 * If the value for the inserted node already exists, it ignores and does nothing.
 */
void insert_node(int binary_tree[MAX_LENGTH], int node, char where, int value);

/*
 * This method  gets  the  index  of  the  node  to  be  deleted.   If  a  node  is  to  be deleted, all of its
 * descendants will be also purged.  Deleting means putting -1 value to the proper area in the array.
 */
void delete_node_rec(int binary_tree[MAX_LENGTH], int node);

/*
 * This is a recursive function that prints the tree in pre-order fashion.  In other words, it will print the nodes
 * starting from the left-most child and and traverse the rest of the tree in that manner.  It gets the index of the
 * root and the depth value as control variable. Initial value of the depth will be the height of the tree.
 */
void draw_binary_tree_rec(int binary_tree[MAX_LENGTH], int root, int depth);

/*
 * This is a recursive function that returns the height of the tree.  If given root does not have any child, its height
 * is 0.
 */
int find_height_of_tree_rec(int binary_tree[MAX_LENGTH], int root);

/*
 * This is a recursive function that returns the minimum value given tree contains.
 */
int find_min_of_tree_rec(int binary_tree[MAX_LENGTH], int root);

/*
 * This is an iterative function that performs breadth-first search on the given tree.  If the value does not appear
 * in the given tree,  it returns -1.  Otherwise,  it returns the index of the first observation of the value.
 * It gets the index of the root and the integer value that is to be searched. It applies level-wise search in the tree
 */
int breadth_first_search_itr(int binary_tree[MAX_LENGTH], int root, int value);

/*
 * This is  a recursive  function  that  performs  depth-first search on the given tree.  If the value does not appear
 * in the given tree,  it returns -1.  Otherwise,  it returns the index of the first observation of the value.  It gets
 * the index of the root and the integer valuethat is to be searched.
 */
int depth_first_search_rec(int binary_tree[MAX_LENGTH], int root, int value);

/*
 * This function prints the binary tree.
 */
void print_binary_tree_values(int binary_tree[MAX_LENGTH]);

#endif
