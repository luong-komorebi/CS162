#pragma once

#define _WIN32_WINNT 0x0500

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include "User.h"
#include "Question.h"
#include "File.h"

void resize(int width, int height);

void gotoxy(int x, int y);

bool inputChar(char a[], char p);

bool deleteChar(char a[]);

void printUser(char a[], int x, int y);

void printPass(char a[], int x, int y);

void getPass(char passString[], int x, int y);

void getUser(char user[], int x, int y);

void createFrame();

bool logIn(userList pH, User* &p);

bool chooseType(userList head, User* cur);

bool printAdmin(userList head, User* cur);

int keyControl(int num);

void createFrameAdmin();

void logOut(userList head, User* cur);

void createFrameTeacher();

bool printTeacher(userList head, User* cur);

bool printStudent(userList head, User* cur);

void encryptPass(char a[]);