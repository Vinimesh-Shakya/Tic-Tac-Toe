/**********************************************                   Tic-Tac-Toe  2-PLAYER                     *********************************************/


#include<iostream>
using namespace std;
void showboard(char board[3][3])      //  Function to print current board
{
    for(int i=0;i<3;i++)
    {
        cout<<"-------------------------------------------------\n";
        for(int j=0;j<3;j++)
        {   
            cout<<"\t"<<board[i][j]<<"\t|";
        }
        cout<<endl;
    }
    cout<<endl;
}
int CheckWin(char board[3][3])     // function to check if anyone win in current turn
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]=='X'&&board[i][1]=='X'&&board[i][2]=='X')// horizontal win
        return 1;
        if(board[0][i]=='X'&&board[1][i]=='X'&&board[2][i]=='X')// vertical win
        return 1;
        if(board[i][0]=='O'&&board[i][1]=='O'&&board[i][2]=='O')// horizontal win
        return 2;
        if(board[0][i]=='O'&&board[1][i]=='O'&&board[2][i]=='O')// vertical win
        return 2;
    }
    if(board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X') //   \  win
    return 1;
    if(board[0][2]=='X'&&board[1][1]=='X'&&board[2][0]=='X') //   /  win
    return 1;
    if(board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O') //   \  win
    return 2;
    if(board[0][2]=='O'&&board[1][1]=='O'&&board[2][0]=='O') //   /  win
    return 2;
    else
    return 0;
}

void UserTurn(char board[3][3], char player)      // Function for user turn- to place respective O/X
{
    int user_input;
    cout<<"User "<<player<<" turn : ";
    cin>>user_input;
    if(user_input > 9 || user_input < 1)
    {
        cout<<"Invalid Input!";
        UserTurn(board,player);
    }
    if((board[(user_input-1)/3][(user_input-1)%3]=='X' ) || (board[(user_input-1)/3][(user_input-1)%3]=='O'))
    {
        cout<<"Block already Occupied! Try another!\n";
        UserTurn(board,player);
    }
    else
    {
        board[(user_input-1)/3][(user_input-1)%3]=player;
    }
}



/****************************************************               MAIN                 ********************************************************/
int main()
{
    // Initialize Board
    char board[3][3] = {{'.','.','.'},
                        {'.','.','.'},
                        {'.','.','.'}};// game board
//
    int count =1;
    // Draw Board for UI
    // For players to remember board blocks
    for(int i=0;i<3;i++)
    {
        cout<<"-------------------------------------------------\n";
        for(int j=0;j<3;j++)
        {   
            cout<<"\t"<<count++<<"\t|";
        }
        cout<<endl;
    }
    cout<<"WELCOME TO TIC-TAC-TOE !\n";
    char player1 = 'X';
    char player2 = 'O';
    showboard(board);
    // game loop
    for(int i=0;i<9;i++)
    {
        if(i == 8)
        {
            showboard(board);
            cout<<"Draw! Try again!";
        }
        UserTurn(board,player1);
        showboard(board);
        if(CheckWin(board) == 1)
        {
            showboard(board);
            cout<<"User X WIN!!\n";
            break;
        }
        else if(CheckWin(board) == 2)
        {
            showboard(board);
            cout<<"User O WIN!!\n";
            break;
        }
        UserTurn(board,player2);
        showboard(board);
        int win ;
        if(CheckWin(board) == 1)
        {
            showboard(board);
            cout<<"User X WIN!!\n";
            break;
        }
        else if(CheckWin(board) == 2)
        {
            showboard(board);
            cout<<"User O WIN!!\n";
            break;
        }
    }
    return 0;
}
