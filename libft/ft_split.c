/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:10:48 by tpirinen          #+#    #+#             */
/*   Updated: 2025/05/20 18:16:31 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_str(char const *s, char c);
static char		**ft_str_alloc(char **arr, char const *s, char c, size_t i);
static char		**ft_str_fill(char **arr, char const *s, char c);
static void		ft_free_all(char **arr, size_t str_count);

/*	Allocates memory (using malloc(3)) and returns an array of strings
	obtained by splitting ’s’ using the character ’c’ as a delimiter.
	The array ends with a NULL pointer.										*/
char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	str_count;

	if (!s)
		return (NULL);
	str_count = ft_count_str(s, c);
	arr = malloc((str_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[str_count] = NULL;
	if (!ft_str_fill(arr, s, c))
	{
		ft_free_all(arr, str_count);
		return (NULL);
	}
	return (arr);
}

/*	Counts the number of strings to be created that are delimited
	by the character 'c'.													*/
static size_t	ft_count_str(char const *s, char c)
{
	size_t	str_count;
	size_t	i;

	str_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			str_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (str_count);
}

/*	Fills the array with the strings to be created.							*/
static char	**ft_str_fill(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!ft_str_alloc(arr, s, c, i))
				return (NULL);
			j = 0;
			while (*s && *s != c)
				arr[i][j++] = *s++;
			arr[i][j] = '\0';
		}
		i++;
	}
	return (arr);
}

/*	Allocates memory for all the strings to be created.						*/
static char	**ft_str_alloc(char **arr, char const *s, char c, size_t i)
{
	size_t	str_size;
	char	*end_of_str;

	end_of_str = ft_strchr(s, (int)c);
	if (end_of_str == NULL)
		str_size = ft_strlen(s);
	else
		str_size = end_of_str - s;
	arr[i] = malloc(str_size + 1);
	if (!arr[i])
		return (NULL);
	return (arr);
}

/*	Frees the memory allocated to the strings. Used when any of the
	memory allocations fail.												*/
static void	ft_free_all(char **arr, size_t str_count)
{
	size_t	i;

	i = 0;
	while (arr[i] && i < str_count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
