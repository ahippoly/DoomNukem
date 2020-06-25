#ifndef RENDER_H
# define RENDER_H

# include "global_header.h"


# define FOV_ANGLE 60
# define MINI_MAP_SIZE_X 250
# define MINI_MAP_SIZE_Y 250
# define MINI_MAP_POS_X WIN_SIZE_X - MINI_MAP_SIZE_X
# define MINI_MAP_POS_Y 0
# define MINI_MAP_PLAYER_SIZE 5

# define MOVE_STEP 3
# define ROT_STEP 0.05 * M_PI_2
# define MOUSE_SENS 0.004
# define Y_VIEW_RANGE 1
# define RENDER_DISTANCE_MAX 30
# define RAY_DIST_MAX 9999
# define HEIGHT_STEP 0.025
# define SCREEN_HEIGHT_STEP 15
# define WALL_SIZE 0.5
# define GRAVITY_FORCE 0.0000005
# define JUMP_FORCE 0.1
# define DEFAULT_Z_GROUND 2
# define PLAYER_HEIGHT 0.5
# define THREAD_NB 4
# define MOVE_WALL_Z_SPEED 4
# define NB_MAX_PROPS 10
# define NB_MAX_MOBS 10
# define NB_MAX_OBJ 230
# define TYPE_WALL -1
# define TYPE_PROP -2
# define TYPE_MOB -3

typedef struct	s_proj_point
{
	int			screen_x;
	float		dist;
	float		wall_start;
	float		wall_size;
	float		scale_x;
	float		scale_len;
	int			on_screen;
}				t_proj_point;

typedef	struct	s_proj_wall
{
	t_proj_point	p1;
	t_proj_point	p2;
	t_wall			wall;
}				t_proj_wall;

typedef	struct	s_draw_line
{
	t_frange	draw_y;
	int			x;
	float		scale_x;
	float		scale_z;
	float		scale_z_step;
	unsigned int	*text;
	int			tw;
	int			th;
}				t_draw_line;

typedef	struct		s_floor
{
	t_point			floor;
	t_point			floor_step;
}					t_floor;

typedef	struct				s_look_rot
{
	float					angle;
	float					step;
	float					rev;
}							t_look_rot;

typedef	struct				s_props
{
				t_point		pos;
				float		size;
				float		z_pos;
				char		collectable;
				char		can_collide;
				char		id;
				t_img		*text;
				t_obj		*obj_ref;
}							t_props;




#endif