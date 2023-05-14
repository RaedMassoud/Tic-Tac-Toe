#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void DoubleDown();
void Bullet();
int timer();
bool gameover();
void display_board();
void player_turn();
void GameRules(int);
using namespace std;

// Array for display board and game logic board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
string fake_board[3][3] = {{"player_0", "player_0", "player_0"},{"player_0","player_0","player_0"},{"player_0","player_0","player_0"}};

// Variable Declaration
int choice, option, menu;
int row,column;
int DoubleDown_X = 1, DoubleDown_O = 1;
char turn = 'X';
bool draw = false, timer_out = false, force_exit = false, EasterEgg;


// Program Main
int main()
{
    do {

        // Reset all necessary elements
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                fake_board[x][y] = "player_0";
            }
        }
        board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
        board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
        board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9'; 

        force_exit = false;
        DoubleDown_O = 1;
        DoubleDown_X = 1;
        EasterEgg = false;

        // Display Menu
        system("clear||cls");
        cout<<"\t\t\t\t   TIC TAC TOE\t\t\t\t" << 
        "\n\nMenu\n----\n\n" <<
        "1) Bullet Tik Tac Toe\n" <<
        "2) Double Down Tik Tac Toe\n" <<
        "3) Exit\n\n>> ";
        cin >> menu;

        switch(menu) {
            case 1: GameRules(menu); 
                    if(EasterEgg)
                        return 0;
                    Bullet(); break;
            case 2: GameRules(menu); 
                    if(EasterEgg)
                        return 0;
                        DoubleDown(); break;
            case 3: return 0; break;

            default: cout << "Invalid input" << endl;
        }
    }while(menu != 3);

    system("pause");
    return 0;
} 

// Game rules
void GameRules(int menu) {
    int x, y, z;
    system("clear||cls");
    if(menu == 1) {
        cout << "\t\t\t\tBullet TIC TAC TOE\t\t\t\t\n\n" <<
        "Rules: Standard Tic Tac Toe rules apply with the addition of a timer.\n" << endl;
    } else
        cout << "\t\t\t     Double Down TIC TAC TOE\t\t\t\t\n\n" <<
        "Rules:\n- Your opponent has the ability to take a possition you already choose\n" <<
        "- You are then granted the ability to DOUBLE DOWN on that posssition or give it up for good!\n" << endl;

    cout << "Press enter to start ";
    system("pause > null");

    system("clear||cls");
    cout << "To decide to plays first each player will pick a number between 1 - 10.\n" <<
    "I have generated a number in that range as well and whoever picks closer to me wins!\n\n" <<
    "First number: ";

    bool notfirsttime = false;
    do {
        if(notfirsttime)
            cout << "Invalid! Number must be between 1 - 10: ";
        cin >> x;
        notfirsttime = true;
    }while(x < 1 || x > 10);

    notfirsttime = false;
    cout << "Second number: ";

    do {
        if(notfirsttime)
            cout << "Invalid! Number must be between 1 - 10: ";
        cin >> y;
        notfirsttime = true;
    }while(y < 1 || y > 10);

    srand(time(0));
    z = rand() % 10 + 1;

    if(x == y) {
        system("cls||clear");
        cout << "Hehehehe you two picked the same number!\n" <<
        "I don't want to play with you anymore\n\n";
        system("pause");
        EasterEgg = true;
        return;
    }

    cout << "My number is: " << z << endl;

    if(x > z)
        x -= z;
    else
        x = z - x;

    if(y > z)
        y -= z;
    else
        y = z - y;

    if(x > y)
        cout << "Second number has won\n";
    else
        cout << "First number has won\n";

    cout << "Press enter to start ";
    system("pause > null");

}

