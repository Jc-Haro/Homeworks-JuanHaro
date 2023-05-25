#include<iostream>
#include"./guessMyNumber.h"
#include"./consoleNumbers.h"
#include"./rockPapersScissors.h"
#include"./guessMyWord.h"
#include"./ hangedManGame.h"
#include"./ticTacToe.h"

int main(){

    char hwOption{};
    bool runMainHW=true;

    do{
        std::cout<<"Welcome to Juan Haro Homeworks\nPlease choose an activity:\n";
        std::cout<<"1.- End program\n";
        std::cout<<"2.- Guess My number\n";
        std::cout<<"3.- Console numbers\n";
        std::cout<<"4.- Rock Paper Scissors\n";
        std::cout<<"5.- Order my word\n";
        std::cout<<"6.- Hanged Man Game\n";
        std::cout<<"7.- TicTacToe\n";

        std::cin>>hwOption;

        switch (hwOption){
        case '1': runMainHW=false;
            break;
        case '2': guessMyNumberMain();
            break;
        case '3': consoleNumbersMain();
            break;
        case '4': rpsMain();
            break;
        case '5': guessMyWordMain();
            break;
        case '6': hangedManGameMain();
            break;
        case '7': ticTacToeMain();
            break;
        default: std::cout<<"That option is not available yet\n";
            break;
        }
    } while (runMainHW);
    
    std::cout<<"Thanks for checking Juan Haro HW\n";
    
    return 0;
}