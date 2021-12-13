# 42_get_next_line
get_next_line
- GNL 은 컴파일 할 때 실제 코드에 define 되어 있는 값을 바꾸는 형식으로 컴파일됨
    
    -D 옵션을 사용하면 코드에 define되어 있는 define 매크로 변수의 값을 바꿀수 있음
    

- gnl프로젝트는 기본적으로  get_next_line(int fd) 함수에 fd(파일 디스크립터)를 보내줘서 어떤 파일인지에 대한 정보를 넘겨주고 그 값을 가지고 함수를 진행한다.
    - 파일 디스크립터 값을 얻으러면 c언어 함수 내부에 있는 open 이라는 함수를 사용하여 파일을 시스템 콜? 위에 띄어줘야한다.
        - 시스템 콜 이란   [https://duksoo.tistory.com/entry/System-call-등록-순서](https://duksoo.tistory.com/entry/System-call-%EB%93%B1%EB%A1%9D-%EC%88%9C%EC%84%9C)
        - 사용자프로세서가 소프트웨어 인터럽트를 통해 커널의 기능을 이용하기 위한 서비스를 요청하는 하나의 방법이다.
            - 쨋든 open()이라는 함수를 사용해서 리눅스 커널에 파일을 올리고 open함수를 사용하면 파일을 컨트롤 할 수 있는 fd(파일 디스크립터)값을 return 으로 알 수 있는데 그 값을 가지고 실제 함수에서 컨트롤 하는 방식으로 만들면 될 것 같다
                - open 함수 파라미터 및 사용 방법 [https://www.it-note.kr/19](https://www.it-note.kr/19)
                - 사용 방법2 [https://badayak.com/4398](https://badayak.com/4398)
                - 버퍼 사이즈 만큼 파일 읽기
                
               ![image](https://user-images.githubusercontent.com/28525747/145814088-7a354380-03c8-42a1-8715-1869963e5e4b.png)
                

                            

- 한줄 씩 읽을려면 어떻게 해야하나??
    - GNL 프로젝트는 기본적으로 한번에 전체 파일을 읽지 말고 한줄씩 읽어야한다. HOW?
    - get_next_line 함수는 한번에 지정된 버퍼의 크기만큼 파일,stdin을 읽는데 읽을 때 한 버퍼에 개행문자가 있는지를 체크하는 함수를 만들면 될 것 같다.  그리고 개행문자를 읽은 곳 까지 malloc후 리턴한다.
