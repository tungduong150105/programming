#include "SoPhuc.cpp"
#include <bits/stdc++.h>

int main() {

	cSoPhuc sp1, sp2;

	sp1.Nhap();
	sp2.Nhap();

	cSoPhuc Cong = sp1.Cong(sp2);
	cSoPhuc Tru = sp1.Tru(sp2);
	cSoPhuc Nhan = sp1.Nhan(sp2);
	cSoPhuc Chia = sp1.Chia(sp2);

	std::cout << "Tong 2 so phuc la: ";
	Cong.Xuat();

	std::cout << "Hieu 2 so phuc la: ";
	Tru.Xuat();

	std::cout << "Tich 2 so phuc la: ";
	Nhan.Xuat();

	std::cout << "Thuong 2 so phuc la: ";
	Chia.Xuat();

	return 0;
}
