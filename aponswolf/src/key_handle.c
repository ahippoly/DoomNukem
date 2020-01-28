#include <math.h>
#include "wolf3d.h"

int     keypress(int key, t_enval *env)
{
    ft_putnbr(key);
    if (key == KEY_ESC)
    {
        //free (env);
        mlx_destroy_image(env->mlx.m_p, env->mlx.i_p);
        mlx_destroy_window(env->mlx.m_p, env->mlx.w_p);
        exit(0);
    }
    if (key == KEY_UP)
        env->keyinf.up = 1;
    if (key == KEY_DOWN)
        env->keyinf.down = -1;
    if (key == KEY_LEFT)
        env->keyinf.left = 1;
    if (key == KEY_RIGHT)
        env->keyinf.right = -1;
    ft_putendl(" interrupts you !");
    return (0);
}

int     keyrelease(int key, t_enval *env)
{
    if (key == KEY_UP)
        env->keyinf.up = 0;
    if (key == KEY_DOWN)
        env->keyinf.down = 0;
    if (key == KEY_LEFT)
        env->keyinf.left = 0;
    if (key == KEY_RIGHT)
        env->keyinf.right = 0;
    ft_putendl("It stopped !");
    return (0);
}