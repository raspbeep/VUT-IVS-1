//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2021-01-04
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author JMENO PRIJMENI
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
    m_pHead = nullptr;
}

PriorityQueue::~PriorityQueue()
{
    Element_t *current_elem;
    current_elem = GetHead();
    while (current_elem != nullptr) {
        Element_t *next_elem = current_elem->pNext;
        delete(current_elem);
        current_elem = next_elem;
    }
}

void PriorityQueue::Insert(int value)
{
    if (m_pHead == nullptr) {
        m_pHead = new Element_t{nullptr, value};
    } else if (value > m_pHead->value) {
        Element_t *old_head = m_pHead;
        m_pHead = new Element_t{old_head, value};
    } else {
        Element_t *current_node = m_pHead;
        while (current_node->pNext != nullptr) {
            if (current_node->pNext->value <= value) break;
            current_node = current_node -> pNext;
        }
        if (current_node->pNext == nullptr) {
            current_node->pNext = new Element_t{nullptr, value};
        }else {
            Element_t *next_elem;
            next_elem = current_node->pNext;
            current_node->pNext = new Element_t{next_elem, value};
        }
    }
}

bool PriorityQueue::Remove(int value) {
    Element_t *current_elem;
    current_elem = GetHead();
    if (current_elem == nullptr) return false;
    if (current_elem->value == value) {
        m_pHead = current_elem->pNext;
        delete (current_elem);
        return true;
    }

    while (current_elem->pNext != nullptr) {
        if (current_elem->pNext->value == value) break;
        current_elem = current_elem->pNext;
    }
    if (current_elem->pNext != nullptr) {
        Element_t *temp_elem;
        temp_elem = current_elem->pNext->pNext;
        delete (current_elem->pNext);
        current_elem->pNext = temp_elem;
        return true;
    }
    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{
    Element_t *current_elem;
    current_elem = GetHead();
    while (current_elem != nullptr) {
        if (current_elem->value == value) return current_elem;
        current_elem = current_elem->pNext;
    }
    return nullptr;
}

size_t PriorityQueue::Length()
{
	Element_t *current_node;
	current_node = m_pHead;
	int length = 0;
	while (current_node != nullptr) {
	    length += 1;
	    current_node = current_node->pNext;
	}
	return length;
}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    return m_pHead;
}

/*** Konec souboru tdd_code.cpp ***/
