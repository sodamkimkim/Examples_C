#include <stdio.h>

void PrintBinary8Bit(char _data);
void PrintBinary16Bit(short _data);

// strlen
int StringLength(const char _str[]);

// strcmp -> ���ڿ� ��
// �� �����ڸ� ���ؼ� ���ڿ� ���� ������ �ƽ�Ű ������ ����.
int StrCmp(const char _lhs[], const char _rhs[]);

// strcpy -> ���ڿ� ����
void StrCpy(char _dest[], const char _sour[]); // destination, source

// strcat (String Concatenation)-> ���ڿ� ������
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

	// ���ڿ�(String)
	// ����(Character)
	// ASCII Code ���̽� - ���ڸ� ���ڷ� ��ȯ. char 1byte�ϳ��� 0~255 ǥ��
	char c = 'a' + 1;
	printf("c : %c, %d\n", c, c);
	char charArr[] = { 'a',65,'z',97};
	//char charArr[] = { 'a',65,'z',97,'\0' };// null���� �Է��ϸ� sting �� ���� �� �� �ִ�.
	for (int i = 0; i < 4; ++i) {
		printf("%c", charArr[i]);
	}
	printf("\n");
	printf("%s\n", charArr);// ������ġ���� 1byte�� �ǳʶٸ鼭 ���

	char charSize[] = "string";
	printf("charSize : %d byte\n", sizeof(charSize)); // 7����Ʈ.  ������ �ι��� ����������.

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("\n");

	// strLength
	printf("Hello, World! : %d\n\n", StringLength("Hello, World!"));

	// strcmp
	int cmpResult = StrCmp("Hello", "World");
	printf("\nCompare: %d,  %s\n", cmpResult, cmpResult == 1 ? "����" : "�ٸ�");

	// ����(Buffer), buff, buf
	char buff[128] = { 0 };
	// 0���� �ʱ�ȭ �߱� ������ �ι��� �ȵ��� hello������ �̻ڰ� ��µȴ�. (0�� null���ڷ� �ν�)
	// ��ǻ� null���ڱ��� ���簡 �̷������Ѵ�. =>_dest[srcLen]��  \0�־���� �Ѵ�.

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
	// 1. �� ���ڿ� ���� ���ϱ�
	// �ϴ� �� �� ���̰� �ٸ��� �ٸ�.
	int lhsLen = StringLength(_lhs);
	int rhsLen = StringLength(_rhs);

	// 2. ���ڿ��� ���̰� ���� �ٸ��� �ٸ� ���ڿ�
	if (lhsLen != rhsLen) return 0;

	// 3. ���ڿ��� ���̸�ŭ �ݺ��ϸ鼭 ���� ������ ���ϱ�
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
		//_sour[i] = _dest[i]; -> const�� ������ �Ұ���

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