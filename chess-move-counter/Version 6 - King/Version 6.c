#include <stdio.h>
#include <stdlib.h>

int WhiteKingMoves;
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

WhiteKing(char x[12][12]){
    int i, j;
    for (i=0; i<12; i++){
        for (j=0; j<12; j++){
            if (x[i][j]=='K'){
                int k, l;
                //Up//
                if (ChessBoard[i- 1][j]==' '){WhiteKingMoves+=1;}
                if (ChessBoard[i-1][j]=='s'||ChessBoard[i-1][j]=='r'||ChessBoard[i-1][j]=='b'||ChessBoard[i-1][j]=='n'||ChessBoard[i-1][j]=='q'||ChessBoard[i-1][j]=='k'){WhiteKingMoves+=1;}
                //UpRight//
                if (x[i- 1][j+1]==' '){WhiteKingMoves+=1;}
                if (x[i-1][j+1]=='s'||x[i-1][j+1]=='r'||x[i-1][j+1]=='n'||x[i-1][j+1]=='b'||x[i-1][j+1]=='q'||ChessBoard[i-1][j+1]=='k' ){WhiteKingMoves+=1;}
                //Right//
                if (ChessBoard[i][j+1]==' '){WhiteKingMoves+=1;}
                if (ChessBoard[i][j+1]=='s'||ChessBoard[i][j+1]=='r'||ChessBoard[i][j+1]=='b'||ChessBoard[i][j+1]=='n'||ChessBoard[i][j+1]=='q'||ChessBoard[i][j+1]=='k'){WhiteKingMoves+=1;}
                // DownRight//
                if (x[i+1][j+1]==' '){WhiteKingMoves+=1;}
                if (x[i+1][j+1]=='s'||x[i+1][j+1]=='r'||x[i+1][j+1]=='n'||x[i+1][j+1]=='b'||x[i+1][j+1]=='q'||ChessBoard[i+1][j+1]=='k' ){WhiteKingMoves+=1;}
                //Down//
                if (ChessBoard[i+1][j]==' '){WhiteKingMoves+=1;}
                if (ChessBoard[i+1][j]=='s'||ChessBoard[i+1][j]=='r'||ChessBoard[i+1][j]=='b'||ChessBoard[i+1][j]=='n'||ChessBoard[i+1][j]=='q'||ChessBoard[i+1][j]=='k'){WhiteKingMoves+=1;}
                //DownLeft//
                if (x[i+1][j- 1]==' '){WhiteKingMoves+=1;}
                if (x[i+1][j-1]=='s'||x[i+1][j-1]=='r'||x[i+1][j-1]=='n'||x[i+1][j-1]=='b'||x[i+1][j-1]=='q'||ChessBoard[i+1][j-1]=='k' ){WhiteKingMoves+=1;}
                //Left//
                if (ChessBoard[i][j- 1]==' '){WhiteKingMoves+=1;}
                if (ChessBoard[i][j-1]=='s'||ChessBoard[i][j-1]=='r'||ChessBoard[i][j-1]=='b'||ChessBoard[i][j-1]=='n'||ChessBoard[i][j-1]=='q'||ChessBoard[i][j-1]=='k'){WhiteKingMoves+=1;}
                //UpLeft//
                if (x[i- 1][j- 1]==' '){WhiteKingMoves+=1;}
                if (x[i-1][j-1]=='s'||x[i-1][j-1]=='r'||x[i-1][j-1]=='n'||x[i-1][j-1]=='b'||x[i-1][j-1]=='q'||ChessBoard[i-1][j-1]=='k' ){WhiteKingMoves+=1;}
            }
        }
    }
}

int main(int argc, char *argv[]) {
    f(ChessB); 					  //Convert to 12x12 for evaluation//
    WhiteKing(ChessBoard);
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
            if (i==4 && j==7){printf("\t   King Moves : %d", WhiteKingMoves); break;}
        }
    printf("\n"); printf ("\t---------------------------------\n");
    }
printf("\n\n\n");
}
