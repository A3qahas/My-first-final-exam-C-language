#include <stdio.h>
#include <string.h>
struct Option1 //Patient option
{
	int PatientID;
	char FullPatientName[100];
	char PhoneNum[15];
	char PreferredDocID[100];
};
struct Option2 // Doctor option
{
	int DoctorId;
	char DoctorFullName[100];
	char DoctorSpecialty[50];
	int NumAvApSl;
	char CPatientId[50];
};
#define SIZE6 20
int iFu[SIZE6];
int isStrictlyIncreasing(int arr[], int SIZE);
int main(void) {
	int Num, Pcount = 0, Dcounter = 0;
	struct Option1 Patientcounter[100];
	struct Option2 Doctorcounter[100];
	do {
		printf_s("%s\n%s\n%s\n%s\n%s\n%s\n%s\n"
			, "Choose one of the following options:"
			, "1 Add a new patient"
			, "2 Add a new doctor"
			, "3 Print all patients information"
			, "4 Print all doctors information"
			, "5 Quit"
			, "6 array analysis");
		scanf_s("%d", &Num);
		getchar();
		if (Num == 1) {
			printf_s("Patient ID: ");
			scanf_s("%d", &Patientcounter[Pcount].PatientID);
			getchar();
			printf_s("Patient Name: ");
			fgets(Patientcounter[Pcount].FullPatientName, sizeof(Patientcounter[Pcount].FullPatientName), stdin);
			Patientcounter[Pcount].FullPatientName[strcspn(Patientcounter[Pcount].FullPatientName, "\n")] = '\0';
			printf_s("Patient Phone number: ");
			fgets(Patientcounter[Pcount].PhoneNum, sizeof(Patientcounter[Pcount].PhoneNum), stdin);
			Patientcounter[Pcount].PhoneNum[strcspn(Patientcounter[Pcount].PhoneNum, "\n")] = '\0';
			printf_s("Patient Preferred doctor ID: (-1=NONE) ");
			fgets(Patientcounter[Pcount].PreferredDocID, sizeof(Patientcounter[Pcount].PreferredDocID), stdin);
			Patientcounter[Pcount].PreferredDocID[strcspn(Patientcounter[Pcount].PreferredDocID, "\n")] = '\0';
			if (strcmp(Patientcounter[Pcount].PreferredDocID, "-1") == 0) {
				strcpy_s(Patientcounter[Pcount].PreferredDocID, 100, "NONE");
			}
			Pcount++;
		}
		else if (Num == 2) {
			printf_s("Doctor ID: ");
			scanf_s("%d", &Doctorcounter[Dcounter].DoctorId);
			getchar();
			printf_s("Doctor full Name: ");
			fgets(Doctorcounter[Dcounter].DoctorFullName, sizeof(Doctorcounter[Dcounter].DoctorFullName), stdin);
			Doctorcounter[Dcounter].DoctorFullName[strcspn(Doctorcounter[Dcounter].DoctorFullName, "\n")] = '\0';
			printf_s("Doctor Specialty: ");
			fgets(Doctorcounter[Dcounter].DoctorSpecialty, sizeof(Doctorcounter[Dcounter].DoctorSpecialty), stdin);
			Doctorcounter[Dcounter].DoctorSpecialty[strcspn(Doctorcounter[Dcounter].DoctorSpecialty, "\n")] = '\0';
			printf_s("Number of available appointment slots: ");
			scanf_s("%d", &Doctorcounter[Dcounter].NumAvApSl);
			getchar();
			printf_s("Patient ID currently assigned: -1=NONE ): ");
			fgets(Doctorcounter[Dcounter].CPatientId, sizeof(Doctorcounter[Dcounter].CPatientId), stdin);
			Doctorcounter[Dcounter].CPatientId[strcspn(Doctorcounter[Dcounter].CPatientId, "\n")] = '\0';
			if (strcmp(Doctorcounter[Dcounter].CPatientId, "-1") == 0) {
				strcpy_s(Doctorcounter[Dcounter].CPatientId, 50, "NONE");
			}
			Dcounter++;
		}
		else if (Num == 3) {
			int i = 0;
			if (Pcount == 0) {
				printf_s("There is no patient\n");
			}
			else {
				printf_s("%-18s%-28s%-15s%-20s\n", "patient ID", "Name", "Phone", "Preferred Doctor");
				for (i; i < Pcount; i++) {
					printf_s("%-18d%-28s%-15s%-20s\n", Patientcounter[i].PatientID, Patientcounter[i].FullPatientName


						, Patientcounter[i].PhoneNum, Patientcounter[i].PreferredDocID);
				}
			}
		}
		else if (Num == 4) {
			int i = 0;
			if (Dcounter == 0) {
				printf_s("There is no doctor\n");
			}
			else {
				printf_s("%-12s%-28s%-20s%-20s%-20s\n", "Doctor ID", "Name", "Specialty", "Available slots", " Assigned Patient");
					for (i; i < Dcounter; i++) {
						printf_s("%-12d%-28s%-20s%-21d%-20s\n", Doctorcounter[i].DoctorId, Doctorcounter[i].DoctorFullName,
							Doctorcounter[i].DoctorSpecialty
							, Doctorcounter[i].NumAvApSl, Doctorcounter[i].CPatientId);
					}
			}
		}
		else if (Num == 6) {
			int NUM2, x, o;
			printf_s("Data Analysis Tools Menu:\n");
			do {
				printf_s("1 Cheack if a List of numbers is strictly increasing\n");
				printf_s("2 Back to main menu\n");
				scanf_s("%d", &NUM2);
				if (NUM2 == 1) {
					printf_s("Enter numbers of elements (Max 20): ");
					scanf_s("%d", &x);
					printf_s("Enter %d integer value", x);
					for (int j = 0; j < x; j++) {
						scanf_s("%d", &iFu[j]);
					}
					o = isStrictlyIncreasing(iFu, x);
					if (o == 0) {
						printf_s(" Strictly increasing \n");
					}
					else {
						printf_s(" Not strictly increasing \n");
					}
				}
			} while (NUM2 != 2);
		}
	} while (Num != 5);
	printf_s("End of program\n");
	return 0;
}
int isStrictlyIncreasing(int arr[], int SIZE) {
	int z, p;
	for (int j = 0; j < SIZE - 1; j++) {
		z = arr[j];
		if (z < arr[j + 1]) {
			p = 0;
		}
		else {
			p = 1;
		}
	}
	return p;
}