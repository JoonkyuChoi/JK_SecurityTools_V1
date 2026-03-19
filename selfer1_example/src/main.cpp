/*==============================================================================
	> 저작권 공지:
		저작권 (c) 2026 ~ 최준규(JK.Choi)<osoi@naver.com> 보유.

		본 소프트웨어의 사본과 관련 문서파일들("소프트웨어")을 얻은 모든 개인에게,
		다음에 나오는 허가 조건들을 대상으로, 제약없이 소프트웨어를 취급할 수 있도록 사용, 복사,
		병합, 공개, 재배포, 2차 라이센스, 소프트웨어의 복사본 판매에 제한없음을 포함하여,
		본 소프트웨어를 제공받은 개인에게 허용하기 위해, 무료 허가증을 승인하게 됩니다.

	> 허가(Permission) 조건 공지:
		1) 위의 저작권 공지와 이 허가 공지는 모든 사본 또는 소프트웨어의 상당한 부분에 포함되어져야만 합니다.
		2) 어떠한 방법으로든 소프트웨어의 내용물을 수정하지 말아야합니다.
		3) 본 소프트웨어의 공개, 재배포, 2차 라이센스, 복사본 판매는 기능이 제한된 Lite에디션에만 허용됩니다.

	> 책임과 보증:
		본 소프트웨어는 특정목적과 비침해에 대한 적합성이나, 상품성의 품질보증을 허용하지 않음을 포함하여,
		명시적 또는 묵시적인, 어떠한 종류의 보증없이 "있는 그대로" 제공됩니다.
		어떠한 경우에도 저자 또는 저작권 보유자는 본 소프트웨어에 기타 거래나 사용과 관련하여 발생하는
		기타 불법 행위, 계약의 작용이든, 손해 또는 기타 책임이든, 어떠한 요구에 대하여 책임을지지 않습니다.
================================================================================
	main.cpp : 보안자체검증기 3급 보안 공개툴
  
	Revision History :
		[2026/03/12:최준규]	first written by JK.Choi
==============================================================================*/
#include <stdio.h>
#include <signal.h>

#ifdef _MSC_VER
  #include <windows.h>  // SetConsoleCtrlHandler
  #include <conio.h>    // getch
  #define getch         _getch
#else
  #include <unistd.h>
  #include <termios.h>
  #define Beep(f, d)    printf("\a")  // Linux/macOS 표준 경고음(Bell)
#endif

#include "include/scp-self/SCP.h"
// -----------------------------------------------------------------------------
// [FUNCTIONS]
// -----------------------------------------------------------------------------
void printLogo()
{
  printf("================================================================================\n");
  printf("*****************   JK-Dreams, Security Codes Selfer V%c Demo   *****************\n", gfGetVer());
  printf("================================================================================\n");
  // -------------------------------------
  // 빌드 구분문자 추가
  // -------------------------------------
  // [빌드] 구분문자 제작
  char  l_cBuild = '-';
#if   defined(_DEBUG)
  l_cBuild = 'D';
#elif defined(RDEBUG)
  l_cBuild = '+';
#elif defined(NDEBUG)
  l_cBuild = 'R';
#endif
  // [에디션/빌드] 라인 출력
  printf("                                                                 Promotional (%c)\n", l_cBuild);
  // -------------------------------------
  printf("----------------------------------------\n");
  printf(">> SECURITY WARNING AND TERMS\n");
  printf("----------------------------------------\n");
  // 보안 경고
  printf("* JK-Dreams' special security products have a limited expiration date.\n");
  printf("  > This program is a PUBLIC-LEVEL security product.\n");
  printf("  > If this program becomes corrupted or expires, it will be automatically removed.\n");
  // 이용 약관
  printf("* Terms and Conditions (Demo Program)\n");
  printf("  1. Privacy Protection\n");
  printf("    This demo program is designed not to collect or transmit any personally identifiable information or data from your system.\n");
  printf("  2. Grant of License\n");
  printf("    This demo program is FREE SOFTWARE that anyone may use.\n");
  printf("    Users are granted the right to use this demo program free of charge for testing, evaluation, and non-commercial purposes only.\n");
  printf("    Furthermore, any products additionally developed using jkd_security3_selfer1_core.lib may be used solely for non-commercial purposes.\n");
  printf("  3. Limitation of Liability\n");
  printf("    This demo program is provided \"AS IS\" without any warranties.\n");
  printf("    The Developer shall not be held legally liable for any issues arising from the use of the demo program,\n");
  printf("    including but not limited to data loss, system failure, or any other direct or indirect damages.\n");
  printf("    The Developer is under no obligation to provide compensation, indemnification, or technical support of any kind.\n");
  printf("    All responsibility for the results of using this demo program rests entirely with the user.\n");
  printf("----------------------------------------\n\n");
  
  printf("                 Copyright (c) 2026 ~ Reserved by JoonKyu Choi <osoi@naver.com>.\n");
  printf("================================================================================\n\n");
  
}

