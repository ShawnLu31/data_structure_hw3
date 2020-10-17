#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define IS_FULL(ptr)(!(ptr))

typedef struct card_list *card_pointer;
typedef struct card_list{
    int x;
    char c;
    card_pointer next;
}card_list;

void InputCard(FILE *f, card_pointer *top);
void Write(FILE *f, card_pointer *top);
bool DrawCard(card_pointer *top, int order);
void MoveCard(card_pointer *top, bool drawn);

int main(int argc, char **argv){
    //open file
    FILE *fin, *fout;
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");    

    card_pointer top = NULL;
    InputCard(fin, &top);
    bool drawn = false;
    int order = 13;
    int stop = 0;
    while(stop != -1){
        Write(fout, &top);
        drawn = DrawCard(&top, order);
        MoveCard(&top, drawn);
        if(drawn == true){
            order--;
            drawn = false;
            if(order == 0)
                stop = -1;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

void InputCard(FILE *f, card_pointer *top){
    char ch;
    while((ch = fgetc(f)) != EOF){
        card_pointer tpstr = (card_pointer)malloc(sizeof(card_list));
        if(IS_FULL(tpstr)){
		    fprintf(stderr, "The memory is full\n");
		    exit(1);
	    }
        if(ch >= '2' && ch <= '9'){
            tpstr->x = ch - 48;
            tpstr->c = ch;
            tpstr->next = *top;
            *top = tpstr;
        }
        else if(ch == '1'){
            tpstr->x = 10;
            tpstr->c = '1';
            tpstr->next = *top;
            *top = tpstr;
        }
        else if(ch == 'A' || ch == 'J' || ch == 'Q' || ch == 'K'){
            switch(ch){
                case 'A':
                    tpstr->x = 1;
                    break;
                case 'J':
                    tpstr->x = 11;
                    break;
                case 'Q':
                    tpstr->x = 12;
                    break;
                case 'K':
                    tpstr->x = 13;
                    break;
                default:
                    break;
            }
            tpstr->c = ch;
            tpstr->next = *top;
            *top = tpstr;
        }            
    }
    card_pointer tp = *top;
    while(tp->next != NULL){
        tp = tp->next;
    }
    tp->next = *top;
    //reverse
    card_pointer pre = tp;
    card_pointer next = (*top)->next;
    card_pointer current = *top;
    do{
        current->next = pre;
        pre = current;
        current = next;
        next = next->next;
    }while(current != *top);
    *top = pre;
};
void Write(FILE *f, card_pointer *top){
    card_pointer temp = *top;
    do{
        if(temp->x == 10)
            fprintf(f, "10 ");
        else
            fprintf(f, "%c ", temp->c);
        temp = temp->next;
    }while(temp != *top);
    fprintf(f, "\n");
};
bool DrawCard(card_pointer *top, int order){
    if((*top)->x == order)
        return true;
    else
        return false;
};
void MoveCard(card_pointer *top, bool drawn){
    if(drawn == true){
        card_pointer temp = *top;
        card_pointer pre = NULL;
        for(pre = *top; pre->next != *top; pre = pre->next)
            ;
        *top = temp->next;
        pre->next = *top;
        temp->next = NULL;
        free(temp);
    }
    else{
        *top = (*top)->next;
    }
};

