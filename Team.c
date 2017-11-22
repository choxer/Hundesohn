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
    do{} while( !getText("Teamname", 25, 0, &(Teams[TeamCounter].Teamn) ) );

    //printf("%s", newTeam->Teamn);
    //trainername
    do{} while( !getText("Trainername", 25, 1, &(Teams[TeamCounter].Coach) ) );

    //anzahl spieler
    (Teams[TeamCounter]).AnzPlayer = 0;

    //TeamCounter++;

    printf("Bitte Eingaben mit Enter bestaetigen!\n");
    WaitForEnter();
    do
    {
        TPlayer *newPlayer;
        newPlayer = malloc(sizeof(TPlayer));

        if ( newPlayer == NULL )
        {
            printf("ERROR:SPEICHERRESERVIERUNG NEWPLAYER");
        }
        else
        {
            addPlayer();
            Teams[TeamCounter].AnzPlayer++;
        }
        free(newPlayer);
    } while( askYesorNo("Wollen sie noch einen Spieler anlegen?") );
}

void deleteTeam(void)
{
    printf("deleteTeam\n");
}

void addPlayer(void)
{
//    int *AnzPlay = (TeamCounter[TeamCounter]).AnzPlayer;

    clearScreen();
    //MenuTitel
    printf("Erfassung eines neuen Spielers\n");
    printline('-',strlen("Erfassung eines neuen Spielers"));

    //Spielername
    do{} while( !getText("Spielername",30,0,&(Teams[TeamCounter].Player[(Teams[TeamCounter]).AnzPlayer].Playern)) );

    //Birthday
    do{} while( !getDate("Geburtsdatum") );
    //Trikonummer
    do{} while ( !getNumber("Trikotnummer",0, &(Teams[TeamCounter].Player[(Teams[TeamCounter]).AnzPlayer].Trikotn),1,99) );
    //Goals

    //(Teams[TeamCounter]).AnzPlayer++;
    printf("Bitte Eingaben mit Enter bestaetigen!\n");
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

void listTeams(void)
{
    int i = 1;

    clearScreen();

    for(i=1; i<=TeamCounter; i++)
    {
        listOneTeam(i);
    }
}

void listOneTeam(int i)
{
    int j = 1;
    int k = 1;

    printf("Name            : %s\n", Teams[i].Teamn);
    printf("Trainer         : %s\n", Teams[i].Coach);
    printf("Anzahl Spieler  : %i\n", Teams[i].AnzPlayer);
    printf("Spieler:\n");

    for(j=1; j<=Teams[i].AnzPlayer; j++)
    {
        listOnePlayer(k, i);
        k++;
    }
}

void listOnePlayer(int k, int i)
{
    printf("%i. %s (%i; * ", k, Teams[i].Player[k].Playern, Teams[i].Player[k].Trikotn);
    //printDate( *(Teams[i].Player[k]).Birthday);
    printf(")\n");
}

void endprog(void){
    printf("Programmende\n");
}

