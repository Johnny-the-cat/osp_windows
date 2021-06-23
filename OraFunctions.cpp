#include "pch.h"
#include <stdio.h>
#include <windows.h>
#include "oci.h"
#include "oratypes.h"
#include "orl.h"
#include "ocipfndfn.h"



pOCIEnvCreate OCIEnvCreate;

pOCIEnvNlsCreate OCIEnvNlsCreate;

pOCITerminate OCITerminate;

pOCIHandleAlloc OCIHandleAlloc;

pOCIServerAttach OCIServerAttach;

pOCIAttrSet OCIAttrSet;

pOCISessionBegin OCISessionBegin;

pOCISessionEnd OCISessionEnd;

pOCIStmtPrepare OCIStmtPrepare;

pOCIDefineByPos OCIDefineByPos;

pOCIStmtExecute OCIStmtExecute;

pOCIBindByName OCIBindByName;

pOCIBindByPos OCIBindByPos;

pOCITransCommit OCITransCommit;

pOCIHandleFree OCIHandleFree;

pOCIServerDetach OCIServerDetach;

pOCIStmtFetch2 OCIStmtFetch2;

pOCIErrorGet OCIErrorGet;

pOCIRawAllocSize OCIRawAllocSize;

pOCIRawAssignBytes OCIRawAssignBytes;

pOCILobFileSetName OCILobFileSetName;

pOCIDescriptorAlloc OCIDescriptorAlloc;

pOCIDescriptorFree OCIDescriptorFree;

pOCILobFileOpen OCILobFileOpen;

pOCILobFileClose OCILobFileClose;

pOCILobGetLength2 OCILobGetLength2;

pOCILobRead2 OCILobRead2;

pOCILobFileExists OCILobFileExists;


