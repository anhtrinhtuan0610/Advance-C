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
![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/9d0ee301-d582-4664-901e-1bf0bbba9f87)

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

#define VARIABLE(name) \  
   
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
   
   * lưu ý : 
   
+"##" dùng để nối chuỗi 
   
   
+"#" dùng để khai báo chuỗi
   
   =======================Buổi 3_INPUT========================
   
+Bài toán 1: tính tổng 3 số a,b,c 
   
#include <stdio.h>

int tinh_tong(int a, int b, int c)
   
{
   
    return a + b + c;
   
}
   
int main()
   
{
   
    printf("tong cua 3 so a b va c la : %d",tinh_tong(10,20,18));
   
    return 0;
   
}

=> từ bài toán trên ta lên 1 bài toán như sau:
   
viết 1 chương trình tính tổng các số với số lượng các số chưa xác định được.
   
=>hay là viết 1 chương trình tính tổng mà chưa biết số lượng input đầu vào.
   
#include<stdarg.h>  : thư viện stdarg.h cung cấp tính năng cho phép hàm có số lượng đối số không xác định hoặc biến đối được truyền vào 
   
- thư viện stdarg.h được khai báo để sử dụng những hàm như va_list, va_start,...
   
- "va_list" : là 1 kiểu dữ liệu trong thư viện <stdarg.h> được sử dụng để duyệt các đối số không định dạng của các hàm mà số lượng tham số chưa xác định trước .
   
- "va_list" : cho phép các hàm nhận tham số có số lượng biến đổi , giúp tạo ra các hàm đa dụng và linh hoạt hơn.
   
-"va_start" : là 1 macro trong thư viện <stdarg.h>  được sử dụng để thiết lập danh sách biến đổi số trong hàm có số lượng đối số không xác định. Macro "va_start"
   
  được sử dụng kết hợp với "va_list" để khởi tạo con trỏ đến danh sách các đối số không xác định và trỏ tới phần đầu tiên trong danh sách đó.
   
+Cú pháp của macro "va_start" 
   
void va_start (va_list ap, last);
   
trong đó : "ap" là biến kiểu "va_list" sẽ trỏ tới danh sách các đối số không xác định và "last" là đối số cuối cùng mà trước đó đã được định danh và biết thông
   
tin chính xác của nó .
   
Thông thường , tham số thứ nhất là 1 biến có kiểu "va_list" được khai báo trong hàm và tham số thứ 2 là đối số cuối cùng trong danh sách các đối số không xác định

-"va_arg" : là 1 macro trong thư viện <stdarg.h>  được sử dụng để truy cập và trả về giá trị của các đối số không xác định trong danh sách đối số của 1 hàm có số 
   
lượng đối số không xác định . macro "va_arg" sẽ trả về giá trị của 1 đối số trong danh sách đó và trỏ con trỏ tới đối số kế tiếp.

+ Cú pháp của macro "va_arg" :
   
type  va_arg(va_list ap, type);
   
trong đó : "ap" là biến có kiểu dữ liệu "va_list" sẽ trỏ tới danh sách các đối số không xác định và "type" là kiểu dữ liệu của đối số cần truy cập và trả về giá trị.

Sau khi gọi "va_arg", con trỏ trong danh sách các đối số sẽ được điều chỉnh để trỏ tới đối số kế tiếp.
   
- "va_end"  dùng để xóa bộ nhớ của "va_list" vì khi ta khai báo "va_list" thì biến đó sẽ được cấp phát 1 vùng nhớ lên sau khi sử dụng cần xóa bộ nhớ đó đi.
   
=> khi mà bắt gặp các bài toán có số tham số không xác định hoặc có số tham số gần giống nhau thì sử dụng thư viên"stdarg.h"
   
EX: chương trình tính tổng sử dụng thư viện "stdarg.h" khi không biết tham số truyền vào.
   
#include <stdio.h>
   
#include <stdarg.h>

int  tong(int so_input, ...)
{
   
    int sum = 0;
    
   va_list va;                                     // thực chất là 1 con trỏ trỏ đến vị trí của đối số không xác định
    
   va_start (va,so_input);                         // khởi tạo con trỏ

   
   for(int i = 0; i < so_input; i++)
    {
                               
      //  printf("test : %f\n", va_arg(va, double)); //chi chop in ra doi so co kieu double
                               
        sum += va_arg(va,int);
        
    }
                               
    va_end(va);                                       // xoa vung nho cua va_list
                               
    return sum;
                               
}

int main()
                               
{
                               
   // tong(5,1, (double)2, 3, 4, 5);
                               
    printf("tong bang : %d",tong(6, 3, 6 ,9, 1, 2, 3));
                               
    return 0;
                               
}
                               
                              =========================Buổi 4: biến(VARIABLE)====================
                               
1. lý thuyết.
                               
- thư viện : "stdint.h" thư viện này giúp lưu trữ và làm việc với dữ liệu 1 cách rõ ràng ở cấp độ bit.
 

1.1 Biến static 
                               
                               
a, biến static trong khai báo biến cục bộ.
                               
- khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại trong suốt thời gian chạy chương trình. Gía trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi taọ nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
                               
Ví dụ.
                               
#include <stdio.h>

#include <stdint.h> 
   
  // thư viện giúp lưu trữ và làm việc với dữ liệu 1 cách hiệu quả ở cấp độ bit

void count()

{
   
    uint8_t temp = 0; 
   
    printf("temp = %d\n",temp);
   
    temp++;
   
}

void count_2()
   
{
   
    static uint8_t temp = 0;     // khi gọi biến static sẽ khởi tạo 1 biến temp 1 lần và địa chỉ của temp sẽ cố định và tồn tại trong suốt chương trình
   
   printf("temp = %d\n",temp);
   
    temp++;
   
}
   
   
int main()
   
   
{
    count();           // khởi tạo 1 biến temp có địa chỉ là 0x01 sau khi hàm count() kết thúc thì thu hồi bộ nhớ của biến cục bộ temp
   
    count();           // khởi tạo lại biến temp có địa chỉ là 0x01 sau khi hàm count() kết thúc thì thu hồi bộ nhớ của biến cục bộ temp
   
    count();           // khởi tạo lại biến temp có địa chỉ là 0x01 sau khi hàm count() kết thúc thì thu hồi bộ nhớ của biến cục bộ temp
   

    count_2();
   
    count_2();
   
    count_2();
   
    return 0;
   
}
   
   1.2 Biến extern .
   
- Trong C, khi 1 biến đi sau từ khóa "extern" có nghĩa là:
   
+ Nó là tham chiếu của 1 biến, hàm cùng tên nào đó, đã được định nghĩa bên ngoài. Nó chỉ khai báo chứ không định nghĩa(cấp pháp bộ nhớ cho biến).
   
+ Biến được tham chiếu phải được khai báo ở cấp độ cao nhất(toàn cục), và có thể nằm trong 1 file khác.
   
=> khi muốn sử dụng 1 biến hoặc 1 hàm ở file khác cùng chung1 folder thì ta sẽ sử dụng biến "extern" nhưng chỉ đối với biến toàn cục.
   
Ví dụ: ta có 1 chương trình gồm 2 file có chương trình như sau:
   
+flie 1:
   
#include<stdio.h>
   
#include<stdint.h>
   

uint8_t temp = 15;
   

void count()
   
{
   
    printf("temp = %d\n",temp);
   
    temp++;
   
} 
   
   
+file 2:
   
#include<stdio.h>
   
#include<stdint.h>
   
#include"b4_extern_test.c"
   

extern void count();
   
extern uint8_t temp;

int main()
   
{
   
    count();
   
    count();
   
    temp = 20;
   
    printf("temp = %d\n",temp);
   
    count();
   
    return 0;
   
}
   
*Giải thích:
   
- ở file 1 ta thấy chương trình khởi tạo 1 biến toàn cục temp và hàm count,
   
- ở file 2 ta thấy chương trình sử dụng biến "extern" trước hàm "count" để xác định rằng sẽ sử dụng hàm "count" ở file 1 tương tự với biến toàn cục "temp"

1.3 biến static với biến toàn cục .
   
- khi biến toàn cục được khai báo với "static" thì biến toàn cục chỉ được sử dụng trong file khai báo đó và không có thể sử dụng trong các file khác kể cả khi được khai báo"extern" 
   
Ví dụ:
   
   
+file 1:
   
   
#include<stdio.h>
   
#include<stdint.h>
   
#include "b4_static_toan_cuc_test.c"
   

extern  uint8_t temp = 0; // khi ta gọi biến extern cũng không thể sử dụng được 
   
extern void dem();       // khi ta gọi biến extern cũng không thể sử dụng được 
   

int main()
   
{
   
    //printf("temp = %d",temp);
   
    test();
   
}
+file 2:
   
#include<stdio.h>
   
