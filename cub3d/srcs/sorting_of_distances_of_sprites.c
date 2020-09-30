/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_of_distances_of_sprites.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:23:36 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/30 15:41:54 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"



static t_tre			*ft_creat_tre(double distance, t_tre *tree, int i)
{

	if (!(tree = (t_tre *)malloc(sizeof(t_tre))))
		return (NULL);
	tree->num = i;
	tree->distance = distance;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

static void		freemem(t_tre *tree)
{
	if (tree != NULL)
	{
		freemem(tree->left);
		freemem(tree->right);
		free(tree);
		tree = NULL;
	}
}

static t_tre			*ft_addnode(double distance, t_tre *tree, int i)
{
	if (tree == NULL)
	{
		if (!(tree = ft_creat_tre(distance, tree, i)))
			return (NULL);
	}
	else
	{
		if (distance > tree->distance)
		{
			if (!(tree->left = ft_addnode(distance, tree->left, i)))
				return (NULL);
		}
		else
		{
			if (!(tree->right = ft_addnode(distance, tree->right, i)))
				return (NULL);
		}
		return (tree);
	}
	return (tree);
}

static int		creat_sort_arr(int *array, int *i, t_tre *tree)
{
	if (tree)
	{
		creat_sort_arr(array, i, tree->left);
		array[(*i)++] = (tree->num);
		creat_sort_arr(array, i ,tree->right);
	}
	return(*array);
}

int			*sorting_of_distances_of_sprites(t_all *s, int *array)
{
	t_tre	*tree;

	int i;
	tree = NULL;
	i = -1;
	while (++i < s->map->item)
	{
		if (!(tree = ft_addnode(s->sprite[i].distance, tree, i)))
		{
			freemem(tree);
			return (array);
		}
	}
	i = 0;
	*array = creat_sort_arr(array, &i, tree);
	free(tree);
	// for (int i = 0; i < s->map->item; i++)
	// 	printf("num = %d\n",array[i]);
	return (array);
}