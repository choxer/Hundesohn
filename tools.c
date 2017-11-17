#include "tools.h"


void clearScreen(void)
{
    system("CLS");
};

int askYesorNo(char strQuestion[])
{
    clearBuffer();
    char Input;

    do{

        printf("%s\n",strQuestion);

        scanf("%c",&Input);



        if(Input=='y'||Input=='Y'||Input=='j'||Input=='J')
        return 1;

        if(Input=='n'||Input=='N')
        return 0;

    }while(Input||Input!='\n');

    return 0;
}

void clearBuffer(void)
{
    while ( getchar() != '\n' );
}

void printline(char text,int anz){

    int i;
    for(i=0;i<anz;i++){

        printf("%c",text);
    }
    printf("\n");



}

void WaitForEnter(void){

    clearBuffer();
    printf("Druecken sie Enter um fortzufahren\n");
    char enter;
    scanf("%c",&enter);
    clearBuffer();



}

int getText(char eingabe[],int maxZeichen,int optional,char **PStruct)
{
    //Benutzer die gewünschte eingabe mitteilen
    printf("%s: ",eingabe);

    //Einlesen der eingabe und speichern als zeiger auf chars
    char *pchar = NULL;
    pchar = malloc(sizeof(char));
    scanf("%s",pchar);
    clearBuffer();

    //auf Inhalt testen und optionalität
    if(!optional)
    {                     //optional=1 für optional
        if( !(*pchar) )                //optional=0 für nicht optional
        {
            printf("Bitte geben Sie was fur %s ein\n",eingabe);
            return 0;
        }
    }
    //testen auf maxlänge
    if(strlen(pchar)>maxZeichen)
    {
        printf("Eingabe für %s überschreitet maxZeichen:%i\n",eingabe,maxZeichen);
        return 0;
    }

    //anlegen des speichers
    char *pcharReal;
    pcharReal = calloc(strlen(pchar) , sizeof(char));

    //kopieren der eingabe
    strcpy(pcharReal,pchar);


    //Pstruct adresse des angelegten speichers überegeben
    *PStruct = pcharReal;

    //Testen
    printf("Ihre Eingabe: %s\n",*PStruct);


    //freigeben des speichers für pchar
    free(pchar);

    return 1;
}

int getNumber(char eingabeAufruf[],int optional,int *PStruct, int von, int bis)
{
    //eingabe
    printf("%s: ", eingabeAufruf);

    //einlesen
    int eingabe = 0;
    scanf("%i", &eingabe);
    clearBuffer();
    //auf Inhalt testen und optionalität
    if( (!optional)&&(!eingabe) )
    {                     //optional=1 für optional
        do                //optional=0 für nicht optional
        {
            printf("Bitte geben Sie was fur %s ein\n", eingabeAufruf);
            scanf("%i", &eingabe);
            clearBuffer();
        } while( !(eingabe) );
    }

    //in int umwandeln
    //int eingabe = atoi(pchar);

    //testen auf bereich von-bis
    if( (eingabe>bis) || (eingabe<von) )
    {
        printf("Eingabe für %s nicht zwischen %i und %i\n", eingabeAufruf, von, bis);
        return 0;
    }

    //kopieren der eingabe
    *PStruct = eingabe;

    //Testen
    printf("Ihre Eingabe: %i\n", *PStruct);

    return 1;

}
