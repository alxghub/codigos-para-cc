#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
} *first, *last;

//Function declarations
void menu();
void addNode();
void showListAsc();
void showListDes();
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
            <<"2. Show List in ascending index order"<<endl
            <<"3. Show List in descending index order"<<endl
            <<"4. Find element"<<endl
            <<"5. Edit Node"<<endl
            <<"6. Delete Node"<<endl
            <<"7. Show Information of List"<<endl
            <<"8. Delete List"<<endl
            <<"9. Close"<<endl
            <<"Choose option -> "; cin>>op;
        switch (op){
            case 1: addNode(); break;
            case 2: showListAsc(); break;
            case 3: showListDes(); break;
            case 4: searchNode(); break;
            case 5: editNode(); break;
            case 6: deleteNode(); break;
            case 7: showInfoList(); break;
            case 8: deleteList(); break;
            case 9:
                cout<<"Program Finished.."<<endl<<"Press Enter to close.."<<endl;
                break;
            default:
                cout<<"Invalid option..";
                break;
            }
    }while(op != 9);
    cin.ignore();
    cin.get();
}
void addNode(){
    Node* new_node = new Node();
    cout<<"Insert the new data to Node -> "; cin>>new_node->data;
    if(first == NULL){
        first = new_node;
        last = new_node;
        first->next = first;
        first->prev = last;
    }else{
        last->next = new_node;
        new_node->prev = last;
        new_node->next = first;
        last = new_node;
        first->prev = last;
    }
    cout<<"\nNode insert correctly.."<<endl<<endl;
}

void showListAsc(){
    if(first == NULL) cout<<"List is empty..";
    else{
        Node* tmp = new Node();
        tmp = first;
        cout<<endl;
        do{
            cout<<tmp->data<<" -> ";
            tmp = tmp->next;
        }while(tmp != first);
    }
    cout<<endl<<endl;
}

void showListDes(){
    if(first == NULL) cout<<"List is empty..";
    else{
        Node* tmp = new Node();
        tmp = last;
        cout<<endl;
        do{
            cout<<tmp->data<<" -> ";
            tmp = tmp->prev;
        }while(tmp != last);
    }
    cout<<endl<<endl;
}

void searchNode(){
    if(first == NULL) cout<<"List is empty..";
    else{
        Node* tmp = new Node();
        tmp = first;
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
        if (!f) cout<<"\nElement has not found..";
    }
    cout<<endl<<endl;
}

void editNode(){
    if(first == NULL) cout<<"List is empty..";
    else{
        Node* tmp = new Node();
        tmp = first;
        bool f = false;
        int n;
        cout<<"Insert element to modify ->"; cin>>n;
        do{
            if(tmp->data == n){
                cout<<"\nFound item in memory location: "<<tmp<<endl;
                cout<<"Insert the new value -> "; cin>>tmp->data;
                cout<<"Changed value"<<endl;
                f = true;
            }
            tmp = tmp->next;
        }while(tmp != first and f != true);
        if (!f) cout<<"\nElement has not found..";
    }
    cout<<endl<<endl;
}

void deleteNode(){
    if(first == NULL) cout<<"List is empty..";
    else{
        Node* tmp = new Node();
        Node* back = new Node();
        tmp = first;
        back = NULL;
        bool f = false;
        int n;
        cout<<"Insert element to delete ->"; cin>>n;
        do{
            if(tmp->data == n){
                cout<<"\nFound item in memory location: "<<tmp;
                if(tmp == first){
                    if(tmp == last){
                        first = NULL;
                        last = NULL;
                    }else{
                        first = first->next;
                        first->prev = last;
                        last->next = first;
                    }
                }else if(tmp == last){
                    last = back;
                    last->next = first;
                    first->prev = last;
                }else{
                    back->next = tmp->next;
                    tmp->next->prev = back;
                }
                cout<<"\nNode removed";
                f = true;
                break;
            }
            back = tmp;
            tmp = tmp->next;
        }while(tmp != first and f != true);
        if (f) delete tmp;
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
            cout<<"Previous pointer: "<<tmp->prev<<" || Memory location: "<<tmp<<" || Data: "<<tmp->data<<" || Next pointer: "<<tmp->next<<endl;
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