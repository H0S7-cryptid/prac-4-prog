#include "FULL_QUEUE.h"

void PrintQueue(wait* queue)
{
	if (queue == NULL || (queue->start == NULL && queue->end == NULL)) return;

	for (item* tmp = queue->end; tmp != NULL; tmp = tmp)
	{
		printGroup(&(tmp->data));
		tmp = tmp->prev;
	}
}

void PrintFirstInQueue(wait* queue)
{
	printf("\t\t\tNext for extraction:\n");
	if (queue->end != NULL) printGroup(&(queue->end->data));
	else return;
}

item* CreateNode(item* node, group grp)
{
	node = (item*)malloc(sizeof(item));
	if (!node) return NULL;
	node->data = grp;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

wait* InitQueue(wait* queue)
{
	queue = (wait*)malloc(sizeof(wait));
	if (!queue) return NULL;

	queue->start = (item*)malloc(sizeof(item));
	if (!queue->start) return NULL;
	queue->start = NULL;

	queue->end = (item*)malloc(sizeof(item));
	if (!queue->end) return NULL;
	queue->end = NULL;

	return queue;
}

wait* EnQueue(wait* queue, group init_group)
{
	if (queue == NULL) queue = InitQueue(queue);

	item* ins_node = NULL;
	ins_node = CreateNode(ins_node, init_group);

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
	item* tmp = queue->end;
	while (tmp->prev != NULL) tmp = tmp->prev;
	tmp->prev = ins_node;

	return queue;
}

wait* DeQueue(wait* queue, char flag)
{
	item* temp = NULL;

	if (flag) PrintFirstInQueue(queue);

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

	free(temp);
	return queue;
}

wait* DeleteQueue(wait* queue)
{
	while (1)
	{
		if (queue->start != NULL && queue->end != NULL) queue = DeQueue(queue, 0);
		else return NULL;
	}
}
