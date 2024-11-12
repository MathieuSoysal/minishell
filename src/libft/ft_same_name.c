/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_same_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:20:30 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:51:08 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_same_name(char *name1, char *name2)
{
	if (!name1 || !name2)
		return (0);
	return (ft_strcmp(name1, name2) == 0);
}
