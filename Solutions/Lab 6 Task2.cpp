//#include "iostream"
//
//using namespace std;
//
//int kSmallest(int A[], int n, int k)
//{
//    for (int i = 0; i < n; i++)                 //n 
//    {                          
//        for (int j = 0; j < n - i - 1; j++)     //n*n 
//        {
//            if (A[j] > A[j + 1])                //1
//            {
//                swap(A[j], A[j + 1]);           //1
//            }
//        }
//    }
//    return A[k - 1];                            //1
//}                                               //O(n^2)
//
//
//int main() {
//    const int size = 6;
//
//    int a[size] = { 10, 5, 6, 2, 8, 1 };
//    //int k;
//
//    //cout << "Enter k: ";
//    //cin >> k;
//    cout << "Kth Smallest = " << kSmallest(a, 6, 3) << endl;
//}