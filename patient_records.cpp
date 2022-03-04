/* Hospital - Patients record Management system
PROBLEM: 

Patients record should contain 
1)Name of the patient
2)Token number
3)Disease
4)Doctor 

PROBLEMS:
1)INSERT PATIENT RECORD
2)DELETE PATIENT RECORD
3)DISPLAY THE PATIENT RECORD
4)SEARCH PATIENT RECORD


*/

#include<iostream>
using namespace std;

class Node {
public:
    int patient_id;
    string Name;
    string disease;
    string doctor;
    
    Node* next;
};
Node* head = new Node();
 
bool check(int x)
{
    if (head == NULL)
        return false;
    Node* t = new Node;
    t = head;
    while (t != NULL)
     {
        if (t->patient_id == x)
            return true;
        t = t->next;
    }
    return false;
}
 
void Insert_Record(int patient_id, string Name,string disease, string doctor)
{
    if (check(patient_id)) 
    {
        cout << "Patient with this record Already Exists\n";
        return;
    }
    Node* t = new Node();
    t->patient_id = patient_id;
    t->Name = Name;
    t->disease = disease;
    t->doctor = doctor;
    t->next = NULL;
    if (head == NULL || (head->patient_id >= t->patient_id))
     {
        t->next = head;
        head = t;
    }
 
    else {
        Node* p = head;
        while (p->next != NULL && p->next->patient_id < t->patient_id) 
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
    cout<<"\nSUCCESS!";
    cout << "\nThe patient record was inserted successfully\n";
}
 
void Search_Record(int patient_id)
{
    if (head==NULL) 
    {
        cout << "Record is not available";
        return;
    }
    else if(head!=NULL) 
    {
        Node* p = head;
        while (p!=NULL)
         {
            if (p->patient_id == patient_id)
             {
                cout << "PATIENT ID NUMBER : \t" << p->patient_id << endl;
                cout << "NAME OF THE PATIENT : \t"<< p->Name << endl;
                cout << "DISEASE : \t" << p->disease << endl;
                cout << "DOCTOR NAME : \t\t"<< p->doctor << endl;
                return;
            }
            p = p->next;
        }
 
        if (p == NULL)
            cout << "This patient info is not available \n";
    }
}
 

int Delete_Record(int patient_id)
{
    Node* t = head;
    Node* p = NULL;
 
    if (t != NULL && t->patient_id == patient_id)
     {
        head = t->next;
        delete t;
 
        cout << "The patient record deleted successfully\n";
        return 0;
     }

    while (t != NULL && t->patient_id != patient_id) 
    {
        p = t;
        t = t->next;
    }
    if (t == NULL) 
    {
        cout << "Record does not Exist\n";
        return -1;
        p->next = t->next;
        delete t;
        cout << "The patient record deleted successfully\n";
        return 0;
    }
}
 

void Display_Record()
{
    Node* p = head;
    if (p == NULL) {
        cout << "No Record Available\n";
    }
    else {
        cout << "PATIENT ID \t PATIENT NAME \t DISEASE \t DOCTOR TREATED \n";
        while (p != NULL) 
        {
            cout << p->patient_id<< "    \t\t"
                 << p->Name << "\t\t"
                 << p->disease << "\t\t"
                 << p->doctor << endl;
            p = p->next;
        }
    }
}
 

int main()
{
    head = NULL;
    string Name, disease, doctor;
    int patient_id;
 
    while (true)
     {
        cout << "\n\t\tWELCOME TO PATIENT RECORD MANAGEMENT SYSTEM \n\t\t LINKED-LIST IMPLEMENTATION \n\n\t Press"
         "\n\t  1 to create a new Record""\n\t  2 to delete a "
                "patient's record\n\t  3 to Search a Patient "
                "Record\n\t  4 to view all patients "
                "record\n\t  5 to Exit\n";
        cout << "\nEnter your Choice\n";
        int Choice;
 
 
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter Name of Patient\n";
            cin >> Name;
            cout << "Enter id Number of patient\n";
            cin >> patient_id;
            cout << "Enter disease that the patient is suffering from \n";
            cin >> disease;
            cout << "Enter the doctor name who treated the patient \n";
            cin >> doctor;
            Insert_Record(patient_id, Name, disease, doctor);
        }
        else if (Choice == 2) {
            cout << "Enter the ID of the Patient whose record is to be deleted\n";
            cin >> patient_id;
            Delete_Record(patient_id);
        }
        else if (Choice == 3) {
            cout << "Enter the ID of the patient whose record you want to Search\n";
            cin >> patient_id;
            Search_Record(patient_id);
        }
        else if (Choice == 4) {
            Display_Record();
        }
        else if (Choice == 5) {
            return 0;
        }
        else {
            cout << "Invalid Choice : Try Again\n";
        }
    }
    return 0;
}

