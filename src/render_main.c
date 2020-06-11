#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"

void print_data2screen(t_data *d, t_map_data *map)
{
    SDL_Rect tmp;
    //printf("before print\n");
    SDL_RenderClear(d->rend);
    SDL_UpdateTexture(d->screen, NULL, d->p_screen, WIN_SIZE_X * 4);
    print_mini_map(d, map);
    SDL_RenderCopy(d->rend, d->screen, NULL, NULL);
    tmp = set_sdl_rect(MINI_MAP_POS_X, MINI_MAP_POS_Y, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
    SDL_RenderCopy(d->rend, d->mini_map, NULL, &tmp);
    SDL_RenderPresent(d->rend);
}

void free_render_env(t_data *d)
{

}

void calc_n_disp_framerate(t_data *d)
{
    static int  last_time;
    static int  framerate;
    static int  last_framerate;
    int time;

    time = SDL_GetTicks();
    if (time > last_time + 1000)
    {
        last_framerate = framerate;
        framerate = 0;
        last_time = time;
    }
    framerate += 1;
    input_text_to_img(ft_itoa(last_framerate), 2, 0xFFFFFFFF, create_img(d->p_screen, set_sdl_rect(5, 5, WIN_SIZE_X, WIN_SIZE_Y)));
}


int main(void)
{
    t_data      d;
    
    init_data(&d);
    ft_putstr("Main worked");
    printf("player pos = %f, %f, wall count = %i\n", d.player_pos.x, d.player_pos.y, d.map.wall_count);
    while (!d.quit)
    {
        d.time_last_frame = d.time;
        d.time = SDL_GetTicks();
        ft_bzero(d.p_screen, sizeof(int) * WIN_SIZE_X * WIN_SIZE_Y);
        SDL_PumpEvents();
        handle_key_event(&d, &d.map);
        handle_poll_event(&d, &d.map);
        gravity(&d);
        //draw_floor(&d, d.texture[1]);
        //raycast_all_screen(&d, &d.map);
		raycast_thread_init(&d);
        //draw_vertical_line(&d, 500, check_intersect_with_all_wall(&d, &d.map, d.rot));
        update_player_pos_mini_map(&d, &d.map);
        print_player_look_vector(&d, &d.map, d.rot);
        calc_n_disp_framerate(&d);
        print_data2screen(&d, &d.map);
    }
    free_render_env(&d);
}
