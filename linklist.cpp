#include <iostream>
#include <cmath>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <set>
#include <algorithm>
using namespace std;

//________________________________Structures_____________________

struct student
{
    // int data;
    // struct node * ptr;

    string names;
    string rollno;
    string course;
    string classes;
    string contacts;

    student *next;
};

student *head = NULL;

student *findlast()
{
    student *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

void addinlist(string n, string r, string cl, string cou, string con)
{
    student *record = new student;
    record->names = n;
    record->rollno = r;
    record->classes = cl;
    record->course = cou;
    record->contacts = con;
    record->next = NULL;

    if (head == NULL)
    {
        head = record;
    }
    else
    {
        student *temp = findlast();
        temp->next = record;
    }
}

bool printvalue(student *record)
{

                 // cout << record->names << " " << record->rollno << " " << record->course << " " << record->classes << " " << record->contacts << endl;
    // student *temp = head;
    // while (temp != NULL)
    // {
    //     if (temp = temp->next)
    //     {
            cout << "Student name: " << record->names << endl;
            cout << "Student rollno: " << record->rollno << endl;
            cout << "Student course: " << record->course << endl;
            cout << "Student class: " << record->classes << endl;
            cout << "Student contact: " << record->contacts << endl;
    //     }
    //     else if (temp == NULL)
    //     {
    //         cout << "plz enter data." << endl;
    //     }
    // }
}

void printAll()
{
    student *temp = head;
    while (temp != NULL)
    {
        printvalue(temp);
        temp = temp->next;
    }
}

bool search(string name)
{
    student *temp = head;
    while (temp != NULL)
    {
        if (name == temp->names)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool deleteRecord(string name)
{
    student *temp = head;
    student *prev = head;
    while (temp != NULL)
    {
        if (temp->names == name && head->names == name)
        {
            head = temp->next;
            delete temp;
            return 1;
        }
        else if (temp->names == name)
        {
            prev->next = temp->next;
            delete temp;
            return 1;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return 0;
}

string parseData(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount++;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

void loadData()
{
    fstream fileVariable;
    fileVariable.open("student.txt", ios::app);
    string record;
    while (!(fileVariable.eof()))
    {
        getline(fileVariable, record);
        string names = parseData(record, 1);
        string rollno = parseData(record, 2);
        string course = parseData(record, 3);
        string classes = parseData(record, 4);
        string contacts = parseData(record, 5);

        addinlist(names, rollno, course, classes, contacts);
    }
    fileVariable.close();
}

void save_student()
{
    fstream file;
    //    Student_Count();
    student *student_record = head;

    file.open("student.txt", ios::out);
    while (student_record != NULL)
    {
        file << student_record->names << "," << student_record->rollno << "," << student_record->course << "," << student_record->classes << "," << student_record->contacts << "," << endl;
        student_record = student_record->next;
    }

    file.close();
}

void sort()
{
    student *current = head;
    student *nextCurrent = current->next;
    while (current != NULL)
    {
        nextCurrent = current->next;
        while (nextCurrent != NULL)
        {
            if (current->rollno > nextCurrent->rollno)
            {
                string temp1 = current->names;
                string temp2 = current->rollno;
                string temp3 = current->course;
                string temp4 = current->classes;
                string temp5 = current->contacts;

                current->names = nextCurrent->names;
                current->rollno = nextCurrent->rollno;
                current->course = nextCurrent->course;
                current->classes = nextCurrent->classes;
                current->contacts = nextCurrent->contacts;

                nextCurrent->names = temp1;
                nextCurrent->rollno = temp2;
                nextCurrent->course = temp3;
                nextCurrent->classes = temp4;
                nextCurrent->contacts = temp5;
            }
            nextCurrent = nextCurrent->next;
        }
        current = current->next;
    }
}
// void read_student_record()
// {
//  	ifstream fin;
//  	char ch;
//  	fin.open("student.txt");
// 	fin.get(ch);
//  	while(!fin.eof())
//  	{

//  		if(ch==',')
//  		{
//  			cout<<"  ";
//  		}
//  		else
//  		{
//  			cout << ch;
//  		}
//  		fin.get(ch);

        
//  	}
//  	fin.close();
//  	char input;
//  	int xy;
//  	xy:

//  	cout<<"\nDo you want to sort the record : (y/n)";
//      cin >> input;

//  	if(input=='y')
//  	{
//  		cout<<"\n_______________Sorted Record_______________\n";
//  		//sort_student_record(student);
//  	}
//      else if(input=='n')
//  	{

//  	}
//      else
//      {
//  		cout<<"Enter a vaild input option \n";
//  		goto xy;
//  	}
// }


//#######################################################################################################################

struct staff
{
    string name;
    string address;
    string salary;
    string contact;

    staff *next;
};

staff *Head = NULL;

staff *Findlast()
{
    staff *temp = Head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

void Addinlist(string n, string a, string sl, string con)
{
    staff *record = new staff;
    record->name = n;
    record->address = a;
    record->salary = sl;
    record->contact = con;
    record->next = NULL;

    if (Head == NULL)
    {
        Head = record;
    }
    else
    {
        staff *temp = Findlast();
        temp->next = record;
    }
}

bool Printvalue(staff *record)
{

    // cout << record->names << " " << record->rollno << " " << record->course << " " << record->classes << " " << record->contacts << endl;
    // staff *temp = Head;
    // while (temp != NULL)
    // {
    //     if (temp = temp->next)
    //     {
            cout << "Staff name: " << record->name << endl;
            cout << "Staff address: " << record->address << endl;
            cout << "Staff salary: " << record->salary << endl;
            cout << "Staff contact: " << record->contact << endl;
    //     }
    //     else if (temp == NULL)
    //     {
    //         cout << "plz enter data." << endl;
    //     }
    // }
}

void PrintAll()
{
    staff *temp = Head;
    while (temp != NULL)
    {
        Printvalue(temp);
        temp = temp->next;
    }
}

bool Search(string name)
{
    staff *temp = Head;
    while (temp != NULL)
    {
        if (name == temp->name)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool DeleteRecord(string name)
{
    staff *temp = Head;
    staff *prev = Head;
    while (temp != NULL)
    {
        if (temp->name == name && Head->name == name)
        {
            Head = temp->next;
            delete temp;
            return 1;
        }
        else if (temp->name == name)
        {
            prev->next = temp->next;
            delete temp;
            return 1;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return 0;
}

string ParseData(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount++;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

void LoadData()
{
    fstream fileVariable;
    fileVariable.open("staff.txt", ios::app);
    string record;
    while (!(fileVariable.eof()))
    {
        getline(fileVariable, record);
        string name = parseData(record, 1);
        string address = parseData(record, 2);
        string salary = parseData(record, 3);
        string contact = parseData(record, 4);

        Addinlist(name, address, salary, contact);
    }
    fileVariable.close();
}

void save_staff()
{
    fstream file;
    //    Student_Count();
    staff *staff_record = Head;

    file.open("staff.txt", ios::out);
    while (staff_record != NULL)
    {
        file << staff_record->name << "," << staff_record->address << "," << staff_record->salary << "," << staff_record->contact << "," << endl;
        staff_record = staff_record->next;
    }

    file.close();
}

void Sort()
{
    staff *current = Head;
    staff *nextCurrent = current->next;
    while (current != NULL)
    {
        nextCurrent = current->next;
        while (nextCurrent != NULL)
        {
            if (current->name > nextCurrent->name)
            {
                string temp1 = current->name;
                string temp2 = current->address;
                string temp3 = current->salary;
                string temp4 = current->contact;

                current->name = nextCurrent->name;
                current->address = nextCurrent->address;
                current->salary = nextCurrent->salary;
                current->contact = nextCurrent->contact;

                nextCurrent->name = temp1;
                nextCurrent->address = temp2;
                nextCurrent->salary = temp3;
                nextCurrent->contact = temp4;
            }
            nextCurrent = nextCurrent->next;
        }
        current = current->next;
    }
}

// struct sortstaffrecord
// {
//     string name1;
//     string address1;
//     string salary1;
//     string contact1;
// };

// struct sortstudentrecord
// {
//     string name2;
//     string rollno2;
//     string course2;
//     string classes2;
//     string contact2;
// };


//__________________________________LINK LIST________________________________

// struct node
// {
//     int data;
//     struct node * ptr;

//     string Names;
//     string Rollno;
//     string Course;
//     string Classes;
//     string Contacts;
// };

//_________________________________arrays ________________________

// string arr1[20], arr2[20], arr3[20], arr4[20], arr5[20];    // ARRAYS FOR STUDENTS.
// string arr6[20], arr7[20], arr8[20], arr9[20], arr10[20];    // ARRAYS FOR STAFF .

string sort_staff[50];
string sort_student[50];

//________________________________default values_________________

int total = 0;

//________________________________FUNCTIONS PROTOTYPES____________

void gotoxy(int x, int y);

// void enter(student s[]);            // FOR STUDENTS
void enter();
void addstaff();

// void show(student s[]);
// void search(student s[]);
// void update(student s[]);
// void deleterecord(student s[]);

void home();
void customer();
void admin();
void how();

// void addstaff(staff st[]);          // FOR STAFF
// void viewstaff(staff st[]);
// void updatestaff(staff st[]);
// void deletestaff(staff st[]);

void user();

// int convert(string n);
// void read_staff_record(sortstaffrecord staff[]);                //1
// void read_student_record(sortstudentrecord staff[]);            //2
// void sort_staff_record(sortstaffrecord staff[]);
// void sort_student_record(sortstudentrecord student[]);

// void Student_Count();
//  void save_student(string arr1[20], string arr2[20], string arr3[20], string arr4[20], string arr5[20]);

// void save_student(student s[]); // MUST ADD BY REFERENCE PARAMETER(student s[])
// void staff_count();
//  void save_Staff(string arr6[20], string arr7[20], string arr8[20], string arr9[20]);

// void save_Staff(staff st[]); // MUST ADD BY REFERENCE PARAMETER(staff st[])

// void student_count_load();

main()

{
    /*student s[5]; // student typr s variable.

    staff st[4]; // staff type st variable

    sortstaffrecord staff[4]; // structure for sort staff record

    sortstudentrecord student[5]; // structure for sort student record

    struct student *head;
    struct student *second;
    struct student *third;
    struct student *fourth;
    struct student *fifth;

    // Allocate memory of nodes in link list of heap
    head = (struct student *)malloc(sizeof(struct student));
    second = (struct student *)malloc(sizeof(struct student));
    third = (struct student *)malloc(sizeof(struct student));
    fourth = (struct student *)malloc(sizeof(struct student));
    fifth = (struct student *)malloc(sizeof(struct student));

    // list for first and second node

    */

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 6);

    system("cls");

    int value = 0;

    string n, r, cou, cl, con; // for student
    string N, A, SL, CON;      // for staff

    //loadData(); // load data from file.LINK LIST

   

    while (true)

    {

    start:

        home();
        how();

        char op;
        cout << "\nEnter Your Option: " << endl;
        cin >> op;

        if (op == '1')
        {
            system("cls");
            customer();

            cout << " \nPLZ ! Enter Your Option: ";

            cin >> value;

            if (value == 1) // enter data student
            {
                SetConsoleTextAttribute(hConsole, 6);
                system("cls");

                // enter(s);
                // addinlist(n,r,cou,cl,con);                       // addinlist.
                enter();
                // save_student(head);
                save_student();
            }
            else if (value == 2) // show
            {
                SetConsoleTextAttribute(hConsole, 12);

                system("cls");

                // read_student_record(student);  //<<<<<<<<<<<<<<<-------------------
                // show(s);

                printAll();
            }
            else if (value == 3) // search
            {
                SetConsoleTextAttribute(hConsole, 1);

                system("cls");

                // search(s);
                search(n);
            }
            //     else if (value == 4)        // update
            //     {
            //         SetConsoleTextAttribute(hConsole, 2);

            //         system("cls");

            //         update(s);
            //     }
            else if (value == 5) // delete
            {
                SetConsoleTextAttribute(hConsole, 3);

                system("cls");

                string n1;
                // deleterecord(s);
                cout << "Write name you want to delete : " << endl;
                cin >> n1;

                deleteRecord(n1);
                addinlist(n, r, cou, cl, con);
            }
            else if (value == 6)
            {
                // system("cls");
                //read_student_record();
                loadData();
                sort();
                printAll();
                
                // view record in merit order.

                // print_Recd(string arr6[]);
                //          read_student_record(student);
            }
            else if (value == 7)
            {
                SetConsoleTextAttribute(hConsole, 5);

                system("cls");

                goto start;
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 6);

                cout << "wrong input." << endl;

                system("cls");

                goto start;
            }
        }

        else if (op == '2')
        {
            system("cls");

            admin();

            cout << " \nPLZ ! Enter Your Option: ";

            cin >> value;

            if (value == 1)
            {

                SetConsoleTextAttribute(hConsole, 12);

                system("cls");

                // addstaff(st);
                addstaff();

                save_staff();
            }
            else if (value == 2)
            {
                SetConsoleTextAttribute(hConsole, 6);

                system("cls");

                // read_staff_record(staff);    //<<<<<<<<<<<<<<<<<<<<<<<-----------------------
                // viewstaff(st);
                PrintAll();
            }
            else if (value == 3)
            {
                SetConsoleTextAttribute(hConsole, 11);

                system("cls");

                // updatestaff(st);
            }
            else if (value == 4)
            {
                SetConsoleTextAttribute(hConsole, 10);

                system("cls");

                string n2;
                // deletestaff(st);
                cout << "Write name you want to delete : " << endl;
                cin >> n2;

                DeleteRecord(n2);
                Addinlist(N, A, SL, CON);
            }
            else if (value == 5)
            {
                SetConsoleTextAttribute(hConsole, 13);

                system("cls");

                //  merit order display karna ha
                // read_staff_record(staff); // staff >> st
                Sort();
                PrintAll();
            }
            else if (value == 6)
            {
                SetConsoleTextAttribute(hConsole, 6);

                system("cls");

                goto start;
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 6);

                cout << "wrong input." << endl;

                system("cls");

                goto start;
            }
        }

        // else if (op == '3')
        // {
        /* string password = "fatiq123";
         string userinput;

         cout << "Enter your Password: "<<endl;
         cin >> userinput;*/

        // while(userinput != password)
        // {
        //  cout << "password valid."<<endl;

        //         system("cls");

        //         user();

        //         cout << " \nPLZ ! Enter Your Option: ";

        //         cin >> value;

        //         if (value == 1)
        //         {
        //             SetConsoleTextAttribute(hConsole, 6);

        //             system("cls");

        //             show(s);                        // JUST VIEW STUDENTS(s)
        //         }
        //         else if (value == 2)
        //         {
        //             SetConsoleTextAttribute(hConsole, 12);

        //             system("cls");

        //             viewstaff(st);                  // JUST VIEW STAFF(st)
        //         }
        //         else if (value == 3)
        //         {
        //             SetConsoleTextAttribute(hConsole, 10);

        //             system("cls");

        //             goto start;
        //         }
        //         else
        //         {
        //             SetConsoleTextAttribute(hConsole, 13);

        //             cout << "wrong input."<<endl;

        //             system("cls");

        //             goto start;
        //         }
        //     }
        //     else if (op == '4')
        //     {
        //         SetConsoleTextAttribute(hConsole, 6);

        //         system("cls");

        //         exit(0);
        //     }
        //     else
        //     {
        //         SetConsoleTextAttribute(hConsole, 6);

        //         cout << "wrong input."<<endl;

        //         system("cls");

        //         goto start;
        //     }
    }
}

// void enter(student s[])
void enter()

{

    int ch = 0;

    cout << "How many students do u want to enter??" << endl;

    cin >> ch;

    string n, r, cl, cou, con;

    if (total == 0)

    {

        total = ch + total;

        for (int i = 0; i < ch; i++)

        {

            cout << "\nEnter the Data of student " << i + 1 << endl
                 << endl;

            cout << "Enter name ";

            // cin >> s[i].names;
            cin >> n;

            cout << "Enter Roll no ";

            // cin >> s[i].rollno;
            cin >> r;

            cout << "Enter course ";

            // cin >> s[i].course;
            cin >> cou;

            cout << "Enter class ";

            // cin >> s[i].classes;
            cin >> cl;

            cout << "Enter contact ";

            // cin >> s[i].contacts;
            cin >> con;
        }
    }

    else

    {

        for (int i = total; i < ch + total; i++)

        {

            cout << "\nEnter the Data of student " << i + 1 << endl
                 << endl;

            cout << "Enter name ";

            // cin >> s[i].names;
            cin >> n;

            cout << "Enter Roll no ";

            // cin >> s[i].rollno;
            cin >> r;

            cout << "Enter course ";

            // cin >> s[i].course;
            cin >> cou;

            cout << "Enter class ";

            // cin >> s[i].classes;
            cin >> cl;

            cout << "Enter contact ";

            // cin >> s[i].contacts;
            cin >> con;
        }

        total = ch + total;
    }
    // save_student(s);
    addinlist(n, r, cou, cl, con);
}

// void show(student s[])
//  void show()

// {

//     if (total == 0)

//     {

//         cout << "No data is entered" << endl;
//     }

//     else
//     {

//         for (int i = 0; i < total; i++)

//         {

//             cout << "\nData of Student " << i + 1 << endl
//                  << endl;

//             //cout << "Name " << s[i].names << endl;
//             cout << "Name " << s[i].names << endl;

//             cout << "Roll no " << s[i].rollno << endl;

//             cout << "Course " << s[i].course << endl;

//             cout << "Class " << s[i].classes << endl;

//             cout << "Contact " << s[i].contacts << endl;
//         }
//     }
// }

// void search(student s[])

// {

//     if (total == 0)

//     {

//         cout << "No data is entered" << endl;

//     }

//     else
//     {

//         string rollno;

//         cout << "Enter the roll no of student" << endl;

//         cin >> rollno;

//         for (int i = 0; i < total; i++)

//         {

//             if (rollno == s[i].rollno)

//             {

//                 cout << "Name " << s[i].names << endl;

//                 cout << "Roll no " << s[i].rollno << endl;

//                 cout << "Course " << s[i].course << endl;

//                 cout << "Class " << s[i].classes << endl;

//                 cout << "Contact " << s[i].contacts << endl;
//             }
//         }
//     }
// }

// void update(student s[])

// {

//     if (total == 0)

//     {
//         cout << "No data is entered" << endl;
//     }

//     else
//     {

//         string rollnou;

//         cout << "Enter the roll no of student which you want to update" << endl;

//         cin >> rollnou;

//         for (int i = 0; i < total; i++)

//         {

//             if (rollnou == s[i].rollno)

//             {

//                 cout << "\nPrevious data" << endl
//                      << endl;

//                 cout << "Data of Student " << i + 1 << endl;

//                 cout << "Name " << s[i].names << endl;

//                 cout << "Roll no " << s[i].rollno << endl;

//                 cout << "Course " << s[i].course << endl;

//                 cout << "Class " << s[i].classes << endl;

//                 cout << "Contact " << s[i].contacts << endl;

//                 cout << "\nEnter new data" << endl
//                      << endl;

//                 cout << "Enter name ";

//                 cin >> s[i].names;

//                 cout << "Enter Roll no ";

//                 cin >> s[i].rollno;

//                 cout << "Enter course ";

//                 cin >> s[i].course;

//                 cout << "Enter class ";

//                 cin >> s[i].classes;

//                 cout << "Enter contact ";

//                 cin >> s[i].contacts;
//             }
//         }
//     }
// }

// void deleterecord(student s[])

// {

//     if (total == 0)

//     {

//         cout << "No data is entered" << endl;
//     }

//     else
//     {

//         int a;

//         cout << "Press 1 to delete all record" << endl;

//         cout << "Press 2 to delete specific record" << endl;

//         cin >> a;

//         if (a == 1)

//         {

//             total = 0;

//             cout << "All record is deleted..!!" << endl;
//         }

//         else if (a == 2)

//         {

//             string rollno;

//             cout << "Enter the roll no of student which you wanted to delete" << endl;

//             cin >> rollno;

//             for (int i = 0; i < total; i++)

//             {

//                 if (rollno == s[i].rollno)

//                 {

//                     for (int j = i; j < total; j++)

//                     {

//                         s->names[j] = s->names[j + 1];

//                         s->rollno[j] = s->rollno[j + 1];

//                         s->course[j] = s->course[j + 1];

//                         s->classes[j] = s->classes[j + 1];

//                         s->contacts[j] = s->contacts[j + 1];
//                     }

//                     total--;

//                     cout << "Your required record is deleted" << endl;
//                 }
//             }
//         }

//         else

//         {

//             cout << "Invalid input";
//         }
//     }
// }

// //___________________________________________ADMIN SECTION_______________________________________________

// void addstaff(staff st[])
void addstaff()
{

    string n, a, sl, con;

    int staff = 0;

    cout << "How many staff members do u want to enter??" << endl;

    cin >> staff;

    if (total == 0)

    {

        total = staff + total;

        for (int i = 0; i < staff; i++)

        {

            cout << "\nEnter the Data of staff " << i + 1 << endl
                 << endl;

            cout << "Enter name: ";

            // cin >> st[i].name;
            cin >> n;

            cout << "Enter Address: ";

            // cin >> st[i].address;
            cin >> a;

            cout << "Enter salary: ";

            // cin >> st[i].salary;
            cin >> sl;

            cout << "Enter contact: ";

            // cin >> st[i].contact;
            cin >> con;
        }
    }

    else

    {

        for (int i = total; i < staff + total; i++)

        {

            cout << "\nEnter the Data of staff " << i + 1 << endl
                 << endl;

            cout << "Enter name ";

            // cin >> st[i].name;
            cin >> n;

            cout << "Enter Address: ";

            // cin >> st[i].address;
            cin >> a;

            cout << "Enter salary: ";

            // cin >> st[i].salary;
            cin >> sl;

            cout << "Enter contact: ";

            // cin >> st[i].contact;
            cin >> con;
        }

        total = staff + total;
    }
    // save_Staff(st);
    Addinlist(n, a, sl, con);
}

// void viewstaff(staff st[])
// {

//     if (total == 0)

//     {
//         cout << "No data is entered" << endl;
//     }

//     else
//     {

//         for (int i = 0; i < total; i++)

//         {

//             cout << "\nData of STAFF " << i + 1 << endl
//                  << endl;

//             cout << "Name " << st[i].name << endl;

//             cout << "Address " << st[i].address << endl;

//             cout << "Salary " << st[i].salary << endl;

//             cout << "Contact " << st[i].contact << endl;
//         }
//     }
// }

// void updatestaff(staff st[])
// {
//      if (total == 0)

//     {

//         cout << "No data is entered" << endl;
//     }

//     else
//     {

//         string name;

//         cout << "Enter the name of staff mamber which you want to update: " << endl;

//         cin >> name;

//         for (int i = 0; i < total; i++)

//         {

//             if (name == st[i].name)

//             {

//                 cout << "\nPrevious data" << endl
//                      << endl;

//                 cout << "Data of Staff " << i + 1 << endl;

//                 cout << "Name " << st[i].name << endl;

//                 cout << "Address " << st[i].address << endl;

//                 cout << "Salary " << st[i].salary << endl;

//                 cout << "Contact " << st[i].contact << endl;

//                 cout << "\nEnter new data" << endl
//                      << endl;

//                 cout << "Enter name: ";

//                 cin >> st[i].name;

//                 cout << "Enter Address: ";

//                 cin >> st[i].address;

//                 cout << "Enter Salary: ";

//                 cin >> st[i].salary;

//                 cout << "Enter contact: ";

//                 cin >> st[i].contact;
//             }
//         }
//     }
// }

// void deletestaff(staff st[])
// {
//     if (total == 0)

//     {

//         cout << "No data is entered" << endl;
//     }

//     else
//     {

//         int a;

//         cout << "Press 1 to delete all record of staff" << endl;

//         cout << "Press 2 to delete specific record of staff" << endl;

//         cin >> a;

//         if (a == 1)

//         {

//             total = 0;

//             cout << "All record of staff is deleted..!!" << endl;
//         }

//         else if (a == 2)

//         {

//             string name;

//             cout << "Enter the name of staff member which you wanted to delete" << endl;

//             cin >> name;

//             for (int i = 0; i < total; i++)

//             {

//                 if (name == st[i].name)

//                 {

//                     for (int j = i; j < total; j++)

//                     {

//                         st->name[j] = st->name[j + 1];

//                         st->address[j] = st->address[j + 1];

//                         st->salary[j] = st->salary[j + 1];

//                         st->contact[j] = st->contact[j + 1];
//                     }

//                     total--;

//                     cout << "Your required record of staff member is deleted" << endl;
//                 }
//             }
//         }

//         else

//         {

//             cout << "Invalid input";
//         }
//     }
// }
//____________________________________________________Customer________________________________

/*void viewstaff()
{

    if (total == 0)

    {

        cout << "No data is entered" << endl;
    }

    else
    {

        for (int i = 0; i < total; i++)

        {

            cout << "\nData of STAFF " << i + 1 << endl
                 << endl;

            cout << "Name " << arr6[i] << endl;

            cout << "Address " << arr7[i] << endl;

            cout << "Salary " << arr8[i] << endl;

            cout << "Contact " << arr9[i] << endl;
        }
    }
}
void show()

{

    if (total == 0)

    {

        cout << "No data is entered" << endl;
    }

    else
    {

        for (int i = 0; i < total; i++)

        {

            cout << "\nData of Student " << i + 1 << endl
                 << endl;

            cout << "Name " << arr1[i] << endl;

            cout << "Roll no " << arr2[i] << endl;

            cout << "Course " << arr3[i] << endl;

            cout << "Class " << arr4[i] << endl;

            cout << "Contact " << arr5[i] << endl;
        }
    }
}*/
//__________________________________________________SORTING_____________________________________

/*void print_Recd(string arr6[])
{
    //_-------------Function of view student In Sorted order
    int temp;

    for (int i = 0; i < total; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            if (arr6[i] > 0)
            {
                if (arr6[j] > arr6[i])
                {
                    temp = arr6[i];
                    arr6[i] = arr6[j];
                    arr6[j] = temp;
                }
            }
        }
    }
}*/

//____________________________________________________OTHER FUNCTIONS___________________________
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void home()
{
    cout << "************************************" << endl;
    cout << "*     SCHOOL MANAGEMENT SYSTEM     *" << endl;
    cout << "************************************" << endl;
}

void customer()
{

    cout << "\n 1. Enter data." << endl;

    cout << " 2. Show data." << endl;

    cout << " 3. Search data." << endl;

    cout << " 4. Update data." << endl;

    cout << " 5. Delete data." << endl;

    cout << " 6. View Record in Merit Order. " << endl;

    cout << " 7. Exit" << endl;
}

void admin()
{
    cout << "1.Add Staff." << endl;

    cout << "2.View Staff." << endl;

    cout << "3.Update staff." << endl;

    cout << "4.Delete Staff" << endl;

    cout << "5.View Staff In Merit Order." << endl;

    cout << "6.Exit." << endl;
}

void user()
{
    cout << "1.View Students." << endl;

    cout << "2.View Staff." << endl;

    cout << "3.Exit." << endl;
}

void how()
{
    cout << "\nHOW IS USING SYSTEM ?\n"
         << endl;

    cout << "1.Customer." << endl;

    cout << "2.Admin." << endl;

    cout << "3.User." << endl;

    cout << "4.Exit." << endl;
}

//         //void save_student(string arr1[20], string arr2[20], string arr3[20], string arr4[20], string arr5[20])
// void save_student()
// {
//     fstream file;
//                     //    Student_Count();
//     file.open("student.txt", ios::app);
//     for (int i = 0; i < total ; i++)
//     {
//         file << s[i].names << "," << s[i].rollno << "," << s[i].course << "," << s[i].classes << "," << s[i].contacts <<","<< endl;
//     }
//     file.close();
// }

// void read_student_record()
// {
// 	ifstream fin;
// 	char ch;
// 	fin.open("student.txt");
// 	fin.get(ch);
// 	while(!fin.eof())
// 	{

// 		if(ch==',')
// 		{
// 			cout<<"  ";
// 		}
// 		else
// 		{
// 			cout << ch;
// 		}
// 		fin.get(ch);
// 	}
// 	fin.close();
// 	char input;
// 	int xy;
// 	xy:

// 	cout<<"\nDo you want to sort the record : (y/n)";
//     cin >> input;

// 	if(input=='y')
// 	{
// 		cout<<"\n_______________Sorted Record_______________\n";
// 		//sort_student_record(student);
// 	}
//     else if(input=='n')
// 	{

// 	}
//     else
//     {
// 		cout<<"Enter a vaild input option \n";
// 		goto xy;
// 	}
// }