/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list_optional.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:16:24 by hsoysal           #+#    #+#             */
/*   Updated: 2024/12/07 16:16:43 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"

bool	double_linked_list_has_next(t_double_linked_list *obj)
{
	return (obj->size > 0);
}
