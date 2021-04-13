#ifndef Myfunctions
#define Myfunctions
typedef unsigned char* byte_pointer;
//2.55�ĸ�������
void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_pointer(void* x);
//2.55�ĺ���
void Function2_55();
//2.59�ĺ���
void Function2_59();
//2.63�ĺ���
void Function2_63();
//2.67�ĺ���
int int_size_is_32();
// 2.71�ĺ���
int xbyte(unsigned word, int bytenum);
//2.75
int signed_high_prod(int x, int y);//��Ŀ�ṩ�ĺ���
unsigned unsigned_high_prod(unsigned x, unsigned y);
//2.79
int mul3div4(int x);

//2.95�ĺ���
float_bits float_half(float_bits f)
{
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xff;
	unsigned frac = f & 0x7fffff;
	if (exp == 0xff)
		return f;
	else if (exp == 0)//�ǹ��
		return (sign << 31) | ((frac >> 1) + (1 & (frac & 3 == 3)));
	else if (exp == 1)//���
		return (sign << 31) | ((exp - 1) << 23) | ((frac >> 1) & 0x400000);
	else
		return (sign << 31) | ((exp - 1) << 23) | frac;
}
#endif


