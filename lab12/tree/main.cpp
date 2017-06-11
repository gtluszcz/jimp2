#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

using namespace tree;
using namespace std;

/**
 * Tests are, again, broken for me and I cannot seem to go around the SIGSEGV
 * error. I have literarily copied tests into this main() function and tweaked
 * them not to use Google's test suite. Everything works as expected.
 * Everything works if output contains only '1's, and no '0's.
 */

class DummyTreeDataType {
public:
    bool operator<(const DummyTreeDataType &other) const {
        return true;
    }
};

int main() {
    /**
     * CanCreateTreeOfInts
     */
    Tree<int> tree1;

    /**
     * CanCreateTreeOfDoubles
     */
    Tree<double> tree2;

    /**
     * CanCreateTreeOfArbitraryType
     */
    Tree<DummyTreeDataType> tree3;

    /**
     * CanInsertSingleValueIntoTree
     */
    Tree<int> tree4 {5};
    cout << (5 == tree4.Value());
    cout << (1 == tree4.Size());
    cout << (1 == tree4.Depth());

    /**
     * CanInsertMoreValuesIntoTree
     */
    Tree<int> tree5 {5};

    cout << (5 == tree5.Value());
    cout << (1 == tree5.Size());
    cout << (1 == tree5.Depth());
    tree5.Insert(0);

    cout << (5 == tree5.Value());
    cout << (2 == tree5.Size());
    cout << (2 == tree5.Depth());
    tree5.Insert(102);

    cout << (5 == tree5.Value());
    cout << (3 == tree5.Size());
    cout << (2 == tree5.Depth());
    tree5.Insert(890);

    cout << (5 == tree5.Value());
    cout << (4 == tree5.Size());
    cout << (3 == tree5.Depth());
    tree5.Insert(81);

    cout << (5 == tree5.Value());
    cout << (5 == tree5.Size());
    cout << (3 == tree5.Depth());
    tree5.Insert(-1);

    cout << (5 == tree5.Value());
    cout << (6 == tree5.Size());
    cout << (3 == tree5.Depth());

    /**
     * Preorder, Inorder and Postorder tests
     */

    cout << (vector<int>{5, 0, -1, 102, 81, 890} == PreOrder(&tree5));
    cout << (vector<int>{0, -1, 5, 102, 81, 890} == InOrder(&tree5));
    cout << (vector<int>{0, -1, 102, 81, 890, 5} == PostOrder(&tree5));

    /**
     * Preorder, Inorder and Postorder manual verification (conforming with the exercise's description):
     */

    cout << endl;

    cout << endl << "PreOrder: " << endl;
    tree5.PrintPreorder();
    cout << "<> ";
    for (const int & value_in_tree : PreOrder(&tree5)) {
        cout << value_in_tree << " ";
    }

    cout << endl << "InOrder: " << endl;
    tree5.PrintInorder();
    cout << "<> ";
    for (const int & value_in_tree : InOrder(&tree5)) {
        cout << value_in_tree << " ";
    }

    cout << endl << "PostOrder: " << endl;
    tree5.PrintPostorder();
    cout << "<> ";
    for (const int & value_in_tree : PostOrder(&tree5)) {
        cout << value_in_tree << " ";
    }

    cout << endl;
}
