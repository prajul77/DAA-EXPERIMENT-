#include <iostream>
#include <vector>
using namespace std;
class InsertionSort {
vector<int> arr;
public:
void read(int n) {
arr.resize(n);
for (int i = 0; i < n; i++)
cin >> arr[i];
}
void insertionSort(int lb, int ub) {
for (int i = lb + 1; i <= ub; i++) {
int key = arr[i];
int j = i- 1;
while (j >= lb && arr[j] > key) {
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key;
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
InsertionSort obj;
cout << "Enter number of elements: ";
cin >> n;
cout << "Enter the elements: ";
obj.read(n);
obj.insertionSort(0, n- 1);
cout << "Sorted array: ";
obj.display();
return 0;
}