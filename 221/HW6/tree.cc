#include "tree.hh"

//HELPERS
bool
isIn (tree_ptr_t tree, key_type key)
{
    if (!tree)
        return false;
    if (tree->key_ == key)
        return true;
    else if (tree){
        return isIn(tree->left_, key) || isIn(tree->right_, key);
    }
    return false;
}

bool
check (tree_ptr_t tree, key_type key)
{
    if (tree->key_ == key)
        return true;
    else
        return false;
}

//////////////////////////////////////////////////////////////////////////////
tree_ptr_t 
create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left,
            tree_ptr_t right)
{
     // tree_ptr_t node;
    // node = new Tree({key, value, left, right});
    return new Tree({key, value, left, right});
}


//////////////////////////////////////////////////////////////////////////////
void
destroy_tree(tree_ptr_t tree)
{
    if (tree) {
        destroy_tree(tree->left_);
        destroy_tree(tree->right_);
        delete(tree);
    }
}


//////////////////////////////////////////////////////////////////////////////
std::string
path_to(tree_ptr_t tree, key_type key)
{
    std::string path = "";
    auto tmp = tree;
    //base cases
    if (!isIn(tree,key)) return ("-");
    if (tree -> key_ == key) return path;
    while (tree->key_!=key){
        if (tree->left_){
            tmp = tree;
            tree = tree->left_;
            path = path + 'L';
            }
        if (tree->right_){
            tmp = tree;
            tree = tree->right_;
            path = path + 'R';
            }
        if (!tree->left_ && !tree->right_){
            delete(tree);
            path.pop_back();
            tree = tmp;
            }
        }
    return path;

}


//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
node_at(tree_ptr_t tree, std::string path)
{
    char lefty = 'L';
    char righty = 'R';
    for (char c : path){
        if (!tree)
            return nullptr;
        if (c == lefty)
            tree = tree->left_;
        if (c == righty)
            tree = tree->right_;
    }
    return tree;
}