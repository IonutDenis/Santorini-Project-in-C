#include "PT_PROJECT.h"

// fai o verificare pentru build sa nu dea seg fault

void resetBoard(board table[LEN][LEN]) // makes the whole board have 0's (reset)
{
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            table[i][j].level = 0;
            table[i][j].piece = ' ';
        }
    }
}

void printUnicode(char c)
{
    if (c == toupper(p1l))
    {
        printf("\xF0\x9F\x91\xA6 ");
    }
    else if (c == tolower(p1l))
    {
        printf("\xF0\x9F\x91\xA7 ");
    }
    else if (c == toupper(p2l))
    {
        printf("\xF0\x9F\xA7\x94 ");
    }
    else if (c == tolower(p2l))
    {
        printf("\xF0\x9F\x91\xB5 ");
    }
    else
        printf("   ");
}

void printTable(board table[LEN][LEN]) // this function prints out the current state of the game board
{
    printf("Player 1 boy: ");
    printUnicode(toupper(p1l));
    printf(", girl: ");
    printUnicode(tolower(p1l));
    printf("\nPlayer 2 boy: ");
    printUnicode(toupper(p2l));
    printf(", girl: ");
    printUnicode(tolower(p2l));

    printf(CYAN "\n-----------------------------\n" RESET);
    printf("  ");
    for (int k = 0; k < LEN; k++)
    {
        printf(CYAN "|%4d" RESET, k);
    }

    printf(CYAN "|\n" RESET);
    for (int i = 0; i < LEN; i++)
    {
        printf(CYAN "-----------------------------\n" RESET);
        for (int j = 0; j < LEN; j++)
        {
            if (j == 0)
            {
                printf(CYAN "%2d|" RESET, i);
            }
            // printf("%c%3c|", (table[i][j].level == 0) ? ' ' : table[i][j].level + '0', table[i][j].piece);
            printf(CYAN "%c" RESET, (table[i][j].level == 0) ? ' ' : table[i][j].level + '0');
            printUnicode(table[i][j].piece);
            printf(CYAN "|" RESET);
        }
        printf("\n");
        if (i == LEN - 1)
        {
            printf(CYAN "----------------------------\n" RESET);
        }
    }
}

int selectRandomPlayer() // generates random num so that we know which player begins
{
    srand(time(0));
    return rand() % num_player;
}

void selectPlayerName(player_type *player1, player_type *player2, int turn) // takes the name which the player wants and also checks whose turn it is
{
    char p1, p2;
    if (turn % 2 != 0)
    {
        printf("Player 2, Please Enter Your Player's Letter:\n");
        scanf(" %c", &p2);
        // getchar();
        do
        {
            printf("Player 1, Please Enter Your Player's Letter:\n");
            scanf(" %c", &p1);
            if (p1 == p2)
            {
                printf("You cannot select the same letter for both players, please input another letter! \n");
                //  getchar();
            }
        } while (p1 == p2);
    }
    else
    {
        printf("Player 1, Please Enter Your Player's Letter:\n");
        scanf(" %c", &p1);
        // getchar();
        do
        {
            printf("Player 2, Please Enter Your Player's Letter:\n");
            scanf(" %c", &p2);
            if (p1 == p2)
            {
                printf("You cannot select the same letter for both players, please input another letter! \n");
                // getchar();
            }
        } while (p1 == p2);
    }
    player1->l = p1;
    player2->l = p2;
    p1l = p1;
    p2l = p2;
}

int checkOverlappingPos(int x, int y, board table[LEN][LEN]) // Makes sure that the position of a piece is not overlapping
{
    if (x < 0 || x >= LEN || y < 0 || y >= LEN)
    {
        return 1;
    }
    if (table[x][y].piece == ' ')
    {
        return 0;
    }

    return 1;
}

