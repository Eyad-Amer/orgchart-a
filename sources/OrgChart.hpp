/**
 * Heading for OrgChart function
 * 
 * Author: Eyad Amer
 * Since : 2022-05
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

//class Heading 
namespace ariel{

    class Node{

        private:
            string nodeName; // node name
            Node *next; // next node
            //vector<Node*> nodes; // vector of nodes

        public:
            Node(); // Default Constructor
            Node(const string &node); // Parameterized Constructor 
            string get_nameNode(); // get name
            void set_nameNode(string &name); // set name
    }; // class Node


    class OrgChart{

        private:
            Node *root; // create root node
            vector<string> preorder; // vector of the names in preorder print.
            vector<string> result; // vector of the result of the names in the organizational table.

        public: 

            OrgChart(); // Default Constructor
            ~OrgChart(); // Default Destructor.
            OrgChart &add_root(const string root); // Add a new root to an organizational table.
            OrgChart &add_sub(string parent, string child); // Add a child to a leaf that already exists in an organizational table.
            string *begin_level_order(); // Returns iterators for transit, in order: parent -> child -> child -> grandchild.
            string *end_level_order(); // Returns iterators for transit, in order: parent -> child -> child -> grandchild.
            string *begin_reverse_order(); // Returns iterators for transit, in order: grandchild -> child -> parent.
            string *end_reverse_order(); // Returns iterators for transit, in order: grandchild -> grandchild -> child -> child -> parent.
            string *begin_preorder(); // Returns iterators for transit, in order: parent -> child -> grandchild -> child -> grandchild.
            string *end_preorder(); // Returns iterators for transit, in order: parent -> child -> grandchild -> child -> grandchild.
            string *begin(); // Returns begin_level_order() function => to "for (auto element : organization)" loop.
            string *end(); // Returns end_level_order() function => to "for (auto element : organization)" loop.
            friend std::ostream &operator<<(std::ostream &output, const OrgChart &other); // output operator that print the organizational table.
    }; // class OrgChart
} // namespace ariel