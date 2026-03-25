// Copyright 2021 NNTU-CS
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
                k += n * (n - 1) / 2;
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
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                k++;
                int j = mid + 1;
                while (j < len && arr[j] == target) {
                    k++;
                    j++;
                }
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return k;
}