void selectStartingPosition(board table[LEN][LEN], player_type *player1, player_type *player2, int turn) // This function allows the player to place the pieces on the board (on a valid position)
{
    if (turn % 2 != 0)
    {
        printf("Player 2 please choose a starting position for both of your pieces\n");
        printf("For Boy:\n");
        scanf("%d %d", &player2->bx, &player2->by);
        table[player2->bx][player2->by].piece = toupper(player2->l);
        do
        {
            printf("For Girl: \n");
            scanf("%d %d", &player2->gx, &player2->gy);
            if (checkOverlappingPos(player2->gx, player2->gy, table) != 0)
            {
                printf("Player 2 please choose another position\n");
            }
        } while (checkOverlappingPos(player2->gx, player2->gy, table));
        table[player2->gx][player2->gy].piece = tolower(player2->l);

        printf("Player 1 please choose a starting position for both of your pieces\n");
        do
        {
            printf("For Boy:\n");
            scanf("%d %d", &player1->bx, &player1->by);
            if (checkOverlappingPos(player1->bx, player1->by, table) != 0)
            {
                printf("Player 1 please choose another position\n");
            }
        } while (checkOverlappingPos(player1->bx, player1->by, table));
        table[player1->bx][player1->by].piece = toupper(player1->l);
        do
        {
            printf("For Girl: \n");
            scanf("%d %d", &player1->gx, &player1->gy);
            if (checkOverlappingPos(player1->gx, player1->gy, table) != 0)
            {
                printf("Player 1 please choose another position\n");
            }
        } while (checkOverlappingPos(player1->gx, player1->gy, table));
        table[player1->gx][player1->gy].piece = tolower(player1->l);
    }
    else
    {
        printf("Player 1 please choose a starting position for both of your pieces\n");
        printf("For Boy:\n");
        scanf("%d %d", &player1->bx, &player1->by);
        table[player1->bx][player1->by].piece = toupper(player1->l);
        do
        {
            printf("For Girl: \n");
            scanf("%d %d", &player1->gx, &player1->gy);
            if (checkOverlappingPos(player1->gx, player1->gy, table) != 0)
            {
                printf("Player 1 please choose another position\n");
            }
        } while (checkOverlappingPos(player1->gx, player1->gy, table));
        table[player1->gx][player1->gy].piece = tolower(player1->l);

        printf("Player 2 please choose a starting position for both of your pieces\n");
        do
        {
            printf("For Boy:\n");
            scanf("%d %d", &player2->bx, &player2->by);
            if (checkOverlappingPos(player2->bx, player2->by, table) != 0)
            {
                printf("Player 2 please choose another position\n");
            }
        } while (checkOverlappingPos(player2->bx, player2->by, table));
        table[player2->bx][player2->by].piece = toupper(player2->l);
        do
        {
            printf("For Girl: \n");
            scanf("%d %d", &player2->gx, &player2->gy);
            if (checkOverlappingPos(player2->gx, player2->gy, table) != 0)
            {
                printf("Player 2 please choose another position\n");
            }
        } while (checkOverlappingPos(player2->gx, player2->gy, table));
        table[player2->gx][player2->gy].piece = tolower(player2->l);
    }
}

