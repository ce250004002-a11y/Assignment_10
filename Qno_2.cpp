
#include <iostream>
#include <string>
using namespace std;

struct Marks{
    float maths, science, english;
    
    float average(){
        return (maths + science + english)/3.0f;
    }
};

struct students{
    int rollno;
    string name;
    Marks marks;
    float average;
};

void show(students arr[], int size){
       for (int i=0; i<size; i++){
            for (int j=0; j<size-i-1; j++){
                if(arr[j].average>arr[j+1].average){
                    //swap
                    students temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        cout<<"\n------------Student Analysis------------------\n";
        cout<<"Student with the lowest average mark is : "<<arr[0].name<<"Average marks :"<<arr[0].average<<endl;
        cout<<"Student with the highest average mark is : "<<arr[size-1].name<<"Average marks :"<<arr[size-1].average<<endl;
    }  

int main() {
    
    students arr[5];
    for(int i=0; i<5; i++){
        cout<<"Enter the rollno : ";
        cin>>arr[i].rollno;
        cout<<"Enter the name: ";
        cin>>arr[i].name;
        cout<<"Enter the Marks of maths: ";
        cin>>arr[i].marks.maths;
        cout<<"Enter the Marks of science: ";
        cin>>arr[i].marks.science;
        cout<<"Enter the Marks of english: ";
        cin>>arr[i].marks.english;
        arr[i].average = arr[i].marks.average();
        cout<<endl;
    }
    show(arr,5);
    return 0;
}
