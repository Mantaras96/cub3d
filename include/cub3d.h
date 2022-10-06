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
# include <math.h>

# define SIZE_TEXTURE 100

# define WIDTH 1920
# define HEIGHT 1080
# define KEY_UP					13
# define KEY_DOWN				1
# define KEY_RIGHT				2
# define KEY_LEFT				0
# define KEY_RIGHT_VISION		124
# define KEY_LEFT_VISION		123
# define ESCAPE					53

typedef struct s_corde
{
	int		x;
	int		y;
	char	direction;
	int				w;
	int				s;
	int				d;
	int				a;
	int				right;
	int				left;
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
	int			max_lenght;
	char		**path_textures;
	char		**path_colors;
	char		**num2;
	int			rgb;
}	t_global;

typedef struct s_pos
{
	double	pos_x;
	double	pos_y;
	double 	ray_x;
	double 	ray_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	double	camera_x;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;

}	t_pos;

typedef struct	s_image
{
	void      *pointer;
	void *image;
	int 		x;
	int			y;	
	char      *pixels;
	int       bits_per_pixel;
	int       line_size;
	int       endian;
}   t_image;

typedef struct s_all
{
	t_pos pos;
	t_global global;
	t_corde corde;
	t_image image;
}	t_all;



void	show_error_msg( char *str);
char	**validate_and_read_map(char *filename, t_all *all);
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
int		mover(int keycode, t_all *all);
void	move_main_char(t_global *global);
int		can_move(t_global *global);
char	get_direction(int keycode);
int		ft_strcmp(const char *str1, const char *str2);
void	clean_img(t_all *all);
int		close_event(void);
void	*transform_img(void *mlx, char *image);
int 	split_map(t_global *global);
int		ft_matrix_len(char **matrix);
int 	malloc_maps(t_global *global);
void 	validate_map(t_global *global);
int 	validate_textures(t_global *global);
int access_textures(const char *filename, t_global *global, int i);
int 	validate_colors(t_global *global);
void	free_matrix(char ***matrix);
void	set_mlx_windows_and_pistolon(t_all *all);
void	calc(t_all *all);
int	main_loop(t_all *all);
int release (int keycode, t_all *all);
void init_data(t_all *all);
int key_move (t_all *all);

#endif