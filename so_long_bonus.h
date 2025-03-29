/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:32 by menwu             #+#    #+#             */
/*   Updated: 2025/02/17 15:01:27 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define MAX_KEY 5
# define BUSH 	"img/tree.xpm"
# define TILE	"img/tile.xpm"
# define INIT	"img/right.xpm"
# define FR		"img/front.xpm"
# define FR1	"img/front_mv.xpm"
# define BK		"img/back.xpm"
# define BK1	"img/back_mv.xpm"
# define L		"img/left.xpm"
# define L1		"img/left_mv.xpm"
# define R		"img/right.xpm"
# define R1		"img/right_mv.xpm"
# define OUT	"img/exit.xpm"
# define END	"img/gameover.xpm"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "get_next_line/get_next_line.h"

typedef struct s_point
{
	int		x;
	int		y;
	int		count_c;
	int		count_e;
}		t_point;

typedef struct s_enemy
{
	int	pos;
	int	flag;
	int	count;
}	t_enemy;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*p;
	void	*p_init;
	void	*p_bk;
	void	*p_bk_mv;
	void	*p_fr;
	void	*p_fr_mv;
	void	*p_l;
	void	*p_l_mv;
	void	*p_r;
	void	*p_r_mv;
	void	*bush;
	void	*background;
	void	*light;
	void	*out;
	void	*enemy;
	void	*enemy_frame[MAX_KEY];
	void	*light_frame[MAX_KEY];
	void	*end_fail;
	int		start;
	int		exit_flag;
	int		old_e;
	int		game_over;
	int		current_frame_enemy;
	int		current_frame_fly;
	int		counter_fly;
	int		counter_enemy;
	int		counter_pattern;
	int		frame_delay;
	int		enemy_flag;
	int		flag;
	int		width;
	int		height;
	int		axis_x;
	int		axis_y;
	int		npc_x;
	int		npc_y;
	int		wall;
	int		npc;
	int		all_to_collect;
	int		collected;
	int		steps;
	int		exit;
	int		back;
	int		x_count;
	int		gameover_drawn;
	char	*current_line;
	char	*long_line;
	t_enemy	*x;
}				t_data;

// 0 Libft util + Map parsing
char	*ft_itoa(int n);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_memset(void *str, int c, size_t n);
size_t	count_width(char *str);
void	flood_fill(char *map, t_point *size, t_point *start);
char	*map_concate(char *s1, char *s2);
char	*get_next_line(int fd);
int		check_first_last(t_data *d);
int		check_cep(t_data *d);
int		check_accessibility(t_data *d, int len);
void	init_data(t_data *d);
int		init_parsing(t_data *d, char *map);
void	map_error(int n);
void	error_free(t_data *d);
void	frame_free(t_data *d, void **array, int i);
void	free_img(t_data *d);
void	axis_x_y(t_data *d, int index);

// 1 show window & display
void	init_play(t_data *d);
void	show_map(t_data *d, char *long_line);
int		is_exit(t_data *d, char ch);
void	move_msg(t_data *d);
int		if_game_over(t_data *d);
void	display_game_over(t_data *d);

// 2 loop_hook functions
int		key_press(int keysym, t_data *d);
void	move_right(t_data *d);
void	move_left(t_data *d);
void	move_util(t_data *d, void *ini, void *mv);
int		enemy_sprint(t_data *d);
int		light_sprint(t_data *d);
void	enemy_pattern(t_data *d);
void	init_enemy(t_data *d);
void	init_collective(t_data *d);
void	init_score_bar(t_data *d);
int		update_counter(t_data *d);
int		update_bar(t_data *d);
int		event_loop(t_data *d);
int		end_game(t_data *d);
void	cleanup(void *mlx_ptr, void **img);
void	clean_npc(t_data *d);
int		end_game(t_data *d);

#endif
