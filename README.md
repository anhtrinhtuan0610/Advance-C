# Advance-C
LEARN C
BUOI 1 - COMPILER 
   -   Compiler : khi ta viết 1 chương trình nào đó sử dụng ngôn ngữ lập trình như C, C++ hay các ngôn ngữ lập trình khác , nhưng những ngôn ngữ lập trình đó thì máy tính không hiểu được vì vậy ta cần có 1 công cụ giúp máy tính hiểu được đó là compiler.
-	Compiler : giống như 1 phần mềm giúp ta chuyển các ngôn ngữ lập trình về ngôn ngữ máy.(ngôn ngữ có dạng nhị phân)

	Vậy tại sao ta không lập trình bằng ngôn ngữ máy ?
-	Câu trả lời là để lập trình được dưới dạng nhị phân bằng ngôn ngữ máy là rất khó. Vì vậy người ta mới sử dụng ngôn ngữ lập trình bậc cao hơn và giúp ta dễ hiểu hơn, và cần có 1 compiler (đưa chương trình sử dụng ngôn ngữ bậc cao xuống ngôn ngữ bậc thấp giúp máy tính hiểu được).
-	Mỗi ngôn ngữ lập trình đều có 1 conpiler riêng.
+Kết luận:
-	Compiler là 1 công cụ giúp chuyển từ ngôn ngữ bậc cao xuống ngôn ngữ máy giúp cho máy tính hiểu và làm việc.

2. quá trình trình biên dịch.

+chú thích:
-	File .c: hay file source (file nguồn) là file main.c hoặc các file .c khác khi ta lập trình.
-	File .h: hay file header(file tiêu đề) là file thư viện ta dùng.
-	File .i  là file sau quá trình tiền xử lý sinh ra(preprocessed source)
-	Khi ta lập trình thì sẽ tạo ra rất nhiều file nhưng khi ta đưa về file.i thì tất cả các file đó sẽ được gộp về 1 file duy nhất
-	Cú pháp tạo file .i trên vs code:
 gcc –E main.c – o main.i
-	Sau quá trình tiền sử lý ta đến quá trình compiler tạo ra file.s(hay còn gọi là file assembly – file cuộc họp)
-	Cú pháp để tạo ra file .s trong vscode là:
gcc main.i -S -o main.s
-	Sau quá trình tạo ra file main.s sẽ đến quá trình tạo ra file .o hay còn gọi là object file – tập tin đối tượng gồm file .o  và file thư viện thông qua quá trình assembler – quá trình lắp ráp.
-	-	Cú pháp tạo file .c trong vscode:
gcc -c main.s -o main.o
-	Sau khi tạo ra file .o thì sẽ tạo ra file.exe thông qua quá trình linker 
-	
=====================buổi 2 macro========================

1.lý thuyết:
-   macro (vỹ mô) – xảy ra ở quá trình tiền xử lý preprocessor 
-   macro thay thế tên macro thành giá trị mà ta muốn thay thế 
-   Cú pháp:
#define <ten_macro>  <gia_tri_macro>

Ifndef 

+cú pháp:

#ifndef <tên_macro>
// Do something here when <tên_macro> is not defined
#define<tên_macro> <giá_trị_macro>
#endif
+lý thuyết : được sử dụng để xem tên là <ten_macro> đã được định nghĩa hay chưa . Nếu đã được định nghĩa rồi thì toàn bộ các câu lệnh trong cú pháp sẽ không được thực thi.


Ifdef

+cú pháp:

#ifdef <tên_macro>
// Do not something here when <tên_macro> is not defined
#define<tên_macro> <giá_trị_macro>
#endif