int validDistance(int xs, int ys, int xe, int ye)
{
    if (xe == xs && ye == (ys + 1))
    {
        // printf("east");
        return 0;
    }
    else if (xe == (xs + 1) && ye == (ys + 1))
    {
        // printf("southeast");
        return 0;
    }
    else if (xe == (xs + 1) && ye == ys)
    {
        // printf("south");
        return 0;
    }
    else if (xe == (xs + 1) && ye == (ys - 1))
    {
        // printf("southWest");
        return 0;
    }
    else if (xe == xs && ye == (ys - 1))
    {
        // printf("west");
        return 0;
    }
    else if (xe == (xs - 1) && ye == (ys - 1))
    {
        // printf("northWest");
        return 0;
    }
    else if (xe == (xs - 1) && ye == ys)
    {
        // printf("north");
        return 0;
    }
    else if (xe == (xs - 1) && ye == (ys + 1))
    {
        // printf("northeast\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

int validDistanceForEros(int xs, int ys, int xe, int ye)
{
    if (xe == xs && ye == (ys + 1))
    {
        // printf("east");
        return 0;
    }
    else if (xe == (xs + 1) && ye == ys)
    {
        // printf("south");
        return 0;
    }
    else if (xe == xs && ye == (ys - 1))
    {
        // printf("west");
        return 0;
    }
    else if (xe == (xs - 1) && ye == ys)
    {
        // printf("north");
        return 0;
    }
    else
    {
        return 1;
    }
}

int correctCoordinates(board table[LEN][LEN], int xs, int ys, int xe, int ye) // xs = x start, xe = x end
{
    // hint* check if distance is maxim 1
    // check if difference of level is max 1
    // check if there exists a player on the location you are currently moving to
    // check if the position actually exists for ex: 7 7 does not exist.......
    if (xe > 4 || ye > 4 || xe < 0 || ye < 0)
    {
        return 1;
    }
    if (table[xe][ye].piece != ' ')
    {
        return 1;
    }
    if (abs(table[xs][ys].level - table[xe][ye].level) > 1)
    {
        return 1;
    }
    if (validDistance(xs, ys, xe, ye))
    {
        return 1;
    }
    return 0;
}

void movePiece(board table[LEN][LEN], int xs, int ys, int xe, int ye) // need to change name
{
    table[xe][ye].piece = table[xs][ys].piece;
    table[xs][ys].piece = ' ';
}

void movePlayer(player_type *Player, board table[LEN][LEN], int opt, int turn) // need to change name
{
    int xe; // result, where it needs to go
    int ye;
    choice Pos[10];
    int len = 0;
    int c = 0;
    if (opt == 1) // move girl
    {
        // do
        // {
        // printf("Enter the coordinates of where you want to move your Girl:");
        printUnicode(tolower(Player->l));
        generateAltPos(table, Pos, &len, Player->gx, Player->gy);
        printf("You can currently move your player to the following positions: \n");
        noMove(turn, len);
        for (int i = 0; i < len; i++)
        {
            printf("Choice: %d, At position: (%d,%d)    ", i, Pos[i].x, Pos[i].y);
            if (i % 3 == 0 && i != 0)
            {
                printf("\n");
            }
        }
        do
        {
            printf("\nYour choice is: ");
            scanf("%d", &c);
            if (c >= len)
            {
                printf("Please select an option from the list provided\n");
            }
        } while (c >= len);

        xe = Pos[c].x;
        ye = Pos[c].y;
        // printf("\nxe = ");
        // scanf("%d", &xe);
        // printf("ye = ");
        // scanf("%d", &ye);
        // if (correctCoordinates(table, Player->gx, Player->gy, xe, ye) == 1)
        // {
        //     printf("You have chosen invalid coordinates!\n");
        //     printTable(table);
        // }
        // } while (correctCoordinates(table, Player->gx, Player->gy, xe, ye));
        movePiece(table, Player->gx, Player->gy, xe, ye);
        Player->gx = xe;
        Player->gy = ye;
        printTable(table);
        buildSomething(table, xe, ye);
    }
    else
    {
        // do
        // {
        // printf("Enter the coordinates of where you want to move your Boy:");
        printUnicode(toupper(Player->l));
        generateAltPos(table, Pos, &len, Player->bx, Player->by);
        printf("You can currently move your player to the following positions: \n");
        noMove(turn, len);
        for (int i = 0; i < len; i++)
        {
            printf("Choice: %d, At position: (%d,%d)    ", i, Pos[i].x, Pos[i].y);
            if (i % 3 == 0 && i != 0)
            {
                printf("\n");
            }
        }
        do
        {
            if (c >= len)
            {
                printf("Please select an option from the list provided\n");
            }
            printf("\nYour choice is: ");
            scanf("%d", &c);
        } while (c >= len);

        xe = Pos[c].x;
        ye = Pos[c].y;
        //     printf("\nxe = ");
        //     scanf("%d", &xe);
        //     printf("ye = ");
        //     scanf("%d", &ye);
        //     if (correctCoordinates(table, Player->bx, Player->by, xe, ye) == 1)
        //     {
        //         printf("You have chosen invalid coordinates!\n");
        //         printTable(table);
        //     }
        // } while (correctCoordinates(table, Player->bx, Player->by, xe, ye));
        movePiece(table, Player->bx, Player->by, xe, ye);
        Player->bx = xe;
        Player->by = ye;
        printTable(table);
        buildSomething(table, xe, ye);
    }
}

void moveAnything(player_type *Player, board table[LEN][LEN], int turn) // change name
{
    printf("Choose which piece you want to move (1 for Girl or 2 for Boy)\n");
    int opt;
    do
    {
        printf("Enter your option: \n");
        scanf("%d", &opt);
        if (opt != 1 && opt != 2)
        {
            printf("Invalid input, please choose 1 for Girl or 2 for Boy\n");
        }
    } while (opt != 1 && opt != 2);
    movePlayer(Player, table, opt, turn);
}

int isBuildValid(board Table[LEN][LEN], int xe, int ye, int xb, int yb)
{
    // check if the build position is on the map and also if there is a dome
    if (xb > 4 || xb < 0 || yb > 4 || yb < 0 || validDistance(xe, ye, xb, yb) || Table[xb][yb].level == 4 || Table[xb][yb].piece != ' ')
    {
        return 1;
    }
    return 0;
}

void buildSomething(board Table[LEN][LEN], int xe, int ye) // change name
{
    int xb, yb;
    choice Build[10];
    int len = 0;
    int b = 0;
    generateAltBuild(Table, Build, &len, xe, ye);
    printf("Please select where you want to build: \n");
    for (int i = 0; i < len; i++)
    {
        printf("Build: %d  Position: (%d, %d)    ", i, Build[i].x, Build[i].y);
        if (i % 3 == 0 && i != 0)
        {
            printf("\n");
        }
    }
    do
    {
        printf("\nYour choice is: ");
        scanf("%d", &b);
        if (b >= len)
        {
            printf("Please select an option from the list provided\n");
        }
    } while (b >= len);

    xb = Build[b].x;
    yb = Build[b].y;
    // do
    // {
    //     printf("xb = ");
    //     scanf("%d", &xb);
    //     printf("yb = ");
    //     scanf("%d", &yb);
    //     if (isBuildValid(Table, xe, ye, xb, yb) == 1)
    //     {
    //         printf("Invalid building position, please choose again: \n");
    //     }

    // } while (isBuildValid(Table, xe, ye, xb, yb) == 1);

    Table[xb][yb].level++;
}

void generateAltPos(board Table[LEN][LEN], choice Pos[10], int *len, int xs, int ys)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (correctCoordinates(Table, xs, ys, xs - 1 + i, ys - 1 + j) == 0)
            {
                Pos[*len].x = xs - 1 + i;
                Pos[*len].y = ys - 1 + j;
                (*len)++;
            }
        }
    }
}

