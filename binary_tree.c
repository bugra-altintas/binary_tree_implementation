#include <stdio.h>
#include <math.h>
#include "binary_tree.h"


int is_empty(int binary_tree[MAX_LENGTH]){
    if(binary_tree[0] == -1){
        return 1;
    }
    return 0;
}
int is_leaf(int binary_tree[MAX_LENGTH],int root){
    if(2*root+1>MAX_LENGTH){
        return 1;
    }
    if((binary_tree[2*root+1] == -1) && (binary_tree[2*root+2] == -1)){
        return 1;
    }
    return 0;
}
void initialize_the_tree(int binary_tree[MAX_LENGTH], int get_values_from_user) {
    int i;
    for(i=0;i<=MAX_LENGTH;i++){
    binary_tree[i] = -1;
    }
    if(get_values_from_user!=0){
        int i=0,number_of_values;
        scanf("%d",&number_of_values);
        while(i<number_of_values){
            int index,value;
            scanf("%d %d",&index,&value);
            if(0<=index && index<=MAX_LENGTH && binary_tree[index]==-1){
                binary_tree[index] = value;
            }
            else{
                i++;
                continue;
            }
        i++;
        }
    }
}

void insert_node(int binary_tree[MAX_LENGTH], int node, char where, int value) {

    if(where=='i'){
        if(node>MAX_LENGTH){
            return ;
        }
        if(binary_tree[node]==-1){
            binary_tree[node] = value;
        }
    }
    else if(where=='l'){
        if(2*node+1>MAX_LENGTH){
            return ;
        }
        if(binary_tree[2*node+1]==-1 && binary_tree[node] != -1){
            binary_tree[2*node+1] = value;
        }
    }
    else if(where=='r'){
        if(2*node+2>MAX_LENGTH){
            return ;
        }
        if(binary_tree[2*node+2]==-1 && binary_tree[node] != -1){
            binary_tree[2*node+2] = value;
        }
    }
}

void delete_node_rec(int binary_tree[MAX_LENGTH], int node) {
    if(node>MAX_LENGTH){
        return ;
    }
    else if(node == MAX_LENGTH){
        binary_tree[node] = -1;
        return ;
    }
    binary_tree[node] = -1;
    if(binary_tree[2*node+1]!=-1){
        delete_node_rec(binary_tree,2*node+1);
    }
    if(binary_tree[2*node+2]!=-1){
        delete_node_rec(binary_tree,2*node+2);
    }
}

void tab_func(int depth){
    if(depth == 0){
        return;
    }
    if(depth>0){
        printf("\t");
        tab_func(depth-1);
    }
}
void draw_binary_tree_rec(int binary_tree[MAX_LENGTH], int root, int depth) {
    if(root>MAX_LENGTH){
        return ;
    }
    if(is_empty(binary_tree)){
        return;
    }
    if (is_leaf(binary_tree,root)&&(binary_tree[root]!=-1)){
        tab_func(depth);
        printf("%d\n",binary_tree[root]);
    }
    if (!(is_leaf(binary_tree,root))){
        if(binary_tree[2*root+1] != -1){
            draw_binary_tree_rec(binary_tree,2*root+1,depth-1);
        }
        tab_func(depth);
        printf("%d\n",binary_tree[root]);
        if(binary_tree[2*root+2] != -1){
            draw_binary_tree_rec(binary_tree,2*root+2,depth-1);
        }
    }
}

int helper_max(int a,int b){
    if(a>=b){
        return a;
    }
    return b;
}
int find_height_of_tree_rec(int binary_tree[MAX_LENGTH], int root) {
    if(root > MAX_LENGTH){
        return 0;
    }
    if(is_leaf(binary_tree,root)){
        return 0;
    }
    if(is_empty(binary_tree)){
        return 0;
    }

    if(!(is_leaf(binary_tree,root))){

        return 1 + helper_max(find_height_of_tree_rec(binary_tree,2*root+1),find_height_of_tree_rec(binary_tree,2*root+2));
    }

    return 0;
}

int helper_min(int a,int b){
    if(a>=0 && b>=0){
        if(a<=b){
            return a;
        }
        return b;
    }
    else{
        if(b>0){
            return b;
        }
        return a;

    }
}
int find_min_of_tree_rec(int binary_tree[MAX_LENGTH], int root) {
    if(root > MAX_LENGTH){
        return -1;
    }
    if(is_leaf(binary_tree,root)){
        return binary_tree[root];
    }
    else{
        return helper_min(binary_tree[root],helper_min(find_min_of_tree_rec(binary_tree,2*root+1),find_min_of_tree_rec(binary_tree,2*root+2)));
    }
    return MIN_VAL;
}

int breadth_first_search_itr(int binary_tree[MAX_LENGTH], int root, int value) {
    int lower_bound = root;
    int upper_bound = root;
    int i;
    if(root > MAX_LENGTH){
        return -1;
    }
    while(upper_bound<=MAX_LENGTH){

        for(i=lower_bound;i<=upper_bound;i++){
            if(binary_tree[i]==value){
                return i;
            }
        }
    lower_bound = 2*lower_bound + 1;
    upper_bound = 2*upper_bound + 2;

    }
    if(upper_bound>MAX_LENGTH){

        for(i=lower_bound;i<=MAX_LENGTH;i++){
            if(binary_tree[i]==value){
                return i;
            }
        }
    }
    return -1;
}


int depth_first_search_rec(int binary_tree[MAX_LENGTH], int root, int value) {
    if(root > MAX_LENGTH){
        return -1;
    }
    if(is_leaf(binary_tree,root) && binary_tree[root] == value){
        return root;
    }
    if(!is_leaf(binary_tree,root)){
        int legal;
        legal = depth_first_search_rec(binary_tree,2*root+1,value);
            if(legal == -1){
                if(binary_tree[root] == value){
                    return root;
                }
                return depth_first_search_rec(binary_tree,2*root+2,value);
            }
            return legal;
    }
    return -1;
}

void print_binary_tree_values(int binary_tree[MAX_LENGTH]) {
    int i;
    for (i = 0; i < MAX_LENGTH; i++) {
        if (binary_tree[i] != -1) {
            printf("%d - %d\n", i, binary_tree[i]);
        }
    }

}
