# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wta <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/06 09:33:53 by wta               #+#    #+#              #
#    Updated: 2019/01/06 10:23:21 by wta              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ====================================================================== COLOR #
_GREEN		=	\033[0;32m
_WHITE		=	\033[m
_YELLOW		=	\033[0;33m
_DYELLOW	=	\x1b[33;01m
# ================================================================== VARIABLES #
PUSH_SWAP	=	push_swap
CHECKER		=	checker
SRCSDIR		=	srcs
LIBFTPATH	=	libft
LIBFTLIB	=	libft.a
LIBFT		=	$(addprefix $(LIBFTPATH)/,$(LIBFTLIB))
INCDIR		=	includes
OBJDIR		=	objs
OBJ			=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
CC			=	gcc
INC			=	-I $(INCDIR) -I .
CFLAGS		=	-Wall -Wextra -Werror
CHECKERMAIN	=	\
checker.c
PSMAIN		=	\
push_swap.c
CHECKEROBJ	=	$(addprefix $(OBJDIR)/, $(CHECKERMAIN:.c=.o))
PSOBJ		=	$(addprefix $(OBJDIR)/, $(PSMAIN:.c=.o))
SRCS		=			\
do_op.c					\
insertion_sort.c		\
insertion_sort_utils.c	\
link_list.c				\
operations.c			\
operations2.c			\
read_args.c				\
selection_sort.c		\
selection_sort_utils.c	\
selection_sort_utils2.c	\
tab_sort.c				\
utils.c					\
utils2.c				\
visu.c
HEADER		=	\
do_op.h			\
link_list.h		\
operations.h	\
push_swap.h		\
read.h			\
sort.h			\
tab_sort.h
# ====================================================================== RULES #
all : $(PUSH_SWAP)
# ==================================================================== CHECKER #
$(PUSH_SWAP) : $(LIBFT) $(OBJ) $(CHECKEROBJ) $(PSOBJ)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(PSOBJ) $(LIBFT) -o $@
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(CHECKEROBJ) $(LIBFT) -o $(CHECKER)
	@echo "\n$(_GREEN)[CREATED]$(_WHITE)" $@
	@echo "$(_GREEN)[CREATED]$(_WHITE)" $(CHECKER)
	@echo "All objects files are in $(_DYELLOW)obj$(_WHITE)/"
# =================================================================== MKDIROBJ #
$(OBJDIR) :
	@mkdir $@
	@echo "\n$(_YELLOW)[CREATED]$(_WHITE)" $@
# ================================================================ PUSH_SWAP.O #
$(PSOBJ) : $(addprefix $(SRCSDIR)/, $(PSMAIN)) $(addprefix $(INCDIR)/, $(HEADER)) | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "\r                                                              \r\c"
	@echo "$(_GREEN)[OK]$(_WHITE) $@\c"
$(CHECKEROBJ) : $(addprefix $(SRCSDIR)/, $(CHECKERMAIN)) $(addprefix $(INCDIR)/, $(HEADER)) | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "\r                                                              \r\c"
	@echo "$(_GREEN)[OK]$(_WHITE) $@\c"
# ======================================================================== OBJ #
$(addprefix $(OBJDIR)/,%.o) : $(addprefix $(SRCSDIR)/,%.c) $(addprefix $(INCDIR)/,$(HEADER)) | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "\r                                                              \r\c"
	@echo "$(_GREEN)[OK]$(_WHITE) $@\c"
#======================================================================= LIBFT #
$(LIBFT) :
	@make -C $(LIBFTPATH)
	@echo "\r                                                              \r\c"
	@echo "$(_GREEN)[OK]$(_WHITE) $@\c"
#======================================================================= CLEAN #
clean :
	@make -C $(LIBFTPATH) clean
	@echo "$(_DYELLOW)[CLEAN]$(_WHITE)" LIBFT
	@rm -f $(OBJ)
	@echo "$(_DYELLOW)[DELETED]$(_WHITE)" OBJECTS
	@rm -rf $(OBJDIR)
	@echo "$(_DYELLOW)[DELETED]$(_WHITE)" $(OBJDIR)/
#====================================================================== FCLEAN #
fclean : clean
	@make -C $(LIBFTPATH) fclean
	@echo "$(_DYELLOW)[FCLEAN]$(_WHITE)" LIBFT
	@rm -f	$(PUSH_SWAP)
	@rm -f	$(CHECKER)
	@echo "$(_DYELLOW)[DELETED]$(_WHITE)" $(PUSH_SWAP)
	@echo "$(_DYELLOW)[DELETED]$(_WHITE)" $(CHECKER)
#========================================================================== RE #
re : fclean all
#============================================================================= #