#include<stdint.h>
   


static uint8_t temp = 0; // khi mà biến toàn cục khai báo theo kiểu static thì chỉ có thể sử dụng trong file được khai báo 

static void dem()
   
{
   
    printf("dem = %d",temp);
   
}
   

void test()
   
{
   
    dem();
   
}
   
=> như vậy khi ta gọi extern trong file 1 nhưng biến toàn cục "temp" và hàm"dem" đều báo lỗi.
   
1.4 biến register (thanh ghi)
   
- tác dụng của register là làm tăng hiệu suất của chương trình.
   

quá trình tính toán của 1 chương trình.
   
 

khi ta khai báo 1 biến trong chương trình thì biến đó sẽ được lưu trên bộ nhớ RAM (bộ nhớ RAM chỉ lưu kết quả không có khả năng tính toán) 
   
- Sau đó bộ nhớ này sẽ đưa biến đưa khai báo lên bộ nhớ register và từu bộ nhớ register lên bộ nhớ ALU để tính toán.
   
- và từ bộ nhớ ALU biến sau khi được tính toán sẽ được trả lại lần lượt bộ nhớ register và trở về lưu trên bộ nhớ RAM
   

- khi khai báo biến với register tốc độ sử lý sẽ nhanh hơn rất nhiều vì biến đó sẽ được lưu trên bộ nhớ register.
   
*lưu ý:
   
- trong  quá trình viết chương trình nhưng biến cần có hiệu suất cao thì mới lưu ở bộ nhớ register vì bộ nhớ của register nhỏ và có hạn.
   
- ta không thể khai báo biến toàn cục với register.

   
+Cú pháp:
   
register <type_of_data>   <variable>
+ EX: ví dụ về sử dụng register 
   
   
#include <stdio.h>
   
   
#include <stdint.h>
   
   
#include <time.h>
   


int main()
   
{
   
   
    clock_t start, end;
   

    register uint32_t i;  //khi khai báo register trước variable thì thông báo rằng biến này sẽ được lưu trên bộ nhớ register
   

    /*những biến mà cần tốc độ sư lý nhanh và hiệu suất cao thì mới sử dụng register để khai báo
   
   
    vì bộ nhớ register rất nhỏ và có giới hạn*/
   

    start = clock();

   
    for(i = 0; i < 0xFFFFFFFF; i++)

                              
    end = clock();
                              

    printf("time : %f\n", (double)(end - start) /CLOCKS_PER_SEC);
                              

    return 0;
                              
}

                                        ===========================Buổi 5================================
                              
1. biến volatile .
                              
ta có ví dụ sau:
                              
#include <stdio.h>
   
#include <stdint.h>
   
#include <time.h>
   


volatile uint8_t a;
   

volatile int test = 10;
   

void d();
   
void b();
   
void c();
   

int comment();
   

int main()
   
{
   
    while(1)
   
    {
   
        test = comment();
   
        d();
   
        b();
   
        c();
   
    }
   
}
   
- trong chương trình trên ta có thấy xuất hiện từ khóa "volatile"
   
+ ý nghĩa: 
   
- từ khóa "volatile" ở đây được dùng để cảnh báo trình biên dịch rằng giá trị của biến có thể thay đổi bất kỳ lúc nào, không chỉ do chương trình chính và còn do
   yếu tố bên ngoài .
   
- việc sử dụng từ khóa "volatile" đảm bảo rằng trình biên dịch sẽ không tối ưu hóa mã máy bằng cách sử dụng các giá trị với giả định rằng chúng không thay đổi 
trong quá trình thực thi chương trình. Thay vào đó, trình biên dịch sẽ luôn đọc lại giá trị của biến từ vị trí bộ nhớ của nó (memory location) mỗi khi biến được sử dụng trong chương trình.

   2. Phân vùng nhớ:
	![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/388e1593-e435-4666-b4b6-3dd49097a333)

   
- bộ nhớ gồm 2 phần 
   
+ FLASH : dùng để lưu bộ nhớ chương trình khi tắt nguồn đi thì nó vẫn còn lưu.
   
+ RAM : tốc độ truy suất nhanh nhưng khi mất điện thì nó sẽ clear hết những chương trình cũ trên RAM.	
   
>> ta sẽ nghiên cứu về phân vùng nhớ RAM.
   
- Trong bộ nhớ RAM sẽ có 5 phân vùng nhớ:
   
 

* text : 
   
- quyền truy cập chỉ có read và nó chứa lệnh để thực thi nên tránh sửa đổi instruction (chỉ dẫn) 
   
+ "lệnh thực thi " : chính là chương trình của chúng ta mà được build đến cuối cùng 
   
- chương trình của chúng ta sau khi được build sẽ được lưu ở text nhưng chỉ có thể đọc không thể sửa đổi được.
   
- chứa khai báo hằng số trong chương trình.
   
+ "hằng số": const 
   
ví du: 
   
#include <stdio.h>
   
#include <stdint.h>
   

const uint8_t temp = 15;  // đây là 1 hằng số được lưu trữ trên phân vừng nhớ test.
   


int main(int argc, char const *argv[])
   
{
   
   temp = 10;   // chỉ có thể xem giá trị của temp nhưng không thể sửa đổi giá trị của nó
   
    printf("temp = %d",temp);
   
    return 0;
   
}

   
=> nghĩa là tất cả các biến hằng số được lưu ở phần vùng test ta chỉ có thể đọc nó chứ không thể sửa đổi nó.
	
*Data:
   
- quyền truy cập đọc và sửa được.
   
- chứa biến toàn cục hoặc biến static với giá trị khởi tạo khác không
   
- được giải phóng khi kết thúc chương trình.
   
+Ví dụ:
   
#include <stdio.h>
   
#include <stdint.h>
   

const uint8_t temp = 15;  // đây là 1 hằng số được lưu trữ trên phân vừng nhớ test.
   

uint8_t cal = 5; // đây là biến toàn cục
   

static uint8_t sal = 5; // đây là biến static với biến toàn cục tức là chỉ được sử dụng biến đó trong file này
   

void find()
 
{
   
    static uint8_t count = 5; //đây là biến static với biến cục bộ tức là biến này được cấp phát bộ nhớ trong suốt chương trình
   
}

   
int main(int argc, char const *argv[])
   
{
   
    temp = 10;   // chỉ có thể xem giá trị của temp nhưng không thể sửa đổi giá trị của nó
   
    printf("temp = %d",temp);
   
    return 0;
   
}
   
*Bss:
   
- quyến truy cập read hoặc write.
   
- khác với phân vùng nhớ Data thì phân vùng nhớ Bss chứa biến toàn cục hoặc biến static với giá trị khởi tạo băng không hoặc không khởi tạo.
   
- Được giải phóng khi kết thúc chương trình.
   
-Ví dụ:
   
#include <stdio.h>
   
#include <stdint.h>
   

static uint8_t a; // đây là biến static với biến toàn cục không được khởi tạo giá trị
   
uint8_t b = 0; // đây là biến toàn cục được khởi tạo bằng không 
   

int main(int argc, char const *argv[])
   
{
   
    a = 10;   // giống với phân vùng nhớ Data thì phân vùng nhớ Bss có thể đọc hoặc viết dữ liệu
   
    printf("temp = %d",a);
   
    return 0;
   
}


/*tức khi khai báo biến toàn cục hoặc biến static mà không khởi tạo 
   
giá trị hoặc khởi tạo giá trị bằng không thì biến đó sẽ được phân vùng nhớ ở phân vùng nhớ Bss*/
   

*Stack:
   
- quyền truy cập là read và write 
   
-  được sử dụng cấp phát cho biến local (biến cục bộ), input parameter của hàm,...
   
- sẽ được giải phóng khi gọi hàm free,...
   
- Ví dụ :
   

#include <stdio.h>
   
#include <stdint.h>
   


uint8_t tong(uint8_t a, uint8_t b)  // a và b ở đây được gọi la input parameter của hàm
   
{
   
    uint8_t c = 0;                  // c ở đây được gọi là biến cục bộ local
   

    c = a + b;
   

    printf("dia chi cua a la : %p\n",&a);      //"%p" để ghi địa chỉ
   
    printf("dia chi cua b la : %p\n",&b);
   
    printf("dia chi cua c la : %p\n",&c);
   

    return c;
}
   


int main()
   
{
   
    printf(" the sum of a and b is : %d\n",tong(5,6));
   
    /*uint8_t a = 5  địa chỉ : 0x01
   
      uint8_t b = 6  địa chỉ : 0x02
   
      uint8_t c = 5 + 6  địa chỉ : 0x03
   
    */
   
   return 0; 
   
}
   

/*tức là : tất cả những biến cục bộ và input parameter của hàm sẽ được phân vùng nhớ
trên vùng nhớ Stack*/

   - Ví dụ:
   
