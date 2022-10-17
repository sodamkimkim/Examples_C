#include <stdio.h>

void PrintBinary8Bit(char _data);
void PrintBinary16Bit(short _data);

// strlen
int StringLength(const char _str[]);

// strcmp -> 문자열 비교
// ㄴ 같은자리 비교해서 문자열 끝날 때까지 아스키 같은지 비교함.
int StrCmp(const char _lhs[], const char _rhs[]);

// strcpy -> 문자열 복사
void StrCpy(char _dest[], const char _sour[]); // destination, source

// strcat (String Concatenation)-> 문자열 합쳐줌
void StrCat(char _dest[], const char _sour1[], const char _sour2[]);

int main() {

	char data = 16 | 1;
	//char data = -1; // 11111111
	//char data = 128; // 1000 0000

	data = 128;
	printf("data : %d\n", data);
	PrintBinary8Bit(data);

	printf("data 16Bit ( short ) : %d\n", (short)data);
	PrintBinary16Bit((short)data);



	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("\n");

	// 문자열(String)
	// 문자(Character)
	// ASCII Code 베이스 - 숫자를 문자로 변환. char 1byte하나에 0~255 표현
	char c = 'a' + 1;
	printf("c : %c, %d\n", c, c);
	char charArr[] = { 'a',65,'z',97};
	//char charArr[] = { 'a',65,'z',97,'\0' };// null문자 입력하면 sting 이 끝을 알 수 있다.
	for (int i = 0; i < 4; ++i) {
		printf("%c", charArr[i]);
	}
	printf("\n");
	printf("%s\n", charArr);// 시작위치에서 1byte씩 건너뛰면서 출력

	char charSize[] = "string";
	printf("charSize : %d byte\n", sizeof(charSize)); // 7바이트.  마지막 널문자 공간때문에.

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("\n");

	// strLength
	printf("Hello, World! : %d\n\n", StringLength("Hello, World!"));

	// strcmp
	int cmpResult = StrCmp("Hello", "World");
	printf("\nCompare: %d,  %s\n", cmpResult, cmpResult == 1 ? "같음" : "다름");

	// 버퍼(Buffer), buff, buf
	char buff[128] = { 0 };
	// 0으로 초기화 했기 때문에 널문자 안들어가도 hello까지만 이쁘게 출력된다. (0을 null문자로 인식)
	// 사실상 null문자까지 복사가 이뤄져야한다. =>_dest[srcLen]에  \0넣어줘야 한다.

	//strcpy
	StrCpy(buff, "Hello");
	printf("%d\n", StringLength("Hello"));
	printf("buff: %s\n", buff);

	// strcat
	StrCat(buff, "Hel", "lo");
	printf("buff : %s\n", buff);

	return 0;
}
// 0x01 0x02 0x04 0x08 0x50 0x60 0x70 0x90
void PrintBinary8Bit(char _data) {
	for (int i = 0; i < 8; ++i) {
		if ((_data & 0x80) != 0) printf("1");
		else printf("0");
		_data <<= 1;

	}
	printf("\n");
}

void PrintBinary16Bit(short _data)
{
	for (int i = 0; i < 16; ++i)
	{
		if ((_data & 0x01 << 15) != 0) printf("1");
		else printf("0");
		_data <<= 1;
	}
	printf("\n");
}

int StringLength(const char _str[])
{
	printf("_str size: %d byte\n", sizeof(_str));
	int cnt = 0;
	// a s d f \0
	while (_str[cnt] != '\0') {
		++cnt;
	}
	return cnt;
}

int StrCmp(const char _lhs[], const char _rhs[])
{
	// 1. 각 문자열 길이 구하기
	// 일단 좌 우 길이가 다르면 다름.
	int lhsLen = StringLength(_lhs);
	int rhsLen = StringLength(_rhs);

	// 2. 문자열의 길이가 서로 다르면 다른 문자열
	if (lhsLen != rhsLen) return 0;

	// 3. 문자열의 길이만큼 반복하면서 문자 단위로 비교하기
	for (int i = 0; i < lhsLen; ++i) {
		if (_lhs[i] != _rhs[i]) return 0;
	}
	return 1;
}

void StrCpy(char _dest[], const char _sour[])
{
	int srcLen = StringLength(_sour);
	for (int i = 0; i < srcLen; ++i) {
		_dest[i] = _sour[i];
		//_sour[i] = _dest[i]; -> const라서 값변경 불가능

	}
	_dest[srcLen] = '\0';
}
void StrCat(char _dest[], const char _sour1[], const char _sour2[])
{
	int src1Len = StringLength(_sour1);
	int src2Len = StringLength(_sour2);
	printf("here %d\n", src1Len);
	printf("here %d\n", src2Len);

	for (int i = 0; i < src1Len; ++i) {
		_dest[i] = _sour1[i];
		printf("%c\n", _dest[i]);
	}
	for (int i = 0; i < src2Len; ++i) {
		_dest[src1Len + i] = _sour2[i];
		printf("%c\n", _dest[src1Len +i]);
	}
	int destLen = src1Len + src2Len;
	_dest[destLen] = '\0';
}