/*Функция получает адреса нужных процедур и функций из oci.dll*/
BOOL LoadOciFunctions(HMODULE hOCIDll)
{
	//printf("Loading procedure and functions from oci.dll library...\n");
	//printf("Pointer to OCIEnvCreate before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIEnvCreate, (unsigned __int64)OCIEnvCreate);
	OCIEnvCreate = (pOCIEnvCreate)GetProcAddress(hOCIDll,
		"OCIEnvCreate");
	if (OCIEnvCreate == NULL) {
		printf("LoadOciFunctions: can't load OCIEnvCreate\n");
		return FALSE;
	}
	//printf("Pointer to OCIEnvCreate after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIEnvCreate, (unsigned __int64)OCIEnvCreate);


	//printf("Pointer to OCIEnvNlsCreate before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIEnvNlsCreate, (unsigned __int64)OCIEnvNlsCreate);
	OCIEnvNlsCreate = (pOCIEnvNlsCreate)GetProcAddress(hOCIDll,
		"OCIEnvNlsCreate");
	if (OCIEnvNlsCreate == NULL) {
		printf("LoadOciFunctions: can't load OCIEnvNlsCreate\n");
		return FALSE;
	}
	//printf("Pointer to OCIEnvNlsCreatee after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIEnvNlsCreate, (unsigned __int64)OCIEnvNlsCreate);


	//printf("Pointer to OCITerminate before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCITerminate, (unsigned __int64)OCITerminate);
	OCITerminate = (pOCITerminate)GetProcAddress(hOCIDll,
		"OCITerminate");
	if (OCITerminate == NULL) {
		printf("LoadOciFunctions: can't load OCITerminate\n");
		return FALSE;
	}
	//printf("Pointer to OCITerminate after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCITerminate, (unsigned __int64)OCITerminate);


	//printf("Pointer to OCIHandleAlloc before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIHandleAlloc, (unsigned __int64)OCIHandleAlloc);
	OCIHandleAlloc = (pOCIHandleAlloc)GetProcAddress(hOCIDll,
		"OCIHandleAlloc");
	if (OCIHandleAlloc == NULL) {
		printf("LoadOciFunctions: can't load OCIHandleAlloc\n");
		return FALSE;
	}
	//printf("Pointer to OCIHandleAlloc after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIHandleAlloc, (unsigned __int64)OCIHandleAlloc);


	//printf("Pointer to OCIServerAttach before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIServerAttach, (unsigned __int64)OCIServerAttach);
	OCIServerAttach = (pOCIServerAttach)GetProcAddress(hOCIDll,
		"OCIServerAttach");
	if (OCIServerAttach == NULL) {
		printf("LoadOciFunctions: can't load OCIServerAttach\n");
		return FALSE;
	}
	//printf("Pointer to OCIServerAttach after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIServerAttach, (unsigned __int64)OCIServerAttach);

	//printf("Pointer to OCIAttrSet before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIAttrSet, (unsigned __int64)OCIAttrSet);
	OCIAttrSet = (pOCIAttrSet)GetProcAddress(hOCIDll,
		"OCIAttrSet");
	if (OCIAttrSet == NULL) {
		printf("LoadOciFunctions: can't load OCIAttrSet\n");
		return FALSE;
	}
	//printf("Pointer to OCIAttrSet after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIAttrSet, (unsigned __int64)OCIAttrSet);

	//printf("Pointer to OCISessionBegin before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCISessionBegin, (unsigned __int64)OCISessionBegin);
	OCISessionBegin = (pOCISessionBegin)GetProcAddress(hOCIDll,
		"OCISessionBegin");
	if (OCISessionBegin == NULL) {
		printf("LoadOciFunctions: can't load OCISessionBegin\n");
		return FALSE;
	}
	//printf("Pointer to OCISessionBegin after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCISessionBegin, (unsigned __int64)OCISessionBegin);


	//printf("Pointer to OCISessionEnd before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCISessionEnd, (unsigned __int64)OCISessionEnd);
	OCISessionEnd = (pOCISessionEnd)GetProcAddress(hOCIDll,
		"OCISessionEnd");
	if (OCISessionEnd == NULL) {
		printf("LoadOciFunctions: can't load OCISessionEnd\n");
		return FALSE;
	}
	//printf("Pointer to OCISessionEnd after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCISessionEnd, (unsigned __int64)OCISessionEnd);


	//printf("Pointer to OCIStmtPrepare before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIStmtPrepare, (unsigned __int64)OCIStmtPrepare);
	OCIStmtPrepare = (pOCIStmtPrepare)GetProcAddress(hOCIDll,
		"OCIStmtPrepare");
	if (OCIStmtPrepare == NULL) {
		printf("LoadOciFunctions: can't load OCIStmtPrepare\n");
		return FALSE;
	}
	//printf("Pointer to OCIStmtPrepare after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIStmtPrepare, (unsigned __int64)OCIStmtPrepare);

	//printf("Pointer to OCIDefineByPos before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIDefineByPos, (unsigned __int64)OCIDefineByPos);
	OCIDefineByPos = (pOCIDefineByPos)GetProcAddress(hOCIDll,
		"OCIDefineByPos");
	if (OCIDefineByPos == NULL) {
		printf("LoadOciFunctions: can't load OCIDefineByPos\n");
		return FALSE;
	}
	//printf("Pointer to OCIDefineByPos after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIDefineByPos, (unsigned __int64)OCIDefineByPos);

	//printf("Pointer to OCIStmtExecute before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIStmtExecute, (unsigned __int64)OCIStmtExecute);
	OCIStmtExecute = (pOCIStmtExecute)GetProcAddress(hOCIDll,
		"OCIStmtExecute");
	if (OCIStmtExecute == NULL) {
		printf("LoadOciFunctions: can't load OCIStmtExecute\n");
		return FALSE;
	}
	//printf("Pointer to OCIStmtExecute after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIStmtExecute, (unsigned __int64)OCIStmtExecute);

	//printf("Pointer to OCIBindByName before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIBindByName, (unsigned __int64)OCIBindByName);
	OCIBindByName = (pOCIBindByName)GetProcAddress(hOCIDll,
		"OCIBindByName");
	if (OCIBindByName == NULL) {
		printf("LoadOciFunctions: can't load OCIBindByName\n");
		return FALSE;
	}
	//printf("Pointer to OCIBindByName after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIBindByName, (unsigned __int64)OCIBindByName);

	//printf("Pointer to OCIBindByPos before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIBindByPos, (unsigned __int64)OCIBindByPos);
	OCIBindByPos = (pOCIBindByPos)GetProcAddress(hOCIDll,
		"OCIBindByPos");
	if (OCIBindByPos == NULL) {
		printf("LoadOciFunctions: can't load OCIBindByPos\n");
		return FALSE;
	}
	//printf("Pointer to OCIBindByPos after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIBindByPos, (unsigned __int64)OCIBindByPos);

	//printf("Pointer to OCITransCommit before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCITransCommit, (unsigned __int64)OCITransCommit);
	OCITransCommit = (pOCITransCommit)GetProcAddress(hOCIDll,
		"OCITransCommit");
	if (OCITransCommit == NULL) {
		printf("LoadOciFunctions: can't load OCITransCommit\n");
		return FALSE;
	}
	//printf("Pointer to OCITransCommit after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCITransCommit, (unsigned __int64)OCITransCommit);

	//printf("Pointer to OCIHandleFree before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIHandleFree, (unsigned __int64)OCIHandleFree);
	OCIHandleFree = (pOCIHandleFree)GetProcAddress(hOCIDll,
		"OCIHandleFree");
	if (OCIHandleFree == NULL) {
		printf("LoadOciFunctions: can't load OCIHandleFree\n");
		return FALSE;
	}
	//printf("Pointer to OCIHandleFree after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIHandleFree, (unsigned __int64)OCIHandleFree);

	//printf("Pointer to OCIServerDetach before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIServerDetach, (unsigned __int64)OCIServerDetach);
	OCIServerDetach = (pOCIServerDetach)GetProcAddress(hOCIDll,
		"OCIServerDetach");
	if (OCIServerDetach == NULL) {
		printf("LoadOciFunctions: can't load OCIServerDetach\n");
		return FALSE;
	}
	//printf("Pointer to OCIServerDetach after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIServerDetach, (unsigned __int64)OCIServerDetach);

	//printf("Pointer to OCIStmtFetch2 before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIStmtFetch2, (unsigned __int64)OCIStmtFetch2);
	OCIStmtFetch2 = (pOCIStmtFetch2)GetProcAddress(hOCIDll,
		"OCIStmtFetch2");
	if (OCIStmtFetch2 == NULL) {
		printf("LoadOciFunctions: can't load OCIStmtFetch2\n");
		return FALSE;
	}
	//printf("Pointer to OCIStmtFetch2 after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIStmtFetch2, (unsigned __int64)OCIStmtFetch2);

	//printf("Pointer to OCIErrorGet before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIErrorGet, (unsigned __int64)OCIErrorGet);
	OCIErrorGet = (pOCIErrorGet)GetProcAddress(hOCIDll,
		"OCIErrorGet");
	if (OCIErrorGet == NULL) {
		printf("LoadOciFunctions: can't load OCIErrorGet\n");
		return FALSE;
	}
	//printf("Pointer to OCIErrorGet after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIErrorGet, (unsigned __int64)OCIErrorGet);

	//printf("Pointer to OCIRawAllocSize before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIRawAllocSize, (unsigned __int64)OCIRawAllocSize);
	OCIRawAllocSize = (pOCIRawAllocSize)GetProcAddress(hOCIDll,
		"OCIRawAllocSize");
	if (OCIRawAllocSize == NULL) {
		printf("LoadOciFunctions: can't load OCIRawAllocSize\n");
		return FALSE;
	}
	//printf("Pointer to OCIRawAllocSize after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIRawAllocSize, (unsigned __int64)OCIRawAllocSize);

	//printf("Pointer to OCIRawAssignBytes before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIRawAssignBytes, (unsigned __int64)OCIRawAssignBytes);
	OCIRawAssignBytes = (pOCIRawAssignBytes)GetProcAddress(hOCIDll,
		"OCIRawAssignBytes");
	if (OCIRawAssignBytes == NULL) {
		printf("LoadOciFunctions: can't load OCIRawAssignBytes\n");
		return FALSE;
	}
	//printf("Pointer to OCIRawAssignBytes after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIRawAssignBytes, (unsigned __int64)OCIRawAssignBytes);

	//printf("Pointer to OCILobFileSetName before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobFileSetName, (unsigned __int64)OCILobFileSetName);
	OCILobFileSetName = (pOCILobFileSetName)GetProcAddress(hOCIDll,
		"OCILobFileSetName");
	if (OCILobFileSetName == NULL) {
		printf("LoadOciFunctions: can't load OCILobFileSetName\n");
		return FALSE;
	}
	//printf("Pointer to OCILobFileSetName after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobFileSetName, (unsigned __int64)OCILobFileSetName);

	//printf("Pointer to OCIDescriptorAlloc before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIDescriptorAlloc, (unsigned __int64)OCIDescriptorAlloc);
	OCIDescriptorAlloc = (pOCIDescriptorAlloc)GetProcAddress(hOCIDll,
		"OCIDescriptorAlloc");
	if (OCIDescriptorAlloc == NULL) {
		printf("LoadOciFunctions: can't load OCIDescriptorAlloc\n");
		return FALSE;
	}
	//printf("Pointer to OCIDescriptorAlloc after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIDescriptorAlloc, (unsigned __int64)OCIDescriptorAlloc);

	//printf("Pointer to OCIDescriptorFree before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIDescriptorFree, (unsigned __int64)OCIDescriptorFree);
	OCIDescriptorFree = (pOCIDescriptorFree)GetProcAddress(hOCIDll,
		"OCIDescriptorFree");
	if (OCIDescriptorFree == NULL) {
		printf("LoadOciFunctions: can't load OCIDescriptorFree\n");
		return FALSE;
	}
	//printf("Pointer to OCIDescriptorFree after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCIDescriptorFree, (unsigned __int64)OCIDescriptorFree);

	//printf("Pointer to OCILobFileOpen before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobFileOpen, (unsigned __int64)OCILobFileOpen);
	OCILobFileOpen = (pOCILobFileOpen)GetProcAddress(hOCIDll,
		"OCILobFileOpen");
	if (OCILobFileOpen == NULL) {
		printf("LoadOciFunctions: can't load OCILobFileOpen\n");
		return FALSE;
	}
	//printf("Pointer to OCILobFileOpen after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobFileOpen, (unsigned __int64)OCILobFileOpen);

	//printf("Pointer to OCILobFileClose before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobFileClose, (unsigned __int64)OCILobFileClose);
	OCILobFileClose = (pOCILobFileClose)GetProcAddress(hOCIDll,
		"OCILobFileClose");
	if (OCILobFileClose == NULL) {
		printf("LoadOciFunctions: can't load OCILobFileClose\n");
		return FALSE;
	}
	//printf("Pointer to OCILobFileClose after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobFileClose, (unsigned __int64)OCILobFileClose);

	//printf("Pointer to OCILobGetLength2 before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobGetLength2, (unsigned __int64)OCILobGetLength2);
	OCILobGetLength2 = (pOCILobGetLength2)GetProcAddress(hOCIDll,
		"OCILobGetLength2");
	if (OCILobGetLength2 == NULL) {
		printf("LoadOciFunctions: can't load OCILobGetLength2\n");
		return FALSE;
	}
	//printf("Pointer to OCILobGetLength2 after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobGetLength2, (unsigned __int64)OCILobGetLength2);

	//printf("Pointer to OCILobRead2 before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobRead2, (unsigned __int64)OCILobRead2);
	OCILobRead2 = (pOCILobRead2)GetProcAddress(hOCIDll,
		"OCILobRead2");
	if (OCILobRead2 == NULL) {
		printf("LoadOciFunctions: can't load OCILobRead2\n");
		return FALSE;
	}
	//printf("Pointer to OCILobRead2 after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobRead2, (unsigned __int64)OCILobRead2);

	//printf("Pointer to OCILobFileExists before GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobFileExists, (unsigned __int64)OCILobFileExists);
	OCILobFileExists = (pOCILobFileExists)GetProcAddress(hOCIDll,
		"OCILobFileExists");
	if (OCILobFileExists == NULL) {
		printf("LoadOciFunctions: can't load OCILobFileExists\n");
		return FALSE;
	}
	//printf("Pointer to OCILobFileExists after GetProcAddress is %llX(%llu)\n", (unsigned __int64)OCILobFileExists, (unsigned __int64)OCILobFileExists);

	return TRUE;
}

