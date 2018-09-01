#pragma once
#include"stdafx.h"
#include<Windows.h>


void OnPipeCreate();
CString OnPipeRead();
void OnPipeWrite(CString mystr);