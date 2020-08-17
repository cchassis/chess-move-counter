#include <stdio.h>
#include <stdlib.h>

int WhiteKnightMoves;
char ChessBoard[12][12];
char ChessB[8][8] = {
{ ' ', ' ', 'k', 'r', ' ', 'b', 'n', 'r' },
{ 's', 's', 's', 'q', 's', 's', 's', 's' },
{ ' ', ' ', 'n', 's', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', 'B', ' ', 'S', ' ', 'b', ' ' },
{ ' ', ' ', 'N', ' ', ' ', 'N', ' ', ' ' },
{ 'S', 'S', 'S', 'S', ' ', 'S', 'S', 'S' },
{ 'R', ' ', 'B', 'Q', ' ', 'R', 'K', ' ' }};


WhiteKnight(char x[12][12]){
    int i, j;
    for (i=0; i<12; i++){
        for (j=0; j<12; j++){
            if (x[i][j]=='N'){
                if (x[i-2][j+1]==' '||x[i-2][j+1]=='s'||x[i-2][j+1]=='r'||x[i-2][j+1]=='n'||x[i-2][j+1]=='b'||x[i-2][j+1]=='q'||x[i-2][j+1]=='k'){WhiteKnightMoves+=1;}
                if (x[i-1][j+2]==' '||x[i-1][j+2]=='s'||x[i-1][j+2]=='r'||x[i-1][j+2]=='n'||x[i-1][j+2]=='b'||x[i-1][j+2]=='q'||x[i-1][j+2]=='k'){WhiteKnightMoves+=1;}
                if (x[i+1][j+2]==' '||x[i+1][j+2]=='s'||x[i+1][j+2]=='r'||x[i+1][j+2]=='n'||x[i+1][j+2]=='b'||x[i+1][j+2]=='q'||x[i+1][j+2]=='k'){WhiteKnightMoves+=1;}
                if (x[i+2][j+1]==' '||x[i+2][j+1]=='s'||x[i+2][j+1]=='r'||x[i+2][j+1]=='n'||x[i+2][j+1]=='b'||x[i+2][j+1]=='q'||x[i+2][j+1]=='k'){WhiteKnightMoves+=1;}
                if (x[i+2][j-1]==' '||x[i-2][j+1]=='s'||x[i-2][j+1]=='r'||x[i-2][j+1]=='n'||x[i-2][j+1]=='b'||x[i-2][j+1]=='q'||x[i-2][j+1]=='k'){WhiteKnightMoves+=1;}
                if (x[i+1][j-2]==' '||x[i+1][j-2]=='s'||x[i+1][j-2]=='r'||x[i+1][j-2]=='n'||x[i+1][j-2]=='b'||x[i+1][j-2]=='q'||x[i+1][j-2]=='k'){WhiteKnightMoves+=1;}
                if (x[i-1][j-2]==' '||x[i-1][j-2]=='s'||x[i-1][j-2]=='r'||x[i-1][j-2]=='n'||x[i-1][j-2]=='b'||x[i-1][j-2]=='q'||x[i-1][j-2]=='k'){WhiteKnightMoves+=1;}
                if (x[i-2][j-1]==' '||x[i-2][j-1]=='s'||x[i-2][j-1]=='r'||x[i-2][j-1]=='n'||x[i-2][j-1]=='b'||x[i-2][j-1]=='q'||x[i-2][j-1]=='k'){WhiteKnightMoves+=1;}
            }
        }
    }
}

int main(int argc, char *argv[]) {
    f(ChessB); 					  //Convert to 12x12 for evaluation//
    WhiteKnight(ChessBoard);     //Function to calculate Knight moves//
    PrintChessBoard(ChessB);      //Print the original 8x8 board//
    getch();
    return 0;
}

int f (char board[8][8]){
//Convert 8x8 board to 12x12, with the extra rows and collumns being 'x'//
    int i, j;
    for (i=0;i<12;i++){
        for (j=0;j<12;j++){
            if (i<2 || j<2 || i>9 || j>9){ChessBoard[i][j]='x';}
            else {ChessBoard[i][j] = board[i-2][j-2];}
        }
    }
//Easier to check in later functions of other pawns//
}

int PrintChessBoard(char ChessBoard[8][8]){
//Better visualisation and easier bugfixing//
    int i, j;
    printf ("\n\n\n\n\t---------------------------------\n");
    for (i=0; i<8; i++){
    printf ("\t| ");
        for (j=0; j<8; j++){
            printf ("%c | ", ChessB[i][j]);
            if (i==3 && j==7){printf("\t Total Possible White "); break;}
            if (i==4 && j==7){printf("\t  Knight Moves : %d", WhiteKnightMoves); break;}
        }
    printf("\n"); printf ("\t---------------------------------\n");
    }
printf("\n\n\n");
}
