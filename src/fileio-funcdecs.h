#define SIZEOF_USERNAME 8
#define SIZEOF_PASSWORD 8

// account functions
void createAccount(char role, char username[SIZEOF_USERNAME], char password[SIZEOF_PASSWORD]);
void assignPatient(char parent[SIZEOF_USERNAME], char patient[SIZEOF_USERNAME]);
void unassignPatient(char parent[SIZEOF_USERNAME], char patient[SIZEOF_USERNAME]);
void viewAssignments(char username[SIZEOF_USERNAME]);
char getRole(char username[SIZEOF_USERNAME]);
char userExists(char username[SIZEOF_USERNAME]);
void deleteAccount(char username[SIZEOF_USERNAME]);

// record functions
void createRecord(char username[SIZEOF_USERNAME]);
void editRecordField(char username[SIZEOF_USERNAME], char field);
void viewRecordField(char username[SIZEOF_USERNAME], char field);
void viewRecord(char username[SIZEOF_USERNAME]);
void deleteRecord(char username[SIZEOF_USERNAME]);