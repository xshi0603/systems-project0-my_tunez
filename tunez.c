#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
  x->next = temp;
  return front;
}

void print_list(struct song_node *x) {
  while (x) {
    printf("%s:%s |", x->artist, x->name);
    x = x->next;
  }
  printf("\n\n");
}

void print_node(struct song_node *x) {

  printf("%s:%s |", x->artist, x->name);
  
}

struct song_node * find_artist(struct song_node *x, char *s_artist) {
  while(x) {
    if (strcmp(x->artist, s_artist) == 0) {
      return x;
    }
    x = x->next;
  }
}

void print_letter(struct song_node *x, char letter) {
  
  while(x) {
    //printf("%d%d", x->artist[0], letter);
    if (x->artist[0] == letter) {
      print_node(x);
    }
    x = x->next;
  }
  printf("\n\n");
}

void songs_by_artist(struct song_node *x, char *s_artist) {

  while(x) {
    if (strcmp(x->artist, s_artist) == 0) {
      print_node(x);
    }
    x = x->next;
  }
  printf("\n\n");
  
}

struct song_node * shuffle(struct song_node *x) {
 
  struct song_node *temp = (struct song_node *)malloc(sizeof(struct song_node));
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
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
  new = x;
  return new;
}


struct song_node * free_list(struct song_node * x) {
  
  struct song_node *prev;
  while (x) {
    prev = x;
    x = x->next;
    free(prev);
    prev = NULL;
  }    

  return x;
  
}

/*
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
*/


int main() {
  struct song_node *tester = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(tester->artist, "Smash Mouth");\
  strcpy(tester->name, "All Star");
  tester->next = NULL;
  
  printf("Printing single node\n");
  print_list(tester);
  
  printf("Adding many nodes and then reprinting\n");
  tester = insert_ordered(tester, "Faded", "Alan Walker");
  tester = insert_ordered(tester, "Sing Me to Sleep", "Alan Walker");
  tester = insert_ordered(tester, "Tired", "Alan Walker");
  tester = insert_ordered(tester, "Too Good at Goodbyes", "Sam Smith");
  tester = insert_ordered(tester, "Ride" , "Twenty one pilots");
  tester = insert_ordered(tester, "Look What You Made Me Do", "Taylor Swift");
  tester = insert_ordered(tester, "Love Story", "Taylor Swift");
  tester = insert_ordered(tester, "Dusk til Dawn", "Zayn");
  print_list(tester);

  printf("Finding \"Sam Smith\" and returning a pointer\n");
  print_list(find_artist(tester, "Sam Smith"));

  printf("Printing nodes with letter \"S\"\n");
  print_letter(tester, 'S');

  printf("Printing nodes with artist \"Taylor Swift\"\n");
  songs_by_artist(tester, "Taylor Swift");

  printf("Testing shuffle\n");
  print_list(shuffle(tester));

  printf("Freeing the list and printing\n");
  tester = free_list(tester);
  print_list(tester);
}
