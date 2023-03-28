#include<iostream>
#include"./guessMyNumber.h"
#include"./consoleNumbers.h"


int main(){

    char hwOption{};
    bool runMainHW=true;

    do{
        system("cls");
        std::cout<<"Welcome to Juan Haro Homeworks\nPlease choose an activity:\n";
        std::cout<<"1- End program\n";
        std::cout<<"2.- Guess My number\n";
        std::cout<<"3.- Console numbers\n";

        std::cin>>hwOption;

        switch (hwOption){
        case '1': runMainHW=false;
            break;
        case '2': guessMyNumberMain();
            break;
        case '3': consoleNumbersMain();
            break;
        default: std::cout<<"That option is not available yet\n";
            break;
        }
    } while (runMainHW);
    
    std::cout<<"Thanks for checcking Juan Haro HW\n";
    
    return 0;
}