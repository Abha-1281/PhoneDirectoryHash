//Phone Directory using hashing

#include <iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

class node{
    string name;
    int id;
    long int tel;
    friend class hashing;
public:
    node(){
        id=0;
        tel=0;
    }
};

class hashing{
    node data[100];
    int index;
public:

    void create_record(int size, string n, int i, long int t){
        index=i%size;
        for(int j=0;j<size;j++){
            if(data[index].id==0){
                data[index].name=n;
                data[index].id=i;
                data[index].tel=t;
                break;
            }
            else{
                index=(index+1)%size;
            }
        }
        cout<<"Record Successfully created "<<endl;

    }

    void delete_record(int size, int i){
        int flag=0;
        index=i%size;
        for(int j=0;j<size;j++){
            if(i==data[index].id){
                    flag=1;
                data[index].id=0;
                data[index].name="";
                data[index].tel=0;
                cout<<"Record Deleted Successfully "<<endl;
                break;
            }
            else{
                index=(index+1)%size;
            }
        }
        if(flag==0)
            cout<<"Data not found "<<endl;
    }


    void modify_record(int size, int old_id, string n, int new_id, long int t ){
        index=old_id%size;
        int flag=0;
        for(int j=0;j<size;j++){
            if(old_id==data[index].id){
                    flag=1;
                data[index].id=new_id;
                data[index].name=n;
                data[index].tel=t;
                cout<<"Record Updated Successfully "<<endl;
                break;
            }
            else{
                index=(index+1)%size;
            }
        }
        if(flag==0)
            cout<<"Data not found "<<endl;

    }


    void search(int size)
    {
        int index1, key, flag = 0;

        cout << "  Enter id to search : ";
        cin >> key;
        index1 = key % size;

        for (int i = 0; i < size; i++) {
            if (data[index1].id == key) {
                flag = 1;
                cout << "\nRecord found:";
                cout << "\n\tID ";
                cout << "\tNAME ";
                cout << "\tTELEPHONE ";
                cout << "\n\t"
                     << data[index1].id
                     << " \t"
                     << data[index1].name
                     << " \t"
                     << data[index1].tel;
                break;
            }
            else
                index1
                    = (index1 + 1) % size;
        }
        if (flag == 0)
            cout << "\nRecord not found";
    }

    void display(int size)
    {
        cout << "\n\tID \tNAME";
        cout << " \tTELEPHONE ";

        for (int i = 0; i < size; i++) {
            if (data[i].id != 0) {
                cout << "\n\t"
                     << data[i].id
                     << " \t"
                     << data[i].name
                     << " \t"
                     << data[i].tel;
            }
        }
    }

};

int main()
{
    int ch;
    int size=10;
    string n;
    int i;
    long int t;
    hashing h;

    while(1){
        cout<<"\n\n";
        cout << "PHONE DIRECTORY " << endl;
        cout<<"\n\n";
        cout<<"1. Create Directory"<<endl;
        cout<<"2. Delete Directory"<<endl;
        cout<<"3. Modify Directory"<<endl;
        cout<<"4. Search Directory"<<endl;
        cout<<"5. Display Director"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choise "<<endl;
        cin>>ch;

        switch(ch){
            case 1:{
                    cout<<"\n\n";
                    cout<<"Enter your name: "<<endl;
                    cin>>n;
                    cout<<"Enter your id: "<<endl;
                    cin>>i;
                    cout<<"Enter telephone number: "<<endl;
                    cin>>t;
                    h.create_record(size,n,i,t);
                    break;
            }

            case 2:{
                    cout<<"\n\n";
                    cout<<"Enter the id you want to delete: "<<endl;
                    cin>>i;
                    h.delete_record(size, i);
                    break;
            }

            case 3:{
                    int old_id,new_id;
                    cout<<"\n\n";
                    cout<<"Enter the id you want to modify: "<<endl;
                    cin>>old_id;
                    cout<<"Enter your name: ";
                    cin>>n;
                    cout<<"Enter your new id: ";
                    cin>>new_id;
                    cout<<"Enter your telephone number: ";
                    cin>>t;
                    h.modify_record(size, old_id, n, new_id,t);
                    break;

            }

            case 4:{
                    h.search(size);
                    break;
            }

            case 5:{
                    h.display(size);
                    break;

            }

            case 6: exit(0);
                    break;

            default:
                cout<<"\nWRONG CHOICE";


        }

    };

    return 0;
}
