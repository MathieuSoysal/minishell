/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_signals_for_readline.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:13:06 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/07 16:16:01 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigint.h"

void	restore_signals_for_readline(void)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = signal_sigint;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}