#include <stdio.h>

void swap(int a, int b)
   
{
   
    int swap = a;
   
    a = b ;
   
    b = swap;
   
    printf("a = %d\n",a);
   
    printf("b = %d\n",b);
   
}

int main()
   
{
   
    int sodau = 10;
   
    int socuoi = 15;
   
    swap(sodau,socuoi); //khi thoát khỏi hàm thì bộ nhớ sẽ được thu hồi
   
   
   printf("so dau la :%d, so cuoi la :%d",sodau,socuoi);
}
   

*Heap:
   
- quyền truy cập là read và write.
   
- được sử dụng để cấp phát bộ nhớ động, malloc, calloc,..
   
- sẽ được giải phóng khi gọi hàm free,..
   
- Ví dụ:
   
#include <stdio.h>
   
#include <stdint.h>
   
#include <stdlib.h>  // thư viện dùng để khai báo các hàm cấp phát động
   

uint8_t array[] = {1,2,3,4}; // được gọi là "mạc tĩnh" tức là kích thước cố định không thay đổi
   

uint8_t *ptr;                //uint8_t : 1byte
   

int main(int argc, char const *argv[])
{
   
    uint16_t *ptr = (int16_t*)malloc(sizeof(int16_t)*5);   //malloc này là 5 byte
   

    for(int i = 0; i < 5; i++)
                         
    {
                         
            ptr[i] = 2*i;
                         
    }
                         

    for(int i = 0; i < 5; i++)
   
    {
   
        printf("i = %d\n",ptr[i]);
   
    }

    return 0;
   
}
- Ví dụ;
   
#include <stdio.h>
   
#include <stdint.h>
   
#include <stdlib.h>  // thư viện dùng để khai báo các hàm cấp phát động
   


void test1()
   
{
   
    uint8_t array[5];
   
   
    printf("dia chi cua mang la : %p\n",array);
   
}

void test2()
   
{
  
    uint8_t *array =  (uint8_t*)malloc(sizeof(int16_t)*5);   //malloc này là 5 byte
   

    printf("dia chi cua mang la : %p\n",array);
   

    free(array);

}

int main(int argc, char const *argv[])
   
{
    
    test1();  //dia chi 2 thg nay giống nhau 
   
    test1();
   

    /*tại sao 2 thg này giống nhau
    vì nó là cấp phát tĩnh địa chỉ của nó sẽ không thay đổi 
    và nó được phân vùng nhớ stack
    stack thoát ra khỏi hàm sẽ thu hồi vùng nhớ */
   

    test2();  // địa chỉ 2 thg này khác nhau
   
    test2();
   

    /*tại sao 2 thg này lại có địa chỉ khác nhau 
    vì nó được lưu trên phân vùng nhớ Heap
    phân vùng Heap không có cơ chế tự phân vùng nhớ mà phải dùng hàm free để thu hồi vùng nhớ*/
    return 0;
}
	
	                                          ======================Buổi 6========================
                                                       ==============Struct Union================

*"struct" : cấu trúc
	
*"union" : hợp nhất
	

1. struct
	
	
- là kiểu dữ liệu do người dùng tự định nghĩa, cũng giống với các kiểu dữ liệu khác như int, double,....
	
- "struct" là 1 kiểu dữ liệu được sử dụng để lưu trữ nhiều giá trị của các kiểu dữ liệu khác nhau dưới cùng 1 tên. Đây là 1 kiểu dữ liệu phức tạp được tạo ta từ nhiều kiểu dữ liệu cơ bản.
	
=> tức là ta có thể sử dụng "struct" để lưu nhiều biến có cùng kiểu dữ liệu hoặc nhiều biến với nhiều kiểu dữ liệu khác nhau.
	
- Ví dụ:
	
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

+ Cú pháp khai báo struct.
	
- cách 1:
	
typedef struct
	
{
	
<type of data>   <name>
	
<type of data>   <name>
	
<type of data>   <name>
	
}name_variable,
	

- cách 2 :
	
struct <Tên struct>
	
{
	
<Kiểu dữ liệu thành viên số 1> <Tên thành viên số 1>;
	
<Kiểu dữ liệu thành viên số 2> <Tên thành viên số 2>;
	
…
	
};

- Cú pháp khởi tạo giá trị biến:
	
+ cách 1: 
	
<tên struct>.<tên biến> = <giá trị cần gán>
	

+cách 2 :
	
<tên struct>.<tên biến> =  {<tên biến>.<tên biến struct 1> = <giá trị>, <tên biến>.<tên biến struct 2> = <giá trị>,<tên biến>.<tên biến struct 3> = <giá trị>}
	
+cách 3:
	
<tên struct>.<tên biến> = {<giá trị 1>, <giá trị 2>,...} 
	
- giá trị sẽ được gán lần lượt theo thứ tự khai báo theo trong struct.
	

*cách tính byte trong struct.
	
	
tên kiểu dữ liệu                                                                    byte
	
uint8_ t                                                                             1
	
uint16_t                             			                             2
	
uint32_t				                                             4

- xét ví dụ :
	
typedef  struct
	
{
	
uint8_t   a;
	
uint16_t b;
	
uint32_t c;
	
}find
	

- cách tính như sau 
	
+ xét biến có kiểu dữ liệu lớn nhất 
	
- trong trường hợp này là c với 4 byte vật ta sẽ quét với 4 byte
	
+ vì biến đầu tiên có 1 byte lên sau khi quét sẽ thùa ra 3 byte bộ nhớ đệm
	
+ sau đó vòng quét sẽ so sánh kiểu dữ liệu thứ 2 với 3 byte bộ nhớ đệm ở trên
	
- nếu kiểu dữ liệu của biến thứ 2 lớn hơn bộ nhớ đệm ta sẽ thực hiện quét lần 2 với bộ nhớ đệm lớn nhất như ta xét ban đầu là 4byte.
	
- nếu kiểu dữ liệu của biến thứ 2 nhỏ hơn bộ nhớ đệm thì sẽ sử dụng bộ nhớ đệm 
	
+trong trường hợp này vì kiểu dữ liệu của biến thứ 2 nhở hơn bộ nhớ đệm lên bộ nhớ đệm thứ 2 sẽ được lưu biến thứ 2 thừa 1 byte
	
- sau đó lại so sánh với biến thứ 3 trong trường hợp này là 4 byte > 1 byte bộ nhớ đệm lên sẽ quét lần thứ 2 thêm 4 byte và thừa 1 byte bộ nhớ đệm
	
>>> ta được tổng là = 4byte +4byte = 8yte
	

-Ví dụ:
	
#include <stdio.h>
	
#include <stdint.h>


typedef struct 
	
{
	
    uint8_t  a;          // 1byte tronng 4byte thừa 3byte bộ nhớ đệm
	
    uint16_t b;          // 2byte so sánh với 3 byte > 2<3 > lưu vào bộ nhớ đệm thừa 1byte
	
    uint32_t c;          // 4byte so sánh với 1 byte bộ nhớ đệm > 4>1 > quét lần 2 4byte thừa 1 byte bộ nhớ đệm
	
}byte;
	

// tổng 4 byte + 4byte = 8byte
	

typedef struct 
	
{
    uint32_t  e;         // 4byte trong 4byte quét > đủ > không có bộ nhớ đệm
	
    uint8_t   f;         // quét lần 2 1byte vs 4byte quét > thừa 3byte bộ nhớ đệm  
	
    uint16_t  g;         // so sánh vs 3byte bộ nhớ đệm > 2byte<3byte > thừ 1 byte bộ nhớ đệm 
	
}count_byte;

// tổng 4 byte + 4byte = 8byte

typedef struct 
	
{
    uint32_t  i;    
	
    uint8_t   j; 
	
    uint32_t  k; 
	
    uint8_t  h; 
	
}count_byte2;

int main(int argc, char const *argv[])
	
{
    byte date;
	
    count_byte cnt;
	
    count_byte2 nn;
	
    printf("size : %d\n",sizeof(date) );
	
    printf("size : %d\n",sizeof(cnt));
	
    printf("size : %d\n",sizeof(nn));
	
    return 0;
	
}

*cách tính byte cho các phần tử là mảng trong struct
	
- cho ví dụ :
	
	
typedef struct 
	
{     
	
    uint8_t     day[3];       //8  
	
    uint64_t   week[6];       //48
	
    uint32_t  month[4];       //16 
	
    uint16_t   year[5];       //16
	
}count_byte3;

+ta tính như sau:
	
- đầu tiên ta tách các phần tử trong mảng về thành các biến như sau:
	
typedef struct
	
