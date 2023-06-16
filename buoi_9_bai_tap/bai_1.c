#include <stdio.h>
#include <stdint.h>

void nhap_mang(uint8_t array[], int so_phan_tu)
{
    for (int i = 0; i < so_phan_tu; i++)
    {
        printf("array[%d] = ", i);
        scanf("%hhu", &array[i]); // Sử dụng %hhu để đọc giá trị cho kiểu unsigned char
    }
}

void sap_xep_tang_dan(uint8_t array[], int so_phan_tu)
{
    int i, j, temp;

    for (i = 0; i < so_phan_tu - 1; i++)
    {
        for (j = i + 1; j < so_phan_tu; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    int so_phan_tu;
    uint8_t array[100];

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &so_phan_tu);

    // Nhập mảng
    nhap_mang(array, so_phan_tu);

    // In mảng trước khi sắp xếp
    printf("\nMang truoc khi sap xep: ");
    for (int i = 0; i < so_phan_tu; i++)
    {
        printf("%d ", array[i]);
    }

    // Sắp xếp mảng
    sap_xep_tang_dan(array, so_phan_tu);

    // In mảng sau khi sắp xếp
    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < so_phan_tu; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
