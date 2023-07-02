#pragma once

#include <vector>
#include <complex>

using namespace std;

enum Modulation {
    QPSK,
    QAM16,
    QAM64
};

class QAMModulator{
public:

	QAMModulator(Modulation mod) : _modulation(mod) {};
    vector<complex<double>>modulate(vector <int> bits);


private:
    Modulation _modulation;

    vector<complex<double>>qpsk(vector <int> bits); 
    vector<complex<double>>qam16(vector <int> bits);
    vector<complex<double>>qam64(vector <int> bits);
    
};

