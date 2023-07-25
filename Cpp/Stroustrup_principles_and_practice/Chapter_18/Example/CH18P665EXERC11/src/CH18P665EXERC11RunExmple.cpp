/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 07/18/2023 09:16:49
	author                                          : Andrei-KS
*/

#include "CH18P665EXERC11RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P665EXERC11RunExmple();

namespace {

  /*
  */
  template<typename T>
  class SkipList
  {
  public:
    /*
    */
    struct Node
    {
      /**/
      Node* next;
      
      /**/
      Node* down;
      
      /**/
      T* key;

      /*
      */
      Node(T* key, Node* down, Node* next)
        : key{ key }
        , down{ down }
        , next{ next }
      {
      }
    };
  public:
    /*
    */
    SkipList()
      : size{ 0 }
      , upperLvlHead{ new Node(nullptr, nullptr, nullptr) }
    {

    }

    /*
    */
    SkipList(list<T> l)
      : size{0}
      , upperLvlHead { new Node(nullptr, nullptr, nullptr) }
    {
      // build first lvl
      Node* currentNode = upperLvlHead;
      for (list<T>::iterator it = l.begin(); it != l.end(); ++it)
      {
        currentNode->next = new Node(new T(*it), nullptr, nullptr);
        currentNode = currentNode->next;
        ++size;
      }

      // build next levels
      while (upperLvlHead->next && upperLvlHead->next->next)
      {
        upperLvlHead = buildLvl(upperLvlHead);
      }
    }

    /*
    */
    ~SkipList()
    {
      while (upperLvlHead)
      {
        Node* downLvl = upperLvlHead->down;
        while (upperLvlHead)
        {
          Node* next = upperLvlHead->next;
          destroyNode(upperLvlHead);
          upperLvlHead = next;
        }
        upperLvlHead = downLvl;
      }
    }

    /*
    */
    Node* find(const T& key)
    {
      return find(upperLvlHead, key);
    }

    /*
    */
    void insert_element(const T& key)
    {
      Node* res = insert(upperLvlHead, key);
      if (res)
      {
        Node* nextLvl = new Node(nullptr, upperLvlHead, nullptr);
        nextLvl->next = new Node(res->key, res, nullptr);
        upperLvlHead = nextLvl;
      }
    }

    /*
    */
    void delete_element(const T& key)
    {
      delete_el(upperLvlHead, key);
    }

  private:
    /**/
    Node* upperLvlHead;
    
    /**/
    size_t size;


    /*
    */
    Node* buildLvl(Node* lvl)
    {
      Node* nextLvl = new Node(nullptr, lvl, nullptr);
      Node* currentNextLvlNode = nextLvl;
      while (lvl->next && lvl->next->next)
      {
        currentNextLvlNode->next = new Node(lvl->next->next->key, lvl->next->next, nullptr);
        lvl = lvl->next->next;
        currentNextLvlNode = currentNextLvlNode->next;
      }
      return nextLvl;
    }

    /*
    */
    void destroyNode(Node* node)
    {
      if (!node->down && node->key)
      {
        delete node->key;
      }
      delete node;
    }

    /*
    */
    Node* find(Node* res, const T& key)
    {
      while (res->next && res->next->key && *res->next->key < key)
      {
        res = res->next;
      }

      if (!res->down)
      {
        return res;
      }

      return find(res->down, key);
    }

    /*
    */
    Node* insert(Node* res, const T& key)
    {
      while (res->next && res->next->key && *res->next->key < key)
      {
        res = res->next;
      }

      Node* down_node = nullptr;
      if (res->down)
      {
        down_node = insert(res->down, key);
      }

      if (down_node || !res->down)
      {
        res->next = new Node(nullptr, down_node, res->next);

        if (!res->down)
        {
          res->next->key = new T(key);
          ++size;
        }
        else
        {
          res->next->key = down_node->key;
        }

        if (coin_flip())
        {
          return res->next;
        }
      }

      return nullptr;
    }

    /*
    */
    //TODO need check it
    void delete_el(Node* res, const T& key)
    {
      while (res->next && res->next->key && *res->next->key < key)
      {
        res = res->next;
      }

      if (res->next && res->next->key && *res->next->key == key)
      {
        Node* next = res->next->next;
        destroyNode(res->next);
        res->next = next;
      }

      if (res->down)
      {
        delete_el(res->down, key);
      }


    }

    /*
    */
    bool coin_flip()
    {
      int res = rand() % 1000;
      return res < 367;
    }

  };
}

int CH18P665EXERC11RunExmple::excute()
{
  list<int> intList{ 1,2,3,5,7 };
  SkipList<int> sl(intList);
  SkipList<int>::Node* r = sl.find(6);
  sl.insert_element(4);
  sl.delete_element(5);
  sl.insert_element(5);
  sl.delete_element(2);
  sl.insert_element(8);

  SkipList<int> sl2;
  for (int index = 0; index < 1000; ++index)
  {
    sl2.insert_element(index);
  }
	return 0;
}