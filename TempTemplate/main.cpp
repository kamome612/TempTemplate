#include <iostream>
#include "cmath"

using std::cout;
using std::cin;
using std::endl;
using std::sqrt;

//テンプレート 型をパラメータにとっていろいろな型に対応できる機能
//　　　　　　 多態性の一つ(同じ関数や、クラスをいろんな型に対応させられる)


//オーバーロードで書く
//2つの整数のうち大きいほうを返す
int myMax(int a, int b);
//2つの単精度実数(float)のうち大きいほうを返す
float myMax(float a, float b);
//2つの倍精度実数(double)のうち大きいほうを返す
double myMax(double a, double b);

//関数テンプレート
template <typename T>
T tMax(T a, T b) {
	if (a > b)
		return a;
	else
		return b;
}

//クラステンプレート
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
	void PrintVec() { cout << "(x,y) = (" << x << "," << y << ")" << endl; }//インライン定義
};
//ベクトルの長さをT型で返すメンバ関数を作る
//ベクトルの長さで比較する>演算子をオーバーロード
//ベクトルの長さを比べて長い方が表示して本当にあっているか確認(tMaxに入れる!)

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
	//double var6 = 1e-15;//10のマイナス15乗
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
	cout << "ベクトルの長さ : " << res.Length() << endl;
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