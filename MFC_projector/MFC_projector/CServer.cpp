#include"CServer.h"
#include "stdafx.h"

HANDLE     m_hPipe;//命名管道实例句柄

void OnPipeCreate()
{
	//创建命名管道
	m_hPipe = CreateNamedPipe(L"\\\\.\\pipe\\MyPipe",
		PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED, 0, 1, 1024, 1024, 0, NULL);
	if (INVALID_HANDLE_VALUE == m_hPipe)
	{
		MessageBox(0, L"创建命名管道失败！", L"", 0);
		m_hPipe = NULL;
		return;
	}

	//创建匿名的人工重置事件对象
	HANDLE hEvent;
	hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (!hEvent)
	{
		MessageBox(0, L"创建事件对象失败", L"", 0);
		CloseHandle(m_hPipe);
		m_hPipe = NULL;
		return;
	}

	OVERLAPPED ovlap;
	ZeroMemory(&ovlap, sizeof(OVERLAPPED));
	ovlap.hEvent = hEvent;

	//等待客户端请求的到来
	if (!ConnectNamedPipe(m_hPipe, &ovlap))
	{
		if (ERROR_IO_PENDING != GetLastError())
		{
			MessageBox(0, L"等待客户端连接失败！", L"", 0);
			CloseHandle(m_hPipe);
			CloseHandle(hEvent);
			m_hPipe = NULL;
			return;
		}
	}
	if (WAIT_FAILED == WaitForSingleObject(hEvent, INFINITE))
	{
		MessageBox(0, L"等待事件对象失败！", L"", 0);
		CloseHandle(m_hPipe);
		CloseHandle(hEvent);
		m_hPipe = NULL;
		return;
	}

	CloseHandle(hEvent);//执行到这一步，说明已经有客户端连上命名管道实例，不再需要该事件对象句柄

}


CString OnPipeRead()
{
	wchar_t buf[100] = { 0 };
	DWORD dwRead;
	if (!ReadFile(m_hPipe, buf, 100, &dwRead, NULL))
	{
		//MessageBox(0, L"读取数据失败！", L"", 0);
		return L"";
	}
	//MessageBox(0, buf, L"", 0);
	wprintf(L"%s", buf);
	return buf;
}


void OnPipeWrite(CString mystr)
{
	//wchar_t buf[] = L"abcdefghijk";
	//printf("%d", wcslen(mystr) + 1);
	DWORD dwWrite;
	if (!WriteFile(m_hPipe, mystr, mystr.GetLength()*2+2, &dwWrite, NULL))
	{
		MessageBox(0, L"写入数据失败！", L"", 0);
		return;
	}
}