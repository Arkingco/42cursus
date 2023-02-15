#include <iostream>

template<class T>
class tree
{
    typedef tree* pointer;
    typedef T& reference;
    typedef T value_type;

    public:
        value_type key;
        pointer left;
        pointer right;
        pointer parent;

    private:
        tree();

    public:
        tree(value_type key): key(key) {}

        // Rotation
        left_rotation()
        {
            
        }
};

int main()
{
    tree<int> a(10);
    tree<int> b(20);
    tree<int> c(30);


    a.left = &b;
    a.right = &c;

    std::cout << a.key << " " << a.left->key << " " << a.right->key << std::endl;

}
