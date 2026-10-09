#include <iostream>
#include <vector>
using namespace std;
class MergeSort {
vector<int> arr;
void merge(int l, int m, int r) {
vector<int> L(arr.begin() + l, arr.begin() + m + 1);
vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
size_t i = 0, j = 0;
int k = l;
while (i < L.size() && j < R.size()) {
if (L[i] <= R[j]) arr[k++] = L[i++];
else
arr[k++] = R[j++];
}
while (i < L.size()) arr[k++] = L[i++];
while (j < R.size()) arr[k++] = R[j++];
}
public:
void read(int n) {
arr.resize(n);
for (int i = 0; i < n; i++)
cin >> arr[i];
}
void mergeSort(int l, int r) {
if (l < r) {
int mid = l + (r- l) / 2;
mergeSort(l, mid);
mergeSort(mid + 1, r);
merge(l, mid, r);
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
MergeSort obj;
cout << "Enter number of elements: ";
cin >> n;
cout << "Enter the elements: ";
obj.read(n);
obj.mergeSort(0, n- 1);
cout << "Sorted array: ";
obj.display();
return 0;
}