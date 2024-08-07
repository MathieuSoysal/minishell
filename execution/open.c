/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:24:15 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 17:43:38 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




int open_file(char *file, int in_or_out, t_pipex *pipex) {
    
        
    if (in_or_out == 0)
        pipex->fd = open(file, O_RDONLY);
    else if (in_or_out == 1)
        pipex->fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else
        pipex -> fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    
    if (pipex -> fd < 0) {
        perror(file);
        exit(1);
    }
    return pipex->fd;
}