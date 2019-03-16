#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"rlyres.h"

int main()
{

        int choice,r;

        int ticket_no;
        char *ptr;
        char num[10];
        char train[6];
        int result;


      add_trains();
        while(1)

        {

            choice=enterchoice();
            char c;
            if (choice==9)
            {


    printf(" \n Do you want to Exit enter (y/n)\n");

            fflush(stdin);

             scanf("%c",&c);


        if('y'==c)
        {

             printf("\n");

         clrscr();

        exit(0);

        }
        else
        {
            clrscr();
            fflush(stdin);

            main();
        }
            }


            switch(choice)
            {
        case 1 :

            clrscr();

               view_train();

        case 2 :
            clrscr();

     *get_passenger_details();
     break;

     /* clrscr();
     FILE *fp;

     fopen("g:\\ramcc.txt","ab+");

     if(fp==NULL)
     {


     ticket=book_ticket(*ram);

         if(ticket==1)
         {

             textcolor(LIGHTRED);
             printf("Booking Failed");

         }
         else
         {
             textcolor(LIGHTGREEN);

             printf("\n Ticket successfully Booked \n your ticket number is = %d",ticket_no")

         }
         textcolor(WHITE);
         printf("\n press any key to go back to main screen");
         getch();
         fclose(fp);
         clrscr();
     } */

        case 4 :

        clrscr();
        textcolor(LIGHTGREEN);
         gotoxy(90,1);
    textcolor(LIGHTGREEN);
    printf(" press 0 to exit");

   gotoxy(1,1);
   textcolor(YELLOW);
    printf(" \n Enter your mobile no : = ");
           fflush(stdin);
           char *po;

fgets(num,11,stdin);
    po =strchr(num,'\n');

    if(po!=NULL)
            *po='\0';

    if(strcmp(num,"0")==0)
    {

     check_no();

   main();
}
             check_mob(num);
             textcolor(WHITE);
               gotoxy(4,20);
             printf("\n \n  press any key to go back to main screen");

             getch();
             clrscr();
            break;


            case 3 :

            clrscr();
               textcolor(LIGHTGREEN);
         gotoxy(90,1);
    textcolor(LIGHTGREEN);
    printf(" press 0 to exit");

   gotoxy(1,1);
   textcolor(YELLOW);
            printf(" \n Enter your ticket no : = ");
            scanf("%d",&r);

    if(r==0)
    {

     check_no();

   main();
}
          view_ticket(r);
            textcolor(WHITE);
            gotoxy(4,20);
             printf("\n \n  press any key to go back to main screen");

             getch();
             clrscr();
             break;


            case 5 :

           clrscr();

           view_all_Booking();

           clrscr();
           break;


            case 6 :

        clrscr();
           textcolor(LIGHTGREEN);
         gotoxy(90,1);
    textcolor(LIGHTGREEN);
    printf(" press 0 to exit");

   gotoxy(1,1);
   textcolor(YELLOW);
    printf(" \n Enter Train no : = ");
           fflush(stdin);
           char *pos;

fgets(train,5,stdin);
    pos =strchr(train,'\n');

    if(pos!=NULL)
            *pos='\0';
            if(strcmp(train,"0")==0)
            {

                check_no();
                main();
            }
             view_train_booking(train);

             getch();
             clrscr();
             break;


            case 7 :

    clrscr();
       textcolor(LIGHTGREEN);
         gotoxy(90,1);
    textcolor(LIGHTGREEN);
    printf(" press 0 to exit");

   gotoxy(1,1);
   textcolor(YELLOW);

    printf(" \n Enter Ticket no : = ");
    scanf("%d",&ticket_no);

    if(ticket_no==0)
    {
        check_no();
        main();

    }
    if(ticket_no!=0)
    {
  result =cancel_ticket(ticket_no);

        if(result==0)
        {

            textcolor(LIGHTRED);
            printf("sorry no tickets booked aganist ticket no %d",ticket_no);
        }
        else if(result==1)
        {

            textcolor(LIGHTGREEN);
            printf(" ticket no %d successfully cancelled", ticket_no);

        }
        textcolor(WHITE);
        gotoxy(4,20);
        printf("\n press any key to go back to main screen");


    }

    getch();
    clrscr();
    break;

              case 8 :
clrscr();
   textcolor(LIGHTGREEN);
         gotoxy(90,1);
    textcolor(LIGHTGREEN);
    printf(" press 0 to exit");

   gotoxy(1,1);
   textcolor(YELLOW);
    printf(" \n Enter Train no : = ");
           fflush(stdin);


fgets(train,5,stdin);
    pos =strchr(train,'\n');

    if(pos!=NULL)
            *pos='\0';
if(strcmp(train,"0")==0)
{
    check_no();
    main();

}
    result=cancle_train(train);

        if(result==0)
        {

            textcolor(LIGHTRED);
            printf("sorry no train booked aganist train no %s",train);
        }
        else if(result==1)
        {

            textcolor(LIGHTGRAY);
            printf(" \n ticket no %s successfully cancelled",train);

        }
        textcolor(WHITE);
        gotoxy(4,20);
        printf("\n press any key to go back to main screen");




             getch();
             clrscr();
             main();
             break;

     default :
                textcolor(LIGHTRED);

                printf(" \n \t Wrong  choice ! try again \n");
                getch();
                clrscr();




        }
        }







    return 0;
}