{
	
uint8_t day[0];
	
uint8_t day[1];
	
uint8_t day[2];
	
lần lượt với các mảng còn lại
	
- sau đó sẽ làm như các bước hướng dẫn tính byte cho biến ở trên
	
ta có:
	
quét 1 : 8yte thừa 1 byte bộ nhớ đệm
	
quét 2:  vì thiếu bộ nhớ đệm lên thực hiện quét lần 2 với 8byte
	
quét 3:   8byte
	
quét 4:   8byte
	
quét 5:   8byte
	
quét 6:   8byte
	
quét 7:   8byte
	
quet 8:   8byte
	
quét  9 : 8byte
	
quét  10: 8byte
	
tổng :88byte 
	
2. kiểu dữ liệu union.
	
- giống với struct thì union cũng là kiểu dữ liệu do người dùng tự định nghĩa
	
- "union" là 1 kiểu dữ liệu giống như "struct" nhưng khác biệt ở chỗ chỉ được phép sử dụng một thành viên của "union" tại một thời điểm. "union" cho phép bạn lưu trữ nhiều giá trị của các loại dự liệu khác nhau trong cùng một vùng nhớ dưới một tên
	
=> nghĩa là tất cả các biến sẽ cùng được lưu tại 1 vùng nhớ và sẽ cùng có 1 giá trị trong cùng 1 thời điểm vì vậy ta sẽ không thể sử dụng các biến trong union cùng 1 lúc.
	
+ cú pháp khai báo các biến có kiểu dữ liệu union.
	
typedef union
	
{
	
<type of data> <member 1>
	
<type of data> <member 1>
	
<type of data> <member 1>
	
<type of data> <member 1>.
	
....
	
}<name union>;
	

-ví dụ về cách khai báo các biến và cách gán giá trị
	
    #include <stdio.h>
	
    #include <stdint.h>

    typedef union 
	
    {
	
        uint32_t var1;
	
        uint16_t var2;
	
        uint64_t var3;
	
    }typeData;


    int main(int argc, char const *argv[])
	
    {
	
        typeData data = {.var1 = 5, .var2 = 7, .var3 = 8};
	

        printf("gia tri : %d\n",data.var3);
	
        printf("gia tri : %d\n",data.var2);
	
        printf("gia tri : %d\n",data.var1);

        printf("gia tri : %p\n",&data.var3);
	
        printf("gia tri : %p\n",&data.var2);
	
        printf("gia tri : %p\n",&data.var1);
	
        printf("gia tri : %p\n",&data);
	
        return 0;
	
    }
    
	
    ***kết luận :
	
- giống với struct là có thể khai báo nhiều biến có cùng kiểu dữ liệu hoặc gồm nhiều kiểu dữ liệu khác nhau nhưng "struct" có thể sử dụng nhiều biến trong cùng 1 thời điểm và các biến này được lưu ở các địa chỉ khác nhau còn "union" chỉ có thể sử dụng 1 biến tại 1 thời điểm.
	
2.1 kích thước của union
	
- kích thước của "union" = kích thước của "member lớn nhất"
	

+ví dụ :
	
#include <stdio.h>
	
	
#include <stdint.h>

typedef union 
	
{
        
    uint32_t var1;
	
    uint16_t var2;
	
    uint64_t var3;
	

}typeData;


	
int main(int argc, char const *argv[])
	
{
	
    typeData sz;

    printf("kich thuoc cua union la : %d",sizeof(sz));
	
    return 0;
	
}

- trong trường hợp này kích thước của "union" sẽ chính bằng kích thước của phần tử lớn nhất trong "union" 
	
"kich thuoc cua union la : 8"
	
	
	                      =====================Buổi 7 : Goto====================
	

1. Goto:
	
- câu lệch thực hiện để giúp ta có thể nhảy đến bất cứ nơi đâu trong chương trình.
	
- nhược điểm là làm thay đổi tính tuần tự của chương trình có thể gây lỗi
	
=> tức là  khi bạn muốn thực hiện nhảy đền một vị trí khác của chương trình không theo tuần tự của chương trình thì ta sẽ sử dụng câu lệnh này 
+cú pháp: 

goto ten_nhan;
..
.
ten_nhan: lenh;

+Ví dụ:
	
#include <stdio.h>



int main(int argc, char const *argv[])
{
	
    int a;

    nhap:
	
    printf("vui long nhap vao a : ");
	
    scanf("%d",&a);
	

	
    if(a < 10)
	      
    {
	      
        goto nhap;
	      
    }
	      
    return 0;
	      
}
	      
- giải thích cách hoạt động của lệnh goto trong chương trình này 
	      
gt : chương trình yêu cầu nhập vào a và so sánh giá trị a nhập vào với điều kiện trong câu lệnh if
	      
nếu a < 10 thì thực hiện câu lệnh goto đi đến nhãn mang tên nhap :
	
vào lại so sánh trong câu lệnh if
	
đến khi nào mà a  nhập vào lớn hơn hoặc bằng 10 sẽ không thực hiện câu lệnh goto nữa
	
=> tức là nếu điều kiện trong if còn đúng thì còn thực hiện câu lệnh goto đến khi nào điều kiện trong if sai thì thôi.
	
	1.1: Exit
- hàm "exit()" trong c có chức năng ngay lập tức thóa khỏi chương trình 
- hàm "exit()" thực chất là 1 lời gọi tới hệ điều hành .
- bạn cần khai báo thư viện "stdlib.h" để sử dụng thư viên này.

+Ví dụ 1:
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    for(int i = 0; i < 10; i++)
    {
       printf("i = %d\n",i);
       if( i == 5 )
       {
        exit(0);
       } 
    }
    return 0;
}

=> khác với break thì exit sẽ lập tức dừng lại chương trình còn break chỉ có khả năng thoát khoi vòng lặp .
	
2. Setjum
	
2.1 thư viện "setjmp.h"
	
- thư viện "setjmp" trong c cung cấp các hàm để quản lý các điểm nhảy trong chương  trình . có thể sử dụng các hàm này để đăng ký các điểm nhảy và quay lại với điểm nhảy đã đăng ký đó trong chương trình.
	
- hàm chính trong thư viện này là "setjmp()" và "longjmp()".
	
- hàm "setjmp()" được sử dụng để đăng ký điểm nhảy và lưu trữ trạng thái của chương trình tại thời điểm đó . Hàm này sẽ trả về 0 nếu nó được gọi lần đầu tiên trong chương trình của bạn và trả về một giá trị khác 0 nếu nó được gọi hàm "longjmp()" . Hàm "setjmp" thường được sử dụng để đăng ký một điểm nhảy cho việc xử lý các trường hợp "ngoại lệ". Bạn có thể lưu trữ giá trị trả về hàm "setjmp()" để sử dụng về sau trong chương trình.
	
- Hàm "longjmp()" được sử dụng để "nhảy" trở lại điểm nhảy đã được đăng ký bởi hàm "setjmp()". Trong hàm "longjmp()" cần truyền đối số là biến kiểu"jmp_buf" và 1 giá trị không âm, đại diện cho giá trị trả về của hàm "setjmp()". Khi hàm "longjmp()" được gọi, chương trình sẽ trở lại điểm nhảy đã được đăng ký trước bởi hàm "setjmp()" và bắt đầu thực thi từ đó. Hàm "longjmp()" thường được sử dụng để thoát khỏi các hàm con sâu hơn trong chương trình. Tất cả các biến cục bộ sẽ bị mất đi và chương trình sẽ tiếp thực thực thi từ điểm nhảy.
	
* 1 số lưu ý khi sủ dụng thư viện "setjmp()":
	
+ Cần phải sử dụng cặp hàm "setjmp()" - "longjmp()" cừng với nhau trong chương trình
	
+ Khi gọi hàm "longjmp()" chương trình sẽ trở về điểm nhảy quy định bởi hàm "setjmp()" gần nhất, nên cần chắc chắn rằng hàm "setjmp()" đã được gọi trước đó.
	
+ Biến kiểu "jmp_buf" phải là 1 đối tượng lớn và phức tạp, nên bạn cần phải khai báo nó trước vào đầu chương trình .
tránh ảnh hưởng đến hiệu suất của chương trình.
	
- Ví dụ:
	
#include <stdio.h>
	
#include <stdlib.h>   // để sử hàm exit thoát chương trình
	
#include <setjmp.h>   // thư viện "setjmp.h" trong c cung cấp các hàm để quản lý điểm nhảy trong chương trình
	


int main(int argc, char const *argv[])
	
{
	
    jmp_buf jumb;                 // tạo 1 biến theo kiểu jmp_buf
	
    int i = setjmp(jumb);           // tạo 1 điểm nhảy i 
	
    printf("i = %d\n",i);
	
    if(i != 0)
	
    {
	
        exit(0);
	
    }

	
    longjmp(jumb, 1);              // 
	
    return 0;
	
}


                                            ==================buổi 8 : poiter======================/
					    

1. poiter
   
1,1 biến con trỏ


ví dụ:

int a = 10;

int *ptr = 0x01;


