#include <iostream>
using namespace std;

enum color {
    BLACK,
    RED
};

// Node class
class Node {

    public:
        int key;
        int color; // 0 for black, 1 for red
        Node *left, *right, *parent;
        

        Node(int key) : key(key) {
            left = right = parent = NULL;
            color = RED; // new nodes are always red by default
        }
        ~Node()
        {
            std::cout << "call Node destruct " << std::endl;
            delete this;
        }
};

class RedBlackTree {
    private:
        Node *root;

        // Helper functions84
        void rotateLeft(Node *x)
        {
            Node *y = x->right;             // node의 right 가 변경되면 이전의 포인터 값을 가져올 수 없으니 미리 저장
            x->right = y->left;
            if (y->left != NULL)
                y->left->parent = x;        // y의 left node를 x의 right-node로 만들고 만약 NULL이 아니라면 left node 의 parent node 는 X가 된다.
            y->parent = x->parent;
            if (x->parent == NULL)          // x 가 root 라면 root 는 y가 됨
                root = y;
            else if (x == x->parent->left)  // x가 원래 parent의 어느쪽 노드인지 확인하고 그 위치에 연결해줌 
                x->parent->left = y;        // left 였다면 y의 parent 는 x->parent 의 left
            else 
                x->parent->right = y;       // 아니면 right
            y->left = x;
            x->parent = y;
        }

        // void rotateRight(Node *x)
        // {

        // }

        // void fixViolation(Node *&root, Node *&newNode)
        // {
    
        // }

        Node *get_node(int key)
        {
            Node *new_node = new Node(key);
            return (new_node);
        }
        void    rb_insert(Node **root, Node *new_node)
        {
            Node *pre_node = NULL;
            Node *cur_node = *root;
            while (cur_node != NULL)
            {
                pre_node = cur_node;
                if (cur_node->key > new_node->key)
                    cur_node = cur_node->left;
                else
                    cur_node = cur_node->right;
            }
            if (cur_node != NULL)
                cur_node->parent = pre_node;
            if (pre_node == NULL)                   // current is root
                *root = new_node;
            else if (pre_node->key > new_node->key)
                pre_node->left = new_node;
            else
                pre_node->right = new_node;
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->color = RED;
        }

    public:
        RedBlackTree() {} 
        void insert(Node **root, int key)
        {
            Node *new_node = get_node(key);
            rb_insert(root, new_node);
        }

      
};


void preorder_traverse(Node *root) //  first meet root node
{
    if (root == NULL)
        return ;
    std::cout << root->key << " ";
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

void inorder_traverse(Node *root) // first meet under left node 
{
    if (root == NULL)
        return ;
    inorder_traverse(root->left);
    std::cout << root->key << " ";
    inorder_traverse(root->right);
    return ;
}

void postorder_traverse(Node *root) // first meed under right node  
{
    if (root == NULL)
        return ;
    postorder_traverse(root->left);
    postorder_traverse(root->right);
    std::cout << root->key << " ";
    return ;
}

int main() {

    RedBlackTree tree;

    {
        Node *root = NULL;
        tree.insert(&root, 11);
        tree.insert(&root, 15);
        tree.insert(&root, 2);
        tree.insert(&root, 10);
        tree.insert(&root, 3);
        tree.insert(&root, 4);
        tree.insert(&root, 1);

        inorder_traverse(root); std::cout << "\n";
        postorder_traverse(root); std::cout << "\n";
        preorder_traverse(root); std::cout << "\n";
    }
    std::cout << "print end of tree" << std::endl;
    return 0;
}