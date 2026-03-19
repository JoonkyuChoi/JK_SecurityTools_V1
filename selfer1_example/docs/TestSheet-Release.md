## 단위 테스트 (Release) : 4급 보안 자체검증 예제 어플 (selfer1_example.exe)

본 문서는 `3급 보안 자체검증 코어 라이브러리 (jkd_security3_selfer1_core.lib)`를 사용한 예제 `어플(selfer1_example.exe)`을 테스트한 것이다.</br>
홍보용으로 공개된 `4급 보안 자체검증 데모 (jkd_security4_selfer1.exe)`도 해당 라이브러리를 사용한 것이다.

예제 소스 코드를 공개하기 위해, 별도로 제작한 것이 본 `어플(selfer1_example.exe)`이다.</br>
이제, 본 `4급 보안 자체검증 예제 어플 (selfer1_example.exe)`을 활성화하고, 단위 테스트를 수행하자.


### 준비 작업
```markdown
> 본 예제 프로젝트(selfer1_example)를 `Release` 모드에서 빌드한다.
> 공개된 `홍보용 3급 주입툴(jkd_security3_injector1)`로 SCB를 주입(활성화)하여, 단위 테스트를 수행한다.
```

### 테스트
```
--------------------------------------------------------------------------------
[자체=검증:성공:Release] 2-2차 출력 확인 (유효기간 무기한 확인)
--------------------------------------------------------------------------------
> selfer1_example

================================================================================
*****************   JK-Dreams, Security Codes Selfer V1 Demo   *****************
================================================================================
                                                                 Promotional (R)
----------------------------------------
>> SECURITY WARNING AND TERMS
----------------------------------------
* JK-Dreams' special security products have a limited expiration date.
  > This program is a PUBLIC-LEVEL security product.
  > If this program becomes corrupted or expires, it will be automatically removed.
* Terms and Conditions (Demo Program)
  1. Privacy Protection
    This demo program is designed not to collect or transmit any personally identifiable information or data from your system.
  2. Grant of License
    This demo program is FREE SOFTWARE that anyone may use.
    Users are granted the right to use this demo program free of charge for testing, evaluation, and non-commercial purposes only.
    Furthermore, any products additionally developed using jkd_security3_selfer1_core.lib may be used solely for non-commercial purposes.
  3. Limitation of Liability
    This demo program is provided "AS IS" without any warranties.
    The Developer shall not be held legally liable for any issues arising from the use of the demo program,
    including but not limited to data loss, system failure, or any other direct or indirect damages.
    The Developer is under no obligation to provide compensation, indemnification, or technical support of any kind.
    All responsibility for the results of using this demo program rests entirely with the user.
----------------------------------------

                 Copyright (c) 2026 ~ Reserved by JoonKyu Choi <osoi@naver.com>.
================================================================================

[INF] This program is valid.
      You can use it indefinitely.
----------------------------------------
Press any key. The current screen disappears.

```

