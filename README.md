##### F74086072 資訊系 呂文翔
#HW3_1

## Program design:
  * Variable:
    - int plateIndex – 存取從plateStack拿取的plate index.
    - int plateOutIndex - 存取從line離開的plate index.
The stack of plate:
	int plateStack[] – 放盤子的index的陣列。
	int top – 存取目前plateStack最末(高)的盤子的位置。
Two lines in the cafeteria:
	int lineA[], lineB[] – 代表A、B兩支取餐隊伍，存盤子的index。
	int frontA, rearA – 存取lineA隊伍的首、末位。
	int frontB, rearB - 存取lineB隊伍的首、末位。
	Function:
1.	Refill:
將輸入指令(PUSH N)傳入的plate index N放到plateStack的最末(高)位。
2.	TakePlate:
輸入指令(POP)，將plateStack的最末(高)位的盤子移出，變更top指的位置。
3.	JoinLine:
輸入指令(ENQUEUE X)，將取出的盤子index放到line X的最末端。
4.	LeaveLine:
輸入指令(DEQUEUE X) 將line X的最前端的盤子index移出line X，並將所有其他盤子向前移一格。
## Result screenshot:

## Program functions:
1.	void Refill(int stack[], int index, int *top)
Refill a plate index N into plate stack. 
Parameters
	stack[] – This is the array of the plate stack.
	index – This is the plate index ‘N’.
	*top – This is pointer of the top of the plate stack.
2.	int TakePlate(int stack[], int *top)
The customer takes a plate from the top of the plate stack.
Parameters
	stack[] – This is the plate stack.
	*top – This is pointer of the top of the plate stack.
Return value
	Return the index of the top of the plate stack.
3.	void JoinLine(int line[], int plate, int *front, int *rear)
The customer joins the end of the line X.
Parameters
	line[] – This is the array of line X.
	plate – This is the index of the customer’s plate.
	*front – This is the pointer of the front of the line X.
	*rear - This is the pointer of the rear of the line X.
4.	int LeaveLine(int line[], int *front, int *rear)
The customer at the front of the line X leaves the line.
Parameters 
	line[] – This is the array of line X.
	*front – This is the pointer of the front of the line X.
	*rear - This is the pointer of the rear of the line X.
Return value
	Return th index of the leaving customer’s plate.

## Program architecture:
##### 流程圖:

