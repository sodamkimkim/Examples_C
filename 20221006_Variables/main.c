#include <stdio.h>
#include <limits.h>
int main()
{
	// # 변수(Variable)
	// 변수 선언(Variable Declaration)
	int val = 10;	
	val = 5;

	char c = 'a';
	printf("c: %c\n", c);
	printf("char size: %d byte\n", sizeof(char));
	printf("c Address: %p\n", &c);
	printf("===================================\n");

	// # 정수형(Integer Type)
	 /*# Most Significant Bit(MSB, 최상위 비트) --> 부호비트가  0이면 양수, 1이면 음수
	 1바이트 = 2진수 8비트 (2의 8승은 256)이지만 부호비트 때문에 1바이트 정수는 -127~127표현가능
	 int는 원래 signed int (부호가 있는 int)
	 */

	// # 2의 보수법 ; 컴퓨터가 음수를 표현하는 방법
	// 1의 보수법에 +1
	signed int si = -1;
	printf("signed int : %d\n", si);
	printf("si size: %d\n", sizeof(si));
	unsigned int usi = -1; // 부호없는 int 이지만 -1이 들어가긴 함
	printf("unsigned int : %d\n", usi);
	printf("usi size: %d\n", sizeof(usi));

	printf("int Range: %d ~ %d\n", INT_MIN, INT_MAX); // #include <limits.h> 땡겨오기
	printf("===================================\n");
	// int 는 4byte라서 부호자리 + (+-)2의 31승까지 표현 가능
	// 0도 포함
	// 그래서 int range : -2,147,483,648 ~ 2,147,483,647
	int aaa = 2147483648; // 출력: -2147483648
	int bbb = 2147483649; // 출력: -2147483647
	int ccc = 2147483650; // 출력: -2147483646
	int ddd = 2147483651; // 출력: -2147483645
	printf("%d\n",aaa);
	printf("%d\n",bbb);
	printf("%d\n",ccc);
	printf("%d\n",ddd);
	
	printf("===================================\n");
	short s = 1;
	printf("short %d byte, %p\n", sizeof(s), &s);
	int i = 12;
	printf("int %d byte, %p\n", sizeof(i), &i);
	long l = 123;
	printf("long %d byte, %p\n", sizeof(l), &l);
	long long ll = 1234;
	printf("long long %d byte, %p\n", sizeof(ll), &ll);

	printf("===================================\n");
	// # 실수형(Floating-Point Type)
	// # 부동소수점(Floating-Point)
	float f = 1.1f; // float f = 1.1 이렇게 f 안붙이면 double을 float에다가 넣는 거임.
	// # double은 두배 더 정확도 가진 실수 이다. 엄연히 다름.
	// float쓸 땐 f 붙여주자.
	// float : 4byte, double: 8byte
	printf("float %d byte, %p\n", sizeof(f), &f);

	// Double - Precision Floating - Point
	double d = 1.1;
	printf("double %d byte, %p\n", sizeof(d), &d);
	long double ld = 1.12;
	printf("long double %d byte, %p\n", sizeof(ld), &ld);
	printf("===================================\n");
	
	// # 부동 소숫점 오차
	// 오차가 생긴다는 것을 인지 하고 대응해줘야 한다.
	// 컴퓨터가 부동소숫점을 계산하기 위해서 희안한 방법을 쓰기 때문임.
	int idx = 0;
	float result = 0.0f;
	for (idx = 0; idx < 1000; ++idx)
		result += 0.001f;
	printf("result: %f\n", result);
	return 0;

	

}