+lý thuyết : được sử dụng để xem tên là <ten_macro> đã được định nghĩa hay chưa . Nếu đã được định nghĩa rồi thì toàn bộ các câu lệnh trong cú pháp sẽ  được thực thi.


	Kết luận: #ifdef và #ifndef là tương tự nhau. Điểm khác nhau duy nhất giữa chúng là #ifdef được sử dụng để kiểm tra xem một định nghĩa đã được định nghĩa trước đó hay chưa, trong khi #ifndef được sử dụng để kiểm tra xem một định nghĩa chưa được định nghĩa.

	Về bản chất thì ifndef và ifdef ngược nhau

	Tại sao người ta lại sử dụng ifndef và ifdef

-	Vì trong khi lập trình ta sẽ viết rất nhiều file khác nhau lên dễ xảy ra tình trạng bị xung đột giữa các file vì vậy mới thực hiện việc kiểm tra xem rằng macro đã được định ngĩa hay chưa nếu đã định nghĩa rồi thì các câu lệnh trong đó sẽ được bỏ qua còn nếu chưa thì sẽ được định nghĩa lại.
1.3 macro viết theo kiểu giống fucion

cú pháp :

#define <ten_macro>   <value>
   
#if <statements>
   
#elif
   
#endif
1.4 macro khai báo nhiều biến với ký tự "##"
   
- "##" thường dùng để đặt tên cho biến, hàm, class
   
- "##" dùng để nối chuỗi trong macro
   
ex : ví dụ ta có thể khai báo nhiều biến dựa vào macro như sau:
   
#include <stdio.h>

#define VARIABLE(name)\  
   
int int_##name;   \
   
char char_##name;  \
   
double double_##name

int main()
{
    VARIABLE(bien);
   
    int_bien = 10;
   
    char_bien = 'A';
   
    double_bien =10.6;
   
    printf("int : %d\n",int_bien);
   
    printf("char : %c\n",char_bien);
   
    printf("double : %f",double_bien);
   
}

-  chú thích :
   
" #define VARIABLE(name)\   
   
int int_##name;   \
   
char char_##name;  \
   
double double_##name"
   
ở đây ta đã tạo 1 macro để khai báo ra 3 biến kiểu int, char, double.
   
sau khi chạy chương trình ta sẽ được 3 biến là:
   
int : 10
   
char : A
   
double: 10.6000000
   
1.5 khai báo hàm bằng macro
   
-  ta cũng có thể khai báo hàm bằng macro
   
ví dụ:
   
#include <stdio.h>
   

#define hien_thi(ten_ham, ten_hoc_sinh, tuoi, lop) \
   
void ten_ham(){                                    \
   
    printf("ten : %s\n",ten_hoc_sinh);               \
   
    printf("tuoi : %d\n", tuoi);                     \
   
    printf("lop : %d\n", lop);                       \
}
hien_thi(nguyen_A,"Nguyen va A", 16, 9)
   
hien_thi(nguyen_B,"Nguyen va B", 17, 10)
   
int main()
{
    nguyen_A();
   
    nguyen_B();
   
    return 0;
}

=> có thể thay thế khai báo chuỗi bằng "#"
   
nếu sử dụng khai báo chuỗi bằng "#" thì ví dụ trên sẽ như sau:
   
printf("ten : %s\n",ten_hoc_sinh); 
   
//sẽ được thay thế bằng:
   
printf("ten : %s\n",#ten_hoc_sinh); 
   
> khi đó khi nhập vào chuỗi 
   
hien_thi(nguyen_B,"Nguyen va B", 17, 10)     
   
// ta sẽ không cần khai báo thêm dấu "" nữa và sẽ có dạng như sau:
   
  hien_thi(nguyen_B,Nguyen va B , 17, 10)   
   
1.6 variadic macros ( macros biến đổi)
   
-  dùng để viết macro mà không có tham số cụ thể hoặc không biết số tham số nhất định.
   
#include <stdio.h>
 
   

#define TEST(...) __VA_ARGS__
   
// đây là 1 macro được sử dụng khi ta chưa biết tham số đầu vào



int main()
{
    TEST(10, 20, 30);
   
    return 0;
}
- macro không phải là code nó chỉ là đoạn được thay thế bằng 1 đoạn khác.	      

