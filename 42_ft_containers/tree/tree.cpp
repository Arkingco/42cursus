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

        void rotateRight(Node *y)
        {
            Node *x = y->left;             // node의 left 가 변경되면 이전의 포인터 값을 가져올 수 없으니 미리 저장
            y->left = x->right;
            if (x->right != NULL)
                x->right->parent = y;
            x->parent = y->parent;
            if (y->parent == NULL)
                root = x;
            else if (y->parent->left == y)
                y->parent->left = x;
            else
                y->parent->right = x;
            x->right = y;
            y->parent = x;
        }

        void fixViolation(Node *&root, Node *&new_node)
        {
            std::cout << "in fixViloation" << std::endl;
            while(1)
            {
                // new_node 가 root일 경우
                if (root == new_node)
                {
                    std::cout << "new node is root and change black" << std::endl;
                    new_node->color = BLACK;
                    return ;
                }

                if (new_node->parent->color == RED)
                {
                    std::cout << "new node parent is red" << std::endl;
                    // 내 부모가 red 라는 얘기는 무조건 할아버지 노드(black)이 있다는 뜻
                    Node *parent = new_node->parent;
                    Node *grandFather = parent->parent;
                    // 내 부모가 할아버지의 왼쪽 노드라면
                    if (grandFather->left == parent)
                    {
                        // 내가 부모의 왼쪽 노드라면
                        if (new_node == parent->left)
                        {
                            // case 1 삼촌이 red
                            if (grandFather->right->color == RED)
                            {
                                grandFather->left->color = BLACK;
                                grandFather->right->color = BLACK;
                                grandFather->color = RED;
                            }
                            // case 2 삼촌이 black
                            else
                            {
                                parent->color = BLACK;
                                grandFather->color = RED;
                                rotateRight(parent);
                            }
                        }
                        // 내가 부모의 오른쪽 노드라면
                        else
                        {
                            // case 1 삼촌이 red
                            if (grandFather->right->color == RED)
                            {
                                grandFather->left->color = BLACK;
                                grandFather->right->color = BLACK;
                                grandFather->color = RED;
                            }
                            // case 2 삼촌이 black
                            else
                            {
                                rotateLeft(parent);
                                parent->color = BLACK;
                                grandFather->color = RED;
                                rotateRight(parent);
                            }
                        }
                    }
                    // 내 부모가 할어버지의 오른쪽 노드라면
                    else
                    {
                        // 내가 부모의 왼쪽 노드라면
                        if (new_node == parent->left)
                        {
                            // case 1 삼촌이 red
                            if (grandFather->left->color == RED)
                            {
                                grandFather->left->color = BLACK;
                                grandFather->right->color = BLACK;
                                grandFather->color = RED;
                            }
                            // case 2 삼촌이 black
                            else
                            {
                                rotateRight(parent);
                                parent->color = BLACK;
                                grandFather->color = RED;
                                rotateRight(parent);
                            }
                        }
                        // 내가 부모의 오른쪽 노드라면
                        else
                        {

                        }
                    }
                }
                // 1. 각 노드는 red, black 이다
                // 2. 루트노드는 black 이다.
                // 3. 모든 리프 노드는 (leaf node) black 노드
                // 4. red 노드의 자식은 모두 black이다.
                // 5. 모든 노드의 경로중 만다는 black 노드의 수는 같다. 
            }
        }

        Node *get_node(int key)
        {
            Node *new_node = new Node(key);
            return (new_node);
        }
        void    rb_insert(Node *&root, Node *new_node)
        {
            Node *pre_node = NULL;
            Node *cur_node = root;
            while (cur_node != NULL)
            {
                pre_node = cur_node;
                if (cur_node->key > new_node->key)
                    cur_node = cur_node->left;
                else
                    cur_node = cur_node->right;
            }
            if (pre_node != NULL)
                new_node->parent = pre_node;
            if (pre_node == NULL)                   // current is root
                root = new_node;
            else if (pre_node->key > new_node->key)
                pre_node->left = new_node;
            else
                pre_node->right = new_node;
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->color = RED;
            fixViolation(root, new_node);
        }

    public:
        RedBlackTree() {} 
        void insert(Node *&root, int key)
        {
            Node *new_node = get_node(key);
            rb_insert(root, new_node);
        }

      
};


void preorder_traverse(Node *root) //  first meet root node
{
    if (root == NULL)
        return ;
    std::cout << root->key << " " << root->color << " -> ";
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

void inorder_traverse(Node *root) // first meet under left node 
{
    if (root == NULL)
        return ;
    inorder_traverse(root->left);
    std::cout << root->key << " " << root->color << " -> ";
    inorder_traverse(root->right);
    return ;
}

void postorder_traverse(Node *root) // first meed under right node  
{
    if (root == NULL)
        return ;
    postorder_traverse(root->left);
    postorder_traverse(root->right);
    std::cout << root->key << " " << root->color << " -> ";
    return ;
}

int main() {

    RedBlackTree tree;

    {
        Node *root = NULL;
        tree.insert(root, 200);
        tree.insert(root, 150);
        tree.insert(root, 300);
        tree.insert(root, 100);

        inorder_traverse(root); std::cout << "\n";
        postorder_traverse(root); std::cout << "\n";
        preorder_traverse(root); std::cout << "\n";
    }
    std::cout << "print end of tree" << std::endl;
    return 0;
}