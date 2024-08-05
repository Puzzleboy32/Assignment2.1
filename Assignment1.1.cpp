/* Gavin Hill
* Assignment 1.1
* 
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Global variable
int totalScore = 0;

// Function to simulate a drive
bool simulateDrive() {
    return (rand() % 2 == 0);
}

// Function to simulate a shot
bool simulateShot() {
    return (rand() % 2 == 0);
}

// Function to simulate a pass
bool simulatePass() {
    return (rand() % 4 != 0); // Return true for successful pass
}

// Function to display game status
void displayGameStatus(int quarter, int score) {
    cout << "Quarter " << quarter << endl;
    cout << "Score: " << score << endl;
    cout << "D - Drive, S - Shoot, P - Pass" << endl;
}

// Function to handle user input
char getUserChoice() {
    char choice;
    cin >> choice;
    return choice;
}

// Function to update score
void updateScore(int points) {
    totalScore += points;
}

int main() {
    srand(time(0));

    int quarter = 1;
    char choice;

    while (quarter <= 4) {
        displayGameStatus(quarter, totalScore);

        choice = getUserChoice();

        switch (choice) {
        case 'D':
            if (simulateDrive()) {
                cout << "Drive successful! You get to shoot." << endl;
                if (simulateShot()) {
                    cout << "Shot made!" << endl;
                    updateScore(2);
                }
                else {
                    cout << "Shot missed!" << endl;
                }
            }
            else {
                cout << "Drive unsuccessful! Turnover." << endl;
            }
            break;
        case 'S':
            if (simulateShot()) {
                cout << "Shot made!" << endl;
                updateScore(2);
            }
            else {
                cout << "Shot missed!" << endl;
            }
            break;
        case 'P':
            if (simulatePass()) {
                cout << "Pass made!" << endl;
            }
            else {
                cout << "Turnover!" << endl;
            }
            break;
        default:
            cout << "Invalid choice." << endl;
        }

        quarter++;
    }

    cout << "Final score: " << totalScore << endl;

    return 0;
}