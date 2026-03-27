// Copyright 2021 NNTU-CS
#include "alg.h"
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
        int sum = arr[l] + arr[r];
        if (sum == value) {
            if (arr[l] == arr[r]) {
                int n = r - l + 1;
                k = k + n * (n - 1) / 2;
                break;
            }
            int leftVal = arr[l];
            int leftCnt = 0;
            while (l <= r && arr[l] == leftVal) {
                leftCnt = leftCnt + 1;
                l = l + 1;
            }
            int rightVal = arr[r];
            int rightCnt = 0;
            while (r >= l && arr[r] == rightVal) {
                rightCnt = rightCnt + 1;
                r = r - 1;
            }
            k = k + leftCnt * rightCnt;
        } else if (sum < value) {
            l = l + 1;
        } else {
            r = r - 1;
        }
    }
    return k;
}

int countPairs3(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int target = value - arr[i];
        if (target < arr[i]) {
            break;
        }
        int left = i + 1;
        int right = len - 1;
        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (first == -1) {
            continue;
        }
        left = first;
        right = len - 1;
        int last = first;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                last = mid;
                left = mid + 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (arr[i] == target) {
            int n = last - i + 1;
            k = k + n * (n - 1) / 2;
            break;
        }
        int leftCnt = 1;
        while (i + leftCnt < len && arr[i + leftCnt] == arr[i]) {
            leftCnt = leftCnt + 1;
        }
        k = k + leftCnt * (last - first + 1);
    }
    return k;
}
