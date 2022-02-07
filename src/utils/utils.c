#include "../../inc/fdf.h"

float	ft_rad(float degree)
{
	float	rad;

	rad = (degree / 180) * M_PI;
	return (rad);
}

char	*ft_word(char *str)
{
	char	*word;
	size_t	i;
	
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	ft_strlcpy(word, str, i + 1);
	printf("word %s\n", word);
	return (word);

}

char	*ft_strupper(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		ft_toupper(str[i++]);
	return (str);
}