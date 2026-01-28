## Anomaly Detection Results

This folder contains the results of anomaly detection performed on
Galvanic Skin Response (GSR) and Electromyography (EMG) signals
to identify stress-related patterns.

### Overview
Anomalies in GSR and EMG signals are treated as indicators of abnormal
stress responses. Two machine learning techniques were used to detect
these anomalies:

- Isolation Forest
- Autoencoder

The combination of these models improves the sensitivity and reliability
of anomaly detection.

---

### Methods Used

#### Isolation Forest
- Number of estimators: 100
- Contamination rate: 5%
- Detects anomalies by isolating data points that differ significantly
  from normal physiological patterns.

#### Autoencoder
- Two-layer encoder with a linear decoder
- Trained on normal GSR and EMG patterns
- Anomalies identified using reconstruction error
- Threshold set at the 95th percentile of Mean Squared Error (MSE)

---

### Results and Observations

- Figures show both normal and stressed conditions based on GSR and EMG values  
- Normal condition exhibits stable sensor readings  
- Stressed condition shows elevated GSR and EMG responses  
- Approximately **7.75%** of data points were classified as anomalies  
- Anomaly distribution is visualized using a pie chart  
- Time-series plots highlight sudden spikes and drops in GSR and EMG values  
- Correlation analysis indicates a modest negative correlation between
  GSR and EMG, reflecting distinct stress response patterns  

---

### Significance

The detected anomalies correspond to periods of high physiological stress
and are crucial for early identification of stress-related disorders.
This is especially important for monitoring children with mental
disabilities and individuals diagnosed with ADHD and Autism Spectrum
Disorder (ASD).

The results validate the effectiveness of Isolation Forest and
Autoencoder models for stress anomaly detection and support their use
in real-time mental health monitoring systems.
