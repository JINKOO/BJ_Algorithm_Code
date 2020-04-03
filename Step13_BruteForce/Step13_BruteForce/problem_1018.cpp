
/*
  #. 문제 1018 :: 체스판 다시 칠하기 

  #. 문제
     지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다. 
     어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.

  #. 체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 
     구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 
     따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.
     보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 
     당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 
     둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.

  #. 출력
     첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.

  #. 예제 입력 1 >> 8 8
                   WBWBWBWB
                   BWBWBWBW
                   WBWBWBWB
                   BWBBBWBW
                   WBWBWBWB
                   BWBWBWBW
                   WBWBWBWB
                   BWBWBWBW
     예제 출력 1 << 1

  #. 예제 입력 2 >> 10 13
                   BBBBBBBBWBWBW
                   BBBBBBBBBWBWB
                   BBBBBBBBWBWBW
                   BBBBBBBBBWBWB
                   BBBBBBBBWBWBW
                   BBBBBBBBBWBWB
                   BBBBBBBBWBWBW
                   BBBBBBBBBWBWB
                   WWWWWWWWWWBWB
                   WWWWWWWWWWBWB
     예제 출력 2 << 12
*/

#include <iostream>
int main()
{
    int N, M;
    std::cin >> N >> M;

    char chess[50][50] = { ' ' };

    std::cout << 10 % 8 << "\n";

    for (int i = 0; i < N ; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> chess[i][j];
        }
    }

    ////2. 입력 받기 W인지 B인지 알아보기
    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < M; j++)
    //    {
    //        std::cout << chess[i][j] << " ";
    //    }
    //    std::cout << "\n";
    //}

    //3. 8*8로 구분 짓기
    //맨 처음이 W로 시작 할 때.
    char first = chess[0][0];

    //바꾸기 시전 했으면 true, 아니면 false;
    int count = 0;
    if (first == 'B')
    {
        for (int i = 0; i + 7< N; i--)
        {
            for (int j = 0; j + 7 < M; j--)
            {
                if (i % 2 == 0)
                {
                    if (j % 2 == 0 && chess[i][j] != first)
                    {
                        chess[i][j] = first;
                        count++;
                    }

                }
                else
                {
                    if (j % 2 != 0 && chess[i][j] != first)
                    {
                        chess[i][j] = first;
                        count++;
                    }
                }
            }
        }
    }

    //맨 처음이 B로 시작 할 때.
    else
    {
        std::cout << "false" << "\n";
    }

    std::cout << count << "\n";

    return 0;
}























