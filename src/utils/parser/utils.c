/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:03:27 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/25 14:18:18 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_parser.h"
#include <stdbool.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_word_until_char(char const *command_line, size_t *i,
		char const delimiter, bool *is_string_mode)
{
	char	*word;
	size_t	j;

	j = *i;
	while (command_line[j] && command_line[j] != delimiter)
	{
		j++;
		if (command_line[j] == '\'' || command_line[j] == '\"')
		{
			if (*is_string_mode == false)
				*is_string_mode = true;
			else if (*is_string_mode == true
				&& command_line[j] == *is_string_mode)
				*is_string_mode = false;
		}
	}
	word = ft_strndup(command_line + *i, j - *i);
	*i = j;
	return (word);
}

char	*get_from_env(char **env, char *word)
{
	char	*result;
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], word, ft_strlen(word)) == 0
			&& env[i][ft_strlen(word)] == '=')
		{
			result = ft_strdup(env[i] + ft_strlen(word) + 1);
			free(word);
			return (result);
		}
		i++;
	}
	free(word);
	result = ft_strdup("");
	return (result);
}
