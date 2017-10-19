#include <stdio.h>
#include <stdlib.h>
//#include <random.h>

struct node { int i; struct node *next; };

struct node * insert_front(struct node *, int);
struct node * insert_ordered(struct node *, int);
void print_list(struct node *);
struct node * find_int(struct node *, int);
//char*  find_artist(struct node *);
struct node * random_pointer(struct node *);
struct node * rm_song(struct node *, int);
struct node * free_list(struct node *);

struct node * insert_front(struct node * x, int a) {

  struct node *front = (struct node *)malloc(sizeof(struct node));
  front->next = x;
  front->i = a;
  return front;
  
}

struct node * insert_ordered(struct node * x, int a) {
  
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  struct node *front = (struct node *)malloc(sizeof(struct node));
  front = x; 
  temp->i = a;
  if (a < x->i) {
    temp->next = x;
    return temp;
  }
  else {
    while(x->next) {
      if (a < x->next->i) {
	temp->next = x->next;
	x->next = temp;
	return front;	
      }
      else {
	x = x->next;
      }
    }
  }
}

void print_list(struct node *x) {
  while (x) {
    printf("%d\n", x->i);
    x = x->next;
  }
}

struct node *  find_int(struct node *x, int a) {
  while(x) {
    if (x->i == a) {
      return x;
    }
    x = x->next;
  }
}

struct node * random_pointer(struct node *x) {
 
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp = x;
  int counter = 0;
  srand(time(NULL));
  int rndmNum;
  while (temp) {
    counter++;
    temp = temp->next;
  } 
  for (rndmNum = rand() % counter;rndmNum; rndmNum --) {
    x = x->next;
  }
  return x;
}

struct node * rm_song(struct node *x, int a) {

  struct node *temp = (struct node *)malloc(sizeof(struct node));
  struct node *front = (struct node *)malloc(sizeof(struct node));
  front = x;
  
  if (a == x->i) {
    return x->next;
  }

  while(x->next) {

    if (x->next->i == a) {
      x->next = x->next->next;
      return front;
    }
    x = x->next;
  }
}

struct node * free_list(struct node * x) {
  
  struct node *prev;
  while (x) {
    prev = x;
    x = x->next;
    free(prev);
    prev = NULL;
  }    

  return x;
  
}

int main () {

  struct node *tester = NULL;
  
  printf("The list is:\n");
  print_list(tester);
  printf("\n");
  
  int i;

  for (i = 15;i > 10; i -= 2) {
    tester = insert_front(tester,i);
  }
  
  tester = insert_ordered(tester, 12);
  tester = insert_ordered(tester, 12);
  
  printf("\n");
  printf("The list now is:\n");
  print_list(tester);

  printf("Finding 12 in list and printing\n");
  print_list(find_int(tester, 12));
  
  printf("Finding random pointer and printing\n");
  print_list(random_pointer(tester));

  printf("Removing 13\n");
  tester = rm_song(tester,13);
  print_list(tester);

  printf("\n");
  printf("The list after clearing is: ");
  print_list(free_list(tester));
  printf("\n");


}


