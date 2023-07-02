#pragma once
#include "QAMModulator.h"

class QAMDemodulator
{
public:

	QAMDemodulator(Modulation demod) : _modulation(demod) {};

	vector<int>demodulator(vector <complex<double>> signal);

private: 
	Modulation _modulation;
	vector<int>qpsk(vector <complex<double>> signal);
	vector<int>qam16(vector <complex<double>>  signal);
	vector<int>qam64(vector <complex<double>> signal);
	
};

