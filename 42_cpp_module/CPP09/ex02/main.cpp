#include "PmergeMe.hpp"

template <class container>
void insertionSort(container &A, int left, int right) {
	std::cout << "left : " << left << " right : " << right << std::endl;
    for (int i=left; i<right; ++i)
    {
        int temp = A[i + 1];
        int j = i + 1;
        while(j > left && A[j - 1] > temp )
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
	std::vector<int> temp;
	temp.assign(A.begin() + left, A.begin() + (right+1));
	for (int i=0; i<temp.size(); ++i)
	{
		std::cout << temp[i] << " ";
	}
	std::cout << std::endl;
}

template <class container>
void merge(container &A, int left, int half, int right) {
    int n1 = half - left + 1;
    int n2 = right - half;
    std::vector<int> LA;
	LA.assign(A.begin() + left, A.begin() + (half + 1));
    std::vector<int> RA;
	RA.assign(A.begin() + half + 1, A.begin() + (right + 1));
    int RIDX = 0;
    int LIDX = 0;
    for (int i = left; i < right - left + 1; i++) {
        if (RIDX == n2) {
            A[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            A[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            A[i] = LA[LIDX];
            LIDX++;
        } else {
            A[i] = RA[RIDX];
            RIDX++;
        }
    }
}

template <class container>
void sort(container &A, int left, int right) {
    if (right - left > 3) {
        int half = (left + right) / 2;
        sort(A, left, half);
        sort(A, half + 1, right);
        merge(A, left, half, right);
    } else {
        insertionSort(A, left, right);
    }
}

int main() {
    std::vector<int> A { 12, 5, 12, 61, 72, 34, 182, 44,19 };
    sort(A, 0, A.size() - 1);
	for(int i=0; i<A.size(); ++i)
	{
		std::cout << A[i] << " ";
	}
	return (0);
}