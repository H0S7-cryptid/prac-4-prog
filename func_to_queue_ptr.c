#include "FULL_QUEUE_PTR.h"

void PrintQueuePtr(waitptr* queue)
{
	if (queue == NULL || (queue->start == NULL && queue->end == NULL))
	{
		printf("\t\t\tNo elements to print\n");
		return;
	}

	for (itemptr* tmp = queue->end; tmp != NULL; tmp = tmp)
	{
		printGroup(tmp->data);
		tmp = tmp->prev;
	}
}

void PrintFirstInQueuePtr(waitptr* queue)
{
	printf("\t\t\tNext for extraction:\n");
	if (queue->end != NULL) printGroup(queue->end->data);
	else return;
}

itemptr* CreateNodePtr(itemptr* node, group* grp)
{
	node = (itemptr*)malloc(sizeof(itemptr));
	if (!node) return NULL;
	node->data = (group*)malloc(sizeof(group));
	if (!node->data) return NULL;
	*(node->data) = *(grp);
	node->next = NULL;
	node->prev = NULL;
	return node;
}

waitptr* InitQueuePtr(waitptr* queue)
{
	queue = (waitptr*)malloc(sizeof(waitptr));
	if (!queue) return NULL;

	queue->start = (itemptr*)malloc(sizeof(itemptr));
	if (!queue->start) return NULL;
	queue->start->data = (group*)malloc(sizeof(group));
	if (!queue->start->data) return NULL;
	queue->start = NULL;

	queue->end = (itemptr*)malloc(sizeof(itemptr));
	if (!queue->end) return NULL;
	queue->end->data = (group*)malloc(sizeof(group));
	if (!queue->end->data) return NULL;
	queue->end = NULL;

	return queue;
}

waitptr* EnQueuePtr(waitptr* queue, group* init_group)
{
	if (queue == NULL) queue = InitQueuePtr(queue); 

	if (init_group == NULL) return NULL;

	itemptr* ins_node = NULL; 
	ins_node = CreateNodePtr(ins_node, init_group); 

	// Вставка самого первого элемента 
	if (queue->start == NULL && queue->end == NULL) 
	{
		queue->start = ins_node; 
		queue->end = ins_node; 
		return queue; 
	}

	// Инизиализация начала очереди
	ins_node->next = queue->start; 
	queue->start = ins_node; 

	// Инициализация конца очереди.
	itemptr* tmp = queue->end; 
	while (tmp->prev != NULL) tmp = tmp->prev; 
	tmp->prev = ins_node; 

	return queue;
}

waitptr* DeQueuePtr(waitptr* queue, char flag)
{
	itemptr* temp = NULL;

	if (flag) PrintFirstInQueuePtr(queue);

	temp = queue->end; 
	queue->end = queue->end->prev; 
	if (queue->end != NULL) queue->end->next = NULL; 
	else
	{
		temp = queue->start; 
		free(temp);
		queue->start = NULL; 
		queue->end = NULL; 
		return queue; 
	}
	free(temp->data);
	free(temp);
	return queue;
}

waitptr* DeleteQueuePtr(waitptr* queue)
{
	while (1)
	{
		if (queue->start != NULL && queue->end != NULL) queue = DeQueuePtr(queue, 0); 
		else return NULL;
	}
}
