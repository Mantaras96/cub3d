#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

# define SIZE_TEXTURE 32

typedef struct s_corde
{
	int		x;
	int		y;
	char	direction;
}	t_corde;

typedef struct s_global
{
	void		*mlx;
	void		*win;
	void		*window;
	void		**img;
	char		**map;
    char        **textures;
    char        **colors;
	char		**nums;
	int			empty_line;
	int			empty_line_2;
	int			width;
	int			height;
	t_corde		character;
	int			count_coll;
	int			count_exit;
	int			count_player;
	int			count_jumpline;
	int			lines_textures;
	int			lines_colors;
	int			lines_maps;
}	t_global;

void	show_error_msg( char *str);
char	**validate_and_read_map(char *filename, t_global *global);
char	**read_map(char *filename, t_global *global);
int		array_str_count(char **arr);
int		ft_validate_name(char *filename);
char	**arr_push(char **arr, char *str);
void	validate_letters_map(t_global *global);
void	read_line(char *map, t_global *global);
void	validate_rectangle_walls(t_global *global);
void	validate_all_leters(t_global *global);
int		get_total_img(t_global *global);
void	**create_img_arr(t_global *global);
void	show_map(t_global *global);
void	set_mlx_and_window(t_global *global);
int		mover(int keycode, t_global *global);
void	move_main_char(t_global *global);
int		can_move(t_global *global);
char	get_direction(int keycode);
void	clean_img(t_global *global);
int		close_event(void);
void	*transform_img(void *mlx, char *image);
void split_map(t_global *global);
int	ft_matrix_len(char **matrix);
void malloc_maps(t_global *global);
void validate_map(t_global *global);

#endif