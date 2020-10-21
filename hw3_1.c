#include <stdio.h>
#include <stdlib.h>
#define IS_FULL(ptr)(!(ptr))
#define IS_EMPTY(ptr)(!(ptr))

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

void Refill(stack_pointer *top, int index);
int TakePlate(stack_pointer *top);
void JoinLine(queue_pointer *front, queue_pointer *rear, int index);
int LeaveLine(queue_pointer *front);

int main(int argc, char **argv){
    //stack and queue
    stack_pointer top = NULL;
	queue_pointer frontA = NULL, rearA = NULL;
	queue_pointer frontB = NULL, rearB = NULL;

	char str[20], tp[10];
	char ch, lineX;
	int plateIndex = 0, plateTakeIndex = 0, plateOutIndex = 0;
	while((ch = getc(stdin)) != '^' && ch != EOF)
	{
		switch(ch)
		{
			case 'P':
				str[0] = ch;
				ch = getc(stdin);
				if(ch == 'U')
				{
					str[1] = ch;
					fgets(&str[2], 18, stdin);
					sscanf(str, "%s %d", tp, &plateIndex);
					Refill(&top, plateIndex);
				}
				else if(ch == 'O')
				{
					str[1] = ch;
					fgets(&str[2], 18, stdin);
					plateTakeIndex = TakePlate(&top);
				}
				break;
			case 'E':
				str[0] = ch;
				fgets(&str[1], 19, stdin);
				sscanf(str, "%s %c", tp, &lineX);
				if(lineX == 'A'){
					JoinLine(&frontA, &rearA, plateTakeIndex);
				}
				else if(lineX == 'B'){
					JoinLine(&frontB, &rearB, plateTakeIndex);
				}
				break;
			case 'D':
				str[0] = ch;
				fgets(&str[1], 19, stdin);
				sscanf(str, "%s %c", tp, &lineX);
				if(lineX == 'A'){
					plateOutIndex = LeaveLine(&frontA);
					fprintf(stdout, "%d\n\n", plateOutIndex);
				}
				else if(lineX == 'B'){
					plateOutIndex = LeaveLine(&frontB);
					fprintf(stdout, "%d\n\n", plateOutIndex);
				}
				break;
			default:
				break;
		}		

	}	
	return 0;
}

void Refill(stack_pointer *top, int index){
    stack_pointer tpstr = (stack_pointer)malloc(sizeof(stack));
	if(IS_FULL(tpstr)){
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	tpstr->plateIndex = index;
    tpstr->next = *top;
    *top = tpstr;
	return;	
};
int TakePlate(stack_pointer *top){
	int index = 0;
	stack_pointer tpstr = *top;
    if(IS_EMPTY(tpstr)){
         fprintf(stderr, "The stack is empty\n");
         exit(1);
    }
    index = tpstr->plateIndex;
    *top = tpstr->next;
    free(tpstr);
	return index;
};
void JoinLine(queue_pointer *front, queue_pointer *rear, int index){
    queue_pointer tpstr = (queue_pointer)malloc(sizeof(queue));
	if(IS_FULL(tpstr)){
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
    tpstr->plateIndex = index;
    tpstr->next = NULL;
    if(*front){
        (*rear)->next = tpstr;
    }
    else{
        *front = tpstr;
    }
    *rear = tpstr;
	return;
};
int LeaveLine(queue_pointer *front){
	int plate = 0;
    queue_pointer tpstr = *front;
    if(IS_EMPTY(tpstr)){
         fprintf(stderr, "The stack is empty\n");
         exit(1);
    }
    plate = tpstr->plateIndex;
    *front = tpstr->next;
    free(tpstr);
	return plate;
};
