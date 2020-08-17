#include <stdio.h>
#include <stdlib.h>

int WhiteBishopMoves;
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

WhiteBishop(char x[12][12]){
    int i, j;
    for (i=0; i<12; i++){
        for (j=0; j<12; j++){
            if (x[i][j]=='B'){
                int k, l;
                //UpRight//
                for (k=i-1,l=j+1; k>0,l>0; k--,l++){
                    if (x[k][l]==' '){WhiteBishopMoves+=1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||ChessBoard[k][l]=='k'){WhiteBishopMoves+=1; break;}
                    else{break;}
                    }
                //DownRight//
                for (k=i+1,l=j+1; k>0,l>0; k++,l++){
                    if (x[k][l]==' '){WhiteBishopMoves += 1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||ChessBoard[k][l]=='k'){WhiteBishopMoves+=1; break;}
                    else{break;}
                }
                //DownLeft//
                for (k=i+1,l=j-1; k>0,l>0; k++,l--){
                    if (x[k][l]==' '){WhiteBishopMoves+=1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||ChessBoard[k][l]=='k'){WhiteBishopMoves+=1; break;}
                    else{break;}
                }
                //UpLeft//
                for (k=i-1,l=j-1; k>0,l>0; k--,l--){
                    if (x[k][l]==' '){WhiteBishopMoves+=1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||ChessBoard[k][l]=='k'){WhiteBishopMoves+=1; break;}
                    else{break;}
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    f(ChessB); 					  //Convert to 12x12 for evaluation//
    WhiteBishop(ChessBoard);     //Function to calculate Bishop moves//
    PrintChessBoard(ChessB);      //Print the original 8x8 board//
    getch();
    return 0;
}

int f (char board[8][8]){
//Convert 8x8 board to 12x12, with the extra rows and collumns being 'x'//
    int i, j;
    for (i=0;i<12;i++){
        for (j=0;j<12;j++){
            if (i<2 || j<2 || i>9 || j>9){ChessBoard[i][j] = 'x';}
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
            if (i==4 && j==7){printf("\t  Bishop Moves : %d", WhiteBishopMoves); break;}
        }
    printf("\n"); printf ("\t---------------------------------\n");
    }
printf("\n\n\n");
}
