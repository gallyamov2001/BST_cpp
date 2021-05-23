#include <iostream>

using namespace std;

template <typename T> class Tree;

template<typename T>
class Node{
protected:
    T data;
    Node<T>* left;
    Node<T>* right;
public:
    enum node_error{
        INVARG,
        EMPTY,
        MEMORY
    };
    
    Node(T _data);
    //~Node();
    T get_data();
    void Print();
    T Min();
    T Max();
    Node<T>* DeleteNode(T _data);
    void TreeDel();
    friend ostream &operator<<(ostream &output, Node<T>* node) {
        if(node->left != nullptr){
            output << node->left;
        }
        output << node->data << " ";
        if(node->right != nullptr){
            output << node->right;
        }
        return output;
    };
    friend class Tree<T>;
};


template<typename T>
class Tree{
    
public:
    Tree();
    //Tree(T _data);
    ~Tree();
    void Print();
    void Insert(T _data);
    Node<T>* Search(T _data);
    T Min();
    T Max();
    void Remove(T _data);
    friend ostream &operator<<(ostream &output, Tree<T> &tree) {
        Node<T>* node = tree.root;
        if(node->left != nullptr){
            output << node->left;
        }
        output << node->data << " ";
        if(node->right != nullptr){
            output << node->right;
        }
        return output;
    };
    

private:
    Node<T>* root;
};

