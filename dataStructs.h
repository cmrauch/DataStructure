/* Binary Tree Implementation
 *
 * Description:
 *     Maintains a binary tree. Uses template types
 */
#ifndef BINARYTREE
 #define BINARYTREE
 #include <iostream>
 using namespace std;
 
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
        void dispTree() {inOrderDisplay(root);}
        T getRoot() {return root->val;}
        
        bool isEmpty() {return ( (root==nullptr) ? true:false);}
        
    private:
        void destroy(node *treeNode);
        void insert(const T &val, node **ptr);
        void inOrderDisplay(node *root) const;

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

/* Destroy
 *
 */
template <class T>
void binaryTree<T>::destroy(node *nodePtr) {
    if(nodePtr == nullptr)
        return;

    destroy(nodePtr->leftNode);
    destroy(nodePtr->rightNode);

    delete nodePtr;
}

/* Find
 *
 */
template <class T>
T* binaryTree<T>::find(const T &val) {
    //TODO
}
/* InOrder Display
 *
 * Uses InOrder traversal to display
 */
template <class T>
void binaryTree<T>::inOrderDisplay(node *root) const {
    if(root == nullptr)
        return;
        
    inOrderDisplay(root->leftNode);
    cout << root->val << " ";
    inOrderDisplay(root->rightNode);    
}

#endif

#ifndef LINKEDLIST
#define LINKEDLSIT

template <class T>
class LinkedList {
    struct node {
        T val;
        node *next;
        node(const T &rVal) : val(rVal), next(nullptr) {} 
    };

    public:
        LinkedList() : head(nullptr), tail(nullptr), size(0) {}
        LinkedList(const LinkedList &rhs);//
        ~LinkedList() {destroyList();}

        void destroyList() {destroy(head);}

        T get_front() {return head->val;}
        T get_back() {return tail->val;}
        void pop_front();//
        void pop_back();//
        void push_front(const T &rVal);//
        void push_back(const T &rVal);//

        bool remove(const T &target);//
        bool removeAll(const T &target);//
        void swap(T lhs, T rhs);
        bool isEmpty() {return ((size == 0) ? true:false);}
        node* getHead() {return head;} 

    private:
        void destroy(node *nodePtr);

    private:
        node *head;
        node *tail;
        int size;
};

/* Copy Constructor
 *
 */
template <class T>
LinkedList<T>::LinkedList(const LinkedList &rhs) : head(nullptr), tail(nullptr), size(0) {
    node *oldList = rhs.head;
    node *newList1 = nullptr, *newList2 = nullptr;
    int rSize = rhs.size;
    
    //copy list 
    for( ; this->size < rSize; ++this->size, oldList = oldList->next) {
        if(this->size == 0)
            this->head = this->tail = newList1 = newList2 = new node(oldList->val);
        else if(this->size == (rSize-1))
            this->tail = new node(oldList->val);
        else {
            newList2 = new node(oldList->val);
            newList1->next = newList2;
        }
    }
}

/* push_front
 *
 */
template <class T>
void LinkedList<T>::push_front(const T &rVal) {
    if(size == 0)
        head = tail = new node(rVal);

    else {
        node *temp = head;
        head = new node(rVal);
        head->next = temp;
    }
    ++size;
}

/* push_back
 *
 */
template <class T>
void LinkedList<T>::push_back(const T &rVal) {
    if(size == 0)
        head = tail = new node(rVal);

    else {
        node *temp = tail;
        tail = new node(rVal);
        temp->next = tail;
    }
    ++size;
}

/* pop_front
 *
 * deletes the head element from the list
 */
template <class T>
void LinkedList<T>::pop_front() {
    if(size == 0)
        return;
        
    else if(size == 1) {
        delete head;
        head = tail = nullptr;
        --size;
    }
    else {
        node *temp = head;
        head = head->next;
        delete temp;
        --size;
    }
}

/* pop_back
 *
 * deletes the tail element from the list
 */
template <class T>
void LinkedList<T>::pop_back() {
    if(size == 0)
        return;
        
    else if(size == 1) {
        delete tail;
        head = tail = nullptr;
        --size;
    }
    else {
        delete tail;
        tail = head;
        //iterate till the second to last eliment
        for(int x = 0; x < (size-2); ++x, tail = tail->next);
        tail->next = nullptr;
        --size;
    }
}

/* remove
 *
 * deletes the first target element in the array
 * use deleteAll() function to delete every instance
 */
template <class T>
bool LinkedList<T>::remove(const T &target) {
    node *temp1 = head;
    node *temp2 = head->next;

    //check the head
    if(head == target) {
        pop_front();
        return true;
    }
        
    //search for the element
    for( ; temp2 != nullptr; temp1 = temp1->next, temp2 = temp2->next) 
        //break early if the element is found
        if(temp2->val == target)
            break;
            
    //if element was not found
    if (temp2 == nullptr)
        return false;
    //if it was found
    else {
        temp1->next = temp2->next;
        delete temp2;
        --size;
    }
}

/* removeAll
 *
 * removes every target element
 */
template <class T>
bool LinkedList::removeAll(const T &target) {
    while(remove(target));
    return true;
}
#endif
