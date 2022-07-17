PDF FILE

[https://github.com/42seoul-translation/subject_ko/blob/65b67d094f93be7cf527f23eacf6f33e86eea2e5/born2beroot/born2beroot_ko.md](https://github.com/42seoul-translation/subject_ko/blob/65b67d094f93be7cf527f23eacf6f33e86eea2e5/born2beroot/born2beroot_ko.md)

4차 회귀

install software까지 갔지만 ssh server를 체크하고 실행했지만 실패

5차 회귀

궁금해서 논리 디스크 sda5를 원래 crypt disk를 하고 해야하는데 안하고 파티션을 전부 나눈 뒤 crypt를 진행해 보았다 디스크 하나하나에 crypt가 걸리고 보안화 되는 장점이 있지만 귀찮다 하나하나 설정하는게 하다가 밥먹고 오니 컴퓨터 재부팅됨 ㅎ;

6차 회귀

원래 15.4GB로 나누는데 14.4GB로 나눴다. SCSI2 → SCSI1 로 바뀜

15.4 로 나눌때 디스크의 크기가 이상하게 16.4  로 잡히게 되는데 이유를 알았다. 보너스 디스크 파티션 구조를 확인해보면 아래에 sr0이라는 항목이 있는데 virbox에서 기본적으로 할당하는 용량이 1gb정도 있는 것 같다. “sr0” 다른 분께 여쭤보니 cd룸 영역 이라고 한다 아마 맨 처음에 부팅에 필요한 ios파일을 받을 때 가상 디스크를 사용해서 부팅을 받는 것 같은데 그 때 사용하기 위한 영역 이라는 생각이 든다.

7차 회귀

슬슬 익숙해진다 이말이여

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2e49cd07-9e62-4b2d-bfef-52f9fb9edd22/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/37dbe912-b7d5-4070-8117-480b74d76907/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0cfeb315-0332-4fc0-a47e-ea1174da04a2/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7da53873-98ee-4c93-a1d9-5d48ce6a8714/Untitled.png)

- VDI(Virtual Disk Image)
    - Oracle 버츄얼박스에서만 사용 가능한 포멧방식
- VHD(Vurtual Hard Disk)
    - Oracle 버츄얼박스, 마이크로소프트( Microsoft) 의 Hyper-V. 시트릭스(Citrix)의 Xen에서 구동 가능한 포멧방식
- VMDK(Virtual Machine Disk)
    - Oracle의 버츄얼박스, VMware의 VMware Player에서 구동이 가능한 포멧방식

[출처 : https://apophis0.tistory.com/48](https://apophis0.tistory.com/48)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/748a5d16-db14-4167-8397-c947314c62ef/Untitled.png)

- 동적 할당
    - 가상 디스크에 용량을 설정한데로 용량을 잡는게 아니고 채워지는 만큼 용량이 증가한다.
- 고정 크기
    - 가상디스크에 용량을 설정한데로 미리 잡아두고 사용하는 방식입니다.

가상 디스크 용량 설정이 10기가 이고 실제 사용량이 5기가 일경우

동적 할당 = 실제 물리 하드에 5~6기가 정도 사용 고정크기보다 속도가 느림

고정 크기 = 실제 물리 하드에 10기가 사용 속도가 더 빠름

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/11cb18c4-b64a-4f87-b61e-2644e45c2246/Untitled.png)

보너스 같은 경우 최상위 파티션의 용량이 30기가가 넘기 때문에 너무 크니 반뚝덜 해서 15.4기가로 가겠다.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a1f1e01d-f613-4d39-9f80-1fdc575a491f/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d542fd23-f89c-4bb6-895d-0e7be4864bc3/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/801630e9-9162-4e5c-b645-7146d08965f6/Untitled.png)

command+c 누르면 비율대로 커짐

command = 마우스 포인터 탈출

출처: jibae

