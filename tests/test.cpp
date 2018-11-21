#include <iostream>
#include <stdio.h>
#include <string>
#include "../src/client.h"
#include <vector>
#include "gtest/gtest.h"


using namespace std;

//INPUTS=("ls" "abc" "date")
 
TEST(command, test1) {
   	string temp = "date";	

	char* temp2 = new char[temp.length() + 1];
	strcpy(temp2,temp.c_str());

	Command* test1 = new Command(temp2);

	EXPECT_EQ(1, test1->run());
}

TEST(command, test2) {
	string temp = "ls";

	char* temp2 = new char[temp.length() + 1];
	strcpy(temp2,temp.c_str());

	Command* test1 = new Command(temp2);

	EXPECT_EQ(1, test1->run());
}

TEST(command, test3) {
	string temp = "abc";

	char* temp2 = new char[temp.length() + 1];
	strcpy(temp2,temp.c_str());

	Command* test1 = new Command(temp2);

	EXPECT_EQ(0, test1->run());
}

TEST(command, test4) {
	string temp = "&*^";

	char* temp2 = new char[temp.length() + 1];
	strcpy(temp2,temp.c_str());

	Command* test1 = new Command(temp2);

	EXPECT_EQ(0, test1->run());
}

TEST(command, test5) {
	
	
	string temp = "echo hello";

	char* temp2 = new char[temp.length() + 1];
	strcpy(temp2,temp.c_str());

	Command* test1 = new Command(temp2);
	
	testing::internal::CaptureStdout();

	test1->run();

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("hello\n", output);
}

TEST(command, test6) {


	string temp = "echo world";

	char* temp2 = new char[temp.length() + 1];
	strcpy(temp2,temp.c_str());

	Command* test1 = new Command(temp2);

	testing::internal::CaptureStdout();

	test1->run();

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("world\n", output);
}

TEST(client, OrTest1) {


	testing::internal::CaptureStdout();

	Client* client = new Client("john || echo sam");
	client->createTree();
	client->runTheCommand();

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("sam\n", output);
}

TEST(client, OrTest2) {


	testing::internal::CaptureStdout();

	Client* client = new Client("echo john || echo sam");
	client->createTree();
	client->runTheCommand();

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("john\n", output);
}

TEST(client, AndTest1) {


	testing::internal::CaptureStdout();

	Client* client = new Client("echo john && echo sam");
	client->createTree();
	client->runTheCommand();

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("john\nsam\n", output);
}

TEST(client, AndTest2) {


	testing::internal::CaptureStdout();

	Client* client = new Client("john && echo sam");
	client->createTree();
	client->runTheCommand();

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("", output);
}

TEST(client, AllTest1) {


	testing::internal::CaptureStdout();

	Client* client = new Client("echo john; echo sam");
	client->createTree();
	client->runTheCommand();

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("john\nsam\n", output);
}

TEST(client, AllTest2) {


	testing::internal::CaptureStdout();

	Client* client = new Client("john; echo sam");
	client->createTree();
	client->runTheCommand();

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ("sam\n", output);
}

int main(int argc, char **argv) {
	  ::testing::InitGoogleTest(&argc, argv);
	    return RUN_ALL_TESTS();
}
