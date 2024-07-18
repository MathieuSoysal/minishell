/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:03:27 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/18 05:07:55 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_parser.h"
#include <stdbool.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*get_word_until(char const *command_line, size_t *i,
		char const delimiter)
{
	char	*word;
	size_t	j;

	j = *i;
	while (command_line[j] && command_line[j] != delimiter)
		j++;
	word = ft_strndup(command_line + *i, j - *i);
	*i = j;
	return (word);
}

char	*concatenate(t_double_linked_list *list)
{
	char	*result;
	char	*temp;

	temp = NULL;
	result = ft_strdup("");
	if (!result)
		return (NULL);
	while (list->size > 0)
	{
		free(temp);
		temp = double_linked_list_pop_first(list);
		if (!temp)
			return (free(result), NULL);
		result = ft_strjoin(result, temp);
		if (!result)
			return (NULL);
	}
	free(temp);
	return (result);
}