void checkerr(OCIError *errhp, sword status)
{
	text errbuf[512];
	sb4 errcode = 0;

	switch (status)
	{
	case OCI_SUCCESS:
		//(void)printf("OCI_SUCCESS\n");
		break;
	case OCI_SUCCESS_WITH_INFO:
		(void)printf("Error - OCI_SUCCESS_WITH_INFO\n");
		break;
	case OCI_NEED_DATA:
		(void)printf("Error - OCI_NEED_DATA\n");
		break;
	case OCI_NO_DATA:
		(void)printf("Error - OCI_NODATA\n");
		break;
	case OCI_ERROR:
		(void)OCIErrorGet((dvoid *)errhp, (ub4)1, (text *)NULL, &errcode,
			errbuf, (ub4) sizeof(errbuf), OCI_HTYPE_ERROR);
		(void)printf("Error - %.*s\n", 512, errbuf);
		break;
	case OCI_INVALID_HANDLE:
		(void)printf("Error - OCI_INVALID_HANDLE\n");
		break;
	case OCI_STILL_EXECUTING:
		(void)printf("Error - OCI_STILL_EXECUTE\n");
		break;
	case OCI_CONTINUE:
		(void)printf("Error - OCI_CONTINUE\n");
		break;
	default:
		break;
	}
}

OCIEnv *hOraEnv;
OCIError *hOraErr;

