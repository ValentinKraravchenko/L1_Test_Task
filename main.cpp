#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>
#include <complex>
#include "QAMModulator.h"
#include "GaussianNoise.h"
#include "QAMDemodulator.h"

using namespace std;

std::vector<int> generateRandomBits(int numBits) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> bitDist(0, 1);

    std::vector<int> bits;
    for (int i = 0; i < numBits; i++) {
        int bit = bitDist(gen);
        bits.push_back(bit);
    }

    return bits;
}

int countErrors(std::vector<int> bits1, std::vector<int> bits2) {
    int errorCount = 0;
    for (int i = 0; i < bits1.size(); i++) {
        if (bits1[i] != bits2[i]) {
            errorCount++;
        }
    }
    return errorCount;
}

int main() {
    ofstream outputFile_qpsk("data_for_plot_qpsk.csv");
    ofstream outputFile_qam16("data_for_plot_qam16.csv");
    ofstream outputFile_qam64("data_for_plot_qam64.csv");
    vector<int>bits = generateRandomBits(240);
    QAMModulator qpsk(Modulation::QPSK);
    vector<complex<double>>qpsk_bits = qpsk.modulate(bits);
    QAMModulator qam16(Modulation::QAM16);
    vector<complex<double>>qam16_bits = qam16.modulate(bits);
    QAMModulator qam64(Modulation::QAM64);
    vector<complex<double>>qam64_bits = qam64.modulate(bits);
    GaussianNoise noise;
    QAMDemodulator qpsk_demod(Modulation::QPSK);
    QAMDemodulator qam16_demod(Modulation::QAM16);
    QAMDemodulator qam64_demod(Modulation::QAM64);
    for (int i = 1; i < 501; i++) {
        noise.setDispersion(i / 10.0);
        vector<complex<double>>noise_qam16 = noise.addNoise(qam16_bits);
        vector<complex<double>>noise_qam64 = noise.addNoise(qam64_bits);
        vector<int>qpsk_de_bits = qpsk_demod.demodulator(noise.addNoise(qpsk_bits));
        vector<int>qam16_de_bits = qam16_demod.demodulator(noise.addNoise(qam16_bits));
        vector<int>qam64_de_bits = qam64_demod.demodulator(noise.addNoise(qam64_bits));
        outputFile_qpsk << countErrors(bits, qpsk_de_bits)/(double)bits.size()<<endl;
        outputFile_qam16 << countErrors(bits, qam16_de_bits) / (double)bits.size() << endl;
        outputFile_qam64 << countErrors(bits, qam64_de_bits) / (double)bits.size() << endl;
    }

    return 0;
}

