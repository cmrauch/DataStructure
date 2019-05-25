/* Binary Tree Implementation
 *
 * Description:
 *     Maintains a binary tree. Uses template types
 */
template <class T>
class binaryTree {
	
	struct node {
    T val;
    node *rightNode;
    node *leftNode;  
    node(T rVal): val(rVal), rightNode(nullptr), leftNode(nullptr){} 
    };

    public:
        binaryTree() : root(nullptr){};
        ~binaryTree() {destroyTree();}

        void insert(T val) {insert(val, root);}
        void destroyTree();
        T* search(T val);
        
        bool isEmpty() {return ( (root==nullptr) ? true:false);}
        
    private:
        void destroy(T *treeNode);
        void insert(T val, node *ptr);

    private:
        node *root;
};

/* Insert
 *
 */
template <class T>
void binaryTree<T>::insert(T val, node *ptr) {
	
	
	if( isEmpty() )
		root = new node(val);
		
	else if (ptr->leftNode == nullptr) {
		ptr->leftNode = new node(val);
	}
	
	else if (ptr->rightNode == nullptr){
		ptr->rightNode = new node(val);
	}

}

/* Destroy Tree
 *
 *
 */
template <class T>
void binaryTree<T>::destroyTree() {
    if(root == nullptr)
        return;

    delete(root->rightNode);
    delete(root->leftNode);
}

template <class T>
void binaryTree<T>::destroy(T *node) {
    if(node == nullptr)
        return;

    destroy(node->rightNode);
    destroy(node->leftNode);
}

/* Search
 *
 */
template <class T>
T* binaryTree<T>::search(T val) {

}
