# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:04:44 by kahoumou          #+#    #+#              #
#    Updated: 2024/07/29 15:13:05 by kahoumou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myprog
CC = gcc
CFLAGS = -Werror -Wextra -Wall -g3
RM = rm -rf

# Path for libft
LIBFT_PATH = exec_part/libft/
LIBFT = $(LIBFT_PATH)/libft.a

# List of main sources
SRCS = exec_part/builtins/cd.c \
       exec_part/builtins/echo.c \
       exec_part/builtins/take_change_all.c \
       exec_part/builtins/testeur.c \
       exec_part/builtins/print_all_adress_fd.c \
       exec_part/builtins/get_env_var_with_name.c \
       exec_part/builtins/get_export_variable_name.c \
       exec_part/builtins/add_new_variable.c \
       exec_part/builtins/assign_env_var_id.c \
       exec_part/builtins/change_env_value_with_name.c \
       exec_part/builtins/change_or_create_var.c \
       exec_part/builtins/export_testeur.c \
       exec_part/builtins/export.c \
       exec_part/builtins/get_env_varible_value.c \
       exec_part/builtins/get_last_env_var.c \
       exec_part/builtins/is_blank.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

# Rule to build the libft library
$(LIBFT):
	make -C $(LIBFT_PATH)

# Target to compile everything
all: $(NAME)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	$(RM) $(OBJS)

# Clean all files, including the libft
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

# Rebuild all files
re: fclean all
