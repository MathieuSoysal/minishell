/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:09:34 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 17:43:27 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




void exit_handler(int n_exit)
{
    if (n_exit == 1)
        ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
    exit(1);
}

void free_in_path(char **allpath, char **s_cmd)
{
    ft_free_tab(allpath);
    ft_free_tab(s_cmd);
}

void ft_free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}
