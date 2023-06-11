#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 5


typedef struct 
{
    int8_t rear;
    int8_t front;
    uint8_t array[SIZE];
    uint8_t max_size;
}queue;



// queue Init() : this operation create the element
// khởi tạo các thành phần trong hàng chờ đợi
void queueInit(queue *queue)
{
    queue->rear = -1;
    queue->front = -1;
   // queue->max_size = max_size;
}


//enqueue(): Inserts an element at the end of the queue i.e. at the rear end.
// thêm 1 phần tử vào cuối (rear) của queue
void enqueue(queue *queue, uint8_t value)
{
    queue->array[++(queue->front)] = value;
}


//dequeue(): This operation removes and returns an element that is at the front end of the queue.
// cách hoạt  đọng này loại bỏ và trả về 1 phần tử ở cuối hàng đợi của queue
/* hàm này sẽ lấy ra 1 phần tử đầu tiên trong hàng chờ và dich các phần tử trong hàng chờ lên 1 đơn vị
- để lấy phần tử đầu tiên trong mảng phải xem hàng chơ có trống hay không-> nếu trông báo hàng chờ trống
nếu không trống báo thì sẽ lấy thành phần đầu tiên trong hàng chờ tức front và tăng các member lên 1 
*/


 uint8_t dequeue(queue *queue, uint8_t value)
{
    if((queue->front == -1) || (queue->front > queue->rear))
    {
        printf("hàng chờ trống!");
    }
    else
    value = queue->array[queue->front];               // trả về giá trị đầu tiên trong hàng chờ đợi
    queue->front++;
    return value;
}



//front(): This operation returns the element at the front end without removing it.
// cách hoạt động  này trả về phần tử ở phía trước không loại bỏ nó
/*hàm dùng để truy xuất giá trị đầu tiên trong hàng chờ đợi nhưng không xóa nó khỏi hàn chờ đợi*/
// tức là giống với hàm dequeue là truy xuất giá trị của front nhưng khác là sẽ không xóa nó khỏi hàng chờ
uint8_t Front(queue *queue)
{
    if (queue->front == -1 || queue->front > queue->rear) // xác định xem hàng chờ có trống hay không
    {
        printf("hàng chờ trống!\n");           // trả về giá trị 0 nếu hàng chờ trống
        return 0;
    }
    else
    {
        return queue->array[queue->front];  // trả về giá trị front
    }
}




//rear(): This operation returns the element at the rear end without removing it.
//cách hoạt động này trả về phần tử ở phía sau không loại bỏ nó






//isEmpty(): This operation indicates whether the queue is empty or not.
//thao tác này cho biết hàng chờ đợi có trống hay không
/* để kiểm tra xem hàng đợi có trông không ta kiểm tra
- ta kiểm tra xem chỉ số front và rear có bằng nhau hay không -> nếu trùng nhau thì tức là hàng chờ không có phần tử nào cả.
*/


bool isEmpty(queue *queue)
{
    if((queue->front == -1) || (queue->front > queue->rear))

     // kiểm tra xem front có bằng -1 không nếu = -1 tức là trống
     //trường hợp còn lại kiểm tra xem front có lơn hơn rear không nếu có tức là con trỏ đã trỏ ra ngoài hàng chờ
          
    {
        return true;
    }
    else
    {
         return false;
    }
   
}




//isFull(): This operation indicates whether the queue is full or not.
// thao tác này cho biết hàng chờ đợi đã đầy hay chưa
/*hàm kiểm tra xem hàng chờ đã full hay chưa 
-nếu hàng chờ đầy số phần tử bằng số kích thước tối đa của hàng đợi  -> trả về 1
- nếu chưa trả về 0*
để tính kích thước của hàng chờ đợi phải biết số lương phần tử của hàng chờ đợi 
lấy rear - front + 1*/


bool isFull(queue *q)
{
    return ((q->rear + 1) % q->max_size == q->front);             
}




//size(): This operation returns the size of the queue i.e. the total number of elements it contains
// thao tác này trả về kích thước của hàng đợi, tức là tổng số phần tử nó chứa


uint8_t size(queue *queue)
{

    if (queue->front == -1)
    {
        return 0;
    }
    else
    {
        return (queue->rear - queue->front + 1);
    }
}
int main(int argc, char const *argv[])
{
    
    return 0;
}

