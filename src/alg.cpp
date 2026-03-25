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
    for (int i = 0; i < len - 1; i++) {
        int nayt = value - arr[i];
        int l = i + 1;
        int r = len - 1;
        int naytindex = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == nayt) {
                naytindex = mid;
                break; 
            } else if (arr[mid] < nayt) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (naytindex != -1) {
            int leftIndex = naytindex;
            while (leftIndex >= i + 1 && arr[leftIndex] == nayt) {
                k++;
                leftIndex--;
            }
            int rightIndex = naytindex + 1;
            while (rightIndex < len && arr[rightIndex] == nayt) {
                k++;
                rightIndex++;
            }
        }
    }
    return k;
}