void printUsage()
{
  printf("\nUsage:");
  printf("  jkd_security3_selfer1");
}

// 신호 처리 (수행)
#ifdef _MSC_VER
  BOOL WINAPI ConsoleHandler(DWORD a_dwCtrlType)
  {
    switch (a_dwCtrlType)
    {
      case CTRL_C_EVENT:      // Ctrl + C
      case CTRL_CLOSE_EVENT:  // 콘솔창 닫기 버튼 클릭 + taskkill (일반)
        gfBreakWorkloop();    // 루프 종료
        return TRUE;  // 이벤트를 처리했음을 OS에 알림
    }
    return FALSE;
  }
#else
  void ExitService(int a_nSignal)
  {
	  gfBreakWorkloop();        // 루프 종료
  }
#endif

// --- [플랫폼별 단일 키 입력 함수 구현] ---
int getChar()
{
#ifdef _WIN32
  return _getch();
#else
  int             ch;
  struct termios  oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);             // 기존 설정 저장
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);           // 버퍼링 및 에코 해제
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);    // 새 설정 적용
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);    // 설정 복구
  return ch;
#endif
}

// 해당 질문과 바이트 범위를 콘솔창에 출력하여, 입력한 데이터를 버퍼에 얻어 내고, 그 바이트 수량을 리턴한다.
uint8_t askUserPassword(const char* a_cpszQuestion, int a_nMin, int a_nMax, char* a_pcBuffer, int a_nHiddenCode=0)
{
  // -------------------------------------
  // check parameters
  // -------------------------------------
  if (a_cpszQuestion== NULL ||
      a_pcBuffer    == NULL ||
      a_nMin        <  0    ||
      a_nMin        > a_nMax)
    return 0;
  // -------------------------------------
  // 질문과 범위 출력
  // -------------------------------------
  printf("%s (%d ~ %d bytes): ", a_cpszQuestion, a_nMin, a_nMax);
  fflush(stdout); // 버퍼 강제 출력
  // -------------------------------------
  // 키보드 입력 루프
  // -------------------------------------
  int   l_nCurKey,
        l_nCurLen = 0;
  while (1)
  {
    l_nCurKey = getChar();
    // -----------------
    // 1. 엔터키 처리 (Windows: 13, Linux: 10)
    // -----------------
    if (l_nCurKey == 13 ||
        l_nCurKey == 10)
    {
      if (l_nCurLen < a_nMin)
      {
        Beep(500, 200);
        continue;
      }
      printf("\n");
      break;
    }
    // -----------------
    // 2. 백스페이스 처리 (Windows: 8, Linux: 127)
    // -----------------
    if (l_nCurKey == 8 ||
        l_nCurKey == 127)
    {
      if (l_nCurLen > 0)
      {
        // 멀티바이트(한글) 체크 (EUC-KR/UTF-8 공통: 0x80 이상)
        if (l_nCurLen >= 2 && (unsigned char)a_pcBuffer[l_nCurLen - 1] >= 0x80)
        {
          // 한글 처리 로직 (EUC-KR은 2바이트 고정이라 가정)
          l_nCurLen -= 2;
          printf("\b\b  \b\b"); 
        }
        else
        {
          l_nCurLen -= 1;
          printf("\b \b");
        }
        fflush(stdout);
      }
      continue;
    }
    // -----------------
    // 3. 일반 키 및 멀티바이트(한글) 처리
    // -----------------
    int l_nCharSize = (l_nCurKey >= 0x80) ? 2 : 1;
    if (l_nCurLen + l_nCharSize > a_nMax)
    {
      Beep(1000, 100);
      // Linux에서는 멀티바이트가 한 번에 들어오지 않을 수 있으나, 단순화를 위해 수량 초과 시 무시 처리
      continue;
    }
    // 버퍼에 할당
    a_pcBuffer[l_nCurLen++] = (char)l_nCurKey;
    // [JKC:20260224-0500] 숨김 문자 적용
    putchar((a_nHiddenCode != 0) ? a_nHiddenCode : l_nCurKey);
    if (l_nCharSize == 2)
    {
      int l_nNextKey = getChar();
      a_pcBuffer[l_nCurLen++] = (char)l_nNextKey;
      // [JKC:20260224-0500] 숨김 문자 적용
      putchar((a_nHiddenCode != 0) ? a_nHiddenCode : l_nNextKey);
    }
    // -----------------
    fflush(stdout);
  }
  a_pcBuffer[l_nCurLen] = '\0';
  // -------------------------------------
  return (uint8_t)l_nCurLen;
}

