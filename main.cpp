#include <iostream>
#include <string> // To work with strings in input and output
#include <cstdlib> // Random number generator
#include <ctime> 

using namespace std;

void rules();
int main() {
    string player_name;
    int balance; // storing the player's balance
    int betting_amount;
    int guess;
    int dice; // storing the random number
    char choice;
    srand(time(0)); // seed the random generator
    cout << "\n\t\t========WELCOME TO CASINO ROYAL========\n\n";
    cout << "\n\nWhat's your name? ";
    getline(cin, player_name);
    cout << "\n\nEnter the staring balance to play: $";
    cin >> balance;

    do {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";
        // getting player's balance
        do {
            cout << "Hey " << player_name << ", enter amount to bet: $";
            cin >> betting_amount;
            if (betting_amount > balance){
                cout << "Betting balance can't be more than the current balance!\n" << "\nRe-enter balance\n";
            }
        }
        while (betting_amount > balance);
        // getting player's guess
        do {
            cout << "Guess any betting number between 1 & 10: ";
            cin >> guess;
            if(guess <= 0 || guess > 10){
                cout << "\nNumber should be between 1 and 10\n" << "Re-enter number:\n";
            }
        }
        while (guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        if (dice == guess){
            cout << "\n\nYou are in luck!! You have won $" << betting_amount * 10 << "\n";
            balance = balance + betting_amount * 10;
        } else {
            cout << "Oops, better luck next time!! You lost $" << betting_amount << "\n";
            balance = balance - betting_amount;
        }
        cout << "The winning number was " << dice << "\n";
        cout << "\n" << player_name << ", your balance is $" << balance << "\n";

        if (balance==0){
            cout << "You went bust!\n";
            break;
        }
        cout << "\n\nDo you want to play again (y/n)> ";
        cin >> choice;
    }
    while (choice == 'y'|| choice == 'Y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $" << balance << "\n\n";
    return 0;
}

void rules(){
    system("cls");
    cout << "\t\t======CASINO ROYAL GUESSING RULES======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times the bet amount\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}