/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:43:56 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/15 21:52:54 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../structures/double_linked_list/double_linked_list.h"
#include "internal_parser.h"

char	**split_by_space(char const *command_line)
{
	t_double_linked_list	*list;
	size_t					i;
	char					*word;

	list = double_linked_list_create();
	i = 0;
	while (command_line[i])
	{
		if (command_line[i] != ' ')
		{
			word = get_word(command_line, &i, ' ');
			double_linked_list_add_last(list, word);
		}
		i++;
	}
	return (double_linked_list_to_array(list));
}
