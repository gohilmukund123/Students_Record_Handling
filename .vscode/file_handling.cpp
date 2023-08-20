#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int ID;

struct Student{
    int id;
    string name;
    int age;
    string degree;
    int semesterNumber;
};

void addStudent(){
    Student student;
    cout<<"\nEnter the name of student: ";
    cin.get();
    getline(cin,student.name); // used getline function because cin directly cannot take name with white-spaces eg- Mukund Gohil
    cout<<"\nEnter the age of student: ";
    cin>>student.age;
    cout<<"\nEnter the degree of student: ";
    cin>>student.degree;
    cout<<"\nEnter the current semester number of student: ";
    cin>>student.semesterNumber;
    ID++;

    ofstream write;
    write.open("student.txt", ios::app);
    write << ID << "\n";
    write << student.name << "\n";
    write << student.age << "\n";
    write << student.degree << "\n";
    write << student.semesterNumber << "\n";
    write.close();
    write.open("id.txt");
    write<<ID;
    write.close();
    cout<<"\n\nDATA SAVED SUCCESSFULLY.\n\n";
}

void print(Student s){
    cout<<"\n------STUDENT'S DATA------";
    cout<<"\nID: "<<s.id;
    cout<<"\nName: "<<s.name;
    cout<<"\nAge: "<<s.age;
    cout<<"\nDegree: "<<s.degree;
    cout<<"\nSemester Number: "<<s.semesterNumber;
    cout<<endl;
}

void readData(){
    Student student;
    ifstream read;
    read.open("student.txt");
    read >> student.id;
    read.ignore(); // error handling
    getline(read,student.name); 
    read >> student.age;
    read >> student.degree;
    read >> student.semesterNumber;

    while (!read.eof()){
        print(student);
        read >> student.id;
        read.ignore();
        getline(read,student.name); 
        read >> student.age;
        read >> student.degree;
        read >> student.semesterNumber;
    }
    read.close();
}

int searchData(){
    int id;
    cout<<"\nEnter the ID of student that you want to search: ";
    cin>>id;
    Student student;
    ifstream read;
    read.open("student.txt");
    read >> student.id;
    read.ignore();
    getline(read,student.name); 
    read >> student.age;
    read >> student.degree;
    read >> student.semesterNumber;
    
    while(!read.eof()){
        if(student.id == id){
            print(student);
            cout<<endl;
            return id;
        }
        read >> student.id;
        read.ignore();
        getline(read,student.name); 
        read >> student.age;
        read >> student.degree;
        read >> student.semesterNumber;
    }
    return 0;
}

void deleteData(){
    int id = searchData();
    cout<<"\n\nDo you want to delete this record?\n (Press y for yes or n for no)";
    cout<<"\nWARNING: Deleted data cannot be recovered!!"<<endl;
    char choice;
    cin>>choice;
    if(choice == 'y'){
        Student student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("student.txt");
        read >> student.id;
        read.ignore();
        getline(read,student.name);
        read >> student.age;
        read >> student.degree;
        read >> student.semesterNumber;
        while (!read.eof()){
            if(student.id != id){
                tempFile << student.id << "\n";
                tempFile << student.name << "\n";
                tempFile << student.age << "\n";
                tempFile << student.degree << "\n";
                tempFile << student.semesterNumber << "\n";
            }
            read >> student.id;
            read.ignore();
            getline(read,student.name);
            read >> student.age;
            read >> student.degree;
            read >> student.semesterNumber;
        }
        read.close();
        tempFile.close();
        remove("student.txt");
        rename("temp.txt","student.txt");
        cout<<"\nData deleted successfully!"<<endl;
    }
    else{
        cout<<"Nothing is deleted!";
    }
}

void updateData(){
    int id = searchData();
    cout<<"\n\nDo you want to update this record?\n (Press y for yes or n for no)";
    char choice;
    cin>>choice;
    if(choice == 'y'){
        Student newData;
        cout<<"\nEnter the name of student: ";
        cin.get();
        getline(cin,newData.name);
        cout<<"\nEnter the age of student: ";
        cin>>newData.age;
        cout<<"\nEnter the degree of student: ";
        cin>>newData.degree;
        cout<<"\nEnter the current semester number of student: ";

        cin>>newData.semesterNumber;
        Student student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("student.txt");
        read >> student.id;
        read.ignore();
        getline(read,student.name);
        read >> student.age;
        read >> student.degree;
        read >> student.semesterNumber;
        while (!read.eof()){
            if(student.id != id){
                tempFile << student.id << "\n";
                tempFile << student.name << "\n";
                tempFile << student.age << "\n";
                tempFile << student.degree << "\n";
                tempFile << student.semesterNumber << "\n";
            }
            else{
                tempFile << id << "\n";
                tempFile << newData.name << "\n";
                tempFile << newData.age << "\n";
                tempFile << newData.degree << "\n";
                tempFile << newData.semesterNumber << "\n";
            }
            read >> student.id;
            read.ignore();
            getline(read,student.name);
            read >> student.age;
            read >> student.degree;
            read >> student.semesterNumber;
        }
        read.close();
        tempFile.close();
        remove("student.txt");
        rename("temp.txt","student.txt");
        cout<<"\nData updated successfully!"<<endl;
    }
    else{
        cout<<"Nothing is updated!";
    }
}

int main(){
    ifstream read;
    read.open("id.txt");
    if(!read.fail()){
        read >> ID;
    }
    else{
        ID = 0;
    }
    read.close();

    while(true){
        cout<<"\n1. Add student's data.";
        cout<<"\n2. Show student's data.";
        cout<<"\n3. Search a student's data.";
        cout<<"\n4. Delete a student's data.";
        cout<<"\n5. Update student's data.";
        cout<<"\n6. Exit";
        cout<<"\nEnter a choice of operation number: ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                addStudent();
                break;
            case 2:
                readData();
                break;
            case 3:
                searchData();
                break;
            case 4:
                deleteData();
                break;
            case 5:
                updateData();
                break;
            case 6:
                return 0;
            default:
                cout<<"\nEnter a valid operation number.";
        }
    }
}