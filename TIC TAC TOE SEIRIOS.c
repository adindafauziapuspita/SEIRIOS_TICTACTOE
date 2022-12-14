#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

/* STRUCT */
typedef struct {
    char nama[40];
} Player;

typedef struct {
    int board;
} Game; 

/* DEKLARASI MODUL */
void mainMenu();
/*Modul ini digunakan untuk menampilkan Menu Utama yang berisi pilihan menu untuk masuk ke sub program selanjutnya
I.S : Main menu tidak tampil.
F.S : Main menu tampil dengan isi tampilan judul permainan “Seirios XOX” beserta pilihan angka untuk lanjut ke section / sub program selanjutnya.
*/
int  readSelectMenu(int x);
/*Modul ini digunakan untuk membaca inputan user pada main menu untuk menentukan sub program selanjutnya
I.S : Tidak diketahui sub program mana yang dipilih oleh user dan program tidak dapat melanjutkan ke sub program selanjutnya.
F.S : Terbaca angka yang diinputkan oleh user dan program dapat melanjutkan ke section berikutnya sesuai dengan yang dipilih oleh user.
*/
void howToPlay();
/*Modul ini digunakan untuk menampilkan petunjuk program permainan (aturan dan cara bermain)
I.S: Pemain tidak mengetahui cara bermain permainan SEIRIOS XOX
F.S : Pemain mengetahui cara bermain permainan SEIRIOS XOX
*/
void playGame();
/*Modul ini digunakan untuk menjalankan permainan SEIRIOS XOX
I.S : Permainan tic tac toe tidak dapat dijalankan 
F.S : Permainan dapat tic tac toe dapat dijalankan
*/
void selectMenu();
/*Modul ini digunakan saat permainan selesai dan user ingin menghentikan permainan 
I.S : User tidak dapat menghentikan permainan dan akan tetap diam di section tersebut 
F.S : User dapat menghentikan permainan dan keluar dari program 
*/
void inputNamePlayer();
/*Modul ini digunakan untuk menampung inputan nama Player 1 dan Player 2
I.S : Belum diketahui nama Player 1 dan Player 2
F.S : Mendapatkan nama Player 1 dan Player 2 dalam bentuk string
*/
void chooseBoard(Game *sizeboard);
/*Modul ini digunakan untuk menginput board berukuran 3x3 atau 5x5 atau 7x7
 I.S: Ukuran board belum terpilih
 F.S: Ukuran board terpilih
*/
void board3x3();
/*Modul ini digunakan untuk melakukan permainan dengan ukuran dimensi board 3x3
I.S : Permainan tidak dapat berjalan pada board berdimensi 3x3 
F.S : Permainan dapat berjalan pada board berdimensi 3x3
*/
void board5x5();
/*Modul ini digunakan untuk melakukan permainan dengan ukuran dimensi board 5x5
I.S : Permainan tidak dapat berjalan pada board berdimensi 5x5 
F.S : Permainan dapat berjalan pada board berdimensi 5x5
*/
void board7x7();
/*Modul ini digunakan untuk melakukan permainan dengan ukuran dimensi board 7x7
I.S : Permainan tidak dapat berjalan pada board berdimensi 7x7 
F.S : Permainan dapat berjalan pada board berdimensi 7x7
*/
void displayWinner();
/*Modul ini digunakan untuk menampilkan tulisan Winner saat pemenang berhasil mencetak skor
I.S : Tulisan Winner tidak tampil pada layar
F.S : Muncul tulisan Winner pada layar ketika ada pemain yang berhasil mencetak skor
*/
void displayQuit();
/*Modul ini digunakan untuk menampilkan menu Quit
I.S : Menu Quit belum tampil layar
F.S : Muncul menu Quit bertuliskan “BYE” di layar
*/
void gotoxy(int x, int y);
/*Modul ini digunakan untuk menempatkan tampilan yang di print pada layer pada koordinat yang diinginkan 
I.S :  Tampilan pada layar tidak terletak pada koordinat yang diinginkan
F.S : Tampilan pada layar terletak pada koordinat yang diinginkan
*/

