/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 05:26:30 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/18 22:07:55 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_parser.h"
#include <stdlib.h>

char	*apply_strings(char *str)
{
	int		i_src;
	int		i_dest;
	char	string_mode;
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	string_mode = '\0';
	i_dest = -1;
	i_src = -1;
	while (str[++i_src])
	{
		if ((str[i_src] == '\'' || str[i_src] == '\"') && string_mode == '\0')
			string_mode = str[i_src];
		else if (string_mode == str[i_src])
			string_mode = '\0';
		else
			new_str[++i_dest] = str[i_src];
	}
	new_str[++i_dest] = '\0';
	return (new_str);
}