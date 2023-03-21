#include "PmergeMe.hpp"

static int piece = 10;

template <class container>
typename container::iterator find(container &AB, int value)
{
    for (typename container::iterator iter = AB.begin(); iter != AB.end(); ++iter)
    {
        if (*iter == value)
            return iter;
    }
    return AB.end();

}

void print_error(std::string msg)
{
    std::cout << msg << std::endl;
    exit(1);
}

template <class container>
void insertion_sort(container &AB, int left, int right) {
    for (int i = left; i < right; i++) {
        int tempVal = AB[i + 1];
        int j = i + 1;
        while (j > left && AB[j - 1] > tempVal) {
            AB[j] = AB[j - 1];
            j--;
        }
        AB[j] = tempVal;
    }
}

template <class container>
void merge(container &AB, int left, int half, int right) {
    container LA;
    container RA;
    LA.assign(AB.begin() + left, AB.begin() + half + 1);
    RA.assign(AB.begin() + half + 1, AB.begin() + right + 1);
    int LA_index = 0;
    int RA_index = 0;
    for (int i = left; i < right - left + 1; i++) {
        if (RA_index == right - half) {
            AB[i] = LA[LA_index];
            LA_index++;
        } else if (LA_index == half - left + 1) {
            AB[i] = RA[RA_index];
            RA_index++;
        } else if (RA[RA_index] > LA[LA_index]) {
            AB[i] = LA[LA_index];
            LA_index++;
        } else {
            AB[i] = RA[RA_index];
            RA_index++;
        }
    }
}

template <class container>
void sort(container &AB, int left, int right) {
    if (right - left > piece) {
        int half = (left + right) / 2;
        sort(AB, left, half);
        sort(AB, half + 1, right);
        merge(AB, left, half, right);
    } else {
        insertion_sort(AB, left, right);
    }
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
    std::clock_t A_start;
    std::clock_t A_stop;
    std::clock_t B_start;
    std::clock_t B_stop;


    push_value(A, B, C, argv);

    A_start = std::clock();
    sort(A, 0, A.size() - 1);
    A_stop  = std::clock();

    B_start = std::clock();
    sort(B, 0, B.size() - 1);
    B_stop  = std::clock();

    std::cout << "Before ";
    for (std::vector<int>::iterator iter = C.begin(); iter != C.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    std::cout << "after  ";
	for (int i=0; i<A.size(); ++i)
        std::cout << A[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << C.size() << " elements with std::vector : " << \
                std::fixed << std::setprecision(5) << 1.0 * (A_stop - A_start) / CLOCK_BOOTTIME << "us" << std::endl;
    std::cout << "Time to process a range of " << C.size() << " elements with std::deque  : " << \
                std::fixed << std::setprecision(5) << 1.0 * (B_stop - B_start) / CLOCK_BOOTTIME << "us" << std::endl;

}