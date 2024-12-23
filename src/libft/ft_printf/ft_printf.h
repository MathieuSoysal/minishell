/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:03:07 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:47:41 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_print_putstr(char *str, int *lenght);
void	ft_print_putnbr(int nb, int *lenght);
void	ft_hexadecimal(unsigned int nb, int *lenght, char hex);
void	ft_pourcentage(int *lenght);
void	ft_print_unsigned(unsigned int nb, int *lenght);
void	ft_print_pointeur(size_t p, int *lenght);
void	ft_putchar_lenght(char c, int *lenght);
void	count_putchar_fd(char c, int *count, int fd);
int		ft_printf_fd(int fd, const char *str, ...);

#endif
