

//テンプレートクラス
template<typename T>
class Array {
private:
	T array_[10];
public:
	Array() {
		float start = 3.14f;
		for (T& a : attay_) {
			a = start;
			start += 0.1;
		}
	}
	void Output
	{
		for (const T& a : array_)
		{
			cout << a << endl;
		}
	}
};

int main() {
	constexpr int row = 3;
	constexpr int col = 4;
	Array<int>iarray;
	Array<float>farray;

	iarray.Output();
	farray.Output();

	int a[10];
	a[10] = 3;

	return 0;

}