#define CATCH_CONFIG_MAIN
#include<catch.hpp>
#include<bits/stdc++.h>
#include<rdi_stl_utils.h>
#include<vector>
#include<string>
using namespace std ;
using namespace RDI ;

TEST_CASE("English String","split test")
{
	SECTION("multi tokens")
	{
		string input = " aaa b c  d   s_sa";
		vector<string> correct_result = {"aaa","b","c","d","s_sa"};
		vector<string> expected_result = split(input,' ');
		CHECK(correct_result==expected_result);
	}
	SECTION("one token")
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

TEST_CASE("Arabic String","split test")
{
	SECTION("multi tokens #space")
	{
		wstring input = L" الحب الذى كان بينانا ";
		vector<wstring> correct_result = {L"الحب"
										  ,L"الذى",
										  L"كان"
										  ,L"بينانا"
										 };
		wchar_t d =L' ';
		vector<wstring> expected_result = split(input,d);
		CHECK(correct_result==expected_result);
	}
	SECTION("multi tokens #ح")
	{
		wstring input = L"الحب الذى كان بينانا";
		vector<wstring> correct_result = {L"ال",
										  L"ب الذى كان بينانا"
										 };
		wchar_t d =L'ح';
		vector<wstring> expected_result = split(input,d);
		CHECK(correct_result==expected_result);
	}
	SECTION("one token")
	{
		wstring input = L" الحب الذى كان بينانا ";
		vector<wstring> correct_result = { L" الحب الذى كان بينانا "};
		wchar_t d =L'ش';
		vector<wstring> expected_result = split(input,d);
		CHECK(correct_result==expected_result);
	}
	SECTION("empty")
	{
		wstring input = L"";
		vector<wstring> correct_result = { };
		wchar_t d =L'	';
		vector<wstring> expected_result = split(input,d);
		CHECK(correct_result==expected_result);
	}
	SECTION("س delimiter")
	{
		wstring input = L"سسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسسس";
		vector<wstring> correct_result = {};
		wchar_t d =L'س';
		vector<wstring> expected_result = split(input,d);
		CHECK(correct_result==expected_result);
	}
}


TEST_CASE("intger vector","concat_vectors test")
{
	SECTION("2 full vector")
	{
		vector<int> V1= {1,2,3,4,5};
		vector<int> V2= {6,7,8,9,10};
		vector<int> V3= RDI::concat_vectors(V1,V2);
		vector<int> V3_correct= {1,2,3,4,5,6,7,8,9,10};
		CHECK(V3==V3_correct);
	}
	SECTION("1  empty vector")
	{
		vector<int> V1= {};
		vector<int> V2= {6,7,8,9,10};
		vector<int> V3= RDI::concat_vectors(V1,V2);
		vector<int> V3_correct= {6,7,8,9,10};
		CHECK(V3==V3_correct);
	}
	SECTION("2 empty vector")
	{
		vector<int> V1= {};
		vector<int> V2= {};
		vector<int> V3= RDI::concat_vectors(V1,V2);
		vector<int> V3_correct= {};
		CHECK(V3==V3_correct);
	}
	/*SECTION("diffrent types")
	{
		vector<float> V1= {1.0f,2.0f,3.0f,4.0f,5.0f};
		vector<int> V2= {6,7,8,9,10};
		vector<float> V3= RDI::concat_vectors(V1,V2);
		vector<float> V3_correct= {1.0f,2.0f,3.0f,4.0f,5.0f,6,7,8,9,10};
		CHECK(V3==V3_correct);
	}*/
}

TEST_CASE("string vector","concat_vectors test")
{
	SECTION("2 full vector")
	{
		vector<string> V1= {"hi","my","name","is","islam"};
		vector<string> V2= {"who","are","***","T","F"};
		vector<string> V3= RDI::concat_vectors(V1,V2);
		vector<string> V3_correct= {"hi","my","name","is","islam","who","are","***","T","F"};
		CHECK(V3==V3_correct);
	}
	SECTION("1 empty vector")
	{
		vector<string> V1= {};
		vector<string> V2= {"who","are","***","T","F"};
		vector<string> V3= RDI::concat_vectors(V1,V2);
		vector<string> V3_correct= {"who","are","***","T","F"};
		CHECK(V3==V3_correct);
	}
	SECTION("2 empty vector")
	{
		vector<string> V1= {};
		vector<string> V2= {};
		vector<string> V3= RDI::concat_vectors(V1,V2);
		vector<string> V3_correct= {};
		CHECK(V3==V3_correct);
	}
}

TEST_CASE("within_vector")
{
	SECTION("Found")
	{
		vector<int> V= {1,2,3,4,5};
		int key = 2;
		bool res  = RDI::within_vector(key,V);
		CHECK(res == true);
	}
	SECTION("Not found")
	{
		vector<int> V= {1,2,3,4,5};
		int key = 10;
		bool res  = RDI::within_vector(key,V);
		CHECK(res == false);
	}
}
TEST_CASE("remove_spaces")
{
	string str = "islam magdy saieed" ;
	string result_correct = "islammagdysaieed";
	string result = remove_spaces(str);
	CHECK(result_correct == result);
}
