#include <iostream>
#include "cmath"

using std::cout;
using std::cin;
using std::endl;
using std::sqrt;

//�e���v���[�g �^���p�����[�^�ɂƂ��Ă��낢��Ȍ^�ɑΉ��ł���@�\
//�@�@�@�@�@�@ ���Ԑ��̈��(�����֐���A�N���X�������Ȍ^�ɑΉ���������)


//�I�[�o�[���[�h�ŏ���
//2�̐����̂����傫���ق���Ԃ�
int myMax(int a, int b);
//2�̒P���x����(float)�̂����傫���ق���Ԃ�
float myMax(float a, float b);
//2�̔{���x����(double)�̂����傫���ق���Ԃ�
double myMax(double a, double b);

//�֐��e���v���[�g
template <typename T>
T tMax(T a, T b) {
	if (a > b)
		return a;
	else
		return b;
}

//�N���X�e���v���[�g
template <typename T>
class Vec2
{
public:
	T x;
	T y;
	T GetX() { return (x); }
	T Length()const { return (sqrt(x * x + y * y)); }
	bool operator>(const Vec2 &other)const
	{
		return  Length() > other.Length();
	}
	void SetX(T _x) { x = _x; }
	void PrintVec() { cout << "(x,y) = (" << x << "," << y << ")" << endl; }//�C�����C����`
};
//�x�N�g���̒�����T�^�ŕԂ������o�֐������
//�x�N�g���̒����Ŕ�r����>���Z�q���I�[�o�[���[�h
//�x�N�g���̒������ׂĒ��������\�����Ė{���ɂ����Ă��邩�m�F(tMax�ɓ����!)

int main()
{
	//int var1 = 10;
	//int var2 = 20;
	////int res1 = myMax(var1, var2);
	//int res1 = tMax<int>(var1, var2);
	//cout << "tMax 10 20 : " << res1 << endl;
	//float var3 = 10.6;
	//float var4 = 2.1;
	////float res2 = myMax(var3, var4);
	//float res2 = tMax<float>(var3, var4);
	//cout << "tMax 10.6 2.1 : " << res2 << endl;
	//double var5 = 0.000062;
	//double var6 = 1e-15;//10�̃}�C�i�X15��
	////double res3 = myMax(var5, var6);
	//double res3 = tMax<double>(var5, var6);
	//cout << "tMax 0.000062 1e-15 : " << res3 << endl;

	Vec2<double>v1;
	v1.x = 5.5;
	v1.y = 1.4;
	Vec2<double>v2;
	v2.x = 2.3;
	v2.y = 3.5;
	Vec2<double> res = tMax(v1, v2);
	cout << endl;
	res.PrintVec();
	cout << "�x�N�g���̒��� : " << res.Length() << endl;
	return 0;
}

int myMax(int a, int b) {
	if (a < b)
		return b;
	else
		return a;
}

float myMax(float a, float b)
{
	if (a < b)
		return b;
	else
		return a;
}

double myMax(double a, double b)
{
	if (a < b)
		return b;
	else
		return a;
}