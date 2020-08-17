#include <stdio.h>
#include <stdlib.h>

int WhiteSoldierMoves, WhiteBishopMoves, WhiteKnightMoves, WhiteRookMoves, WhiteQueenMoves, WhiteKingMoves;
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

int main(int argc, char *argv[]) {
    f(ChessB);
    WhiteSoldier(ChessBoard); WhiteRook(ChessBoard); WhiteKnight(ChessBoard); WhiteBishop(ChessBoard); WhiteQueen(ChessBoard); WhiteKing(ChessBoard);
    PrintChessBoard(ChessB);
    getch();
    return 0;
}

int f (char x[8][8]){
    int i, j;
    for (i=0;i<12;i++){ for (j=0;j<12;j++){
            if (i<2 || j<2 || i>9 || j>9){ChessBoard[i][j] = 'x';}
            else {ChessBoard[i][j] = x[i-2][j-2];}}}}

int PrintChessBoard(char x[8][8]){
    int i, j;
    printf ("\n\n\n\n\t---------------------------------\n");
    for (i=0; i<8; i++){
    printf ("\t| ");
        for (j=0; j<8; j++){
            printf ("%c | ", x[i][j]);
            if (i==1 && j==7){printf("\t  Soldier Moves :  %d", WhiteSoldierMoves); break;}
            if (i==2 && j==7){printf("\t  Rook Moves    :  %d", WhiteRookMoves); break;}
            if (i==3 && j==7){printf("\t  Knight Moves  :  %d", WhiteKnightMoves); break;}
            if (i==4 && j==7){printf("\t  Bishop Moves  :  %d", WhiteBishopMoves); break;}
            if (i==5 && j==7){printf("\t  Queen Moves   :  %d", WhiteQueenMoves); break;}
            if (i==6 && j==7){printf("\t  King Moves    :  %d", WhiteKingMoves); break;}
        }
    printf("\n"); printf ("\t---------------------------------\n");
    }
printf("\n\n\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Version 1 - Soldier//
WhiteSoldier(char x[12][12]){
    int i, j;
    for (i=0;i<12;i++){ for (j=0;j<12;j++){ if (x[i][j]=='S'){
                if ( x[i-1][j]==' ' ){WhiteSoldierMoves+=1;}
                if (x[i-1][j+1]=='s'||x[i-1][j+1]=='r'||x[i-1][j+1]=='n'||x[i-1][j+1]=='b'||x[i-1][j+1]=='q'||x[i-1][j+1]=='k' ){WhiteSoldierMoves+=1;}
                if (x[i-1][j-1]=='s'||x[i-1][j-1]=='r'||x[i-1][j-1]=='n'||x[i-1][j-1]=='b'||x[i-1][j-1]=='q'||x[i-1][j-1]=='k' ){WhiteSoldierMoves+=1;}
                if ( i==8 && x[i-1][j]==' ' && x[i-2][j]==' '){WhiteSoldierMoves+=1;}}}}}
                
//Version 2 - Knight//
WhiteKnight(char x[12][12]){
    int i, j;
    for (i=0;i<12;i++){ for (j=0;j<12;j++){ if (x[i][j]=='N'){
                if (x[i-2][j+1]==' '||x[i-2][j+1]=='s'||x[i-2][j+1]=='r'||x[i-2][j+1]=='n'||x[i-2][j+1]=='b'||x[i-2][j+1]=='q'||x[i-2][j+1]=='k'){WhiteKnightMoves+=1;}
                if (x[i-1][j+2]==' '||x[i-1][j+2]=='s'||x[i-1][j+2]=='r'||x[i-1][j+2]=='n'||x[i-1][j+2]=='b'||x[i-1][j+2]=='q'||x[i-1][j+2]=='k'){WhiteKnightMoves+=1;}
                if (x[i+1][j+2]==' '||x[i+1][j+2]=='s'||x[i+1][j+2]=='r'||x[i+1][j+2]=='n'||x[i+1][j+2]=='b'||x[i+1][j+2]=='q'||x[i+1][j+2]=='k'){WhiteKnightMoves+=1;}
                if (x[i+2][j+1]==' '||x[i+2][j+1]=='s'||x[i+2][j+1]=='r'||x[i+2][j+1]=='n'||x[i+2][j+1]=='b'||x[i+2][j+1]=='q'||x[i+2][j+1]=='k'){WhiteKnightMoves+=1;}
                if (x[i+2][j-1]==' '||x[i-2][j+1]=='s'||x[i-2][j+1]=='r'||x[i-2][j+1]=='n'||x[i-2][j+1]=='b'||x[i-2][j+1]=='q'||x[i-2][j+1]=='k'){WhiteKnightMoves+=1;}
                if (x[i+1][j-2]==' '||x[i+1][j-2]=='s'||x[i+1][j-2]=='r'||x[i+1][j-2]=='n'||x[i+1][j-2]=='b'||x[i+1][j-2]=='q'||x[i+1][j-2]=='k'){WhiteKnightMoves+=1;}
                if (x[i-1][j-2]==' '||x[i-1][j-2]=='s'||x[i-1][j-2]=='r'||x[i-1][j-2]=='n'||x[i-1][j-2]=='b'||x[i-1][j-2]=='q'||x[i-1][j-2]=='k'){WhiteKnightMoves+=1;}
                if (x[i-2][j-1]==' '||x[i-2][j-1]=='s'||x[i-2][j-1]=='r'||x[i-2][j-1]=='n'||x[i-2][j-1]=='b'||x[i-2][j-1]=='q'||x[i-2][j-1]=='k'){WhiteKnightMoves+=1;}}}}}

//Version 3 - Bishop//
WhiteBishop(char x[12][12]){
    int i, j, k, l;
    for (i=0;i<12;i++){ for (j=0;j<12;j++){ if (x[i][j]=='B'){
                for (k=i-1,l=j+1; k>0,l>0; k--,l++){
                    if (x[k][l]==' '){WhiteBishopMoves+=1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||x[k][l]=='k'){WhiteBishopMoves+=1; break;}
                    else{break;}}
                for (k=i+1,l=j+1; k>0,l>0; k++,l++){
                    if (x[k][l]==' '){WhiteBishopMoves += 1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||x[k][l]=='k'){WhiteBishopMoves+=1; break;}
                    else{break;}}
                for (k=i+1,l=j-1; k>0,l>0; k++,l--){
                    if (x[k][l]==' '){WhiteBishopMoves+=1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||x[k][l]=='k'){WhiteBishopMoves+=1; break;}
                    else{break;}}
                for (k=i-1,l=j-1; k>0,l>0; k--,l--){
                    if (x[k][l]==' '){WhiteBishopMoves+=1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||x[k][l]=='k'){WhiteBishopMoves+=1; break;}
                    else{break;}}}}}}

//Version 4 - Rook//
WhiteRook(char x[12][12]){
    int i, j, y;
    for (i=0;i<12;i++){ for (j=0;j<12;j++){ if (x[i][j]=='R'){
                for (y=i-1; y>0; y--){
                    if (x[y][j]==' '){WhiteRookMoves+=1; continue;}
                    if (x[y][j]=='s'||x[y][j]=='r'||x[y][j]=='b'||x[y][j]=='n'||x[y][j]=='q'||x[y][j]=='k'){WhiteRookMoves+=1; break;}
                    else{break;}}
                for (y=j+1; y>0; y++){
                    if (x[i][y]==' '){WhiteRookMoves+=1;continue;}
                    if (x[i][y]=='s'||x[i][y]=='r'||x[i][y]=='b'||x[i][y]=='n'||x[i][y]=='q'||x[i][y]=='k'){WhiteRookMoves+=1; break;}
                    else{break;}}
                for (y=i+1; y>0; y++){
                    if (x[y][j]==' '){WhiteRookMoves+=1;continue;}
                    if (x[y][j]=='s'||x[y][j]=='r'||x[y][j]=='b'||x[y][j]=='n'||x[y][j]=='q'||x[y][j]=='k'){WhiteRookMoves+=1; break;}
                    else{break;}}
                for (y=j-1; y>0; y--){
                    if (x[i][y]==' '){WhiteRookMoves+=1;continue;}
                    if (x[i][y]=='s'||x[i][y]=='r'||x[i][y]=='b'||x[i][y]=='n'||x[i][y]=='q'||x[i][y]=='k'){WhiteRookMoves+=1; break;}
                    else{break;}}}}}}
                    
//Version 5 - Queen//
WhiteQueen(char x[12][12]){
    int i, j, k, l;
    for (i=0;i<12;i++){ for (j=0;j<12;j++){ if (x[i][j]=='Q'){
                for(k=i-1; k>0; k--){
                    if (x[k][j]==' '){WhiteQueenMoves+=1; continue;}
                    if (x[k][j]=='s'||x[k][j]=='r'||x[k][j]=='b'||x[k][j]=='n'||x[k][j]=='q'||x[k][j]=='k'){WhiteQueenMoves+=1; break;}
                    else{break;}}
                for (k=i-1,l=j+1; k>0,l>0; k--,l++){
                    if (x[k][l]==' '){WhiteQueenMoves += 1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||x[k][l]=='k'){WhiteQueenMoves+=1; break;}
                    else{break;}}
                for (k=j+1; k>0; k++){
                    if (x[i][k]==' '){WhiteQueenMoves+=1; continue;}
                    if (x[i][k]=='s'||x[i][k]=='r'||x[i][k]=='b'||x[i][k]=='n'||x[i][k]=='q'||x[i][k]=='k'){WhiteQueenMoves+=1; break;}
                    else{break;}}
                for (k=i+1,l=j+1; k>0,l>0; k++,l++){
                    if (x[k][l]==' '){WhiteQueenMoves += 1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||x[k][l]=='k'){WhiteQueenMoves+=1; break;}
                    else{break;}}
                for (k=i+1; k>0; k++){
                    if (x[k][j]==' '){WhiteQueenMoves+=1; continue;}
                    if (x[k][j]=='s'||x[k][j]=='r'||x[k][j]=='b'||x[k][j]=='n'||x[k][j]=='q'||x[k][j]=='k'){WhiteQueenMoves+=1; break;}
                    else{break;}}
                for (k=i+1,l=j-1; k>0,l>0; k++,l--){
                    if (x[k][l]==' '){WhiteQueenMoves += 1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||x[k][l]=='k'){WhiteQueenMoves+=1; break;}
                    else{break;}}
                for (k=j-1; k>0; k--){
                    if (x[i][k]==' '){WhiteQueenMoves+=1; continue;}
                    if (x[i][k]=='s'||x[i][k]=='r'||x[i][k]=='b'||x[i][k]=='n'||x[i][k]=='q'||x[i][k]=='k'){WhiteQueenMoves+=1; break;}
                    else{break;}}
                for (k=i-1,l=j-1; k>0,l>0; k--,l--){
                    if (x[k][l]==' '){WhiteQueenMoves += 1; continue;}
                    if (x[k][l]=='s'||x[k][l]=='r'||x[k][l]=='n'||x[k][l]=='b'||x[k][l]=='q'||x[k][l]=='k'){WhiteQueenMoves+=1; break;}
                    else{break;}}}}}}
                    
//Version 6 - King//
WhiteKing(char x[12][12]){
    int i, j, k, l;
    for (i=0; i<12; i++){ for (j=0; j<12; j++){ if (x[i][j]=='K'){
                if (x[i- 1][j]==' '){WhiteKingMoves+=1;}
                if (x[i-1][j]=='s'||x[i-1][j]=='r'||x[i-1][j]=='b'||x[i-1][j]=='n'||x[i-1][j]=='q'||x[i-1][j]=='k'){WhiteKingMoves+=1;}
                if (x[i- 1][j+1]==' '){WhiteKingMoves+=1;}
                if (x[i-1][j+1]=='s'||x[i-1][j+1]=='r'||x[i-1][j+1]=='n'||x[i-1][j+1]=='b'||x[i-1][j+1]=='q'||x[i-1][j+1]=='k' ){WhiteKingMoves+=1;}
                if (x[i][j+1]==' '){WhiteKingMoves+=1;}
                if (x[i][j+1]=='s'||x[i][j+1]=='r'||x[i][j+1]=='b'||x[i][j+1]=='n'||x[i][j+1]=='q'||x[i][j+1]=='k'){WhiteKingMoves+=1;}
                if (x[i+1][j+1]==' '){WhiteKingMoves+=1;}
                if (x[i+1][j+1]=='s'||x[i+1][j+1]=='r'||x[i+1][j+1]=='n'||x[i+1][j+1]=='b'||x[i+1][j+1]=='q'||x[i+1][j+1]=='k' ){WhiteKingMoves+=1;}
                if (x[i+1][j]==' '){WhiteKingMoves+=1;}
                if (x[i+1][j]=='s'||x[i+1][j]=='r'||x[i+1][j]=='b'||x[i+1][j]=='n'||x[i+1][j]=='q'||x[i+1][j]=='k'){WhiteKingMoves+=1;}
                if (x[i+1][j- 1]==' '){WhiteKingMoves+=1;}
                if (x[i+1][j-1]=='s'||x[i+1][j-1]=='r'||x[i+1][j-1]=='n'||x[i+1][j-1]=='b'||x[i+1][j-1]=='q'||x[i+1][j-1]=='k' ){WhiteKingMoves+=1;}
                if (x[i][j- 1]==' '){WhiteKingMoves+=1;}
                if (x[i][j-1]=='s'||x[i][j-1]=='r'||x[i][j-1]=='b'||x[i][j-1]=='n'||x[i][j-1]=='q'||x[i][j-1]=='k'){WhiteKingMoves+=1;}
                if (x[i- 1][j- 1]==' '){WhiteKingMoves+=1;}
                if (x[i-1][j-1]=='s'||x[i-1][j-1]=='r'||x[i-1][j-1]=='n'||x[i-1][j-1]=='b'||x[i-1][j-1]=='q'||x[i-1][j-1]=='k' ){WhiteKingMoves+=1;}}}}}
