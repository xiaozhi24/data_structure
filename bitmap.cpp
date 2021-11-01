#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;
int main() {
#ifdef _DEBUG
	printf("正在使用 Debug 模式编译程序...\n");
#else
	printf("正在使用 Release 模式编译程序...\n");
#endif

/*
#define INT_BITS sizeof(int)
#define SHIFT 5 // 2^5=32
#define MASK 0x1f // 2^5=32
#define MAX 1024*1024*1024 //max number
	int bitmap[MAX / INT_BITS];
	
	* 设置第i位
	* i >> SHIFT 相当于 i / (2 ^ SHIFT),
	* i&MASK相当于mod操作 m mod n 运算
	
	void set(int i) {;
		bitmap[i >> SHIFT] |= 1 << (i & MASK);
	}
	//获取第i位
	int test(int i) {
		return bitmap[i >> SHIFT] & (1 << (i & MASK));
	}
	//清除第i位
	int clear(int i) {
		return bitmap[i >> SHIFT] & ~(1 << (i & MASK));
	}
*/
	class Bitmap {
	private:
		int N;
		char * M;
	public:
		Bitmap(int n = 8) { M = new char[N = (n + 7) / 8]; memset(M, 0, N);}
		~Bitmap() { delete[] M; M = NULL; }
		void set(int k) { M[k >> 3] |= (0x80 >> (k & 0x07)); }
		void clear(int k) { M[k >> 3] &= ~(0x80 >> (k & 0x07)); }
		bool test(int k) { return M[k >> 3] & (0x80 >> (k & 0x07)); }
		
	};
	int nums[12] = { 5, 2, 1, 2, 6, 2, 5, 6, 7, 8 };
	Bitmap mybitmap(32);
	mybitmap.set(12);
	mybitmap.set(13);
	mybitmap.set(14);
	int i=0;
	while(nums[i]) {
		mybitmap.set(nums[i]);
		i++;
	}
	//利用bitmap实现简单的排序
	for (int j = 31; j >= 0; j--) {
		if(mybitmap.test(j)) {
			cout << j << ',';
		}
	}
	int a;
	int b;
	a = mybitmap.test(13);
	b = mybitmap.test(18);
	cout << sizeof(mybitmap) << endl;
	system("pause");
	return 0;
}