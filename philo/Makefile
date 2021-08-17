SHELL :=		/bin/bash

CC =			clang

FLAGS =			-Wall -Wextra -Werror -g

RM =			rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS =		./srcs/

MACOS_FLAGS =	-framework OpenGL -framework AppKit

LINUX_FLAGS =	-pthread

#FSAN =			-fsanitize=address

SRC =			main.c \
				error.c \
				parsing.c \
				threads.c \
				actions.c \
				utils/time.c \
				utils/ft_putstr_fd.c \
				utils/ft_atoi.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

#SRCS_BONUS =	$(addprefix $(DIR_SRCS), $(SRC_BONUS))

COMPIL =		$(FLAGS)# $(FSAN)

OBJS =			$(SRCS:.c=.o)

OBJS_BONUS =	$(SRCS_BONUS:.c=.o)

NAME =			philo

UNAME := 		$(shell uname)

ifeq ($(UNAME),Darwin)
	OS = -D MACOS
endif

ifeq ($(UNAME),Linux)
	OS = $(LINUX_FLAGS) -D LINUX
endif

all:			$(NAME)

$(NAME) :		echoCL $(OBJS) echoOK echoCS
				$(CC) $(COMPIL) $(OS) $(OBJS) -lncurses -o $(NAME)

%.o: %.c
				$(CC) $(FLAGS) $(OS) -I $(DIR_HEADERS) -c $< -o $@
				printf "$(GREEN)██"

bonus:			echoCL $(OBJS_BONUS) echoOK echoCS
				$(CC) $(COMPIL) $(OS) $(OBJS_BONUS) -lncurses -o $(NAME)

norme:			fclean
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:			echoCLEAN
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(LIBFT)
				$(RM) $(NAME)

git:			fclean
				git pull
				git add .
				git commit -m "$(shell date)"
				git push

re:				fclean all

.PHONY:			all, clean, fclean, re, norme, git, bonus

.SILENT:

# COLOR
#----------------reset----------------#
NC = \033[0m

#-----------Regular Colors------------#
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[33;33m
BLUE = \033[0;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[0;37m

###########################ECHO
echoCL:
	printf "\n$(YELLOW)===> Compiling $(RED)$(NAME)$(NC)\n"
echoOK:
	printf "$(GREEN) OK$(NC)\n"
echoCS :
	printf "$(GREEN)===> Compilation Success$(NC)\n"
echoCLEAN :
	printf "$(PURPLE)$(NAME) ===> Cleanning$(NC)\n"
echoFCLEAN :
	printf "$(PURPLE)$(NAME) ===> Cleanning Exec & Lib$(NC)\n"