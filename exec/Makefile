# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:04:44 by kahoumou          #+#    #+#              #
#    Updated: 2024/07/29 15:01:51 by kahoumou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  myprog
CC  =  gcc
CFLAGS = -Werror -Wextra -Wall -g3
RM =  rm  -rf 
#road for libft 
LIBFT_PATH =  exec_part/libft/
LIBFT =  $(LIBFT_PATH)/libft.a

# #liste des sources principales
SRCS =	exec_part/builtins/cd.c\
		exec_part/builtins/echo.c \
		exec_part/builtins/take_change_all.c\
		exec_part/builtins/testeur.c\
		exec_part/builtins/print_all_adress_fd.c\
		exec_part/builtins/ get_env_var_with_name.c\
		exec_part/builtins/ get_export_variable_name.c\
		exec_part/builtins/add_new_variable.c\
		exec_part/builtins/assign_env_var_id.c\
		exec_part/builtins/change_env_value_with_name.c\
		exec_part/builtins/change_or_create_var.c\
		exec_part/builtins/export_testeur.c\
		exec/exec_part/builtins/export.c\
		exec_part/builtins/get_env_varible_value.c\
		exec_part/builtins/get_last_env_var.c\
		exec_part/builtins/is_blank.c
		
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)



#Regle pour construire la bibliotheque  libft
$(LIBFT):
		make -C $(LIBFT_PATH)

#Cibles  pour tout compiler
all: $(NAME)

# Règles pour compiler les fichiers sources en fichiers objet
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et des executables
clean : 
		$(RM) $(OBJS)
#clean all file
fclean : clean
		$(RM) $(NAME) 
		make fclean -C $(LIBFT_PATH)
#rebuilt all file
re : fclean  all

