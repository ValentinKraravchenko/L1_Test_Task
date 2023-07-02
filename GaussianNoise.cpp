#include "GaussianNoise.h"
#include <random>

using namespace std;

vector<complex<double>> GaussianNoise::addNoise(vector<complex<double>> signal)
{
   
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> noiseDist(0, sqrt(_dispersion));

    vector<complex<double>>noise_signal = {};

    for (int i = 0; i < signal.size(); i++) {
        noise_signal.push_back(signal[i] + noiseDist(gen)+noiseDist(gen)*1i);
    }

    return noise_signal;
}

void GaussianNoise::setDispersion(double dispersion)
{
    _dispersion = dispersion;
}
