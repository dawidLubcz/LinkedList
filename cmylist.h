#ifndef MYLIST
#define MYLIST

typedef long unsigned int uint64_t;
typedef bool bool_t;

template<class T>
class CMyList
{
private:
    class Node
    {
       public:
        T iValue;
        Node* pNextItem;

        explicit Node(T a_iValue);
        explicit Node(Node& a_oNode);
    };

    Node* m_pFirstItem;
    Node* m_pLastItem;
    static uint64_t iItemsCounter;

public:
    CMyList();

    /**
     * Add item to front of the list
     *
     * @param a_oItem item which will be added to the list
     *
     * @return true if succeed, false otherwise
     */
    bool_t addFirst(T a_oItem);

    /**
     * Get the size of the list.
     *
     * @return uint64_t list size
     */
    uint64_t size();

    /**
     * Remove item from the list.
     *
     * @param item which will be removed from the list
     *
     * @return true if succeed, false otherwise
     */
    bool_t remove(T a_oItem);

    /**
     * Remove the last node of the list.
     *
     * @return true if succeed, false otherwise
     */
    bool_t removeLast();

    /**
     * Remove the first node of th list.
     *
     * @return true if succeed, false otherwise
     */
    bool_t removeFirst();

    /**
     * Clear the list.
     *
     * @return true if succeed, false otherwise
     */
    bool_t clear();

    /**
     * Get items from the list.
     *
     * @param a_atItemsArray array which will be filled by list items
     * @param a_ui64Size size of the array
     *
     * @return true if succeed, false otherwise
     */
    bool_t getItems(T *a_atItemsArray, uint64_t a_ui64Size = iItemsCounter);

};

#include "cmylist.cpp"

#endif // MYLIST

