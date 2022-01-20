//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2021-02-21
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author PAVEL KRATOCHVÍL <xkrato61@stud.fit.vutbr.cz>
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

class EmptyTree : public ::testing::Test {
protected:
    BinaryTree empty_tree;
};


class NonEmptyTree:public::testing::Test {
protected:
    void SetUp() override {
        int values[] = {10, 85, 15, 70, 20, 60, 30, 50, 50, 65, 80, 90, 40, 5, 55};

        for(int i = 0; i < 14; ++i)
            non_empty_tree.InsertNode(values[i]);
    }
    BinaryTree non_empty_tree;
};


TEST_F(EmptyTree, InsertNode) {
    // new node
    auto insert_result = empty_tree.InsertNode(69);
    EXPECT_TRUE(insert_result.first);
    EXPECT_EQ(insert_result.second -> key, 69);

    // testing with the same node, should return False, same pointer as before
    auto insert_result2 = empty_tree.InsertNode(69);
    EXPECT_FALSE(insert_result2.first);
    EXPECT_EQ(insert_result.second, insert_result2.second);
}


TEST_F(EmptyTree, DeleteNode) {
    // with an existing node
    int insert_key = 123;
    empty_tree.InsertNode(insert_key);
    auto delete_result = empty_tree.DeleteNode(insert_key);
    EXPECT_TRUE(delete_result);

    // without an existing node
    int non_existing_key = 567;
    auto delete_result2 = empty_tree.DeleteNode(non_existing_key);
    EXPECT_FALSE(delete_result2);
}


TEST_F(EmptyTree, FindNode) {
    // with an existing node
    int find_key = 789;
    empty_tree.InsertNode(find_key);
    auto find_result = empty_tree.FindNode(find_key);
    EXPECT_EQ(find_result->key, find_key);

    // without an existing node
    int non_existing_key2 = 31;
    auto find_result2 = empty_tree.FindNode(non_existing_key2);
    EXPECT_FALSE(find_result2);
}


// NON EMPTY TREE TESTS
TEST_F(NonEmptyTree, InsertNode) {
    // new node
    auto insert_result = non_empty_tree.InsertNode(69);
    EXPECT_TRUE(insert_result.first);
    EXPECT_EQ(insert_result.second -> key, 69);

    // testing with the same node, should return False, same pointer as before
    auto insert_result2 = non_empty_tree.InsertNode(69);
    EXPECT_FALSE(insert_result2.first);
    EXPECT_EQ(insert_result.second, insert_result2.second);
}


TEST_F(NonEmptyTree, DeleteNode) {
    // with an existing node
    int insert_key = 123;
    non_empty_tree.InsertNode(insert_key);
    auto delete_result = non_empty_tree.DeleteNode(insert_key);
    EXPECT_TRUE(delete_result);

    // without an existing node
    int non_existing_key = 567;
    auto delete_result2 = non_empty_tree.DeleteNode(non_existing_key);
    EXPECT_FALSE(delete_result2);
}

TEST_F(NonEmptyTree, FindNode) {
    // with an existing node
    int find_key = 789;
    non_empty_tree.InsertNode(find_key);
    auto find_result = non_empty_tree.FindNode(find_key);
    EXPECT_EQ(find_result->key, find_key);

    // without an existing node
    int non_existing_key2 = 31;
    auto find_result2 = non_empty_tree.FindNode(non_existing_key2);
    EXPECT_FALSE(find_result2);
}


// NON EMPTY TREE AXIOM TESTS
// all NIL leaves should be black
TEST_F(NonEmptyTree, Axiom1) {
    std::vector<BinaryTree::Node_t *> leaf_nodes;
    non_empty_tree.GetLeafNodes(leaf_nodes);

    // RED = 0, BLACK = 1, expecting all leaves are black
    for(auto & leaf_node : leaf_nodes) {
        //std::cout << leaf_node -> color;
        EXPECT_EQ(leaf_node -> color, 1);
    }
}

// children of red node should be black
TEST_F(NonEmptyTree, Axiom2) {
    std::vector<BinaryTree::Node_t *> all_nodes;
    non_empty_tree.GetAllNodes(all_nodes);
    for (auto & node : all_nodes) {
        if (node -> color == 0) {
            //std::cout << "color right:" << node->pRight->color << "color left:" << node->pLeft->color << "/n";
            EXPECT_EQ(node->pLeft->color, 1);
            EXPECT_EQ(node->pRight->color, 1);
        }
    }
}

// same number of black nodes for each NIL leaf to ROOT
TEST_F(NonEmptyTree, Axiom3) {
    std::vector<BinaryTree::Node_t *> leaf_nodes;
    non_empty_tree.GetLeafNodes(leaf_nodes);

    // first value to compare other nodes with
    int counter_black_nodes = -1;
    // counter of black nodes for each node in the loop
    int current_counter = -1;

    Node_t * root_node = non_empty_tree.GetRoot();
    for (auto & leaf_node : leaf_nodes) {
        current_counter = 0;
        Node_t * current_node = leaf_node;
        while (current_node != root_node) {
            if (current_node->color == 1) {
                current_counter += 1;
            }
            current_node = current_node->pParent;
        }
        if (counter_black_nodes == -1) {
            //std::cout << "first: " << counter_black_nodes << " ";
            counter_black_nodes = current_counter;
        }else {
            //std::cout << "next: " << current_counter << " ";
            EXPECT_EQ(counter_black_nodes, current_counter);
        }
    }
}


//

/*** Konec souboru black_box_tests.cpp ***/
