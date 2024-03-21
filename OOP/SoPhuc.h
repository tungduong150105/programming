class cSoPhuc {
	double dPhanThuc, dPhanAo;
public:
	cSoPhuc(double dPhanThuc_ = 0, double dPhanAo_ = 0) : dPhanThuc(dPhanThuc_), dPhanAo(dPhanAo_) {}
	void Nhap();
	void Xuat();
	cSoPhuc Cong(cSoPhuc sp);
	cSoPhuc Tru(cSoPhuc sp);
	cSoPhuc Nhan(cSoPhuc sp);
	cSoPhuc Chia(cSoPhuc sp);
};
