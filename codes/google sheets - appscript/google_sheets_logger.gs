function doPost(e) {
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getSheetByName("Sheet1");

  try {
    var data = JSON.parse(e.postData.contents);
    var timestamp = new Date();
    var lastRow = sheet.getLastRow();
    var lastTimestamp;

    // Check if there are any existing rows
    if (lastRow > 0) {
      lastTimestamp = sheet.getRange(lastRow, 1).getValue();

      // Check if the last timestamp is within a small time window (e.g., 5 seconds)
      if (lastTimestamp instanceof Date && (timestamp.getTime() - lastTimestamp.getTime()) < 5000) {
        // Update the existing row
        if (data.sensorType == "GSR") {
          sheet.getRange(lastRow, 2).setValue(data.value);
        } else if (data.sensorType == "EMG") {
          sheet.getRange(lastRow, 3).setValue(data.value);
        }
      } else {
        // Create a new row
        if (data.sensorType == "GSR") {
          sheet.appendRow([timestamp, data.value, ""]);
        } else if (data.sensorType == "EMG") {
          sheet.appendRow([timestamp, "", data.value]);
        }
      }
    } else {
      // If no rows exist, create a new one
      if (data.sensorType == "GSR") {
        sheet.appendRow([timestamp, data.value, ""]);
      } else if (data.sensorType == "EMG") {
        sheet.appendRow([timestamp, "", data.value]);
      }
    }

    return ContentService.createTextOutput("Data recorded successfully");

  } catch (error) {
    Logger.log("Error: " + error.toString());
    return ContentService.createTextOutput("Error processing data: " + error.toString());
  }
}