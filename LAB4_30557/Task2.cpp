#include <iostream>

using namespace std;

class Leaderboard {
private:
    int* playerScores;
    int maxSize; 
    int currentPlayers; 

    void expand() {
        int newSize = maxSize * 2;
        int* newScores = new int[newSize];

        for (int i = 0; i < currentPlayers; i++) {
            newScores[i] = playerScores[i]; 
        }

        delete[] playerScores; 
        playerScores = newScores;
        maxSize = newSize;

        cout << "Leaderboard expanded to capacity: " << maxSize << endl;
    }

public:
    Leaderboard(int cap = 4) {
        maxSize = cap;
        playerScores = new int[maxSize];
        currentPlayers = 0;
    }

    ~Leaderboard() {
        delete[] playerScores;
    }

    void addPlayer(int score) {
        if (currentPlayers == maxSize) {
            expand();
        }
        playerScores[currentPlayers++] = score;
        cout << "Player added with score: " << score << endl;
    }

    void updateScore(int index, int newScore) {
        if (index < 0 || index >= currentPlayers) {
            cout << "Invalid player index!" << endl;
            return;
        }
        playerScores[index] = newScore;
        cout << "Score updated for player " << index << ": " << newScore << endl;
    }

    void displayLeaderboard() {
        cout << "Leaderboard:\n";
        for (int i = 0; i < currentPlayers; i++) {
            cout << "Player " << i << ": " << playerScores[i] << endl;
        }
    }
};

int main() {
    Leaderboard leaderboard1;

    leaderboard1.addPlayer(100);
    leaderboard1.addPlayer(200);
    leaderboard1.addPlayer(150);
    leaderboard1.addPlayer(120);
    leaderboard1.addPlayer(180); 

    leaderboard1.displayLeaderboard();

    leaderboard1.updateScore(2, 170);
    leaderboard1.displayLeaderboard();

    return 0;
}