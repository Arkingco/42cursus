#include "MutantStack.hpp"

void subject_test()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack top : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack size : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void custom_test()
{
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);

    for (MutantStack<int>::iterator iter = mstack.begin(); iter != mstack.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main()
{
    subject_test();
    std::cout << "\n\n---------------- custom -------------" << std::endl;
    custom_test();

    
    return 0;
}
