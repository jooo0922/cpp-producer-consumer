#include <iostream>
#include <queue>
#include <thread>

void produce();
void consume();

// 각 스레드의 공유 자원
int sum = 0;

int main()
{
  // 공유 자원 초기값 출력
  std::cout << "initial sum: " << sum << std::endl;

  // 생산자 스레드와 소비자 스레드 생성 후 실행
  std::thread producer(produce);
  std::thread consumer(consume);

  // 스레드 실행 완료 후 메인 스레드로 복귀
  producer.join();
  consumer.join();

  // 스레드 종료 후 공유 자원에 저장된 값 출력
  std::cout << "sum after producer, consumer thread execution: " << sum << std::endl;

  return 0;
}

/**
 * 생산자 스레드가 수행할 작업
 * -> 공유 자원 sum 을 10만 번 순회하며 1씩 증가시킴
 */
void produce()
{
  for (int i = 0; i < 100000; i++)
  {
    sum++;
  }
}

/**
 * 소비자 스레드가 수행할 작업
 * -> 공유 자원 sum 을 10만 번 순회하며 1씩 감소시킴
 */
void consume()
{
  for (int i = 0; i < 100000; i++)
  {
    sum--;
  }
}