void generateAltBuild(board Table[LEN][LEN], choice Build[10], int *len, int xs, int ys)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (isBuildValid(Table, xs, ys, xs - 1 + i, ys - 1 + j) == 0)
            {
                Build[*len].x = xs - 1 + i;
                Build[*len].y = ys - 1 + j;
                (*len)++;
            }
        }
    }
}

void chronosAbility(board Table[LEN][LEN], player_type Player1, player_type Player2)
{
    int count = 0;
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            if (Table[i][j].level == 4)
            {
                ++count;
            }
        }
    }
    if (count == 5)
    {
        if (Player1.hero == 1)
        {
            printf("\n\n\nPlayer 1 Wins!\n\n\n");
            exit(-1);
        }
        else
        {
            printf("\n\n\nPlayer 2 Wins!\n\n\n");
            exit(-1);
        }
    }
}

void erosAbility(board Table[LEN][LEN], player_type Player1, player_type Player2)
{
    if (setSetup == 0)
    {
        // printf("Enterning set up\n");
        if (Player1.hero == 0)
        {
            // printf("Player1 is hero");
            if ((Player1.bx == 0 && Player1.by == 0 && ((Player1.gx == 0 && Player1.gy == 4) || (Player1.gx == 4 && Player1.gy == 4) || (Player1.gx = 4 && Player1.gy == 0))) ||
                (Player1.bx == 0 && Player1.by == 4 && ((Player1.gx == 0 && Player1.gy == 0) || (Player1.gx == 4 && Player1.gy == 4) || (Player1.gx == 4 && Player1.gy == 0))) ||
                (Player1.bx == 4 && Player1.by == 4 && ((Player1.gx == 0 && Player1.gy == 0) || (Player1.gx == 4 && Player1.gy == 0) || (Player1.gx == 0 && Player1.gy == 4))) ||
                (Player1.bx == 4 && Player1.by == 0 && ((Player1.gx == 0 && Player1.gy == 0) || (Player1.gx == 4 && Player1.gy == 4) || (Player1.gx == 0 && Player1.gy == 4))))
            {
                // printf("Player1 set up complete");
                setup = 1;
            }
        }
        else if (Player2.hero == 0)
        {
            // printf("Player2 is hero");
            if ((Player2.bx == 0 && Player2.by == 0 && ((Player2.gx == 0 && Player2.gy == 4) || (Player2.gx == 4 && Player2.gy == 4) || (Player2.gx = 4 && Player2.gy == 0))) ||
                (Player2.bx == 0 && Player2.by == 4 && ((Player2.gx == 0 && Player2.gy == 0) || (Player2.gx == 4 && Player2.gy == 4) || (Player2.gx == 4 && Player2.gy == 0))) ||
                (Player2.bx == 4 && Player2.by == 4 && ((Player2.gx == 0 && Player2.gy == 0) || (Player2.gx == 4 && Player2.gy == 0) || (Player2.gx == 0 && Player2.gy == 4))) ||
                (Player2.bx == 4 && Player2.by == 0 && ((Player2.gx == 0 && Player2.gy == 0) || (Player2.gx == 4 && Player2.gy == 4) || (Player2.gx == 0 && Player2.gy == 4))))
            {
                // printf("Player2 set up complete");
                setup = 1;
            }
        }
        setSetup = 1;
    }
    // printf("setSetup = %d\n setup = %d", setSetup, setup);
    if (setup == 1)
    {
        if (Player1.hero == 0)
        {
            // printf("Entering Verification for player 1");
            if (((validDistanceForEros(Player1.bx, Player1.by, Player1.gx, Player1.gy)) == 0) && ((Table[Player1.bx][Player1.by].level && Table[Player1.gx][Player1.gy].level) == 1))
            {
                printf("\n\n\nPlayer 1 Wins!\n\n\n");
                exit(-1);
            }
        }
        else if (Player2.hero == 0)
        {
            // printf("Entering Verification for player 2");
            if (((validDistanceForEros(Player2.bx, Player2.by, Player2.gx, Player2.gy)) == 0) && ((Table[Player2.bx][Player2.by].level && Table[Player2.gx][Player2.gy].level) == 1))
            {
                printf("\n\n\nPlayer 2 Wins!\n\n\n");
                exit(-1);
            }
        }
    }
    // for (int i = 0; i < LEN; i++)
    // {
    //     for (int j = 0; j < LEN; j++)
    //     {
    //         // if((Table[Player1.bx][Player1.by].piece || Table[Player1.gx][Player1.gy].piece)==Table[0][0].piece)
    //         if (((Table[Player1.bx][Player1.by].piece) && (Table[Player1.gx][Player1.gy].piece)) == Table[0][0].piece || Table[0][4].piece || Table[4][0].piece || Table[4][4].piece)
    //         {
    //             while ((validDistanceForEros(Player1.bx, Player1.by, Player1.gx, Player1.gy)) == 0)
    //             {
    //                 if (Table[Player1.bx][Player1.by].level && Table[Player1.gx][Player1.gy].level == 1)
    //                 {
    //                     printf("\n\n\nPlayer 1 Wins!\n\n\n");
    //                     exit(-1);
    //                 }
    //             }
    //         }

    //         if (((Table[Player2.bx][Player2.by].piece) && (Table[Player2.gx][Player2.gy].piece)) == Table[0][0].piece || Table[0][4].piece || Table[4][0].piece || Table[4][4].piece)
    //         {
    //             while ((validDistanceForEros(Player2.bx, Player2.by, Player2.gx, Player2.gy)) == 0)
    //             {
    //                 if (Table[Player2.bx][Player2.by].level && Table[Player2.gx][Player2.gy].level == 1)
    //                 {
    //                     printf("\n\n\nPlayer 2 Wins!\n\n\n");
    //                     exit(-1);
    //                 }
    //             }
    //         }
    //     }
    // }
}

