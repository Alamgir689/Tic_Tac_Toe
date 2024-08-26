#include <bits\stdc++.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <limits>

using namespace std;

char box[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string s1, s2;

int checkwin();
void drawboard();
void exitProgram();
void start();

void gotocr(int col, int row)
{
    COORD coord = {static_cast<SHORT>(col), static_cast<SHORT>(row)};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!SetConsoleCursorPosition(hConsole, coord))
    {
        cerr << "Error: Unable to set cursor position." << endl;
    }
}

int main()
{
    system("title Tic Tac Toe By M.A.Kabir");
    system("color 07");

    gotocr(50, 10);
    cout << "Welcome To Tic Tac Toe\n\n\t\t\t\t\t\t      BY M.A Kabir" << endl;

    Sleep(3000);
    system("cls");
    system("color F2");

    start();

    return 0;
}

void start()
{
    for (int i = 1; i <= 9; ++i)
    {
        box[i] = '0' + i;
    }

    cout << "Enter First Player Name : ";
    cin >> s1;
    cout << "Enter Second Player Name : ";
    cin >> s2;

    int player = 1, i, choice;
    char sign;

    do
    {
        drawboard();
        player = (player % 2) ? 1 : 2;

        if (player == 1)
        {
            cout << player << " : " << s1 << " Enter Your Position: ";
        }
        else
        {
            cout << player << " : " << s2 << " Enter Your Position: ";
        }

        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 9)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 9." << endl;
            player--;
            continue;
        }

        if (box[choice] == '0' + choice)
        {
            sign = (player == 1) ? 'X' : 'O';
            box[choice] = sign;
        }
        else
        {
            cout << "Position already taken or invalid! Choose another position." << endl;
            player--;
        }

        i = checkwin();
        if (i != -1)
            break;
        player++;
    } while (i == -1);

    drawboard();
    system("cls");
    system("color 57");
    gotocr(50, 10);
    cout << "***Congratulations***" << endl;

    if (i == 1)
    {
        cout << "\t\t\t\t\t\t     " << ((player == 1) ? s1 : s2) << " You Won" << endl;
    }
    else
    {
        cout << "\t\t\t\t\t\t     It's a Draw!\n\t\t\t\t\t\t   Better Luck Next Time" << endl;
    }
    Sleep(4400);
    system("cls");
    system("color 75");

    exitProgram();
}

int checkwin()
{
    if (box[1] == box[2] && box[2] == box[3])
    {
        return 1;
    }
    else if (box[4] == box[5] && box[5] == box[6])
    {
        return 1;
    }
    else if (box[7] == box[8] && box[8] == box[9])
    {
        return 1;
    }
    else if (box[1] == box[4] && box[4] == box[7])
    {
        return 1;
    }
    else if (box[2] == box[5] && box[5] == box[8])
    {
        return 1;
    }
    else if (box[3] == box[6] && box[6] == box[9])
    {
        return 1;
    }
    else if (box[1] == box[5] && box[5] == box[9])
    {
        return 1;
    }
    else if (box[7] == box[5] && box[5] == box[3])
    {
        return 1;
    }
    else if (box[1] != '1' && box[2] != '2' && box[3] != '3' && box[4] != '4' && box[5] != '5' && box[6] != '6' && box[7] != '7' && box[8] != '8' && box[9] != '9')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void drawboard()
{
    system("cls");
    cout << endl
         << endl
         << "Tic Tac Toe" << endl
         << endl;
    cout << "Player 1 (" << s1 << "): X - Player 2 (" << s2 << "): O" << endl
         << endl;

    cout << "\t\t\t\t\t\t\t   |   |   " << endl;
    cout << "\t\t\t\t\t\t\t " << box[1] << " | " << box[2] << " | " << box[3] << " " << endl;
    cout << "\t\t\t\t\t\t\t___|___|___" << endl;

    cout << "\t\t\t\t\t\t\t   |   |   " << endl;
    cout << "\t\t\t\t\t\t\t " << box[4] << " | " << box[5] << " | " << box[6] << " " << endl;
    cout << "\t\t\t\t\t\t\t___|___|___" << endl;

    cout << "\t\t\t\t\t\t\t   |   |   " << endl;
    cout << "\t\t\t\t\t\t\t " << box[7] << " | " << box[8] << " | " << box[9] << " " << endl;
    cout << "\t\t\t\t\t\t\t   |   |   " << endl;

    cout << endl
         << "\t\t\t\t\t\tMade and Designed by M_A_Kabir" << endl
         << endl
         << endl
         << endl;
}

void exitProgram()
{
    while (true)
    {
        cout << "Please Choose Your Option.\n If You Want To Leave Please Press (Y/y) : \n If You Want To Play Again Please Press (N/n) : " << endl;
        char permission;
        cin >> permission;

        if (permission == 'y' || permission == 'Y')
        {
            system("cls");
            system("color F2");
            gotocr(50, 10);
            cout << "Thanks For Visiting\n \t\t\t\t\t\t     BY M.A Kabir" << endl;
            getch();
            exit(0);
        }
        else if (permission == 'n' || permission == 'N')
        {
            system("cls");
            start();
        }
        else
        {
            cout << "\nNext time choose after clearly reading the corresponding line.\n"
                 << endl;
        }
    }
}
