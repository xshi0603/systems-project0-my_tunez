struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct node * insert_front(struct song_node *, int);
struct node * insert_ordered(struct song_node *, int);
void print_list(struct song_node *);
struct node * find_int(struct song_node *, int);
//char*  find_artist(struct node *);
struct node * random_pointer(struct song_node *);
struct node * rm_song(struct song_node *, int);
struct node * free_list(struct song_node *);
