#include <iostream>
#include <string>
#include <random>

int guessingGame(int difficulty, int lives){
    std::random_device rd;
    std::uniform_int_distribution<int> r(1,difficulty);
    std::mt19937 gen(rd());
    int randomNumber = r(gen);
    int userGuess;
    while(lives > 0){
        std::cout << "Make your guess: "; 
        std::cin >> userGuess;
        if(userGuess == randomNumber){
            std::cout << "That's right, you got it!" << '\n';
            return 0;
        }
        else if(userGuess > randomNumber){
            std::cout << "Wrong! Try going lower." << '\n';
            lives = lives - 1;
            std::cout << "Lives:" << lives << '\n';
        }
        else if(userGuess < randomNumber){
            std::cout << "Wrong! Try going higher" << '\n';
            lives = lives -1;
            std::cout << "Lives:" << lives << '\n';
        }
    }
    std::cout << "Game over!" << '\n';
    return 0;
}
int main(){
    char gameReady;
    std::string diffInput;
    std::cout << "Do you want to play a game? Y/N" << '\n';
    std::cin >> gameReady;
    if(gameReady == 'Y'){
        std::cout << "Great! Pick a difficulty! Easy/Normal/Hard" << '\n';
        std::cin >> diffInput;
        if(diffInput == "Easy"){
            guessingGame(10,4);
        }
        else if(diffInput == "Normal"){
            guessingGame(100,10);
        }
        else if(diffInput == "Hard"){
            guessingGame(1000,20);
        }
    }
    else{
        std::cout << "Ok...";
        return 0;
    }
    return 0;
}