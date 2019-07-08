/*
** EPITECH PROJECT, 2018
** get_next.c
** File description:
** Fct get_next_line
*/

#include "my_navy.h"

char *my_calloc(int ln)
{
    char *result;

    if (!(result = malloc(sizeof(char) * ln + 1)))
        return (NULL);
    for (int i = 0; i <= ln; i++)
        result[i] = '\0';
    return (result);
}

char *copy(char *str1, char *str2)
{
    char *result;
    int len = 0;
    int j = 0;

    for (int i = 0; str1[i] != '\0'; i++, len++, j++);
    for (int i = 0; str2[i] != '\0'; i++, len++);
    result = my_calloc(len + 1);
    if (result == NULL)
        return (NULL);
    for (int i = 0; i < j; i++)
        result[i] = str1[i];
    len = len - j;
    for (int i = 0; i < len; i++, j++)
        result[j] = str2[i];
    return (result);
}

char *error(int fd, char *buffer, char *temp, int len)
{
    temp = buffer;
    buffer = my_calloc(len);
    if (buffer == NULL)
        return (NULL);
    read(fd, buffer, 10);
    buffer = copy(temp, buffer);
    free(temp);
    return (buffer);
}

char *line(int fd, char **temp, char *buffer, int len)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            temp[0] = copy(buffer + i + 1, "\0");
            return (buffer);
        }
        if (buffer[i + 1] == '\0') {
            len += 10;
            buffer = error(fd, buffer, temp[0], len);
        }
        if (buffer == NULL)
            return (NULL);
    }
    if (buffer[0] != '\0')
        return (buffer);
    return (NULL);
}

char *get_next_line(int fd)
{
    int len = 10;
    static char *temp = "NULL";
    char *buffer = my_calloc(10);

    if (10 < 0 || buffer == NULL)
        return (NULL);
    read(fd, buffer, 10);
    buffer = (temp != "NULL") ? copy(temp, buffer) : buffer;
    buffer = line(fd, &temp, buffer, len);
    return (buffer);
}
