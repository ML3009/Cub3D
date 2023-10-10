/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:40:41 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/10 14:39:52 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

/*étape 3 : La Minimap
A faire :
Utiliser le parsing que j’ai fait dans mon char** map pour créer une minimap avec les 0, les 1 et les 2 chacun d'une couleur
Faire un pixel = 10 pixels pour qu’on voit correctement la minimap
Pouvoir faire bouger mon personnage avec les flèches dans la minimap (voir les keys à l'étape 4)
Checker si le case sur laquelle je vais me déplacer est un mur ou pas (si == ‘0’) : si oui je peux me déplacer dessus, sinon non
Comment faire ça avec les fonctions vues précédemment ? :
Il faut mlx_init, mlx_new_window, et mlx_loop bien sur
Il faut mlx_hook qui tourne pour les key_press et les key_release qui permet de récupérer si une touche est appuyée ou non (voir étape 4)
Il faut mlx_get_data_addr pour récupérer l'adresse de l'image et écrire des pixels dedans
Il faut mlx_loop_hook avec à l'intérieur ta fonction qui imprime la minimap pour que dès qu'il y a une key press la minimap s'adapte
Il faut mlx_put_image_to_window*/

static void	draw_square(t_data *data, int y, int x, int color);

void	draw_mini_map(t_data *data)
{
	int	y;
	int x;
	int y_bis;
	int x_bis;

	y = -1;
	y_bis = 0;
	while (++y < data->mlx.size.y && y < data->row)
	{
		x = -1;
		x_bis = 0;
		while (++x < data->mlx.size.x && x < data->col)
		{
			if (x < data->col && y < data->row)
			{
		//	printf ("data->map[y][x] : %c\n", data->map[y][x]);
				if (data->map && data->map[y][x] && data->map[y][x] == '1')
					draw_square(data, y_bis, x_bis, 0x1A6303);
				else if (data->map && data->map[y][x] && (data->map[y][x] == '0' || is_dir(data->map[y][x])))
					draw_square(data, y_bis, x_bis, 0xF0D5F8);
			}
			//else
			//	draw_square(data, y_bis, x_bis, 0x000020);
			x_bis+=5;
		}
		y_bis+=5;
	}
	draw_square(data, (int)data->ray.pos.y * 5, (int)data->ray.pos.x * 5, 0x00000000);
	//dessiner carre joueur
}

static void	draw_square(t_data *data, int y, int x, int color)
{
	int	y_temp;
	int	x_temp;
	int save_x;

	y_temp = y + 5;
	x_temp = x + 5;
	save_x = x;

	while (y < y_temp)
	{
		x = save_x;
		while (x < x_temp)
		{
			img_pix_put(&data->base_img,x, y, color);
			x++;
		}
		y++;
	}



	return ;
}


// fonction qui dessine un carre plutot qu un unique pixel