- biến bình thường sẽ lưu giá trị
- 
- biến con trỏ sẽ lưu giá trị địa chỉ của biến khác.
- 

nếu ta có địa chỉ của 1 biến nào đó mà muốn lấy giá trị của biến đó ta thêm * trước địa chỉ đó.

ví dụ:

#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>



int a = 10;

char b = 'C';

void tong()

{

    printf("ren roi noi di cung!");
    
}



int main(int argc, char const *argv[])

{

    int *ptr = &a;
    
    *ptr = 25;
    
    printf("chao buoi sang\n");
    
    printf("gia tri dia chi cua a la : %p\n",ptr);
    
    printf("gia tri dia chi cua b la : %p\n",&b);
    
    printf("gia tri dia chi cua tong la : %p\n",&tong);
    
    printf("gia tri cua a la : %d\n",a);
    
    return 0;
    
}


- ở đây ta có int *ptr là khai báo 1 biến con trỏ "= a" là để khai báo rằng giá trị biến con trỏ ptr là giá trị địa chỉ của con trỏ a .
  
- còn  ở dưới ta có  "*ptr" = 25 tức là gán giá trị của a = 23
  
vì sao trên *ptr mà dưới cũng *ptr mà lại cho giá trị khác nhau?

Vì trên int *ptr ở đây là 1 biến con trỏ bản chất của con trỏ là giá trị của nó sẽ là địa chỉ của biến mà con trỏ trỏ tới tức là ở đây biến con trỏ sẽ lưu địa chỉ của biến a.

còn ở dưới ở đây không phải là con trỏ mà là giá trị tại địa chỉ mà con trỏ trỏ tới trên là giá trị địa chỉ dưới là giá trị tại địa chỉ mà con trỏ trở tới lên khi này nó có giá trị bằng giá trị của biến a là bằng 10 và sau đó được gán bằng 25.


1.2 hàm con trỏ

- cũng giống với biến con trỏ là lưu địa chỉ nhưng khác với con trỏ biến thì hàm con trỏ lưu địa chỉ của hàm.
cho ví dụ:


#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>



void tong(int a,int b)

{

    printf("tong cua %d va %d = %d\n",a,b,a+b);
    
}

float thuong(float a ,float b)

{

    return a*b;
    
}

int main(int argc, char const *argv[])

{
    void(*ptr)(int,int);
    
    ptr = &tong;
    
    ptr(8,10);

    float(*ptr1)(float,float);
    
    ptr1 = &thuong;
    
    printf("thuong cua a va b la : %.2f",ptr1(1.2,2.1));
    
    return 0;
    
}

- ta có : cách khởi tạo 1 con trỏ tới hàm như sau :

void (*ptr)(int,int);

trong đó ta có hàm được con trỏ trở tới không có giá trị trả về lên là void(*ptr) 2 biến input parameter có kiểu dữ liệu là kiểu int lên sẽ là void (*ptr)(int,int);

sau đó gán giá trị của con trỏ bằng địa chỉ của hàm tức là ptr = &tong;

sau khi gán giá trị cho con trỏ bằng địa chỉ hàm đó thì có thể thay thế hàm bằng con trỏ đó như sau:

ptr(8,10) ở đây ta không cần gọi lại hàm tong() mà sẽ thay thế bằng ptr() vì lúc này con trỏ ptr chính bằng địa chỉ của hàm tong()


tương tự như vậy với hàm thuong() thì có kiểu trả về là float,tham số đầu vào của hàm cũng có kiểu float lên khai báo con trỏ với hàm thuong() như sau:
float(*ptr1)(float,float);

ptr = & thuong;


1.2.2 cũng có thể thông qua con trỏ hàm sử dụng hàm được trỏ tới làm input parameter của 1 hàm khác như sau:

#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>



void tong(int a,int b)

{

    printf("tong cua %d va %d = %d\n",a,b,a+b);
    
}


void hieu(int a,int b)

{

    printf("hieu cua %d va %d = %d\n",a,b,a-b);
    
}

void tich(int a,int b)

{

    printf("tong cua %d va %d = %d\n",a,b,a*b);
    
}

void thuong(int a,int b)

{

    printf("thuong cua %d va %d = %.2f\n",a,b,(float)a/b);
    
}


void pheptinh(int a, int b, void(*ptr)(int,int))

{

    printf("phep tinh la : \n");

    ptr(a,b);
    
}

int main(int argc, char const *argv[])

{

    pheptinh(8, 6, &tong);
    
    pheptinh(8, 6, &hieu);
    
    pheptinh(8, 6, &tich);
    
    pheptinh(8, 6, &thuong);
    
    return 0;
    
}

- ta thấy:
- 
"void tong(int a,int b)

{

    printf("tong cua %d va %d = %d\n",a,b,a+b);
    
}

void hieu(int a,int b)

{

    printf("hieu cua %d va %d = %d\n",a,b,a-b);
    
}

void tich(int a,int b)

{

    printf("tong cua %d va %d = %d\n",a,b,a*b);
    
}

void thuong(int a,int b)

{

    printf("thuong cua %d va %d = %.2f\n",a,b,(float)a/b);
    
}"

đều là những hàm không có kiểu trả về đồng thời tham số truyền vào đều có kiểu int 

=> vì vậy ở đây ta sử dụng biến con trỏ hàm làm tham số truyền vào của 1 hàm mang tên pheptinh() 

tức là ta sẽ khởi tạo 1 con trỏ hàm như sau:

