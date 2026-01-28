## Disorder Prediction Results

This folder contains the results of stress-related disorder prediction
using machine learning on GSR and EMG sensor data.

The classification task was performed using an XGBoost model to
categorize individuals into different health conditions based on
physiological stress indicators.

---

## Health Condition Classification Criteria

The following threshold-based rules were used to label health conditions
based on normalized GSR and EMG values:

| Health Condition           | GSR Threshold | EMG Threshold |
|----------------------------|---------------|---------------|
| ASD                        | GSR > 0.6     | EMG > 0.6     |
| Cognitive Impairment       | GSR > 0.5     | EMG < 0.5     |
| ADHD                       | GSR < 0.3     | EMG > 0.5     |
| Normal                     | All Other Cases | All Other Cases |

These thresholds help in mapping physiological patterns to
corresponding stress-related conditions.

---

## Model Performance Evaluation

The performance of the XGBoost classifier was evaluated using standard
classification metrics as shown below:

| Class                    | Precision | Recall | F1-Score |
|--------------------------|-----------|--------|----------|
| ADHD                     | 1.00      | 1.00   | 1.00     |
| ASD                      | 1.00      | 1.00   | 1.00     |
| Cognitive Impairment     | 0.96      | 0.96   | 0.96     |
| Normal                   | 0.90      | 0.90   | 0.90     |
| **Macro Average**        | **0.97**  | **0.97** | **0.97** |
| **Weighted Average**     | **0.95**  | **0.95** | **0.95** |

**Overall Accuracy:** **94.74%**

The results indicate strong classification performance with minimal
misclassification across all health conditions.

---

## Confusion Matrix

The confusion matrix below visualizes the classification performance of
the model, showing how well it differentiates between health conditions.


---

## Actual vs Predicted Classification

The table below compares actual and predicted health conditions for
individual data samples. The color-coded visualization highlights
correct classifications and confirms the consistency of the model’s
predictions.


---

## Key Observations

- The model achieved high precision and recall across all classes
- Very low misclassification was observed
- Strong agreement between actual and predicted labels
- Results validate the effectiveness of GSR and EMG signals for
  stress-related disorder prediction
- The system demonstrates strong potential for early diagnosis and
  mental health monitoring applications
