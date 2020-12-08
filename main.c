#include "parser/parse.h"
#include <stdio.h>

void fill_list(t_list **list)
{
	int i;
	t_word *word;
	t_list *elem;

	i = 0;
	while (i != 10)
	{
		word = word_constructor("123");
		elem = ft_lstnew(word);
		ft_lstadd_back(list, elem);
		i++;
	}
}

int main()
{
	t_list *list;
	t_list *elem;

	list = NULL;
	fill_list(&list);

	elem = list;
	while (elem != NULL)
	{
		printf("%s\n", ((t_word *)elem->content)->word);
		elem = elem->next;
	}
	ft_lstclear(&list, (void (*)(void *))word_destructor);
	return 0;
}