void pheptinh(int a, int b, void(*ptr)(int, int);

ptr(a,b);


sau đó trong hàm main ta gọi hàm pheptinh(8,6, &tong);

tức này ta đã truyền vào địa chỉ của thằng tổng cho con trỏ ptr và như trên đã nói khi nó gắn bằng địa chỉ của 1 hàm thì nó có thể thay thế hàm đó thực hiện chức năng trong hàm và ở đây nó đã trở thành 1 tham số truyền vào cho hàm khác

=> tức là có thể sử dụng con trỏ hàm đề làm 1 iput parametter cho hàm khác.

1.2.3 con trỏ đặc biệt void *ptr

xét ví dụ:

#include <stdio.h>


int main(int argc, char const *argv[])

{

    int a = 10;
    
    char b = 'c';
    
    double c = 10.65;
    

    int *ptr = &a;
    
    ptr = &b;
    
    ptr = &c;
    
    return 0;
    
}

ta có biến con trỏ :

int *ptr 

- tức là đây là biến con trỏ có kiểu trả về là int
- 
lên nếu gán giá trị của con trỏ đó băng giá trị địa chỉ của biên có kiểu dữ liệu khác kiểu int sẽ lỗi


*còn nếu khai báo biến con trỏ theo kiểu đặc biệt void *ptr thì có thể lưu hết tất cả giá trị địa chỉ của tất cả các loại biến

ví dụ:

#include <stdio.h>


int main(int argc, char const *argv[])

{
    int a = 10;
    
    char b = 'c';
    
    double c = 10.65;
    

    void *ptr = &a;

    
    printf("gia tri cua a la : %d\n",ptr);

    ptr = &b;
    
    printf("gia tri cua b la : %p\n",ptr);

    ptr = &c;
    
    printf("gia tri cua b la : %p\n",ptr);

    return 0;
    
}


=> với con trỏ kiểu void ta có thể lưu hết tất các các địa chỉ của tất cả các biến 

- vậy với địa chỉ đó thì con trỏ có lấy được giá trị tại địa chỉ nó trỏ tới hay không câu trả lời là không.
  
vì với kiểu trả về là void nó sẽ không biết giá trị được lưu tại địa chỉ đó có kiểu gì lên nó sẽ không đọc ra được giá trị đó

- vậy có cách nào để lấy giá trị đó không câu trả lời là có ta phải ép kiểu cho con trỏ đó
  
ví dụ 

ta có 

int a = 10;

void *ptr = &a;

    printf("gia tri cua a la : %d\n",ptr);
    
- để lấy được giá trị của  a ta phải ép kiểu cho con trỏ ptr như sau:
  
đó là thêm

 "*(kieu_tra_ve*)ptr"
 

printf("gia tri cua a la : %d\n",*(int*)ptr);



-Ví dụ:

#include <stdio.h>



int main(int argc, char const *argv[])

{

    int a = 10;
    
    char b = 'c';
    
    double c = 10.65;
    

    void *ptr = &a;

    
    printf("gia tri cua a la : %d\n",ptr);
    
    printf("gia tri cua a la : %d\n",*(int*)ptr);
    

    ptr = &b;
    
    printf("gia tri cua b la : %p\n",ptr);
    
    printf("gia tri cua b la : %c\n",*(char*)ptr);
    

    ptr = &c;
    
    printf("gia tri cua c la : %p\n",ptr);
    
    printf("gia tri cua b la : %.2f\n",*(double*)ptr);
    

    return 0;
    
}

Output:

gia tri cua a la : 6291092

gia tri cua a la : 10

gia tri cua b la : 00000000005ffe93

gia tri cua b la : c

gia tri cua c la : 00000000005ffe88

gia tri cua b la : 10.65

2. hàm con trỏ

- khi sử dụng 1 hàm theo kiểu con trỏ ta có thể lưu nhiều địa chỉ trong cùng 1 mảng với con trỏ.
  
-Ví dụ:

#include <stdio.h>

#include <stdlib.h>



int a = 10;


char b = 'c';


void tong (int a, int b)

{

    printf("tong cua 2 so a va b la : %d",a+b);
    
}

int main(int argc, char const *argv[])

{

    void *arry[] = {&a, &b, &tong};
    

    printf("gia tri cua a la :%d\n", *(int *)arry[0]);
    
    printf("gia tri cua a la :%c\n", *(char *)arry[1]);
    
    
    int(*ptr)(int,int) = (void (*)(int,int))arry[2];
    
    int tong = ptr(5,8);
    
    


    return 0;
    
}

3. Con trỏ NULL

-Ví dụ:

#include <stdio.h>

#include <stlib.h>


int main(int argc, char const *argv[])

{

    int*ptr;
    
    
    return 0;
    
}

- con trỏ "int*ptr; " khi không được gán một giá trị địa chỉ cho nó nó sẽ trỏ đến 1 giá trị rác, đôi khi địa chỉ đó chính là 1 địa chỉ nào đó trong chương trình của mình
- 
khi con trỏ đã trỏ đến địa chỉ rác đó thì con trỏ có thể thay đổi giá trị được lưu tại địa chỉ đó được. Có thể vì nguyên nhân đó có thể làm cho chương trình của mình bị lỗi.

=> Nên khi khai báo 1 con trỏ mà không sử dụng thì người ta sẽ khai báo cho nó 1 địa chỉ NULL (có địa chỉ là 0x00 và có giá trị = 0) hoặc khi ta khai báo 1 con trỏ mà khi sử dụng xong ta không muốn sử dụng nữa thì lúc đó ta cũng khai báo địa chỉ NULL cho con trỏ.

-Ví dụ:

#include <stdio.h>

#include <stdlib.h>


int main(int argc, char const *argv[])

{

    int*ptr = NULL;
    

    printf("gia tri cua con tro la : %d",*ptr);
    

    return 0;
    
}

4. poiter to poiter (con trỏ tới con trỏ) - con trỏ cấp 2
   
![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/693790f0-5dcc-4a03-b78c-75d197927a9c)

 
- ở đây ta có con trỏ cấp 1 với int *ptr có giá trị là 0xc1 và có địa chỉ là 0xa3;
vậy thì con trỏ poiter to poiter là gì ?

- là 1 con trỏ cấp 2 dùng để lưu địa chỉ của con trỏ cấp 1 nó có giá trị = địa chỉ của con trỏ cấp 1 ở đây là 0xa3 và có giá trị = 0xc1

+Kết luận:

- khi mà ta chỉ muốn đọc giá trị của biến thì dùng truyền vào biến còn khi nào ta muốn đọc và có thể thay đổi giá trị của biến thi dùng poiter.

  - Trong ngôn ngữ lập trình C, con trỏ cấp 2 (hay con trỏ tới con trỏ) là một con trỏ trỏ tới một con trỏ khác. Nó cho phép ta truy xuất đến giá trị hoặc địa chỉ của một biến thông qua một con trỏ trung gian. Có nhiều trường hợp mà con trỏ cấp 2 rất hữu ích, như khi ta làm việc với các cấu trúc dữ liệu phức tạp.

Cú pháp của con trỏ cấp 2 là `type **var;`, trong đó `type` là kiểu dữ liệu được trỏ đến và `var` là tên của con trỏ. Chúng ta có thể sử dụng toán tử `&` để lấy địa chỉ của con trỏ cấp 1, và sử dụng toán tử `*` để lấy giá trị của biến mà con trỏ cấp 2 đang trỏ tới. Để truyền con trỏ cấp 2 vào hàm, ta cần khai báo đối số tương ứng với con trỏ cấp 2 bằng cách sử dụng cú pháp `type **var`.

#include <stdio.h>

void swap(int **p1, int **p2) {

    int *temp = *p1;
    
    *p1 = *p2;
    
    *p2 = temp;
    
}

int main()
{

    int a = 10, b = 20;
    
    int *p1 = &a, *p2 = &b;
    

    printf("Before swap: a = %d, b = %d\n", a, b);
    
    swap(&p1, &p2);
    
    printf("After swap: a = %d, b = %d\n", a, b);
    

    return 0;
    
}

Trong ví dụ này, chúng ta khai báo hai con trỏ `p1` và `p2` trỏ tới hai biến `a` và `b` tương ứng. Hàm `swap` có hai tham số kiểu con trỏ cấp 2 để nhận địa chỉ của `p1` và `p2` và thực hiện hoán đổi giá trị của chúng. Trong hàm `swap`, chúng ta sử dụng một biến trung gian `temp` để lưu giá trị của `*p1`, sau đó gán `*p1 = *p2`, `*p2 = temp` để hoán đổi giá trị của `p1` và `p2`. Trong hàm `main`, chúng ta gọi `swap` bằng cách truyền địa chỉ của `p1` và `p2` cho hai tham số của hàm. Kết quả in ra sẽ cho thấy rằng giá trị của biến `a` và `b` được hoán đổi thành công.



                                       =====================Buổi 9 : bài tập =====================
				       

bài 1:

yêu cầu : tạo 1 mảng ngẫu nhiên có n phần tử và sắp xếp số phần tử trong đó theo thứ tự bé đến lớn.


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


bài 2 : đếm số lần xuất hiện của các phần tử trong mảng ở trên

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


void in_so_lan_xuat_hien(uint8_t array[], int so_phan_tu) {

    uint8_t count[so_phan_tu];
    
    
    // Khởi tạo tất cả các giá trị của count bằng 0
    
    for (int i = 0; i < so_phan_tu; i++) {
    
        count[i] = 0;
    }
    
    
    // Tính số lần xuất hiện của mỗi phần tử trong mảng
    
    for (int i = 0; i < so_phan_tu; i++) {
    
        count[array[i]]++;
	
    }
    
    // In ra số lần xuất hiện của từng phần tử trong mảng
    
    printf("So lan xuat hien cua cac phan tu trong mang la:\n");
    
    for (int i = 0; i < so_phan_tu; i++) {
    
        if (count[i] > 0) {
	
            printf("%d xuat hien %d lan\n", i, count[i]);
	    
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
    

    in_so_lan_xuat_hien(array,so_phan_tu);
    
    return 0;
    
}


		===================== Buổi 10 : Linklist ===================
                                ===== Danh sách liên kết ======

1. danh sách liên kết Linklist.
   
Một Danh sách liên kết (Linked List) là một dãy các cấu trúc dữ liệu được kết nối với nhau thông qua các liên kết (link). Hiểu một cách đơn giản thì Danh sách liên kết là một cấu trúc dữ liệu bao gồm một nhóm các nút (node) tạo thành một chuỗi. Mỗi nút gồm dữ liệu ở nút đó và tham chiếu đến nút kế tiếp trong chuỗi.

Danh sách liên kết là cấu trúc dữ liệu được sử dụng phổ biến thứ hai sau mảng. Dưới đây là các khái niệm cơ bản liên quan tới Danh sách liên kết:

Link (liên kết): mỗi link của một Danh sách liên kết có thể lưu giữ một dữ liệu được gọi là một phần tử.

Next: Mỗi liên kết của một Danh sách liên kết chứa một link tới next link được gọi là Next.

First: một Danh sách liên kết bao gồm các link kết nối tới first link được gọi là First.

Biểu diễn Danh sách liên kết (Linked List)

Danh sách liên kết có thể được biểu diễn như là một chuỗi các nút (node). Mỗi nút sẽ trỏ tới nút kế tiếp.

 


Cấu trúc dữ liệu Danh sách liên kết (Linked List)


Dưới đây là một số điểm cần nhớ về Danh sách liên kết:

Danh sách liên kết chứa một phần tử link thì được gọi là First.

Mỗi link mang một trường dữ liệu và một trường link được gọi là Next.

Mỗi link được liên kết với link kế tiếp bởi sử dụng link kế tiếp của nó.

Link cuối cùng mang một link là null để đánh dấu điểm cuối của danh sách.

Các loại Danh sách liên kết (Linked List)

Dưới đây là các loại Danh sách liên kết (Linked List) đa dạng:

Danh sách liên kết đơn (Simple Linked List): chỉ duyệt các phần tử theo chiều về trước.

Danh sách liên kết đôi (Doubly Linked List): các phần tử có thể được duyệt theo chiều về trước hoặc về sau.

Danh sách liên kết vòng (Circular Linked List): phần tử cuối cùng chứa link của phần tử đầu tiên như là next và phần tử đầu tiên có link tới phần tử cuối cùng như là prev.

Các hoạt động cơ bản trên Danh sách liên kết

Dưới đây là một số hoạt động cơ bản có thể được thực hiện bởi một danh sách liên kết:


Hoạt động chèn: thêm một phần tử vào đầu danh sách liên kết.

Hoạt động xóa (phần tử đầu): xóa một phần tử tại đầu danh sách liên kết.

Hiển thị: hiển thị toàn bộ danh sách.

Hoạt động tìm kiếm: tìm kiếm phần tử bởi sử dụng khóa (key) đã cung cấp.

Hoạt động xóa (bởi sử dụng khóa): xóa một phần tử bởi sử dụng khóa (key) đã cung cấp.

Hoạt động chèn trong Danh sách liên kết

Việc thêm một nút mới vào trong danh sách liên kết không chỉ là một hoạt động thêm đơn giản như trong các cấu trúc dữ liệu khác (bởi vì chúng ta có dữ liệu và có link). Chúng ta sẽ tìm hiểu thông qua sơ đồ dưới đây. Đầu tiên, tạo một nút bởi sử dụng cùng cấu trúc và tìm vị trí để chèn nút này.
 
![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/8c18ab79-43f3-4968-bf52-9b3ff2d44120)


Hoạt động chèn trong Danh sách liên kết

Giả sử chúng ta cần chèn một nút B vào giữa nút A (nút trái) và C (nút phải). Do đó: B.next trỏ tới C.

NewNode.next −> RightNode;

Hình minh họa như sau:

![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/d422fbf8-cd02-4b80-ac57-d6352df2f580)

 


Hoạt động chèn trong Danh sách liên kết

Bây giờ, next của nút bên trái sẽ trở tới nút mới.

LeftNode.next −> NewNode;

Hoạt động chèn trong Danh sách liên kết

Quá trình trên sẽ đặt nút mới vào giữa hai nút. Khi đó danh sách mới sẽ trông như sau:

Hoạt động chèn trong Danh sách liên kết

 ![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/6e818e37-0a30-46c4-8725-7643d8b94c4d)



Các bước tương tự sẽ được thực hiện nếu chèn nút vào đầu danh sách liên kết. Trong khi đặt một nút vào vị trí cuối của danh sách, thìnút thứ hai tính từ nút cuối cùng của danh sách sẽ trỏ tới nút mới và nút mới sẽ trỏ tới NULL.


Hoạt động xóa trong Danh sách liên kết cũng phức tạp hơn trong cấu trúc dữ liệu khác. Đầu tiên chúng ta cần định vị nút cần xóa bởi sử dụng các giải thuật tìm kiếm.
 
![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/f9739ad3-eee9-4452-a4d9-80db67aa7d8d)


Bây giờ, nút bên trái (prev) của nút cần xóa nên trỏ tới nút kế tiếp (next) của nút cần xóa.

LeftNode.next −> TargetNode.next;

 ![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/cb1841c1-fb8c-4ac6-aef2-1ca86ac2bcc2)



Quá trình này sẽ xóa link trỏ tới nút cần xóa. Bây giờ chúng ta sẽ xóa những gì mà nút cần xóa đang trỏ tới.

TargetNode.next −> NULL;

 ![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/9ae707aa-132b-43a4-954b-4f92f7fa4b33)


Hoạt động xóa trong Danh sách liên kết

Nếu bạn cần sử dụng nút đã bị xóa này thì bạn có thể giữ chúng trong bộ nhớ, nếu không bạn có thể xóa hoàn toàn hẳn nó khỏi bộ nhớ.

 

![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/6b858cfc-e80e-4cee-ade8-84163a19a62e)



Hoạt động đảo ngược Danh sách liên kết

Với hoạt động này, bạn cần phải cẩn thận. Chúng ta cần làm cho nút đầu (head) trỏ tới nút cuối cùng và đảo ngược toàn bộ danh sách liên kết.

 
![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/3aed99e4-4122-4649-a61f-9326cfecd431)


Đầu tiên, chúng ta duyệt tới phần cuối của danh sách. Nút này sẽ trỏ tới NULL. Bây giờ điều cần làm là làm cho nút cuối này trỏ tới nút phía trước của nó.

 
![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/a12a5b0d-dd0b-4d88-bae5-89689d178075)


Chúng ta phải đảm bảo rằng nút cuối cùng này sẽ không bị thất lạc, do đó chúng ta sẽ sử dụng một số nút tạm (temp node – giống như các biến tạm trung gian để lưu giữ giá trị). Tiếp theo, chúng ta sẽ làm cho từng nút bên trái sẽ trỏ tới nút trái của chúng.

 
![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/9f87c990-a263-4caa-962e-abb6d0ee5189)


Sau đó, nút đầu tiên sau nút head sẽ trỏ tới NULL.

 
![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/861fe98c-e826-4126-af53-36dca0307c96)


Chúng ta sẽ làm cho nút head trỏ tới nút đầu tiên mới bởi sử dụng các nút tạm.

 
![image](https://github.com/anhtrinhtuan0610/Advance-C/assets/134681201/cb7409b3-2369-489a-862b-fab6e4b97ea9)


Bây giờ Danh sách liên kết đã bị đảo ngược.

Danh sách liên kết (Linked List) trong C

Một Danh sách liên kết (Linked List) là một dãy các cấu trúc dữ liệu được kết nối với nhau thông qua các liên kết (link). Hiểu một cách đơn giản thì Danh sách liên kết là một cấu trúc dữ liệu bao gồm một nhóm các nút (node) tạo thành một chuỗi. Mỗi nút gồm dữ liệu ở nút đó và tham chiếu đến nút kế tiếp trong chuỗi

2. Nhắc lại lý thuyết cấp phát động Malloc, Calloc.
   
- khi ta khai báo 1 mảng như sau:
  
ví dụ:

uint8_t array[] = {1, 2, 3, 4} 

- đây được gọi là 1 mảng tĩnh nghĩa là mảng này không thay đổi kích thước được.
  
- bản chất của mảng là để lưu các giá trị liền kề.
  
2.1 cấp phát động 

Như bạn đã biết, mảng là một tập hợp của các phần tử nằm liên tiếp nhau trên bộ nhớ và có cùng kiểu dữ liệu. Khi khai báo mảng, bạn phải chỉ định rõ kích thước tối đa (số lượng phần tử tối đa). Và sau khi khai báo, bạn không thể thay đổi kích thước của mảng – Cấp phát tĩnh.

Đôi khi kích thước của mảng bạn khai báo có thể không đủ sài. Để giải quyết vấn đề này, bạn có thể cấp phát thêm bộ nhớ theo cách thủ công trong thời gian chạy chương trình. Đó cũng chính là khái niệm cấp phát động trong C.

Bảng dưới đây so sánh giúp bạn sự khác biệt giữa cấp phát bộ nhớ động và tĩnh.

Cấp phát bộ nhớ tĩnh	Cấp phát bộ nhớ động

Bộ nhớ được cấp phát trước khi chạy chương trình (trong quá trình biên dịch)	Bộ nhớ được cấp phát trong quá trình chạy chương trình.

Không thể cấp phát hay phân bổ lại bộ nhớ trong khi chạy chương trình	Cho phép quản lý, phân bổ hay giải phóng bộ nhớ trong khi chạy chương trình

Vùng nhớ được cấp phát và tồn tại cho đến khi kết thúc chương trình	Chỉ cấp phát vùng nhớ khi cần sử dụng tới

Chương trình chạy nhanh hơn so với cấp phát động	Chương trình chạy chậm hơn so với cấp phát tĩnh

Tốn nhiều không gian bộ nhớ hơn	Tiết kiệm được không gian bộ nhớ sử dụng

Ưu điểm chính của việc sử dụng cấp phát động là giúp ta tiết kiệm được không gian bộ nhớ mà chương trình sử dụng. Bởi vì chúng ta sẽ chỉ cấp phát khi cần dùng và có thể giải phóng vùng nhớ đó ngay sau khi sử dụng xong.


Nhược điểm chính của cấp phát động là bạn phải tự quản lý vùng nhớ mà bạn cấp phát. Nếu bạn cứ cấp phát mà quên giải phóng bộ nhớ thì chương trình của bạn sẽ tiêu thụ hết tài nguyên của máy tính dẫn đến tình trạng tràn bộ nhớ (memory leak).


Cấp phát bộ nhớ động trong C

Để cấp phát vùng nhớ động cho biến con trỏ trong ngôn ngữ C, bạn có thể sử dụng hàm malloc() hoặc hàm calloc(). Sử dụng hàm free() để giải phóng bộ nhớ đã cấp phát khi không cần sử dụng, sử dụng realloc() để thay đổi (phân bổ lại) kích thước bộ nhớ đã cấp phát trong khi chạy chương trình.

Sử dụng hàm malloc()

Từ malloc là đại diện cho cụm từ memory allocation (dịch: cấp phát bộ nhớ).


Hàm malloc() thực hiện cấp phát bộ nhớ bằng cách chỉ định số byte cần cấp phát. Hàm này trả về con trỏ kiểu void cho phép chúng ta có thể ép kiểu về bất cứ kiểu dữ liệu nào.

Cú pháp của hàm malloc():

ptr = (castType*) malloc(size);

Ví dụ:

ptr = (int*) malloc(100 * sizeof(int));

Ví dụ trên thực hiện cấp phát cho việc lưu trữ 100 số nguyên. Giả sử sizeof int là 4, khi đó lệnh dưới đây thực hiện cấp phát 400 bytes. Khi đó, con trỏ ptr sẽ có giá trị là địa chỉ của byte dữ liệu đầu tiên trong khối bộ nhớ vừa cấp phát.

Trong trường hợp không thể cấp phát bộ nhớ, nó sẽ trả về một con trỏ NULL.

Sử dụng hàm calloc()

Từ calloc đại diện cho cụm từ contiguous allocation (dịch: cấp phát liên tục).

Hàm malloc() khi cấp phát bộ nhớ thì vùng nhớ cấp phát đó không được khởi tạo giá trị ban đầu. Trong khi đó, hàm calloc() thực hiện cấp phát bộ nhớ và khởi tạo tất cả các ô nhớ có giá trị bằng 0.

Hàm calloc() nhận vào 2 tham số là số ô nhớ muốn khởi tạo và kích thước của 1 ô nhớ.

Cú pháp của hàm calloc():

ptr = (castType*)calloc(n, size);

Ví dụ:

ptr = (int*) calloc(100, sizeof(int));

Trong ví dụ trên, hàm calloc() thực hiện cấp phát 100 ô nhớ liên tiếp và mỗi ô nhớ có kích thước là số byte của kiểu int. Hàm này cũng trả về con trỏ chứa giá trị là địa chỉ của byte đầu tiên trong khối bộ nhớ vừa cấp phát.


Sử dụng hàm free()

Việc cấp phát bộ nhớ động trong C dù sử dụng malloc() hay calloc() thì chúng cũng đều không thể tự giải phóng bộ nhớ. Bạn cần sử dụng hàm free() để giải phóng vùng nhớ.

Cú pháp:

free(ptr); // ptr là con trỏ

Lệnh này sẽ giải phóng vùng nhớ mà con trỏ ptr đã được cấp phát. Giải phóng ở đây có nghĩa là trả lại vùng nhớ đó cho hệ điều hành và hệ điều hành có thể sử dụng vùng nhớ đó vào việc khác nếu cần.

Nếu bạn không giải phóng nó thì nó sẽ tồn tại cho tới khi chương trình kết thúc. Điều này sẽ rất nguy hiểm nếu chương trình của bạn liên tục cấp phát các vùng nhớ mới và sẽ gây ra hiện tượng tràn bộ nhớ mà mình đã nhắc tới ở trên. Thử code này xem sao (bảo đảm là máy bạn sẽ bị treo và chỉ còn cách ấn nút nguồn thôi, bạn có thể để cấp phát size nhỏ hơn và theo dõi thay đổi qua Task Manager):

#include <stdio.h>

#include <stdlib.h>

 
int main(){

    for(;;){
    
        printf("\nCap phat %d bytes!", 1000000 * sizeof (int));
	
        int *ptr = (int*) malloc (1000000 * sizeof (int));
	
 
    }
    
}

Ví dụ sử dụng malloc() và free()

Trong ví dụ dưới đây, chúng ta sẽ sử dụng hàm malloc() để cấp phát động n * sizeof int byte và sử dụng xong sẽ dùng free() để giải phóng.

#include <stdio.h>

// Thư viện này cần để cấp phát bộ nhớ động

#include <stdlib.h>

 
int main()

{

    int n, i, *ptr, sum = 0;
    
    printf("Nhap so luong phan tu: ");
    
    scanf("%d", &n);
    
    ptr = (int *)malloc(n * sizeof(int));
    
 
    // Nếu không thể cấp phát,
    
    // hàm malloc sẽ trả về con trỏ NULL
    
    if (ptr == NULL)
    
    {
    
        printf("Co loi! khong the cap phat bo nho.");
	
        exit(0);
	
    }
    
    printf("Nhap cac gia tri: ");
    
    for (i = 0; i < n; ++i)
    
    {
    
        scanf("%d", ptr + i);
	
        sum += *(ptr + i);
	
    }
    
    printf("Tong = %d", sum);
 
    // Giải phóng vùng nhớ cho con trỏ
    
    free(ptr);
    
    return 0;
    
}

Ví dụ sử dụng calloc() và free()

Trong ví dụ này, chúng ta sẽ dùng calloc() để cấp phát n ô nhớ liên tiếp và mỗi ô nhớ có kích thước là sizeof int. Lưu ý là hàm calloc() sẽ chậm hơn malloc() một chút do nó phải thêm bước khởi tạo các ô nhớ có giá trị bằng 0. Do đó, tùy thuộc bạn cần hiệu năng hay cần khởi tạo giá trị ban đầu mà sử dụng hàm cấp phát thích hợp.

#include <stdio.h>

// Thư viện này cần để cấp phát bộ nhớ động

#include <stdlib.h>

 
int main()

{

    int n, i, *ptr, sum = 0;
    
    printf("Nhap so luong phan tu: ");
    
    scanf("%d", &n);
    
    ptr = (int *)calloc(n, sizeof(int));
    
 
    // Nếu không thể cấp phát, 
    
    // hàm calloc sẽ trả về con trỏ NULL
    
    if (ptr == NULL)
    
    {
    
        printf("Co loi! khong the cap phat bo nho.");
	
        exit(0);
	
    }
    
    printf("Nhap cac gia tri: ");
    
    for (i = 0; i < n; ++i)
    
    {
    
        scanf("%d", ptr + i);
	
        sum += *(ptr + i);
	
    }
    
    printf("Tong = %d", sum);
    
 
    // Giải phóng vùng nhớ cho con trỏ
    
    free(ptr);
    
    return 0;
}

Sử dụng hàm realloc()

Nếu việc cấp phát bộ nhớ động không đủ hoặc cần nhiều hơn mức đã cấp phát, bạn có thể thay đổi kích thước của bộ nhớ đã được cấp phát trước đó bằng cách sử dụng hàm realloc().

Cú pháp của realloc():

ptr = realloc(ptr, n);

Hàm này thực hiện cấp phát vùng nhớ mới cho con trỏ ptr. Vùng nhớ mới đó sẽ có kích thước mới là n bytes.

Hàm này cũng trả về con trỏ chứa giá trị là địa chỉ của byte đầu tiên trong vùng nhớ mới. Hàm này sẽ cố gắng mở rộng số ô nhớ ra phía sau nếu có thể để giữ nguyên giá trị của con trỏ ban đầu. Trong trường hợp phải đổi sang một vùng nhớ khác, hàm realloc() cũng sẽ mang theo giá trị đã có ở vùng nhớ cũ sang vùng nhớ mới và giải phóng luôn vùng nhớ cũ (đọc thêm tài liệu số 2). Trong trường hợp không thể, nó sẽ trả về con trỏ NULL giống như malloc() và calloc().

Ví dụ sử dụng hàm realloc()

Trong ví dụ dưới đây, ta sẽ sử dụng hàm realloc() để tái phân bổ lại bộ nhớ. Như trong ví dụ dưới đây thì việc cấp phát không phải di chuyển sang vùng nhớ khác mà chỉ mở rộng ra phía sau.

#include <stdio.h>

#include <stdlib.h>

int main()

{

    int *ptr, i , n1, n2;
    
    printf("Nhap so luong phan tu: ");
    
    
    scanf("%d", &n1);
    
    ptr = (int*) malloc(n1 * sizeof(int));
    
    printf("Dia chi cua vung nho vua cap phat: %u", ptr);
    
    
    printf("\nNhap lai so luong phan tu: ");
    
    scanf("%d", &n2);
    
    // phân bổ lại vùng nhớ
    
    ptr = (int*) realloc(ptr, n2 * sizeof(int));
    
    printf("Dia chi cua vung nho duoc cap phat lai: %u", ptr);
    
    // giải phóng
    
    free(ptr);
    
    return 0;
    
}

Kết quả chạy:


Nhap so luong phan tu: 2

Dia chi cua vung nho vua cap phat: 1993360

Nhap lai so luong phan tu: 100

Dia chi cua vung nho duoc cap phat lai: 1993360








    















	





   
   



   


