
#include "datetime.h"

//Überprüft ob datum ein schaltjahr  ist

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

//Überprüft ob Datum gueltig ist

int isdatevalid(TDate today)
{
    int leapyear = isleapyear(today);
    int month=today.Month;
    int day=today.Day;
    int year=today.Year;

    if(day>31||day==0)
    {   return 0;                   //Tage über 31 und nicht 0.
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

    }else                           //Außer feb alle geraden monate weniger
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



//Übergibt einer Tplayer datei ein geburtsdatum aus einem eingegebenen String

int getDate(char strdate[])
{
    //printf("TEST!!999!!\n");

    char *pdate   =  &(*strdate);
    char *pday    =  &(*strdate);
    char *pmonth  =  NULL;
    char *pyear   =  NULL;

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
    for(i=0;*(pdate+i);i++) //Shleife über Array
    {

        if((*(pdate+i)=='.'||*(pdate+i)==':')&&x==0)  //sucht nach trennzeichen
        {


         pmonth=&strdate[i+1];          //übergibt pointer die adresse vom
                                        //element nach dem trennzeichen
         today.Month=(atoi(pmonth));    //month wird wert int  übergeben

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

    printf("%02i.%02i.%04i\n", today.Day, today.Month, today.Year);

    if(isdatevalid(today)==1)           //testet ob valid ist und übergibt an
    {                                   // unsere struct
        TDate *birthday;

        birthday = malloc(sizeof(TDate));

        (Teams+TeamCounter)->Player->Birthday   = birthday;

        (Teams+TeamCounter)->Player->Birthday->Day   = (atoi(pday));
        (Teams+TeamCounter)->Player->Birthday->Month = (atoi(pmonth));
        (Teams+TeamCounter)->Player->Birthday->Year  = (atoi(pyear));
        return 1;

    }
    else
        return 0;

}

//Funktion schreibt datum im Format dd.mm.yyyy

void printDate(TDate Date){
   int  iday    = Date.Day;
   int  imonth  = Date.Month;
   int  iyear   = Date.Year;

    printf("%2i.%2i.%4i",iday,imonth,iyear);
}