void win(board Table[LEN][LEN], player_type Player1, player_type Player2)
{
    if (Table[Player1.gx][Player1.gy].level == 3 || Table[Player1.bx][Player1.by].level == 3)
    {
        printf("\n\n\nPlayer 1 Wins!\n\n\n");
        exit(-1);
    }
    if (Table[Player2.gx][Player2.gy].level == 3 || Table[Player2.bx][Player2.by].level == 3)
    {
        printf("\n\n\nPlayer 2 Wins!\n\n\n");
        exit(-1);
    }
}

FILE *openFile(const char *filename, const char *filetype)
{
    FILE *f = NULL;
    f = fopen(filename, filetype);
    if (f == NULL)
    {
        printf("The file has not been found\n");
        exit(-1);
    }
    return f;
}

void saveGame(FILE *fout, board Table[LEN][LEN], player_type Player1, player_type Player2, int turn)
{
    rewind(fout);
    fprintf(fout, "%d\n", turn);
    fprintf(fout, "%c %d %d %d %d %d\n", Player1.l, Player1.hero, Player1.bx, Player1.by, Player1.gx, Player1.gy);
    fprintf(fout, "%c %d %d %d %d %d\n", Player2.l, Player2.hero, Player2.bx, Player2.by, Player2.gx, Player2.gy);
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            fprintf(fout, "%d ", Table[i][j].level);
        }
        fprintf(fout, "\n");
    }
    fflush(fout);
}

