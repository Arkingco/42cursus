#include "PmergeMe.hpp"

template <class container>
typename container::iterator find(container &A, int value)
{
    for (typename container::iterator iter = A.begin(); iter != A.end(); ++iter)
    {
        if (*iter == value)
            return iter;
    }
    return A.end();
}

void print_error(std::string msg)
{
    std::cout << msg << std::endl;
    exit(1);
}

template <class container1, class container2, class container3>
void push_value(container1 &c1, container2 &c2, container3 &c3, char **argv)
{
    for (int i=1; argv[i] != NULL; ++i)
    {
        int value = atoi(argv[i]);
        if (value < 0)
            print_error("Error");
        if(find(c3, value) != c3.end())
            continue;
        c3.push_back(value);
    }
    for (std::vector<int>::iterator iter = c3.begin(); iter != c3.end(); ++iter)
    {
        c1.push_back(*iter);
        c2.push_back(*iter);
    }
}

int main(int argc, char **argv) {

    if (argc < 2)
        print_error("not enough input");
    std::vector<int> A;
    std::deque<int> B;
    std::vector<int> C;
    PmergeMe A_sort;

    push_value(A, B, C, argv);

    sort(A, 0, A.size() - 1);
    sort(B, 0, B.size() - 1);
    std::cout << "Before ";
    for (std::vector<int>::iterator iter = C.begin(); iter != C.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    std::cout << "after  ";
	for (int i=0; i<A.size(); ++i)
        std::cout << A[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << C.size(); << "elements with std::vector : " << 0.00031 << "us" << std::endl;
    std::cout << "Time to process a range of " << C.size(); << "elements with std::deque : " << 0.00014 << "us" << std::endl;

}