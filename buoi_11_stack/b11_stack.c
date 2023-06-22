#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 5 

int8_t on_top = -1;


//isEmpty() returns true if stack is empty else false. /  kiểm tra xem là ngăn xếp có trống không
// cách để kiểm tra là kiểm tra xem phần tử ở đáy của ngăn xếp có giá trị hay không tức là "on_top" đã có giá trị hay chưa
//Nếu on_top = -1 tức là chưa có giá trị còn nếu khác -1  tức là có giá trị rồi.
// với "index" được khai báo ở trên là đại diện cho biến đầu tiên được lưu vào trong ngăn xếp  stack
// Nó sẽ khác với biến "on_top" ở trong hàm Isfull() ở đây nó đại biểu cho biên trên đầu hay phần tử cuối cùng được thêm vào ngăn xếp 
//phải phân biệt rõ 2 biến này không sẽ bị rối.

bool isEmpty()
{
    if(on_top == -1)
    {
        return true;
    }
    else
    return false;
}


//IsFull: Kiểm tra ngăn xếp đã đầy hay chưa. Thao tác này không phải lúc nào cũng có.
// để kiểm tra ngăn xếp đã đầy hay chưa ta sẽ kiểm tra xem số phần tử trong ngăn xếp có bằng hoặc lớn hơn kích thước của ngăn xếp hay không
// hay tức là ta sẽ đi kiểm tra xem phần tử trên cùng có = kích thước của ngăn xếp -1 không vì ta đếm từ vị trí số 0.

bool IsFull()
{
    if(on_top == SIZE -1)
    {
        return true;
    }
    else
    return false;
}


//push() to insert an element into the stack / hàm này dùng để thêm 1 phần tử vào vị trí trên cùng của stack.
// dùng để thêm 1 phần tử vào trong ngăn xếp muốn thêm 1 phần tử vào trong ngăn xếp ta phải xem xem stack đã đầy hay chưa bằng cách gọi hàm IsFull()
// sau khi kiểm tra là ngăn xếp chưa đầy thì 1 phần tử mới sẽ được thêm vào vị trí cao nhất của ngăn xếp vì vậy 

void push(uint8_t stack[], uint8_t value)
{
    if(IsFull()== true)
    {
        printf("stack is full ! \n");
    }
    else
    {
        stack[++on_top] = value;
    }
}




//pop() to remove an element from the stack
// hàm này dùng để xóa phần tử cuối cùng trong ngăn xếp tức là xóa vị trí on_top cao nhất 
// cách làm là ta sẽ đi xóa phần tử on_top của stack và trả lại ở vị trí top--;

void pop(uint8_t stack[], uint8_t value)
{
    if(isEmpty() == true )
    {
        printf("stack is Empty !\n");
    }
    else 
    {
    stack[on_top--] = '\0' ;    // băng NULL
    }
}


//top() Returns the top element of the stack.
// hàm này có nhiệm vụ trả về phần tử cao nhất của ngăn xếp.
uint64_t top (const uint8_t stack[], uint8_t value)
{
    return stack[on_top];
}




//size() returns the size of stack.
// hàm này trả về kích thước của ngăn xếp

uint8_t size()
{
    return on_top + 1;
}

int main(int argc, char const *argv[])
{
    uint8_t stack[SIZE];
    push(stack,8);
    push(stack,1);
    push(stack,2);
    push(stack,3);
    return 0;
}
