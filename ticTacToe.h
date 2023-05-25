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
bool checkWin(int playerLastChoice, char board[COLUMNS][ROWS]);


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
        if(turnNumber>4){
            hasWin = checkWin(pickedBox, gameBoard);
            turnNumber--;
        }
        turnNumber++;
        
    }while(turnNumber<10 && !hasWin);
    
    std::cout<<"\nFinal board"<<std::endl;
    DrawBoard(gameBoard);
    if(hasWin){
        std::cout<<"And "<< actualPlayer << " WINS!!!"<<std::endl<<std::endl;
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

bool checkWin(int playerLastChoice, char board[COLUMNS][ROWS]){
    
    int x = playerLastChoice/3;
    int y = playerLastChoice%3;
    bool won = false;

    if(board[x][0] == board[x][1] && board[x][0] == board[x][2]){
        won = true;
    }
    if(board[0][y] == board[1][y] && board[0][y] == board[2][y]){
        won = true;
    }
    if(playerLastChoice == 0  || playerLastChoice == 4 || playerLastChoice == 8){
        if(board[0][0]== board[1][1] && board[0][0] == board[2][2]){
            won =  true;
        }
    }
    if( playerLastChoice == 2 || playerLastChoice == 4 || playerLastChoice == 6 ){
        if(board[2][0]== board[1][1] && board[0][0] == board[0][2]){
            won = true;
        }
    }

    return won;
}