// Bullet mode Tic Tac Toe
void Bullet() {

    while(!gameover()) {
    gameover();
    display_board();
    player_turn();
    if(force_exit)
        break;
    }

    // Force Exit
    if(force_exit) {
        system("cls||clear");
        display_board();
        cout <<"\n\nPlayer forced an exit\n\n" <<
        "Press Enter to go back to menu ";
        system("pause > null");
        return;
    }

    // X has won
    if(turn != 'X' && draw == false){
        system("cls||clear");
        display_board();
        cout<<"\n\nCongratulations! Player 1 has won the game\n\n" <<
        "Press Enter to go back to menu ";
        system("pause > null");
        return;
    }
    
    // O has won
    else if(turn != 'O' && draw == false){
        system("cls||clear");
        display_board();
        cout<<"\n\nCongratulations! Player 2 has won the game\n\n" <<
        "Press Enter to go back to menu ";
        system("pause > null");
        return;
    }

    else // Game draw
    cout<<"\n\nGAME DRAW!!!\n\n" <<
    "Press Enter to go back to menu ";
    system("pause > null");
    return;
}

// Game mode 2
void DoubleDown() {

    while(!gameover()) {
    gameover();
    display_board();
    player_turn();
    if(force_exit)
        break;
    }

    // Force Exit
    if(force_exit) {
        system("cls||clear");
        display_board();
        cout <<"\n\nPlayer forced an exit\n\n" <<
        "Press Enter to go back to menu ";
        system("pause > null");
        return;
    }

        // X has won
    if(turn != 'X' && draw == false){
        system("cls||clear");
        display_board();
        cout<<"\n\nCongratulations! Player 1 has won the game\n\n" <<
        "Press Enter to go back to menu ";
        system("pause > null");
        return;
    }
    
    // O has won
    else if(turn != 'O' && draw == false){
        system("cls||clear");
        display_board();
        cout<<"\n\nCongratulations! Player 2 has won the game\n\n" <<
        "Press Enter to go back to menu ";
        system("pause  > null");
        return;
    }

    else // Game draw
    cout<<"\n\nGAME DRAW!!!\n\n" <<
    "Press Enter to go back to menu ";
    system("pause > null");
    return;
}

//Function to show the current status of the gaming board

void display_board(){

    system("clear||cls");
    if(menu == 2) {
        cout << "\t\t\t     Double Down TIC TAC TOE\t\t\t\t\n\n" <<endl;
    }else
        cout << "\t\t\t\tBullet TIC TAC TOE\t\t\t\t\n\n" << endl;

    cout<<"\n\n\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"\n";
    cout<<"\t\t\t\t     |     |     \n";
}

// Function to get the player input and update the board
void player_turn(){
    
    timer_out = false;
    gameover();

    // Double Down times display
    if(turn == 'X' && menu == 2) {
        cout <<"\nDouble Down X: " << DoubleDown_X << endl;
    } else if(turn == 'O' && menu == 2) 
        cout <<"\nDouble Down O: " << DoubleDown_O << endl;

    // take input from the user accordingly.
    if(turn == 'X'){
        cout<<"\nPlayer 1 [X] turn (Press 0 to force exit): ";
    }
    else if(turn == 'O'){
        cout<<"\nPlayer 2 [O] turn (Press 0 to force exit): ";
    }

    if(menu == 1)
       choice = timer() - 48;
    else
        cin >> choice;
    
    if(timer_out)
        return;

    if(choice == 0) {
        force_exit = true;
        return;
    }

    if(menu == 2)
        option = 3;
    else
        option = 4; // Auto set for Bullet Tic Tac Toe
    
    // switch operator to set row and column values in line with input.
    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    // Switch operator for object choice
    switch(option) {

        case 3:
        if(turn == 'X' &&
        fake_board[row][column] == "player_0") {

        // update position and swtich turn to o
        board[row][column] = 'X';
        fake_board[row][column] = "player_X";
        turn = 'O';

        }else if(fake_board[row][column] == "player_O" &&
        DoubleDown_X > 0) {

            DoubleDown_X--;
            board[row][column] = 'X';
            fake_board[row][column] = "player_X";
            turn = 'O';

        }   else if(turn == 'O') {
            if(fake_board[row][column] == "player_0") {

        // update position and swtich turn to x
        board[row][column] = 'O';
        fake_board[row][column] = "player_O";
        turn = 'X';
            } else if(fake_board[row][column] == "player_X" &&
            DoubleDown_O > 0) {
                DoubleDown_O--;
                board[row][column] = 'O';
                fake_board[row][column] = "player_O";
                turn = 'X';
            }

        }   else {

        // if invalid
        cout<<"Invalid move!\nPlease choose another!!\n\n";
        player_turn();
        }
        break;

        // Case for Bullet Tic Tac Toe
        case 4:
        if(turn == 'X' && fake_board[row][column] == "player_0") {

        // update position and switch turn       
        board[row][column] = 'X';
        fake_board[row][column] = "player_X";
        turn = 'O';

        }   else if(turn == 'O' && fake_board[row][column] == "player_0") {

        // update position and swtich turn
        board[row][column] = 'O';
        fake_board[row][column] = "player_O";
        turn = 'X';
        }   else {

        // if invalid
        cout<<"Invalid move!\nPlease choose another!!\n\n";
        player_turn();
        }
        break;
    }
}