/*Функция инициализирует окружение OCIEnv и OCIError*/
BOOL InitOraEnvironment()
{
	hOraEnv = NULL;
	//printf("Pointer to hOraEnv before initialization is %llX(%llu)\n", (unsigned __int64)hOraEnv, (unsigned __int64)hOraEnv);

	if (OCIEnvCreate((OCIEnv **)&hOraEnv,
		(ub4)OCI_DEFAULT | OCI_OBJECT,
		(const void  *)0,
		(const void  * (*)(void  *, size_t))0,
		(const void  * (*)(void  *, void  *, size_t))0,
		(const void(*)(void  *, void  *))0,
		(size_t)0, (void  **)0))
	{
		printf("Application error, InitOraEnvironment function - can not create OCI Environment handle\n");
		return FALSE;
	}
	//printf("Pointer to hOraEnv after initialization is %llX(%llu)\n", (unsigned __int64)hOraEnv, (unsigned __int64)hOraEnv);

	hOraErr = NULL;
	//printf("Pointer to Error Handle before initialization is %llX(%llu)\n", (unsigned __int64)hOraErr, (unsigned __int64)hOraErr);
	if (OCIHandleAlloc((const void *)hOraEnv,
		(void **)&hOraErr,
		OCI_HTYPE_ERROR,
		(size_t)0,
		(void **)0))
	{
		printf("Application error, InitOraEnvironment function - can not allocate OCI Error handle\n");
		return FALSE;
	}
	//printf("Pointer to Error Handle after initialization is %llX(%llu)\n", (unsigned __int64)hOraErr, (unsigned __int64)hOraErr);

	
	return TRUE;

}

/*Процедура освобождает Error Handle и завершает сеанс работы с OCI*/
void CloseOraEnvironment()
{
	OCIHandleFree(hOraErr, OCI_HTYPE_ERROR);

	OCITerminate(OCI_DEFAULT);
}

OCIServer *hOraServerStandby;
OCISvcCtx *hOraSvcCtxStandby;
OCISession *hStandbySession;

/*Создаем и инициируем OCISvcCtx, OCIServer, OCISession и подулючаемся к серверу как пользователь SYS as sysdba*/
int CreateStandbySession(const char *username, const char *password, const char *dbname, int assysdba)
{

	hOraServerStandby = NULL;
	//printf("Pointer to Server Context Handle for sys or system before initialization is %llX(%llu)\n", (unsigned __int64)hOraServerForSYS, (unsigned __int64)hOraServerForSYS);
	if (OCIHandleAlloc((const void *)hOraEnv,
		(void **)&hOraServerStandby,
		OCI_HTYPE_SERVER,
		(size_t)0,
		(dvoid **)0))
	{
		printf("Application error, CreateSysSession function - can not allocate server handle for SYS or SYSTEM\n");
		return FALSE;
	}
	//printf("Pointer to Server Context Handle  for sys or system  after initialization is %llX(%llu)\n", (unsigned __int64)hOraServerForSYS, (unsigned __int64)hOraServerForSYS);

	if (OCIServerAttach(hOraServerStandby, hOraErr, (const OraText *)dbname, (sb4)strlen(dbname), (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Unable to attach to server. Check TNS name or connect string. May be network error\n");
		return FALSE;
	}

	hOraSvcCtxStandby = NULL;
	//printf("Pointer to Service Context Handle  for sys or system before initialization is %llX(%llu)\n", (unsigned __int64)hOraSvcCtxForSYS, (unsigned __int64)hOraSvcCtxForSYS);
	if (OCIHandleAlloc((const void *)hOraEnv,
		(void **)&hOraSvcCtxStandby,
		OCI_HTYPE_SVCCTX,
		(size_t)0,
		(dvoid **)0))
	{
		printf("Application error, CreateSysSession function - can not allocate service handle for SYS or SYSTEM\n");
		return FALSE;
	}
	//printf("Pointer to Service Context Handle  for sys or system after initialization is %llX(%llu)\n", (unsigned __int64)hOraSvcCtxForSYS, (unsigned __int64)hOraSvcCtxForSYS);

	if (OCIAttrSet((void *)hOraSvcCtxStandby, OCI_HTYPE_SVCCTX, (void *)hOraServerStandby, (ub4)0, OCI_ATTR_SERVER, (OCIError *)hOraErr) != OCI_SUCCESS)
	{
		printf("Application error, CreateSysSession function - unable to put server handle to service context for SYS or SYSTEM \n");
		return FALSE;
	}
	/*Выделяем хендл для сессии Администратора*/
	hStandbySession = NULL;
	//printf("Pointer to Sys Session Handle before initialization is %llX(%llu)\n", (unsigned __int64)hSYSSession, (unsigned __int64)hSYSSession);
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hStandbySession, (ub4)OCI_HTYPE_SESSION, (size_t)0, (void **)0))
	{
		printf("Application error, CreateSysSession function - can not allocate session handle for SYS or SYSTEM\n");
		return FALSE;
	}
	//printf("Pointer to Sys Session Handle after initialization is %llX(%llu)\n", (unsigned __int64)hSYSSession, (unsigned __int64)hSYSSession);


	/*Устанавливаем аттрибут "Имя пользователя"*/
	if (OCIAttrSet((void *)hStandbySession, (ub4)OCI_HTYPE_SESSION, (void *)username, (ub4)strlen(username), (ub4)OCI_ATTR_USERNAME, hOraErr) != OCI_SUCCESS)
	{
		printf("Application error, CreateSysSession function - unable to set username to SYS or SYSTEM session handle\n");
		return FALSE;
	}

	/*Устанавливаем аттрибут "Пароль"*/
	if (OCIAttrSet((void *)hStandbySession, (ub4)OCI_HTYPE_SESSION, (void *)password, (ub4)strlen(password), (ub4)OCI_ATTR_PASSWORD, hOraErr) != OCI_SUCCESS)
	{
		printf("Application error, CreateSysSession function - unable to set password to SYS or SYSTEM session handle\n");
		return FALSE;
	}

	/*Устанавливаем сессию*/
	if (OCISessionBegin(hOraSvcCtxStandby, hOraErr, hStandbySession, OCI_CRED_RDBMS, (ub4)(OCI_DEFAULT | (assysdba ? OCI_SYSDBA : 0))) != OCI_SUCCESS)
	{
		printf("Unable to begin SYS(SYSTEM) session. Check your login and password is correct\n");
		return FALSE;
	}

	if (OCIAttrSet((void *)hOraSvcCtxStandby, (ub4)OCI_HTYPE_SVCCTX, (void *)hStandbySession, (ub4)0, (ub4)OCI_ATTR_SESSION, hOraErr) != OCI_SUCCESS)
	{
		printf("Application error, CreateSysSession function - unable to set the SYS or SYSTEM session handle into the service context handle.\n");
		return FALSE;
	}

	return TRUE;
}

