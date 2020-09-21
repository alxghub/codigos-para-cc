#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
} *first=NULL, *last=NULL;

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
    Node *new_node = new Node();
    cout<<"Insert new element -> "; cin>>new_node->data;

    if(first==NULL){
        first = new_node;
        first->next = NULL;
        first->prev = NULL;
        last = first;
    }else{
        last->next = new_node;
        new_node->next = NULL;
        new_node->prev = last;
        last = new_node;
    }
    cout<<"\nElement insert correctly.."<<endl<<endl;
}

void showListAsc(){
    if(first != NULL){
        Node *tmp = new Node();
        tmp = first;
        cout<<endl;
        while(tmp != NULL){
            cout<<tmp->data<<" -> ";
            tmp = tmp->next;
        }
        delete tmp;
    }else cout<<"\nList is empty..";
    cout<<endl<<endl;
}

void showListDes(){
    if(first != NULL){
        Node *tmp = new Node();
        tmp = last;
        cout<<endl;
        while(tmp != NULL){
            cout<<tmp->data<<" -> ";
            tmp = tmp->prev;
        }
        delete tmp;
    }else cout<<"\nList is empty..";
    cout<<endl<<endl;
}

void searchNode(){
    if(first != NULL){
        int n;
        bool f = false;
        Node *tmp = new Node();
        tmp = first;
        cout<<"Insert element to search -> "; cin>>n;
        cout<<endl;
        while(tmp != NULL){
            if(tmp->data == n){
                cout<<"\nFound item in memory location: "<<tmp<<endl;
                f = true;
                break;
            }
            tmp = tmp->next;
        }
        if(!f) cout<<"Item has not found"<<endl;
        //delete tmp;
    }else cout<<"\nList is empty..";
    cout<<endl<<endl;
}

void editNode(){
    if(first != NULL){
        int n;
        bool f = false;
        Node *tmp = new Node();
        tmp = first;
        cout<<"Insert element to edit -> "; cin>>n;
        cout<<endl;
        while(tmp != NULL){
            if(tmp->data == n){
                cout<<"\nFound item"<<tmp->data<<" in memory location: "<<tmp<<endl;
                cout<<"Insert new value: "; cin>>tmp->data;
                cout<<"Changed value"<<endl;
                f = true;
                break;
            }
            tmp = tmp->next;
        }
        if(!f) cout<<"Item has not found"<<endl;
        //delete tmp;
    }else cout<<"\nList is empty..";
    cout<<endl<<endl;
}

void deleteNode(){
    if(first != NULL){
        int n;
        bool f = false;
        Node *tmp = new Node();
        Node *back = new Node();
        back = NULL;
        tmp = first;
        cout<<"Insert element to delete node-> "; cin>>n;
        cout<<endl;
        while(tmp != NULL){
            if(tmp->data == n){
                cout<<"\nFound item in memory location: "<<tmp<<endl;
                if(tmp == first){
                    first = first->next;
                    if(first != NULL) first->prev = NULL;
                }else if(tmp == last){
                    back->next = NULL;
                    last = back;
                }else{
                    back->next = tmp->next;
                    tmp->next->prev = back;
                }
                cout<<"\n Node removed "<<endl;
                f = true;
                break;
            }
            back = tmp;
            tmp = tmp->next;
        }
        if(!f) cout<<"Item has not found"<<endl;
        delete tmp;
    }else cout<<"\nList is empty..";
    cout<<endl<<endl;
}

void showInfoList(){
    if(first != NULL){
        Node *tmp = new Node();
        tmp = first;
        cout<<endl;
        while(tmp != NULL){
            cout<<"Previous pointer: "<<tmp->prev<<" || Data: "<<tmp->data<<" || Memory location: "<<tmp<<" || Next pointer: "<<tmp->next<<endl;
            tmp = tmp->next;
        }
        delete tmp;
    }else cout<<"\nList is empty..";
    cout<<endl<<endl;
}

void deleteList(){
    if(first != NULL){
        cout<<"\nRemoving nodes.."<<endl;
        while(first != NULL){
            Node *tmp = new Node();
            tmp = first;
            cout<<first->data<<" -> ";
            first = first->next;
            delete tmp;
        }
        last = NULL;
    }else cout<<"\nList is empty..";
    cout<<endl<<endl;
}