#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct Train
{
    char train_no[10];

    char from[10];

    char to[10];

    int fac_fare;
    int sac_fare;

};
struct passenger
{

    char p_name[10];
    char gender;
    char mob_no[10];
    int age;
    char train_no[10];
    char address[20];
    char p_class;
    int ticketno;

};
typedef struct Train Train;
typedef struct passenger passenger;

int enterchoice();
void add_trains();
int ticket_no();
void view_all_booking();
void view_train();
int book_ticket(passenger);
int* get_ticket_no(char *);
void view_ticket(int);
int cancle_train(char *);
int cancel_ticket(int);
passenger *get_passenger_details();
int check_train_no(char*);
int get_booked_ticket_count(char*,char);
int last_ticket_no();
char check_mob_no(char *);
int check_no();
char check_mob(char *num);
int check_book_ticket();
char view_train_booking(char *);





#endif // RLYRES_H_INCLUDED
