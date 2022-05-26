##
## EPITECH PROJECT, 2020
## B-MUL-200-PAR-2-1
## File description:
## Makefile
##

#SRC =	data_edit_linklist_all.c	\
#		data_init_linklist_all.c	\
#		data_linklist_at.c	\
#		linklist_all.c	\
#		linklist_at.c	\
#		data_create.c	\

SRC =	sources/plinkst_all.c	\
		sources/plinkst_at.c	\

OBJ =	$(SRC:.c=.o)

NAME =	liblinkst.a

CPPFLAGS =  -iquote includes/

SRC_EXAMPLES =	example/example.c

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

example: all
	gcc $(SRC_EXAMPLES) -iquote includes -L./ -l linkst -g3

clean:
	@rm -f $(OBJ)
	@rm -f *~

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re