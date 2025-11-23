#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

class GameOfLife
{
public:
    GameOfLife();
    void InitGame();
    void NextGeneration();
    void DrawGame();
    int getCurrentGen() { return currentGen; };
    int getMaxGen() { return maxGen; };
    void increaseCurrentGenNbr() { currentGen++; };

private:
    vector<string> grid;
    int width = 20;
    int height = 10;
    int currentGen = 0;
    int maxGen = 10;
};

GameOfLife::GameOfLife()
{
}

void GameOfLife::InitGame() {
    srand(time(0));


    for (int i = 0; i < height; i++) {
        string line = "";
        for (int j = 0; j < width; j++) {
            line += (rand() % 2 == 0) ? '0' : '1';
        }
        grid.push_back(line);
    }
}

void GameOfLife::NextGeneration()
{
    vector<string> newGrid(height, string(width, '0'));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int voisins = 0;

            if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == '1') voisins++;
            if (i - 1 >= 0 && grid[i - 1][j] == '1') voisins++;
            if (i - 1 >= 0 && j + 1 < width && grid[i - 1][j + 1] == '1') voisins++;
            if (j - 1 >= 0 && grid[i][j - 1] == '1') voisins++;
            if (j + 1 < width && grid[i][j + 1] == '1') voisins++;
            if (i + 1 < height && j - 1 >= 0 && grid[i + 1][j - 1] == '1') voisins++;
            if (i + 1 < height && grid[i + 1][j] == '1') voisins++;
            if (i + 1 < height && j + 1 < width && grid[i + 1][j + 1] == '1') voisins++;

            if (grid[i][j] == '1') {
                if (voisins == 2 || voisins == 3) {
                    newGrid[i][j] = '1';
                }
            }
            else {
                if (voisins == 3) {
                    newGrid[i][j] = '1';
                }
            }
        }
    }
    system("cls");
    grid.clear();
    for (int i = 0; i < height; i++) {
        cout << newGrid[i] << endl;
        grid.push_back(newGrid[i]);
    }
    

}


int main()
{
    GameOfLife newGame;

    newGame.InitGame();
    newGame.NextGeneration();

    while (newGame.getCurrentGen() < newGame.getMaxGen())
    {
        newGame.NextGeneration();
        newGame.increaseCurrentGenNbr();
        Sleep(1000);
    }
}
