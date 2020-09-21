#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
} *first, *last;

//Function declarations
void menu();
void addNode();
void showList();
void searchNode();
void editNode();
void deleteNode();
void showInfoList();
void deleteList();

int main(){
    menu();
    return 0;
}

void menu(){
    int op;
    do{
        cout<<"~~~~~~~~~~~~ Menu ~~~~~~~~~~~~~"<<endl
            <<"1. Add Element"<<endl
            <<"2. Show List"<<endl
            <<"3. Find element"<<endl
            <<"4. Edit Node"<<endl
            <<"5. Delete Node"<<endl
            <<"6. Show Information of List"<<endl
            <<"7. Delete List"<<endl
            <<"8. Close"<<endl
            <<"Choose option -> "; cin>>op;
        switch (op){
            case 1: addNode(); break;
            case 2: showList(); break;
            case 3: searchNode(); break;
            case 4: editNode(); break;
            case 5: deleteNode(); break;
            case 6: showInfoList(); break;
            case 7: deleteList(); break;
            case 8:
                cout<<"Program Finished.."<<endl<<"Press Enter to close.."<<endl;
                break;
            default:
                cout<<"\nInvalid option.."<<endl;
                break;
            }
    }while(op != 8);
    cin.ignore();
    cin.get();
}

void addNode(){
    Node *new_node = new Node();
    cout<<"Insert the new element: "; cin>> new_node->data;
    if(first == NULL){
        first = new_node;
        first->next = first;
        last = first;
    }else{
        last->next = new_node;
        new_node->next = first;
        last = new_node;
    }
    cout<<"\nNode add correctly.."<<endl<<endl;
}

void showList(){
    if(first == NULL) cout<<"\nList is empty..";
    else{
        Node *tmp = first;
        cout<<endl;
        do{
            cout<<tmp->data<<" -> ";
            tmp = tmp->next;
        }while(tmp != first);
    }
    cout<<endl<<endl;
}

void searchNode(){
    if(first == NULL) cout<<"\nList is empty..";
    else{
        Node *tmp = first;
        bool f = false;
        int n;
        cout<<"Insert element to search ->"; cin>>n;
        do{
            if(tmp->data == n){
                cout<<"\nFound item in memory location: "<<tmp;
                f = true;
            }
            tmp = tmp->next;
        }while(tmp != first and f != true);
        if (f == false) cout<<"\nElement has not found..";
    }
    cout<<endl<<endl;
}

void editNode(){
    if(first == NULL) cout<<"\nList is empty..";
    else{
        Node *tmp = first;
        bool f = false;
        int n;
        cout<<"Insert element to modify -> "; cin>>n;
        do{
            if(tmp->data == n){
                cout<<"Found item "<<tmp->data<<" in memory location: "<<tmp<<endl;
                cout<<"Insert the new value -> "; cin>>tmp->data;
                cout<<"Changed value"<<endl;
                f = true;
            }
            tmp = tmp->next;
        }while(tmp != first and f != true);
        if (f == false) cout<<"\nElement has not found..";
    }
    cout<<endl<<endl;
}

void deleteNode(){
    if(first == NULL) cout<<"\nList is empty..";
    else{
        Node *tmp = first;
        Node *back = NULL;
        bool f = false;
        int n;
        cout<<"Insert element to delete -> "; cin>>n;
        do{// tmp = 15 ; first = 15;  last = 15;  back = null     5       ->  15 -> 15         12 ->
            if(tmp->data == n){
                cout<<"Found item "<<tmp->data<<" in memory location: "<<tmp<<endl;
                if(tmp == first){
                    if(tmp == last){
                        first = NULL;
                        last = NULL;
                    }else{
                        first = first->next;
                        last->next = first;
                    }
                }else if(tmp == last){
                    back->next = first;
                    last = back;
                }else{
                    back->next = tmp->next;
                }
                cout<<"\nNode removed";
                f = true;
                break;
            }
            back = tmp;
            tmp = tmp->next;
        }while(tmp != first);
        if (f == true) delete tmp;
        else cout<<"\nElement has not found..";
    }
    cout<<endl<<endl;
}

void showInfoList(){
    if(first == NULL) cout<<"\nList is empty..";
    else{
        Node *tmp = first;
        cout<<endl;
        do{
            cout<<"Memory location: "<<tmp<<" || Data: "<<tmp->data<<" || Next pointer: "<<tmp->next<<endl;
            tmp = tmp->next;
        }while(tmp != first);
    }
    cout<<endl<<endl;
}

void deleteList(){
    if(first == NULL) cout<<"\nList is empty..";
    else{
        Node *tmp = first;
        cout<<"\nRemoving nodes.."<<endl;
        do{
            cout<<tmp->data<<" -> ";
            Node *aux = tmp;
            tmp = tmp->next;
            delete aux;
        }while(tmp != first);
        first = NULL;
    }
    cout<<endl<<endl;
}