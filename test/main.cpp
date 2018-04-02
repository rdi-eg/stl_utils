#define CATCH_CONFIG_MAIN
#include<catch.hpp>
#include<bits/stdc++.h>
#include<rdi_stl_utils.h>
#include<vector>
#include<string>
using namespace std ;
using namespace RDI ;
TEST_CASE("split test","English String")
{
	SECTION("normal input")
	{
	string input = " aaa b c  d   s_sa";
	vector<string> correct_result = {"aaa","b","c","d","s_sa"};
	vector<string> expected_result = split(input,' ');
	CHECK(correct_result==expected_result);
	}
	SECTION("one split")
	{
	string input = "aaacds_sa";
	vector<string> correct_result = {"aaacds_sa"};
	vector<string> expected_result = split(input,' ');
	CHECK(correct_result==expected_result);
	}
	SECTION("empty")
	{
	string input = "	";
	vector<string> correct_result = {"	"};
	vector<string> expected_result = split(input,' ');
	CHECK(correct_result==expected_result);
	}
	SECTION("x delimiter")
	{
	string input = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	vector<string> correct_result = {};
	vector<string> expected_result = split(input,'x');
	CHECK(correct_result==expected_result);
	}
}
TEST_CASE("split test","Arabic String")
{
	SECTION("normal input")
	{
	string input = " aaa b c  d   s_sa";
	vector<string> correct_result = {"aaa","b","c","d","s_sa"};
	vector<string> expected_result = split(input,' ');
	CHECK(correct_result==expected_result);
	}
	SECTION("one split")
	{
	string input = "aaacds_sa";
	vector<string> correct_result = {"aaacds_sa"};
	vector<string> expected_result = split(input,' ');
	CHECK(correct_result==expected_result);
	}
	SECTION("empty")
	{
	string input = "	";
	vector<string> correct_result = {"	"};
	vector<string> expected_result = split(input,' ');
	CHECK(correct_result==expected_result);
	}
	SECTION("x delimiter")
	{
	string input = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	vector<string> correct_result = {};
	vector<string> expected_result = split(input,'x');
	CHECK(correct_result==expected_result);
	}
}
