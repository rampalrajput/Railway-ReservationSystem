#include<stdio.h>
#include<stdlib.h>
#include "conio2.h"
#include "rlyres.h"
#define FONTMAPPER_MAX 12
int enterchoice()
{

    int choice ,i;
    char c;

    textcolor(LIGHTGREEN);
    printf("\n \n \n");
    gotoxy(40,2);
    printf("RAILWAY RESERVATION SYSTEM \n");


    for(i=1;i<=112;i++)
        printf("-");

        printf("\n select an option \n 1 : view Trains \n 2 : Book Tickets \n 3 : view ticket \n 4 : search Ticket no \n 5 : view All Bookings \n 6 : View Train Bookings \n 7 : cancel Ticket \n 8 : cancel Train ");
       printf(" \n 9 : Quit \n");
        printf("\n \n Enter your choice");
        scanf("%d",&choice);

        return choice;
}

        void add_trains()
        {

    FILE *fp;

    fp = fopen("g:\\my project\\alltrain.dat","rb");
    //w is used to  file read or write

    if(fp==NULL)
    {

        Train alltrains[4]={

        {"123","BPL","DEL",2100,1500},


        {"546","BPL","GWA",1560,2240},
        {"367","BPL","AGR",1200,1500},
        {"654","BPL","KML",2500,3698}



        };


        fp=fopen("g:\\my project\\alltrain.dat","rb");

        fwrite(alltrains,4*sizeof(Train),1,fp);

     //   printf(" \n File saved successfully \n");

        fclose(fp);
    }
    else
    {

 //  printf("\n File already present");

   fclose(fp);


    }
        }

int ticket_no()
        {
            FILE *fp;
            passenger psn;

 fp = fopen("g:\\ramcc.txt","rb");
 if(fp==NULL)
    {
     printf(" sorry no data");
 fclose(fp);

     return 1;
 }
 int count=0;
 while (fread(&psn.ticketno,sizeof(int),1,fp)==1)
{

   count=psn.ticketno;
}

count = count+1;

fclose(fp);

return count;
}
/*int book_ticket(passenger p)
        {

            int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
            if(ticket_count==2)
            {
                textbokk(LIGHTRED);

                printf("All seats full in Train no %s in %c class \n ",p.train_no,p.p_class);

                return -1;
            }
         int r = ticket_no();+1;
        p.ticketno=ticket_no;
        FILE *fp =fopen("g:\\ramcc.txt","ab");
        if(fp==NULL)
        {

            return -1;
        }
        fwrite(&p,sizeof(p),1,fp);

        fclose(fp);
        return -1;
        } */

        int get_booked_ticket_count(char * train_no,char tc)
        {

    FILE *fp=fopen("g:\\ramcc.txt","rb");
    if(fp==NULL)
        return 0;

    passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0 && pr.p_class==tc)
            ++count;

    }
    fclose(fp);
    return count;
}


void view_train()
{

FILE *fp;

 fp = fopen("g:\\my project\\alltrain.dat","rb");

 Train s;
 int i;

 textcolor(LIGHTGREEN);
 printf("\n TRAIN NO \t FORM \t\t  To \t \t FIRST AC FAIR \t \t SECOND AC FAIR\n");

  for(i=1;i<=112;i++)
        printf("-");
 rewind(fp);

 while( fread(&s,sizeof(s),1,fp)!=0)
 {


   printf(" \n %s \t \t  %s \t  \t  %s \t \t  %d \t \t  \t %d \n ",s.train_no,s.from,s.to,s.fac_fare,s.sac_fare);

}

textcolor(WHITE);
printf(" \n \n press any key to on back to the main screen ");
_getch();

clrscr();
fclose(fp);

main();

}
char view_train_booking(char *train)
{
     passenger psn;

    int valid =1;
      FILE *fp;
 fp = fopen("g:\\ramcc.txt","rb");

  if(fp==NULL)
    {
      printf(" sorry no data");
    fclose(fp);

     return NULL;

 }
  printf("\n NAME \t Gender \tMOBILE NO \t AGE \t TRAIN NO\t ADDRESS \t PASSENGER CLASS   TICKET NO \n");
int i;

  for(i=1;i<=111;i++)


printf("-");

    while( fread(&psn,sizeof(psn),1,fp)==1)
    {
        if(strcmp(psn.train_no,train)==0)
        {
            textcolor(YELLOW);
            valid=0;
printf("\n %s     %c \t\t%s \t %d \t  %s \t \t %s \t \t%c \t\t%d ",psn.p_name,psn.gender,psn.mob_no,psn.age,psn.train_no,psn.address,psn.p_class,psn.ticketno);

 }
}

    if(valid==1)
    {
        textcolor(LIGHTRED);
        gotoxy(4,15);
        printf("INVALID TRAIN NUMBER ");
    }
     textcolor(WHITE);
  fflush(stdin);
  gotoxy(4,20);
           printf("\n press any key to go back to main screen");

    _getch();
fclose(fp);
     return NULL;

}



