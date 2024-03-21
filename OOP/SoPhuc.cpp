#include "SoPhuc.h"
#include <bits/stdc++.h>

void cSoPhuc::Nhap() {
	std::cout << "Nhap phan thuc: ";
	std::cin >> this->dPhanThuc;
	std::cout << "Nhap phan ao: ";
	std::cin >> this->dPhanAo;
}

void cSoPhuc::Xuat() {
	std::cout << std::fixed << std::setprecision(2);
	std::cout << this->dPhanThuc << " + " << this->dPhanAo << "i\n";
}

cSoPhuc cSoPhuc::Cong(cSoPhuc sp) {
	cSoPhuc KetQua;
	KetQua.dPhanThuc += this->dPhanThuc;
	KetQua.dPhanAo += this->dPhanAo;
	return KetQua;
}

cSoPhuc cSoPhuc::Tru(cSoPhuc sp) {
	cSoPhuc KetQua;
	KetQua.dPhanThuc -= this->dPhanThuc;
	KetQua.dPhanAo -= this->dPhanAo;
	return KetQua;
}

cSoPhuc cSoPhuc::Nhan(cSoPhuc sp) {
	cSoPhuc KetQua;
	KetQua.dPhanThuc = sp.dPhanThuc * this->dPhanThuc - sp.dPhanAo * this->dPhanAo;
	KetQua.dPhanAo = sp.dPhanThuc * this->dPhanAo - sp.dPhanAo * this->dPhanThuc;
	return KetQua;
}

cSoPhuc cSoPhuc::Chia(cSoPhuc sp) {
	cSoPhuc KetQua;
	double dDiv = this->dPhanThuc * this->dPhanThuc + this->dPhanAo * this->dPhanAo;
	KetQua.dPhanThuc = (sp.dPhanThuc * this->dPhanThuc + sp.dPhanAo * this->dPhanAo) / dDiv;
	KetQua.dPhanAo = (sp.dPhanAo * this->dPhanThuc - sp.dPhanThuc * this->dPhanAo) / dDiv;
	return KetQua;
}
