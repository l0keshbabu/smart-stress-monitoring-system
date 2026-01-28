# Smart Stress Monitoring System
Using IoT and Machine Learning

---

## Project Overview

This project implements a Smart Stress Monitoring System using
physiological signals to detect and analyze stress levels in individuals.
The system focuses on objective, real-time stress monitoring using
Electromyography (EMG) and Galvanic Skin Response (GSR) sensors.

Sensor data is collected using an ESP8266 microcontroller, logged to
Google Sheets through Google Apps Script, and analyzed using machine
learning models in Google Colab. The system supports anomaly detection
and stress-related disorder prediction.

---

## System Workflow

EMG and GSR Sensors  
→ ESP8266 (NodeMCU)  
→ Google Sheets (Apps Script)  
→ Google Colab (Machine Learning)  
→ Stress Detection and Disorder Prediction

---

## Hardware Components

- ESP8266 (NodeMCU)
- Electromyography (EMG) Sensor
- Galvanic Skin Response (GSR) Sensor
- Electrode pads and connecting wires
- USB / regulated power supply

---

## Software Tools and Platforms

- Arduino IDE – ESP8266 programming
- Google Apps Script – Data logging to Google Sheets
- Google Sheets – Cloud data storage
- Google Colab – Machine learning and analysis
- ThingsBoard Cloud – Real-time visualization

---

## Project Folder Structure

``` smart-stress-monitoring-system/
├── codes/
│   ├── arduino/
│   ├── google sheets-appscript/
│   └── machine_learning/
│
├── results/
│   ├── anomaly_detection/
│   └── disorder_prediction/
│
├── project_report.pdf
└── README.md ```

---

## Arduino Implementation

This section contains the ESP8266 source code used to read EMG and GSR
sensor values.

The microcontroller:
- Reads analog EMG and GSR data
- Connects to Wi-Fi
- Sends data to Google Sheets using HTTP requests
- Enables real-time data transmission

---

## Google Sheets AppScript Integration

This section contains the Google Apps Script used for cloud data logging.

The script:
- Receives HTTP POST requests from ESP8266
- Extracts EMG and GSR values
- Appends data to Google Sheets
- Acts as a bridge between hardware and cloud storage

---

## Machine Learning Implementation

This section contains Jupyter notebooks used for:

- Fetching data from Google Sheets
- Data preprocessing and normalization
- Feature extraction
- Model training and evaluation

---

## Anomaly Detection

Anomaly detection is performed to identify abnormal stress patterns in
EMG and GSR signals.

Models used:
- Isolation Forest
- Autoencoder

These models learn normal physiological patterns and flag deviations
that indicate elevated stress.

---

## Disorder Prediction Results

This folder contains the results of stress-related disorder prediction
using machine learning on GSR and EMG sensor data.

The classification task was performed using an XGBoost model to
categorize individuals into different health conditions based on
physiological stress indicators.

---

## Health Condition Classification Criteria

The following threshold-based rules were used to label health
conditions using normalized sensor values:

Autism Spectrum Disorder (ASD)
- GSR > 0.6
- EMG > 0.6

Cognitive Impairment
- GSR > 0.5
- EMG < 0.5

Attention Deficit Hyperactivity Disorder (ADHD)
- GSR < 0.3
- EMG > 0.5

Normal Condition
- All other cases

---

## Performance Evaluation

The XGBoost model achieved strong classification performance.

- Overall accuracy: ~94.7%
- High precision and recall across classes
- Confusion matrix used for evaluation
- Minimal misclassification

Evaluation graphs are available in the results folder.

---

## Results Summary

The system demonstrates:
- Real-time IoT-based data acquisition
- Reliable cloud data storage
- Effective anomaly detection
- Accurate disorder classification
- Clear visualization of stress patterns

---

## Applications

- Mental health monitoring
- Stress analysis for individuals with communication difficulties
- Early detection of abnormal stress conditions
- Remote caregiver monitoring
- Academic and research use

---

## Future Scope

- Integration of additional biosignals (ECG, PPG)
- Wearable device deployment
- Real-time alert system
- Mobile or web application integration
- Edge-based machine learning

---

## Academic Information

This project was developed as part of the Bachelor of Technology (B.Tech)
in Internet of Things at Seshadri Rao Gudlavalleru Engineering College,
affiliated to JNTU Kakinada.

---

## Author

Lokesh Babu  
B.Tech – Internet of Things  
Seshadri Rao Gudlavalleru Engineering College  

