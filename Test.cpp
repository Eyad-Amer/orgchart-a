/**
 * Unit tests.
 *
 * AUTHORS: Eyad Amer
 * Date:  2022-05
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

#include "doctest.h"
#include "OrgChart.hpp"

using namespace std;
using namespace ariel;

// Good inputs and results
TEST_CASE("Good input")
{
  OrgChart organization;
  size_t i = 0;

  CHECK_NOTHROW(organization.add_root("CEO"));
  CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
  CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
  CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
  CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
  CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));

  vector<string> result1 = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};

  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it, ++i)
  {
    CHECK(result1.at(i).compare(*it) == 0);
  }

  for (auto it = organization.end_reverse_order(); it != organization.begin_reverse_order(); --it, ++i)
  {
    CHECK(result1.at(i).compare(*it) == 0);
  }

  vector<string> result2 = {"CEO","CTO","VP_SW","CFO","COO","VP_BI"};

  for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it, ++i) {
    CHECK(result2.at(i).compare(*it) == 0);
  }

  for (auto element : organization)
  { 
    CHECK(result1.at(i++).compare(element) == 0);
  }

  vector<string> result3 = {"3", "3", "3", "3", "5", "5"};

  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it, ++i)
  {
    CHECK(result3.at(i).compare(*it) == 0);
  }

  CHECK_NOTHROW(organization.add_root("Eyad Amer"));
  CHECK_NOTHROW(organization.add_sub("Eyad Amer", "1"));
  CHECK_NOTHROW(organization.add_sub("Eyad Amer", "2"));
  CHECK_NOTHROW(organization.add_sub("Eyad Amer", "3"));
  CHECK_NOTHROW(organization.add_sub("Eyad Amer", "4"));
  CHECK_NOTHROW(organization.add_sub("Eyad Amer", "5"));
  CHECK_NOTHROW(organization.add_root("0"));
}

// wrong results
TEST_CASE("Bad input - wrong results")
{
  OrgChart organization;
  size_t i = 0;

  CHECK_NOTHROW(organization.add_root("CEO"));
  CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
  CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
  CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
  CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
  CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));

  vector<string> result1 = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};

  CHECK_EQ(result1.at(0),"CFO");
  CHECK_EQ(result1.at(1),"CFO");
  CHECK_EQ(result1.at(3),"CFO");
  CHECK_EQ(result1.at(4),"CFO");
  CHECK_EQ(result1.at(5),"CFO");

  CHECK_NOTHROW(organization.add_root("Eyad Amer"));
  CHECK_EQ(result1.at(0),"Eyad?");
  CHECK_EQ(result1.at(0),"Amer?");

}