```
--------------------------------------------------------------------------------
[자체=검증:대상=주입:성공:Release] 2-1차 (주입툴의 대상주입으로, 자체검증기에 [패스워드=불용/보안레벨=4/사용횟수=0/유효기간=0=무기한] 주입하기)
--------------------------------------------------------------------------------
> 다시 빌드하여 재생성
> ..\jkd_security3_injector1 selfer1_example.exe

================================================================================
******************   JK-Dreams, Security Codes Injector V1   *******************
================================================================================
                                                                 Promotional (R)
----------------------------------------
>> SECURITY WARNING AND TERMS
----------------------------------------
* JK-Dreams' special security products have a limited expiration date.
  > This program is a TOP-CLASS security product.
  > If this program becomes corrupted or expires, it will be automatically removed.
* Terms and Conditions (Promotional Edition)
  1. Privacy Protection
    This program does not collect or transmit any personally identifiable information or data from your system.
  2. Grant of License
    This Program is distributed as a PROMOTIONAL EDITION for the purpose of demonstration and evaluation.
    Users are granted the right to use the Program free of charge, subject to the following conditions:
      > The Program may be used for personal or non-commercial purposes.
      > Commercial use, redistribution, or modification of the Program is not permitted
        without prior written consent from the Developer.
      > This edition may contain limitations compared to the full version.
  3. Limitation of Liability
    This Program is provided "AS IS".
    The Developer shall not be held legally liable for any issues arising from the use of the Program,
    including but not limited to data loss, system failure, or any other direct or indirect damages.
    The Developer is under no obligation to provide compensation or indemnification of any kind.
    All responsibility for the results of using this Program rests entirely with the user.
----------------------------------------

                 Copyright (c) 2026 ~ Reserved by JoonKyu Choi <osoi@naver.com>.
================================================================================

Do you want to proceed? (y/n): y

----------------------------------------
[1] Self Validating...
----------------------------------------
> State : Validation Need
> File  : D:\E\Job\Security_V1_2026\docs\dist\V1\promo\release\selfer1_example\bin\jkd_security3_injector1.exe
--------------------
[1-1] File hashing...
--------------------
[######################################] 100%
Hash completed.
--------------------
[1-2] Valid-term Checking...
--------------------
> Valid-term   : You can use this indefinitely.
----------------------------------------
[2] Detection results for own SCB
----------------------------------------
> State : Validation Done
> File  : D:\E\Job\Security_V1_2026\docs\dist\V1\promo\release\selfer1_example\bin\jkd_security3_injector1.exe
> Result:
  [INF] This SCF has been validated.
        The SCB was injected at 20260311-103824 and can be used indefinitely.

Shall we start verifying the target? (y/n): y

----------------------------------------
[3] SCB Injecting...
----------------------------------------
> State : Injection Need
> File  : selfer1_example.exe
--------------------

Inject SCB into specified file? (y/n): y

Enter the password to apply to the tool (0 ~ 32 bytes):
--------------------
[3-1] Request Injector Informations
--------------------
Select the security level of the target file (4 ~ 9): 4
--------------------
[3-2] Valid-term Limiting...
--------------------
Do you want to limit the files based on number of uses? (0 ~ 255): 0
Select valid-term unit: 0=unlimit, 1=minute, 2=hour, 3=day, 4=month, 5=year (0 ~ 5): 0

> Valid-term   : You can use this indefinitely.
> Injected Time: 20260314-112623
--------------------
[3-3] File hashing...
--------------------
[######################################] 100%
Hash completed.
--------------------
[3-4] Saving into file...
--------------------
Save completed.
----------------------------------------
[4] Detection results for target SCB
----------------------------------------
> State : Injection Done
> File  : selfer1_example.exe
> Result:
  [INF] Injected a SCB in the target SCF.
        The SCB was injected at 20260314-112623 and can be used indefinitely.
----------------------------------------
Press any key. The current screen disappears.

```

```
--------------------------------------------------------------------------------
[자체=검증:성공:Release] 1-3차 (패스워드 입력, 사용횟수 만료, 자체 소멸 확인)
--------------------------------------------------------------------------------
> selfer1_example

================================================================================
*****************   JK-Dreams, Security Codes Selfer V1 Demo   *****************
================================================================================
                                                                 Promotional (R)
----------------------------------------
>> SECURITY WARNING AND TERMS
----------------------------------------
* JK-Dreams' special security products have a limited expiration date.
  > This program is a PUBLIC-LEVEL security product.
  > If this program becomes corrupted or expires, it will be automatically removed.
* Terms and Conditions (Demo Program)
  1. Privacy Protection
    This demo program is designed not to collect or transmit any personally identifiable information or data from your system.
  2. Grant of License
    This demo program is FREE SOFTWARE that anyone may use.
    Users are granted the right to use this demo program free of charge for testing, evaluation, and non-commercial purposes only.
    Furthermore, any products additionally developed using jkd_security3_selfer1_core.lib may be used solely for non-commercial purposes.
  3. Limitation of Liability
    This demo program is provided "AS IS" without any warranties.
    The Developer shall not be held legally liable for any issues arising from the use of the demo program,
    including but not limited to data loss, system failure, or any other direct or indirect damages.
    The Developer is under no obligation to provide compensation, indemnification, or technical support of any kind.
    All responsibility for the results of using this demo program rests entirely with the user.
----------------------------------------

                 Copyright (c) 2026 ~ Reserved by JoonKyu Choi <osoi@naver.com>.
================================================================================

Enter this tool's password (1 ~ 32 bytes): **************
[WRN] This program's valid-term has expired.
----------------------------------------
Press any key. The current screen disappears.

```