// timer for input in bullet mode
int timer() {

    DWORD start_time, check_time;
    start_time = GetTickCount();
    check_time = start_time+5000;

    // Check for keypresses while timer > 0
    while((check_time>GetTickCount()))
    {
        if (kbhit()) {
            choice = getch();
            if (choice == 49 || choice == 50 ||
                choice == 51 || choice == 52 ||
                choice == 53 || choice == 54 ||
                choice == 55 || choice == 56 ||
                choice == 57)
                cout << "Choice returned" << endl;
                return choice;
        }
    }
    cout<<"Time-out: 5 seconds"<<endl;

    if(turn == 'X')
        turn = 'O';
    else
        turn = 'X'; 

    cout << "Reached return 0" << endl;
    timer_out = true;
    return 0;
}

// function to determine when game is over ( X wins / O wins / Draw ).
bool gameover(){

    // check simple row for X
    for(int i=0; i<3; i++)
    if(fake_board[i][0] == "player_X" &&
    fake_board[i][1] == "player_X" &&
    fake_board[i][2] == "player_X" ||
    fake_board[0][i] == "player_X" &&
    fake_board[1][i] == "player_X" &&
    fake_board[2][i] == "player_X")
    return true;

    // check simple row for O
    for(int i=0; i<3; i++)
    if(fake_board[i][0] == "player_O" &&
    fake_board[i][1] == "player_O" &&
    fake_board[i][2] == "player_O" ||
    fake_board[0][i] == "player_O" &&
    fake_board[1][i] == "player_O" &&
    fake_board[2][i] == "player_O")
    return true;

    // check both diagonal for X
    if(fake_board[0][0] == "player_X" &&
    fake_board[1][1] == "player_X" &&
    fake_board[2][2] == "player_X" ||
    fake_board[0][2] == "player_X" &&
    fake_board[1][1] == "player_X" &&
    fake_board[2][0] == "player_X")
    return true;

    // check both diagonal for O
    if(fake_board[0][0] == "player_O" &&
    fake_board[1][1] == "player_O" &&
    fake_board[2][2] == "player_O" ||
    fake_board[0][2] == "player_O" &&
    fake_board[1][1] == "player_O" &&
    fake_board[2][0] == "player_O")
    return true;

    // game can't be over if players still have ability to double down.
    if(menu == 2) {
        if(DoubleDown_O != 0 ||
        DoubleDown_X != 0) {
        return false; }
    }

    // If players can no longer double down AND all positions are taken => game must be draw.
    if(DoubleDown_O == 0 &&
    DoubleDown_X == 0) {
        for(int i=0; i<3; i++)
        if(fake_board[i][0] == "player_0" ||
        fake_board[i][1] == "player_0" ||
        fake_board[i][2] == "player_0" ||
        fake_board[0][i] == "player_0" ||
        fake_board[1][i] == "player_0" ||
        fake_board[2][i] == "player_0")
            return false;
        }

    for(int i=0; i<3; i++)
    if(menu == 1 &&
    fake_board[i][0] == "player_0" ||
    fake_board[i][1] == "player_0" ||
    fake_board[i][2] == "player_0" ||
    fake_board[0][i] == "player_0" ||
    fake_board[1][i] == "player_0" ||
    fake_board[2][i] == "player_0")
        return false;

    // if none of the above returns false then game must be a draw.
    draw = true;
    return true;

}
