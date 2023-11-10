class CManiac {
public:
    // 単項 + 演算子を定義する。
    int operator+() {
        return 2;
    }
};

int main() {
    CManiac maniac;          // クラスオブジェクト maniac を作成する。
    int iValue = +maniac;   // 単項の+ 演算子を maniac に適用する。
    printf("iValue = %d\n", iValue);    // 答えは 2 になります。
    return 0;
}