- debian-installer는 DHCP를 사용하여 네트워크를 자동으로 설정
- 자동으로 네트워크 설정에 실패할 시 수동으로 설정 가능
    - DHCP(Dynamic Host Configuration Protocol)
        - DHCP란 호스트의 IP주소와 각종 TCP/IP 프로토콜의 기본 설정을 클라이언트에게 자동적으로 제동해주는 프로토콜을 말합니다. DHCP에 대한 표준은 RFC문서에 정의되어 있으며 DHCP서버가 중앙 집중식으로 관리하는 클라이언트/서버 모델을 사용하게 됩니다.
        - DHCP지원 클라이어트는 네트워크 부팅과정에서 DHCP서버에 IP주소를 요청하고 이를 얻을 수 있습니다.
        
        네트워크 안에 컴퓨터에 자동으로 네임 서버 주소, IP주소, 게이트웨이 주소를 할당해주는 것을 의미하고, 해당 클라이언트에게 일정 기간 임대를 하는 동적 주소 할당 프로토콜입니다.
        
        - **DHCP 장점**
        
        PC의 수가 많거나 PC 자체 변동사항이 많은 경우 IP 설정이 자동으로 되기 때문에 효율적으로 사용 가능하고, IP를 자동으로 할당해주기 때문에 IP 충돌을 막을 수 있습니다.
        
        - **DHCP 단점**
        
        DHCP 서버에 의존되기 때문에 서버가 다운되면 IP 할당이 제대로 이루어지지 않습니다.
        

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/05c718c7-e1dd-416c-86d4-f760e26910e8/Untitled.png)

![스크린샷 2022-03-02 오후 8.36.18.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/20746ebb-0a1d-4979-8ef9-cfec65a5f6a8/스크린샷_2022-03-02_오후_8.36.18.png)

![스크린샷 2022-03-02 오후 8.36.32.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d33eae19-5f60-4842-8b0d-43ab3e2efcca/스크린샷_2022-03-02_오후_8.36.32.png)

![스크린샷 2022-03-02 오후 8.37.52.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fc2777be-4278-4c1a-a691-663126ed8aae/스크린샷_2022-03-02_오후_8.37.52.png)

![스크린샷 2022-03-02 오후 8.39.48.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/518e3acd-1e6f-40e2-848a-e25e9e0d97e8/스크린샷_2022-03-02_오후_8.39.48.png)

(암호화된 LVM)

서브젝트에서 원하는 요구사항을 맞추기 위하여 디스크 파티션을 나눠여함

운영체제애서 파티션을 나누면 그 정보는 파티션 테이블(Partition Table)로 넘어가게 된다.

 

- 파티션 타이블(Partition Table)
    - 저장장치에서 사용하는 파티션을 묶어 저장장치의 맨 앞부분에 모아 부팅 시에 컴퓨터가 불어올 수 있도록 하는 정보이다.

