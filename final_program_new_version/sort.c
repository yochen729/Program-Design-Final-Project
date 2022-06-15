#include "basic.h"
#include "base_operator.h"
#include "sort.h"
#include "BST.h"

extern int num;

void Swap(struct basic_account* head, char* name1, char *name2)
{
    struct basic_account *ptr,*qtr,*ptr_pre;
    for(ptr=head->next,ptr_pre=head;ptr;ptr_pre=ptr,ptr=ptr->next)
    {
      if(strcmp(ptr->name,name1)==0)
              break;
    }
      for(qtr=head->next;qtr;qtr=qtr->next)
    {
      if(strcmp(qtr->name,name2)==0)
              break;
    }
    ptr->next=qtr->next;
    ptr_pre->next=qtr;
    qtr->next=ptr;
}

void my_sort(struct basic_account* head){
  //if no item in this linked list, then return.
    if(num<=500){
      struct Information  *tail1,*tail2;
      printf("---1.name 2.money 3.date---\n");
      int state;
      scanf("%d", &state);
      if(head->next == NULL){
        wait_screen();
        return;
      }
      //Use bubble sorting(from small to large), but replace inner for loop with while loop.
      struct basic_account* qtr;
      if(state==1 || state==2 || state==3)
      {
        for(int i=0;i<num-1;i++)
        {
            //initialize qtr
            qtr = head->next;
            //To make sure that qtr and qtr->next can be exchange, "qtr->next!=NULL" is necessary.
            while(qtr->next!=NULL)
            {
                switch(state){
                  case 1: // name
                    if(strcmp(qtr->name, qtr->next->name)>0)
                    //Because Swap() function will cause qtr=qtr->next, "qtr = qtr->next" is not necessary in this block.
                        Swap(head, qtr->name, qtr->next->name);
                    else
                        qtr = qtr->next;
                    break;
                  case 2: // money
                    if((qtr->money - qtr->trade->loan) > (qtr->next->money - qtr->next->trade->loan))
                    //Because Swap() function will cause qtr=qtr->next, "qtr = qtr->next" is not necessary in this block.
                        Swap(head, qtr->name, qtr->next->name);
                    else
                        qtr = qtr->next;
                    break;
                  case 3: // date
                    // get tail(the newest date)
                    tail1 = qtr->trade;
                    tail2 = qtr->next->trade;
                    while(tail1->nt) {tail1 = tail1->nt;}
                    while(tail2->nt) {tail2 = tail2->nt;}
                    if(strcmp(tail1->date, tail2->date)>0)
                    //Because Swap() function will cause qtr=qtr->next, "qtr = qtr->next" is not necessary in this block.
                        Swap(head, qtr->name, qtr->next->name);
                    else
                        qtr = qtr->next;
                    break;
                }
            }
        }
      }
      else printf("invalid input.\n");
      wait_screen();
    }
    else
      my_sort_BST(head);
}