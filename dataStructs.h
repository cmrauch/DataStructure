/* Binary Tree Implementation
 *
 * Description:
 *     Maintains a binary tree. Uses template types
 */
template <class T>
class binaryTree {

    //internal node container
	struct node {
    T val;
    node *rightNode;
    node *leftNode;  
    node(T rVal): val(rVal), rightNode(nullptr), leftNode(nullptr){} 
    };

    public:
        binaryTree() : root(nullptr){};
        ~binaryTree() {destroyTree();}

        void insert(const T &val) {insert(val, &root);}
        void destroyTree() {destroy(root);}
        T* find(const T &val);
        
        bool isEmpty() {return ( (root==nullptr) ? true:false);}
        
    private:
        void destroy(node *treeNode);
        void insert(const T &val, node **ptr);

    private:
        node *root;
};

/* Insert
 *
 */
template <class T>
void binaryTree<T>::insert(const T &val, node **ptr) {

	if(*ptr == nullptr) {
		*ptr = new node(val);
        return;
    }
    if(val < (*ptr)->val)
        insert(val, &((*ptr)->leftNode));
    else
        insert(val, &((*ptr)->rightNode));
}

template <class T>
void binaryTree<T>::destroy(node *nodePtr) {
    if(nodePtr == nullptr)
        return;

    destroy(nodePtr->rightNode);
    destroy(nodePtr->leftNode);

    delete nodePtr;
}

/* Search
 *
 */
template <class T>
T* binaryTree<T>::find(const T &val) {

}
