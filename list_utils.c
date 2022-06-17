#include "multitask.h"

t_task	*new_task(char *content, int nb)
{
	int	l;
	t_task	*new;

	new = malloc(sizeof(t_task));
	if (!new)
		return (NULL);
	l = strlen(content);
	new->Content = content;
	new->Lib_task = ft_strjoin("task ", ft_itoa(nb));
	new->Level_task = 1;
	new->Mem_task = 512;
	new->State_task = 0;
	new->Time_task = l;
	new->next = NULL;
	return (new);
}

t_task	*copy_task(t_task *node)
{
	t_task	*new;
	new = malloc(sizeof(t_task));
	if (!new)
		return (NULL);
	new->Content = node->Content;
	new->Lib_task = node->Lib_task;
	new->Level_task = node->Mem_task;
	new->State_task = 1;
	new->Time_task = node->Time_task;
	new->next = NULL;
	return (new);
}
void	add_back(t_task **lst, t_task *new)
{
	t_task	*last;

	if (!(*lst))
	{
		add_front(lst, new);
		return ;
	}
	last = find_last(*lst);
	if (new->next == NULL)
		last->next = new;
	while (new->next)
	{
		last->next = new;
		new = new->next;
	}
}

void	add_front(t_task **lst, t_task *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	circular_push(t_task **head, t_task *new)
{
	t_task	*tmp;

	tmp = *head;
	if (!(*head))
	{
		*head = new;
		new->next = *head;
	}
	else
	{
		new->next = *head;
		while (tmp->next != *head)
			tmp = tmp->next;
		tmp->next = new;
		*head = new;
	}
}

t_task	*find_last(t_task *lst)
{
	t_task	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
/*
void	clear(t_task **lst, void (*del)(void *))
{
	t_task	*temp;

	if (!(*lst))
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		delone(lst, del);
		*lst = temp;
	}
	lst = NULL;
}

void	delone(t_task *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

int	find_size(t_task *lst)
{
	t_task	*temp;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	temp = lst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}*/

