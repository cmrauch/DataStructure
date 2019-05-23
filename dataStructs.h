/* Binary Tree Implementation
 *
 * Description:
 *     Maintains a binary tree. Uses template types
 */
template <class T>
class binaryTree {

    public:
        binaryTree();
        ~binaryTree();

        void insert(T val);
        void destroyTree();
        void delete(T* node);
        T* search(T val);

    private:
        T *root;
};

/* Node Container
 *
 * Description
 *     A container to hold each node in the binary tree
 */
template <class T>
struct node {
    T val;
    node *rightNode;
    node *leftNode;
};

/* Constructor
 *
 */
template <class T>
binaryTree::binaryTree() {
    this->root = nullptr;
}

/* Destructor
 *
 */
template <class T>
binaryTree::~binaryTree() {
     destroyTree();
 }

/* Insert 
 *
 */
void binaryTree::insert(T val) {
    
}

/* Destroy Tree
 *
 */
void binaryTree::destroyTree() {
    if(root == nullptr) 
        return;

    delete(root->rightNode);
    delete(root->leftNode);
}

template <class T>
void delete(T *node) {
    if(node == nullptr)
        returm;
        
    delete(node->rightNode);
    delete(node->leftNode);
}

/* Search
 *
 */
T* binaryTree::search(T val) {
    
}
