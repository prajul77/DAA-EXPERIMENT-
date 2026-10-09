#include <iostream>
#include <vector>
using namespace std;
class HeapSort {
vector<int> arr;
void heapify(int n, int i) {
int largest = i;
int left = 2 * i + 1, right = 2 * i + 2;
if (left < n && arr[left] > arr[largest])
largest = left;
if (right < n && arr[right] > arr[largest])
largest = right;
if (largest != i) {
swap(arr[i], arr[largest]);
heapify(n, largest);
}
}
public:
void read(int n) {
arr.resize(n);
for (int i = 0; i < n; i++)
cin >> arr[i];
}
void heapSort() {
int n = arr.size();
for (int i = n / 2- 1; i >= 0; i--)
heapify(n, i);
for (int i = n- 1; i > 0; i--) {
swap(arr[0], arr[i]);
heapify(i, 0);
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
HeapSort obj;
cout << "Enter number of elements: ";
cin >> n;
cout << "Enter the elements: ";
obj.read(n);
obj.heapSort();
cout << "Sorted array: ";
obj.display();
return 0;
}
