/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:23:05 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/03/04 16:35:00 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_read_file(int fd, char *buffer)
// {
// 	char	*buff;
// 	ssize_t	byte_read;
// 	char	*temp;

// 	buff = malloc(BUFFER_SIZE + 1);
// 	if (!buff)
// 		return (NULL);
// 	if (!buffer)
// 		buffer = ft_strdup("");
// 	if (!buffer)
// 		return (free(buff), NULL);
// 	byte_read = 1;
// 	while (byte_read > 0 && !ft_strchr(buffer, '\n'))
// 	{
// 		byte_read = read(fd, buff, BUFFER_SIZE);
// 		if (byte_read < 0)
// 			return (free(buff), free(buffer), NULL);
// 		buff[byte_read] = '\0';
// 		temp = buffer;
// 		buffer = ft_strjoin(buffer, buff);
// 		if (!buffer)
// 			return (free(buff), free(temp), NULL);
// 		free(temp);
// 	}
// 	return (free(buff), buffer);
// }

// char	*ft_extract_line(char *buffer)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	if (!buffer[0])
// 		return (NULL);
// 	while (buffer[i] != '\n' && buffer[i] != '\0')
// 		i++;
// 	line = malloc(sizeof(char) * (i + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (buffer[i] != '\n' && buffer[i] != '\0')
// 	{
// 		line[i] = buffer[i];
// 		i++;
// 	}
// 	if (buffer[i] == '\n')
// 		line[i++] = '\n';
// 	line[i] = '\0';
// 	return (line);
// }

// char	*ft_store(char *buffer)
// {
// 	char	*new_buffer;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (buffer[i] != '\n' && buffer[i] != '\0')
// 		i++;
// 	if (buffer[i] == '\0')
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
// 	if (!new_buffer)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (buffer[i] != '\0')
// 		new_buffer[j++] = buffer[i++];
// 	new_buffer[j] = '\0';
// 	free(buffer);
// 	return (new_buffer);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buffer = ft_read_file(fd, buffer);
// 	if (!buffer)
// 		return (NULL);
// 	line = ft_extract_line(buffer);
// 	buffer = ft_store(buffer);
// 	return (line);
// }

/* char *get_next_line(int fd)
{
    static char *buffer;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = ft_read_file(fd, buffer);
    if (!buffer)
        return (NULL);

    line = ft_extract_line(buffer);

    // Clear the buffer if the end of the file is reached
    if (!ft_strchr(buffer, '\n'))
    {
        free(buffer);
        buffer = NULL;
    }
    else
    {
        buffer = ft_store(buffer);
    }

    return (line);
} */

/* int main(void)
{
	int fd = open("file1.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
} */

static char	*read_buff(int fd, char *buffer)
{
	char		*tmp;
	ssize_t		buf_count;
	char		*mod_buffer;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (1)
	{
		buf_count = read(fd, tmp, BUFFER_SIZE);
		if (buf_count == -1)
			return (free(tmp), free(buffer), NULL);
		if (buf_count == 0)
			break ;
		tmp[buf_count] = '\0';
		if (buffer)
			mod_buffer = ft_strjoin(buffer, tmp);
		else
			mod_buffer = ft_strdup(tmp);
		free(buffer);
		buffer = mod_buffer;
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	return (free(tmp), buffer);
}

static char	*make_line(char *buffer)
{
	char		*nline;
	size_t		len;
	size_t		check;

	if (!buffer)
		return (NULL);
	len = 0;
	check = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		check++;
	nline = malloc(((len + check) + 1) * sizeof(char));
	if (!nline)
		return (NULL);
	ft_memcpy(nline, buffer, len + check);
	nline[len + check] = '\0';
	return (nline);
}

static char	*save_prev(char *buffer)
{
	char	*tmp;
	size_t	len;

	len = 0;
	while (buffer[len] != '\n' && buffer[len])
		len++;
	if (buffer[len] == '\0' || buffer[len + 1] == '\0')
		return (free(buffer), NULL);
	tmp = ft_strdup(&buffer[len + 1]);
	return (free(buffer), tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*read_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buff(fd, buffer);
	if (!buffer)
		return (NULL);
	read_line = make_line(buffer);
	if (read_line == NULL)
		return (NULL);
	buffer = save_prev(buffer);
	return (read_line);
}
