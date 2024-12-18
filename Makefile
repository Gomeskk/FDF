### COMPILATION ###
CC      = gcc -O2
FLAGS  = -Wall -Wextra -Werror -ffast-math -g -O3 -Ofast
### EXECUTABLE ###
NAME   = fdf

### INCLUDES ###
LIBFT  = LIBFT
OBJ_PATH  = objs
HEADER = incl
SRC_PATH  = srcs
MLX = minilibx-linux

### SOURCE FILES ###
SOURCES = color.c \
		  controls_u.c \
		  controls.c \
		  convert.c \
		  draw.c \
		  init.c \
		  key_controls.c \
		  main.c \
		  menu.c \
		  read_map.c \
		  read_stack.c \
		  util.c \
		  utils2.c \
		  mouse_controls.c \
		  project.c \

### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)
	@make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -I $(LIBFT) -I $(MLX) -L $(LIBFT) -L $(MLX) -o $@ $^ -lft -lmlx -lXext -lX11 -lm
	@echo "$(GREEN)Project successfully compiled"

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: temporary, re, fclean, clean