```
--------------------------------------------------------------------------------
[자체=검증:성공:Release] 1-2차 (패스워드 입력, 사용횟수 감소)
--------------------------------------------------------------------------------
> selfer1_example

================================================================================
*****************   JK-Dreams, Security Codes Selfer V1 Demo   *****************
================================================================================
                                                                 Promotional (R)
----------------------------------------
>> SECURITY WARNING AND TERMS
----------------------------------------
* JK-Dreams' special security products have a limited expiration date.
  > This program is a PUBLIC-LEVEL security product.
  > If this program becomes corrupted or expires, it will be automatically removed.
* Terms and Conditions (Demo Program)
  1. Privacy Protection
    This demo program is designed not to collect or transmit any personally identifiable information or data from your system.
  2. Grant of License
    This demo program is FREE SOFTWARE that anyone may use.
    Users are granted the right to use this demo program free of charge for testing, evaluation, and non-commercial purposes only.
    Furthermore, any products additionally developed using jkd_security3_selfer1_core.lib may be used solely for non-commercial purposes.
  3. Limitation of Liability
    This demo program is provided "AS IS" without any warranties.
    The Developer shall not be held legally liable for any issues arising from the use of the demo program,
    including but not limited to data loss, system failure, or any other direct or indirect damages.
    The Developer is under no obligation to provide compensation, indemnification, or technical support of any kind.
    All responsibility for the results of using this demo program rests entirely with the user.
----------------------------------------

                 Copyright (c) 2026 ~ Reserved by JoonKyu Choi <osoi@naver.com>.
================================================================================

Enter this tool's password (1 ~ 32 bytes): **************
[INF] This program is valid.
      You can be used 1 more times.
----------------------------------------
Press any key. The current screen disappears.

```

```
--------------------------------------------------------------------------------
[자체=검증:대상=주입:성공:Release] 1-1차 (주입툴의 대상주입으로, 자체검증기에 [패스워드=적용/보안레벨=4/사용횟수=1/유효기간=0=무기한] 주입하기)
--------------------------------------------------------------------------------
> ..\jkd_security3_injector1 selfer1_example.exe

================================================================================
******************   JK-Dreams, Security Codes Injector V1   *******************
================================================================================
                                                                 Promotional (R)
----------------------------------------
>> SECURITY WARNING AND TERMS
----------------------------------------
* JK-Dreams' special security products have a limited expiration date.
  > This program is a TOP-CLASS security product.
  > If this program becomes corrupted or expires, it will be automatically removed.
* Terms and Conditions (Promotional Edition)
  1. Privacy Protection
    This program does not collect or transmit any personally identifiable information or data from your system.
  2. Grant of License
    This Program is distributed as a PROMOTIONAL EDITION for the purpose of demonstration and evaluation.
    Users are granted the right to use the Program free of charge, subject to the following conditions:
      > The Program may be used for personal or non-commercial purposes.
      > Commercial use, redistribution, or modification of the Program is not permitted
        without prior written consent from the Developer.
      > This edition may contain limitations compared to the full version.
  3. Limitation of Liability
    This Program is provided "AS IS".
    The Developer shall not be held legally liable for any issues arising from the use of the Program,
    including but not limited to data loss, system failure, or any other direct or indirect damages.
    The Developer is under no obligation to provide compensation or indemnification of any kind.
    All responsibility for the results of using this Program rests entirely with the user.
----------------------------------------

                 Copyright (c) 2026 ~ Reserved by JoonKyu Choi <osoi@naver.com>.
================================================================================

Do you want to proceed? (y/n): y

----------------------------------------
[1] Self Validating...
----------------------------------------
> State : Validation Need
> File  : D:\E\Job\Security_V1_2026\docs\dist\V1\promo\release\selfer1_example\bin\jkd_security3_injector1.exe
--------------------
[1-1] File hashing...
--------------------
[######################################] 100%
Hash completed.
--------------------
[1-2] Valid-term Checking...
--------------------
> Valid-term   : You can use this indefinitely.
----------------------------------------
[2] Detection results for own SCB
----------------------------------------
> State : Validation Done
> File  : D:\E\Job\Security_V1_2026\docs\dist\V1\promo\release\selfer1_example\bin\jkd_security3_injector1.exe
> Result:
  [INF] This SCF has been validated.
        The SCB was injected at 20260311-103824 and can be used indefinitely.

Shall we start verifying the target? (y/n): y

----------------------------------------
[3] SCB Injecting...
----------------------------------------
> State : Injection Need
> File  : selfer1_example.exe
--------------------

Inject SCB into specified file? (y/n): y

Enter the password to apply to the tool (0 ~ 32 bytes): **************
Enter the tool's password again (0 ~ 32 bytes): **************
--------------------
[3-1] Request Injector Informations
--------------------
Select the security level of the target file (4 ~ 9): 4
--------------------
[3-2] Valid-term Limiting...
--------------------
Do you want to limit the files based on number of uses? (0 ~ 255): 1
Select valid-term unit: 0=unlimit, 1=minute, 2=hour, 3=day, 4=month, 5=year (0 ~ 5): 0

> Valid-term   : Can be used 1 times.
> Injected Time: 20260314-112346
--------------------
[3-3] File hashing...
--------------------
[######################################] 100%
Hash completed.
--------------------
[3-4] Saving into file...
--------------------
Save completed.
----------------------------------------
[4] Detection results for target SCB
----------------------------------------
> State : Injection Done
> File  : selfer1_example.exe
> Result:
  [INF] Injected a SCB in the target SCF.
        The SCB was injected at 20260314-112346 and can be used 1 more times.
----------------------------------------
Press any key. The current screen disappears.

```

