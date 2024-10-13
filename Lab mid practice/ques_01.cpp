#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void guessGame(int numberToguess, int currentPlayer, int totalPlayers)
{
    int guess;
    
    cout<<"Player "<<currentPlayer<<", enter you guess(between 1 and 100):";
    cin>>guess;
    
    if(guess == numberToguess)
    {
        cout<<"Player "<<currentPlayer<<" guessed correctly and wins the game"<<endl;
        return;
    }
    else if(guess < numberToguess)
    {
        cout<<"Too low"<<endl;
    }
    else
    {
        cout<<"Too high"<<endl;
    }
    
    int nextPlayer = (currentPlayer + 1) % totalPlayers;
    guessGame(numberToguess, nextPlayer, totalPlayers);
}

void startGame()
{
    srand(time(0));
    
    int numberToGuess = rand() % 100 - 1 + 1 + 1;
    
    int totalPlayers;
    cout<<"Enter the number of total players: "<<endl;
    cin>>totalPlayers;
    
    guessGame(numberToGuess, 1, totalPlayers);
}

int main()
{
    startGame();
    return 0;
}
