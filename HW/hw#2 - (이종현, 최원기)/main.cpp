#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "GamblingGame.h"
using namespace std;

// Player 클래스 구현
Player::Player(string playerName) : name(playerName) {}

string Player::getName() {
    return name;
}

bool Player::generate() {
    int num1 = rand() % 3;
    int num2 = rand() % 3;
    int num3 = rand() % 3;

    cout << "\t\t" << num1 << "\t" << num2 << "\t" << num3 << "\t";

    return (num1 == num2 && num2 == num3);
}

// GamblingGame 클래스 구현
GamblingGame::GamblingGame(string name1, string name2) : players{ Player(name1), Player(name2) } {}

void GamblingGame::startGame() {
    srand(static_cast<unsigned int>(time(0)));
    char enterKey;
    int currentPlayer = 0;

    while (true) {
        cout << players[currentPlayer].getName() << ": <Enter>";
        cin.ignore();
        cin.get(enterKey);

        if (players[currentPlayer].generate()) {
            cout << players[currentPlayer].getName() << "님 승리!!" << endl;
            break;
        }
        else {
            cout << "아쉽군요!\n";
        }

        currentPlayer = (currentPlayer + 1) % 2;
    }
}

// main 함수
int main() {
    string Player1Name, Player2Name;

    cout << "***** 갬블링 게임을 시작합니다. *****" << endl;

    cout << "첫번째 선수 이름>> ";
    cin >> Player1Name;

    cout << "두번째 선수 이름>> ";
    cin >> Player2Name;

    GamblingGame game(Player1Name, Player2Name);

    game.startGame();

    return 0;
}
