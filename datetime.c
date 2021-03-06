#include <stdio.h>
#include "datetime.h"
#include "tools.h"
//�berpr�ft ob datum ein schaltjahr  ist

int isleapyear(TDate today)
{

    int year = today.Year;

    if(year%4==0&&year%100!=0)    //teilbar durch 4 nicht 100 = svhaltjahr
    {return 1;
    }

    if(year%100==0&&year%400!=0) //teilbar durch 100 nicht 400 = kein schaltjahr
    {return 0;
    }

    if(year%400==0)              //teilbar durch 400 = schaltjahr
    {return 1;
    }

    return 1;
}

//�berpr�ft ob Datum gueltig ist

int isdatevalid(TDate today, int optional)
{
    int leapyear = isleapyear(today);
    int month=today.Month;
    int day=today.Day;
    int year=today.Year;

    if( (optional) && (day==0) && (month==0) && (year==0) )
        return 1;

    if(day>31||day==0)
    {   return 0;                   //Tage �ber 31 und nicht 0.
    }

    if(month>12||month==0)          //nicht mehr als 12 monate und nicht 0.
    {   return 0;
    }

    if(year<1990||year>2999||year==0) // jahr muss zwichen 1990 und 2999 und
    {   return 0;                      // nicht 0 sein.
    }

    if(month==2)
    {
        if(leapyear==1 && day>29)   //bei schaltjahr feb 29 tage oder weniger.
        {return 0;
        }

        if(leapyear==0&&day>28)   //kein schaltjahr feb 28 tage oder weniger.
        {return 0;
        }

    }else                           //Au�er feb alle geraden monate weniger
    {                               //als 30 Tage
        if(month%2==0&&day>30)
        {return 0;
        }                           //ungeraden monate weniger als 30 Tage
        if(month%2!=0&&day>31)
        {return 0;
        }
    }
    return 1;
}



//�bergibt einer Tplayer datei ein geburtsdatum aus einem eingegebenen String
int getDate(char eingabeAufruf[], int optional)
{
    //printf("TEST!!999!!\n");
    char strdate[25];
    char *eingabestr = &(strdate[0]);
    char *pdate   =  &(*strdate);
    char *pday    =  &(*strdate);
    char *pmonth  =  NULL;
    char *pyear   =  NULL;


    printf("%s: ", eingabeAufruf);
    //scanf("%s", strdate);
    fgets(eingabestr, 25, stdin);
    //clearBuffer();
    //printf("%s\n", strdate);
    if(!optional)
    {                     //optional=1 f�r optional //optional=0 f�r nicht optional
        //printf("NICHT OPTIONAL!\n");
        if( !(*strdate) )
        {
            printf("Nicht korrekte Eingabe in Kategorie: %s \n",eingabeAufruf);
            return 0;
        }
        else if( *strdate == '\n')
        {
            printf("Nicht korrekte Eingabe in Kategorie: %s \n",eingabeAufruf);
            return 0;
        }
    }

    TDate today;

    //int count=0;
    int i=0;
    int count = 0;

       // printf("TEST!!!!\n");


        while(*(strdate+i))
        {
            if( (*(strdate+i) == '.') && (*(strdate+i+1) != '.') )
            {
                if(count == 1)
                {
                    pyear = &(*(strdate+i+1));
                }
                if(count == 0)
                {
                    pmonth = &(*(strdate+i+1));
                    //printf("TEST666");
                    count++;
                }
            }
            i++;
        }
    /*
        for(i=0;*(pdate+i);i++) //Shleife �ber Array
        {

            if((*(pdate+i)=='.'||*(pdate+i)==':')&&x==0)  //sucht nach trennzeichen
            {


             pmonth=&strdate[i+1];          //�bergibt pointer die adresse vom
                                            //element nach dem trennzeichen
             today.Month=(atoi(pmonth));    //month wird wert int  �bergeben

             x=1;                       // x auf eins um in das jahers if zu kommen
            }

            if((*(pdate+i)=='.'||*(pdate+i)==':')&&x==1)
            {
             pyear=&strdate[i+1];
             today.Year=(atoi(pyear));

            }

        }
    */
        //printf("TEST!\n");

        today.Day   = (atoi(pday));
        today.Month = (atoi(pmonth));
        today.Year  = (atoi(pyear));

        //printf("Ihre Eingabe: %02i.%02i.%04i\n", today.Day, today.Month, today.Year);
        //printDate(today);

    if(isdatevalid(today, optional)==1)           //testet ob valid ist und �bergibt an
    {                                   // unsere struct
            TDate *birthday;

            birthday = malloc(sizeof(TDate));
            int k = (Teams+TeamCounter)->AnzPlayer;

            (Teams+TeamCounter)->Player[k].Birthday   = birthday;

            (Teams+TeamCounter)->Player[k].Birthday->Day   = (atoi(pday));
            (Teams+TeamCounter)->Player[k].Birthday->Month = (atoi(pmonth));
            (Teams+TeamCounter)->Player[k].Birthday->Year  = (atoi(pyear));
            //free(birthday);
            return 1;

    }


    else
    {
        printDate(today);
        printf("Eingabe ungueltig!\n");
        return 0;
    }


}

//Funktion schreibt datum im Format dd.mm.yyyy

void printDate(TDate Date)
{
   int  iday    = Date.Day;
   int  imonth  = Date.Month;
   int  iyear   = Date.Year;
    if(!((iday==0)&&(imonth==0)&&(iyear==0) ))
        printf("%02i.%02i.%04i",iday,imonth,iyear);
    else
        printf("          ");
}
