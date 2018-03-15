/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:00:53 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/15 18:30:15 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "libftmath.h"
# include "libshader.h"
# include "fmod.h"
# include "SDL.h"
# include "SDL_events.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <pthread.h>
# include <math.h>
# include <time.h>

# define NB_THRD 4

# define XWIN 3200
# define YWIN 1800
# define X_WIN 3200.0
# define Y_WIN 1800.0

# define SIDE 400
# define X_SCALE 10
# define Z_SCALE 10

# define FFT_SIZE 1024
# define OCT_NB 9

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define C_BLA 0x00000000
# define C_BLU 0x000000ff
# define C_GRE 0x0000ff00
# define C_RED 0x00ff0000
# define C_WHI 0x00ffffff

# define C_GOLD_PALE 0x00ffe7ba
# define C_GREEN_DARK 0x00006400
# define C_AQUAMARINE 0x007fffd4
# define C_PURPLE_DARK 0x00551a8b
# define C_ORANGE_DARK 0x008b2500
# define C_BLUE_NAVY 0x00000080
# define C_LIGHT_RED 0x00ff4444

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

enum			e_ps3buttons
{
	PS3_LEFT_SHOULDER = 10,
	PS3_RIGHT_SHOULDER = 11
};

typedef	void	(*t_fct_type)();

typedef struct	s_starfuncs
{
	void		(*draw)();
	char		type[3];
}				t_starfuncs;

typedef struct	s_star
{
	t_vec4		pos;
	void		(*draw)();
}				t_star;

typedef enum	e_lmodes
{
	L_DEFAULT = 1,
	L_LOUD,
	L_QUIET,
	L_LAST
}				t_lmodes;

typedef enum	e_infmodes
{
	INF_OFF = 0,
	INF_ON
}				t_infmodes;

typedef enum	e_modes
{
	M_SKY = 1,
	M_GRD,
	M_LAST
}				t_modes;

typedef enum	e_dstmodes
{
	DST_DEFAULT = 1,
	DST_AROUND_FLAT,
	DST_DEFAULT_NS,
	DST_AROUND_FLAT_NS,
	DST_LAST
}				t_dstmodes;

typedef enum	e_vdstmodes
{
	VDST_DEFAULT = 1,
	VDST_LIGHT,
	VDST_SOUND_TOTAL,
	VDST_LAST
}				t_vdstmodes;

typedef enum	e_cmodes
{
	C_STOCK = 1,
	C_DISCO,
	C_HYPER,
	C_STROBO,
	C_GLOWING,
	C_LAST
}				t_cmodes;

typedef enum	e_bmodes
{
	B_DEFAULT = 1,
	B_TRIPPY,
	B_LAST
}				t_bmodes;

typedef enum	e_projmodes
{
	P_DEFAULT = 1,
	P_WIDE,
	P_SPACE,
	P_SKY,
	P_ORTHO,
	P_LAST
}				t_projmodes;

typedef enum	e_viewmodes
{
	V_GRD = 1,
	V_SKY,
	V_LAST
}				t_viewmodes;

typedef union	u_gmodes
{
	t_projmodes	pmode;
	t_viewmodes	vmode;
}				t_gmodes;

typedef enum	e_soundmodes
{
	S_OFF = 0,
	S_ON
}				t_soundmodes;

typedef enum	e_srmodes
{
	SR_DEFAULT = 1,
	SR_BASS_ALTI,
	SR_TOTAL_ALTI,
	SR_LAST
}				t_srmodes;

typedef enum	e_scmodes
{
	SC_DEFAULT = 1,
	SC_TOTAL_VISION,
	SC_TOTAL_UNVISION,
	SC_LAST
}				t_scmodes;

typedef enum	e_kbmodes
{
	KB_GRD = 1,
	KB_SWI,
	KB_SKY,
	KB_RT,
	KB_LAST
}				t_kbmodes;

typedef struct	s_kfuncs
{
	void	(*f)();
	int		keycode;
}				t_kfuncs;

typedef struct	s_dstfuncs
{
	void		(*f)();
	t_dstmodes	dstmode;
}				t_dstfuncs;

typedef struct	s_vdstfuncs
{
	void		(*f)();
	t_vdstmodes	vdstmode;
}				t_vdstfuncs;

typedef struct	s_cfuncs
{
	void		(*f)();
	t_cmodes	cmode;
}				t_cfuncs;

typedef struct	s_bfuncs
{
	void		*(*f)();
	t_bmodes	bmode;
}				t_bfuncs;

typedef struct	s_matstock
{
	t_mat4		mat;
	t_gmodes	gmode;
}				t_matstock;

typedef struct	s_srfuncs
{
	void		(*f)();
	t_srmodes	srmode;
}				t_srfuncs;

typedef struct	s_scfuncs
{
	void		(*f)();
	t_scmodes	scmode;
}				t_scfuncs;

