/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:11:41 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:48:58 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int character)
{
	if (character >= 'a' && character <= 'z')
		return (1024);
	else if (character >= 'A' && character <= 'Z')
		return (1024);
	else
		return (0);
}
