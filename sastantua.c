/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 00:30:31 by minhnguy          #+#    #+#             */
/*   Updated: 2019/08/11 21:22:17 by minhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	ft_putchar(char c);

void		print_offset(int offset)
{
	int counter;

	counter = 0;
	while (counter < offset)
	{
		ft_putchar(' ');
		++counter;
	}
}

void		print_triangle(int nb_line, int char_increase, int offset)
{
	int nb_chars;
	int row;
	int counter;

	nb_chars = char_increase;
	row = 1;
	while (row <= nb_line)
	{
		print_offset(offset);
		ft_putchar('/');
		counter = 0;
		while (counter < nb_chars)
		{
			ft_putchar('*');
			++counter;
		}
		ft_putchar('\\');
		ft_putchar('\n');
		++row;
		--offset;
		nb_chars += 2;
	}
}

void		print_door( int nb_line, int char_increase, int offset, int size)
{
	int door_size;
	int counter;
	int door_start;
	int door_count;
	int loop_count;

	door_size = ((size - 1) / 2) * 2 + 1;
	print_triangle(nb_line - door_size, char_increase, offset);
	offset = offset - (nb_line - door_size);
	char_increase = char_increase + (nb_line - door_size) * 2; 
	loop_count = door_size;
	while (loop_count > 0 )
	{
		print_offset(offset);
		ft_putchar('/');
		counter = 0;
		while (counter < char_increase)
		{
			if (counter == char_increase / 2 - door_size / 2)
			{
				door_count = 0;
				while (door_count < door_size)
				{
					if ((loop_count == door_size / 2 + 1) && door_count == door_size - 2)
						ft_putchar('$');
					else
						ft_putchar('|');
					++door_count;
					++counter;
				}
			}
			ft_putchar('*');
			++counter;
		}
		ft_putchar('\\');
		ft_putchar('\n');
		--loop_count;
		char_increase += 2;
		--offset;
	}		
}	

int			find_last_row(int size)
{
	int first_row;
	int start_increase;
	int triangle_counter;
	int nb_row;

	start_increase = 3;
	triangle_counter = 1;
	nb_row = 3;
	first_row = 1 + (nb_row - 1) * 2;
	while (triangle_counter < size)
	{
		++nb_row;
		first_row = first_row +  start_increase * 2 + (nb_row - 1) * 2;
		start_increase = start_increase + nb_row % 2;
		++triangle_counter;
	}
	return (first_row);
}

void		sastantua(int size)
{
	int nb_row;
	int start_increase;
	int triangle_counter;
	int first_row;
	int offset;
	int data[2];

	first_row = find_last_row(size);
	offset = first_row / 2;
	nb_row = 3;
	start_increase = 3;
	first_row = 1;
	triangle_counter = 0;
	while (triangle_counter < size)
	{
		if (triangle_counter == size - 1)
		{
			print_door(nb_row, first_row, offset, size);
			break ;
		}
		print_triangle(nb_row, first_row, offset);
		offset = offset - (nb_row - 1) - start_increase;
		first_row = first_row + (nb_row - 1) * 2 + start_increase * 2;
		++nb_row;
		start_increase = start_increase + nb_row % 2;
		++triangle_counter;
	}
}

int		main(void)
{
	int i;

	i = 6;
	while (i < 7)
	{
		sastantua(i);
		++i;
	}
	return (1);
}
