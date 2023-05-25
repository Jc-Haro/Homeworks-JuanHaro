#include<iostream>
#include<string>
#include <sstream>
#include<vector>


const int ROWS = 3;
const int COLUMNS = 3;
const char player1 = 'x';
const char player2 = 'o';


void DrawBoard(char board[ROWS][COLUMNS]);
int getPlayerInput(std::vector<int> & availableBoxes);
int  checkValidInput();
bool checkDigit(char check);
void checkWin(bool & hasWon, int lastPlayerInput,char board[ROWS][COLUMNS]);



void ticTacToeMain(){

    std::vector<int> availableBoxes = {0,1,2,3,4,5,6,7,8,9};
    char gameBoard [ROWS][COLUMNS] = {{'0','1','2'},{'3','4','5'},{'6','7','8'}};
    int turnNumber = 1;
    bool hasWin = false;
    char actualPlayer{};
    int pickedBox;

    do{
        DrawBoard(gameBoard);
        actualPlayer = turnNumber%2==0? player1 : player2;
        std::cout<<std::endl<<"Is "<<actualPlayer<<" turn"<<std::endl;
        pickedBox =  getPlayerInput(availableBoxes);
        gameBoard[pickedBox/3][pickedBox%3] = actualPlayer;
        if(turnNumber>5){
            //checkWin(hasWin,pickedBox, gameBoard);
        }
        turnNumber++;
        
    }while(turnNumber<10 && !hasWin);
    
    std::cout<<"\nFinal board"<<std::endl;
    DrawBoard(gameBoard);
    if(hasWin){
        actualPlayer = (turnNumber-1)%2==0? player1 : player2;
        std::cout<<"And "<< actualPlayer << " WINS!!!";
    }
    else{
        std::cout<<"And its a Draw!!!"<<std::endl<<std::endl;
    }
    
    

}

void DrawBoard(char board[ROWS][COLUMNS]){
    
    std::cout<<std::endl;

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){    
            std::cout<<" "<<board[i][j];
        }
        std::cout<<std::endl;
    }
}

int getPlayerInput(std::vector<int> & availableBoxes){
    
    int temporalPlayerInput{};
    bool isBoxedUsed = true;
    int spaceToErase{};

    std::cout<<"Pick a box: ";

    do{
        temporalPlayerInput = checkValidInput();
        for(int i = 0; i<availableBoxes.size(); i++){
            if(availableBoxes[i]==temporalPlayerInput){
                isBoxedUsed = false;
                spaceToErase = i;
            }
        }
        if(isBoxedUsed){
            std::cout<<"That boxed is already used"<<std::endl;
        }

    }while(isBoxedUsed);

    availableBoxes.erase(availableBoxes.begin() + spaceToErase);

    return temporalPlayerInput;
    
}

int  checkValidInput(){

    std::string temporalPlayerInput{};
    bool isValid = false;
   
    do{
        
       std::cin>>temporalPlayerInput;
       isValid = checkDigit(temporalPlayerInput[0]);
       if(!isValid){
        std::cout<<"Invalid input"<<std::endl;
       }

    }while(!isValid);

    return int(temporalPlayerInput[0]-48);
}



bool checkDigit(char check){
    return check == '0' ||check == '1' ||check == '2' ||check == '3' ||check == '4' ||check == '5' ||check == '6' ||check == '7' ||check == '8' ||check == '9';
}

void checkWin(bool & hasWon, int lastPlayerInput, char board[ROWS][COLUMNS]){
    switch (lastPlayerInput)
    {
        case 0 : 
        //Finished
            if((board[0][0]==board[0][1] && board[0][0] == board[0][2]) || (board[0][0]==board[1][0] && board[0][0] == board[2][0]) || (board[0][0]==board[1][1] && board[0][0]==board[2][2])){
                hasWon = true;
            }
            break;
        case 1 : 
            break;
        case 2 : 
        //Finished
            if((board[0][2]==board[0][1] && board[0][2] == board[0][0]) || (board[0][2]==board[1][2] && board[0][2] == board[2][2]) || (board[0][2]==board[1][1] && board[0][2]==board[2][0])){
                hasWon = true;
            }
            break;
        case 3 : 
            break;
        case 4 : 
            break;
        case 5 : 
            break;
        case 6 : 
        //Finished
            if((board[2][0]==board[2][1] && board[2][0] == board[2][2]) || (board[2][0]==board[1][0] && board[2][0] == board[0][0]) || (board[2][0]==board[1][1] && board[0][2])){
                hasWon = true;
            }
            break;
        case 7 : 
            break;
        case 8 : 

            if((board[2][2]==board[2][1] && board[2][2] == board[2][0]) || (board[2][2]==board[1][2] && board[2][2] == board[0][2]) || (board[2][2]==board[1][1] && board[2][2] == board[0][0])){
                hasWon = true;
            }
            break;
        case 9 : 
            break;
        default: std::cout<<"That's something unexpected\nAn error has occur"<<std::endl;
            break;
    }
}