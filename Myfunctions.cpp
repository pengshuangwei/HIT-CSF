#include<stdio.h>
#include<limits.h>
#include "Myfunctions.h"
//2.55的函数
void show_bytes(byte_pointer start, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++)
	{
		printf("%.2x ", start[i]);
	}
	printf("\n");
}
void show_int(int x)
{
	show_bytes((byte_pointer)&x, sizeof(int));
}
void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}
void show_pointer(void* x)
{
	show_bytes((byte_pointer)&x, sizeof(void*));
}
unsigned  srl(unsigned x, int k)
{
	unsigned xsra = (int)x >> k;
	unsigned total_w = sizeof(int) << 3;
	total_w = total_w - k;
	unsigned mask = 1 << total_w;
	mask = mask - 1;
	return xsra & mask;
}
unsigned sra(int x, int k)
{
	int xsrl = (unsigned)x >> k;
	unsigned total_w = sizeof(int) << 3;
	total_w = total_w - k - 1;
	int mask_w = 1 << total_w;
	int sign = xsrl & mask_w;
	int right = (mask_w - 1) & xsrl;
	int left = ~sign + 1;
	return left | right;
}
void Function2_55()
{
	int val;
	printf("2-55:请输入测试用例：\n");
	scanf_s("%d", &val);
	float fval = (float)val;
	int* pval = &val;
	show_int(val);
	show_float(fval);
	show_pointer(pval);
}
//2_59的函数
void Function2_59()
{
	printf("2-59:\n");
	int x = 0x89ABCDEF;
	int y = 0x765432EF;
	printf("%X", x + (y << 24));
}
//2.63的函数
void Function2_63()
{
	int k;
	unsigned x = 0x12345678;
	printf("2-63:\n向右循环的个数为(小于32)(测试数字为：0x12345678):\n");
	scanf_s("%d", &k);
	printf("%d\t%x\n", x, srl(x, k));
	printf("%d\t%x\n", int(x), sra(x, k));

}
//2.67的函数
int int_size_is_32()
{
	int set_msb = 1 << 31;
	int beyond_msd = 1 << 31;
	beyond_msd = beyond_msd << 1;
	return set_msb && beyond_msd;
}
int int_size_is16()
{
	int set_msb = INT_MIN;
	int beyond_msb = 1 << 15;
	beyond_msb <<= 15;
	beyond_msb <<= 2;
	return set_msb && beyond_msb;
}
//2.71的函数
int xbyte(unsigned word, int bytenum)
{
	int ret = word << ((3 - bytenum) << 3);
	return ret >> 24;
}
//2.75
int signed_high_prod(int x, int y)
{//此函数是自己定义，具体实现无知，写出只为保证程序运行。
	return x * y;
}
unsigned unsigned_high_prod(unsigned x, unsigned y)
{
	int w = sizeof(int) << 3;
	return signed_high_prod(x, y) + (x >> (w - 1)) * y + x * (y >> (w - 1));
}
//2.79
int mul3div4(int x)
{
	int b0 = x & 1;
	int b1 = (x >> 1) & 1;
	int ans = (x >> 1) + (x >> 2);
	int w = sizeof(int) << 3;
	ans += (b0 & b1);
	ans += (x >> (w - 1) && (x & (((x << 1) + x) & 3)));
	return ans;
}

//2.95的函数
float_bits float_half(float_bits f)
{
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xff;
	unsigned frac = f & 0x7fffff;
	if (exp == 0xff)
		return f;
	else if (exp == 0)//非规格
		return (sign << 31) | ((frac >> 1) + (1 & (frac & 3 == 3)));
	else if (exp == 1)//规格
		return (sign << 31) | ((exp - 1) << 23) | ((frac >> 1) & 0x400000);
	else
		return (sign << 31) | ((exp - 1) << 23) | frac;
}

