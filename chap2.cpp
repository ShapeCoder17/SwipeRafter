#include<iostream>
#include<algorithm>

using namespace std;

class node{
    public:

    int data;
    int height;
    node* left;
    node* right;

    node(int value){
        data = value;
        left = right = NULL;
        height = 1;
    }


};

class AVL{
    node* root;

    int getheight(node* root){
        if(!root) return 0;
        return root->height;
    }

    int getbalance(node* root){
        if(!root) return 0;
        return getheight(root->left) - getheight(root->right);
    }

    node* rightrotate(node* y){
        node* x = y->left;
        node* t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = max(getheight(y->left),getheight(y->right)) + 1;
        x->height = max(getheight(x->left),getheight(x->right)) + 1;

        return x;
    }

    node* leftrotate(node* x){
        node* y = x->right;
        node* t2 = y->left;

        x->right = t2;
        y->left = x;

        y->height = max(getheight(y->left),getheight(y->right)) + 1;
        x->height = max(getheight(x->left),getheight(x->right)) + 1;

        return y;
    }

    node* minvaluenode(node* root){
        node* current = root;
        while(current->left != NULL) current = current->left;
        return current;
    }
    
    public:
    AVL(){
        root = NULL;
    }

    node* insertion(node* root, int value){
        if(!root) return new node(value);
        if(value < root->data) root->left = insertion(root->left,value);
        else if(value > root->data) root->right = insertion(root->right,value);
        else return root;

        root->height = 1 + max(getheight(root->left), getheight(root->right));
        int balance = getbalance(root);

        if(balance > 1 && root->left->data > value){return rightrotate(root);}
        if(balance > 1 && root->left->data < value){root->left = leftrotate(root->left); return rightrotate(root);}
        if(balance < -1 && root->right->data < value){return leftrotate(root);}
        if(balance < -1 && root->right->data > value){root->right = rightrotate(root->right); return leftrotate(root);}
        
        return root;
    }

    void display_preorder(node* root){
        if(root==NULL){return;}
        else{
            cout<<root->data<<" ";
            display_preorder(root->left);
            display_preorder(root->right);
        }
    }

    node* deletion(node* root, int key){
        if(root==NULL) return root;
        if(key < root->data) root->left = deletion(root->left, key);
        else if(key > root->data) root->right = deletion(root->right, key);
        else{
            if(root->left == NULL){
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                node* temp = root->left;
                delete root;
                return temp;
            }

            node* temp = minvaluenode(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
        return root;
    }
};

int main(){
    AVL avl1;
    node* root = NULL;


    int choice,key;
    bool game=true;

    while(game){
        cout<<"Enter the choice from 1-10: \n";
        cin >> choice;  
        
        switch(choice){
            case 1:
            cout<<"Enter the key: ";
            cin>>key;
            root = avl1.insertion(root,key);
            break;

            case 2:
            avl1.display_preorder(root);
            break;

            case 3:
            game = false;
            break;
        }
    }
}



