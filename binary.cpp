#include <bits/stdc++.h>
using namespace std;

void linear(int arr[], int n, int ID) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ID) {
            cout << "ID found at position " << i + 1 << endl;
            found = true;
            break; // stop after finding first occurrence
        }
    }
    if (!found)
        cout << "ID not found" << endl;
}

void binary(int arr[], int n, int ID) {
    int low = 0;
    int high = n - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;  // ✅ correct midpoint formula

        if (arr[mid] < ID) {
            low = mid + 1;
        } 
        else if (arr[mid] > ID) {
            high = mid - 1;
        } 
        else {
            cout << "ID found at position " << mid + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "ID not found" << endl;
}

int main() {
    int n, id;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " IDs (in sorted order for binary search): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> id;

    cout << "\nLinear Search:\n";
    linear(arr, n, id);

    cout << "\nBinary Search:\n";
    binary(arr, n, id);

    return 0;
}
