
#include "htree.cc"

class HForest {
	public:
		int size() //return how many trees are in the forest.
		void add_tree(tree_ptr_t) //Take a pointer to an HTree (of type HTree::tree_ptr_t) and add it to the forest.
		tree_ptr_t pop_tree() //return a pointer to the HTree with the lowest value in the root node, and remove it from the forest.
		tree_ptr_t compare_trees
		bool compare_trees();
	
	private:
		using forest_heap = std::list<tree_ptr_t>;

}
