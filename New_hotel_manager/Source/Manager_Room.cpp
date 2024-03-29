/*
* File Name: Manager_Room.cpp
* Author: Anh Trinh
* Date: 08/08/2023
* Description: This file is a Source file that contains all the prototypes to manage room for the hotel
*/


#include <iostream>
#include <stdint.h>
#include <string.h>
#include <vector>
#include "Manager_Customer.h"
#include "Manager_Room.h"
#include "Employee.h"


/*Chuong trinh quan ly khach san
--------------------------------
Quản lý đặt phòng: Ứng dụng cho phép người dùng xem danh sách các phòng khách sạn và kiểm tra tính trạng phòng (đã đặt, 
còn trống, đang dọn dẹp). Người dùng có thể tiến hành đặt phòng 

Quản lý khách hàng: Ứng dụng lưu trữ thông tin cá nhân của khách hàng, bao gồm tên, số điện thoại,
 địa chỉ và lịch sử đặt phòng. Người dùng có thể tạo mới, chỉnh sửa và xóa thông tin khách hàng.

Quản lý nhân viên: Ứng dụng cung cấp danh sách nhân viên khách sạn và cho phép quản lý thông tin cá nhân của họ. 
Điều này bao gồm tên, số điện thoại, vị trí công việc và lịch làm việc. Người dùng có thể thêm, sửa đổi và xóa nhân viên khỏi danh sách.

Quản lý dịch vụ và tiện ích: Ứng dụng cho phép người dùng thêm, sửa đổi và xóa các dịch vụ và tiện ích được cung cấp trong khách sạn, 
ví dụ: nhà hàng, quầy bar, bể bơi, phòng tập thể dục và dịch vụ đỗ xe.

Quản lý thanh toán: Ứng dụng cung cấp chức năng thanh toán online cho khách hàng.
 Người dùng có thể thanh toán thông qua các phương thức thanh toán phổ biến như thẻ tín dụng, ví điện tử hay Internet Banking. 
 Ứng dụng ghi lại lịch sử thanh toán và cung cấp hóa đơn điện tử cho khách hàng.


Bảo mật và quyền truy cập: Ứng dụng quản lý quyền truy cập để đảm bảo rằng chỉ có nhân viên có quyền mới có thể truy cập và chỉnh sửa thông tin nhạy cảm. Đồng thời, ứng dụng cũng cần đảm bảo bảo mật thông tin cá nhân của khách hàng và không cho phép truy cập trái phép vào hệ thống. Điều này có thể đảm bảo bằng cách sử dụng mã hóa dữ liệu và các biện pháp bảo mật khác như xác thực hai yếu tố hoặc xác thực dấu vân tay.
Báo cáo và thống kê: Ứng dụng cung cấp khả năng tạo báo cáo và thống kê về hoạt động của khách sạn.

 Người dùng có thể xem doanh thu, tỷ lệ lấp đầy phòng, đánh giá từ khách hàng, số lượng đặt phòng và các chỉ số quản lý khác. Điều này giúp quản lý khách sạn hiểu rõ hơn về hiệu suất kinh doanh và đưa ra quyết định dựa trên thông tin được cung cấp.

Tương tác khách hàng: Ứng dụng có thể cung cấp khả năng gửi thông báo và tin nhắn đến khách hàng, ví dụ như thông báo về chương trình khuyến mãi, sự kiện đặc biệt hoặc thông tin quan trọng khác. Điều này giúp duy trì liên lạc với khách hàng và tạo sự tương tác tích cực.
Quản lý phản hồi và đánh giá: Ứng dụng cho phép khách hàng gửi phản hồi và đánh giá về trải nghiệm của họ tại khách sạn. Quản lý có thể xem xét và phản hồi lại các đánh giá này để cải thiện chất lượng dịch vụ và tạo lòng tin cho khách hàng.

*/
using namespace std;


/*Quản lý đặt phòng:
Ứng dụng cho phép người dùng xem danh sách các phòng khách sạn và kiểm tra tính trạng phòng
 (đã đặt, còn trống, đang dọn dẹp). Người dùng có thể tiến hành đặt phòng 
*/

    // method lay so phong 
    uint8_t Room::getroomNumber(){
        return roomNumber;
    }
    /*Method check room Available - kiem tra xem co phong khong
    +kiem tra xem phong da duoc book hay chua
    +kiem tra xem phong da duoc don hay chua
    */
    bool Room::isAvailable(){
        return !isBooked && !isClearing;
    }
    //Method book room 
    void Room::bookRoom(){
        isBooked = true;
    }
    /*
    Method check in 
    - phong da duoc dat
    +phong chua don dep 
    +phong da duoc dat
    */
    void Room::checkIn()
    {
        isClearing = false;
        isBooked = true;
    }
    /*
    Method check out 
    - phong da duoc tra
    +phong da duoc don dep 
    +phong chua duoc book
    */
    void Room::checkOut()
    {
        isBooked = false;
        isClearing = true;
    }

void roommanager()
{
    // Tạo danh sách các phòng khách sạn
    Room room1(101);
    Room room2(102);
    Room room3(103);
    Room room4(104);

    // Kiểm tra tính trạng các phòng
    cout << "Danh sach cac phong khach san:" << endl;
    cout << "Phong " << room1.getroomNumber() << ": ";
    if (room1.isAvailable()) {
        cout << "Con trong" << endl;
    } else {
        cout << "Da duoc dat" << endl;
    }

    cout << "Phong " << room2.getroomNumber() << ": ";
    if (room2.isAvailable()) {
        cout << "Con trong" << endl;
    } else {
        cout << "Da duoc dat" << endl;
    }

    cout << "Phong " << room3.getroomNumber() << ": ";
    if (room3.isAvailable()) {
        cout << "Con trong" << endl;
    } else {
        cout << "Da duoc dat" << endl;
    }

    cout << "Phong " << room4.getroomNumber() << ": ";
    if (room4.isAvailable()) {
        cout << "Con trong" << endl;
    } else {
        cout << "Da duoc dat" << endl;
    }

    // Đặt phòng
    room1.bookRoom();

    // Kiểm tra lại tính trạng các phòng sau khi đặt phòng
    cout << "Danh sach cac phong khach san sau khi dat phong:" << endl;
    cout << "Phong " << room1.getroomNumber() << ": ";
    if (room1.isAvailable()) {
        cout << "Con trong" << endl;
    } else {
        cout << "Da duoc dat" << endl;
    }

    cout << "Phong " << room2.getroomNumber() << ": ";
    if (room2.isAvailable()) {
        cout << "Con trong" << endl;
    } else {
        cout << "Da duoc dat" << endl;
    }

    cout << "Phong " << room3.getroomNumber() << ": ";
    if (room3.isAvailable()) {
        cout << "Con trong" << endl;
    } else {
        cout << "Da duoc dat" << endl;
    }

    cout << "Phong " << room4.getroomNumber() << ": ";
    if (room4.isAvailable()) {
        cout << "Con trong" << endl;
    } else {
        cout << "Da duoc dat" << endl;
    }
}


