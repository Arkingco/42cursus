# 42_libft
libft intra clear
# [LIBFT] 함수 정리 & 디펜스 TIL

### man part

-


- ft_is 함수들

    isalpha
    isdigit
    isalnum
    isascii
    isprint

    실수할게 딱히 없지만 조심하자 man 을 사용해서 만들어야 하기 때문에 man 과 같은 내용(자료형, 반환값)등등을 담을 수 있도록 확인을 철저히 하자


- size_t 형이란 무었인가.
    - size_t의 명시적 정의 [https://namu.wiki/w/size_t](https://namu.wiki/w/size_t)
    - size_t는 해당 시스템에서 어떤 객체나 값이 포함할 수 있는 최대 크기의 데이터를 표현하는 타입으로 반드시 unsigned 형으로 나타낸다.아래는 C99 원문.  이 내용이 가장 중요하고 알고있으면된다.

- restrict 란 무었인가
    - 컴파일러에게 두 포인터 변수가 오버랩 되는 일이 없으니 오버랩을 생각하지 말고 함수를 만들어라 라고 하는 형지정자
    - restrict 포인터는 메모리 접근에 관련된 최적화 기능입니다(C99 표준). 예를 들어 다음과 같이 포인터를 역참조하여 값을 증가시키는 코드가 있습니다.


- ft_memmove 와 ft_memcpy의 차이점 과 오버랩
    - memmove는 오버랩을 메모리 오버랩을 막아주고 memcpy는 메모리 오버랩을 못 막아줍니다.
        - 메모리 오버랩이란?

            테스트

            ```c
            char a[10] = "12345";
            ft_memcpy(a+1, a, 5);
            ```

            실행기댓값

            ```c
            "11234"
            ```

            실제 실행값

            ```c
            "11111"
            ```

            왜?

            ```c
            void	*ft_memcpy(void *dst, const void *src, size_t n)
            {
            	unsigned char		*idst;
            	const unsigned char	*isrc;
            	size_t				i;

            	if ((!dst && !src) && n)
            		return (0);
            	i = 0;
            	idst = (unsigned char *)dst;
            	isrc = (const unsigned char *)src;
            	while (i < n)
            	{
            		idst[i] = isrc[i];
            		++i;
            	}
            	return (idst);
            }
            ```

            memcpy는 다음과 같은 함수로 구성되어있다. 여기서 만약

            ![Notes_211210_151130.jpg](%5BLIBFT%5D%20%E1%84%92%E1%85%A1%E1%86%B7%E1%84%89%E1%85%AE%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%B5%20&%20%E1%84%83%E1%85%B5%E1%84%91%E1%85%A6%E1%86%AB%E1%84%89%E1%85%B3%20TIL%20f3f0293dd299496d8befab986004e4f8/Notes_211210_151130.jpg)


- ft_*_fd
    - *_fd 함수는 구현이 어렵지는 않지만 물어뜯으면 뜯길게 굉장히 많은 함수이다. 기본적으로 write함수 기반으로 작성하게 되는데 **write에서는 파일디스립트** 라는 인자를 받게된다.
    - 파일 디스크립터란?
        - 파일 디스크립터란  [https://dev-ahn.tistory.com/m/96](https://dev-ahn.tistory.com/m/96)
        - [https://code4human.tistory.com/123](https://code4human.tistory.com/123) 이 블로그 정리 굳
        - 파일 디스크립터는 파이프, FIFO, 소켓, 터미널, 디바이스, 일반파일 등 종류에 상관없이 모든 열려있는 파일을 참조할때 쓴다.
        - getconf OPEN_MAX 를 사용하면 시스템의 최대 fd값을 구할 수 있다.

fd는 해당 프로세스의 open file 을 관리하는 구조체 배열의 index.

그 구조체의 index 가 가리키는 객체가 dentry 라는 객체이고, 그 dentry 객체는 또다시 해당 파일을 나타내는 inode 객체를 가리키게 됩니다.

커널 구조체중 struct files_struct 보시면 struct file fd_array 라는 배열이 있다.실제로 open()을 통해 얻는 fd 는 저 구조체의 index 를 나타냅니다.

일반적으로 0, 1, 2 index 는 std-in/std-out/error 와 관련된 fd 로 미리 할당이되고, 보통 open()을 하게 되면 fd 값은 3이 됩니다.

3 번 index 로 test.txt 를 찾는 방법은 우선 fd_array[3] 이 pointing 하고 있는 file 구조체의 f_dentry 를 얻어오게됩니다. dentry 란 것은 directory entry 를 의미하는데, 리눅스에서 디렉토리에 접근을 빠르게 하기 위한 구조체로 사용하고 있습니다. open() 시스템 콜을 호출하게 되면, test.txt 가 존재하는 위치와 관련되어 dentry 구조체가 만들어집니다.

dentry 구조체는 관련된 inode 구조체를 가리키는 필드를 포함합니다.따라서 open("test.txt',...) 함수로 호출된 파일은 test.txt 에 대한 dentry 생성, inode 생성(또는 읽음) 후에 해당 프로세스의 open 파일 관리 구조체인 files_struct 의 fd_array 의 비어있는 위치에 test.txt 의 dentry 를 포인팅하고 그 index 인 3을 넘겨주는 것입니다.

이후 사용자가 3번을 가지고 시스템 콜을 수행하게되면, 해당 프로세스의 files_struct 의 fd_array index 를 통해서 관련 inode에 접근할 수 있게 되는 것입니다.

출처:

[https://dev-ahn.tistory.com/96](https://dev-ahn.tistory.com/96)

라고 훌룡하게 나와있다 새겨듣자!!!

- 함수 설명 및 검수 작업
    - Part_1
        - isalpha(int c)
            - isupper 또는 islower이 true라면 리턴 아니면 0리턴
        - isdigit(int c)
            - 아스키코드 값 '0' < c < '9' 에 있으면 리턴 1 아니면 0리턴
        - isalnum(int c) : 만약 c가 알파벳이거나 숫자라면 리턴 ture 아니면 0
            - isalpha() || isdigit()



        - isasciii(int c)
            - 아스키 코드인지 확인하는 함수 true | 0
        - isprint(int c)
            - 출력가능한 아스키 코드인지 확인하는 함수 true | 0
        - size_t strlen(const char *s)
            - s의 크기가 얼마인지 리턴해주는 함수 자료형 조심하자!!
        - void *memset(void *b, int c, size_t len)
            - void *형 값을 c 로 len 개만큼 초기화 해준다.
        - void bzero(void *s, size_t n)
            - memset과 같은 역할이지만 값만 0으로 초기화
        - void *memcpy(void  *dst, const void  *src, size_t n);
            - dst[i] = src[i] 를 n번 해주기 메모리 복사 (하지만 오버랩 안됨)
        - void *memmove(void dst, const void *str, size_t len);
            - dst[i] = src[i] 를 n번 해주기 메모리 복사 (오버랩 방지 가능)
        - size_t strlcpy(char *dst, char *src, size_t dstsize)
            - src의 문자열을 dst에 문자열 복사하는 함수
            - dstsize에 dst_length + src_length + 1(NULL문자) 까지 넣어 줘야함
            - 널문자를 보장하는 함수
        - size_t strlcat(char * dst, const char * src, size_t dstsize);
            - src 와 dst가 오버랩 되면 behavior 값을 리턴한다.
            - dst 뒤에 src를 dstsize만큼 이어주는 함수
                - dstsize 는 정확하게 작동할려면 dst_length + src_length + 1(null문자 까지) 들어있어야한다.
                - strlcat의 반환형은 두 가지가 있는데 하나는 dst_length ≥ dstsize 일 때 와 아닐 때
                - 리턴값들을 가지고 이 함수가 어떻게 작동 했는지에 대한 정보를 얻을 수 있다. 이 함수가 중간에 끊겼는지 전부 복사가 됐는지 복사 자체가 안됐는지 등등
        - int toupper(int c)
            - 소문자를 대문자로 바꿔주는 함수
        - int tolower(int c)
            - 대문자를 소문자로 바꿔주는 함수
        - char *strchr(const char *s, int c)
            - 앞에서부터 문자열에서 s[i]를 탐색하면서 c가 있는지 확인하는 함수
        - char *strrchr(const char *s, int c)*
            - 뒤에서부터 문자열에서 s[i]를 탐색하면서 c가 있는지 확인하는 함수
        - int strncmp(const char *s1, const char *s2, size_t n)
            - 두 문자열이 같은 문자열인지 확인하는 함수
            - 만약 두 문자열이 다르다면 두 문자열의 다른 부분을 빼줌 양수면 s1이 큰거 음수면 s2가 큰거 같으면 0

            ```c
            if (is1[i] != is2[i] || is1[i] == 0 || is2[i] == 0)
            			return (is1[i] - is2[i]);
            ```

        - void *memchr(const void *s, int c, size_t n);
            - strchr void *버전
            - 메모리를 하나씩 비교해서 구분한다. 범용성있음
        - int memcmp(const void *s1, const void *s2, size_t n);
            - strcmp void *버전
            - 만약 두 메모리가 다르다면 두 매모리의 다른 부분을 빼줌 양수면 s1이 큰거 음수면 s2가 큰거 같으면 0
            - 메모리를 하나씩 비교해서 구분한다. 범용성있음
        - char *strnstr(const char *haystack, const char *needle, size_t len);
            - haystack에 needle이라는 문자열이 있는지 len만큼 확인하는 함수
        - atoi

            atoi 는

            const char * 로 들어온 문자열을 int 형으로 바꾼 뒤 반환해주는 함수이다.

            - 디펜스
                - long max value 가 들어왔을 때 어떤 값을 리턴하고 이유는?
                - long min value 가 들어왔을 떄 어떤 값을 리턴하고 이유는?

                    실제 atoi 함수의 구현 방식은 다음과 같다

                    ```c
                    출처 : apple 오픈소스
                    [https://opensource.apple.com/source/Libc/Libc-186/stdlib.subproj/atoi.c.auto.html](https://opensource.apple.com/source/Libc/Libc-186/stdlib.subproj/atoi.c.auto.html)

                    #include <stdlib.h>
                    #include <stddef.h>

                    atoi(str)
                    	const char *str;
                    {
                    	return((int)strtol(str, (char **)NULL, 10));
                    }
                    ```

                    atoi는 strtol을 int로 케스팅한 값을 가져오기 때문에 strtol의 값에 절대적이다.

                    strtol은 내부적으로 long_max와 long_min 벨류가 들어오면 각각

                    0 , -1 을 반환하기때문에

                    strtol 을 본체로하는 atoi는 0 과  -1 이 반환된다.

                    따라서 atoi는 long_max 와 long_min 이 값이 들어오면 0 1 이 리턴 하는게 맞지만 내가쓰는 libft라면 상관 없다고 생각을 하여 따로 처리를 안해주었다.

                    제 코드는 [https://github.com/Arkingco/42_libft/blob/master/ft_atoi.c](https://github.com/Arkingco/42_libft/blob/master/ft_atoi.c)

        - void *calloc(size_t count, size_t size);
            - count * size 크기만큼 malloc 해주고 0으로 초기화 해주는 함수
        - char *strdup(const char *s1);
