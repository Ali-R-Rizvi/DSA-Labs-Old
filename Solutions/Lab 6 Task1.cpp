//#include "iostream"
//
//using namespace std;
//
//int intersection1(int A[], int B[], int C[], int n) {
//    int s = 0;
//
//    for (int i = 0; i < n; i++) 
//    {
//        for (int j = 0; j < n; j++) 
//        {
//            if (A[i] == B[j]) 
//            {
//                C[s] = B[j];
//                s++;
//            }
//        }
//    }
//
//    return s;
//}
//int intersection2(int A[], int B[], int C[], int n) {
//    int s = 0, temp = n, mid;
//
//    for (int i = 0; i < n; i++) 
//    {
//        int low = 0;
//        int high = temp - 1;
//
//        while (low <= high) 
//        {
//            mid = (low + (high - low) / 2);
//            if (A[mid] == B[i]) 
//            {
//                C[s++] = B[i];
//                break;
//            }
//            else if (A[mid] > B[i]) {
//                high = mid - 1;
//            }
//            else {
//                low = mid + 1;
//            }
//        }
//    }
//    return s;
//}
//
//int main() {
//    const int size = 7;
//    int a[size] = { 1, 4, 5, 6, 2, 9, 8 };
//    int b[size] = { 2, 4, 6, 8, 0, 1, 3 };
//    int c[size];
//    int d[size] = { 0, 2, 4, 6, 8, 10, 12 };
//    int e[size] = { 1, 2, 5, 6, 9, 10, 13 };
//    int f[size];
//    int i1 = 0, i2 = 0;
//
//    i1 = intersection1(a, b, c, size);
//    cout << "Common Elements: " << i1 << endl;
//    
//    cout << "Intersaction: " << endl;
//    if (i1 == 0) 
//    {
//        cout << "Empty Set";
//    }
//    else 
//    {
//        for (int i = 0; i < i1; i++) 
//        {
//            cout << c[i] << " ";
//        }
//        cout << endl;
//    }
//
//    i2 = intersection2(d, e, f, size);
//
//    cout << "Common Elements: " << i2 << endl;
//    if (i2 == 0) 
//    {
//        cout << "EMPTY";
//    }
//    else 
//    {
//        for (int i = 0; i < i2; i++) 
//        {
//            cout << f[i] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
