CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

CUBE = cub3D
PHILO_BONUS = philo_bonus

MANDATORY = parsing.c GNL/get_next_line.c GNL/get_next_line_utils.c initializer.c
CUB_OBJ = $(MANDATORY:.c=.o)

all: $(CUBE)

%.o: %.c cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(CUBE): $(CUB_OBJ)
	@$(CC) $(CFLAGS) $(CUB_OBJ) -o $(CUBE)
	@echo "\033[0;32mcub3d Compiled successfully\033[0m"

clean:
	@echo "\033[0;31mCleaning up.....\033[0m"
	@$(RM) $(CUB_OBJ)

fclean: clean
	@$(RM) $(CUBE)

re: fclean all