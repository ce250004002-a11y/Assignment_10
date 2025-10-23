#include <iostream>
#include <string>
using namespace std;

struct item{
    int id;
    string name;
    float cost;

    void show(item arr[], int size){
        cout<<"{";
        for( int i=0; i<size; i++){
            cout<<"(id : "<<arr[i].id<<", name : "<<arr[i].name<<", cost: "<<arr[i].cost<<"),"<<endl;
        }
        cout<<"}"<<endl;
    }

    double average_cost(item arr[], int size ){
        double average = 0;
        for (int i=0; i<size; i++){
            average+=arr[i].cost;
        }
        average = average/size;
        return average;
    }
};

int main(){
    
    item arr[8];
    for (int i=0; i<8; i++){
        cout<<"Enter the id: ";
        cin>>arr[i].id;
        cout<<"Enter the name: ";
        cin>>arr[i].name;
        cout<<"Enter the cost: ";
        cin>>arr[i].cost;
        cout<<endl;
    }

    for (int i=0; i<8; i++){
        for (int j=0; j<8-i-1; j++){
            if(arr[j].cost<arr[j+1].cost){
                //swap
                item temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    arr->show(arr,8);

    cout<<"Average cost of all the items is : "<<arr->average_cost(arr,8);
    

    
    return 0;
}
