#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: Pointer to the first node of the list
 * @number:Number n of the node to be inserted
 * Return: The address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = NULL;
	listint_t *new_node = malloc(sizeof(listint_t *));

	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = number;
	if (*head == NULL)
	{
		*(head) = new_node;
		return (new_node);
	}

	for (current = *head ; current->next != NULL ; current = current->next)
	{
		if (current->n <= new_node->n && current->next->n >= new_node->n)
		{
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}
		if (current->n > new_node->n)
		{
			new_node->next = current;
			*head = new_node;
			return (new_node);
		}
	}
	if (current->next == NULL && current->n <= new_node->n)
	{
		current->next = new_node;
		new_node->next = NULL;
		return (new_node);
	}
	return (NULL);
}

