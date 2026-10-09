#include <iostream>
#include <vector>
using namespace std;
class QuickSort {
    vector<int> arr;
int partition(int lb, int ub) {
int pivotValue = arr[ub];
int i = lb- 1;
for (int j = lb; j < ub; j++) {
if (arr[j] < pivotValue) {
i++;
swap(arr[i], arr[j]);
}
}
swap(arr[i + 1], arr[ub]);
return i + 1;
}
public:
void read(int n) {
arr.resize(n);
for (int i = 0; i < n; i++)
cin >> arr[i];
}
void quickSort(int lb, int ub) {
if (lb < ub) {
int pivotIndex = partition(lb, ub);
quickSort(lb, pivotIndex- 1);
quickSort(pivotIndex + 1, ub);
}
}
void display() {
for (int x : arr)
cout << x << " ";
cout << endl;
}
};
int main() {
int n;
QuickSort obj;
cout << "Enter number of elements: ";
cin >> n;
cout << "Enter the elements: ";
obj.read(n);
obj.quickSort(0, n- 1);
cout << "Sorted array: ";
obj.display();
return 0;
}