typedef struct	s_kbpreset
{
	t_kfuncs	*preset;
	t_kbmodes	kbmode;
}				t_kbpreset;

typedef struct	s_kbsync
{
	t_modes		envmode;
	t_kbmodes	kbmode;
}				t_kbsync;

typedef struct	s_controls
{
	t_kfuncs			*active;
	t_kfuncs			*target;
	t_kbpreset			*presets;
	t_kbsync			*kbsync;
	SDL_GameController	*ps3;
}				t_controls;

typedef struct	s_vec2c
{
	int		x;
	int		y;
	int		color;
	float	dst;
}				t_vec2c;

typedef struct	s_cmix
{
	int		a;
	int		b;
	float	r;
}				t_cmix;

typedef struct	s_colorset
{
	int			text;
	int			bg1;
	int			bg2;
	int			bottom;
	int			top;
	int			st1;
	int			st2;
	int			st3;
}				t_colorset;

typedef struct	s_colors
{
	t_colorset	active;
	t_colorset	from;
	t_colorset	target;
	t_colorset	*stock;
	t_colorset	*disco;
	t_colorset	*hyper;
	t_colorset	*strobo;
	t_colorset	*glowing;
	size_t		progress;
	size_t		stock_size;
	t_cmodes	cmode;
	t_bmodes	bmode;
	t_cfuncs	*cfuncs;
	t_bfuncs	*bfuncs;
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
	t_mat4		active;
	t_mat4		from;
	t_mat4		target;
	size_t		progress;
	size_t		stock_size;
	int			switching;
	t_matstock	*stock;
	t_gmodes	gmode;
}				t_mat4set;

typedef struct	s_map
{
	t_list		*vertices_list;
	t_vec4		*vertices_glb;
	t_vec4		*vertices;
	float		*target_vtx_y;
	int			az_targut;
	t_vec4		*mod_vertices;
	t_vec4		*world_coords_glb;
	t_vec4		*m_world_vtx;
	t_vec4		*world_vtx;
	float		*distancesxy;
	float		*distancesxz;
	int			viewdist_active;
	int			viewdist_target;
	t_vec3		*proj;
	t_vec2c		*draw;
	char		*clip;
	size_t		nb_col_glb;
	size_t		nb_line_glb;
	size_t		nb_col;
	size_t		nb_line;
	t_vec2r		middle;
	size_t		closest_vtx_i;
	size_t		nb_vtx_glb;
	size_t		nb_vtx;
	t_vec4		mid_mod;
	t_vec4		mid_point;
	double		mid_height;
	int			min_z;
	int			max_z;
	int			min_y;
	int			max_y;
	size_t		starbox_size;
	t_starfuncs	*starfuncs;
	t_star		*starbox;
	t_vec3		*starproj;
	t_vec2r		*stardraw;
	t_dstmodes	dstmode;
	t_dstfuncs	*dstfuncs;
	t_vdstmodes	vdstmode;
	t_vdstfuncs	*vdstfuncs;
	t_infmodes	infmode;
}				t_map;

typedef struct	s_img
{
	void	*img;
	int		*addr;
	int		**p_addr;
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
	t_vec4		prev_eye_pos;
	t_vec4		diff_eye_pos;
	t_mat4		model_mat;
	t_mat4		f_mat;
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
	float					volume;
	int						numchannels;
	FMOD_DSP_PARAMETER_FFT	*spec;
	float					**oct;
	t_spec					*p_spec;
}				t_audiodata;

