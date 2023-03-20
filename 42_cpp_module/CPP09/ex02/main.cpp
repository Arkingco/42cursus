#include "PmergeMe.hpp"

int K = 3;
void insertionSort(std::vector<int> &A, int left, int right) {
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

void merge(std::vector<int> &A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> LA;
	LA.assign(A.begin() + p, A.begin() + (q + 1));
    std::vector<int> RA;
	RA.assign(A.begin() + q + 1, A.begin() + (r + 1));
    int RIDX = 0;
    int LIDX = 0;
    for (int i = p; i < r - p + 1; i++) {
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

void sort(std::vector<int> &A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        sort(A, p, q);
        sort(A, q + 1, r);
        merge(A, p, q, r);
    } else {
        insertionSort(A, p, r);
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