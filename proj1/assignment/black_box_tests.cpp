//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     Boris Strbak <xstrba05@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author Boris Strbak
 *
 * @brief Implementace testu binarniho stromu.
 */

#include <stdlib.h>
#include <utility>
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

class NonEmptyTree : public ::testing::Test
{
    protected:
        std::vector<int> values = { 1, 6, 13, 8, 11, 17, 15 , 22, 25, 27};
        std::vector<std::pair<bool, Node_t *> > nodes= {};

        std::vector<int> inserts = { -100, -3, 0, 3, 100};

        virtual void SetUp() {
            tree.InsertNodes(values, nodes);
        }

        BinaryTree tree;
};

class EmptyTree : public ::testing::Test
{
    protected:
        BinaryTree tree;
};

class TreeAxioms : public NonEmptyTree
{

};

TEST_F(EmptyTree, InsertNode)
{
    EXPECT_TRUE(tree.GetRoot() == NULL);
    std::pair<bool, BinaryTree::Node_t *> insert = tree.InsertNode(1);
    BinaryTree::Node_t *root = insert.second;

    ASSERT_EQ(tree.GetRoot()->key, 1);
    EXPECT_TRUE(root->color == BLACK);
    EXPECT_TRUE(root->pParent == NULL);
    EXPECT_TRUE(root->pRight->key == 0);
    EXPECT_TRUE(root->pLeft->key == 0);
    EXPECT_TRUE(root->pRight->color == BLACK);
    EXPECT_TRUE(root->pLeft->color == BLACK);
}

TEST_F(EmptyTree, DeleteNode)
{
    EXPECT_EQ(tree.DeleteNode(100),  0);
    EXPECT_EQ(tree.DeleteNode(0),  0);
    EXPECT_EQ(tree.DeleteNode(-2), 0);
}

TEST_F(EmptyTree, FindNode)
{
    EXPECT_TRUE(tree.FindNode(100) == NULL);
    EXPECT_TRUE(tree.FindNode(0) == NULL);
    EXPECT_TRUE(tree.FindNode(-2) == NULL);
}

TEST_F(NonEmptyTree, InsertNode)
{
    // std::cout << tree.GetRoot()->key << '\n';
    //kontrola vsetkych uzlov
    BinaryTree::Node_t *root = tree.GetRoot();
    ASSERT_TRUE(root != NULL);
    for (int n : values) {
        ASSERT_TRUE(tree.FindNode(n) != NULL);
    }

    //vlozenie uz existujuceho uzla
    std::pair<bool, BinaryTree::Node_t *> insert_f = tree.InsertNode(values[2]);
    EXPECT_FALSE(insert_f.first);
    EXPECT_TRUE(insert_f.second == nodes[2].second);

    //vlozenie noveho uzla
    std::pair<bool, BinaryTree::Node_t *> insert_new = tree.InsertNode(20);
    EXPECT_TRUE(insert_new.first);
    EXPECT_TRUE(insert_new.second != NULL);
    EXPECT_TRUE(tree.FindNode(20) != NULL);
}

TEST_F(NonEmptyTree, DeleteNode)
{
    //kontrola vsetkych uzlov
    BinaryTree::Node_t *root = tree.GetRoot();
    ASSERT_TRUE(root != NULL);
    for (int n : values) {
        ASSERT_TRUE(tree.FindNode(n) != NULL);
    }

    //odstranenie uz existujuceho uzla
    EXPECT_TRUE(tree.DeleteNode(values[0]));
    ASSERT_TRUE(tree.FindNode(values[0]) == NULL);

    //odstranenie vsetkych uzlov
    for (int i = 1; i < values.size(); i++) {
        EXPECT_TRUE(tree.DeleteNode(values[i]));
        ASSERT_TRUE(tree.FindNode(values[i]) == NULL);
    }

    //kontrola ci su v strome neni ziadne uzly
    std::vector<BinaryTree::Node_t *> AllLeafs;
    tree.GetAllNodes(AllLeafs);
    ASSERT_EQ(AllLeafs.size(), 0);
    ASSERT_TRUE(tree.GetRoot() == NULL);

    //odstranenie neexistujuceho uzla
    EXPECT_FALSE(tree.DeleteNode(values[0]));
}

TEST_F(NonEmptyTree, FindNode)
{
    //kontrola vsetkych uzlov
    BinaryTree::Node_t *root = tree.GetRoot(), *node;
    ASSERT_TRUE(root != NULL);
    for (int i = 0; i < values.size(); i++) {
        node = tree.FindNode(values[i]);
        ASSERT_TRUE(node != NULL);
        EXPECT_EQ(node, nodes[i].second);
    }


    //vyhladanie neexistujuceho uzla
    EXPECT_TRUE(tree.FindNode(3) == NULL);
}

TEST_F(TreeAxioms, Axiom1)
{
    // tree.InsertNode(20);
    // Node_t *fnode = tree.FindNode(20);
    // std::cout << fnode->pLeft->key << '\n';
    std::vector<BinaryTree::Node_t *> AllLeafs;
    tree.GetLeafNodes(AllLeafs);
    for(Node_t *leaf : AllLeafs){
            EXPECT_TRUE(leaf->color == BLACK);
    }
}

TEST_F(TreeAxioms, Axiom2)
{
    std::vector<BinaryTree::Node_t *> AllNonLeafs;
    tree.GetNonLeafNodes(AllNonLeafs);
    for(Node_t *nonLeaf : AllNonLeafs){
            //find red ones
            if(nonLeaf->color == RED){
                EXPECT_TRUE(nonLeaf->pRight->color == BLACK);
                EXPECT_TRUE(nonLeaf->pLeft->color == BLACK);
            }
    }

}

TEST_F(TreeAxioms, Axiom3)
{
    std::vector<BinaryTree::Node_t *> AllLeafs;
    tree.GetLeafNodes(AllLeafs);
    BinaryTree::Node_t *curNode = AllLeafs.at(0);
    int blackCount = 0, count = 0;
    //count the blacknodes from first leaf
    do{
        ASSERT_TRUE(curNode->pParent != NULL);
        curNode = curNode->pParent;
        if(curNode->color == BLACK)
            blackCount++;
    }while(curNode->pParent != tree.GetRoot());
    //count black nodes from other leafs(first too)
    for(Node_t *leaf : AllLeafs){
        curNode = leaf;
        count = 0;
        do{
            ASSERT_TRUE(curNode->pParent != NULL);
            curNode = curNode->pParent;
            if(curNode->color == BLACK)
                count++;
        }while(curNode->pParent != tree.GetRoot());
        EXPECT_EQ(blackCount, count);
    }
}
/*** Konec souboru black_box_tests.cpp ***/
