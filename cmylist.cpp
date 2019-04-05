#include"cmylist.h"
#include <iostream>

template<typename T>
uint64_t CMyList<T>::iItemsCounter = 0;

template<typename T>
CMyList<T>::CMyList():m_pFirstItem(0),m_pLastItem(0)
{}

template<typename T>
CMyList<T>::Node::Node(T a_iValue)
{
    iValue = a_iValue;
    pNextItem = 0;
}

template<typename T>
CMyList<T>::Node::Node(Node& a_item)
{
    iValue = a_item.iValue;
    pNextItem = a_item.pNextItem;
}

template<typename T>
bool_t CMyList<T>::addFirst(T a_oItem)
{
    bool_t fResult = true;

    // create poiter to new item
    Node* newItem = new Node(a_oItem);

    // check if list is empty
    if(0 == iItemsCounter)
    {
        // if we adding first element, first and last item are the same
        m_pFirstItem = newItem;
        m_pLastItem  = newItem;
    }
    else
    {
        // store addres to first element in newItem.next and set new Item as first element
        newItem->pNextItem = m_pFirstItem;
        m_pFirstItem = newItem;
    }

    if(0 == m_pFirstItem || 0 == m_pLastItem)
    {
        fResult = false;
    }

    iItemsCounter++;

    return fResult;
}

template<typename T>
uint64_t CMyList<T>::size()
{
    return iItemsCounter;
}

template<typename T>
bool_t CMyList<T>::remove(T a_oItem)
{
    bool_t fResult = true;

    Node oItemToRem(a_oItem);
    Node* temp = m_pFirstItem;
    while(temp)
    {
        if(oItemToRem.iValue == temp->iValue)
        {
            try
            {
                bool_t isFirst = false;
                bool_t isLast  = false;

                //first item
                if(temp == m_pFirstItem)
                {
                    fResult = removeFirst();

                    temp = m_pFirstItem->pNextItem;
                    isFirst = true;
                }

                //last item
                if((false == isFirst)) // if one element was in the list is need to check if poiter was deleted
                {
                    if(0 == temp->pNextItem)
                    {
                        fResult = removeLast();
                        isLast = true;
                        break;
                    }
                }

                if(false == isFirst && false == isLast)
                {
                    Node* toRem = temp;
                    Node* iterator = m_pFirstItem;
                    while(iterator)
                    {
                        if(oItemToRem.iValue == iterator->pNextItem->iValue)
                        {
                            iterator->pNextItem = temp->pNextItem;
                            temp = iterator;
                            break;
                        }
                        iterator = iterator->pNextItem;
                    }

                    delete toRem;
                    iItemsCounter--;
                }
            }
            catch(...)
            {
                fResult = false;
            }
        }
        if(temp != 0)
            temp = temp->pNextItem;
    }
    return fResult;
}

template<typename T>
bool_t CMyList<T>::removeLast()
{
    bool_t fResult = true;

    try
    {
        Node* toRem = m_pLastItem;
        Node* iterator = m_pFirstItem;
        while(iterator)
        {
            if(0 == iterator->pNextItem->pNextItem)
            {
                iterator->pNextItem = 0;
                m_pLastItem = iterator;
            }

            iterator = iterator->pNextItem;
        }

        delete toRem;
        iItemsCounter--;
    }
    catch(...)
    {
        fResult = false;
    }

    return fResult;
}

template<typename T>
bool_t CMyList<T>::removeFirst()
{
    bool_t fResult = true;

    try
    {
        if(0 != m_pFirstItem)
        {
            Node* toRem = m_pFirstItem;
            m_pFirstItem = m_pFirstItem->pNextItem;

            delete toRem;

            iItemsCounter--;
        }
        else
        {
            fResult = false;
        }
    }
    catch(...)
    {
        fResult = false;
    }

    return fResult;
}

template<typename T>
bool_t CMyList<T>::clear()
{
    bool_t fResult = true;

    while(m_pFirstItem)
    {
        try
        {
            // delete elements from first to last
            Node* toRem = m_pFirstItem;
            m_pFirstItem = m_pFirstItem->pNextItem;
            delete toRem;

            iItemsCounter--;
        }
        catch(...)
        {
            fResult = false;
        }
    }
    return fResult;
}

template<typename T>
bool_t CMyList<T>::getItems(T *a_atItemsArray, uint64_t a_ui64Size)
{
    bool_t fResult = false;

    Node* temp = m_pFirstItem;

    for(uint64_t idx64 = 0;( (idx64 < a_ui64Size) && (idx64 < iItemsCounter) && (0 != temp) ); idx64++)
    {
        a_atItemsArray[idx64] = temp->iValue;
        temp = temp->pNextItem;
    }

    return fResult;
}
