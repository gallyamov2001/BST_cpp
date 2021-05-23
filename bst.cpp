#include "bst.h"

using namespace std;

template<typename T>
Node<T>::Node(T _data){
    this->data = _data;
    this->left = nullptr;
    this->right = nullptr;
}


template<typename T>
T Node<T>::get_data(){
    return data;
}

template<typename T>
void Node<T>::Print(){
    if(this->left != nullptr){
        (this->left)->Print();
    }
    cout << this->data << " ";
    if(this->right != nullptr){
        (this->right)->Print();
    }
}

template<typename T>
T Node<T>::Min(){
    Node<T>* next_node = this;
    Node<T>* current_node = this;
    while(next_node != nullptr){
        current_node = next_node;
        next_node = next_node->left;
    }
    return current_node->data;
}

template<typename T>
T Node<T>::Max(){
    Node<T>* next_node = this;
    Node<T>* current_node = this;
    while(next_node != nullptr){
        current_node = next_node;
        next_node = next_node->right;
    }
    return current_node->data;
}

template<typename T>
Tree<T>::Tree(){
    root = nullptr;
}

template<typename T>
void Tree<T>::Print(){
    root->Print();
}

template<typename T>
void Tree<T>::Insert(T _data){
    Node<T> *node = new Node<T>(_data);
    if(root == nullptr){
        root = node;
        return;
    }
    Node<T>* next_node = root;
    Node<T>* current_node = root;
    while(next_node != nullptr){
        current_node = next_node;
        if(_data < current_node->data){
            next_node = next_node->left;
        }
        else{
            next_node = next_node->right;
        }
    }
    if(_data < current_node->data){
        current_node->left = node;
    }
    else{
        current_node->right = node;
    }
}




template<typename T>
Node<T>* Tree<T>::Search(T _data){
    if(root == nullptr){
        return nullptr;
    }
    Node<T>* next_node = root;
    while(next_node != nullptr && next_node->data != _data){
        if(_data < next_node->data){
            if(next_node->left != nullptr){
                next_node = next_node->left;
            }
            else{
                cerr << "Node wasn't found\n";
                throw Node<T>::INVARG;
                return nullptr;
            }
        }
        else{
            if(_data == next_node->data){
                return next_node;
            }
            if(next_node->right != nullptr){
                next_node = next_node->right;
            }
            else{
                cerr << "Node wasn't found\n";
                throw Node<T>::INVARG;
                return nullptr;
            }
        }
    }
    return next_node;
}

template<typename T>
T Tree<T>::Min(){
    return root->Min();
}

template<typename T>
T Tree<T>::Max(){
    return root->Max();
}



template<typename T>
Node<T>* Node<T>::DeleteNode(T _data){
    if(_data < this->data && this->left != nullptr)
        this->left = (this->left)->DeleteNode(_data);
    else if(_data > this->data && this->right != nullptr)
        this->right = (this->right)->DeleteNode(_data);
    //далее ситуация, когда мы нашли удаляемый узел
    else if(this->data == _data){
        if(this->right != nullptr){
            this->data = (this->right)->Min();
            this->right = (this->right)->DeleteNode(this->data);
        }
        else if(this->left != nullptr){
            this->data = (this->left)->Max();
            this->left = (this->left)->DeleteNode(this->data);
        }
        else{
            delete this;
            return nullptr;
            //this = nullptr;
        }
    }
    else{ //значит такой вершины нет
        cerr << "Node wasn't found\n";
        throw INVARG;
        return nullptr;
    }
    
    return this;
    
}


template<typename T>
void Tree<T>::Remove(T _data){
    if(root == nullptr){
        cerr << "Empty tree\n";
        throw Node<T>::EMPTY;
    }
    else{
        //Node<T>* node_d = root;
        root = root->DeleteNode(_data);
        return;
    }
}


template<typename T>
void Node<T>::TreeDel(){
    if(this->left != nullptr)
        (this->left)->TreeDel();
    if(this->right != nullptr)
        (this->right)->TreeDel();
    delete this;
}


