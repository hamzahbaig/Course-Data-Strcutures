#include "MySortedSet.h"

using namespace std;
template <class T>
MySortedSet<T>::MySortedSet()
{
}

template <class T>
MySortedSet<T>::~MySortedSet()
{}

template <class T>
ListItem<T>* MySortedSet<T>::getListHead()
{
	return container.getHead();
}

template <class T>
int MySortedSet<T>::count()
{
	return container.length();
}

template <class T>
int MySortedSet<T>::insert(T ele)
{
	if (isEmpty() == 1)
	{
		container.insertAtHead(ele);
		return 1;
	}
	else
	{
		if (isMember(ele)==0)
		{
			container.insertSorted(ele);
			return 1;
		}
		else
		{
			return 0;
		}

	}

}

template <class T>
int MySortedSet<T>::deleteEle(T ele)
{
	if (container.searchFor(ele))
	{
		container.deleteElement(ele);
		return 1;
	}
	else
	{
		return 0;
	}
}

template <class T>
int MySortedSet<T>::isEmpty()
{
	if (container.length()<=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <class T>
int MySortedSet<T>::isMember(T ele)
{
	if(container.searchFor(ele)!=NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <class T>
int MySortedSet<T>::isEqual(MySortedSet<T>* anotherset)
{
	int flag = 0;
	ListItem<T>* list1 = getListHead();
	ListItem<T>* list2 = anotherset->getListHead();
	while(list1 != NULL && list2 != NULL)
		{
			if(list1->value == list2->value)
			{
				flag=0;
			}
			else
			{
				flag=1;
				break;
			}
			list1=list1->next;
			list2=list2->next;
		}
		if (flag==0)
		{
			return 1;
		}
		else if (flag==1)
		{
			return 0;
		}
	
	
}
	

template <class T>
int MySortedSet<T>::isSubset(MySortedSet<T>* anotherset)
{
	ListItem<T> *temp = anotherset->getListHead();
	while(temp!=NULL)
	{
		if (isMember(temp->value)==0)
		{
			return 0;
		}
		temp=temp->next;
	}
	return 1;
}

template <class T>
MySortedSet<T>* MySortedSet<T>::setUnion(MySortedSet<T>* anotherset)
{
	MySortedSet<T>* new_set = new MySortedSet;
	ListItem<T>* current_set= getListHead();
	ListItem<T>* external_set=anotherset->getListHead();
	while(external_set!=NULL)
	{
		new_set->insert(external_set->value);
		external_set=external_set->next;
	}
	if(isEmpty()==0) // means current list is not empty :D
	{
		while(current_set!=NULL)
		{
			new_set->insert(current_set->value);
			current_set=current_set->next;
		}
	}
	return new_set;
}

template <class T>
MySortedSet<T>* MySortedSet<T>::setIntersection(MySortedSet<T>* anotherset)
{
	MySortedSet<T>* new_set = new MySortedSet;
	ListItem<T>* current_set= getListHead();
	ListItem<T>* external_set=anotherset->getListHead();
	while(current_set!=NULL)
	{
		while(external_set!=NULL)
		{	
			if(current_set->value == external_set->value)
			{
				new_set->insert(current_set->value);			
			}
			external_set=external_set->next;
		}
		current_set=current_set->next;
	}
	return new_set;	

}

template <class T>
MySortedSet<T>* MySortedSet<T>::setDifference(MySortedSet<T>* anotherset)
{
	int flag=0;
	MySortedSet<T>* new_set = new MySortedSet;
	ListItem<T>* current_set= getListHead();
	ListItem<T>* external_set=anotherset->getListHead();
	while(current_set !=NULL)
	{
		while (external_set !=NULL )
		{
			if(current_set->value != external_set->value)
			{
				flag=0;
			}
			else
			{
				flag=1;
				break;
			}
			external_set=external_set->next;
		}
		if(flag==0)
		{
			new_set->insert(current_set->value);
		}
		current_set=current_set->next;
	}
	return new_set;
}
