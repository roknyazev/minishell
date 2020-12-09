
#include "parse.h"
#include "stdio.h"

static t_list *parse_pipeline(char *pipeline_line)
{
	t_list	*command_list;
	t_list	*command;
	char	**command_lines;
	int 	i;

	command_list = NULL;
	command_lines = ft_split(pipeline_line, '|');
	i = 0;
	while (command_lines[i] != NULL)
	{
		command = ft_lstnew(ft_strdup(command_lines[i]));
		ft_lstadd_back(&command_list, command);
		i++;
	}
	return (command_list);
}

static void	fill_pipeline_list(t_list **pipeline_list, char **pipeline_lines)
{
	int 	i;
	t_list	*pipeline;
	t_list	*command_list;

	i = 0;
	while (pipeline_lines[i] != NULL)
	{
		command_list = parse_pipeline(pipeline_lines[i]);
		pipeline = ft_lstnew(command_list);
		ft_lstadd_back(pipeline_list, pipeline);
		i++;
	}
}

t_list	*parse(char *command_line)
{
	t_list	*pipeline_list;
	char	**pipeline_lines;
	int		i;

	pipeline_list = NULL;
	pipeline_lines = ft_split(command_line, ';'); //TODO обработать ошибку с несколькими точками с сзапятой
	fill_pipeline_list(&pipeline_list, pipeline_lines);
	i = 0;
	while (pipeline_lines[i] != NULL)
	{
		free(pipeline_lines[i]);
		i++;
	}
	free(pipeline_lines);
	return (pipeline_list);
}
