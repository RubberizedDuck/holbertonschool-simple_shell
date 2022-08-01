#include "main.h"

/**
 * add_node - adds new node to the beginning of list_t
 * @head: pointer to start of the list
 * @str: pointer to string needing to be duplicated
 * Return: pointer to new node
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *newNode;
	list_t *prevNode;

	prevNode = *head;
	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (NULL);

	newNode->str = strdup(str);
	if (newNode->str == NULL)
		free(newNode);

	newNode->len = _strlen(newNode->str);
	newNode->next = prevNode;
	*head = newNode;

	return (newNode);
}

/**
 * add_node_end - add node to the end of linked list
 * @head: pointer to current head of node
 * @str: string needing to be duplicated
 * Return: pointer to new node
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newNode;
	list_t *prevNode;

	prevNode = *head;
	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (NULL);

	newNode->str = strdup(str);
	if (newNode->str == NULL)
		free(newNode);

	newNode->len = _strlen(newNode->str);
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}
	/* loops to the end of linked list */
	while (prevNode->next != NULL)
		prevNode = prevNode->next;

	/* when reaches end, assigs new address to new node */
	prevNode->next = newNode;
	return (newNode);
}

/**
 * print_list - prints the number of elements of struct list
 * @h: pointer to first struct list
 * Return: Number of elements created from struct list
 */

size_t print_list(const list_t *head)
{
	size_t numOfElements = 0;

	while (head != NULL)
	{
		printf("[%d] ", head->len);
		if (head->str == NULL)
			printf("(nil)\n");
		else
			printf("%s\n", head->str);
		numOfElements++;
		head = head->next;
	}
	return (numOfElements);
}

/**
 * free_list - free linked list memory
 * @head: pointer to start of the list
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
	free(head);
}

/**
 * list_len - returns number of elements in a linked struct
 * @h: pointer to first struct list
 * Return: Number of elements created from struct list
 */

size_t list_len(const list_t *head)
{
	size_t numOfElements = 0;

	while (head != NULL)
	{
		if (head->str == NULL)
			printf("(nil)\n");
		else
		numOfElements++;
		head = head->next;
	}
	return (numOfElements);
}