template<typename T>
Tree<T>::~Tree(){
    (this->root)->TreeDel();
}

/*
int main(){
    Node<int>* node_d = nullptr;
    node_d = new Node<int>(7);
    Tree<int> tree_n;
    //Tree<int> tree_d;
    
    
    
    int nums[14] = {17, 101, 9, 23, 55, 17, 24, 34, 11, 99, 54, 24, 100, 9};
    for(int i = 0; i < 14; ++i){
        tree_n.Insert(nums[i]);
    }
    cout << "Tree is: ";
    
    
    try{                //1
        tree_n.Print();
        cout << "\n";
    } catch(...){
        cout << "Test_1\tfailed" << endl;
    }   cout << "Test_1\tpassed" << endl;
    
    
    try{                //2
        node_d = tree_n.Search(1001);
    } catch(Node<int>::node_error &ex){
        if(ex == Node<int>::INVARG){
            cout << "Test_2\tpassed" << endl;
        }
        else{
            cout << "Test_2\tfailed" << endl;
        }
    } catch(...){
        cout << "Test_2\tfailed" << endl;
    }
    
    
    try{                //3
        node_d = tree_n.Search(23);
    } catch(...){
        cout << "Test_3\tfailed" << endl;
    }   cout << "Test_3\tpassed" << endl;
    
    
    try{                //4
        node_d = tree_n.Search(-1000);
    } catch(const Node<int>::node_error &ex){
        if(ex == Node<int>::INVARG){
            cout << "Test_4\tpassed" << endl;
        }
        else{
            cout << "Test_4\tfailed" << endl;
        }
    } catch(...){
        cout << "Test_4\tfailed" << endl;
    }
    
    try{                //5
        node_d = tree_n.Search(25);
    } catch(const Node<int>::node_error &ex){
        if(ex == Node<int>::INVARG){
            cout << "Test_5\tpassed" << endl;
        }
        else{
            cout << "Test_5\tfailed" << endl;
        }
    } catch(...){
        cout << "Test_5\tfailed" << endl;
    }
    
    try{                //6
        node_d = tree_n.Search(87);
    } catch(const Node<int>::node_error &ex){
        if(ex == Node<int>::INVARG){
            cout << "Test_6\tpassed" << endl;
        }
        else{
            cout << "Test_6\tfailed" << endl;
        }
    } catch(...){
        cout << "Test_6\tfailed" << endl;
    }
    
    try{                //7
        cout << "Max is " << tree_n.Max() << endl;
    } catch(...){
        cout << "Test_7\tfailed" << endl;
    }   cout << "Test_7\tpassed" << endl;
    
    try{                //8
        cout << "Min is " << tree_n.Min() << endl;
    } catch(...){
        cout << "Test_8\tfailed" << endl;
    }   cout << "Test_8\tpassed" << endl;
    
    try{                //9
        node_d = tree_n.Search(17);
        cout << node_d->get_data() << endl;
    } catch(...){
        cout << "Test_9\tfailed" << endl;
    }   cout << "Test_9\tpassed" << endl;
    
    try{                //10
        node_d = tree_n.Search(101);
        cout << node_d->get_data() << endl;
    } catch(...){
        cout << "Test_10\tfailed" << endl;
    }   cout << "Test_10\tpassed" << endl;
    
    try{                //11
        node_d = tree_n.Search(9);
        cout << node_d->get_data() << endl;
    } catch(...){
        cout << "Test_11\tfailed" << endl;
    }   cout << "Test_11\tpassed" << endl;
    
    try{                //12
        node_d = tree_n.Search(23);
        cout << node_d->get_data() << endl;
    } catch(...){
        cout << "Test_12\tfailed" << endl;
    }   cout << "Test_12\tpassed" << endl;
    
    try{                //13
        node_d = tree_n.Search(55);
        cout << node_d->get_data() << endl;
    } catch(...){
        cout << "Test_13\tfailed" << endl;
    }   cout << "Test_13\tpassed" << endl;
    
    try{                //14
        node_d = tree_n.Search(24);
        cout << node_d->get_data() << endl;
    } catch(...){
        cout << "Test_14\tfailed" << endl;
    }   cout << "Test_14\tpassed" << endl;
    
    try{                //15
        node_d = tree_n.Search(34);
        cout << node_d->get_data() << endl;
    } catch(...){
        cout << "Test_15\tfailed" << endl;
    }   cout << "Test_15\tpassed" << endl;
    
    try{                //16
        node_d = tree_n.Search(99);
        cout << node_d->get_data() << endl;
    } catch(...){
        cout << "Test_16\tfailed" << endl;
    }   cout << "Test_16\tpassed" << endl;
    
    try{                //17
        tree_n.Remove(99);
    } catch(...){
        cout << "Test_17\tfailed" << endl;
    }   cout << "Test_17\tpassed" << endl;
    
    try{                //18
        tree_n.Remove(34);
    } catch(...){
        cout << "Test_18\tfailed" << endl;
    }   cout << "Test_18\tpassed" << endl;
    
    try{                //19
        tree_n.Remove(24);
    } catch(...){
        cout << "Test_19\tfailed" << endl;
    }   cout << "Test_19\tpassed" << endl;
    
    try{                //20
        tree_n.Remove(101);
    } catch(...){
        cout << "Test_20\tfailed" << endl;
    }   cout << "Test_20\tpassed" << endl;
    
    try{                //21
        tree_n.Remove(9);
    } catch(...){
        cout << "Test_21\tfailed" << endl;
    }   cout << "Test_21\tpassed" << endl;
    
    try{                //22
        tree_n.Remove(9);
    } catch(...){
        cout << "Test_22\tfailed" << endl;
    }   cout << "Test_22\tpassed" << endl;
    
    
    try{                //23
        tree_n.Print();
        cout << endl;
    } catch(...){
        cout << "Test_23\tfailed" << endl;
    }   cout << "Test_23\tpassed" << endl;
    
    try{                //24
        tree_n.Insert(9);
    } catch(...){
        cout << "Test_24\tfailed" << endl;
    }   cout << "Test_24\tpassed" << endl;
    tree_n.Print();
    cout << endl;
    
    try{                //25
        tree_n.Insert(18);
        tree_n.Print();
        cout << endl;
    } catch(...){
        cout << "Test_25\tfailed" << endl;
    }   cout << "Test_25\tpassed" << endl;
    tree_n.Print();
    cout << endl;
    
    try{                //26
        tree_n.Insert(101);
    } catch(...){
        cout << "Test_26\tfailed" << endl;
    }   cout << "Test_26\tpassed" << endl;
    tree_n.Print();
    cout << endl;
    
    try{                //27
        tree_n.Insert(24);
    } catch(...){
        cout << "Test_27\tfailed" << endl;
    }   cout << "Test_27\tpassed" << endl;
    
    try{                //28
        tree_n.Insert(34);
    } catch(...){
        cout << "Test_28\tfailed" << endl;
    }   cout << "Test_28\tpassed" << endl;
    
    try{                //29
        tree_n.Insert(99);
    } catch(...){
        cout << "Test_29\tfailed" << endl;
    }   cout << "Test_29\tpassed" << endl;
    
    try{                //30
        tree_n.Insert(-88);
    } catch(...){
        cout << "Test_30\tfailed" << endl;
    }   cout << "Test_30\tpassed" << endl;
    
    
    node_d = tree_n.Search(99);
    cout << node_d->get_data() << endl;
    cout << 0 << endl;
    cout << tree_n;
    cout << endl;
    cout << 1 << endl;
    node_d = tree_n.Search(34);
    cout << node_d->get_data() << endl;
    cout << 2 << endl;
    cout << node_d;
    
    
    
    return 0;

}
*/
