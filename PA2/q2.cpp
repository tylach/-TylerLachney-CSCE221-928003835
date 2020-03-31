#include<iostream>
#include<random>
#include"BinarySearchTree.h"

int main(){
    BinarySearchTree<int> Tree;

    Tree.insert (5);
    Tree.insert (3);
    Tree.insert (1);
    Tree.insert (4);

    //Tree.remove(3);
    Tree.remove_left(3);

//    Tree.insert (6);
//    Tree.insert (7);
//    Tree.insert (9);
//    Tree.insert (8);
    
    std::cout << "In-order:" << std::endl; 
    Tree.printTree();

    std::cout << "Pre-order:" << std::endl; 
    Tree.preorder();
	//this call the public preorder functions
	//if the tree is empty it will print "empty tree"
	//if the tree is not empty then it will (recursivly):
		//print the current node
		//then print the left subTree
		//then print the Right subTree
	

    std::cout << "Level-order:" << std::endl; 
    Tree.levelorder();

    std::cout << "max depth:" << Tree.max_depth() << std::endl; 
    std::cout << "min depth:" << Tree.min_depth() << std::endl; 
    std::cout << "diameter:" << Tree.diameter() << std::endl;

    Tree.LCA(5, 4);

    BinarySearchTree<int> Tree1;

    int range = 1e4;
    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_int_distribution<int> distribution(1, range);
	//the maximum difference is one for an AVL tree since that is the perameter of an AVL tree
	//the random tree maxes out its difference in depths at aobut 30
    for(int i=0 ; i < range; i++)
    {
        auto const r = distribution(random_engine);
        Tree1.insert (r);
    }

    for(int i=0 ; i < range; i+=5 )
    {
        auto const r = distribution(random_engine);
        Tree1.remove(r);
        Tree1.remove(r);
    }
    std::cout << "Tree1 max= " << Tree1.max_depth() ;
    std::cout << " min= " << Tree1.min_depth();
    std::cout << " diff= " << Tree1.max_depth() - Tree1.min_depth() 
        << std::endl;


    BinarySearchTree<int> Tree2;
    for(int i=0 ; i < range; i++)
    {
        auto const r = distribution(random_engine);
        Tree2.insert (r);
    }
    for(int i=0 ; i < range; i+=5 )
    {
        auto const r = distribution(random_engine);
        Tree1.remove(r);
        Tree1.remove_left(r);
    }



    std::cout << "Tree2 max= " << Tree2.max_depth() ;
    std::cout << " min= " << Tree2.min_depth();
    std::cout << " diff= " << Tree2.max_depth() - Tree2.min_depth() 
        << std::endl;

}
