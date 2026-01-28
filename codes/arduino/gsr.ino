#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

// WiFi credentials
const char* ssid = "Device"; 
const char* password = "1234567890"; 

// Google Apps Script URL (replace with your script's deployment URL)
const char* googleSheetsUrl = "https://script.google.com/macros/s/AKfycbyVW8WTF-Jo9CJQ6AqoEGttCrB9LeM2rAo2cfJg_trjvqj0Ec_Fgh7a15_GndJV-AdxNA/exec";

WiFiClientSecure clientGoogle;  // Secure client for Google Sheets
#define GSR_PIN A0  // Define GSR sensor pin

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi");

    clientGoogle.setInsecure(); // Trust all certificates
}

void sendGSRDataToGoogleSheets(int gsrValue) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        
        // Generate timestamp (in milliseconds since boot)
        unsigned long timestamp = millis();  

        String payload = "{\"sensorType\":\"GSR\",\"value\":" + String(gsrValue) + ",\"timestamp\":\"" + String(timestamp) + "\"}";

        Serial.println("Sending GSR data to Google Sheets: " + payload);
        http.begin(clientGoogle, googleSheetsUrl);
        http.addHeader("Content-Type", "application/json");

        int httpResponseCode = http.POST(payload);
        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println("Google Sheets Response: " + response);
        } else {
            Serial.print("Error sending GSR data: ");
            Serial.println(httpResponseCode);
        }
        http.end();
    } else {
        Serial.println("WiFi not connected for Google Sheets!");
    }
}

void loop() {
    int gsrValue = analogRead(GSR_PIN);
    Serial.print("GSR: ");
    Serial.println(gsrValue);

    sendGSRDataToGoogleSheets(gsrValue);
    delay(1000);  // Delay before next reading
}
