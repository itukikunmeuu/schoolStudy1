#include "DxLib.h"
#include <vector>


{
std::vector<int> a = { 1,2,3,4,5 };
int& b = a[3]; 
cout << b << endl;
a = { 2,4,6,8,10,12 };
cout << a << endl;

return;
}
