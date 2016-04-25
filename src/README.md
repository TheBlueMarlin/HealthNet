# HealthNet
Small File IO based healthcare network to demonstrate Secure Software Development capabilities

# FILE IO

## ACCOUNT FUNCTIONS

void createAccount(char role, char *username, char *password) {
	creates new account
		char role
			1-Doctor
			2-Nurse
			3-Patient
			4-Staff Admin
		char *username
			// username of account
		char *password
			// password of account
}

void assignPatient(char *parent, char *patient) {
	assigns patient to a given doctor or nurse, generalized as "parent"
		char *parent
			// username of doctor or nurse
		char *patient
			// username of patient
}

void unassignPatient(/*refer to assignPatient()*/) {
	unassigns patient from a given doctor or nurse, generalized as "parent"
}

void viewAssignments(char *username) {
	prints list of patients assigned to given doctor or nurse
}

char getRole(char *username) {
	returns role of given user
}

char userExists(char *username) {
	returns 1 if true / 0 if false
}

void deleteAccount(char *username) {
	deletes account from system
}

## RECORD FUNCTIONS

void createRecord(char *username) {
	creates new record
}

void editRecordField(char *username, char field) {
	edits field within record
		char field
			1-name
			2-age
			3-height (inches)
			4-weight (pounds)
			etc...
}

void viewRecordField(/*refer to editRecordField()*/) {
	prints one field from record
}

void viewRecord(char *username) {
	prints all fields from record
}

void deleteRecord(char *username) {
	deletes entire record
}