// 이벤트 수신/응답 처리 (패스워드 처리용)
static int sfEvent(uint8_t a_ucType, const char* a_cpszMsg, int a_nCurMin, int a_nMax, char* a_pcBuffer)
{
  int l_nRet = 0;
  // -------------------------------------
  switch (a_ucType)
  {
	  case EVT_ASK_PW:  //13 비번요청(min~max,buffer)
	    l_nRet = askUserPassword(a_cpszMsg, a_nCurMin, a_nMax, a_pcBuffer, '*');
	    break;
  }
  // -------------------------------------
  return l_nRet;
}

// 지정한 파일이나 실행중인 자신의 파일을 삭제하는 명령울 예약하고, 성공 여부를 리턴한다. (삭제 성공을 장담할 수는 없다.)
bool reserveFileDeletion(const char* a_cpszDeletedFile=NULL, bool a_bExit=false)
{
  bool    l_bRet = false;
  char    l_szFilePath[MAX_PATH];
  
  if (a_cpszDeletedFile)
    strcpy(l_szFilePath, a_cpszDeletedFile);
  else
  {
    if (GetModuleFileNameA(NULL, l_szFilePath, MAX_PATH) == 0)
      return l_bRet;
  }
  // -------------------------------------
  // cmd.exe를 이용한, 자기자신 삭제
  // -------------------------------------
  char              l_szCmd[MAX_PATH * 3];
  SHELLEXECUTEINFOA l_tSEI        = {0};
                    l_tSEI.cbSize = sizeof(l_tSEI);
                    l_tSEI.fMask  = SEE_MASK_NOCLOSEPROCESS;
                    l_tSEI.lpVerb = "open";
                    l_tSEI.lpFile = "cmd.exe";
  // -----------------
  // 반복 시도 콘솔 명령: 루프 돌면서 파일 존재 여부 확인 후 삭제
  // -----------------
  _snprintf(l_szCmd, sizeof(l_szCmd), "/C FOR /L %%i IN (1,1,100) DO (IF EXIST \"%s\" (DEL /F /Q \"%s\") ELSE EXIT)",
                                      l_szFilePath, l_szFilePath);
  l_tSEI.lpParameters = l_szCmd;
  l_tSEI.nShow        = SW_HIDE;
  // -----------------
  if (ShellExecuteExA(&l_tSEI))
  {
    if (l_tSEI.hProcess)
      CloseHandle(l_tSEI.hProcess);
    l_bRet = true;
  }
  // -------------------------------------
  // 부모 프로세스는 즉시 종료, 그래야만 파일 잠금이 풀림
  // -------------------------------------
  if (l_bRet &&
      a_bExit)
    exit(0);
  // -------------------------------------
  return l_bRet;
}
/*----------------------------------------------------------------------------+-
보안자체검증기 공개툴
-+----------------------------------------------------------------------------+-
- 용어 정의
  SCF   : 보안코드파일
  SCB   : 보안코드블록
  SCP   : 보안코드처리기
  SCI   : 보안코드주입기
  
- 소개
  > SCB를 초간단 검증하기 위해, [주입/키입력] 기능이 제외된 3급 보안 툴이다.
    본 확인툴은 보안코드주입기로 SCB를 주입시켜야 활성화 된다.
  > 기원틀 소스코드의 검증 부분만을 사용하여, SCB 파일의 [사용횟수/유효기간] 확인용으로 사용한다.
  > 툴의 명칭은 `jkd_security3_selfer1`로 한다.
    끝의 '1'은 버전으로, 업그레이드하면 달라진다.
    
- 설계 조건
  > "단위테스트" 기능은 철저하게 차단한다.
  > "SCB 주입"   기능도 철저하게 차단한다.
  > "대상검증"   기능도 철저하게 차단한다.
  > 제공 기능
    - 자체 SCB 검증 (초간단 검증)
      > 사용자의 키입력 요청과, 메세지 출력 부분들을 모두 제거한다.
      > 사용횟수를 제한하려면, 어플단에서 gfAccOwnUsage() 함수를 직접 사용해야 한다.
  > 파일데이터 로드청크 사이즈는 해시코드 사이즈의 배수여야만 한다.

- 개발 이력
  [2026.01.04~2026.03.10] V1 최초 개발

- 사용법
  + 자체 검증
    > jkd_security3_selfer1
-+----------------------------------------------------------------------------*/
int main(int a_nArgC, char** a_ppszArgV)
{
	// -------------------------------------
	// 신호 처리 (등록)
	// -------------------------------------
#ifdef _MSC_VER
  if (!SetConsoleCtrlHandler(ConsoleHandler, TRUE))
  {
    printf("[ERR] Control handler registration failed.\n");
    return -100;
  }
#else
	// Signal 초기화
	signal(SIGHUP,  SIG_IGN);			// 터미널과 시스템 사이에 통신 접속이 끊겼을 때(Hangup)
	signal(SIGQUIT, SIG_IGN);			// 터미널에서 유저가 Quit키를 친 경우
	signal(SIGINT,  ExitService);	// Ctrl+C 입력된 경우 실행
	signal(SIGTERM, ExitService);	// kill 명령에 의해 프로세스를 종료할 경우
	signal(SIGALRM, SIG_IGN);			// 알람타이머 만료 시
	signal(SIGPIPE, SIG_IGN);			// 종료된 소켓에 쓰기를 시도할 때
	signal(SIGCLD,  SIG_IGN);			// 자식프로세스가 종료될 때
#endif
  // -------------------------------------
	// 1. 가상화면 처리
	// -------------------------------------
	// 타이틀 출력 (제품명/보안경고/라이센스)
	// -----------------
	printLogo();
  // -------------------------------------
  // 2. 자체검증
	// -------------------------------------
	int   l_nRet = 0,         // 10 미만은 자체검증, 10 이상은 대상검증 문제
	      l_nState4OwnSCB = SCBST_NONE;
	bool  l_bValid,
	      l_bDestroy = false; // 자체소멸 여부
	// -----------------
	// 자체검증 시도
	// -----------------
	gfRegAskEvent(sfEvent);   // 질의 전용 이벤트 콜백함수를 등록한다. (패스워드 입력 요청에 대응)
	l_bValid = gfOnlySelfValidation(&l_nRet); // 자체검증을 수행하고, 남은 [유효시간/사용횟수]를 얻고, 유효 여부를 리턴한다.
	if (l_bValid)
	    printf("[INF] This program is valid.\n");
	else
	{
	  // [옵션] 자체소멸 처리
	  if (l_nRet <= SCBST_INFO_BAD)     // 손상되었다면
	  {
	    // 본 프로그램은 심각하게 손상되었습니다. 제작사에 문의하세요.
      printf("[ERR] This program is severely corrupted. Please contact the production company.\n");
	    l_bDestroy = true;
	  }
	  if (l_nRet == SCBST_DL_EXPIRE)    // 기한만료면
	  {
	    // 본 프로그램의 유효 기한은 만료되었습니다.
      printf("[WRN] This program's valid-term has expired.\n");
	    l_bDestroy = true;
	  }
	  else
	    printf("[WRN] This program is invalid.\n");
	}
	// -----------------
	// 상세 정보(사용횟수/유효시간) 출력
	// -----------------
	uint8_t     l_ucRemainedCount = 0;  // 남은횟수
	if (l_bValid)
	{
	  uint8_t   l_ucSecurityLevel;      // 보안레벨
	  uint32_t  l_uiRemainedTime;       // 남은시간
	  
	  // 자체검증된 상태의 [보안레벨/남은유효시간/남은사용횟수]를 얻고, 성공 여부를 리턴한다. (Notes: 남은유효시간이 0일 때, 보안레벨이 3급 이상이면 무제한을 의미하고, 2급 이하는 기간만료를 의미한다.)
	  if (gfGetRemainedValidTerm(l_ucSecurityLevel, &l_uiRemainedTime, &l_ucRemainedCount))
	  {
	    // -------
	    // 정보 출력
	    // -------
	    if (l_uiRemainedTime)
      {
        if (l_ucRemainedCount)
          // 당신은 n초 동안에, n회 더 사용할 수 있습니다.
          printf("      You can be used %u more times for %u seconds.\n", l_ucRemainedCount, l_uiRemainedTime);
        else
          // 당신은 n초 동안 사용할 수 있습니다.
          printf("      You can be used for %u seconds.\n", l_uiRemainedTime);
      }
      else
      {
        if (l_ucRemainedCount)
          // 당신은 n회 더 사용할 수 있습니다.
          printf("      You can be used %u more times.\n", l_ucRemainedCount);
        else
        {
          // 3급 이상
          if (l_ucSecurityLevel > 2)
            // 당신은 무기한으로 사용할 수 있습니다.
            printf("      You can use it indefinitely.\n");
          // 2급 이하
          else
            // 유효기간이 만료되었습니다.
            printf("      The valid-term has expired.\n");
        }
      }
      // -------
	  }
	}
	// -------------------------------------
	// 3. 콘솔창 복원
	// -------------------------------------
	// 3-1. 색상 복원
	// -----------------
	printf("----------------------------------------\n");
	// -----------------
	// 3-2. 입력 대기 (사용자 화면캡쳐 대비용)
	// -----------------
  // 아무키나 누르세요. 현재 화면은 사라집니다.
  printf("Press any key. The current screen disappears.\n");
  getch();
  // -----------------
	// 3-4. [검증완료] 마무리
	// -----------------
	// 사용횟수 누적
	if (l_ucRemainedCount)
	{
	  if (gfAccOwnUsage() > 0)  // 원본 SCB의 사용횟수를 누적하여, 자신의 파일에 저장시키기 위해, 프로세스 종료를 예약하고, 결과 코드를 리턴한다.(0=관련없음, 음수=실패, 양수=수행완료)
	    return 999;
	}
	// 모듈 분석정보 지우기
	gfClearAll(true);
  // 사용자 중단 요청
  if (gfGetWorkloop())
    return 1000;
  // -----------------
	// 3-5. 자체 소멸 체크/수행
	// -----------------
#ifndef _DEBUG
	if (l_bDestroy)
	{
	  // 본 프로그램은 종료되고, 즉시 제거될 것입니다.
    printf("[INF] **** This program will be terminated and removed. ****\n");
    if (!reserveFileDeletion()) // 지정한 파일이나 실행중인 자신의 파일을 삭제하는 명령울 예약하고, 성공 여부를 리턴한다. (삭제 성공을 장담할 수는 없다.)
    {
      // 본 프로그램 제거에 실패하였습니다.
      printf("[INF] **** This program failed to remove. ****\n");
    }
    // 프로세스 종료
    exit(l_nRet);
  }
#endif
  // -------------------------------------
	return l_nRet;
}
// -----------------------------------------------------------------------------
