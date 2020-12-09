#ifndef MINISHELL_PARSE_H
#define MINISHELL_PARSE_H
#include "utils/utils.h"


/*
** list of words
*/
typedef struct		s_word
{
	char			*word;
	int 			len;
}					t_word;

t_word				*word_constructor(char *word);
void 				word_destructor(t_word *word);

t_list				*parse(char *command_line);

#endif //MINISHELL_PARSE_H