void loadGame(FILE *fin, board Table[LEN][LEN], player_type *Player1, player_type *Player2, int *turn)
{
    // FILE *fin = openFile(filename, "r+");
    rewind(fin);
    fscanf(fin, "%d\n", turn);
    fscanf(fin, "%c %d %d %d %d %d\n", &Player1->l, &Player1->hero, &Player1->bx, &Player1->by, &Player1->gx, &Player1->gy);
    fscanf(fin, "%c %d %d %d %d %d\n", &Player2->l, &Player2->hero, &Player2->bx, &Player2->by, &Player2->gx, &Player2->gy);
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            fscanf(fin, "%d", &Table[i][j].level);
        }
    }
    p1l = Player1->l;
    p2l = Player2->l;

    Table[Player1->bx][Player1->by].piece = toupper(Player1->l);
    Table[Player1->gx][Player1->gy].piece = tolower(Player1->l);

    Table[Player2->bx][Player2->by].piece = toupper(Player2->l);
    Table[Player2->gx][Player2->gy].piece = tolower(Player2->l);

    fprintf(stdout, "%c %d %d %d %d %d\n", Player1->l, Player1->hero, Player1->bx, Player1->by, Player1->gx, Player1->gy);
    fprintf(stdout, "%c %d %d %d %d %d\n", Player2->l, Player2->hero, Player2->bx, Player2->by, Player2->gx, Player2->gy);
}

void noMove(int turn, int len)
{
    if (len == 0)
    {
        if (turn % 2 != 0)
        {
            printf("Player 2 has no moves!\n \n\n\nPlayer 1 Wins!\n\n\n");
            exit(-1);
        }
        else
        {
            printf("Player 1 has no moves!\n \n\n\nPlayer 2 Wins!\n\n\n");
            exit(-1);
        }
    }
}

