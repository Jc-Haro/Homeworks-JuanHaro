#include<iostream>
#include<time.h>
#include<stdlib.h>
#if _WIN32
#include<Windows.h> 
#else
#include<unistd.h>
#endif
std::string attempMessage();
const int maxRange=200;//Determines the max range of guessing which goes from 1-maxRange
const int howClose=3;//Determines the range to tell if guess is close to the random number

//By Juan Carlos Haro Romo
void guessMyNumberMain() {

    //insigend int uses only positive numbers optimazing space 
    srand(static_cast<unsigned int>(time(0)));


    int myguess = 0;
    bool run = true;
    do {
        //Generate a number between 0-maxRange each time game starts 
        int mynumb = (rand() % maxRange) + 1; system("cls");
        int attempCounter = 0;
        std::cout << "Bienvenido a adivina mi numero\n";


        system("pause");
        do {
            system("Color 07");
            system("cls");
            attempCounter++;
            do {
                std::cout << "Adivina mi numero del 1 al "<<maxRange<<"\nDigite un numero:\n" << "\n";
                std::cin >> myguess;
                //Checks if the guess number is between 1-maxRange
                if (myguess > maxRange || myguess < 1) {
                    std::cout << "El numero esta entre 1 y "<<maxRange<<"\nDigita un numero en dicho rango\n";
                    system("pause");
                    system("cls");
                }
            } while (myguess > maxRange || myguess < 1);

            //Checking guees and number
            if (myguess > mynumb) {
                system("cls");
                system("Color 0B");
                std::cout << "Mi numero es menor que " << myguess << "\n";
                if (myguess <= mynumb + howClose) {
                    std::cout << "Pero esta muy cerca a " << myguess << "\n";
                }
                std::cout << attempMessage();
                system("pause");
            }
            else if (myguess < mynumb) {
                system("cls");
                system("Color 0D");
                std::cout << "Mi numero es mayor que " << myguess << "\n";
                if (myguess >= mynumb - howClose ) {
                    std::cout << "Pero esta muy cerca a " << myguess << "\n";
                }
                std::cout << attempMessage();
                system("pause");
            }

        } while (mynumb != myguess);

        system("cls");


        //Special 7 or less attemps victory screen
        if (attempCounter < 8) {
            std::cout << "||***************************************************************||\n||***Felicidades adivinaste el numero en 7 intententos o menos***||\n||***************************************************************||\n||***********************Tus intentos: " << attempCounter << "*************************||\n||***************************************************************||\n";//This hurts A LOT, but looks cool

            for (int j = 0; j < 2; j++) {
                for (int i = 1; i < 12; i++) {
                    switch (i) {
                    case 1: system("Color 01");
                        break;
                    case 2: system("Color 02");
                        break;
                    case 3: system("Color 03");
                        break;
                    case 4: system("Color 04");
                        break;
                    case 5: system("Color 05");
                        break;
                    case 6: system("Color 06");
                        break;
                    case 7: system("Color 09");
                        break;
                    case 8: system("Color 0A");
                        break;
                    case 9: system("Color 0B");
                        break;
                    case 10: system("Color 0C");
                        break;
                    case 11: system("Color 0D");
                        break;
                    default: std::cout << "ERROR";
                        break;
                    }
                    sleep(500);
                }
            }
            system("Color 07");
        }
        //Regular victory screen
        else {
            std::cout << "||***Felicidades adivinaste el numero en " << attempCounter << " intentos***||\nCrees poder hacerlo en 7 o menos?\n";
        }

        system("pause");
    } while (run);


}

std::string attempMessage() {
    srand(time(NULL));
    int randMDM = (rand() % 9) + 1;
    switch (randMDM) {
    case 1: return "Seguro que puedes lograrlo\n";
        break;
    case 2: return "No es tan facil eh?\n";
        break;
    case 3: return "Superado por una maquina, ja\n";
        break;
    case 4: return "Pero no lo adivinaste\n";
        break;
    case 5: return "No le atinas?\n";
        break;
    case 6: return "Listo para rendirte?\n";
        break;
    case 7: return "Problemas de habilidad\n";
        break;
    case 8: return "Mejora e intentalo de nuevo\n";
        break;
    case 9: return "Aun no puedes\n";
        break;
    case 10: return "Vamos que se puede\n";
        break;
    default:return "Algo salio mal xd?\n";
        break;
    }
}