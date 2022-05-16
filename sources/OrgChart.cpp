/**
 * Implementation of the OrgChart functions
 *
 * Author: Eyad Amer
 * Since : 2022-05
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "OrgChart.hpp"

using namespace std;

namespace ariel
{

    // Default Constructor
    OrgChart::OrgChart()
    {
    }

    // Default Destructor.
    OrgChart::~OrgChart()
    {
    }

    // Add a new root to an organizational table.
    OrgChart &OrgChart::add_root(const string root)
    {
        return *this;
    }

    // Add a child to a leaf that already exists in an organizational table.
    OrgChart &OrgChart::add_sub(string parent, string child)
    {
        return *this;
    }

    // Returns iterators for transit, in order: parent -> child -> child -> grandchild.
    string *OrgChart::begin_level_order()
    {
         return &(this->result[0]);
        
    }

    // Returns iterators for transit, in order: parent -> child -> child -> grandchild.
    string *OrgChart::end_level_order()
    {
        return &(this->result[0]);
    }

    // Returns iterators for transit, in order: grandchild -> child -> parent.
    string *OrgChart::begin_reverse_order()
    {
        return &(this->result[0]);
    }

    // Returns iterators for transit, in order: grandchild -> grandchild -> child -> child -> parent.
    string *OrgChart::end_reverse_order()
    {
        return &(this->preorder[0]);
    }

    // Returns iterators for transit, in order: parent -> child -> grandchild -> child -> grandchild.
    string *OrgChart::begin_preorder()
    {
        return &(this->result[0]);
    }

    // Returns iterators for transit, in order: parent -> child -> grandchild -> child -> grandchild.
    string *OrgChart::end_preorder()
    {
        return &(this->result[0]);
    }

    // Returns begin_level_order() function => to "for (auto element : organization)" loop.
    string *OrgChart::begin()
    {
        return begin_level_order();
    }

    // Returns end_level_order() function => to "for (auto element : organization)" loop.
    string *OrgChart::end()
    {
        return end_level_order();
    }

    // output operator that print the organizational table.
    std::ostream &operator<<(std::ostream &output, const OrgChart &other)
    {
        return output;
    }

    // Default Constructor
    Node::Node()
    {
        nodeName = "";
        next = NULL;
    }

    // Parameterized Constructor
    Node::Node(const string &node)
    {
        this->nodeName = node;
        this->next = NULL;
    }

    // get name node
    string Node::get_nameNode()
    {
        return this->nodeName;
    }

    // set name node
    void Node::set_nameNode(string &name)
    {
        this->nodeName = name;
    }
}