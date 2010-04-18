#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define LIST_END_ID INT_MAX
#define LIST_BEGIN_ID INT_MIN
#define LIST_BEGIN 0
#define LIST_END 1

#define DIR_LEFT = 0
#define DIR_RIGHT = 1
#define DIR_UP = 0
#define DIR_DOWN = 1

struct _List
{
    int id;
    char *key;
    char *data;
    struct _List *ptr[2];
    struct _List *end[2];
};

typedef struct _List List;

struct _Cell
{
  struct _Cell *ptr[2];
  unsigned int data;
};

typedef struct _Cell Cell;

void
list_init(List *li)
{
    li = (List *) calloc(2,sizeof(List));
    li[0].id = LIST_BEGIN_ID;
    li[0].key = NULL;
    li[0].ptr[DIR_UP] = NULL;
    li[0].end[LIST_BEGIN] = NULL;
    li[0].ptr[DIR_DOWN] = li+1;
    li[0].end[LIST_END] = NULL;
    li[0].data = NULL;

    li[1].id = LIST_END_ID;
    li[1].key = NULL;
    li[1].data = NULL;
    li[1].ptr[DIR_DOWN] = NULL;
    li[1].ptr[DIR_UP] = li;
    li[1].end[LIST_BEGIN] = NULL;
    li[1].end[LIST_END] =NULL;
}

void
list_append(List *li)
{

}


Cell *
init_cells (Cell *cp, size_t size)
{
  int i;
  cp = (Cell *) calloc (size, sizeof (Cell));
  for (i = 0; i < size; i++)
    {
      cp[i].data = 0;
      cp[i].ptr[0] = NULL;
      cp[i].ptr[0] = NULL;
    }
  return cp;
}

void
load_tape (Cell *tape)
{
}

int
main(int argc,char **argv)
{
    exit(EXIT_SUCCESS);
}