int main()
{
    board table[LEN][LEN];
    player_type player1;
    player_type player2;
    int turn;
    // resetBoard(table);
    // printTable(table);
    // turn = selectRandomPlayer();
    // selectPlayerName(&player1, &player2, turn);
    // printf("Player 1 = %c\n", player1);
    // printf("Player 2 = %c\n", player2);
    printf("Do you want to continue the last game? (y/n)\n");
    char opt = 'n';
    printf("Option =");
    scanf(" %c", &opt);
    FILE *fout = openFile("saveGame.txt", "r+");
    do
    {
        if (opt != 'y' && opt != 'n')
        {
            printf("Invalid Option, Please Enter a Valid Option\n");
            printf("Option =");
            scanf(" %c", &opt);
        }
    } while (opt != 'y' && opt != 'n');
    switch (opt)
    {
    case 'y':
        resetBoard(table);
        loadGame(fout, table, &player1, &player2, &turn);
        printf("Player 1 = %c\n", player1.l);
        printf("Player 2 = %c\n", player2.l);
        printf("Staring a saved game...\n");
        printTable(table);
        do
        {
            erosAbility(table, player1, player2);
            if (turn % 2 != 0)
            {
                printf("Its Player 2's turn\n");
                moveAnything(&player2, table, turn);
            }
            else
            {
                printf("Its Player 1's turn\n");
                moveAnything(&player1, table, turn);
            }
            chronosAbility(table, player1, player2);
            win(table, player1, player2);
            turn++;
            printTable(table);
            saveGame(fout, table, player1, player2, turn);
        } while (1);
        break;

    case 'n':
        resetBoard(table);
        turn = selectRandomPlayer();
        selectPlayerName(&player1, &player2, turn);
        printf("Player 1 = %c\n", player1.l);
        printf("Player 2 = %c\n", player2.l);
        printTable(table);
        int hero = -1;
        if (turn % 2 != 0)
        {
            do
            {
                printf("Player 2, please choose your hero!\n 0 - Eros (When your workers start in 2 of the 4 corners, you also win if they get into neighbouring positions and are both on level 1)\n 1 - Chronus (You also win when there are at least five Complete Towers on the board)\n Hero = ");
                scanf(" %d", &hero);
                if (hero != 0 && hero != 1)
                {
                    printf("Invalid hero, please try again\n");
                }
            } while (hero != 0 && hero != 1);
            if (hero == 0)
            {
                player2.hero = 0;
                player1.hero = 1;
            }
            else
            {
                player1.hero = 0;
                player2.hero = 1; // for when player 2 starts
            }
        }
        else
        {
            do
            {
                printf("Player 1, please choose your hero!\n 0 - Eros (When your workers start in 2 of the 4 corners, you also win if they get into neighbouring positions and are both on level 1)\n 1 - Chronus (You also win when there are at least five Complete Towers on the board)\n Hero = ");
                scanf(" %d", &hero);
                if (hero != 0 && hero != 1)
                {
                    printf("Invalid hero, please try again\n");
                }
            } while (hero != 0 && hero != 1);
            if (hero == 0)
            {
                player2.hero = 1;
                player1.hero = 0;
            }
            else
            {
                player1.hero = 1;
                player2.hero = 0; // for when player 1 starts
            }
        }
        selectStartingPosition(table, &player1, &player2, turn);
        printTable(table);
        printf("Staring a New Game...\n");
        do
        {
            erosAbility(table, player1, player2);
            if (turn % 2 != 0)
            {
                printf("Its Player 2's turn\n");
                moveAnything(&player2, table, turn);
            }
            else
            {
                printf("Its Player 1's turn\n");
                moveAnything(&player1, table, turn);
            }
            chronosAbility(table, player1, player2);
            win(table, player1, player2);
            turn++;
            printTable(table);
            saveGame(fout, table, player1, player2, turn);
        } while (1);
        break;
    }
    return 0;
}