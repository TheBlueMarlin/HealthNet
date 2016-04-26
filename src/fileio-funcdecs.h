#define SIZEOF_PATIENTID 3
#define SIZEOF_FILENUMBER 2

/*
 * char patientid[3], unique ID of patient
 * char fileType,
 *     1-inprocessing
 *     2-outprocessing
 *     3-immunizations
 *     4-medications
 * char fileNumber, number of file in database
 */
void readFile(char patientid[SIZEOF_PATIENTID],char fileType,char fileNumber[SIZEOF_FILENUMBER]);
void createFile(char patientid[SIZEOF_PATIENTID],char fileType,char fileNumber[SIZEOF_FILENUMBER]);
void deleteFile(char patientid[SIZEOF_PATIENTID],char fileType,char fileNumber[SIZEOF_FILENUMBER]);

void sendImmmunizations(char patientid[SIZEOF_PATIENTID]); // moves immunizations files to immunizationClinic directory

// helper function(s)
void concatFilePath(char *filePath,char patientid[SIZEOF_PATIENTID],char fileType,char fileNumber[SIZEOF_FILENUMBER]);