/*Отключаемся от сервера как пользователь SYS as sysdba, оосвобождаем хендлы и обнуляем указатели OCISvcCtx, OCIServer, OCISession*/
void CloseStandbySession()
{
	OCISessionEnd(hOraSvcCtxStandby, hOraErr, hStandbySession, OCI_DEFAULT);
	OCIHandleFree(hStandbySession, OCI_HTYPE_SESSION);
	hStandbySession = NULL;
	OCIHandleFree(hOraSvcCtxStandby, OCI_HTYPE_SVCCTX);
	hOraSvcCtxStandby = NULL;
	OCIServerDetach(hOraServerStandby, hOraErr, (ub4)OCI_DEFAULT);
	OCIHandleFree(hOraServerStandby, OCI_HTYPE_SERVER);
	hOraServerStandby = NULL;
}



OCIServer *hOraServerPrimary;
OCISvcCtx *hOraSvcCtxPrimary;
OCISession *hPrimarySession;

/*Создаем и инициируем OCISvcCtx, OCIServer, OCISession и подулючаемся к серверу как пользователь SYS as sysdba*/
int CreatePrimarySession(const char *username, const char *password, const char *dbname, int assysdba)
{

	hOraServerPrimary = NULL;
	//printf("Pointer to Server Context Handle for sys or system before initialization is %llX(%llu)\n", (unsigned __int64)hOraServerForSYS, (unsigned __int64)hOraServerForSYS);
	if (OCIHandleAlloc((const void *)hOraEnv,
		(void **)&hOraServerPrimary,
		OCI_HTYPE_SERVER,
		(size_t)0,
		(dvoid **)0))
	{
		printf("Application error, CreateSysSession function - can not allocate server handle for SYS or SYSTEM\n");
		return FALSE;
	}
	//printf("Pointer to Server Context Handle  for sys or system  after initialization is %llX(%llu)\n", (unsigned __int64)hOraServerForSYS, (unsigned __int64)hOraServerForSYS);

	if (OCIServerAttach(hOraServerPrimary, hOraErr, (const OraText *)dbname, (sb4)strlen(dbname), (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Unable to attach to server. Check TNS name or connect string. May be network error\n");
		return FALSE;
	}

	hOraSvcCtxPrimary = NULL;
	//printf("Pointer to Service Context Handle  for sys or system before initialization is %llX(%llu)\n", (unsigned __int64)hOraSvcCtxForSYS, (unsigned __int64)hOraSvcCtxForSYS);
	if (OCIHandleAlloc((const void *)hOraEnv,
		(void **)&hOraSvcCtxPrimary,
		OCI_HTYPE_SVCCTX,
		(size_t)0,
		(dvoid **)0))
	{
		printf("Application error, CreateSysSession function - can not allocate service handle for SYS or SYSTEM\n");
		return FALSE;
	}
	//printf("Pointer to Service Context Handle  for sys or system after initialization is %llX(%llu)\n", (unsigned __int64)hOraSvcCtxForSYS, (unsigned __int64)hOraSvcCtxForSYS);

	if (OCIAttrSet((void *)hOraSvcCtxPrimary, OCI_HTYPE_SVCCTX, (void *)hOraServerPrimary, (ub4)0, OCI_ATTR_SERVER, (OCIError *)hOraErr) != OCI_SUCCESS)
	{
		printf("Application error, CreateSysSession function - unable to put server handle to service context for SYS or SYSTEM \n");
		return FALSE;
	}
	/*Выделяем хендл для сессии Администратора*/
	hPrimarySession = NULL;
	//printf("Pointer to Sys Session Handle before initialization is %llX(%llu)\n", (unsigned __int64)hSYSSession, (unsigned __int64)hSYSSession);
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hPrimarySession, (ub4)OCI_HTYPE_SESSION, (size_t)0, (void **)0))
	{
		printf("Application error, CreateSysSession function - can not allocate session handle for SYS or SYSTEM\n");
		return FALSE;
	}
	//printf("Pointer to Sys Session Handle after initialization is %llX(%llu)\n", (unsigned __int64)hSYSSession, (unsigned __int64)hSYSSession);


	/*Устанавливаем аттрибут "Имя пользователя"*/
	if (OCIAttrSet((void *)hPrimarySession, (ub4)OCI_HTYPE_SESSION, (void *)username, (ub4)strlen(username), (ub4)OCI_ATTR_USERNAME, hOraErr) != OCI_SUCCESS)
	{
		printf("Application error, CreateSysSession function - unable to set username to SYS or SYSTEM session handle\n");
		return FALSE;
	}

	/*Устанавливаем аттрибут "Пароль"*/
	if (OCIAttrSet((void *)hPrimarySession, (ub4)OCI_HTYPE_SESSION, (void *)password, (ub4)strlen(password), (ub4)OCI_ATTR_PASSWORD, hOraErr) != OCI_SUCCESS)
	{
		printf("Application error, CreateSysSession function - unable to set password to SYS or SYSTEM session handle\n");
		return FALSE;
	}

	/*Устанавливаем сессию*/
	if (OCISessionBegin(hOraSvcCtxPrimary, hOraErr, hPrimarySession, OCI_CRED_RDBMS, (ub4)(OCI_DEFAULT | (assysdba ? OCI_SYSDBA : 0))) != OCI_SUCCESS)
	{
		printf("Unable to begin SYS(SYSTEM) session. Check your login and password is correct\n");
		return FALSE;
	}

	if (OCIAttrSet((void *)hOraSvcCtxPrimary, (ub4)OCI_HTYPE_SVCCTX, (void *)hPrimarySession, (ub4)0, (ub4)OCI_ATTR_SESSION, hOraErr) != OCI_SUCCESS)
	{
		printf("Application error, CreateSysSession function - unable to set the SYS or SYSTEM session handle into the service context handle.\n");
		return FALSE;
	}

	return TRUE;
}

