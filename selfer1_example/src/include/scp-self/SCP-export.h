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
	SCP-export.h : [보안자체검증기 전용] 보안코드처리기 노출 [클래스/함수/변수]들의 서두 정의
  
	Revision History :
		[2026/02/13:최준규]	first written by JK.Choi
==============================================================================*/
#ifndef __SCP_LIB_EXPORT_H__
#define __SCP_LIB_EXPORT_H__
// -----------------------------------------------------------------------------
// [SCPDLL_MAKING]를 정의하면, 동적라이브러리를 export하여 생성하게 된다.
// [SCPDLL_USING ]를 정의하면, 동적라이브러리를 임포트하여 사용하게 된다.
// [SCPDLL_MAKING/SCPDLL_USING]를 정의하지 않으면, 정적라이브러리로 동작한다.
// -----------------------------------------------------------------------------
#ifdef _MSC_VER
	// -------------------------------------
	// 공용
	// -------------------------------------
	// 소스를 [동적/정적] 2가지 라이브러리로 사용할 때
	#if defined(SCPDLL_MAKING)		// DLL 제작단에서 정의
		#define SCPDLL_EXP			__declspec(dllexport)
	#elif defined(SCPDLL_USING)	  // DLL 사용단에서 정의
		#define SCPDLL_EXP			__declspec(dllimport)
	#else
		#define SCPDLL_EXP          // LIB로 사용
	#endif
	#define SCPDLL_EXT			  extern
	// -------------------------------------
	// C++전용
	// -------------------------------------
	// 변수   DLL 외부노출 표현	(ex: SCPDLL_EXVAL int a;)
	#define SCPDLL_EXVAL			SCPDLL_EXT SCPDLL_EXP
	// 함수   DLL 외부노출 표현 (ex: SCPDLL_EXFNC int a();)
	#define SCPDLL_EXFNC			SCPDLL_EXP
	// 클래스 DLL 외부노출 표현 (ex: SCPDLL_EXCLS a : public b)
	#define SCPDLL_EXCLS			class SCPDLL_EXP
	// -------------------------------------
	// C전용
	// -------------------------------------
	#ifdef __cplusplus
		#define SCPDLL_CEXT		  extern "C"
	#else
		#define SCPDLL_CEXT		  extern
	#endif
	// 변수   DLL 외부노출 표현	(ex: SCPDLL_CEXVAL int a;)
	#define SCPDLL_CEXVAL		  SCPDLL_CEXT SCPDLL_EXP
	// 함수   DLL 외부노출 표현 (ex: SCPDLL_CEXFNC int a();)
	#define SCPDLL_CEXFNC		  SCPDLL_CEXT SCPDLL_EXP
	// -------------------------------------
#else
	#define SCPDLL_EXP
	#define SCPDLL_EXT			  extern
	// -------------------------------------
	// C++전용
	// -------------------------------------
	#define SCPDLL_EXVAL			SCPDLL_EXT
	#define SCPDLL_EXFNC
	#define SCPDLL_EXCLS			class
	// -------------------------------------
	// C전용
	// -------------------------------------
	#ifdef __cplusplus
		#define SCPDLL_CEXT		  extern "C"
	#else
		#define SCPDLL_CEXT		  extern
	#endif
	#define SCPDLL_CEXVAL		  SCPDLL_CEXT
	#define SCPDLL_CEXFNC		  SCPDLL_CEXT
	// -------------------------------------
#endif
// -----------------------------------------------------------------------------
#endif  // __SCP_LIB_EXPORT_H__
