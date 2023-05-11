#include<iostream>

void DrawInitialState();
void DrawSecondState();
void DrawThirdState();
void DrawFourthState();
void DrawFifthState();
void DrawFinalState();

void DrawHangedMan(int stage){

    switch (stage)
    {
    case 0: DrawInitialState();
        break;
    case 1: DrawSecondState();
        break;
    case 2: DrawThirdState();
        break;
    case 3: DrawFourthState();
        break;
    case 4: DrawFifthState();
        break;
    case 5: DrawFinalState();
    default: std::cout<<"An error has happend";
        break;
    }
}

void DrawInitialState(){
    
    std::cout<<" ___________________________"<<std::endl;
    std::cout<<"  |                      |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;    
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"__|___________________________ "<<std::endl;
}
void DrawSecondState(){
    
    std::cout<<" ___________________________"<<std::endl;
    std::cout<<"  |                      |"<<std::endl;
    std::cout<<"  |                  -------"<<std::endl;
    std::cout<<"  |                 |  O  O |"<<std::endl;
    std::cout<<"  |                 |   __  |"<<std::endl;
    std::cout<<"  |                 |_______|"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;    
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"__|___________________________ "<<std::endl;
}
void DrawThirdState(){
    
    std::cout<<" ___________________________"<<std::endl;
    std::cout<<"  |                      |"<<std::endl;
    std::cout<<"  |                  -------"<<std::endl;
    std::cout<<"  |                 |  o  O |"<<std::endl;
    std::cout<<"  |                 |   __  |"<<std::endl;
    std::cout<<"  |                 |_______|"<<std::endl;
    std::cout<<"  |                     |"<<std::endl;
    std::cout<<"  |                     |"<<std::endl;
    std::cout<<"  |                     |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;    
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"__|___________________________ "<<std::endl;
}
void DrawFourthState(){
    
  std::cout<<" ___________________________"<<std::endl;
    std::cout<<"  |                      |"<<std::endl;
    std::cout<<"  |                  -------"<<std::endl;
    std::cout<<"  |                 |  -  O |"<<std::endl;
    std::cout<<"  |                 |   __  |"<<std::endl;
    std::cout<<"  |                 |_______|"<<std::endl;
    std::cout<<"  |                     |"<<std::endl;
    std::cout<<"  |                   \\ | /"<<std::endl;
    std::cout<<"  |                    \\|/"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;    
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"__|___________________________ "<<std::endl;
}
void DrawFifthState(){
    
    std::cout<<" ___________________________"<<std::endl;
    std::cout<<"  |                      |"<<std::endl;
    std::cout<<"  |                  -------"<<std::endl;
    std::cout<<"  |                 |  -  o |"<<std::endl;
    std::cout<<"  |                 |   __  |"<<std::endl;
    std::cout<<"  |                 |_______|"<<std::endl;
    std::cout<<"  |                     |"<<std::endl;
    std::cout<<"  |                   \\ | /"<<std::endl;
    std::cout<<"  |                    \\|/"<<std::endl;
    std::cout<<"  |                     |"<<std::endl;
    std::cout<<"  |                     |"<<std::endl;    
    std::cout<<"  |                     |"<<std::endl;
    std::cout<<"  |                    / \\"<<std::endl;
    std::cout<<"  |                   /   \\"<<std::endl;
    std::cout<<"  |                  /     \\"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"__|___________________________ "<<std::endl;
}
void DrawFinalState(){
    
  std::cout<<" ___________________________"<<std::endl;
    std::cout<<"  |                      |"<<std::endl;
    std::cout<<"  |                  -------"<<std::endl;
    std::cout<<"  |                 |  x  X |"<<std::endl;
    std::cout<<"  |                 |   __  |"<<std::endl;
    std::cout<<"  |                 |_______|"<<std::endl;
    std::cout<<"  |                     |"<<std::endl;
    std::cout<<"  |                   \\ | /"<<std::endl;
    std::cout<<"  |                    \\|/"<<std::endl;
    std::cout<<"  |                     |"<<std::endl;
    std::cout<<"  |                     |"<<std::endl;    
    std::cout<<"  |                     |"<<std::endl;
    std::cout<<"  |                    / \\"<<std::endl;
    std::cout<<"  |                   /   \\"<<std::endl;
    std::cout<<"  |                  /     \\"<<std::endl;
    std::cout<<"  |"<<std::endl;
    std::cout<<"__|___________________________ "<<std::endl;
}
void winState(){

    std::cout<<"                    -------"<<std::endl;
    std::cout<<"                   |  O  O |"<<std::endl;
    std::cout<<"                   |    w  |"<<std::endl;
    std::cout<<"                   |_______|"<<std::endl;
    std::cout<<"                       |"<<std::endl;
    std::cout<<"                     \\ | /"<<std::endl;
    std::cout<<"                      \\|/"<<std::endl;
    std::cout<<"                       |"<<std::endl;
    std::cout<<"                       |"<<std::endl;    
    std::cout<<"                       |"<<std::endl;
    std::cout<<"                      / \\"<<std::endl;
    std::cout<<"                     /   \\"<<std::endl;
    std::cout<<"                    /     \\"<<std::endl;
    std::cout<<"  "<<std::endl;
}