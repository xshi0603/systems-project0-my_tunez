struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node *, char *, char *);
struct song_node * insert_ordered(struct song_node *, char *, char *);
void print_list(struct song_node *);
struct song_node * find_int(struct song_node *, int);
char*  find_artist(struct song_node *);
struct song_node * random_pointer(struct song_node *);
struct song_node * rm_song(struct song_node *, int);
struct song_node * free_list(struct song_node *);
