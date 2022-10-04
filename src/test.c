/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_untextured_raycast.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:12:25 by yohan             #+#    #+#             */
/*   Updated: 2020/07/21 08:08:19 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

void	verLine(t_info *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		//mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
}

void	cal1c(t_info *info)
{
	int	x;

	x = 0;
	while (x < 5)
	{
		double cameraX = 2 * x / (double)WIDTH - 1;
		double rayDirX = info->dirX + info->planeX * cameraX;
		double rayDirY = info->dirY + info->planeY * cameraX;
		
		int mapX = (int)info->posX;
		int mapY = (int)info->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
        printf("deltaY%f\n", deltaDistY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
           //  printf("X nega\n");
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
            // printf("sideX%f\n", sideDistX);
		}
		else
		{
            // printf("X posit\n");
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
            // printf("sideX%f\n", sideDistX);
		}
		if (rayDirY < 0)
		{
             //printf("Y nega\n");
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
             //rintf("sideY%f\n", sideDistY);
		}
		else
		{
             //printf("Y posit\n");
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
             //printf("sideY%f\n", sideDistY);
		}

		// while (hit == 0)
		// {
		// 	//jump to next map square, OR in x-direction, OR in y-direction
		// 	if (sideDistX < sideDistY)
		// 	{
		// 		sideDistX += deltaDistX;
		// 		mapX += stepX;
		// 		side = 0;
		// 	}
		// 	else
		// 	{
		// 		sideDistY += deltaDistY;
		// 		mapY += stepY;
		// 		side = 1;
		// 	}
		// 	//Check if ray has hit a wall
		// 	if (worldMap[mapX][mapY] > 0) hit = 1;
		// }
		// if (side == 0)
		// 	perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		// else
		// 	perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

		// //Calculate height of line to draw on screen
		// int lineHeight = (int)(height / perpWallDist);

		// //calculate lowest and highest pixel to fill in current stripe
		// int drawStart = -lineHeight / 2 + height / 2;
		// if(drawStart < 0)
		// 	drawStart = 0;
		// int drawEnd = lineHeight / 2 + height / 2;
		// if(drawEnd >= height)
		// 	drawEnd = height - 1;

		// int	color;
		// if (worldMap[mapY][mapX] == 1)
		// 	color = 0xFF0000;
		// else if (worldMap[mapY][mapX] == 2)
		// 	color = 0x00FF00;
		// else if (worldMap[mapY][mapX] == 3)
		// 	color = 0x0000FF;
		// else if (worldMap[mapY][mapX] == 4)
		// 	color = 0xFFFFFF;
		// else
		// 	color = 0xFFFF00;
		
		// if (side == 1)
		// 	color = color / 2;

		// verLine(info, x, drawStart, drawEnd, color);
		
		x++;
	}
}

int	main_loop(t_info *info)
{
	cal1c(info);
	// mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);

	return (0);
}

int	main(void)
{
	t_info info;
	//info.mlx = mlx_init();

	info.posX = 12;
	info.posY = 5;
	info.dirX = -1;
	info.dirY = 0;
	info.planeX = 0;
	info.planeY = 0.66;
	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;
	
    cal1c(&info);
	//info.win = mlx_new_window(info.mlx, WIDTH, height, "mlx");
	//mlx_loop_hook(info.mlx, &main_loop, &info);
	//mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

	//mlx_loop(info.mlx);
}
