/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:43:56 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 12:19:34 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../structures/double_linked_list/double_linked_list.h"
#include "../internal_parser.h"

char	**split_by_space(char const *command_line)
{
	t_double_linked_list	*list;
	size_t					i;
	char					*word;

	word = NULL;
	list = double_linked_list_create();
	if (!list)
		return (NULL);
	i = 0;
	while (command_line && command_line[i] != '\0' && command_line[i] != '\n')
	{
		if (command_line[i] != ' ')
		{
			word = get_word(command_line, &i, ' ');
			if (word == NULL)
				return (NULL);
			double_linked_list_add_last(list, word);
		}
		else
			i++;
	}
	return (double_linked_list_to_array(list));
}
