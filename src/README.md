# HealthNet
Small File IO based healthcare network to demonstrate Secure Software Development capabilities

# FILE IO

## void readFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
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

## void createFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
### same params as void readFile()

## void deleteFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
### same params as void readFile()

## void editFile(char *data,unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
### char *data
-data for writing to file
### same params as void readFile()

## void appendFile(char *data,unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
### same params as void editFile()

## void sendImmmunizations(unsigned int patientid)
### unsigned int patientid
#### refer to void readFile()

## void concatFilePath(char *filePath,unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
### char *filePath
-static memory address for holding the filePath
### same params as void readFile()

## char fileExists(char *filePath)
### char *filePath
#### refer to void concatFilePath()