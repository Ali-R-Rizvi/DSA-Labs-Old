#include "iostream"

using namespace std;

//Task 1
double power(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return power(x, n - 1) * x;
}

//Task 2
int arraySum(int A[], int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return A[n - 1] + arraySum(A, n - 1);
}

//Task 3
void reverseSubArray(int A[], int start, int end)
{
    if (start < end)
    {
        swap(A[start], A[end]);
        reverseSubArray(A, start + 1, end - 1);
    }
}

void showArray(int A[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << ", ";
    }
}

//Task 4
bool checkSum(int A[], int start, int end, int k)
{
    if (start < end)
    {
        for (int i = start + 1; i <= end; i++)
        {
            if (A[start] + A[i] == k)
            {
                return true;
            }
        }
        return checkSum(A, start + 1, end, k);
    }    
}

int main()
{
    //Task 1
     double x = 2;
     int n = 3;
     cout << power(x, n) << endl;

    //Task 2
     int A[10] = {1, 22, 3, 11, 5, 6, 57, 8, 99, 10}, size = 10;
     cout << arraySum(A, size) << endl;

    //Task 3
     //int A[10] = {1, 22, 3, 11, 5, 6, 57, 8, 99, 10};
     reverseSubArray(A, 1, 5);
     showArray(A);
     cout << endl;

    //Task 4
     //int A[10] = {1, 22, 3, 11, 5, 6, 57, 8, 99, 10};
     cout << checkSum(A, 0, 9, 25) << endl;

    return 0;
}