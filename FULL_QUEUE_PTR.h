#ifndef FULL_QUEUE
#define FULL_QUEUE

#include "STRUCT.h"

// Описание элемента очереди

struct node_of_queue
{
	group data;
	struct node_of_queue* next;
	struct node_of_queue* prev;
};

typedef struct node_of_queue item;

// Описание самой очереди

struct Queue_
{
	item* start;
	item* end;
};

typedef struct Queue_ wait;

// Вывод всей очереди
void PrintQueue(wait* queue);

// Создание узла - элемпента очереди
item* CreateNode(item* node, group grp);

// Инициализация очереди
wait* InitQueue(wait* queue);

// Вставка элемента в начала
wait* EnQueue(wait* queue, group init_group);

// Удаление элемента из конца (первого вошедшего узла)
wait* DeQueue(wait* queue, char flag);

// Удаление всей очереди
wait* DeleteQueue(wait* queue);

#endif
