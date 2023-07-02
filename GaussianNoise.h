
#include <vector>
#include <complex>

using namespace std;

class GaussianNoise
{
public: 
	GaussianNoise() {};
	GaussianNoise(double dispersion) : _dispersion(dispersion) {};
	
	vector<complex<double>>addNoise(vector<complex<double>>signal);

	void setDispersion(double dispersion);

private:
	double _dispersion{1.0};
};