```
--------------------------------------------------------------------------------
[자체=검증:실패:Release] 최초 자체 검증 (SCB 비활성 상태지만, 유효 여부만 표출)
--------------------------------------------------------------------------------
> selfer1_example

================================================================================
*****************   JK-Dreams, Security Codes Selfer V1 Demo   *****************
================================================================================
                                                                 Promotional (R)
----------------------------------------
>> SECURITY WARNING AND TERMS
----------------------------------------
* JK-Dreams' special security products have a limited expiration date.
  > This program is a PUBLIC-LEVEL security product.
  > If this program becomes corrupted or expires, it will be automatically removed.
* Terms and Conditions (Demo Program)
  1. Privacy Protection
    This demo program is designed not to collect or transmit any personally identifiable information or data from your system.
  2. Grant of License
    This demo program is FREE SOFTWARE that anyone may use.
    Users are granted the right to use this demo program free of charge for testing, evaluation, and non-commercial purposes only.
    Furthermore, any products additionally developed using jkd_security3_selfer1_core.lib may be used solely for non-commercial purposes.
  3. Limitation of Liability
    This demo program is provided "AS IS" without any warranties.
    The Developer shall not be held legally liable for any issues arising from the use of the demo program,
    including but not limited to data loss, system failure, or any other direct or indirect damages.
    The Developer is under no obligation to provide compensation, indemnification, or technical support of any kind.
    All responsibility for the results of using this demo program rests entirely with the user.
----------------------------------------

                 Copyright (c) 2026 ~ Reserved by JoonKyu Choi <osoi@naver.com>.
================================================================================

[WRN] This program is invalid.
----------------------------------------
Press any key. The current screen disappears.

```

```
--------------------------------------------------------------------------------
[자체=검증:오류:Release] 출력 확인 (단위 테스트 제공 안함, 유효 여부만 표출)
--------------------------------------------------------------------------------
> selfer1_example -t

================================================================================
*****************   JK-Dreams, Security Codes Selfer V1 Demo   *****************
================================================================================
                                                                 Promotional (R)
----------------------------------------
>> SECURITY WARNING AND TERMS
----------------------------------------
* JK-Dreams' special security products have a limited expiration date.
  > This program is a PUBLIC-LEVEL security product.
  > If this program becomes corrupted or expires, it will be automatically removed.
* Terms and Conditions (Demo Program)
  1. Privacy Protection
    This demo program is designed not to collect or transmit any personally identifiable information or data from your system.
  2. Grant of License
    This demo program is FREE SOFTWARE that anyone may use.
    Users are granted the right to use this demo program free of charge for testing, evaluation, and non-commercial purposes only.
    Furthermore, any products additionally developed using jkd_security3_selfer1_core.lib may be used solely for non-commercial purposes.
  3. Limitation of Liability
    This demo program is provided "AS IS" without any warranties.
    The Developer shall not be held legally liable for any issues arising from the use of the demo program,
    including but not limited to data loss, system failure, or any other direct or indirect damages.
    The Developer is under no obligation to provide compensation, indemnification, or technical support of any kind.
    All responsibility for the results of using this demo program rests entirely with the user.
----------------------------------------

                 Copyright (c) 2026 ~ Reserved by JoonKyu Choi <osoi@naver.com>.
================================================================================

[WRN] This program is invalid.
----------------------------------------
Press any key. The current screen disappears.

```