디스크의 파티션을 설명하는 자료 구조이다. 파티션 테이블 및 파티션 맵이라는 용어는 [IBM](https://ko.wikipedia.org/wiki/IBM)
 PC 호환 장치 [MBR](https://ko.wikipedia.org/wiki/MBR)
 (Master Boot Record)의 MBR 파티션 테이블을 가리키는 경우가 흔하나, 다른 디스크 드라이브 파티션 방식을 두고 부를 때도 있다. 예를 들면 GPT (GUID Partition Table), APM (Apple partition map), 또는 BSD 디스크 레이블과 같은 방식이 있다.

![Screen Shot 2022-03-05 at 4.45.36 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/62bf2bf8-acdd-424f-82c9-a954888e6543/Screen_Shot_2022-03-05_at_4.45.36_PM.png)

SCSI (SmallComputer SystemsInterface)

  ㅇ컴퓨터와주변장치를 연결하는 외부 입출력버스구조(ExternalBus Structure)에 대한
     일련의 규격 (전기적,기계적 요구사항 및명령어 집합,구조 등)

![Screen Shot 2022-03-05 at 5.36.19 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/20035b18-087c-492e-bfbc-a5d4950702e6/Screen_Shot_2022-03-05_at_5.36.19_PM.png)

- 마운트 포인트 설정
    - 마운트 포인트란? (mount point)
        - 리눅스에서 여러가지 하드웨어 장치들을 사용하기 위해 리눅스라는 운영체제에 인식시켜야하는데 이를 가능하게 해주는 것이 마운트(mount)라고 한다.
        - 즉, 마운트란 리눅슷 시스템에서 사용하기를 원하는 특정장치를 시스템에 인식시키는 작업인데 이러힌 장치들을 특정 디렉토리에 연결해야 장치들을 사용할 수 있고 이때 말하는 특정 디렉토리라하는 것이 마운트 포인트(mount point)이다.
            
            ![Screen Shot 2022-03-05 at 7.34.27 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1cf473e2-7c0b-4bf1-97d6-0791bc82cc08/Screen_Shot_2022-03-05_at_7.34.27_PM.png)
            
            부트로 설정하기
            
            커널 부트 이미지 파티션으로 나뉘어진다.
            
            ![Screen Shot 2022-03-05 at 7.35.29 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2929700d-84c7-46b4-b000-2dc52d3621d9/Screen_Shot_2022-03-05_at_7.35.29_PM.png)
            

리눅스에는 세 가지 종류의 파티션이 있다.

1. Primary Partition (주 영역 파티션)

실제로 영역을 나누는 것 실제로 변하지 않는,필요한 정보를 저장하는 용도로 사용하는 것 같다.

기본적으로 리눅스 구조에서 총 4개까지 만들 수 있는 것 같다.

ex) boot, var, 사용자 정보 등등등

2. Extended Partition (확장 영역 파티션)

아직 할당되지 않은 파티션 primary partition이든 logical Partition이든될 수 있는 것 같다. 

3. Logical Partition (논리 영역 파티션)

말 그대로 extended partition에서 논리로 나눈 파티션 이다.

논리 파티션의 경우 주 파티션보다 좀 더 많이 나눌 수 있다.

데이터를 저장할 수 있지만 운영체제는 설치 불가능하다

(암호화 된 디스크의 비밀번호 설정)

![Screen Shot 2022-03-05 at 8.07.11 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d2956ff2-b1ea-4d0f-8f41-3c8770b8fa58/Screen_Shot_2022-03-05_at_8.07.11_PM.png)

![Screen Shot 2022-03-05 at 8.11.03 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/932f121b-1c8c-4da8-ad74-5ca203d9bbc2/Screen_Shot_2022-03-05_at_8.11.03_PM.png)

논리화 디스크를 세부 설정하기 

![Screen Shot 2022-03-05 at 8.44.18 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e1464e2d-eb99-494c-b1e2-d0b7d953fb92/Screen_Shot_2022-03-05_at_8.44.18_PM.png)

확장 파티션을 논리 파티션으로 세분화하기 위해 논리 파티션들을 묶을 그룹이 필요하다

![Screen Shot 2022-03-05 at 8.45.42 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a40923c4-f40e-4c4e-b8f6-d22d5f6222b5/Screen_Shot_2022-03-05_at_8.45.42_PM.png)

- Ex4 journaling file system 선택
- Ex4 파일 시스템 : Ex3 파일 시스템을 개선한 버전으로 대용량 파일 시스템을 지원
- Ex3과 호환 가능
- Ex4 파일 시스템을 사용할 것을 권장

![Screen Shot 2022-03-05 at 8.56.29 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2740c175-44f2-4c7e-b67a-96dbe69bd05e/Screen_Shot_2022-03-05_at_8.56.29_PM.png)

![Screen Shot 2022-03-05 at 8.57.41 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/75297572-0280-444f-8b77-57e1ebf4e4c8/Screen_Shot_2022-03-05_at_8.57.41_PM.png)

![Screen Shot 2022-03-05 at 8.57.53 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/cc58bc4b-290e-4888-a86d-8dbba9c0d654/Screen_Shot_2022-03-05_at_8.57.53_PM.png)

 sudo(superUser Do)

- sudo란?
    - sudo 명령어는 유닉스 및 리눅스 계역에서 다른 사용자의 보안 권한과 관련된 프로그램을 구동할 수 있게 해주는 프로그램이다.
- sudo 사용 이유
    - 최소 권한 규칙에 의거하여 root로 로그인하는 것은 차단하고 root권한이 필요할 경우에만 sudo 명령어를 사용하여 제한적으로 실행하는 것이 시스템 안정성과 보안 측면에서 좋은 습관이다.
        
        [https://deois.tistory.com/entry/sudo사용의-필요성](https://deois.tistory.com/entry/sudo%EC%82%AC%EC%9A%A9%EC%9D%98-%ED%95%84%EC%9A%94%EC%84%B1)
        
- sudo, su, su -의 차이점
    - sudo
        - 다른 사용자 계정의 권한을 빌려서 프로그램을 실행할 수 있도록 하는 명령어 보통 root권한으로 되어있다.
    - su
        - 사용 계정을 다른 사용자로 옮기는 것
    - su -
        - 사용 계정을 다른 사용자로 옮기는 것 으로 su와 같으나 환경변수 path나 관련 세팅값이 같이 딸려간다 su는 따라오지않는다.
