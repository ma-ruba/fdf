NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRCDIR = srcs/
OBJDIR = obj/

FILES = fdf	handle_errors visualization	map_conversion \
draw_xline draw_yline gradient	draw_parall	key_hook
SRC = $(addprefix $(SRCDIR), $(addsuffix .c,$(FILES)))
OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(FILES)))

LIBFT = ./libft/libftprintf.a 
INCDIR = -I ./includes
LIBLINK = -L ./libft -lftprintf
LIBINC = -I ./libft/includes

MLX		= ./miniLibX/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./miniLibX
MLX_LNK	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

all: $(LIBFT) $(MLX_LIN) $(NAME)

$(LIBFT):
	@make -C ./libft

$(MLX_LIB):
	make -C $(MLX)

$(OBJDIR):
	@echo "Creating FdF object files directory..."
	@mkdir $(OBJDIR)
	@echo "Directory created!"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(CC) $(FLAGS) $(MLX_INC) $(INCDIR) $(LIBINC) -c $< -o $@

$(NAME): $(OBJ)
	@echo "Compiling FdF..."
	@$(CC) $(LIBLINK) $(MLX_LNK) -o $(NAME) $(OBJ)
	@echo "FdF is compiled!"

libclean:
	@make clean -C ./libft

clean: libclean
	@echo "Deleting FdF object files..."
	@rm -rf $(OBJDIR)
	@echo "FdF object files are deleted!"

fclean: clean
	@echo "Deleting FdF executable..."
	@rm -rf $(NAME)
	@echo "Executable is deleted!"
	@make fclean -C ./libft
	@echo "Everything is cleaned!"

re: fclean
	@$(MAKE) all