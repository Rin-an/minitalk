NAME_S = server
NAME_C = client
NAME_CB = client_bonus
NAME_SB = server_bonus

RM = rm -rf

HEADER = mandatory/minitalk.h
HEADER_B = bonus/minitalk_bonus.h

SRC_S = mandatory/server/server.c mandatory/utils.c
SRC_C = mandatory/client/client.c mandatory/utils.c
SRC_CB = bonus/client/client_bonus.c bonus/utils_bonus.c
SRC_SB = bonus/server/server_bonus.c bonus/utils_bonus.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_CB = $(SRC_CB:.c=.o)
OBJ_SB = $(SRC_SB:.c=.o)

$(NAME_S): $(OBJ_S) $(HEADER)
	cc $(OBJ_S) -o $(NAME_S)
$(NAME_C): $(OBJ_C) $(HEADER) 
	cc $(OBJ_C) -o $(NAME_C)
$(NAME_CB): $(OBJ_CB) $(HEADER_B)
	cc $(OBJ_CB) -o $(NAME_CB)
$(NAME_SB): $(OBJ_SB) $(HEADER_B)
	cc $(OBJ_SB) -o $(NAME_SB)

%.o: %.c
	gcc -Wall -Wextra -Werror  -o $@ -c $< -g

all: $(NAME_S) $(NAME_C)

bonus: $(NAME_CB) $(NAME_SB)

clean:
	$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_CB) $(OBJ_SB)

fclean: clean
	$(RM) $(NAME_C) $(NAME_S) $(NAME_CB) $(NAME_SB)

re: fclean all

.PHONY: clean fclean re
