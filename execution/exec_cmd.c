/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:25:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 17:43:24 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




void exec_cmd(char *cmd, t_pipex *pipex)
{
        
    t_variables  var;
    
     var.s_cmd = ft_split(cmd, ' ');
    if (!var.s_cmd || !var.s_cmd[0])
    {
        ft_putstr_fd("pipex: command not found: ", 2);
        ft_putendl_fd(cmd, 2);
        if (var.s_cmd)
            ft_free_tab(var.s_cmd);
        exit(127);
    }
    var.path = get_path(var.s_cmd[0], pipex->env);
    if (execve(var.path, var.s_cmd, pipex->env) == -1)
    {
        ft_putstr_fd("pipex: command not found: ", 2);
        ft_putendl_fd(var.s_cmd[0], 2);
        ft_free_tab(var.s_cmd);
        free(var.path);
        exit(127);
    }
}