/* VARIABEL GLOBAL */
Player player[2];
int i, j;
char board[7][7];
int baris, kolom;
int turn = 1;
int status = 0;
int score = 0; 
Game sizeboard;


/* PROGRAM UTAMA */
int main () { 
	int selectMenu;
	
	system ("cls");
	mainMenu(); 
	selectMenu = readSelectMenu(selectMenu);
	    switch(selectMenu){
	        case 1 : system ("cls");
                    playGame();
	                break;
	        case 2 : system ("cls");
	                howToPlay();
	                break;
	        case 3 : displayQuit();
	                break;
	        default : printf("\nInvalid Input");          
	    }
    return 0;
}
 
/* MODUL */
void gotoxy (int x, int y) {
    COORD coord; 
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 

void mainMenu() {
     gotoxy(32, 1); printf ("x o x o x o x o x o x o x o x o x o x o x o x o x o x o x"); 
     gotoxy(32, 2); printf ("o                                                       o"); 
     gotoxy(32, 3); printf ("x     *****  *****  *****  ****   *****  *****  *****   x");
     gotoxy(32, 4); printf ("o     *      *        *    *   *    *    *   *  *       o");
     gotoxy(32, 5); printf ("x     *      *        *    *   *    *    *   *  *       x");
     gotoxy(32, 6); printf ("o     *****  *****    *    ****     *    *   *  *****   o");
     gotoxy(32, 7); printf ("x         *  *        *    **       *    *   *      *   x");
     gotoxy(32, 8); printf ("o         *  *        *    * *      *    *   *      *   o");
     gotoxy(32, 9); printf ("x     *****  *****  *****  *  *   *****  *****  *****   x");
     gotoxy(32, 10); printf ("o                                                       o");
     gotoxy(32, 11); printf ("x                                                       x");
     gotoxy(32, 12); printf ("o               *     *   ******   *     *              o");
     gotoxy(32, 13); printf ("x                *   *    *    *    *   *               x");
     gotoxy(32, 14); printf ("o                 * *     *    *     * *                o");
     gotoxy(32, 15); printf ("x                  *      *    *      *                 x");
     gotoxy(32, 16); printf ("o                 * *     *    *     * *                o");
     gotoxy(32, 17); printf ("x                *   *    *    *    *   *               x");
     gotoxy(32, 18); printf ("o               *     *   ******   *     *              o");
     gotoxy(32, 19); printf ("x                                                       x");
     gotoxy(32, 20); printf ("o x o x o x o x o x o x o x o x o x o x o x o x o x o x o");                                          
     gotoxy(32, 22); printf (">>>>>>>>>>>>>>>>>>>>>>>> MAIN MENU <<<<<<<<<<<<<<<<<<<<<<");
     gotoxy(43, 24); printf ("            1. Start                               ");
     gotoxy(43, 25); printf ("            2. How To Play                         ");
     gotoxy(43, 26); printf ("            3. Quit                                ");
     gotoxy(43, 28); printf ("            SELECT MENU : ");
}

void playGame(){
	inputNamePlayer();
    system("cls");
    chooseBoard(&sizeboard);
}

void inputNamePlayer(){
     gotoxy(32, 1); printf ("x o x o x o x o x o x o x o x o x o x o x o x o x o x "); 
     gotoxy(32, 2); printf ("o                                                   o"); 
     gotoxy(32, 3); printf ("x         *   *     *   ***    *   *   *****        x");
     gotoxy(32, 4); printf ("o         *   * *   *   *  *   *   *     *          o");
     gotoxy(32, 5); printf ("x         *   *   * *   ***    *   *     *          x");
     gotoxy(32, 6); printf ("o         *   *     *   *      *   *     *          o");
     gotoxy(32, 7); printf ("x         *   *     *   *        *       *          x");
     gotoxy(32, 8); printf ("o                                                   o");
     gotoxy(32, 9); printf ("x     ***     *      ****   *   *   ****   ****     x");
     gotoxy(32, 10); printf ("o     *   *   *      *  *   *   *   *      *  *     o");
     gotoxy(32, 11); printf ("x     ***     *      ****    ***    ****   ****     x");
     gotoxy(32, 12); printf ("o     *       *      *  *     *     *      * *      o");
     gotoxy(32, 13); printf ("x     *       ****   *  *     *     ****   *   *    x");
     gotoxy(32, 14); printf ("o                                                   o");
     gotoxy(32, 15); printf ("x o x o x o x o x o x o x o x o x o x o x o x o x o x");       
     gotoxy(32, 18); printf ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	 gotoxy(32, 19); printf ("\xba    Player 1     \xba                                 \xba");
     gotoxy(32, 20); printf ("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9");
	 gotoxy(32, 21); printf ("\xba    Player 2     \xba                                 \xba");
     gotoxy(32, 22); printf ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
     getchar();
     gotoxy(52, 19); gets (player[0].nama);
     gotoxy(52, 21); gets (player[1].nama);
}

void chooseBoard(Game *sizeboard) {
     gotoxy(32, 1); printf ("x o x o x o x o x o x o x o x o x o x o x o x o x o x o x o x"); 
     gotoxy(32, 2); printf ("o                                                           o"); 
     gotoxy(32, 3); printf ("x         ****  *   *   ****    ****    ****   *****        x");
     gotoxy(32, 4); printf ("o        *      *   *  *    *  *    *  *       *            o");
     gotoxy(32, 5); printf ("x        *      *****  *    *  *    *   ****   *****        x");
     gotoxy(32, 6); printf ("o        *      *   *  *    *  *    *       *  *            o");
     gotoxy(32, 7); printf ("x         ****  *   *   ****    ****    ****   *****        x");
     gotoxy(32, 8); printf ("o                                                           o");
     gotoxy(32, 9); printf ("x         *****     ****    ******   *****    *****         x");
     gotoxy(32, 10); printf ("o         *    *   *    *   *    *   *    *   *    *        o");
     gotoxy(32, 11); printf ("x         *****   *      *  ******   *****    *    *        x");
     gotoxy(32, 12); printf ("o         *    *   *    *   *    *   *    *   *    *        o");
     gotoxy(32, 13); printf ("x         *****     ****    *    *   *     *  *****         x");
     gotoxy(32, 14); printf ("o                                                           o");
     gotoxy(32, 15); printf ("x o x o x o x o x o x o x o x o x o x o x o x o x o x o x o x");  

     
     gotoxy(52, 18); printf ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
     gotoxy(52, 19); printf ("\xba     Choose Board    \xba");
     gotoxy(52, 20); printf ("\xba       1. 3x3        \xba");
	 gotoxy(52, 21); printf ("\xba       2. 5x5        \xba");
	 gotoxy(52, 22); printf ("\xba       3. 7x7        \xba");
     gotoxy(52, 23); printf ("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcc");
     gotoxy(52, 24); printf ("\xba     Input :         \xba");
	 gotoxy(52, 25); printf ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
     gotoxy(68, 24); scanf ("%d", &(*sizeboard).board);
     if ( (*sizeboard).board == 1) {
        board3x3();
        selectMenu();
    //jika user memilih 5x5
    } else if ((*sizeboard).board == 2) { 
        board5x5();
        selectMenu();
    //jika user memilih 7x7
    } else if ((*sizeboard).board == 3) {
        board7x7();
        selectMenu();
    }
}    

void displayWinner(){
  system("cls");
     gotoxy(32, 9); printf ("*           *  ***  **       *  **       *  *******  ****** ");
     gotoxy(32,10); printf ("*           *   *   * *      *  * *      *  *        *     *");
     gotoxy(32,11); printf ("*           *   *   *   *    *  *   *    *  *        *     *");
     gotoxy(32,12); printf ("*    **     *   *   *    *   *  *    *   *  *        *     *");
     gotoxy(32,13); printf ("*   *  *    *   *   *     *  *  *     *  *  *******  ****** ");
     gotoxy(32,14); printf ("*  *    *   *   *   *      * *  *      * *  *        **    ");
     gotoxy(32,15); printf ("* *       * *   *   *       **  *       **  *        * *   ");
     gotoxy(32,16); printf ("**         **   *   *        *  *        *  *        *  * ");
     gotoxy(32,17); printf ("*           *  ***  *        *  *        *  *******  *    *");
     printf("\n\n");  
}

void displayQuit(){
    system("cls");
     gotoxy(32, 9); printf ("******  *         *  *******       *    *    *");
     gotoxy(32,10); printf ("*     *  *       *   *             *    *    *");
     gotoxy(32,11); printf ("*     *   *     *    *             *    *    *");
     gotoxy(32,12); printf ("*     *    *   *     *             *    *    *");
     gotoxy(32,13); printf ("*****       ***      *******       *    *    *");
     gotoxy(32,14); printf ("*     *      *       *             *    *    *");
     gotoxy(32,15); printf ("*     *      *       *             *    *    *");
     gotoxy(32,16); printf ("*     *      *       *                        ");
     gotoxy(32,17); printf ("******       *       *******       *    *    *");
     printf("\n\n");
}

void howToPlay() {
	 char back;
	 int selectMenu;
     gotoxy(15, 1); printf ("=========================================================================================");
     gotoxy(15, 2); printf ("||                                                                                     ||");
     gotoxy(15, 3); printf ("||   *    *  ******  *       *    *******  ******    ******  *       ******  *     *   ||");
     gotoxy(15, 4); printf ("||   *    *  *    *  *       *       *     *    *    *    *  *       *    *  *     *   ||");
     gotoxy(15, 5); printf ("||   *    *  *    *  *       *       *     *    *    *    *  *       *    *  *     *   ||");
     gotoxy(15, 6); printf ("||   ******  *    *  *   *   *       *     *    *    ******  *       ******  *******   ||");
     gotoxy(15, 7); printf ("||   *    *  *    *  *  * *  *       *     *    *    *       *       *    *     *      ||");
     gotoxy(15, 8); printf ("||   *    *  *    *  * *   * *       *     *    *    *       *       *    *     *      ||");
     gotoxy(15, 9); printf ("||   *    *  ******  *       *       *     ******    *       ******  *    *     *      ||");
     gotoxy(15, 10); printf ("||                                                                                     ||");
     gotoxy(15, 11); printf ("=========================================================================================");
     gotoxy(15, 13); printf ("Before starting the game :");
     gotoxy (22, 14); printf ("1. Start the game with input the name of Player 1 and Player 2.");
     gotoxy (22, 15); printf ("2. Input the board size (3x3 / 5x5 / 7x7).");
     gotoxy (22, 16); printf ("3. The Player 1's symbol will be an X and the Player 2's symbol will be an O.");
     gotoxy (15, 17); printf ("When playing the game :");
     gotoxy (22, 18); printf ("1. Player 1 will take the first turn in the game.");
     gotoxy (22, 19); printf ("2. Enter the row index of the board you want to fill.");
     gotoxy (22, 20); printf ("3. Enter the column index of the board you want to fill.");
     gotoxy (25, 21); printf ("You can't select the coordinates that have been choosen before.");
     gotoxy (22, 22); printf ("4. After you input the coordinates, the symbol will automaticly show in board.");
     gotoxy (22, 23); printf ("5. Repeat the step alternately until one of the player make a row that contain 3 / 5 / 7 ");
     gotoxy (25, 24); printf ("symbol sequentially horizontally, vertically and diagonally.");
     gotoxy (15, 27); printf ("Back to menu (Y : yes) : ");

     scanf("%s", &back);
     if(back=='y' || back=='Y') {
        system("cls");
        mainMenu();
        selectMenu = readSelectMenu(selectMenu);
	    switch(selectMenu){
	        case 1 : system ("cls");
                    playGame();
	                break;
	        case 2 : system ("cls");
	                howToPlay();
	                break;
	        case 3 : displayQuit();
	                break;
	        default : printf("\nInvalid Input");        
	    }
     } else {
        system("cls");
        howToPlay();  
     }
}

void board3x3(){
    
	for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        
        //permainan dimulai
        while (status == 0) {
        	system("cls");
            printf("\n");
            printf("     column\n");
            printf("    0   1   2\n");
            printf("   ___ ___ ___ \n");
            printf("  | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
            printf("0 |___|___|___|\n");
            printf("  | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
            printf("1 |___|___|___|\n");
            printf("  | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
            printf("2 |___|___|___|\n");
            printf("row\n");
            
            //giliran player
            if (turn == 1) {
                printf("\n %s's turn\n", player[0].nama);
            } else {
                printf("\n %s's turn\n", player[1].nama);
            }
            
            //inputan user
            printf(" Input row : ");
            scanf("%d", &baris);
            printf(" Input column : ");
            scanf("%d", &kolom);
            
            //mengecek apakah baris dan kolom yang dimasukkan valid
            if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3 && board[baris][kolom] == ' ') {
                if (turn == 1) {
                    board[baris][kolom] = 'X';
                    turn = 2;
                } else {
                    board[baris][kolom] = 'O';
                    turn = 1;
                }
            }
            
            //mengecek apakah ada pemenang
            if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') || 
                (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')) {
                status = 1;
            }
            for (i = 0; i < 3; i++) {
                if ((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') || 
                    (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')) {
                    status = 1;
                }
            }
            
        }
        score = 1;
        //menampilkan pemenang
        if (turn == 1) {
            displayWinner();
            printf("\t\t\t\t\t\tCONGRATS %s, YOU WIN !!\n\n", player[1].nama);
            printf("\t\t\t\t\t\t   Your score : %d", score);
            
        } else {
            displayWinner();
            printf("\t\t\t\t\t\tCONGRATS %s, YOU WIN !!\n\n", player[0].nama);
            printf("\t\t\t\t\t\t   Your score : %d", score);
     
        }       
}

void board5x5(){
	//inisialisasi board 5x5
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                board[i][j] = ' ';
            }
        }
        
        //permainan dimulai
        while (status == 0) {
        	system("cls");
            printf("\n");
            printf("          column\n");
            printf("    0   1   2   3   4\n");
            printf("   ___ ___ ___ ___ ___ \n");
            printf("  | %c | %c | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4]);
            printf("0 |___|___|___|___|___|\n");
            printf("  | %c | %c | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4]);
            printf("1 |___|___|___|___|___|\n");
            printf("  | %c | %c | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4]);
            printf("2 |___|___|___|___|___|\n");
            printf("  | %c | %c | %c | %c | %c |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4]);
            printf("3 |___|___|___|___|___|\n");
            printf("  | %c | %c | %c | %c | %c |\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4]);
            printf("4 |___|___|___|___|___|\n");
            printf("row\n");
            
            //giliran player
            if (turn == 1) {
                printf("\n %s's turn\n", player[0].nama);
            } else {
                printf("\n %s's turn\n", player[1].nama);
            }
            
            //inputan user
            printf(" Input row : ");
            scanf("%d", &baris);
            printf(" Input column : ");
            scanf("%d", &kolom);
            
            //mengecek apakah baris dan kolom yang dimasukkan valid
            if (baris >= 0 && baris < 5 && kolom >= 0 && kolom < 5 && board[baris][kolom] == ' ') {
                if (turn == 1) {
                    board[baris][kolom] = 'X';
                    turn = 2;
                } else {
                    board[baris][kolom] = 'O';
                    turn = 1;
                }
            }
            
            //mengecek apakah ada pemenang
            if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] == board[4][4] && board[0][0] != ' ') || 
                (board[0][4] == board[1][3] && board[0][4] == board[2][2] && board[0][4] == board[3][1] && board[0][4] == board[4][0] && board[0][4] != ' ')) {
                status = 1;
            }
            for (i = 0; i < 5; i++) {
                if ((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] == board[i][4] && board[i][0] != ' ') || 
                    (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] == board[4][i] && board[0][i] != ' ')) {
                    status = 1;
                }
            }
        }
        score = 1;
        //menampilkan pemenang
        if (turn == 1) {
            displayWinner();
            printf("\t\t\t\t\t\tCONGRATS %s, YOU WIN !!\n\n", player[1].nama);
            printf("\t\t\t\t\t\t   Your score : %d", score);
            
        } else {
            displayWinner();
            printf("\t\t\t\t\t\tCONGRATS %s, YOU WIN !!\n\n", player[0].nama);
            printf("\t\t\t\t\t\t   Your score : %d", score);
        }
}

void board7x7(){
	//inisialisasi board 7x7
	for (i = 0; i < 7; i++) {
            for (j = 0; j < 7; j++) {
                board[i][j] = ' ';
            }
        }
        
        //permainan dimulai
        while (status == 0) {
        	system("cls");
            printf("\n");
            printf("                 column\n");
            printf("     0    1    2    3    4    5    6  \n");
            printf("   ____ ____ ____ ____ ____ ____ ____ \n");
            printf("  | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6]);
            printf("0 |____|____|____|____|____|____|____|\n");
            printf("  | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6]);
            printf("1 |____|____|____|____|____|____|____|\n");
            printf("  | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6]);
            printf("2 |____|____|____|____|____|____|____|\n");
            printf("  | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6]);
            printf("3 |____|____|____|____|____|____|____|\n");
            printf("  | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6]);
            printf("4 |____|____|____|____|____|____|____|\n");
            printf("  | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6]);
            printf("5 |____|____|____|____|____|____|____|\n");
            printf("  | %c  | %c  | %c  | %c  | %c  | %c  | %c  |\n", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6]);
            printf("6 |____|____|____|____|____|____|____|\n");
            printf("row\n");
            
            //giliran player
            if (turn == 1) {
                printf("\n %s's turn\n", player[0].nama);
            } else {
                printf("\n %s's turn\n", player[1].nama);
            }
            
            //inputan user
            printf(" Input row : ");
            scanf("%d", &baris);
            printf(" Input column : ");
            scanf("%d", &kolom);
            
            //mengecek apakah baris dan kolom yang dimasukkan valid
            if (baris >= 0 && baris < 7 && kolom >= 0 && kolom < 7 && board[baris][kolom] == ' ') {
                if (turn == 1) {
                    board[baris][kolom] = 'X';
                    turn = 2;
                } else {
                    board[baris][kolom] = 'O';
                    turn = 1;
                }
            }
            
            //mengecek apakah ada pemenang
            if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] == board[4][4] && board[0][0] == board[5][5] && board[0][0] == board[6][6] && board[0][0] != ' ') || 
                (board[0][6] == board[1][5] && board[0][6] == board[2][4] && board[0][6] == board[3][3] && board[0][6] == board[4][2] && board[0][6] == board[5][1] && board[0][6] == board[6][0] && board[0][6] != ' ')) {
                status = 1;
            }
            for (i = 0; i < 7; i++) {
                if ((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] == board[i][4] && board[i][0] == board[i][5] && board[i][0] == board[i][6] && board[i][0] != ' ') || 
                    (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] == board[4][i] && board[0][i] == board[5][i] && board[0][i] == board[6][i] && board[0][i] != ' ')) {
                    status = 1;
                }
            }
        }
        score = 1;
        //menampilkan pemenang
        if (turn == 1) {
            displayWinner();
            printf("\t\t\t\t\t\tCONGRATS %s, YOU WIN !!\n\n", player[1].nama);
            printf("\t\t\t\t\t\t   Your score : %d", score);
            
        } else {
            displayWinner();
            printf("\t\t\t\t\t\tCONGRATS %s, YOU WIN !!\n\n", player[0].nama);
            printf("\t\t\t\t\t\t   Your score : %d", score);
            
        }
}

int readSelectMenu(int x) {
	scanf("%d", &x);
	return x;
}

void selectMenu(){
    char back;
	printf("\n\n");
	gotoxy (20, 25); printf ("End Game? (Y : yes) : ");

     scanf("%s", &back);
     if(back=='y' || back=='Y') {
        system("cls");
        displayQuit();
    } else {
        printf (" Invalid Input ");
        system ("cls");
        displayWinner();
        selectMenu();
    }    
}