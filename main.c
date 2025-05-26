#include "FULL_QUEUE.h"
#include "FULL_QUEUE_PTR.h"

int main()
{
	waitptr* queue = NULL;
	group* buff = NULL;

	buff = initGroup(buff, "", "", 1950, 0);
	queue = EnQueuePtr(queue, buff);

	buff = initGroup(buff, "", "", 1980, 0);
	queue = EnQueuePtr(queue, buff);
	
	buff = initGroup(buff, "", "", 2000, 0);
	queue = EnQueuePtr(queue, buff);
	
	buff = initGroup(buff, "", "", 2000, 1);
	queue = EnQueuePtr(queue, buff);
	
	buff = initGroup(buff, "", "", 2010, 1);
	queue = EnQueuePtr(queue, buff);

	printf("\t\t\tEntered queue:\n");
	PrintQueuePtr(queue);

	queue = DeQueuePtr(queue, 1);
	queue = DeQueuePtr(queue, 1);
	queue = DeQueuePtr(queue, 1);
	
	printf("\t\t\tQueue without 3 ""extracted"" elements\n");
	PrintQueuePtr(queue);

	queue = DeleteQueuePtr(queue);

	PrintQueuePtr(queue);

	return 0;
}
