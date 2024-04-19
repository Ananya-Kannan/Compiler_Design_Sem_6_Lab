#include <iostream>
using namespace std;
int main(){
    int c, num1, num2;
    cout<<"Menu"<<endl;
    cout<<"1. Add"<<endl;
    cout<<"2. Subtract"<<endl;
    cout<<"3. Multiply"<<endl;
    cout<<"4.Divide"<<endl;
    cout<<"5. Exit"<<endl;
    
    do{
        cout<<"Enter your choice: "<<endl;
        cin>>c;
        switch(c){
            case 1:
                cout<<"Enter 2 nos.: "<<endl;
                cin>>num1>>num2;
                cout<<num1+num2<<endl;
                break;
            case 2:
                cout<<"Enter 2 nos.: "<<endl;
                cin>>num1>>num2;
                cout<<num1-num2<<endl;
                break;
            case 3:
                cout<<"Enter 2 nos.: "<<endl;
                cin>>num1>>num2;
                cout<<num1*num2<<endl;
                break;
            case 4:
                cout<<"Enter 2 nos.: "<<endl;
                cin>>num1>>num2;
                if (num2==0){
                    cout<<"Error"<<endl;
                }
                else{
                    cout<<num1/num2<<endl;
                    break;
                }
            case 5:
                cout<<"Exiting program"<<endl;
                break;
            default:
                cout<<"invalid choice"<<endl;
        }
        
    }while(c!=5);
    return 0;
}

