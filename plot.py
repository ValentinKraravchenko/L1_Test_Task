import matplotlib.pyplot as plt
import pandas as pd

data_for_qpsk = pd.read_csv("data_for_plot_qpsk.csv")
data_for_qam16 = pd.read_csv("data_for_plot_qam16.csv")
data_for_qam64 = pd.read_csv("data_for_plot_qam64.csv")

plt.plot(data_for_qpsk,label="qpsk")
plt.plot(data_for_qam16,label="qam16")
plt.plot(data_for_qam64,label="qam64")
plt.xlabel("Noise Dispercion")
plt.ylabel("BER")
plt.legend()
plt.grid(True)
plt.show()
