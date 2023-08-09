#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * find_max_char - finds the biggest character in the username
 *
 * @username: the username
 * @length: the length of the username
 * Return: biggest character
 */
int find_max_char(char *username, int length)
{
	int max_char;
	int current_char;
	unsigned int rand_num;

	max_char = *username;

	for (int i = 0; i < length; i++)
	{
		current_char = username[i];
		if (current_char > max_char)
			max_char = current_char;
	}

	srand(max_char ^ 14);
	rand_num = rand();

	return (rand_num & 63);
}

/**
 * multiply_username_chars - multiplies each character of the username
 *
 * @username: the username
 * @length: the length of the username
 * Return: the multiplied character
 */
int multiply_username_chars(char *username, int length)
{
	int result;
	int current_char;

	result = 0;

	for (int i = 0; i < length; i++)
	{
		current_char = username[i];
		result = result + current_char * current_char;
	}

	return (((unsigned int)result ^ 239) & 63);
}

/**
 * generate_random_char - generates  random character
 *
 * @username: the username
 * Return: random character
 */
int generate_random_char(char *username)
{
	int result;
	int counter;

	result = counter = 0;

	while (counter < *username)
	{
		result = rand();
		counter++;
	}

	return (((unsigned int)result ^ 229) & 63);
}

/**
 * main - Entry point
 *
 * @argc: the arguments count
 * @argv:  the arguments vector
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char keygen[7];
	int length, ch, vch;
	long alph[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };
	(void)argc;

	for (length = 0; argv[1][length]; length++)
		;
	/* ----------- f1 ----------- */
	keygen[0] = ((char *)alph)[(length ^ 59) & 63];
	/* ----------- f2 ----------- */
	ch = vch = 0;
	while (vch < length)
	{
		ch = ch + argv[1][vch];
		vch++;
	}
	keygen[1] = ((char *)alph)[(ch ^ 79) & 63];
	/* ----------- f3 ----------- */
	ch = 1;
	vch = 0;
	while (vch < length)
	{
		ch = argv[1][vch] * ch;
		vch++;
	}
	keygen[2] = ((char *)alph)[(ch ^ 85) & 63];
	/* ----------- f4 ----------- */
	keygen[3] = ((char *)alph)[find_max_char(argv[1], length)];
	/* ----------- f5 ----------- */
	keygen[4] = ((char *)alph)[multiply_username_chars(argv[1], length)];
	/* ----------- f6 ----------- */
	keygen[5] = ((char *)alph)[generate_random_char(argv[1])];
	keygen[6] = '\0';
