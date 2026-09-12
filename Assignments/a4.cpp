#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *next ;
} ;

ListNode* insertNodeAtEnd(ListNode *head,int val){
    if(head==NULL){
        head= new ListNode ;
        head->data = val;
        head->next = NULL ;
        return head;
    }
    ListNode *itr = head ;
    while(itr->next!=NULL){
        itr= itr->next ;
    }
    itr->next = new ListNode ;
    itr= itr->next ;
    itr->data= val ;
    itr->next = nullptr ;
    return head ;
}


// ek thik krta hun dusra bigad jata hai sir , T-T
void deleteNodeAtEnd(ListNode *&head){//pass by reference needs to be done
    ListNode *itr = head;

    if(head == NULL){// this line is checking if the head is pointing to null means that linked list is empty
        cout << "List is empty nothing to delete !!" << endl;
    }else{// if head is not pointing to null menaing there are emelemt or elements
        if(head->next==NULL){// this is checking if *(head).next is null , in simple terms it means that t is checking if the linked list is having only one element
            ListNode *tempp=head;//tempp is pointing to head 
            head=NULL;// head assigned to null 
            itr=NULL;//thus itr needs to be asigned to null as well
            free(tempp);// we are freeing the memory takin it into consideration that its memory is allocated using malloc,calloc if new is used then we need to use delete
            tempp=NULL; // to make sure its not a dangling pointer
        }
        if(itr==NULL){//now if i wont check this it should give a segmentation fault
            return;
        }
            while(itr->next->next != NULL){
                itr = itr->next;
            }

            ListNode *temp = itr->next;
            itr->next = NULL;

            free(temp);
            temp = NULL;
        }
}

void displayLinkedList(ListNode *head){
    ListNode *itr = head ;
    while(itr!=NULL){
        cout<<itr->data<<"->" ;
        itr= itr->next ;
    }
    cout<<"nullptr\n" ;
}

ListNode* insertNodeAtStart(ListNode *head, int val){
    ListNode *temp = new ListNode ;
    temp->data = val ;
    temp->next = NULL ;
    temp->next = head ;
    head = temp ;
    return head ;
}

ListNode* deleteNodeAtStart(ListNode *head){
    ListNode *temp = head ;
    head= head->next ;
    free(temp) ;
    temp = nullptr ;
    return head ;
}


int main() 
{
    ListNode *head = NULL ;
    int n ;
    cin>>n ;
    int temp ;
    while(n--){
        cin>>temp ;
        head= insertNodeAtEnd(head, temp) ;
    }
    displayLinkedList(head) ;
    deleteNodeAtEnd(head);
    displayLinkedList(head) ;
    head = deleteNodeAtStart(head) ;
    displayLinkedList(head) ;
    cout<<"Insert element-> " ;
    cin>>temp ;
    head = insertNodeAtStart(head, temp) ;
    displayLinkedList(head) ;
    return 0;
}