#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 
#define cap 10000
 
struct file
{
  int UIN;
  char name[20];
  int age;
  char bt[5];
  char job[10];
  char addr[30];
  char city[20];
  struct file *next;
}*top,*top1,*temp,*current;
 
int topelement();
int search();
void push();
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();
 
int count = 0;
 
int main()
{
  int ch,e,p;
  
  printf("\n1. Create a file.");
  printf("\n2. Delete a file.");
  printf("\n3. Display top file.");
  printf("\n4. Check Database if empty.");
  printf("\n5. Exit Database.");
  printf("\n6. Display all files.");
  printf("\n7. File Count.");
  printf("\n8. Delete Database.");
  printf("\n9. File Search.");
  
  create();
  
  while (1)
  {
    printf("\n\nEnter choice: ");
   scanf("%d", &ch);
   switch (ch)
    {
      case 1:push();
         	break;
         	
      case 2:pop();
      	  break;
       
     case 3:if (top == NULL)
         	{
           	printf("No elements in stack");
         	}
       
            else
         	{
           	e = topelement();
           	printf("\n Top element : %d", e);
         	}
         	
         	break;
         	
      case 4:empty();
         	break;
         	
      case 5:printf("\nLeaving the Application.");
         	exit(0);
         	
      case 6:display();
         	break;
         	
      case 7:stack_count();
         	break;
         	
      case 8:destroy();
         	break;
 
      case 9:p=search();
         	printf("%d",p);
         	break;
         	
      default:printf("\nWrong choice, Please enter correct choice.\n");
              break;
   }
  }
  
  return 0;
}
 
//Block Jinendra
//Create empty stack
void create()
{
 top = NULL;
}
//Count stack elements
void stack_count()
{
 printf("\n No. of elements in stack : %d", count);
}
 
// Push data into stack
void push()
{
  int f_UIN,f_age;
  char flag,f_name[20],f_bt[5],f_job[10],f_addr[30],f_city[20];
  
  printf("\n\nEnter details into file:-\n");
  printf("\nEnter UIN: ");
  scanf("%d",&f_UIN);
  printf("Enter name: ");
  scanf("%c",&flag);
  scanf("%[^\n]",f_name);
  printf("Enter age: ");
  scanf("%d",&f_age);
  printf("Enter blood type: ");
  scanf("%c",&flag);
  scanf("%[^\n]",f_bt);
 printf("Enter job: ");
  scanf("%c",&flag);
  scanf("%[^\n]",f_job);
  printf("Enter residential address: ");
  scanf("%c",&flag);
  scanf("%[^\n]",f_addr);
  printf("Enter city of residence: ");
  scanf("%c",&flag);
  scanf("%[^\n]",f_city);
 
  if (top == NULL)
  {
    top =(struct file *)malloc(1*sizeof(struct file));
   top->next = NULL;
   top->UIN=f_UIN;
   strcpy(top->name,f_name);
   top->age=f_age;
   strcpy(top->bt,f_bt);
   strcpy(top->job,f_job);
   strcpy(top->addr,f_addr);
   strcpy(top->city,f_city);
  }
  
  else
  {
    temp =(struct file *)malloc(1*sizeof(struct file));
    temp->next= top;
    temp->UIN = f_UIN;
    strcpy(temp->name,f_name);
    temp->age=f_age;
    strcpy(temp->bt,f_bt);
    strcpy(temp->job,f_job);
    strcpy(temp->addr,f_addr);
    strcpy(temp->city,f_city);
    top = temp;
  }
 
  //Block Jeevan
  FILE *fp;
  fp=fopen("file.txt","a+");
 
  if(fp==NULL)
  {
    printf("error!!!");
  }
 
  else
  {
   fprintf(fp,"\nUIN:%d\n",f_UIN);
    fprintf(fp,"Name:%s\n",f_name);
    fprintf(fp,"Age:%d\n",f_age);
    fprintf(fp,"Blood Type:%s\n",f_bt);
   fprintf(fp,"Job:%s\n",f_job);
    fprintf(fp,"Address:%s\n",f_addr);
    fprintf(fp,"City:%s\n\n",f_city);
  }
 
  fclose(fp);
 
  count++;
}
 
// Display files in database
void display()
{
  top1 = top;
  
  if (top1 == NULL)
  {
    printf("Stack is empty");
    return;
  }
  
  while (top1 != NULL)
  {
    printf("\nUIN: %d ", top1->UIN);
   printf("\nName:%s",top1->name);
   printf("\nAge:%d",top1->age);
   printf("\nBlood Type:%s",top1->bt);
   printf("\nJob:%s",top1->job);
   printf("\nAddress:%s",top1->addr);
   printf("\nResidential City:%s",top1->city);
   printf("\n");
   top1 = top1->next;
  }
}
 
//Block Hemang
// Pop Operation on stack
void pop()
{
  top1 = top;
 
  if (top1 == NULL)
  {
    printf("\n Error : Trying to pop from empty stack");
   return;
  }
  
  else
  {
    top1 = top1->next;
  }
  
  printf("\n Popped UIN : %d", top->UIN);
  free(top);
  top = top1;
  count--;
}
// Return top element
int topelement()
{
  printf("\nUIN:%d",top->UIN);
  printf("\nName:%s",top->name);
  printf("\nAge:%d",top->age);
  printf("\nBlood Type:%s",top->bt);
  printf("\nJob:%s",top->job);
  printf("\nAddress:%s",top->job);
  printf("\nCity of Residence:%s",top->city);
  return 1;
}
// Check if stack is empty or not
void empty()
{
  if (top == NULL)
  {
    printf("\n Stack is empty");
  }
  
  else
  {
    printf("\n Stack is not empty with %d elements", count);
  }
}
// Destroy entire stack
void destroy()
{
  top1 = top;
  
  while (top1 != NULL)
  {
    top1 = top->next;
   free(top);
   top = top1;
   top1 = top1->next;
  }
  
  free(top1);
  top = NULL;
  printf("\n All stack elements destroyed");
  count = 0;
}
 
int search()
{
  current=top;
  int s_UIN;
 
  printf("\nEnter UIN of file to be checked for: ");
  scanf("%d",&s_UIN);
 
  if(top==NULL)
  {
    return -1;
  }
 
  else
  {
    while(current->UIN!=NULL)
    { 
      if(current->UIN==s_UIN)
      {
        printf("\nFile found.");
        printf("\nUIN: %d ", current->UIN);
       printf("\nName:%s",current->name);
       printf("\nAge:%d",current->age);
       printf("\nBlood Type:%s",current->bt);
       printf("\nJob:%s",current->job);
       printf("\nAddress:%s",current->addr);
       printf("\nResidential City:%s",current->city);
       printf("\n");
        return 1;
      }
 
      else
      {
        current=current->next;
      }
    }
  }
 
  return 0;
}