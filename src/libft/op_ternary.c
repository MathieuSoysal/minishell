/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:18:48 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:52:32 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	op_ternary(int cond, int cond1, int cond2)
{
	if (cond)
		return (cond1);
	else
		return (cond2);
	return (0);
}
