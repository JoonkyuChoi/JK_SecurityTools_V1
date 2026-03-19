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
	SCP.h : [보안자체검증기 전용] 보안코드처리기
  
	Revision History :
		[2026/02/13:최준규]	first written by JK.Choi
==============================================================================*/
#ifndef __SCP_LIB_H__
#define __SCP_LIB_H__

#include <stdlib.h>         // abs

#include <win/inttypes.h>	  // uint8_t
#include "SCP-export.h"
// -----------------------------------------------------------------------------
// [DEFINES]
// -----------------------------------------------------------------------------
#if !defined(_LIB)

#ifndef __STORY_BOARD_H__
// -------------------------------------
// [이벤트]
// -------------------------------------
// [이벤트:콜백함수] 타입
typedef int(*CBFP_SCP_PROC)(uint8_t a_ucType, const char* a_cpszMsg, int a_nCurMin, int a_nMax, char* a_pcBuffer);

// [이벤트:타입] 상수
typedef enum eEventTypes
{
	EVT_MSG   =  0, // 0 메세지 (LF 추가 필요,color/basecolor)
	EVT_FMT,        // 1 형식문자열 (ASIS 표출,color/basecolor)
	EVT_ASK_YN= 10, //10 동의요청(y/n)
	EVT_ASK_NM,     //11 숫자요청(min~max)
	EVT_ASK_ST,     //12 문자열요청(min~max,buffer)
	EVT_ASK_PW,     //13 비번요청(min~max,buffer)
	EVT_PROG_S= 20, //20 진행시작(cur/max)
	EVT_PROG_I,     //21 진행중  (cur/max)
	EVT_PROG_E      //22 진행종료(cur/max)
} E_EVENT_TYPES;
#endif
// -------------------------------------
// [SCB탐지:결과] 코드
// -------------------------------------
// [SCB탐지:결과] 인덱스
typedef enum eStateOfSCB
{
	SCBST_HASH_BAD= -5,   //-5 해시불량(손상)
	SCBST_INFO_BAD= -4,   //-4 정보불량(손상)
	SCBST_PROC_ERR= -3,   //-3 처리오류
	SCBST_VAL_FAIL= -2,   //-2 검증실패
	SCBST_INJ_FAIL= -1,   //-1 주입실패
	SCBST_NONE    =  0,   // 0 SCB 없음
	SCBST_INJ_NEED,       // 1 주입필요(대상검증 전용)
	SCBST_INJ_ONCE,       // 2 일시주입(자체검증+OriginSCI 전용)
	SCBST_INJ_DONE,       // 3 주입완료(대상검증 전용)
	SCBST_VAL_NEED,       // 4 검증필요(내부용)
	SCBST_VAL_DONE,       // 5 검증완료
	SCBST_DL_EXPIRE,      // 6 기한만료
	SCBST_MAXPW_ATT,      // 7 최대비번시도
	SCBST_MAX             // 8 수량
} E_STATE_OF_SCB;
// [SCB탐지:상태] 문자열
static const char* s_cprszStateOfSCB[SCBST_MAX]=
{
	"No SCB",             // 0 SCB 없음
	"Injection Need",     // 1 주입필요(대상검증 전용)
	"Injection Once",     // 2 일시주입(자체검증+OriginSCI 전용)
	"Injection Done",     // 3 주입완료(대상검증 전용)
	"Validation Need",    // 4 검증필요(내부용)
	"Validation Done",    // 5 검증완료
	"Deadline Expires",   // 6 기한만료
	"Max PW Attempts"     // 7 최대비번시도
};
// [SCB탐지:오류] 문자열
static const char* s_cprszErrorOfSCB[]=
{
	"No SCB",             // 0 SCB 없음
	"Injection Failed",   //-1 주입실패
	"Validation Failed",  //-2 검증실패
	"Processing Error",   //-3 처리오류
	"Information Damage", //-4 정보불량
	"Hash Corruption"     //-5 해시불량
};
// 해당 상태코드에 대한, 문자열 포인터을 리턴한다.
static const char* sfGetStateMsg4SCB(int a_nState)
{
static const char* s_cpszUnknownState = "Unknown State";

  if (a_nState >= SCBST_NONE &&
      a_nState <  SCBST_MAX)
    return s_cprszStateOfSCB[a_nState];
  else
  {
    if (a_nState >= SCBST_HASH_BAD)
      return s_cprszErrorOfSCB[abs(a_nState)];
    return s_cpszUnknownState;
  }
};
#endif
// -----------------------------------------------------------------------------
// [FUNCTIONS]
// -----------------------------------------------------------------------------
// 속성 함수들
// -------------------------------------
SCPDLL_CEXFNC uint8_t gfGetVer();         // 버전을 리턴한다.
SCPDLL_CEXFNC void    gfBreakWorkloop();  // 작업 루프를 중단한다.
SCPDLL_CEXFNC bool    gfGetWorkloop();    // 작업 루프 상태를 얻는다. (true=종료)
// -------------------------------------
// 검증 함수
// -------------------------------------
SCPDLL_CEXFNC void    gfRegAskEvent(CBFP_SCP_PROC a_pfAskBack, uint16_t a_usBaseColor=7); // 질의 전용 이벤트 콜백함수를 등록한다. (패스워드 입력 요청에 대응)
SCPDLL_CEXFNC bool    gfOnlySelfValidation(int* a_pnResultCode=NULL); // 자체검증을 수행하고, 남은 [유효시간/사용횟수]를 얻고, 유효 여부를 리턴한다.
// -------------------------------------
// 제어 함수들
// -------------------------------------
// 자체검증된 상태의 [보안레벨/남은유효시간/남은사용횟수]를 얻고, 성공 여부를 리턴한다. (Notes: 남은유효시간이 0일 때, 보안레벨이 3급 이상이면 무제한을 의미하고, 2급 이하는 기간만료를 의미한다.)
SCPDLL_CEXFNC bool    gfGetRemainedValidTerm(uint8_t& a_rucSecurityLevel, uint32_t* a_puiRemainedTime=NULL, uint8_t* a_pucRemainedCount=NULL);
SCPDLL_CEXFNC int     gfAccOwnUsage();    // 원본 SCB의 사용횟수를 누적하여, 자신의 파일에 저장시키기 위해, 프로세스 종료를 예약하고, 결과 코드를 리턴한다.(0=관련없음, 음수=실패, 양수=수행완료)
SCPDLL_CEXFNC void    gfClearAll(bool a_bStories=false);  // 모든 멤버변수들의 데이터를 지운다.
// -----------------------------------------------------------------------------
#endif // __SCP_LIB_H__
