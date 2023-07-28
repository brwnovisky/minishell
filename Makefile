# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 15:52:33 by macarval          #+#    #+#              #
#    Updated: 2023/07/15 22:31:40 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

FILE_PATH		= ./src
OBJS_PATH		= ./obj
LIBFT_PATH		= ./libs/libft

HEADERS			= headers/minishell.h

LIBFT			= $(LIBFT_PATH)/libft.a

FILES			= main.c \
				minishell.c \
				pipe_list.c \
				execution.c \
				split_commands.c \
				built_in.c \
				echo.c \
				exit.c \
				env.c \
				export.c \
				pwd.c \
				unset.c \
				utils.c \
				cd.c \
				heredoc.c \
				signals.c \
				clear.c \
				args.c \
				flags.c \
				perror_free_exit.c \
				enviroment.c \
				quotes.c \
				validations_input.c \
				initial_env.c


IFLAGS			= -I./libs/libft
LFLAGS			= -L./libs/libft -lreadline -lft
CFLAGS			= -Wall -Wextra -Werror -g

CC				= gcc
RM				= rm -rf

OBJS			= $(addprefix $(OBJS_PATH)/, $(FILES:.c=.o))

all:			$(NAME)
$(NAME):		$(LIBFT) $(OBJS_PATH) $(OBJS)
				@$(CC) $(OBJS) -o $(NAME) $(LFLAGS)
				@echo "Minishell created!!"

$(OBJS_PATH):
				@mkdir -p $(OBJS_PATH)


$(OBJS_PATH)/%.o: $(FILE_PATH)/%.c $(HEADERS)
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJS_PATH)/%.o: $(FILE_PATH_BONUS)/%.c $(HEADERS_BONUS)
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
			
$(LIBFT):
				@make -C $(LIBFT_PATH)
					
clean:
				@$(RM) $(OBJS)
				@echo "clean Done!"

fclean:			clean
				@make -C $(LIBFT_PATH) fclean
				@$(RM) $(NAME) $(OBJS_PATH)
				@echo "fclean Done!"

re:				fclean all

.PHONY: 		all bonus clean fclean re


#VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
#--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose \
#--trace-children=yes --track-fds=yes \
#--log-file=valgrind-out.txt

VALGRIND 		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --trace-children=yes --log-file=valgrind-out.txt -s

valgrind:
	$(VALGRIND) ./minishell
