#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50
#define MIN_VALUE 1
#define MAX_VALUE 10

void createArray(uint8_t arr[]){
    uint8_t i;

    // Khởi tạo seed cho hàm rand()
    srand(time(NULL));

    // Tạo mảng ngẫu nhiên trong phạm vi từ MIN_VALUE đến MAX_VALUE
    for (i = 0; i < SIZE; i++) {
        arr[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    }
}

void sap_xep(uint8_t arr[], uint8_t n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                // Hoán đổi giá trị của 2 phần tử
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int tim_n(uint8_t arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        // Nếu giá trị tại vị trí giữa bằng x, trả về vị trí đó
        if (arr[mid] == x) {
            return mid;
        }
        // Nếu giá trị tại vị trí giữa lớn hơn x, tìm kiếm trong nửa đầu tiên của mảng
        if (arr[mid] > x) {
            return tim_n(arr, left, mid - 1, x);
        }
        // Nếu giá trị tại vị trí giữa nhỏ hơn x, tìm kiếm trong nửa sau của mảng
        return tim_n(arr, mid + 1, right, x);
    }
    // Nếu không tìm thấy, trả về -1
    return -1;
}

void printArray(uint8_t arr[], uint8_t n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    uint8_t arr[10];

    createArray(arr);

     // In ra mảng
    printf("Mang ngau nhien:\n");
    for (uint8_t i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    sap_xep(arr,10);
    printArray(arr,10);

    tim_n(arr, 2,  10, 5);
    return 0;
}

