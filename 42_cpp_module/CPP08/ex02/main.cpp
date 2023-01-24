#include "MutantStack.hpp"

template<typename T>
void printMutantStack(T &container)
{
    for (typename T::iterator iter = container.begin(); iter != container.end(); ++iter)
        std::cout << *iter << " ";
}

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
    MutantStack<int> copy_mstak;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);

    copy_mstak.push(1);
    copy_mstak.push(1);
    copy_mstak.push(1);
    copy_mstak.push(1);
    copy_mstak.push(1);
    copy_mstak.push(1);
    copy_mstak.push(1);
    copy_mstak.push(1);

    printMutantStack(mstack); std::cout << std::endl;
    printMutantStack(copy_mstak);

    copy_mstak = mstack;
    
    for (MutantStack<int>::iterator iter = copy_mstak.begin(); iter != copy_mstak.end(); ++iter)
        *iter = *iter + 10;

    printMutantStack(mstack); std::cout << std::endl;
    printMutantStack(copy_mstak);
    std::cout << std::endl;

    std::list<int> list_mstack(mstack.begin(), mstack.end());

    printMutantStack(mstack); std::cout << std::endl;
    printMutantStack(list_mstack);
    std::cout << std::endl;
}

int main()
{
    subject_test();
    std::cout << "\n\n---------------- custom -------------" << std::endl;
    custom_test();
    return 0;
}
