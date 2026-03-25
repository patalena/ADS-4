// Copyright 2021 NNTU-CS

int binarySearchFirst(int* arr, int left, int right, int target) {
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int binarySearchLast(int* arr, int left, int right, int target) {
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int countPairs1(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k++;
            }
        }
    }
    return k;
}

int countPairs2(int* arr, int len, int value) {
    int k = 0;
    int l = 0, r = len - 1;
    while (l < r) {
        int suma = arr[l] + arr[r];
        if (suma == value) {
            if (arr[l] == arr[r]) {
                int n = r - l + 1;
                k += n * (n - 1) / 2;
                break;
            } else {
                int lcount = 1;
                while (l + 1 < r && arr[l] == arr[l + 1]) {
                    l++;
                    lcount++;
                }
                int rcount = 1;
                while (r - 1 > l && arr[r] == arr[r - 1]) {
                    r--;
                    rcount++;
                }
                k += lcount * rcount;
                l++;
                r--;
            }
        } else if (suma < value) {
            l++;
        } else {
            r--;
        }
    }
    return k;
}

int countPairs3(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        int nayt = value - arr[i];
        int first = binarySearchFirst(arr, i + 1, len - 1, nayt);
        if (first != -1) {
            int last = binarySearchLast(arr, first, len - 1, nayt);
            k += (last - first + 1);
        }
    }
    return k;
}
