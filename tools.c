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
        clearBuffer();


        if(Input=='y'||Input=='Y'||Input=='j'||Input=='J')
        return 1;

        if(Input=='n'||Input=='N')
        return 0;

    }while(Input||Input!='\n');

    return 0;
}

void clearBuffer(void)
{
    char dummy;
    do
    {
        scanf("%c", &dummy);
    } while(dummy != '\n');
}

void printline(char text,int anz){

    int i;
    for(i=0;i<anz;i++){

        printf("%c",text);
    }
    printf("\n");



}

void WaitForEnter(void){

    //clearBuffer();
    printf("Druecken sie Enter um fortzufahren..\n");
    char enter;
    scanf("%[^\n]",&enter);
    clearBuffer();



}

void chomp(char *str)       // KOPIERTE FUNKTION !!!!
{
   size_t p=strlen(str);
   /* '\n' mit '\0' überschreiben */
   str[p-1]='\0';
}
/*
int getText(char eingabe[],int maxZeichen,int optional,char **PStruct)
{
    int len;
    int i = 0;
    //Benutzer die gewünschte eingabe mitteilen
    printf("%s: ",eingabe);

    //Einlesen der eingabe und speichern als zeiger auf chars
    char *pchar = NULL;
    *pchar = calloc(maxZeichen, (sizeof(char)) );
    //scanf("%s",pchar);
    if(pchar)
        fgets(pchar, maxZeichen, stdin);
    //chomp(pchar);
    else
        printf("FEHLER\n");

    //printf("%s\n", pchar);
    //printf("%s", *pchar);

    //auf Inhalt testen und optionalität
    if(!optional)
    {                     //optional=1 für optional //optional=0 für nicht optional
        //printf("NICHT OPTIONAL!\n");
        if( !(*pchar) )
        {
            printf("Nicht korrekte Eingabe in Kategorie: %s \n",eingabe);
            return 0;
        }
        else if( *pchar == '\n')
        {
            printf("Nicht korrekte Eingabe in Kategorie: %s \n",eingabe);
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
    *pcharReal = calloc(strlen(pchar) , sizeof(char));

    if(pcharReal)
    {
    //kopieren der eingabe
        strcpy(pcharReal,pchar);
        *PStruct = pchar;
    }
    else
        printf("Hallo!!!!!!FEHLER\n");

    //Pstruct adresse des angelegten speichers überegeben


    //Testen
    //if(pcharReal != '\n')
       // printf("Ihre Eingabe: %s\n",*PStruct);


    //freigeben des speichers für pchar
    free(pchar);
    free(pcharReal);

    return 1;
}
*/


int getNumber(char eingabeAufruf[],int optional,int *PStruct, int von, int bis)
{
    //eingabe
    printf("%s: ", eingabeAufruf);
    //einlesen
    int eingabe = 0;
    scanf("%i[^\n]", &eingabe);
    clearBuffer();
    //auf Inhalt testen und optionalität
    if( (!optional)&&(!eingabe) )
    {                     //optional=1 für optional
        do                //optional=0 für nicht optional
        {
            printf("Nicht korrekte Eingabe in Kategorie: %s \n", eingabeAufruf);
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
    //printf("Ihre Eingabe: %i\n", *PStruct);

    return 1;

}

int getText(char *Prompt, int MaxLen, char **Text, int allowEmpty)
{
    char *Input;
    char Format[20];
    int scanErg;
    int len;

    if(MaxLen <= 0)
    {
        printf("1\n");
        return 0;
    }
    if(Text == NULL)
    {
        printf("2\n");
        return 0;
    }
    *Text = NULL;
    Input = calloc(MaxLen+1, sizeof(char));

    if(Input)
    {
        sprintf(Format, "%%%i[^\n]", MaxLen);

        do
        {
            printf("%s: ", Prompt);
            scanErg = scanf((Format, Input));
            clearBuffer();
            len = strlen(Input);

            if(len > 0)
            {
                *Text = malloc((len+1)*sizeof(char));
                if(Text)
                    strcpy(*Text, Input);
                else
                {
                    free(Input);
                    printf("3\n");
                    return 0;
                }
            }
            else
            {
                if(allowEmpty)
                {
                    free(Input);
                    return 1;
                }
                else
                    scanErg = 0;
            }
        } while(scanErg==0);
        free(Input);
        return 1;
    }
}