char check_mob(char *num)
{
    passenger psn;

    int valid =1;
      FILE *fp;
 fp = fopen("g:\\ramcc.txt","rb");

  if(fp==NULL)
    {
      printf(" sorry no data");
    fclose(fp);

     return 1;

 }
    while( fread(&psn,sizeof(psn),1,fp)==1)
    {
        if(strcmp(psn.mob_no,num)==0)
        {

            valid=0;

            textcolor(YELLOW);
             printf(" \n successfully found your ticket no = %d",psn.ticketno);

            fclose(fp);

            return NULL;
        }
    }
    if(valid==1)
    {
        textcolor(LIGHTRED);
        gotoxy(1,15);
        printf(" \n INVALID MOBILE NUMBER ");

    }
     fclose(fp);
     return NULL;

}



int check_train_no(char *trainno)
{

    FILE *fp;

 fp = fopen("g:\\my project\\alltrain.dat","rb+");


     Train tr;

    while( fread(&tr,sizeof(tr),1,fp)==1)
    {

        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
     fclose(fp);
            return 0;
}

char check_mob_no(char *p_mob)
{

    if(strlen(p_mob)!=10)
    return 0;

    while((*p_mob)!='\0')
    {

        if(isdigit(*p_mob)==0)

            return 0;

    p_mob++;
    }
    return 1;

}
void view_all_Booking()
{

            FILE *fp;
    passenger psn;

 fp = fopen("g:\\ramcc.txt","rb");
 if(fp==NULL)
    {
     printf(" sorry no data");
 fclose(fp);

     return 1;

 }
textcolor(YELLOW);
gotoxy(25,1);
 // printf(" ALL BOOKING TICKET  ");

 textcolor(LIGHTGREEN);


 printf("\n NAME \t Gender\t\tMOBILE NO \t AGE \t TRAIN NO\t ADDRESS \t PASSENGER CLASS   TICKET NO \n");
int i;
  for(i=1;i<=111;i++)
        printf("-");




 while (fread(&psn,sizeof(passenger),1,fp)==1)
 {

textcolor(YELLOW);
printf("\n %s     %c \t\t%s \t %d \t  %s \t \t %s \t \t%c \t\t%d \n",psn.p_name,psn.gender,psn.mob_no,psn.age,psn.train_no,psn.address,psn.p_class,psn.ticketno);

//printf("\n %s \t %c  \t %s \t  %d \t  %s \t \t %s \t \t%c \t \t %d \n ",psn.p_name,psn.gender,psn.mob_no,psn.age,psn.train_no,psn.address,psn.p_class,psn.ticketno);

 }
  textcolor(WHITE);
  gotoxy(4,20);
           printf("\n press any key to go back to main screen");
           getch();
           textcolor(GREEN);
fclose(fp);
getch();
}

int check_no()
{
 gotoxy(1,40);
    textcolor(LIGHTRED);
    printf("Reservation cancelled");
    getch();
    clrscr();
    textcolor(YELLOW);
    clrscr();

     return 1;

}
int cancle_train(char *train)
{
     FILE *fp1;

    fp1=fopen("g:\\ramcc.txt","ab+");

      if(fp1==NULL)
    {
        printf(" sorry Data not found");

        fclose(fp1);
        return -1;
        }

        FILE *fp2=fopen("g:\\temp.txt","wb+");
        passenger pr;
        int found =0;
        while(fread(&pr,sizeof(pr),1,fp1)==1)

        {

            if(strcmp(pr.train_no,train)!=0)
            {

                fwrite(&pr,sizeof(pr),1,fp2);
            }
            else
            {
                found=1;

            }
        }

        fclose(fp1);
        fclose(fp2);
        if(found==0)
        {

            remove("g:\\temp.txt");
        }
        else{
            remove("g:\\ramcc.txt");
            rename("g:\\temp.txt","g:\\ramcc.txt");
        }

        return found;

}
int cancel_ticket(int ticket_no)
{
     FILE *fp1;

    fp1=fopen("g:\\ramcc.txt","ab+");

      if(fp1==NULL)
    {
        printf(" sorry Data not found");

        fclose(fp1);
        return -1;
        }

        FILE *fp2=fopen("g:\\temp.txt","wb+");
        passenger pr;
        int found =0;
        while(fread(&pr,sizeof(pr),1,fp1)==1)

        {

            if(pr.ticketno!=ticket_no)
            {

                fwrite(&pr,sizeof(pr),1,fp2);
            }
            else
            {
                found=1;

            }
        }

        fclose(fp1);
        fclose(fp2);
        if(found==0)
        {

            remove("g:\\temp.txt");
        }
        else{
            remove("g:\\ramcc.txt");
            rename("g:\\temp.txt","g:\\ramcc.txt");
        }

        return found;
}

 void view_ticket(r)
{
    FILE *fp;

    fp=fopen("g:\\ramcc.txt","ab+");


    passenger psn;
    int valid=1;

    //fp = fopen("g:\\ramcc.txt","ab+");

    if(fp==NULL)
    {
        printf(" sorry Data not found");

        fclose(fp);
        }
        while (fread(&psn,sizeof(passenger),1,fp)==1)
{
    if(r==psn.ticketno)
    {
int i;
    clrscr();
     textcolor(LIGHTGREEN);
 printf("\n  NAME \t \t Gender \t MOBILE NO \t AGE \t TRAIN NO \t ADDRESS \t PASSENGER CLASS \n");

  for(i=1;i<=112;i++)
        printf("-");
textcolor(YELLOW);
printf("\n  %s \t  %c \t \t %s \t  %d \t  %s \t \t %s \t \t %c ",psn.p_name,psn.gender,psn.mob_no,psn.age,psn.train_no,psn.address,psn.p_class);

textcolor(GREEN);
    valid=0;
        fclose(fp);
    }

}
if(valid==1)

{
    gotoxy(10,5);

    textcolor(LIGHTRED);

    printf(" SORRY !INVALID TICKET NUMBER");

    fclose(fp);
}
}




passenger *get_passenger_details()
{

    FILE *fp;

    fp = fopen("g:\\ramcc.txt","ab+");
    //w is used to  file read or write

    if(fp==NULL)
    {
   fp = fopen("g:\\ramcc.txt","wb+");
   fclose(fp);
   fp = fopen("g:\\ramcc.txt","ab+");
        //printf("sorry no file open");

    }

    gotoxy(90,1);
    textcolor(LIGHTGREEN);
    printf(" press 0 to exit");

   gotoxy(1,1);
   textcolor(YELLOW);
    printf("Enter passenger name:");
    getch();


    static passenger psn;

    fflush(stdin);

    fgets(psn.p_name,20,stdin);



    char *pos;

    pos =strchr(psn.p_name,'\n');

    *pos='\0';

    if(strcmp(psn.p_name,"0")==0)
    {

     check_no();
     return NULL;
}


    int valid;
    printf("Enter gender (M/F):");

        do
        {
            valid=1;
            fflush(stdin);
            scanf("%c",&psn.gender);
            if(psn.gender=='0')
                {

  check_no();
     return NULL;

        }
if(psn.gender!='M'&&psn.gender!='F')
{

    textcolor(LIGHTRED);
    gotoxy(1,25);
    printf(" Error! Gendar should be M or F(in uppercase)");

    valid=0;
     getch();
     fflush(stdin);
       gotoxy(1,25);
     printf(" \t \t \t \t \t  \t \b");
   gotoxy(20,2);
    printf(" \b");
 textcolor(YELLOW);
}
}
while(valid==0);
//gotoxy(1,25);
//printf("\t \t \t \t \t \b");
int x,i;
gotoxy(1,3);
printf("Enter mobile no :");
do
{


fflush(stdin);

fgets(psn.mob_no,11,stdin);

x=strlen(psn.mob_no);

  char *pol;

    pol =strchr(psn.mob_no,'\n');

    if(pol!=NULL)
        *pol='\0';
         if(strcmp(psn.mob_no,"0")==0)
    {
       check_no();
     return NULL;
    }

   // *pol='\0';

     i = check_mob_no(psn.mob_no);

   if(i==0)
    {

    textcolor(LIGHTRED);
    gotoxy(1,25);
    printf(" Error! mobile number should be 10 digits and numeric ");

    i=0;
     getch();
     fflush(stdin);
       gotoxy(1,25);
     printf(" \t \t \t \t \t  \t \t \b");
   gotoxy(18,3);
    printf(" \t \t \t \t \t \t \t \t \t \b");
    gotoxy(18,3);
 textcolor(YELLOW);
}
}
while(i==0);



     if(valid==0)
     {
          fflush(stdin);
       gotoxy(1,25);
     printf(" \t \t \t \t \t  \t \b");
   gotoxy(18,3);
    printf(" \t \t \t \t \t \t \t \t \b");
    gotoxy(18,3);
 textcolor(YELLOW);


     }
    printf("Enter age :");

    int num;
    do
    {
        num=1;

    scanf("%d",&psn.age);
   /* fwrite(&psn,sizeof(psn),1,fc);
    fread(&psn.age,sizeof(psn),1,fc);
      printf("age=%d",psn.age); */

     if(psn.age==0)
    {
         check_no();

     return NULL;
    }
    if(psn.age<0)
    {
        num=0;
         gotoxy(2,28);
           fflush(stdin);
           textcolor(LIGHTRED);
           printf(" ERROR! AGE SHOUID BE POSITIVE ");

            getch();
             gotoxy(2,28);
            printf(" \t \t \t \t \b");
            gotoxy(12,4);
            printf("\t \t \t \t \t \b");
            gotoxy(12,4);
            textcolor(YELLOW);

    }
    }
    while(num==0);

int d;

printf("Enter train number:");
do
{

fflush(stdin);

    fgets(psn.train_no,20,stdin);
    d=1;
    char *po;

    po =strchr(psn.train_no,'\n');

    *po='\0';
   // printf("%s",psn.train_no);
     if(strcmp(psn.train_no,"0")==0)
    {
 check_no();
     return NULL;
}
   FILE *fp;

 fp = fopen("g:\\my project\\alltrain.dat","rb");


     Train tr;

    while( fread(&tr,sizeof(tr),1,fp)==1)
    {

        if(strcmp(tr.train_no,psn.train_no)==0)
        {
            d=0;
            fclose(fp);

        }
    }
       if(d==1)
       {
           gotoxy(2,28);
           fflush(stdin);
           textcolor(LIGHTRED);
           printf(" ERROR! INVAILD TRAIN NUMBER ");

            getch();
             gotoxy(2,28);
            printf(" \t \t \t \t \b");
            gotoxy(20,5);
            printf("\t \t \t \t \t \b");
            gotoxy(20,5);
            textcolor(YELLOW);
            d=1;
       }


       }


while(d==1);

printf("Enter address :");
fflush(stdin);
  fgets(psn.address,20,stdin);
    char *poe;

    poe =strchr(psn.address,'\n');

    *poe='\0';
   // printf("%s",psn.train_no);
     if(strcmp(psn.address,"0")==0)
    {
 check_no();
     return NULL;
}


printf("Enter AC FAIR(F/S):");
 do
        {
            valid=1;
            fflush(stdin);
            scanf("%c",&psn.p_class);
            if(psn.p_class=='0')
                {
       check_no();

     return NULL;

        }
if(psn.p_class!='F'&&psn.p_class!='S')
{

    textcolor(LIGHTRED);
    gotoxy(1,25);
    printf(" Error! Travelling class should be F or S(in uppercase)");

    valid=0;
     getch();
     fflush(stdin);
       gotoxy(1,25);
     printf(" \t \t \t \t \t  \t  \t \b");
   gotoxy(20,7);
    printf("           \b");
    gotoxy(20,7);
 textcolor(YELLOW);
}
}
while(valid==0);

 textcolor(GREEN);

textcolor(YELLOW);
                                                           ;
/* while (fread(&psn,sizeof(passenger),1,fp)==1)
{

    //printf(" \n name =%s \n gender  = %c \n mobile noumber  = %s \n age= %d \n train no =%s \n address =%s \n pass. class = %c \n ",psn.p_name,psn.gender,psn.mob_no,psn.age,psn.train_no,psn.address,psn.p_class);
count=count+1;

}

psn.ticketno = count+1;

printf(" ticket no\n = %d",psn.ticketno);

 fseek(fp,-count*sizeof(passenger),SEEK_SET); */

psn.ticketno =  ticket_no();

int ticket_count=get_booked_ticket_count(psn.train_no,psn.p_class);

if(ticket_count >= 2)
{
    clrscr();
    textcolor(LIGHTGREEN);
    gotoxy(15,1);
    printf("  TICKET BOOKING \n");
     textcolor(LIGHTRED);

     gotoxy(5,5);

                printf("sorry ! All seats full in Train no %s in %c class \n ",psn.train_no,psn.p_class);
                textcolor(WHITE);

    printf("\n press any key to go back to main screen \n ");
    getch();
    clrscr();
    return &psn;
}
else
{


 fwrite(&psn,sizeof(passenger),1,fp);

  clrscr();

printf(" \n your ticket number is  = %d",psn.ticketno);
textcolor(GREEN);

printf(" \n \n \t your ticket is successfully booked \n");

textcolor(WHITE);
gotoxy(4,5);
printf(" press any key");

getch();

rewind(fp);

 /* while (fread(&psn,sizeof(passenger),1,fp)==1)
{

printf(" \n name =%s \n gender  = %c \n mobile number  = %s \n age= %d \n train no =%s \n address =%s \n pass. class = %c \n ticket no = %d \n ",psn.p_name,psn.gender,psn.mob_no,psn.age,psn.train_no,psn.address,psn.p_class,psn.ticketno);

   } */

    getch();
    fclose(fp);
    clrscr();
   return &psn;
}


}









