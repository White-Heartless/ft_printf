#include "./includes/libftprintf.h"

int	main(void)
{
	int i= 0;
	int j= 0;
	j = ft_printf("%d\n", 13);
	i =    printf("%d\n", 13);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	j = ft_printf("%d\n", 'a');
	i =    printf("%d\n", 'a');
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	j = ft_printf("%5d\n", 42);
	i =    printf("%5d\n", 42);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	j = ft_printf("%05d\n", 43);
	i =    printf("%05d\n", 43);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	j = ft_printf("%5.3d\n", 14);
	i =    printf("%5.3d\n", 14);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	j = ft_printf("%3.5d\n", 15);
	i =    printf("%3.5d\n", 15);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
}
