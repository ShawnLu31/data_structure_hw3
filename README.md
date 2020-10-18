##### F74086072 資訊系 呂文翔
# HW3_1
## Program design:
   * struct
   for linked lists
 ```c
  typedef struct stack *stack_pointer;
  typedef struct stack{
    int plateIndex;
    stack_pointer next;
  }stack;
  
  typedef struct queue *queue_pointer;
  typedef struct queue{
    int plateIndex;
    queue_pointer next;
  }queue;
 ```
   * Variable:
      - int plateIndex – 存取要放入plateStack的plate index.
      - int plateTakeIndex - 存取從plateStack拿取的plate index.
      - int plateOutIndex - 存取從line離開的plate index.
  #### The stack of plate:
      - stack_pointer top – 存取目前plateStack最末(高)的盤子的位置。
  #### Two lines in the cafeteria:
      - stack_pointer frontA, rearA – 存取lineA隊伍的首、末位。
      - stack_pointer frontB, rearB - 存取lineB隊伍的首、末位。
   * Function:
      1. Refill:
         將輸入指令(PUSH N)傳入的plate index N放到plateStack的最末(高)位。
      2.	TakePlate:
         輸入指令(POP)，將plateStack的最末(高)位的盤子移出，變更top指的位置。
      3.	JoinLine:
         輸入指令(ENQUEUE X)，將取出的盤子index放到line X的最末端。
      4.	LeaveLine:
         輸入指令(DEQUEUE X) 將line X的最前端的盤子index移出line X，並將所有其他盤子向前移一格。
## Result screenshot:
![image](https://github.com/ShawnLu31/data_structure_hw3/blob/main/hw3_1.PNG)
## Program functions:
   1. void Refill(stack_pointer *top, int index)
      Refill a plate index N into plate stack. 
      * Parameters
         - *top – This is pointer of the pointer of the top of the plate stack.
         - index – This is the plate index ‘N’.
   2. int TakePlate(stack_pointer *top)
      The customer takes a plate from the top of the plate stack.
      * Parameters
         - *top – This is pointer of the pointer of the top of the plate stack.
      * Return value
         - Return the index of the top of the plate stack.
   3. void JoinLine(queue_pointer *front, queue_pointer *rear, int index)
      The customer joins the end of the line X.
      * Parameters
         - *front – This is the pointer of the pointer of the front of the line X.
         - *rear - This is the pointer of the pointer of the rear of the line X.
         - plate – This is the index of the customer’s plate.
   4. int LeaveLine(queue_pointer *front)
      The customer at the front of the line X leaves the line.
      * Parameters 
         - *front – This is the pointer of the pointer of the front of the line X.
      * Return value
         - Return th index of the leaving customer’s plate.
## Program architecture:
#### 流程圖:
![image](https://github.com/ShawnLu31/data_structure_hw3/blob/main/Untitled%20Diagram.png)

# HW_2
## Program design:
## Result screenshot:
## Program functions:
## Program architecture:
#### 流程圖:
