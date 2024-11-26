/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:16:29 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/24 17:04:40 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include<stdio.h>

int	get_exit_status(int status)
{	
	static int	exit_status = 0;

	if (status != _LAST_STATUS)
		exit_status = status;
	return (exit_status);
}

void set_exit_status(int status)
{
	get_exit_status(status);
}
