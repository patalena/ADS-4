// Copyright 2021 NNTU-CS

int binarySearch(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int countPairs1(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k = k + 1;
            }
        }
    }
    return k;
}

int countPairs2(int* arr, int len, int value) {
    int l = 0;
    int r = len - 1;
    int k = 0;
    while (l < r) {
        int suma = arr[l] + arr[r];
        if (suma == value) {
            int ld = arr[l];
            int rd = arr[r];
            if (ld == rd) {
                int n = r - l + 1;
                k = k + n * (n - 1) / 2;
                break;
            }
            int indl = l;
            int lcount = 0;
            while (indl <= r && arr[indl] == ld) {
                lcount++;
                indl++;
            }
            int indr = r;
            int rcount = 0;
            while (indr >= l && arr[indr] == rd) {
                rcount++;
                indr--;
            }
            k = k + lcount * rcount;
            l = l + lcount;
            r = r - rcount;
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
    for (int i = 0; i < len; i++) {
        int nayt = value - arr[i];
        int pos = binarySearch(arr, i + 1, len - 1, nayt);
        if (pos != -1) {
            k++;
            int j = pos + 1;
            while (j < len && arr[j] == nayt) {
                k++;
                j++;
            }
        }
    }
    return k;
}
