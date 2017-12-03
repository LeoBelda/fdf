/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:00:53 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/03 15:18:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "libftmath.h"
# include "fmod.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <math.h>
# include <time.h>

# define XWIN 2560
# define YWIN 1440
# define X_WIN 2560.0
# define Y_WIN 1440.0

# define FFT_SIZE 512

# define C_BLA 0x00000000
# define C_BLU 0x000000ff
# define C_GRE 0x0000ff00
# define C_RED 0x00ff0000
# define C_WHI 0x00ffffff

# define C_GOLD_PALE 0x00ffe7ba
# define C_GREEN_DARK 0x00006400
# define C_PURPLE_DARK 0x00551a8b
# define C_ORANGE_DARK 0x008b2500
# define C_BLUE_NAVY 0x00000080

enum			e_keycodes
{
	K_A = 0,
	K_S,
	K_D,
	K_F,
	K_H,
	K_C = 8,
	K_B = 11,
	K_W = 13,
	K_P = 35,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP
};

typedef enum	e_modes
{
	M_SKY,
	M_GRD
}				t_modes;

typedef enum	e_cmodes
{
	C_STOCK = 1,
	C_DISCO,
	C_DAYNIGHT,
	C_STROBO,
	C_GLOWING,
	C_LAST
}				t_cmodes;

typedef enum	e_bufmodes
{
	B_DEFAULT = 1,
	B_TRIPPY,
	B_LAST
}				t_bufmodes;

typedef enum	e_projmodes
{
	P_DEFAULT = 1,
	P_SPACE,
	P_LAST
}				t_projmodes;

typedef struct	s_kfuncs
{
	void	(*f)();
	int		keycode;
}				t_kfuncs;

typedef struct	s_cfuncs
{
	void		(*f)();
	t_cmodes	cmode;
}				t_cfuncs;

typedef struct	s_controls
{
	t_kfuncs	*grd;
	t_kfuncs	*sky;
}				t_controls;

typedef struct	s_vec2c
{
	int		x;
	int		y;
	int		color;
}				t_vec2c;

typedef struct	s_colorset
{
	int			text;
	int			background1;
	int			background2;
	int			bottom;
	int			top;
}				t_colorset;

typedef struct	s_colors
{
	t_colorset	active;
	t_colorset	from;
	t_colorset	target;
	t_colorset	*stock;
	t_colorset	*disco;
	t_colorset	*daynight;
	t_colorset	*strobo;
	t_colorset	*glowing;
	size_t		progress;
	size_t		stock_size;
	t_cmodes	cmode;
	t_bufmodes	bufmode;
	t_cfuncs	*cfuncs;
}				t_colors;

typedef struct	s_modmat
{
	double	rx;
	double	ry;
	double	rz;
	double	tx;
	double	ty;
	double	tz;
	double	s;
}				t_modmat;

typedef struct	s_mat4set
{
	t_mat4	active;
	t_mat4	from;
	t_mat4	target;
	t_mat4	*stock;
	size_t	progress;
	size_t	stock_size;
	int		switching;
}				t_mat4set;

typedef struct	s_map
{
	t_list	*vertices_list;
	t_vec4	*vertices;
	float	*target_vtx_z;
	t_vec4	*mod_vertices;
	t_vec3	*proj;
	t_vec2c	*draw;
	char	*clip;
	size_t	nb_col;
	size_t	nb_line;
	size_t	nb_vtx;
	t_vec4	mid_mod;
	t_vec4	mid_point;
	double	mid_height;
	int		min_z;
	int		max_z;
}				t_map;

typedef struct	s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_matrices
{
	t_modmat	initst;
	t_modmat	movement;
	t_mat4set	*projs;
	t_mat4set	*views;
	t_vec4		eye_pos;
	t_mat4		model_mat;
	t_mat4		f_mat;
	t_projmodes	projmode;
}				t_matrices;

typedef struct	s_overlay
{
	char	*fps;
}				t_overlay;

typedef struct	s_spec
{
	float	low_band;
	float	mid_band;
	float	high_band;
	float	total;
}				t_spec;

typedef struct	s_audiodata
{
	float							volume;
	FMOD_DSP_PARAMETER_FFT			*spec;
	t_spec							*p_spec;
}				t_audiodata;

typedef struct	s_sound
{
	FMOD_SYSTEM		*system;
	FMOD_SOUND		*song;
	FMOD_CHANNEL	*channel;
	FMOD_DSP		*fft;
	t_audiodata		*data;
}				t_sound;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_matrices	*matrices;
	t_colors	*colors;
	t_controls	*controls;
	t_overlay	*overlay;
	t_sound		*sound;
	t_modes		mode;
}				t_env;

void			fdf(char *file);

void			parse_map(t_map *map, char *file);
void			init_geometry(t_matrices *matrices, t_map *map);
void			init_colors(t_colors *colors);
void			init_controls(t_controls *controls);
void			init_overlay(t_overlay *overlay);
void			init_sound(t_sound *sound);
t_mat4			get_view_mat(t_vec4 eye, t_vec4 target, t_vec4 up);

void			load_program_disco(t_colors *colors);
void			load_program_daynight(t_colors *colors);
void			load_program_strobo(t_colors *colors);
void			load_program_glowing(t_colors *colors);

int				draw(t_env *e);
void			get_audio_data(t_sound *sound);
void			map_audio(t_spec *spec, t_map *map);
void			set_matrices(t_matrices *matrices);
void			manage_text_overlay(t_env *e);

void			plain_background(int *addr, int color);
void			stripped_background(int *addr, int cola, int colb, size_t thick);

t_vec4			get_eye_pos(t_mat4 active);

void			switch_colorset(t_colors *colors);
void			switch_colors(t_colors *colors, size_t distance, size_t progress);
void			program_disco(t_colors *colors);
void			program_daynight(t_colors *colors);
void			program_strobo(t_colors *colors);
void			program_glowing(t_colors *colors);
int				get_color(int min_z, int max_z, int z,
												t_colorset active);

void			vertices_to_proj(t_map *map, t_mat4 f_mat);
void			proj_to_draw(t_map *map, t_colorset active);
void			draw_to_img(t_map *map, int *addr);


void			bresenham(t_vec2c a, t_vec2c b, int *addr);
void			bresenham_clip(t_vec2c a, t_vec2c b, int *addr);
int				pix_clip(t_vec2c coord);

int				expose_hook(void *param);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				key_press_hook(int keycode, t_env *e);
int				key_release_hook(int keycode, t_env *e);

void			k_exit(t_env *e);
void			k_chpov(t_env *e, int flag);
void			k_chcolor_stock(t_env *e, int flag);
void			k_chcolor_program(t_env *e, int flag);
void			k_chbuff_mode(t_env *e, int flag);
void			k_chspace(t_env *e, int flag);
void			k_trscamx(t_env *e, int flag);
void			k_trscamrx(t_env *e, int flag);
void			k_trscamy(t_env *e, int flag);
void			k_trscamry(t_env *e, int flag);
void			k_trscamz(t_env *e, int flag);
void			k_trscamrz(t_env *e, int flag);
void			k_rotcamy(t_env *e, int flag);
void			k_rotcamry(t_env *e, int flag);
void			k_rotcamx(t_env *e, int flag);
void			k_rotcamrx(t_env *e, int flag);
void			k_rotcamz(t_env *e, int flag);
void			k_rotcamrz(t_env *e, int flag);

void			usage_exit(void);
void			error_exit(char *msg);

void			print_parsed_map(t_list *map);
void			print_array_map(t_vec4 *array, size_t size);
void			print_draw_coords(t_list *draw);

#endif
