#ifndef MAIN_H
#define MAIN_H
/**
 * struct ops - structure for printing
 * @a: character representing format specifier
 * @f: pointer to printing function based on specifier
 *
 * Description: This structure forms is designed to allow for printing to std
 * output based on modifier passed to function.
 */

typedef struct ops
{
	char a;
	void (*f)(void *);
} ops_p;

int _printf(const char *format, ...);
int op_char(int);
int op_str(char *);
void op_int(void *);
void op_bin(unsigned int n);
void op_uint(unsigned int n);
void op_oct(unsigned int n);
void op_hex(unsigned int n);

#endif /* #ifndef MAIN_H */
