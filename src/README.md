# HealthNet
Small File IO based healthcare network to demonstrate Secure Software Development capabilities

# FILE IO

## void readFile()
### unsigned int patientid
-id of desired patient record
### unsigned int fileType
-id of type of record
--1-inprocessing
--2-outprocessing
--3-immunizations
--4-medications
### unsigned int fileNumber
-number of record in order from 0

## void createFile()
### same params as void readFile()

## void deleteFile()
### same params as void readFile()

## void editFile()
### char *data
-data for writing to file
### same params as void readFile()

## void appendFile()
### same params as void editFile()

## void sendImmunizations()
### unsigned int patientid
#### refer to void readFile()

## void concatFilePath()
### char *filePath
-static memory address for holding the filePath
### same params as void readFile()

## void fileExists()
### char *filePath
#### refer to void concatFilePath()