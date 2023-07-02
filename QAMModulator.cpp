#include "QAMModulator.h"

vector<complex<double>> QAMModulator::modulate(vector<int> bits)
{
    vector < complex<double>>modulated_bites;
    switch (_modulation) {
    case QPSK:
        modulated_bites = qpsk(bits);
        break;
    case QAM16:
        modulated_bites = qam16(bits);
        break;
    case QAM64:
        modulated_bites = qam64(bits);
        break;
    }
    
	return modulated_bites;
}

vector<complex<double>> QAMModulator::qpsk(vector <int> bits)
{
    vector<complex<double>>modulated_bits = {};
    double imag;
    double real;
    for (int i = 0; i < bits.size()-bits.size()%2; i += 2) {
        if (bits[i] == 0) {
            imag = sqrt(2) / 2;
        }
        else {
            imag = -sqrt(2) / 2;
        }
        if (bits[i + 1] == 0) {
            real = sqrt(2) / 2;
        }
        else {
            real = -sqrt(2) / 2;
        }
        modulated_bits.push_back(real+imag*1i);
    }

    return modulated_bits;
}

vector<complex<double>> QAMModulator::qam16(vector<int> bits)
{
    vector<complex<double>>modulated_bits = {};
    double imag;
    double real;
    for (int i = 0; i < bits.size() - bits.size() % 4; i += 4) {
        if (bits[i]==0 && bits[i+1]==0) {
            real = -3.0;
        }
        else if (bits[i] == 0 && bits[i + 1] == 1) {
            real = -1.0;
        }
        else if (bits[i] == 1 && bits[i + 1] == 1) {
            real = 1.0;
        }
        else {
            real = 3.0;
        }
        if (bits[i+2] == 1 && bits[i + 3] == 0) {
            imag = -3.0;
        }
        else if (bits[i+2] == 1 && bits[i + 3] == 1) {
            imag = -1.0;
        }
        else if (bits[i+2] == 0 && bits[i + 3] == 1) {
            imag = 1.0;
        }
        else {
            imag = 3.0;
        }
        modulated_bits.push_back(real + imag * 1i);
    }
    return modulated_bits;
}

vector<complex<double>> QAMModulator::qam64(vector<int> bits)
{
    vector<complex<double>>modulated_bits = {};
    double imag;
    double real;
    for (int i = 0; i < bits.size() - bits.size() % 6; i += 6) {
        if (bits[i]==0 && bits[i+1]==0 && bits[i+2]==0) {
            real = -7.0;
        }
        else if (bits[i] == 0 && bits[i + 1] == 0 && bits[i + 2] == 1) {
            real = -5.0;
        }
        else if (bits[i] == 0 && bits[i + 1] == 1 && bits[i + 2] == 1) {
            real = -3.0;
        }
        else if (bits[i] == 0 && bits[i + 1] == 1 && bits[i + 2] == 0) {
            real = -1.0;
        }
        else if (bits[i] == 1 && bits[i + 1] == 1 && bits[i + 2] == 0) {
            real = 1.0;
        }
        else if (bits[i] == 1 && bits[i + 1] == 1 && bits[i + 2] == 1) {
            real = 3.0;
        }
        else if (bits[i] == 1 && bits[i + 1] == 0 && bits[i + 2] == 1) {
            real = 5.0;
        }
        else {
            real = 7.0;
        }
        if (bits[i + 3] == 0 && bits[i + 4] == 0 && bits[i + 5] == 0) {
            imag = -7.0;
        }
        else if (bits[i + 3] == 0 && bits[i + 4] == 0 && bits[i + 5] == 1) {
            imag = -5.0;
        }
        else if (bits[i + 3] == 0 && bits[i + 4] == 1 && bits[i + 5] == 1) {
            imag = -3.0;
        }
        else if (bits[i + 3] == 0 && bits[i + 4] == 1 && bits[i + 5] == 0) {
            imag = -1.0;
        }
        else if (bits[i + 3] == 1 && bits[i + 4] == 1 && bits[i + 5] == 0) {
            imag = 1.0;
        }
        else if (bits[i + 3] == 1 && bits[i + 4] == 1 && bits[i + 5] == 1) {
            imag = 3.0;
        }
        else if (bits[i + 3] == 1 && bits[i + 4] == 0 && bits[i + 5] == 1) {
            imag = 5.0;
        }
        else {
            imag = 7.0;
        }
        modulated_bits.push_back(real + imag * 1i);
    }
    return modulated_bits;
}



