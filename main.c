#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int hp = 3;
char board[5][5];
int pos[2];


void movement(){
    char input = ' ';

    board[pos[0]][pos[1]] = '_';

    printf("\ninput : ");
    scanf("%c", &input);

    switch (input)
    {
    case 'w':
        if (pos[0] == 0){
            pos[0] = 4;
        }
        else
        {
        pos[0] -=1;
        }
        break;
    case 's':
        if (pos[0] == 4){
            pos[0] = 0;
        }
        else
        {
        pos[0] +=1;
        }
        break;
    case 'a':
        if (pos[1] == 0){
            pos[1] = 4;
        }
        else
        {
        pos[1] -=1;
        }
        break;
    case 'd':
        if (pos[1] == 4){
            pos[1] = 0;
        }
        else
        {
        pos[1] +=1;
        }
        break;
    default:
        printf("\nno\n");
        printf("%d %d\n", pos[0], pos[1] );
        printf("%c", input);
    }
    
    board[pos[0]][pos[1]] = 'P';
}

void printBoard(){
    for (int i =0; i <5; i++){
        for(int j = 0; j<5; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void setBoard()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = '_';
        }
    }
    //player
    pos[1] = 0;
    pos[0] = 0;
    board[0][0] = 'P';

    //end
    board[2][2] = 'e';
}

int main(){
    
    setBoard();
    
    do
    {
        printBoard();
        movement();
        
    } while (pos[1] != 2 || pos[0] != 2);
    


    return 0;
}
