##
## EPITECH PROJECT, 2023
## GGJ
## File description:
## Makefile
##

SRC =	src/main.c							\
		src/story/story.c					\
		src/menu/menu.c						\
		src/menu/init_menu.c				\
		src/menu/destroy_menu.c				\
		src/menu/keybinds/keybinds.c		\
		src/play/game.c						\
		src/play/init_game.c				\
		src/play/init_monsters.c			\
		src/play/level_1/level_1.c			\
		src/play/level_1/animation1.c		\
		src/play/level_2/transition2.c		\
		src/play/level_2/level_2.c			\
		src/play/level_2/animation2.c		\
		src/play/level_3/transition3.c		\
		src/play/level_3/level_3.c			\
		src/play/level_3/animation3.c		\
		src/play/level_4/transition4.c		\
		src/play/level_4/level_4.c			\
		src/play/level_4/animation4.c		\
		src/play/level_5/transition5.c		\
		src/play/level_5/level_5.c			\
		src/play/level_5/animation5.c		\
		src/play/end/transitionEnd.c		\
		src/play/end/transitionEnd2.c		\
		src/play/end/end.c					\
		sounds/sounds.c

OBJ =	$(SRC:.c=.o)

NAME =	underoots

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):
		@gcc -o $(NAME) $(SRC) $(CSFML) -lm
		@rm -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re:		fclean all