/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:45:04 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/14 07:08:20 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGINT_H
# define SIGINT_H

static int	g_sigint;

void		setup_sigint(void);
void		signal_sigquit(int sig);
void		signal_sigint(int sig);

#endif // SIGINT_H
