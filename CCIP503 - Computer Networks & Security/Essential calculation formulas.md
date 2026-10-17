
These are the main formulas you should memorize for your exam.

| Topic                           | Formula                                                                              |
| ------------------------------- | ------------------------------------------------------------------------------------ |
| Transmission delay              | $d_{\text{trans}}=\frac{L}{R}$                                                       |
| Propagation delay               | $d_{\text{prop}}=\frac{d}{s}$                                                        |
| Total nodal delay               | $d_{\text{nodal}}=d_{\text{proc}}+d_{\text{queue}}+d_{\text{trans}}+d_{\text{prop}}$ |
| Traffic intensity               | $\rho=\frac{La}{R}$                                                                  |
| File transfer time              | $T=\frac{\text{file size in bits}}{R}$                                               |
| Average throughput              | $\frac{\text{delivered data}}{\text{transfer time}}$                                 |
| Bottleneck throughput           | $\min(R_1,R_2,\ldots,R_n)$                                                           |
| Per-connection throughput       | $\min(R_s,R_c,R/N)$                                                                  |
| Non-persistent HTTP             | $2RTT+\text{transmission time}$                                                      |
| Average cache response          | $hT_{\text{hit}}+(1-h)T_{\text{miss}}$                                               |
| Traffic intensity after caching | $\rho_{\text{new}}=\rho_{\text{old}}(1-h)$                                           |

Where $L$ is packet length in bits, $R$ is link rate in bits/s, $d$ is distance in metres, $s$ is propagation speed, $a$ is packet arrival rate, $N$ is number of connections, and $h$ is cache hit rate.

Remember these conversions:

$$ 1\text{ byte}=8\text{ bits} $$

$$ 1\text{ Mbps}=10^6\text{ bits/s} $$

$$ 1\text{ km}=1000\text{ m} $$

$$ 1\text{ second}=1000\text{ ms} $$
