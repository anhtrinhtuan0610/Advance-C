#include <stdio.h>
#include <stdint.h>


typedef struct                                     
{
    int ngay;
    int thang;
    int nam;
}typeDate;                                  //tạo 1 kiểu dũ liệu gọi là typeDate gồm có ngày tháng,năm



void sceen(typeDate date)
{
    printf("Ngay : %d, Thang : %d, Nam: %d\n",date.ngay,date.thang,date.nam);
}

int main(int argc, char const *argv[])
{
    /*đây là cách khai báo 1 biến theo kiểu struct và khởi tạo các biến thành phần*/

    //typeDate date;                            // tạo 1 biến có kiểu typeDate tên date
    //date.ngay = 6;                            //khởi tạo giá trị cho ngày tháng năm
   // date.thang = 9; 
   // date.nam = 2023;

    /*ta có thể khai báo theo cách khác như sau*/

    // typeDate date = {date.ngay = 6, date.thang = 10, date.nam =2023};

     /*ta có thể khai báo theo cách thứ 3 như sau*/

     typeDate date = {6,10,2023};

    sceen(date);                              //gọi hàm hiển thị ra màn hình
    return 0;
}
