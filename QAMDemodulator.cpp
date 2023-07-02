#include "QAMDemodulator.h"

vector<int> QAMDemodulator::demodulator(vector <complex<double>>  signal)
{
    vector < int>bits;
    switch (_modulation) {
    case QPSK:
        bits = qpsk(signal);
        break;
    case QAM16:
        bits = qam16(signal);
        break;
    case QAM64:
        bits = qam64(signal);
        break;
    }
    return bits;
}

vector<int> QAMDemodulator::qpsk(vector <complex<double>> signal)
{
    vector<int>bits;
    for (int i = 0; i < signal.size(); i++) {
        if (imag(signal[i]) < 0) {
            bits.push_back(1);
        }
        else bits.push_back(0);
        if (real(signal[i]) < 0) {
            bits.push_back(1);
        }
        else bits.push_back(0);
    }
    return bits;
}

vector<int> QAMDemodulator::qam16(vector <complex<double>>  signal)
{
    vector<int>bits;
    for (int i = 0; i < signal.size(); i++) {
        if (real(signal[i]) < -2.0) {
            bits.push_back(0);
            bits.push_back(0);
        }
        else if (real(signal[i]) < 0.0) {
            bits.push_back(0);
            bits.push_back(1);
        }
        else if (real(signal[i]) < 2.0) {
            bits.push_back(1);
            bits.push_back(1);
        }
        else {
            bits.push_back(1);
            bits.push_back(0);
        }
        if (imag(signal[i]) < -2.0) {
            bits.push_back(1);
            bits.push_back(0);
        }
        else if (imag(signal[i]) < 0.0) {
            bits.push_back(1);
            bits.push_back(1);
        }
        else if (imag(signal[i]) < 2.0) {
            bits.push_back(0);
            bits.push_back(1);
        }
        else {
            bits.push_back(0);
            bits.push_back(0);
        }
    }
    return bits;
}

vector<int> QAMDemodulator::qam64(vector <complex<double>>  signal)
{   
    vector<int>bits;
    for (int i = 0; i < signal.size(); i++) {
        if (real(signal[i]) < -6.0) {
            bits.push_back(0);
            bits.push_back(0);
            bits.push_back(0);
        }
        else if (real(signal[i]) < -4.0) {
            bits.push_back(0);
            bits.push_back(0);
            bits.push_back(1);
        }
        else if (real(signal[i]) < -2.0) {
            bits.push_back(0);
            bits.push_back(1);
            bits.push_back(1);
        }
        else if (real(signal[i]) < -0.0) {
            bits.push_back(0);
            bits.push_back(1);
            bits.push_back(0);
        }
        else if (real(signal[i]) < 2.0) {
            bits.push_back(1);
            bits.push_back(1);
            bits.push_back(0);
        }
        else if (real(signal[i]) < 4.0) {
            bits.push_back(1);
            bits.push_back(1);
            bits.push_back(1);
        }
        else if (real(signal[i]) < 6.0) {
            bits.push_back(1);
            bits.push_back(0);
            bits.push_back(1);
        }
        else {
            bits.push_back(1);
            bits.push_back(0);
            bits.push_back(0);
        }
        if (imag(signal[i]) < -6.0) {
            bits.push_back(0);
            bits.push_back(0);
            bits.push_back(0);
        }
        else if (imag(signal[i]) < -4.0) {
            bits.push_back(0);
            bits.push_back(0);
            bits.push_back(1);
        }
        else if (imag(signal[i]) < -2.0) {
            bits.push_back(0);
            bits.push_back(1);
            bits.push_back(1);
        }
        else if (imag(signal[i]) < -0.0) {
            bits.push_back(0);
            bits.push_back(1);
            bits.push_back(0);
        }
        else if (imag(signal[i]) < 2.0) {
            bits.push_back(1);
            bits.push_back(1);
            bits.push_back(0);
        }
        else if (imag(signal[i]) < 4.0) {
            bits.push_back(1);
            bits.push_back(1);
            bits.push_back(1);
        }
        else if (imag(signal[i]) < 6.0) {
            bits.push_back(1);
            bits.push_back(0);
            bits.push_back(1);
        }
        else {
            bits.push_back(1);
            bits.push_back(0);
            bits.push_back(0);
        }
    }
    return bits;
}

