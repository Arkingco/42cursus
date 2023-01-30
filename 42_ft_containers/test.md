# ft_container
ft_container 를 통과하기 위한 몸부림
<br>

## gcc 컴파일러 c++98 vector코드
https://github.com/gcc-mirror/gcc/blob/54c1bf7801758caf2ff54917e79a8c239643061c/libstdc%2B%2B-v3/include/bits/stl_vector.h
<br>

## sfinae, enable_if 와 관련된 모두의코드
https://modoocode.com/255
<br>

## exception safety 깃허브 출처 : yongmkim
https://github.com/ecole42-yoma/ft_containers/wiki/Exception-Safety#classification
<br>

## C++98 gcc 파일 받기
git clone https://github.com/gcc-mirror/gcc.git <br>
git reset --hard 3d90ff935245a9cd141d939019502d4b72dce430

<br>
<br>


## 필요한 함수 타입 정의하기
<img width="1150" alt="Screen Shot 2023-01-30 at 7 34 31 PM" src="https://user-images.githubusercontent.com/28525747/215453521-b129327b-93a7-4c4f-a46c-2874c9b95f0c.png"> <br>
vscode 에서 #incldue<vector> 하면 clang vector file이 나오는데 <br>
synopsis 라고 벡터에서 사용하는 함수랑 타입만 따로 정의되어 있는 부분이 있음 <br>
여기 안에 만들어야 하는 함수랑 타입들 전부 선언되어 있어서 복붙하고 <br>
98에서  쓰는 함수랑 타입빼고 다 제외하는 방식으로 벡터파일 구성 <br>



## container가 메모리를 할당하고 선언하는 방식
container와 같은 경우 기본적으로 std::Allocator를 받아서 할당 받는다 allocator는
  - allocate() 메모리 할당
  - construct() 요소 초기화(요소 추가)
  - destroy() 요소 삭제
  - deallocate() 메모리 해제
