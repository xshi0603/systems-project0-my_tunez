#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"

struct song_node * insert_front(struct song_node * x, char *s_name, char *s_artist) {

  struct song_node *front = (struct song_node *)malloc(sizeof(struct song_node));
  front->next = x;
  strcpy(front->name, s_name);
  strcpy(front->artist, s_artist);
  return front;
  
}


struct song_node * insert_ordered(struct song_node *x, char *s_name, char *s_artist) {
  struct song_node *temp = (struct song_node *)malloc(sizeof(struct song_node));
  struct song_node *front = (struct song_node *)malloc(sizeof(struct song_node));
  front = x; 
  strcpy(temp->name, s_name);
  strcpy(temp->artist, s_artist);

  if (strcmp(s_artist, x->artist) < 0) {
    temp->next = x;
    return temp;
  }
  else {
    while(x->next) {
      if (strcmp(s_artist, x->next->artist) < 0) {
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

void print_list(struct song_node *x) {
  while (x) {
    printf("%s:%s |", x->artist, x->name);
    x = x->next;
  }
}

/*
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
*/

int main() {
  struct song_node *x;
  strcpy(x->artist, "Smash Mouth");
  /*
  strcpy(x->name, "All Star");
  x->next = NULL;
  
  printf("x");
  print_list(x);

  printf("x");
  */
}
