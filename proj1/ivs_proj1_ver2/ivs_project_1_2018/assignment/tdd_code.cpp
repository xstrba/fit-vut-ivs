//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     BORIS STRBAK <xstrba05@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author BORIS STRBAK
 *
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"

//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find a GetHead
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "double-linked list", ktera bude splnovat dodane testy
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{
    head = NULL;
}

PriorityQueue::~PriorityQueue()
{
    Element_t *item = GetHead();
    Element_t *itemtod;
    while(item != NULL)
    {

        itemtod = item;
        item = item->pNext;
        delete itemtod;

    }
}

void PriorityQueue::Insert(int value)
{

    Element_t *item = GetHead();
    Element_t *newitem = new Element_t();
    newitem->pPrev = NULL;
    newitem->pNext = NULL;
    newitem->value = value;

    //v pripade ze queue neobsahuje head prvok, resp. nema ziadne prvky
    if(item == NULL)
        head = newitem;
    else
    {

        while(item != NULL)
        {
            //najdeny prvok je jediny prvok a zaroven head
            if(item->pPrev == NULL && item->pNext == NULL)
            {

                if(item->value > value)
                {

                    newitem->pPrev = NULL;
                    newitem->pNext = item;
                    item->pPrev = newitem;
                    head = newitem;

                } else
                {

                    item->pNext = newitem;
                    newitem->pPrev = item;

                }
                return;

            }
            //najdeny prvok je head a za nim su dalsie prvky
            else if(item->pPrev == NULL && item->pNext != NULL)
            {

                if(item->value > value)
                {

                    newitem->pPrev = NULL;
                    newitem->pNext = item;
                    head = newitem;
                    item->pPrev = head;
                    return;

                }

            }
            //najdeny prvok je posledny prvok
            else if(item->pPrev != NULL && item->pNext == NULL)
            {

                if(item->value > value)
                {

                    newitem->pPrev = item->pPrev;
                    item->pPrev->pNext = newitem;
                    newitem->pNext = item;
                    item->pPrev = newitem;

                } else
                {

                    item->pNext = newitem;
                    newitem->pPrev = item;

                }
                return;

            }
            //najdeny prvok je v strede
            else if(item->pPrev != NULL && item->pNext != NULL)
            {

                if(item->value >= value && item->pPrev->value <= value)
                {

                    newitem->pPrev = item->pPrev;
                    item->pPrev->pNext = newitem;
                    newitem->pNext = item;
                    item->pPrev = newitem;
                    return;

                }

            }

            item = item->pNext;

        }

    }

}

bool PriorityQueue::Remove(int value)
{

    Element_t *item = Find(value);
    if(item != NULL)
    {

        //prvok je prvy a za nim nasleduju dalsie
        if(item->pPrev == NULL && item->pNext != NULL)
        {

            item->pNext->pPrev = NULL;
            head = item->pNext;

        }
        //prvok je posledny
        else if(item->pPrev != NULL && item->pNext == NULL)
        {

            item->pPrev->pNext = NULL;

        }
        //prvok je v strede
        else if(item->pPrev != NULL && item->pNext != NULL)
        {

            item->pPrev->pNext = item->pNext;
            item->pNext->pPrev = item->pPrev;

        } else  head = NULL;    //queue obsahuje iba head

        delete item;
        return true;

    }
    //prvok s hodnotou value neexistuje
    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{

    Element_t *item = GetHead();
    while(item != NULL)
    {

        //pvok je v queue
        if(item->value == value){
            return item;
        }
        item = item->pNext;

    }
    //prvok sa nenachadza v queue
    return NULL;

}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    return head;
}

/*** Konec souboru tdd_code.cpp ***/
