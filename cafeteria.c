#include <stdio.h>
#include <stdlib.h>
#define PLATE_MAX_SIZE 1000
#define LINE_MAX_SIZE 1000

void Refill(int stack[], int index, int *top);
int TakePlate(int stack[], int *top);
void JoinLine(int line[], int plate, int *front, int *rear);
int LeaveLine(int line[], int *front, int *rear);

int main(int argc, char **argv){
	int plateStack[PLATE_MAX_SIZE];
	int lineA[LINE_MAX_SIZE], lineB[LINE_MAX_SIZE];
	FILE *fin, *fout;
	//open file
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	char str[20], tp[10];
	char ch, lineX;
	int plateIndex = 0, plateOutIndex = 0;
	int top = -1;//top for plateStack
	int frontA = -2, rearA = -1;//for lineA
	int frontB = -2, rearB = -1;//for lineB
	while((ch = fgetc(fin)) != '^' && ch != EOF)
	{
		switch(ch)
		{
			case 'P':
				str[0] = ch;
				ch = fgetc(fin);
				if(ch == 'U')
				{
					str[1] = ch;
					fgets(&str[2], 18, fin);
					sscanf(str, "%s %d", tp, &plateIndex);
					Refill(plateStack, plateIndex, &top);
				}
				else if(ch == 'O')
				{
					str[1] = ch;
					fgets(&str[2], 18, fin);
					plateIndex = TakePlate(plateStack, &top);
				}
				break;
			case 'E':
				str[0] = ch;
				fgets(&str[1], 19, fin);
				sscanf(str, "%s %c", tp, &lineX);
				if(lineX == 'A'){
					JoinLine(lineA, plateIndex, &frontA, &rearA);
				}
				else if(lineX == 'B'){
					JoinLine(lineB, plateIndex, &frontB, &rearB);
				}
				break;
			case 'D':
				str[0] = ch;
				fgets(&str[1], 19, fin);
				sscanf(str, "%s %c", tp, &lineX);
				if(lineX == 'A'){
					plateOutIndex = LeaveLine(lineA, &frontA, &rearA);
					fprintf(fout, "%d\n\n", plateOutIndex);
				}
				else if(lineX == 'B'){
					plateOutIndex = LeaveLine(lineB, &frontB, &rearB);
					fprintf(fout, "%d\n\n", plateOutIndex);
				}
				break;
			default:
				break;
		}		

	}	
	fclose(fin);
	fclose(fout);
	return 0;
}

void Refill(int stack[], int index, int *top){
	if(*top >= PLATE_MAX_SIZE){
		printf("There are too much plates!");
		return;
	}
	stack[++*top] = index;
	return;	
};
int TakePlate(int stack[], int *top){
	int index = 0;
	if(*top < 0)
	{
		printf("No plate can be taken.");
		return 0;	
	}
	else
	{
		index = stack[*top];
		*top -= 1;
	}
	return index;
};
void JoinLine(int line[], int plate, int *front, int *rear){
	if(*rear >= LINE_MAX_SIZE)
	{
		printf("There is too much people in the line.");
		return;
	}
	line[++*rear] = plate;
	if(*front < 0)
		*front += 1;
	return;
};
int LeaveLine(int line[], int *front, int *rear){
	int plate = 0;
	if(*front < 0 && *rear < 0){
		printf("No one is in line now.");
	}
	else if(*front < 0 && *rear == 0){
		plate = line[*rear];
		line[*rear] = 0;
		*front -= 1;
		*rear -= 1;
	}
	else{
		plate = line[*front];
		for(int i = *front; i < *rear; i++)
		{
			line[i] = line[i+1];
		}
		line[*rear] = 0;
		*rear -= 1;
		if(*rear <= 0)
			*front -= 1;
	}
	return plate;
};
