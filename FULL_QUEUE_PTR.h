#ifndef FULL_QUEUE_PTR
#define FULL_QUEUE_PTR

#include "STRUCT.h"

struct node_of_queue_
{
	group* data;
	struct node_of_queue_* next;
	struct node_of_queue_* prev;
};

typedef struct node_of_queue_ itemptr;

struct _Queue_
{
	itemptr* start;
	itemptr* end;
};

typedef struct _Queue_ waitptr;

void PrintQueuePtr(waitptr* queue);

void PrintFirstInQueuePtr(waitptr* queue);

itemptr* CreateNodePtr(itemptr* node, group* grp);

waitptr* InitQueuePtr(waitptr* queue);

waitptr* EnQueuePtr(waitptr* queue, group* init_group);

waitptr* DeQueuePtr(waitptr* queue, char flag);

waitptr* DeleteQueuePtr(waitptr* queue);

#endif
