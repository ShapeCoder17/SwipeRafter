#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
     node(int value){
        data = value;
        left=right=NULL;
     }
};

class BST{

    node* root;
    BST(){root = NULL;}

    node* search_node(node* root, int value){
        if(!root || root->data == value) return root;
        else{
            if(root->data < value){
                root->left = search_node(root->left,value);
            }
            else{
                root->right = search_node(root->right,value);
            }
        }
    }

    public:

    node* insert_node(node* root, int value){
        if(root==NULL){
            return new node(value);
        }
        else{
            if(root->data < value){
                root->left = insert_node(root->left,value);
            }
            else{
                root->right = insert_node(root->right,value);
            }
            
        }
    }

    void display_inorder(node* root){
        if(root==NULL){return;}
        else{
            display_inorder(root->left);
            cout<<root->data<<" ";
            display_inorder(root->right);
        }
    }

    int count_leafnode(node* root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return count_leafnode(root->left) + count_leafnode(root->right);  
    }

    int count_node(node* root){
        if(!root) return 0;
        return 1 + count_node(root->left) + count_node(root->right);  
    }

    int count_internalnode(node* root){
        if(!root || (!root->left && !root->right)) return 0;
        return count_internalnode(root->left) + count_internalnode(root->right);  
    }

    void display_leafnode(node* root){
        if(!root) return;
        if(!root->left && !root->right) cout<<root->data<<" ";

        display_leafnode(root->left);
        display_leafnode(root->right);  
    }

    void display_internalnode(node* root){
        if(!root || (!root->left && !root->right)) return;

        cout<<root->data<<" ";
        display_internalnode(root->left);
        display_internalnode(root->right);  
    }

    int sum_node(node* root){
        if(!root) return 0;
        return root->data + count_node(root->left) + count_node(root->right);
    }

    int subtree_sum(node* root, int key){
        node* target = search_node(root, key);
        return sum_node(target);
    }
};