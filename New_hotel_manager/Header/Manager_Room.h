/*
* File Name: Manager_Room.h
* Author: Anh Trinh
* Date: 08/08/2023
* Description: This file is a header file that contains all the prototypes to manage room for the hotel
*/



#ifndef __ROOM_H
#define __ROOM_H


#include <stdio.h>
#include <stdint.h>


using namespace std;


/*Quản lý đặt phòng:
Ứng dụng cho phép người dùng xem danh sách các phòng khách sạn và kiểm tra tính trạng phòng
 (đã đặt, còn trống, đang dọn dẹp). Người dùng có thể tiến hành đặt phòng 
*/
class Room {
    private:
    uint8_t roomNumber;
    bool isBooked;
    bool isClearing;

    public:
        Room(uint8_t Number){
            roomNumber = Number;
            isBooked = false;
            isClearing = false;

    }

uint8_t getroomNumber();

/*Method check room Available - kiem tra xem co phong khong
+kiem tra xem phong da duoc book hay chua
+kiem tra xem phong da duoc don hay chua
*/


bool isAvailable();

//Method book room 

void bookRoom();

/*
 Method check in 
- phong da duoc dat
+phong chua don dep 
+phong da duoc dat
*/


void checkIn();
/*
Method check in 
+phong da duoc dat
+phong chua don dep 
+phong da duoc dat
*/

void checkOut();

/*
Method check out 
+phong da duoc tra
+phong da duoc don dep 
+phong chua duoc book
*/
};
void roommanager();
// Tạo danh sách các phòng khách sạn


#endif
