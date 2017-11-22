#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Team.h"
#include "tools.h"
#include "datetime.h"


extern int TeamCounter;     //Deklaration von globalen variabeln,
extern TTeam Teams[MAXTEAM];


//---------------------Funktionen-----------------------------------------//




void createTeam(void){

    clearScreen();
    printf("Erfassung einer neuen Mannschaft\n");
    printline('-',strlen("Erfassung einer neuen Mannschaft"));


    TTeam *newTeam = (Teams+TeamCounter);

    newTeam=malloc(sizeof(TTeam));
    TeamCounter++;


    //printf("%i",newTeam->AnzPlayer);

    //Teamname
    getText("Teamname: ", 25, 0, &((Teams+TeamCounter)->Teamn) );
    //printf("%s", newTeam->Teamn);
    //trainername
    getText("Trainername: ", 25, 1, &((Teams+TeamCounter)->Coach) );
    //anzahl spieler
    (Teams+TeamCounter)->AnzPlayer = 0;


    //TTeam Team+TeamCounter;

}

void deleteTeam(void){

    printf("deleteTeam\n");

}

void addPlayer(void)
{
    char strdate[20];

    clearScreen();
    //MenuTitel
    printf("Erfassung eines neuen Spielers\n");
    printline('-',strlen("Erfassung eines neuen Spielers"));

    //Spielername
    do{} while( !getText("Spielername",30,0,&((Teams+TeamCounter)->Player->Playern)) );
    //Birthday
    do{} while( !getDate("Geburtsdatum") );
    //Trikonummer
    do{} while ( !getNumber("Trikotnummer",0, &((Teams+TeamCounter)->Player->Trikotn),1,99) );
    //Goals

}

void deletePlayer(void){

    printf("deletePlayer\n");

}

void searchPlayer(void){

    printf("searchPlayer\n");

}

void sortTeams(void){

    printf("sortTeams\n");

}

void listTeams(void){

    printf("listTeams\n");

}

void endprog(void){
    printf("Programmende\n");
}

