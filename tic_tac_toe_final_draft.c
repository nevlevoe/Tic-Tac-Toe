#include <stdio.h>
void main(){
    char board[3][3];
    int row,column,row_1,column_1,i,j,k,l,y,z,v,r,s,iteration=0,winner=1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j]=' ';
        }
    }
    while(winner==1){
        int counter=0;
        printf("Input row: ");
        if (scanf("%d", &row_1) != 1) {
            printf("Invalid input for row. Please enter a valid number.\n");
            // Clear the input buffer to avoid issues with subsequent inputs
            while (getchar() != '\n');
            continue;  // Go back to the beginning of the loop
        }

        printf("Input column: ");
        if (scanf("%d", &column_1) != 1) {
            printf("Invalid input for column. Please enter a valid number.\n");
            // Clear the input buffer to avoid issues with subsequent inputs
            while (getchar() != '\n');
            continue;  // Go back to the beginning of the loop
        }
        if(row_1 > 3 || column_1 > 3|| row_1 < 1|| column_1 < 1){
            printf("The number of rows or columns is exceeding or lesser than the board \n");
            printf("Enter the number between one and three only \n");
        }
        else{
            row=row_1-1;
            column=column_1-1;

            if(board[row][column]!='X' && board[row][column]!='O'){
                if(iteration%2!=0){
                    board[row][column]='X';
                    iteration++;
                }
                else{
                    board[row][column]='O';
                    iteration++;
                }
            }
            else{
                printf("The position has already been entered! Please try another position\n");
            }
            printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
            printf("\n");
            // win condition for row
            for(k=0;k<3;k++){
                if((board[k][0]=='X' && board[k][1]=='X' && board[k][2]=='X')||(board[k][0]=='O' && board[k][1]=='O' && board[k][2]=='O')){
                    printf(" Player %c  wins!", board[k][0]);
                    winner=0;
                }
            }
            // win condition for column
            for(l=0;l<3;l++){
                if ((board[0][l]=='X' && board[1][l]=='X' && board[2][l]=='X')||(board[0][l]=='O' && board[1][l]=='O' && board[2][l]=='O')){
                    printf(" Player %c  wins!", board[0][l]);
                    winner=0;
                }
            }
            // win condition for diagonal
            for (y = 0; y < 3; y++) {
                for (z = 0; z < 3; z++) {
                    if(y==z){
                        if ((board[y][y]=='X' && board[y+1][y+1]=='X' && board[y+2][y+2]=='X')||(board[y][y]=='O' && board[y+1][y+1]=='O' && board[y+2][y+2]=='O')){
                            printf(" Player %c  wins!", board[0][0]);
                            winner=0;
                        }
                    else if(y+z==2 && v==0){
                        if ((board[v][2-v]=='X' && board[v+1][1-v]=='X' && board[v+2][-v]=='X')||(board[v][2-v]=='O' && board[v+1][1-v]=='O' && board[v+2][-v]=='O')){
                            printf(" Player %c  wins!", board[0][2]);
                            winner=0;
                        }
                    }
                    }
                }
            }
            //end of the game check
            for(r=0;r<3;r++){
                for(s=0;s<3;s++){
                    if(board[r][s]!=' '){
                        counter+=1;
                    }
                }
            }
            if(counter==9){
                printf(" It's a Draw!");
                winner=0;
            }

        }

    }

}