/*Отключаемся от сервера как пользователь SYS as sysdba, оосвобождаем хендлы и обнуляем указатели OCISvcCtx, OCIServer, OCISession*/
void ClosePrimarySession()
{
	OCISessionEnd(hOraSvcCtxPrimary, hOraErr, hPrimarySession, OCI_DEFAULT);
	OCIHandleFree(hPrimarySession, OCI_HTYPE_SESSION);
	hPrimarySession = NULL;
	OCIHandleFree(hOraSvcCtxPrimary, OCI_HTYPE_SVCCTX);
	hOraSvcCtxPrimary = NULL;
	OCIServerDetach(hOraServerPrimary, hOraErr, (ub4)OCI_DEFAULT);
	OCIHandleFree(hOraServerPrimary, OCI_HTYPE_SERVER);
	hOraServerPrimary = NULL;
}



int GetStandbyUnnamedFile(int *fileNumber, char *fileName, char *TBSName)
{
	OCIStmt *hGetStandbyUnnamedFile = NULL;
	const char *getFileCountStmt = "select count(*) from v$datafile where name LIKE '%UNNAMED%'";
	sword countFiles = 0;
	sword status = 0;

	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hGetStandbyUnnamedFile, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
		printf("Application error, GetStandbyUnnamedFile function - can not allocate hGetStandbyUnnamedFile handle\n");
		return FALSE;
	}

	if (OCIStmtPrepare(hGetStandbyUnnamedFile, hOraErr, (const OraText *)getFileCountStmt, (ub4)strlen(getFileCountStmt), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetStandbyUnnamedFile function - unable to prepare getFileCountStmt statement.\n");
		OCIHandleFree(hGetStandbyUnnamedFile, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIDefine *OraCountDefine = NULL;
	if (OCIDefineByPos(hGetStandbyUnnamedFile, &OraCountDefine, hOraErr, 1, (void *)&countFiles, (sword)sizeof(countFiles), SQLT_INT, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetStandbyUnnamedFile function - unable to DefineByPos OraCountDefine.\n");
		OCIHandleFree(hGetStandbyUnnamedFile, OCI_HTYPE_STMT);
		return FALSE;
	}
	status = OCIStmtExecute(hOraSvcCtxStandby, hGetStandbyUnnamedFile, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{

		printf("Application error, GetStandbyUnnamedFile function - unable to execute getFileCountStmt.\n");
		checkerr(hOraErr, status);
		OCIHandleFree(hGetStandbyUnnamedFile, OCI_HTYPE_STMT);
		return FALSE;
	}

	//printf("Is unnamed file exists - %d\n", countFiles);
	if (countFiles == 0)
	{
		printf("No unnamed files on standby server.\n");
		OCIHandleFree(hGetStandbyUnnamedFile, OCI_HTYPE_STMT);
		return NO_UNNAMED_FILE;
	}

	const char *getUnnamedFileStmt = "select a.file#, a.name, b.name from v$datafile a, v$tablespace b WHERE a.TS# = b.TS# (+) and a.name LIKE '%UNNAMED%' order by file#";


	if (OCIStmtPrepare(hGetStandbyUnnamedFile, hOraErr, (const OraText *)getUnnamedFileStmt, (ub4)strlen(getUnnamedFileStmt), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetStandbyUnnamedFile function - unable to prepare getUnnamedFileStmt statement.\n");
		OCIHandleFree(hGetStandbyUnnamedFile, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIDefine *OraFileNumberDefine = NULL;
	if (OCIDefineByPos(hGetStandbyUnnamedFile, &OraFileNumberDefine, hOraErr, 1, (void *)fileNumber, (sword)sizeof(int), SQLT_INT, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetStandbyUnnamedFile function - unable to DefineByPos OraFileNumberDefine.\n");
		OCIHandleFree(hGetStandbyUnnamedFile, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIDefine *OraFileNameDefine = NULL;
	if (OCIDefineByPos(hGetStandbyUnnamedFile, &OraFileNameDefine, hOraErr, 2, (void *)fileName, (sword)513, SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetStandbyUnnamedFile function - unable to DefineByPos OraFileNameDefine.\n");
		OCIHandleFree(hGetStandbyUnnamedFile, OCI_HTYPE_STMT);
		return FALSE;
	}


	OCIDefine *OraTBSNameDefine = NULL;
	if (OCIDefineByPos(hGetStandbyUnnamedFile, &OraTBSNameDefine, hOraErr, 3, (void *)TBSName, (sword)32, SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetStandbyUnnamedFile function - unable to DefineByPos OraTBSNameDefine.\n");
		OCIHandleFree(hGetStandbyUnnamedFile, OCI_HTYPE_STMT);
		return FALSE;
	}

	status = OCIStmtExecute(hOraSvcCtxStandby, hGetStandbyUnnamedFile, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{
		printf("Application error, GetStandbyUnnamedFile function - unable to execute getUnnamedFileStmt.\n");
		checkerr(hOraErr, status);
		OCIHandleFree(hGetStandbyUnnamedFile, OCI_HTYPE_STMT);
		return FALSE;
	}


	OCIHandleFree(hGetStandbyUnnamedFile, OCI_HTYPE_STMT);

	return UNNAMED_FILE_EXISTS;
}


int GetPrimaryFileByNumber(int fileNumber, char *fileName)
{
	OCIStmt *hGetPrimaryFile = NULL;
	sword status = 0;

	const char *getPrimaryFileStmt = "select name from v$datafile where file# = :file_number";

	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hGetPrimaryFile, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
		printf("Application error, GetPrimaryFileByNumber function - can not allocate hGetPrimaryFile handle\n");
		return FALSE;
	}

	if (OCIStmtPrepare(hGetPrimaryFile, hOraErr, (const OraText *)getPrimaryFileStmt, (ub4)strlen(getPrimaryFileStmt) + 1, (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetPrimaryFileByNumber function - unable to prepare getUnnamedFileStmt statement.\n");
		OCIHandleFree(hGetPrimaryFile, OCI_HTYPE_STMT);
		return FALSE;
	}


	OCIDefine *OraFileNameDefine = NULL;
	if (OCIDefineByPos(hGetPrimaryFile, &OraFileNameDefine, hOraErr, 1, (void *)fileName, (sword)513, SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetPrimaryFileByNumber function - unable to DefineByPos OraFileNameDefine.\n");
		OCIHandleFree(hGetPrimaryFile, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIBind  *bnd1p = NULL;
	OCIBindByName(hGetPrimaryFile, &bnd1p, hOraErr, (text *)":file_number", -1, (void *)&fileNumber, (sb4)sizeof(fileNumber), SQLT_INT, (void *)0, (ub2 *)0, (ub2 *)0, (ub4)0, (ub4 *)0, OCI_DEFAULT);


	status = OCIStmtExecute(hOraSvcCtxPrimary, hGetPrimaryFile, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{
		printf("Application error, GetPrimaryFileByNumber function - unable to execute getPrimaryFileStmt.\n");
		checkerr(hOraErr, status);
		OCIHandleFree(hGetPrimaryFile, OCI_HTYPE_STMT);
		return FALSE;
	}


	OCIHandleFree(hGetPrimaryFile, OCI_HTYPE_STMT);
	return TRUE;
}

int GetLastTBSFile(const char *TBSName, char *fileName)
{
	OCIStmt *hGetLastTBSFile = NULL;
	const char *getTBSFileCountStmt = "select count(*) from v$datafile a, v$tablespace b WHERE a.TS# = b.TS# (+) and b.name LIKE :TABLESPACENAME and a.name NOT LIKE '%UNNAMED%'";
	sword countFiles = 0;
	sword status = 0;

	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hGetLastTBSFile, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
		printf("Application error, GetLastTBSFile function - can not allocate hGetLastTBSFile handle\n");
		return FALSE;
	}

	if (OCIStmtPrepare(hGetLastTBSFile, hOraErr, (const OraText *)getTBSFileCountStmt, (ub4)strlen(getTBSFileCountStmt), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetLastTBSFile function - unable to prepare getTBSFileCountStmt statement.\n");
		OCIHandleFree(hGetLastTBSFile, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIDefine *OraCountDefine = NULL;
	if (OCIDefineByPos(hGetLastTBSFile, &OraCountDefine, hOraErr, 1, (void *)&countFiles, (sword)sizeof(countFiles), SQLT_INT, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetLastTBSFile function - unable to DefineByPos OraCountDefine.\n");
		OCIHandleFree(hGetLastTBSFile, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIBind  *bnd1p = NULL;
	OCIBindByName(hGetLastTBSFile, &bnd1p, hOraErr, (text *) ":TABLESPACENAME", -1, (void *)TBSName, (sb4)(strlen(TBSName) + 1), SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, (ub4)0, (ub4 *)0, OCI_DEFAULT);


	status = OCIStmtExecute(hOraSvcCtxStandby, hGetLastTBSFile, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{

		printf("Application error, GetLastTBSFile function - unable to execute getTBSFileCountStmt\n");
		checkerr(hOraErr, status);
		OCIHandleFree(hGetLastTBSFile, OCI_HTYPE_STMT);
		return FALSE;
	}

	//printf("Is named file in tablespace exists - %d\n", countFiles);
	if (countFiles == 0)
	{
		//printf("No unnamed files on standby server.\n");
		OCIHandleFree(hGetLastTBSFile, OCI_HTYPE_STMT);
		return NO_NAMED_FILE;
	}

	const char *getStandbyTBSNamedFileStmt = "select a.name from v$datafile a, v$tablespace b WHERE a.TS# = b.TS# (+) and b.name LIKE :TABLESPACENAME and a.name NOT LIKE '%UNNAMED%' order by file# DESC";


	if (OCIStmtPrepare(hGetLastTBSFile, hOraErr, (const OraText *)getStandbyTBSNamedFileStmt, (ub4)strlen(getStandbyTBSNamedFileStmt), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetLastTBSFile function - unable to prepare getStandbyTBSNamedFileStmt statement.\n");
		OCIHandleFree(hGetLastTBSFile, OCI_HTYPE_STMT);
		return FALSE;
	}


	OCIDefine *OraFileNameDefine = NULL;
	if (OCIDefineByPos(hGetLastTBSFile, &OraFileNameDefine, hOraErr, 1, (void *)fileName, (sword)513, SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetLastTBSFile function - unable to DefineByPos OraFileNameDefine.\n");
		OCIHandleFree(hGetLastTBSFile, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIBind  *bnd2p = NULL;
	OCIBindByName(hGetLastTBSFile, &bnd2p, hOraErr, (text *) ":TABLESPACENAME", -1, (void *)TBSName, (sb4)(strlen(TBSName) + 1), SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, (ub4)0, (ub4 *)0, OCI_DEFAULT);


	status = OCIStmtExecute(hOraSvcCtxStandby, hGetLastTBSFile, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{
		printf("Application error, GetLastTBSFile function - unable to execute getStandbyTBSNamedFileStmt.\n");
		checkerr(hOraErr, status);
		OCIHandleFree(hGetLastTBSFile, OCI_HTYPE_STMT);
		return FALSE;
	}


	OCIHandleFree(hGetLastTBSFile, OCI_HTYPE_STMT);

	return NAMED_FILE_FOUND;
}

int CreateStandbyDatafile(char *unnamed, char *correctname)
{
	OCIStmt *hCreateStandbyDatafile = NULL;
	char createStabdbyDatafileStmt[1024] = { 0 };
	sprintf(createStabdbyDatafileStmt, "alter database create datafile '%s' as '%s'", unnamed, correctname);

	sword status = 0;

	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hCreateStandbyDatafile, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
		printf("Application error, CreateStandbyDatafile function - can not allocate hCreateStandbyDatafile handle\n");
		return FALSE;
	}

	if (OCIStmtPrepare(hCreateStandbyDatafile, hOraErr, (const OraText *)createStabdbyDatafileStmt, (ub4)strlen(createStabdbyDatafileStmt), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, CreateStandbyDatafile function - unable to prepare createStabdbyDatafileStmt statement.\n");
		OCIHandleFree(hCreateStandbyDatafile, OCI_HTYPE_STMT);
		return FALSE;
	}


	status = OCIStmtExecute(hOraSvcCtxStandby, hCreateStandbyDatafile, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{

		printf("Application error, CreateStandbyDatafile function - unable to execute createStabdbyDatafileStmt\n");
		checkerr(hOraErr, status);
		OCIHandleFree(hCreateStandbyDatafile, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIHandleFree(hCreateStandbyDatafile, OCI_HTYPE_STMT);
	return TRUE;

}

int GetNextDatafileName(const char* tablespace, char* datafilename, unsigned int bufSizeDatafilename)
{

	sword status;

	//const char *plsql_get_last_datafile_statement = "select file_name from dba_data_files where tablespace_name = :TABLESPACE order by file_id DESC";

	const char *plsql_get_last_datafile_statement = "select a.name from v$datafile a, v$tablespace b WHERE a.TS# = b.TS# (+) and b.name LIKE :TABLESPACE and a.name NOT LIKE '%UNNAMED%' order by a.file# DESC";

	OCIStmt *hOraPlsqlGetLastDatafileStatement = NULL;
	//printf("Pointer to PlSQLUserExists Statement Handle before initialization is %llX(%llu)\n", (unsigned __int64)hOraPlsqlDeleteStatement, (unsigned __int64)hOraPlsqlDeleteStatement);
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hOraPlsqlGetLastDatafileStatement, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
		printf("Application error, GetNextDatafileName function - can not allocate hOraPlsqlGetLastDatafileStatement handle\n");
		return FALSE;
	}
	//printf("Pointer to PlSQLUserExists Statement Handle after initialization is %llX(%llu)\n", (unsigned __int64)hOraPlsqlDeleteStatement, (unsigned __int64)hOraPlsqlDeleteStatement);


	if (OCIStmtPrepare(hOraPlsqlGetLastDatafileStatement, hOraErr, (const OraText *)plsql_get_last_datafile_statement, (ub4)strlen(plsql_get_last_datafile_statement), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetNextDatafileName function - unable to prepare plsql_get_last_datafile_statement\n");
		OCIHandleFree(hOraPlsqlGetLastDatafileStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIDefine *Ora1Define = NULL;

	if (OCIDefineByPos(hOraPlsqlGetLastDatafileStatement, &Ora1Define, hOraErr, 1, (void *)datafilename, (sword)bufSizeDatafilename, SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
		printf("Application error, GetNextDatafileName function - unable to DefineByPos Ora1Define\n");
		OCIHandleFree(hOraPlsqlGetLastDatafileStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIBind  *bnd1p = NULL;
	if (OCIBindByName(hOraPlsqlGetLastDatafileStatement, &bnd1p, hOraErr, (text *) ":TABLESPACE", -1, (void *)tablespace, (sb4)(strlen(tablespace) + 1), SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, (ub4)0, (ub4 *)0, OCI_DEFAULT))
	{
		printf("Application error, GetNextDatafileName GetDatafilesFromDB - unable to bind TABLESPACE to list\n");
		OCIHandleFree(hOraPlsqlGetLastDatafileStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	status = OCIStmtExecute(hOraSvcCtxStandby, hOraPlsqlGetLastDatafileStatement, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{
		printf("Application error, GetNextDatafileName function - unable to execute plsql_user_to_list_statement\n");
		checkerr(hOraErr, status);
		OCIHandleFree(hOraPlsqlGetLastDatafileStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	//printf("%s\n", datafilename);

	char buffer[513];
	int i;

	char * prevfilenamenumber = NULL;
	for (i = strlen(datafilename); !isdigit(*(datafilename + i)); i--);
	for (; isdigit(*(datafilename + i)); i--);
	prevfilenamenumber = datafilename + i + 1;
	//printf("%s\n", prevfilenamenumber);

	int numfile = 0;
	numfile = atoi(prevfilenamenumber);
	numfile++;

	//printf("Номер последнего датафайла %s, номер нового - %d\n", prevfilenamenumber, numfile);

	char * prevfilenameext = NULL;
	for (i = 0; *(prevfilenamenumber + i) != '.'; i++);
	prevfilenameext = prevfilenamenumber + i;

	//printf("Расширение последнего датафайла %s\n", prevfilenameext);

	*(prevfilenamenumber) = 0;
	//printf("Первая часть иммени последнего датафайла %s\n", datafilenameutf8);

	sprintf(buffer, "%s%02d%s", datafilename, numfile, prevfilenameext);
	//printf("Новое имя файла - %s\n", buffer);

	strncpy(datafilename, buffer, bufSizeDatafilename);
	//printf("Новое имя файла - %s\n", datafilename);

	//MultiByteToWideChar(CP_UTF8, 0, buffer, -1, datafilename, 513);
//PUT FILL LIST ACTION HERE
//wprintf(L"%s\n", datafilename);
//SendMessage(hUsersComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)username);

	OCIHandleFree(hOraPlsqlGetLastDatafileStatement, OCI_HTYPE_STMT);
	return TRUE;

}
