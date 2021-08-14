#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
struct info
{
 char FirstName[30];
 char LastName[30];
 int number;
 int age;
 char gender;
 int priority;
 int boarding;
 int deboarding;
 char boardName[20];
 char destinationName[20];
 int additional;
 int tier;
 int total;
 struct info *next;
};
int max=50,add=2;
struct info *start=NULL;
struct info *book(struct info *start)
{
    int i,j;
    char first[30],last[30],gen;
    struct info *p,*temp;
    temp=(struct info*)malloc(sizeof(struct info));
    p=start;
    printf("Enter your First Name : ");
    scanf("%s",&first);
    strcpy(temp->FirstName,first);
    printf("Enter your Last Name : ");
    scanf("%s",&last);
    strcpy(temp->LastName,last);
    printf("Enter your gender :\n 'M' for Male and 'F' for Female : ");
    scanf("%s",&gen);
    temp->gender=gen;
    printf("Enter your age : ");
    scanf("%d",&i);
    temp->age=i;
    printf("Enter the number of additional passengers : ");
    scanf("%d",&i);
    temp->additional=i;
    while(1)
    {
        printf("\n***Choose Boarding and Destination Station***\n");
        printf("1. New Delhi\n");
        printf("2. Lucknow\n");
        printf("3. Haridwar\n");
        printf("4. Kolkata\n");
        printf("5. Allahbad\n");
        printf("6. Pune\n");
        printf("Enter your Boarding station : ");
        scanf("%d",&i);
        printf("Enter Destination station : ");
        scanf("%d",&j);
        if((i<0) || (i>6))
        {
            printf("Invalid Boarding Station\n");
            printf("Please try again\n");

        }
        else if((j<0) || (j>6))
        {
            printf("Invalid Destination Station\n");
            printf("Please try again\n");
        }
        else if(i==j)
        {
            printf("Boarding and Destination stations cannot be the same\n");
            printf("Please try again\n");
        }
        else
        {
            break;
        }
        switch(i)
        {
          case 1:
           strcpy(temp->boardName,"New Delhi");
          case 2:
            strcpy(temp->boardName,"Lucknow");
          case 3:
            strcpy(temp->boardName,"Haridwar");
          case 4:
            strcpy(temp->boardName,"Kolkata");
          case 5:
            strcpy(temp->boardName,"Allahbad");
          case 6:
            strcpy(temp->boardName,"Pune");
        }
        switch(j)
        {
          case 1:
           strcpy(temp->destinationName,"New Delhi");
          case 2:
            strcpy(temp->destinationName,"Lucknow");
          case 3:
            strcpy(temp->destinationName,"Haridwar");
          case 4:
            strcpy(temp->destinationName,"Kolkata");
          case 5:
            strcpy(temp->destinationName,"Allahbad");
          case 6:
            strcpy(temp->destinationName,"Pune");
        }

    temp->boarding=i;
    temp->deboarding=j;
    temp->number=1000+add;
    add=add+2;
    while(1)
    {
        printf("\nChoose which class you will travel in :\n");
        printf("1. General Class - 200/- per unit distance per passenger\n");
        printf("2. Officer's Class -300/- per unit distance per passenger\n");
        printf("3. Business Class - 500/- per unit distance per passenger\n");
        printf("Enter your choice : ");
        scanf("%d",&i);
        if((i==1)||(i==2)||(i==3))
        {
            break;
        }
        else
        {
            printf("Invalid Choice\n Please try again\n");
        }
    }
    temp->tier=i;
    while(1)
    {
        printf("\nIs any additional Quota applicable?\n");
        printf("1. Government Permit\n");
        printf("2. Official/Company Permit\n");
        printf("3. General passenger\n");
        printf("your answer :\n");
        scanf("%d",&i);
         if((i==1)||(i==2)||(i==3))
        {
            break;
        }
        else
        {
            printf("Invalid Choice\n Please try again\n");
        }
    }
    temp->priority=i;
    if(temp->tier==1)
    {
        temp->total=(temp->additional+1)*(temp->deboarding-temp->boarding)*200;
    }
    else if(temp->tier==2)
    {
       temp->total=(temp->additional+1)*(temp->deboarding-temp->boarding)*300;
    }
    else
    {
        temp->total=(temp->additional+1)*(temp->deboarding-temp->boarding)*500;
    }
    if(temp->total<0)
    {
        temp->total=-1*(temp->total);
    }
if(p=NULL)
{
    start=temp;
    temp->next=NULL;
}
else
{
    while((temp->priority>=p->priority)&&(p!=NULL))
    {
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
}

if(strcmp(temp->gender,"M")||strcmp(temp->gender,"m"))
{
    printf("Reservation successful for :- \n Mr. %s %s and %d others \n Your Registration number is %d \n Total booking cost = %d/- \n Returning to Main Menu . . . ",temp->FirstName,temp->LastName,temp->additional,temp->number,temp->total);
}
else
{
    printf("Reservation successful for :- \n Mrs. %s %s and %d others \n Your Registration number is %d \n Total booking cost = %d/- \n Returning to Main Menu . . . ",temp->FirstName,temp->LastName,temp->additional,temp->number,temp->total);
}
   return start;
}
struct info *remove(struct info *start)
{
 struct info *p1,*p2;
 int k;
 p2=start;
 p1=p2->next;
 if(p2==NULL)
 {
     printf("The List if Empty\n");
     return start;
 }
 else
 {
     printf("Enter your Registration Number : ");
     scanf("%d",&j);
 }
 if(p2->number==j)
 {
   start=p1;
   p2->next=NULL;
   free(p2);
 }
 else if(p1->number==j)
 {
     p2->next=p1->next;
     p1->next=NULL;
     free(p1);
 }
 while(p1!=NULL)
 {
     p2=p1;
     p1=p1->next;
     if(p1->number==j)
     {
         p2->next=p1->next;
         p1->next=NULL;
         free(p1);
         return start;

     }
     else if(p1->next==NULL)
     {
         printf("Registration Number not applicable.\n");
         return start;
     }
 }
}}
void print(struct info *start)
{
    struct info *p;
    char seat="A";
    int i=1,j;
    p=start;
    if(p==NULL)
    {
        printf("Booking List is Empty\n");
        return ;

    }
    while((max>p->additional+1)&&(p!=NULL))
    {
        if(max>p->number+1)
           {
            printf("NAME : %s %s        REGISTRATION NO. : %d        AGE : %d        BOARDING STATION : %s\n ",p->FirstName,p->LastName,p->number,p->age,p->boardName);
            printf("ADDITIONAL : %d     GENDER : %c       DESTINATION : %s\n ",p->additional,p->gender,p->destinationName);
           }
        else
          {
            printf("NAME : %s %s        REGISTRATION NO. : %d        AGE : %d        BOARDING STATION : %s\n ",p->FirstName,p->LastName,p->number,p->age,p->boardName);
            printf("ADDITIONAL : %d     GENDER : %c       DESTINATION : %s\n ",max,p->gender,p->destinationName);
          }
        for(j=0;j<p->total+1;j++)
        {
         printf("ALLOTED SEATS ARE : %c%d \n",seat,i);
         i++;
         if(i==10)
            {
             seat++;
             i=1;
            }
        }
         max=max-p->total+1;
         p=p->next;
    }
    max=50;
    return;
}

int main()
{
  int choice;
  while(1)
  {
      printf("\n***Main Menu***\n");
      printf("1. Book a ticket\n");
      printf("2. Cancel a booking\n");
      printf("3. Print final list\n");
      printf("4. Exit\n");
      printf("Enter your choice : ");
      scanf("%d",&choice);
      if(choice==4)
        break;
      else
        switch(choice)
      {
          case 1 :
           start=book(start);
           break;
          case 2 :
           start=remove(start);
           break;
          case 3 :
           print(start);
           break;
          default :
           printf("Invalid Choice\n");

      }

  }
  return 0;
}
