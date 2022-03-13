#include "tree.cc"



int main(){
    Tree* root;
//Create root
    root = create_tree(126, 1, nullptr, nullptr);
//Add children to root to create the tree
/*
            126
           /   \
          /     \
        -5       12
        / \     /
      12   6   3
          /
         9
*/
//left side
    root->left_ = create_tree(-5, 1, nullptr, nullptr);
    root->left_->left_ = create_tree(12, 1, nullptr, nullptr);
    root->left_->right_ = create_tree(6, 1, nullptr, nullptr);
    root->left_->right_->left_ = create_tree(9, 1, nullptr, nullptr);
//right side
    root->right_ = create_tree(12, 1, nullptr, nullptr);
    root->right_->left_ = create_tree(3, 1, nullptr, nullptr);

    return 0;
}