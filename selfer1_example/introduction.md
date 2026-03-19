## 자체검증 4급 보안 데모 프로그램과, 3급 보안 라이브러리
```
- 소개
  > SCB를 SCF에 내장시키고, 제공하는 자체검증 기능을 테스트하는 데모 어플이다.
    자체검증만을 제공하는 3급 보안 라이브러리를 내장하여, 사용하는 방법을 보여주기 위한 예제 어플이다.
  > 코어 라이브러리는 3급 보안이며, 데모 어플은 4급 보안에 해당한다.
    [키입력요청/대상주입/대상검증] 기능이 제외된 어플이지만, [비번입력]은 가능하도록 처리하였다.
    만약에, GUI 어플로 제작한다면, 이벤트(sfEvent) 함수를 참조하여, 응용하면 된다.
  > 본 데모 어플은 3급 보안 주입기로, SCB를 주입시켜야 활성화 된다.
  
- 제공 기능
  > 자체 SCB 검증 (초간단 검증)
    - 사용자의 키입력 요청과, 메세지 출력 부분들을 모두 제거한다. (비번입력 요청 제외)
    - 사용횟수를 누적하려면, 어플단에서 gfAccOwnUsage() 함수를 직접 호출해야 한다.
  
- 보안 경고문과 이용약관 (데모 프로그램)
  > 영문
    SECURITY WARNING AND TERMS
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
  > 한글
    보안 경고와 약관
    * JK-Dreams의 특수한 보안제품에는 유효기간이 정해져 있습니다.
      > 본 프로그램은 공개 수준의 보안 제품입니다.
      > 본 프로그램이 손상되거나 만료되면, 자동으로 제거됩니다.
    * 이용 약관 (데모 프로그램)
      1. 개인정보 보호
        본 데모 프로그램은 귀하의 시스템에서, 어떠한 개인 식별 정보나 데이터를 수집하거나, 전송하지 않도록 설계되었습니다.
      2. 라이센스 부여
        본 데모 프로그램은 누구나 자유롭게 사용할 수 있는 무료 소프트웨어입니다.
        사용자에게는 시험적·평가적·비상업적 목적으로, 본 데모 프로그램을 무료로 사용할 권리가 부여됩니다.
        또한, 사용자가 `jkd_security3_selfer1_core.lib`를 이용하여, 추가적으로 개발한 제품은 비상업적 목적으로만 사용할 수 있습니다.
      3. 책임의 제한
        본 데모 프로그램은 어떠한 보증도 없이 "있는 그대로" 제공됩니다.
        개발자는 데모 프로그램 사용으로 인해 발생하는 데이터 손실, 시스템 오류 또는 기타 직간접적 손해를 포함하되,
        이에 국한되지 않는 모든 문제에 대해, 법적 책임을 지지 않습니다.
        개발자는 어떠한 종류의 보상, 면책 또는 기술 지원도 제공할 의무가 없습니다.
        본 데모 프로그램의 사용 결과에 대한, 모든 책임은 전적으로 사용자에게 있습니다.
```
