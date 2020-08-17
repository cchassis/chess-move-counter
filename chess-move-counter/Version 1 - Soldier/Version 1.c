#include <stdio.h>
#include <stdlib.h>

int WhiteSoldierMoves;
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

WhiteSoldier(char board[12][12]){
    int i, j;
    for (i=0; i<12; i++){
        for (j=0; j<12; j++){
            if (ChessBoard[i][j]=='S'){
				//Single Forward Move//
                if ( ChessBoard[i-1][j]==' ' ){WhiteSoldierMoves+=1;}
				//Diagonal Single Elimination//
                if (ChessBoard[i-1][j+1]=='s'||ChessBoard[i-1][j+1]=='r'||ChessBoard[i-1][j+1]=='n'||ChessBoard[i-1][j+1]=='b'||ChessBoard[i-1][j+1]=='q'||ChessBoard[i-1][j+1]=='k' ){WhiteSoldierMoves+=1;}
                if (ChessBoard[i-1][j-1]=='s'||ChessBoard[i-1][j-1]=='r'||ChessBoard[i-1][j-1]=='n'||ChessBoard[i-1][j-1]=='b'||ChessBoard[i-1][j-1]=='q'||ChessBoard[i-1][j-1]=='k' ){WhiteSoldierMoves+=1;}
                //Double Forward Move//
                if ( i==8 && ChessBoard[i-1][j]==' ' && ChessBoard[i-2][j]==' '){WhiteSoldierMoves+=1;}
            }
        }
    }
}

int main(int argc, char *argv[]) {
    f(ChessB); 					  //Convert to 12x12 for evaluation//
    WhiteSoldier(ChessBoard);     //Function to calculate Soldier moves//
    PrintChessBoard(ChessB);      //Print the original 8x8 board//
    getch();
    return 0;
}

int f (char board[8][8]){
//Convert 8x8 board to 12x12, with the extra rows and collumns being 'x'//
    int i, j, WhiteSoldierMoves;
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
            if (i==4 && j==7){printf("\t  Soldier Moves : %d", WhiteSoldierMoves); break;}
        }
    printf("\n"); printf ("\t---------------------------------\n");
    }
printf("\n\n\n");
}
