#include "../include/cub3d.h"
void move_up(t_all *all)
{
    if (all->global.nums[(int)(all->pos.pos_x + all->pos.dir_x * all->pos.move_speed)][((int)all->pos.pos_y)] == '0')
        all->pos.pos_x += all->pos.dir_x * all->pos.move_speed;
    if (all->global.nums[((int)all->pos.pos_x)][(int)(all->pos.pos_y + all->pos.dir_x * all->pos.move_speed)] == '0')
        all->pos.pos_y += all->pos.dir_y * all->pos.move_speed;
}

void move_down(t_all *all)
{
    if (all->global.nums[(int)(all->pos.pos_x - all->pos.dir_x * all->pos.move_speed)][((int)all->pos.pos_y)] == '0')
        all->pos.pos_x -= all->pos.dir_x * all->pos.move_speed;
    if (all->global.nums[((int)all->pos.pos_x)][(int)(all->pos.pos_y - all->pos.dir_x * all->pos.move_speed)] == '0')
        all->pos.pos_y -= all->pos.dir_y * all->pos.move_speed;
}

void move_right(t_all *all)
{
    if (all->global.nums[(int)(all->pos.pos_x)][((int)(all->pos.pos_y -  all->pos.dir_x * all->pos.move_speed))] == '0')
        all->pos.pos_y -= all->pos.dir_x * all->pos.move_speed;
    if (all->global.nums[(int)(all->pos.pos_y + all->pos.dir_x * all->pos.move_speed)][(int)(all->pos.pos_y)] == '0')
        all->pos.pos_x += all->pos.dir_y * all->pos.move_speed;
}

void move_left(t_all *all)
{
    if (all->global.nums[(int)(all->pos.pos_x)][((int)(all->pos.pos_y +  all->pos.dir_x * all->pos.move_speed))] == '0')
        all->pos.pos_y += all->pos.dir_x * all->pos.move_speed;
    if (all->global.nums[(int)(all->pos.pos_y - all->pos.dir_x * all->pos.move_speed)][(int)(all->pos.pos_y)] == '0')
        all->pos.pos_x -= all->pos.dir_y * all->pos.move_speed;
}

void move_right_vision(t_all *all)
{
    double old_dir_x;
    double old_plane_x;
    old_dir_x = all->pos.dir_x;
    all->pos.dir_x = all->pos.dir_x * cos(-all->pos.rot_speed) - all->pos.dir_y * sin(-all->pos.rot_speed);
    all->pos.dir_y = old_dir_x * sin(-all->pos.rot_speed) + all->pos.dir_y * cos(-all->pos.rot_speed);
    old_plane_x = all->pos.plane_x;
    all->pos.plane_x = all->pos.plane_x * cos(-all->pos.rot_speed) - all->pos.plane_y * sin(-all->pos.rot_speed);
    all->pos.plane_y = old_plane_x * sin(-all->pos.rot_speed) + all->pos.plane_y * cos(-all->pos.rot_speed);
}

void move_left_vision(t_all *all)
{
    double old_dir_x;
    double old_plane_x;
    old_dir_x = all->pos.dir_x;
    all->pos.dir_x = all->pos.dir_x * cos(all->pos.rot_speed) - all->pos.dir_y * sin(all->pos.rot_speed);
    all->pos.dir_y = old_dir_x * sin(all->pos.rot_speed) + all->pos.dir_y * cos(all->pos.rot_speed);
    old_plane_x = all->pos.plane_x;
    all->pos.plane_x = all->pos.plane_x * cos(all->pos.rot_speed) - all->pos.plane_y * sin(all->pos.rot_speed);
    all->pos.plane_y = old_plane_x * sin(all->pos.rot_speed) + all->pos.plane_y * cos(all->pos.rot_speed);
}

int key_move (t_all *all)
{
    if (all->corde.w == 1)
        move_up(all);
    if (all->corde.s == 1)
        move_down(all);
    if (all->corde.d == 1)
        move_right(all);
    if (all->corde.a == 1)
        move_left(all);
    if (all->corde.right == 1)
        move_right_vision(all);
    if (all->corde.left == 1)
        move_left_vision(all);
    return (0);
}