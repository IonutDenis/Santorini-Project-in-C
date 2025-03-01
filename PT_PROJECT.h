#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define LEN 5        // refers to the game board lenght
#define num_player 2 // refers to the number of players
#define RED "\x1B[31m"
#define RESET "\x1B[0m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
char p1l;
char p2l;
int freq[4] = {18, 22, 18, 14}; // dome, level1, level2, level3
int setup = 0;
int setSetup = 0;

typedef struct
{
    int level;
    char piece;
} board;

typedef struct
{
    int bx, by, gx, gy; // boy and girl coordinates
    char l;             // letter
    int hero;           // 0 for eros ............. 1 for chronos
} player_type;

typedef struct
{
    int x;
    int y;
}choice;

void resetBoard(board table[LEN][LEN]);
void printUnicode(char c);
void printTable(board table[LEN][LEN]);
int selectRandomPlayer();
void selectPlayerName(player_type *player1, player_type *player2, int turn);
int checkOverlappingPos(int x, int y, board table[LEN][LEN]);
void selectStartingPosition(board table[LEN][LEN], player_type *player1, player_type *player2, int turn);
void generateAltPos(board Table[LEN][LEN], choice Pos[10], int *len, int xs, int ys);
void generateAltBuild(board Table[LEN][LEN], choice Build[10], int *len, int xs, int ys);
int validDistance(int xs, int ys, int xe, int ye);
int correctCoordinates(board table[LEN][LEN], int xs, int ys, int xe, int ye);
void movePiece(board table[LEN][LEN], int xs, int ys, int xe, int ye);
void movePlayer(player_type *Player, board table[LEN][LEN], int opt, int turn);
void moveAnything(player_type *Player, board table[LEN][LEN], int turn);
int isBuildValid(board Table[LEN][LEN],int xe, int ye, int xb, int yb);
void buildSomething(board Table[LEN][LEN], int xe, int ye);
void chronosAbility(board Table[LEN][LEN], player_type Player1, player_type Player2);
void win(board Table[LEN][LEN], player_type Player1, player_type Player2);
int validDistanceForEros(int xs, int ys, int xe, int ye);
void erosAbility(board Table[LEN][LEN], player_type Player1, player_type Player2);
void noMove(int turn, int len);
FILE *openFile(const char *filename, const char *filetype);
void saveGame(FILE *fout, board Table[LEN][LEN], player_type Player1, player_type Player2, int turn);
void loadGame(FILE *fin, board Table[LEN][LEN], player_type *Player1, player_type *Player2, int *turn);