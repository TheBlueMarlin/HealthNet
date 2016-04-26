/*
 * unsigned int patientid, unique ID of patient
 * unsigned int fileType,
 *     1-inprocessing
 *     2-outprocessing
 *     3-immunizations
 *     4-medications
 * unsigned int fileNumber, number of file in database
 */
void readFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber);
void createFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber);
void deleteFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber);

/*
 * char *data
 *     data to be written to file
 */
void editFile(char *data,unsigned int patientid,unsigned int fileType,unsigned int fileNumber);
void appendFile(char *data,unsigned int patientid,unsigned int fileType,unsigned int fileNumber);

void sendImmmunizations(unsigned int patientid); // moves immunizations files to immunizationClinic directory

// helper function(s)
void concatFilePath(char *filePath,unsigned int patientid,unsigned int fileType,unsigned int fileNumber); // combines params to generate filePath
char fileExists(char *filePath); // returns 1 if file exists