#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include <vector>
#include "LinkedList.h"
using namespace std;
template <class T>
LinkedList<T>::LinkedList()
{
    head=NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
	head=NULL;
    ListItem<T> *temp = otherLinkedList.head;
    insertAtHead(temp->value);
    temp=temp->next;
    while (temp!=NULL)
    {
    	insertAtTail(temp->value);
    	temp=temp->next;
    }
    
}

template <class T>
LinkedList<T>::~LinkedList()
{
	while(head!=NULL)
	{
		deleteHead();
	}
    
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
	ListItem<T> *temp= new ListItem<T>(item);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;
    }
    
}

template <class T>
int LinkedList<T>:: isPalindrome()
{
	if (head==NULL)
	{
		return 0;
	}
	ListItem<T> *start = getHead();
	ListItem<T> *end = getTail();
	while (start!=end)
	{
		if (start->value != end->value)
		{
			return 0;
		}
		else
		{
			start=start->next;
			end=end->prev;
		}
	}
	return 1;
    
}




template <class T>
void LinkedList<T>::insertAtTail(T item)
{
    if(head==NULL)
    {
        insertAtHead(item);
    }
    else
    {
        ListItem<T> *Traverse_var= head;
        ListItem<T> *insert= new ListItem<T>(item);
        while(Traverse_var->next!=NULL)
        {
            Traverse_var=Traverse_var->next;
        }
        Traverse_var->next=insert;
            insert->prev=Traverse_var;
            insert->next=NULL;
    }
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
    ListItem<T> *insert = new ListItem<T>(toInsert);
    ListItem<T> *temp=head;
    while (temp->next!=NULL && temp->value!=afterWhat)
    {
        temp=temp->next;
    }
    insert->next=temp->next;
    insert->prev=temp;
    temp->next=insert;
    if(insert->next!=NULL)
    {
        insert->next->prev=insert;
    }
}
template <class T>

void LinkedList<T>::insertSorted(T item)
{
	 if (head == NULL ||head->value >= item) 
	 	{
	 		insertAtHead(item);
	 	}
    else
    {
        ListItem<T> *temp= head;
        while (temp != NULL && temp->value<item)  
        	{
        		temp = temp->next;
        	}
        if (temp == NULL) 
        	{
        		insertAtTail(item);
        	}
        else
        {
            ListItem<T> *insert=new ListItem<T>(item);
            insert->next=temp;
            temp->prev->next= insert;
            insert->prev=temp->prev;
            temp->prev=insert;
        }

    }
    
}

template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
	return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
	if (head==NULL)
	{
		return NULL;
	}
    ListItem<T>*temp=head;
    while(temp->next!=NULL)
    {
    	temp=temp->next;
    }
    return temp;
}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
	ListItem<T> *Traverse_var= head;
	if (head==NULL)
	{
		return NULL;
	}
	else
	{
		while (Traverse_var!=NULL)
		{
			if (Traverse_var->value==item)
			{
				return Traverse_var;
			}
			Traverse_var=Traverse_var->next;
		}
		return NULL;
	}
}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
	ListItem<T> *current = head;
	if(head==NULL)
	{
		return;
	}
	else if (current->value==item)
	{
		deleteHead();
		return;
	}
	else
	{
		while(current->next!=NULL && current->value!=item)
		{
			current=current->next;
		}
		if(current->next==NULL && current->value==item)
		{
			deleteTail();
			return;
		}
		else if (current->value==item)
		{	
			current->prev->next=current->next;
			current->next->prev=current->prev;
			return;
		}
	}
    
}

template <class T>
void LinkedList<T>::deleteHead()
{
   if(head!=NULL && head->next!=NULL)
    {
        ListItem <T>* temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    else 
    {
	head = NULL;
    }    
}

template <class T>
void LinkedList<T>::deleteTail()
{
   ListItem<T> *temp=head;
    if(this->length()<=1)
    {
        head=NULL;
        return;
    }
    while(temp->next!=NULL) 
    {
	temp=temp->next;
    }
    (temp->prev)->next=NULL;
    free(temp);
    
}


template <class T>
int LinkedList<T>::length()
{
	int counter=0;
    ListItem<T> *current= head;
    while(current!=NULL)
    {
    	counter++;
    	current=current->next;
    }
    return counter;
}

template <class T>
void LinkedList<T>::reverse()
{
	ListItem<T> *current =head;
	ListItem<T> *temp;
	 while (current !=  NULL)
     {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;              
       current = current->prev;
     }      
      
     if(temp != NULL )
     {
     	head= temp->prev;
     } 

    
}

template <class T>
void LinkedList<T>::parityArrangement()
{
    int counter=length();
    if(length()<=1) return;
    vector<T> temp;
    while(length()!=0)
    {
        temp.push_back(head->value);
        head=head->next;
    }
    head=NULL;
    for (int i = 1 ; i<=counter; i ++)
    {
        if (i%2==1)
        {
            insertAtHead(temp[i-1]);
        }
        else if ( i%2==0)
        {
            insertAtTail(temp[i-1]);
        }

    }

   
}


#endif
