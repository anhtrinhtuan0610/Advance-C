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



   