typedef struct	s_sound
{
	FMOD_SYSTEM		*system;
	FMOD_SOUND		*song;
	FMOD_CHANNEL	*channel;
	FMOD_DSP		*fft;
	t_audiodata		*data;
	t_soundmodes	smode;
	t_srmodes		srmode;
	t_scmodes		scmode;
	t_srfuncs		*srfuncs;
	t_scfuncs		*scfuncs;
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

typedef struct	s_thrd
{
	t_env	*e;
	int		i;
}				t_thrd;

typedef struct	s_thrdm
{
	t_map	*map;
	int		i;
}				t_thrdm;

typedef struct	s_thrdbuf
{
	int		*addr;
	int		color;
	int		i;
}				t_thrdbuf;

void			fdf(char *file, char *audio, t_lmodes launchmode);

void			parse_map(t_map *map, char *file);
void			init_geometry(t_matrices *matrices, t_map *map);
void			init_colors(t_colors *colors);
void			init_controls(t_env *e);
void			init_starbox(t_map *map);
void			init_overlay(t_overlay *overlay);
void			init_sound(t_sound *sound, char *file);
t_mat4			get_view_mat(t_vec4 eye, t_vec4 target, t_vec4 up);

void			get_active_vertices(t_map *map);
void			*get_active_world(void *dt);
t_vec2r			get_new_middle(t_map *map);

void			switch_kbmode(t_env *e, t_kfuncs **preset, t_kbmodes mode);
t_kbmodes		get_mode_sync(t_kbsync *kbsync, t_modes envmode);

t_kfuncs		*kfuncs_grd(void);
t_kfuncs		*kfuncs_sky(void);
t_kfuncs		*kfuncs_swi(void);
t_kfuncs		*kfuncs_rt(void);

void			load_view_presets(t_matrices *matrices, t_map *map);
void			load_proj_presets(t_mat4set *projs);
void			set_dstfuncs(t_map *map);
void			set_vdstfuncs(t_map *map);

void			set_state_eno(t_env *e);
void			set_state_loud(t_env *e);
void			set_state_quiet(t_env *e);
void			set_state_default(t_env *e);
void			set_state_rt(t_env *e);

void			load_program_disco(t_colors *colors);
void			load_program_hyper(t_colors *colors);
void			load_program_strobo(t_colors *colors);
void			load_program_glowing(t_colors *colors);
void			set_cfuncs(t_colors *colors);
void			set_bfuncs(t_colors *colors);

void			set_sr_funcs(t_sound *sound);
void			set_sc_funcs(t_sound *sound);

int				draw(t_env *e);
void			*pre_to_render(void *dt);

void			get_sound_data(t_sound *sound);

void			set_dst_map(t_map *map);
void			get_distances(t_vec4 eye_pos, t_map *map);
void			dst_default(t_map *map);
void			dst_default_ns(t_map *map);
void			dst_around_flat(t_map *map);
void			dst_around_flat_ns(t_map *map);

void			vdst_default(t_sound *sound, t_map *map);
void			vdst_light(t_sound *sound, t_map *map);
void			vdst_sound_total(t_sound *sound, t_map *map);

void			set_sound_map(t_sound *sound, t_map *map);
void			sr_default(t_spec *spec, t_map *map);
void			sr_bass_alti(t_spec *spec, t_map *map);
void			sr_total_alti(t_spec *spec, t_map *map);

void			set_sound_color(t_sound *sound, t_map *map, t_colorset active);
void			sc_default(t_map *map, t_colorset active);
void			sc_total_vision(t_map *map, t_colorset active);
void			sc_total_unvision(t_map *map, t_colorset active);

void			set_matrices(t_env *e, t_matrices *matrices);
void			manage_text_overlay(t_env *e);

void			*plain_background(void *dt);
void			*no_background(void *dt);

void			get_eye_pos(t_matrices *matrices);

void			switch_colorset(t_colors *colors);
void			switch_colors(t_colors *colors, size_t distance,
													size_t progress);
void			program_disco(t_colors *colors);
void			program_hyper(t_colors *colors);
void			program_strobo(t_colors *colors);
void			program_glowing(t_colors *colors);
int				get_color(int min_z, int max_z, int z,
												t_colorset active);

void			draw_starbox(t_map *map, t_matrices *matrices,
							t_colorset active, int *addr);
void			*vertices_to_proj(void *dt);
void			*proj_to_draw(void *dt);
void			*draw_to_img(void *dt);

void			bresenham(t_vec2c a, t_vec2c b, int *addr, int bg);
void			bresenham_clip(t_vec2c a, t_vec2c b, int *addr);
int				pix_clip(t_vec2c coord);
int				pix_clipr(t_vec2r coord);

void			dw_pt(t_vec2r point, t_cmix cl, int *addr);
void			draw_star_10(t_vec2r point, t_colorset cl, int *addr);
void			draw_star_11(t_vec2r point, t_colorset cl, int *addr);
void			draw_star_p0(t_vec2r point, t_colorset cl, int *addr);
void			draw_star_p1(t_vec2r point, t_colorset cl, int *addr);
void			draw_star_n0(t_vec2r point, t_colorset cl, int *addr);
void			draw_star_n1(t_vec2r point, t_colorset cl, int *addr);
void			draw_star_n2(t_vec2r point, t_colorset cl, int *addr);
void			draw_star_n3(t_vec2r point, t_colorset cl, int *addr);

int				expose_hook(void *param);
int				quit_hook(t_env *e);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				key_press_hook(int keycode, t_env *e);
int				key_release_hook(int keycode, t_env *e);

void			k_exit(t_env *e, int flag);
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

void			handle_sdl_events(t_env *e);
void			ps3_camrotz(t_env *e, int value);
void			ps3_camrotx(t_env *e, int value);
void			ps3_camroty(t_env *e, int value);
void			ps3_camtrsz(t_env *e, int value);
void			ps3_reset_camrot(t_env *e);

void			send_threads(void *(*f)(), t_env *e);
void			send_threads_m(void *(*f)(), t_map *map);
void			send_threads_buf(void *(*f)(), int *addr, int color);

void			clean_lst(void *elem, size_t size);
void			free_all_the_stuff(t_env *e);

void			usage_exit(void);
void			error_exit(char *msg);

void			print_parsed_map(t_list *map);
void			print_array_map(t_vec4 *array, size_t size);
void			print_draw_coords(t_list *draw);

#endif
