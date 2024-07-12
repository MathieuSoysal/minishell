# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:04:44 by kahoumou          #+#    #+#              #
#    Updated: 2024/07/11 19:15:24 by kahoumou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  myprog
CC  =  gcc
CFLAGS = -Werror -Wextra -Wall -g3
RM =  rm  -rf 
#road for libft 
LIBFT_PATH =  ../../libft/libft
LIBFT =  $(LIBFT_PATH)/libft.a

# #liste des sources principales
SRCS = exec_part/builtins/cd.c \
       exec_part/builtins/echo.c \
       exec_part/builtins/mem_malloc_str.c \
       exec_part/builtins/take_change_all.c\
       exec_part/builtins/testeur.c


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
		$(RM) $(SRCS:.c=.o)
#clean all file
fclean : clean
		$(RM) $(NAME) 
		make fclean -C $(LIBFT_PATH)
#rebuilt all file
re : fclean  all

