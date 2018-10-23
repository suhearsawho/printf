#include "holberton.h"

/**
 * rot13 - encodes a string with rot13
 * @str: string to be encoded
 * Return: pointer to beginning of string
 */
char *rot13(char *str)
{
	char encode[] = "azAZbyBYcxCXdwDWevEVfuFUgtGThsHSirIRjqJQkpKPloLOmnMN";
	int i, k = 0;
	int encode_r;

	while (*(str + k) != '\0')
	{
		encode_r = 13;
		for (i = 0; i < 52; i++)
		{
			if (*(str + k) == encode[i])
			{
				*(str + k) += encode_r;
				break;
			}
			encode_r *= -1;
		}
		k++;
	}
	return (str);
}

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 * Return: returns the reversed string
 */
char *rev_string(char *s)
{
	int copy;
	int count;
	int i, j;

	for (count = 0; *(s + count) != '\0'; count++)
		;
	for (i = 0, j = count - 1; i < j; i++, j--)
	{
		copy = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = copy;
	}
	return (s);
}

/**
  * print_rev_str - prints a reversed string
  * @input: argument array that is passed
  * Return: number of characters
  */
int print_rev_str(va_list input)
{
	char *buf;
	char *str;
	char temp[] = "(null)";
	int i, k;

	buf = va_arg(input, char *);
	i = _strlen(buf);
	if (buf == NULL)
	{
		buf = malloc(sizeof(char) * 7);
		if (buf == NULL)
			return (0);
		for (i = 0; temp[i] != '\0'; i++)
			*(buf + i) = temp[i];
		*(buf + i) = temp[i];
		i--;
	}
	else
	{
		str = malloc(sizeof(char) * i);
		if (str == NULL)
			return (0);
		for (k = 0; k < i; k++)
			*(str + k) = *(buf + k);
		buf = rev_string(str);
	}

	if (write(1, buf, sizeof(char) * i) == -1)
		return (0);

	if (str != NULL)
		free(str);
	else
		free(buf);

	return (i);
}

/**
  * print_rot13 - prints a rot13 encrypted string
  * @input: argument array that is passed
  * Return: number of characters
  */
int print_rot13(va_list input)
{
	char *buf;
	char *str;
	char temp[] = "(null)";
	int i, k;

	buf = va_arg(input, char *);
	i = _strlen(buf);
	if (buf == NULL)
	{
		buf = malloc(sizeof(char) * 7);
		if (buf == NULL)
			return (0);
		for (i = 0; temp[i] != '\0'; i++)
			*(buf + i) = temp[i];
		*(buf + i) = temp[i];
		i--;
	}
	else
	{
		str = malloc(sizeof(char) * i);
		if (str == NULL)
			return (0);
		for (k = 0; k < i; k++)
			*(str + k) = *(buf + k);
		buf = rot13(str);
	}

	if (write(1, buf, sizeof(char) * i) == -1)
		return (0);
	if (str != NULL)
		free(str);
	else
		free(buf);

	return (i);
}
