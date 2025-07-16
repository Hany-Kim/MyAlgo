# [Gold III] 마트료시카 - 23845 

[문제 링크](https://www.acmicpc.net/problem/23845) 

### 성능 요약

메모리: 41140 KB, 시간: 724 ms

### 분류

그리디 알고리즘

### 제출 일자

2025년 7월 16일 11:02:56

### 문제 설명

<p style="text-align: center;"><a href="https://en.wikipedia.org/wiki/Matryoshka_doll#/media/File:Matryoshka_transparent.png"><img alt="" src="https://upload.acmicpc.net/e6b74707-802e-4062-9849-f3b1b4f55496/-/preview/" style="width: 311px; height: 200px;"></a></p>

<p>인형 수집가 하령이에게는<em> N</em>개의 속이 비어있는 인형이 있다. 각각의 인형은 크기는 <em>X<sub>i</sub></em>이다.</p>

<p>인형의 속은 비어있기 때문에 그 안에 또 다른 인형을 넣을 수 있고, 크기가 서로 다른 인형들을 조합해서 마트료시카를 만들 수 있다. 정확히는 가장 큰 인형의 크기를 <em>Q</em>, 가장 작은 인형의 크기를 <em>W</em>, 인형의 개수를 <em>T</em>라고 할 때, (<em>Q </em>- <em>W </em>+ 1 = <em>T</em>)를 만족하는 인형의 집합을 마트료시카라고 하자. 마트료시카는 1개의 인형으로 구성될 수도 있음에 유의하라.</p>

<p>하나의 마트료시카의 가격은 <em>Q ×</em> <em>T</em>로 책정된다고 한다. 하령이는 가지고 있는 인형을 적절히 조합하여 마트료시카들을 구성해서 최대의 수익을 올리고 싶다.</p>

<p><em>N</em>개의 인형을 모두 사용하여, 마트료시카들을 판매한다고 할 때, 하령이가 올릴 수 있는 최대 수익은 얼마인가?</p>

### 입력 

 <p>첫째 줄에 인형의 개수 <em>N</em>이 주어진다. (1 ≤ <em>N</em> ≤ 2 × 10<sup>5</sup>)</p>

<p>둘째 줄에 하령이가 가지고 있는 인형들의 크기를 나타내는 <em>N</em>개의 정수 <em>X<sub>i</sub></em>가 공백으로 구분되어 주어진다. (1 ≤ <em>X</em><sub><em>i</em> </sub>≤ 10<sup>5</sup>)</p>

### 출력 

 <p>하령이가 올릴 수 있는 최대 수익을 출력하시오.</p>

<p>정답은 32비트 정수 변수(int) 범위를 초과할 수 있기 때문에 64비트 정수 변수(C/C++ : long long, JAVA : long)를 사용해야 한다.</p>

